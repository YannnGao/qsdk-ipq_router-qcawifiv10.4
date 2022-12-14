/*
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "sw.h"
#include "ssdk_init.h"
#include "fal_init.h"
#include "fal_misc.h"
#include "fal_mib.h"
#include "fal_port_ctrl.h"
#include "fal_portvlan.h"
#include "fal_fdb.h"
#include "fal_stp.h"
#include "fal_igmp.h"
#include "fal_qos.h"
#include "hsl.h"
#include "hsl_dev.h"
#include "ssdk_init.h"
#include <linux/kconfig.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/phy.h>
#include <linux/platform_device.h>
#include <linux/types.h>
//#include <asm/mach-types.h>
#include <generated/autoconf.h>
#if defined(CONFIG_OF) && (LINUX_VERSION_CODE >= KERNEL_VERSION(3,14,0))
#include <linux/switch.h>
#include <linux/reset.h>
#else
#include <net/switch.h>
#include <linux/ar8216_platform.h>
#endif
#include <linux/delay.h>
#include <linux/phy.h>
#include <linux/netdevice.h>
#include "ssdk_plat.h"
#include "ref_vlan.h"
#include <linux/time.h>
#include "f1_phy.h"
#include "ref_port_ctrl.h"

#if defined(CONFIG_OF) && (LINUX_VERSION_CODE >= KERNEL_VERSION(3,14,0))
extern struct reset_control *ess_mac_clock_disable[5];
#endif

int
qca_ar8327_sw_get_port_link(struct switch_dev *dev, int port,
			                        struct switch_port_link *link)
{
	struct qca_phy_priv *priv = qca_phy_priv_get(dev);

	fal_port_speed_t speed;
	fal_port_duplex_t duplex;
	a_bool_t status;
	a_bool_t tx_fc;
	a_bool_t rx_fc;
	a_uint32_t ret;

	mutex_lock(&priv->reg_mutex);
	ret = fal_port_link_status_get(0, port, &status);
	if (ret){
		mutex_unlock(&priv->reg_mutex);
		return -1;
	}

	ret = fal_port_speed_get(0, port, &speed);
	if (ret){
		mutex_unlock(&priv->reg_mutex);
		return -1;
	}

	ret = fal_port_duplex_get(0, port, &duplex);
	if (ret){
		mutex_unlock(&priv->reg_mutex);
		return -1;
	}

	ret = fal_port_rxfc_status_get(0, port, &rx_fc);
	if (ret){
		mutex_unlock(&priv->reg_mutex);
		return -1;
	}

	ret = fal_port_txfc_status_get(0, port, &tx_fc);
	if (ret){
		mutex_unlock(&priv->reg_mutex);
		return -1;
	}
	mutex_unlock(&priv->reg_mutex);

	link->link = status;
	if (speed == FAL_SPEED_10){
		link->speed = SWITCH_PORT_SPEED_10;
	} else if (speed == FAL_SPEED_100){
		link->speed = SWITCH_PORT_SPEED_100;
	} else if (speed == FAL_SPEED_1000){
		link->speed = SWITCH_PORT_SPEED_1000;
	} else {
		link->speed = SWITCH_PORT_SPEED_UNKNOWN;
	}

	if (duplex == FAL_HALF_DUPLEX){
		link->duplex = 0; /* HALF */
	} else if (duplex == FAL_FULL_DUPLEX){
		link->duplex = 1; /* FULL */
	}

	link->rx_flow = rx_fc;
	link->tx_flow = tx_fc;

	return 0;
}

