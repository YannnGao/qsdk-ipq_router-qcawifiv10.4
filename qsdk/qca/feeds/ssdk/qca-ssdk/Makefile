
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=qca-ssdk
PKG_SOURCE_PROTO:=git
PKG_BRANCH:=master
PKG_RELEASE:=1

include $(INCLUDE_DIR)/local-development.mk
ifeq ($(DUMP)$(PKG_VERSION),)
  PKG_VERSION:=$(shell git ls-remote $(PKG_SOURCE_URL) $(PKG_BRANCH) | cut -b -7)
endif
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_VERSION)

LOCAL_VARIANT=$(patsubst qca-ssdk-%,%,$(patsubst qca-ssdk-%,%,$(BUILD_VARIANT)))
include $(INCLUDE_DIR)/package.mk

define KernelPackage/qca-ssdk/default-nohnat
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Devices
  TITLE:=Kernel driver for QCA SSDK
  FILES:=$(PKG_BUILD_DIR)/build/bin/qca-ssdk.ko
  AUTOLOAD:=$(call AutoLoad,30,qca-ssdk)
  PROVIDES:=qca-ssdk
endef

define KernelPackage/qca-ssdk-nohnat
$(call KernelPackage/qca-ssdk/default-nohnat)
  VARIANT:=nohnat
endef

define KernelPackage/qca-ssdk-nohnat/Description
This package contains a qca-ssdk driver for QCA chipset
endef

define KernelPackage/qca-ssdk-hnat
$(call KernelPackage/qca-ssdk/default-nohnat)
  DEPENDS:=+kmod-ipt-extra +kmod-ipt-filter +kmod-ipv6 +kmod-qca-rfs +kmod-ppp
  TITLE+= (hnat)
  VARIANT:=hnat
endef

define KernelPackage/qca-ssdk-hnat/Description
This package contains a qca-ssdk-hnat driver for QCA chipset
endef

GCC_VERSION=$(shell echo "$(CONFIG_GCC_VERSION)" | sed 's/[^0-9.]*\([0-9.]*\).*/\1/')
ifeq ($(GCC_VERSION), 4.8)
GCC_VERSION=4.8.3
endif

QCASSDK_CONFIG_OPTS+= TOOL_PATH=$(TOOLCHAIN_DIR)/bin/ \
                SYS_PATH=$(LINUX_DIR) \
                TOOLPREFIX=$(TARGET_CROSS) \
                KVER=$(LINUX_VERSION) \
                ARCH=$(LINUX_KARCH) \
		TARGET_SUFFIX=$(CONFIG_TARGET_SUFFIX) \
		GCC_VERSION=$(GCC_VERSION) \
		CFLAGS=-I$(STAGING_DIR)/usr/include

ifeq ($(LOCAL_VARIANT),hnat)
    QCASSDK_CONFIG_OPTS+= HNAT_FEATURE=enable
    QCASSDK_CONFIG_OPTS+= RFS_FEATURE=enable
endif

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/qca-ssdk
	$(INSTALL_DIR) $(1)/usr/include/qca-ssdk/api
	$(INSTALL_DIR) $(1)/usr/include/qca-ssdk/ref
	$(INSTALL_DIR) $(1)/usr/include/qca-ssdk/fal
	$(INSTALL_DIR) $(1)/usr/include/qca-ssdk/sal
	$(CP) -rf $(PKG_BUILD_DIR)/include/api/sw_ioctl.h $(1)/usr/include/qca-ssdk/api
	if [ -f $(PKG_BUILD_DIR)/include/ref/ref_vsi.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/ref/ref_vsi.h $(1)/usr/include/qca-ssdk/ref/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/ref/ref_fdb.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/ref/ref_fdb.h $(1)/usr/include/qca-ssdk/ref/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_bm.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_bm.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_fdb.h $(1)/usr/include/qca-ssdk/fal
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_qm.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_qm.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_qos.h $(1)/usr/include/qca-ssdk/fal
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_shaper.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_shaper.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_type.h $(1)/usr/include/qca-ssdk/fal
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_portvlan.h $(1)/usr/include/qca-ssdk/fal
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_vsi.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_vsi.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_policer.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_policer.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_ctrlpkt.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_ctrlpkt.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_mirror.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_mirror.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_trunk.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_trunk.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_stp.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_stp.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_pppoe.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_pppoe.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/fal/fal_mib.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/fal/fal_mib.h $(1)/usr/include/qca-ssdk/fal/; \
	fi
	if [ -f $(PKG_BUILD_DIR)/include/ref/ref_port_ctrl.h ]; then \
	$(CP) -rf $(PKG_BUILD_DIR)/include/ref/ref_port_ctrl.h $(1)/usr/include/qca-ssdk/ref/; \
	fi
	$(CP) -rf $(PKG_BUILD_DIR)/include/common $(1)/usr/include/qca-ssdk
	$(CP) -rf $(PKG_BUILD_DIR)/include/sal/os $(1)/usr/include/qca-ssdk/sal
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) $(strip $(QCASSDK_CONFIG_OPTS))
endef

$(eval $(call KernelPackage,qca-ssdk-nohnat))
$(eval $(call KernelPackage,qca-ssdk-hnat))