static int qca_switch_get_qm_status(struct switch_dev *dev, a_uint32_t port_id, a_uint32_t *qm_buffer_err)
{
	a_uint32_t reg = 0;
	a_uint32_t qm_val = 0;
	struct qca_phy_priv *priv = qca_phy_priv_get(dev);

	if (port_id < 0 || port_id > 6) {
		*qm_buffer_err = 0;
		return -1;
	}
	if (priv->version == 0x14)
	{
		if (port_id < 4) {
			reg = 0x1D;
			qca_switch_reg_write(0, 0x820, (a_uint8_t *)&reg, 4);
			qca_switch_reg_read(0, 0x824, (a_uint8_t *)&qm_val, 4);
			*qm_buffer_err = (qm_val >> (port_id * 8)) & 0xFF;
		} else {
			reg = 0x1E;
			qca_switch_reg_write(0, 0x820, (a_uint8_t *)&reg, 4);
			qca_switch_reg_read(0, 0x824, (a_uint8_t *)&qm_val, 4);
			*qm_buffer_err = (qm_val >> ((port_id-4) * 8)) & 0xFF;
		}
	}
	if (priv->version == QCA_VER_AR8337 ||
		priv->version == QCA_VER_AR8327)
	{
		if (port_id < 4) {
			reg = 0x1D;
			priv->mii_write(0x820, reg);
			qm_val = priv->mii_read(0x824);
			*qm_buffer_err = (qm_val >> (port_id * 8)) & 0xFF;
		} else {
			reg = 0x1E;
			priv->mii_write(0x820, reg);
			qm_val = priv->mii_read(0x824);
			*qm_buffer_err = (qm_val >> ((port_id-4) * 8)) & 0xFF;
		}
	}

	return 0;
}

static int qca_switch_force_mac_1000M_full(struct switch_dev *dev, a_uint32_t port_id)
{
	a_uint32_t reg, value = 0;
	struct qca_phy_priv *priv = qca_phy_priv_get(dev);

	if (port_id < 0 || port_id > 6)
		return -1;
	if (priv->version == 0x14)
	{
		reg = AR8327_REG_PORT_STATUS(port_id);
		qca_switch_reg_read(0, reg, (a_uint8_t *)&value, 4);
		value &= ~(BIT(6) | BITS(0,2));
		value |= AR8327_PORT_SPEED_1000M | BIT(6);
		qca_switch_reg_write(0, reg, (a_uint8_t *)&value, 4);
	}
	if (priv->version == QCA_VER_AR8337 ||
		priv->version == QCA_VER_AR8327)
	{
		reg = AR8327_REG_PORT_STATUS(port_id);
		value = priv->mii_read(reg);
		value &= ~(BIT(6) | BITS(0,2));
		value |= AR8327_PORT_SPEED_1000M | BIT(6);
		priv->mii_write(reg, value);
	}
	return 0;
}

static int qca_switch_force_mac_status(struct switch_dev *dev, a_uint32_t port_id,a_uint32_t speed,a_uint32_t duplex)
{
	a_uint32_t reg, value;
	struct qca_phy_priv *priv = qca_phy_priv_get(dev);

	if (port_id < 1 || port_id > 5)
		return -1;
	if (priv->version == 0x14)
	{
#if defined(CONFIG_OF) && (LINUX_VERSION_CODE >= KERNEL_VERSION(3,14,0))
		/*disable mac clock*/
		reset_control_assert(ess_mac_clock_disable[port_id -1]);
		udelay(10);
		reg = AR8327_REG_PORT_STATUS(port_id);
		qca_switch_reg_read(0,reg,(a_uint8_t*)&value,4);
		value &= ~(BIT(6) | BITS(0,2));
		value |= speed | (duplex?BIT(6):0);
		qca_switch_reg_write(0,reg,(a_uint8_t*)&value,4);
		/*enable mac clock*/
		reset_control_deassert(ess_mac_clock_disable[port_id -1]);
#endif
	}
	if (priv->version == QCA_VER_AR8337 ||
	priv->version == QCA_VER_AR8327)
	{
		reg = AR8327_REG_PORT_STATUS(port_id);
		value = priv->mii_read(reg);
		value &= ~(BIT(6) | BITS(0,2));
		value |= speed | (duplex?BIT(6):0);
		priv->mii_write(reg,value);
	}

	return 0;
}

a_bool_t
qca_ar8327_sw_rgmii_mode_valid(a_uint32_t port_id)
{
	a_uint32_t rgmii_mode;

	rgmii_mode = ssdk_dt_global_get_mac_mode();

	if(((rgmii_mode == PORT_WRAPPER_SGMII0_RGMII5) ||
		(rgmii_mode == PORT_WRAPPER_SGMII1_RGMII5)) && (port_id == 5))
		return A_TRUE;

	if(((rgmii_mode == PORT_WRAPPER_SGMII0_RGMII4) ||
		(rgmii_mode == PORT_WRAPPER_SGMII1_RGMII4) ||
		(rgmii_mode == PORT_WRAPPER_SGMII4_RGMII4)) && (port_id == 4))
		return A_TRUE;

	return A_FALSE;
}

static int
qca_switch_get_mac_link(struct switch_dev *dev, a_uint32_t port_id, a_uint32_t *link)
{
	a_uint32_t reg, value = 0;
	struct qca_phy_priv *priv = qca_phy_priv_get(dev);

	if (port_id < 0 || port_id > 6)
		return -1;
	if (priv->version == 0x14)
	{
		reg = AR8327_REG_PORT_STATUS(port_id);
		qca_switch_reg_read(0,reg,(a_uint8_t*)&value,4);
		*link = (value>>8)&0x1;
	}
	if (priv->version == QCA_VER_AR8337 ||
	priv->version == QCA_VER_AR8327)
	{
		reg = AR8327_REG_PORT_STATUS(port_id);
		value = priv->mii_read(reg);
		*link = (value>>8)&0x1;
	}

	return 0;
}


#define MDI_FROM_PHY_STATUS 1
#define MDI_FROM_MANUAL 0
#define PORT_LINK_UP 1
#define PORT_LINK_DOWN 0

#define QM_NOT_EMPTY  1
#define QM_EMPTY  0

static a_uint32_t port_link_down[AR8327_NUM_PORTS] = {0, 0 ,0 ,0 , 0, 0, 0};

static a_uint32_t port_link_up[AR8327_NUM_PORTS] = {0, 0 ,0 ,0 , 0, 0, 0};

static a_uint32_t port_old_link[AR8327_NUM_PORTS] = {0, 0 ,0 ,0 , 0, 0, 0};
static a_uint32_t port_old_speed[AR8327_NUM_PORTS] = {AR8327_PORT_SPEED_10M,
	AR8327_PORT_SPEED_10M,
	AR8327_PORT_SPEED_10M,
	AR8327_PORT_SPEED_10M,
	AR8327_PORT_SPEED_10M,
	AR8327_PORT_SPEED_10M,
	AR8327_PORT_SPEED_10M};

static a_uint32_t port_old_duplex[AR8327_NUM_PORTS] = {0, 0 ,0 ,0 , 0, 0, 0};
static a_uint32_t port_old_phy_status[AR8327_NUM_PORTS] = {0, 0 ,0 ,0 , 0, 0, 0};


static a_uint32_t port_qm_buf[AR8327_NUM_PORTS] = {QM_EMPTY, QM_EMPTY ,QM_EMPTY ,QM_EMPTY , QM_EMPTY, QM_EMPTY, QM_EMPTY};

static a_uint32_t phy_current_speed = 2;
static a_uint32_t phy_current_duplex = 1;

int qca_ar8327_sw_enable_vlan0(a_bool_t enable, a_uint8_t portmap);
int qca_ar8327_vlan_recovery(struct switch_dev *dev)
{
	struct qca_phy_priv *priv = qca_phy_priv_get(dev);
	fal_pbmp_t portmask[AR8327_NUM_PORTS];
	int i, j;
	a_uint32_t reg, val;
	u8 mask ;

	mutex_lock(&priv->reg_mutex);

	memset(portmask, 0, sizeof(portmask));
	if (!priv->init) {
		/*Handle VLAN 0 entry*/
		if (priv->vlan_id[0] == 0 && priv->vlan_table[0] == 0) {
			qca_ar8327_sw_enable_vlan0(A_FALSE, 0);
		}

		/* calculate the port destination masks and load vlans
		 * into the vlan translation unit */
		for (j = 0; j < AR8327_MAX_VLANS; j++) {
			/*
			//############################# VLAN -1 #########################
			//## VID=1 VLAN member : P1-t,P2-t,P3-t,P4-t,P5-t, P6-t
			or 610 000AAAB0
			or 614 80010002
			*/
			if (priv->vlan_id[j]) {
				/* reg 0x610 VLAN_TABLE_FUNC0_OFFSET*/
				reg = 0x610;
				val = 0x00180000;
				for (i = 0; i < dev->ports; ++i) {
					mask = (1 << i);
					if (mask & priv->vlan_table[j])
					{
						val |= ((mask & priv->vlan_tagged[j])? FAL_EG_TAGGED : FAL_EG_UNTAGGED) << ((i << 1) + 4);
					}
					else
						val |= (0x3) << ((i << 1) + 4);	// not member.
				}
				priv->mii_write(reg, val);

				/* reg 0x614 VLAN_TABLE_FUNC1_OFFSET*/
				reg = 0x614;
				val = 0x80000002;	// load en entry
				val |= priv->vlan_id[j] << 16;
				priv->mii_write(reg, val);
			}
		}

		/*Hanlde VLAN 0 entry*/
		if (priv->vlan_id[0] == 0 && priv->vlan_table[0]) {
			qca_ar8327_sw_enable_vlan0(A_TRUE, priv->vlan_table[0]);
		}

	} else {
		/* vlan disabled:
		 * isolate all ports, but connect them to the cpu port */
		for (i = 0; i < dev->ports; i++) {
			if (i == AR8327_PORT_CPU)
				continue;

			portmask[i] = 1 << AR8327_PORT_CPU;
			portmask[AR8327_PORT_CPU] |= (1 << i);
		}
	}

	/* update the port destination mask registers and tag settings */
	for (i = 0; i < dev->ports; i++) {
		int pvid;
		fal_pt_1qmode_t ingressMode;
		fal_pt_1q_egmode_t egressMode;

		if (priv->vlan) {
			pvid = priv->vlan_id[priv->pvid[i]];
			if (priv->vlan_tagged[priv->pvid[i]] & (1 << i)) {
				egressMode = FAL_EG_TAGGED;
			} else {
				egressMode = FAL_EG_UNTAGGED;
			}

			ingressMode = FAL_1Q_SECURE;
		} else {
			pvid = i;
			egressMode = FAL_EG_UNTOUCHED;
			ingressMode = FAL_1Q_DISABLE;
		}

		/*If VLAN 0 existes, change member port
		   *egress mode as UNTOUCHED*/
		if (priv->vlan_id[0] == 0 &&
			  priv->vlan_table[0] &&
			  ((0x1 << i) & priv->vlan_table[0]) &&
			  priv->vlan) {
			egressMode = FAL_EG_UNTOUCHED;
		}

		fal_port_1qmode_set(0, i, ingressMode);
		fal_port_egvlanmode_set(0, i, egressMode);
		fal_port_default_cvid_set(0, i, pvid);
		fal_portvlan_member_update(0, i, portmask[i]);
	}

	mutex_unlock(&priv->reg_mutex);

	return 0;
}

int qca_qm_error_check(struct qca_phy_priv *priv)
{
	a_uint32_t value = 0, qm_err_int=0;

	if (priv->version == QCA_VER_AR8337 ||
		priv->version == QCA_VER_AR8327)
	{
		value = priv->mii_read(0x24);
		qm_err_int = value & BIT(14);	// b14-QM_ERR_INT

		if(qm_err_int)
			return 1;

		priv->mii_write(0x820, 0x0);
		value = priv->mii_read(0x824);
	}
	if(priv->version==0x14)
	{
		qca_switch_reg_read(0, 0x24, (a_uint8_t*)&value, 4);
		qm_err_int = value & BIT(14);	// b14-QM_ERR_INT

		if(qm_err_int)
			return 1;
		value = 0;
		qca_switch_reg_write(0, 0x820, (a_uint8_t*)&value, 4);
		qca_switch_reg_read(0, 0x824, (a_uint8_t*)&value, 4);
	}
	return value;
}

void qca_ar8327_phy_linkdown(void);
int qca_ar8327_hw_init(struct qca_phy_priv *priv);

int qca_qm_err_recovery(struct qca_phy_priv *priv)
{
	memset(port_link_down, 0, sizeof(port_link_down));
	memset(port_link_up, 0, sizeof(port_link_up));
	memset(port_old_link, 0, sizeof(port_old_link));
	memset(port_old_speed, 0, sizeof(port_old_speed));
	memset(port_old_duplex, 0, sizeof(port_old_duplex));
	memset(port_old_phy_status, 0, sizeof(port_old_phy_status));
	memset(port_qm_buf, 0, sizeof(port_qm_buf));

	/* in soft reset recovery procedure */
	qca_ar8327_phy_linkdown();

	qca_ar8327_hw_init(priv);

	qca_ar8327_vlan_recovery(&priv->sw_dev);

	/*To add customerized recovery codes*/

	return 1;
}

a_bool_t
qca_ar8327_sw_mac_polling_port_valid(struct switch_dev *dev, a_uint32_t port_id)
{
	a_uint32_t mac_mode;

	mac_mode = ssdk_dt_global_get_mac_mode();

	if( port_id >= AR8327_NUM_PORTS-1 || port_id < 1)
		return A_FALSE;

	if(((mac_mode == PORT_WRAPPER_SGMII0_RGMII5) ||
		(mac_mode == PORT_WRAPPER_SGMII1_RGMII5)) && (port_id != 5))
		return A_FALSE;

	if(((mac_mode == PORT_WRAPPER_SGMII0_RGMII4) ||
		(mac_mode == PORT_WRAPPER_SGMII1_RGMII4) ||
		(mac_mode == PORT_WRAPPER_SGMII4_RGMII4)) && (port_id != 4))
		return A_FALSE;

	return A_TRUE;
}
void
qca_phy_status_get(a_uint32_t port_id, a_uint32_t *speed_status, a_uint32_t *link_status, a_uint32_t *duplex_status)
{
	a_uint16_t port_phy_status;
	a_uint32_t phy_addr;

	phy_addr = port_id -1;
	if (qca_ar8327_sw_rgmii_mode_valid(port_id) == A_TRUE)
		phy_addr = 4;

	qca_ar8327_phy_read(0, phy_addr, F1_PHY_SPEC_STATUS, &port_phy_status);
	*speed_status = (a_uint32_t)((port_phy_status >> 14) & 0x03);
	*link_status = (a_uint32_t)((port_phy_status & BIT(10)) >> 10);
	*duplex_status = (a_uint32_t)((port_phy_status & BIT(13)) >> 13);
}

/* Initialize notifier list for QCA SSDK */
static BLOCKING_NOTIFIER_HEAD(ssdk_port_link_notifier_list);

static int ssdk_port_link_notify(unsigned char port_id,
            unsigned char link, unsigned char speed, unsigned char duplex)
{
    ssdk_port_status port_status;

    port_status.port_id = port_id;
    port_status.port_link = link;
    port_status.speed = speed;
    port_status.duplex = duplex;

    return blocking_notifier_call_chain(&ssdk_port_link_notifier_list,	0, &port_status);
}

int ssdk_port_link_notify_register(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&ssdk_port_link_notifier_list, nb);
}
EXPORT_SYMBOL(ssdk_port_link_notify_register);

int ssdk_port_link_notify_unregister(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&ssdk_port_link_notifier_list, nb);
}
EXPORT_SYMBOL(ssdk_port_link_notify_unregister);


void
qca_ar8327_sw_mac_polling_task(struct switch_dev *dev)
{
	static int task_count = 0;
	a_uint32_t i;
	a_uint32_t value;
	a_uint32_t link = 0, speed = 0, duplex = 0;
	a_uint32_t qm_buffer_err = 0;
	a_uint16_t port_phy_status[AR8327_NUM_PORTS] = {0,0,0,0,0,0,0};
	static a_uint32_t qm_err_cnt[AR8327_NUM_PORTS] = {0,0,0,0,0,0,0};

	static a_uint32_t link_cnt[AR8327_NUM_PORTS] = {0,0,0,0,0,0,0};

	struct qca_phy_priv *priv = qca_phy_priv_get(dev);

	/*Only valid for S17c chip*/
	if (priv->version != QCA_VER_AR8337 &&
		priv->version != QCA_VER_AR8327 &&
		priv->version != 0x14)
		return;

	value = qca_qm_error_check(priv);
	if(value)
	{
		if(priv->version != 0x14)
			qca_qm_err_recovery(priv);
		return;
	}

	++task_count;

	for (i = 1; i < AR8327_NUM_PORTS-1; i++) {
		if(qca_ar8327_sw_mac_polling_port_valid(dev, i) == A_FALSE)
			continue;

		if (qca_ar8327_sw_rgmii_mode_valid(i) == A_FALSE)
			qca_switch_get_mac_link(dev, i, &link);
		else
		{
			qca_phy_status_get(i, &speed, &link, &duplex);
		}
		if (link != port_old_link[i]) {
			if (qca_ar8327_sw_rgmii_mode_valid(i) == A_FALSE)
			{
				qca_phy_status_get(i, &speed, &link, &duplex);
			}
			++link_cnt[i];
			/* Up --> Down */
			if ((port_old_link[i] == PORT_LINK_UP) && (link == PORT_LINK_DOWN)) {

				if (qca_ar8327_sw_rgmii_mode_valid(i) == A_TRUE)
				{
					fal_port_rxmac_status_set(0, i, A_FALSE);
					fal_port_txmac_status_set(0, i, A_FALSE);
				}
				else
				{
					// a_uint32_t pstatus = 0;
					fal_port_link_forcemode_set(0, i, A_TRUE);
					// below only for dess debug print
					// qca_switch_reg_read(0, AR8327_REG_PORT_STATUS(i), (a_uint8_t *)&pstatus, 4);
					// printk("%s, %d, port_id %d link down pstatus 0x%x\n",__FUNCTION__,__LINE__,i, pstatus);
				}
				port_link_down[i]=0;
				ssdk_port_link_notify(i, 0, 0, 0);
				fal_fdb_del_by_port(0, i, 0);/*flush all dynamic fdb of this port*/
				if(priv->version != 0x14){
					/* Check queue buffer */
					a_uint16_t value = 0;
					qm_err_cnt[i] = 0;
					qca_switch_get_qm_status(dev, i, &qm_buffer_err);

					if (qm_buffer_err) {
						port_qm_buf[i] = QM_NOT_EMPTY;
					}
					else {
						port_qm_buf[i] = QM_EMPTY;

						/* Force MAC 1000M Full before auto negotiation */
						qca_switch_force_mac_1000M_full(dev, i);
						mdelay(10);
						// printk("%s, %d, port %d link down\n",__FUNCTION__,__LINE__,i);
					}
					qca_ar8327_phy_dbg_read(0, i-1, 0, &value);
					value &= (~(1<<12));
					qca_ar8327_phy_dbg_write(0, i-1, 0, value);
				}
			}
			/* Down --> Up */
			else if ((port_old_link[i] == PORT_LINK_DOWN) && (link == PORT_LINK_UP)) {

				if (port_link_up[i] < 1) {
					++port_link_up[i];
					qca_switch_get_qm_status(dev, i, &qm_buffer_err);
					if (qm_buffer_err) {
						if(priv->version != 0x14)
								qca_qm_err_recovery(priv);
						return;
					}
				}
				else{
					//a_uint32_t pstatus = 0;
					port_link_up[i]=0;
					qca_switch_force_mac_status(dev, i, speed, duplex);
					udelay(100);
					if (qca_ar8327_sw_rgmii_mode_valid(i) == A_FALSE) {
						fal_port_link_forcemode_set(0, i, A_FALSE);
					}
					else
					{
						fal_port_rxmac_status_set(0, i, A_TRUE);
						fal_port_txmac_status_set(0, i, A_TRUE);
					}
					udelay(100);
					//qca_switch_reg_read(0, AR8327_REG_PORT_STATUS(i), (a_uint8_t *)&pstatus, 4);
					//printk("%s, %d, port %d link up speed %d, duplex %d pstatus 0x%x\n",__FUNCTION__,__LINE__,i, speed, duplex, pstatus);
                    ssdk_port_link_notify(i, 1, speed, duplex);
					if((speed == 0x01) && (priv->version != 0x14))/*PHY is link up 100M*/
					{
						a_uint16_t value = 0;
						qca_ar8327_phy_dbg_read(0, i-1, 0, &value);
						value |= (1<<12);
						qca_ar8327_phy_dbg_write(0, i-1, 0, value);
					}
				}
			}
			if ((port_link_down[i] == 0)
				&& (port_link_up[i] == 0)){
				/* Save the current status */
				port_old_speed[i] = speed;
				port_old_link[i] = link;
				port_old_duplex[i] = duplex;
				port_old_phy_status[i] = port_phy_status[i];
			}
		}

		if (port_qm_buf[i] == QM_NOT_EMPTY) {
			/* Check QM */
			qca_switch_get_qm_status(dev, i, &qm_buffer_err);
			if (qm_buffer_err) {
				port_qm_buf[i] = QM_NOT_EMPTY;
				++qm_err_cnt[i];
			}
			else {
				port_qm_buf[i] = QM_EMPTY;
				qm_err_cnt[i] = 0;

				/* Force MAC 1000M Full before auto negotiation */
				qca_switch_force_mac_1000M_full(dev, i);
			}
		}
	}
	return ;
}

void
dess_rgmii_sw_mac_polling_task(struct switch_dev *dev)
{
	a_uint32_t mac_mode;
	a_uint16_t phy_spec_status, phy_link_status;
	a_uint32_t speed, duplex;

	mac_mode = ssdk_dt_global_get_mac_mode();

	if ((mac_mode == PORT_WRAPPER_SGMII0_RGMII5)
		||(mac_mode == PORT_WRAPPER_SGMII1_RGMII5)
		||(mac_mode == PORT_WRAPPER_SGMII0_RGMII4)
		||(mac_mode == PORT_WRAPPER_SGMII1_RGMII4)
		||(mac_mode == PORT_WRAPPER_SGMII4_RGMII4)) {
		qca_ar8327_phy_read(0, 4, 0x11, &phy_spec_status);
		phy_link_status = (a_uint16_t)((phy_spec_status & BIT(10)) >> 10);
		if (phy_link_status == 1) {
			speed = (a_uint32_t)((phy_spec_status >> 14) & 0x03);
			duplex = (a_uint32_t)((phy_spec_status & BIT(13)) >> 13);
			if ((speed != phy_current_speed) || (duplex != phy_current_duplex)) {
				if ((mac_mode == PORT_WRAPPER_SGMII0_RGMII5)
				||(mac_mode == PORT_WRAPPER_SGMII1_RGMII5))
				qca_switch_force_mac_status(dev, 5,speed,duplex);

				if ((mac_mode == PORT_WRAPPER_SGMII0_RGMII4)
				||(mac_mode == PORT_WRAPPER_SGMII1_RGMII4)
				||(mac_mode == PORT_WRAPPER_SGMII4_RGMII4))
				qca_switch_force_mac_status(dev, 4,speed,duplex);
			}
			phy_current_speed = speed;
			phy_current_duplex = duplex;
		}
	}

	return;
}

