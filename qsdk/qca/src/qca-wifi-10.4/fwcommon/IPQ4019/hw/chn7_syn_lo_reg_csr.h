/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _CHN7_SYN_LO_REG_CSR_H_
#define _CHN7_SYN_LO_REG_CSR_H_


#ifndef __CHN7_SYN_LO_REG_CSR_BASE_ADDRESS
#define __CHN7_SYN_LO_REG_CSR_BASE_ADDRESS (0x49e40)
#endif


// 0x0 (CHN7_LO0)
#define CHN7_LO0_DIST_NOTAIL_EN_LSB                                            31
#define CHN7_LO0_DIST_NOTAIL_EN_MSB                                            31
#define CHN7_LO0_DIST_NOTAIL_EN_MASK                                           0x80000000
#define CHN7_LO0_DIST_NOTAIL_EN_GET(x)                                         (((x) & CHN7_LO0_DIST_NOTAIL_EN_MASK) >> CHN7_LO0_DIST_NOTAIL_EN_LSB)
#define CHN7_LO0_DIST_NOTAIL_EN_SET(x)                                         (((0 | (x)) << CHN7_LO0_DIST_NOTAIL_EN_LSB) & CHN7_LO0_DIST_NOTAIL_EN_MASK)
#define CHN7_LO0_DIST_NOTAIL_EN_RESET                                          0x0
#define CHN7_LO0_GEN_MIX_PWR_LSB                                               28
#define CHN7_LO0_GEN_MIX_PWR_MSB                                               30
#define CHN7_LO0_GEN_MIX_PWR_MASK                                              0x70000000
#define CHN7_LO0_GEN_MIX_PWR_GET(x)                                            (((x) & CHN7_LO0_GEN_MIX_PWR_MASK) >> CHN7_LO0_GEN_MIX_PWR_LSB)
#define CHN7_LO0_GEN_MIX_PWR_SET(x)                                            (((0 | (x)) << CHN7_LO0_GEN_MIX_PWR_LSB) & CHN7_LO0_GEN_MIX_PWR_MASK)
#define CHN7_LO0_GEN_MIX_PWR_RESET                                             0x1
#define CHN7_LO0_HBTX_DIVIQ_LSB                                                23
#define CHN7_LO0_HBTX_DIVIQ_MSB                                                27
#define CHN7_LO0_HBTX_DIVIQ_MASK                                               0xf800000
#define CHN7_LO0_HBTX_DIVIQ_GET(x)                                             (((x) & CHN7_LO0_HBTX_DIVIQ_MASK) >> CHN7_LO0_HBTX_DIVIQ_LSB)
#define CHN7_LO0_HBTX_DIVIQ_SET(x)                                             (((0 | (x)) << CHN7_LO0_HBTX_DIVIQ_LSB) & CHN7_LO0_HBTX_DIVIQ_MASK)
#define CHN7_LO0_HBTX_DIVIQ_RESET                                              0x0
#define CHN7_LO0_HBRX_DIVIQ_LSB                                                18
#define CHN7_LO0_HBRX_DIVIQ_MSB                                                22
#define CHN7_LO0_HBRX_DIVIQ_MASK                                               0x7c0000
#define CHN7_LO0_HBRX_DIVIQ_GET(x)                                             (((x) & CHN7_LO0_HBRX_DIVIQ_MASK) >> CHN7_LO0_HBRX_DIVIQ_LSB)
#define CHN7_LO0_HBRX_DIVIQ_SET(x)                                             (((0 | (x)) << CHN7_LO0_HBRX_DIVIQ_LSB) & CHN7_LO0_HBRX_DIVIQ_MASK)
#define CHN7_LO0_HBRX_DIVIQ_RESET                                              0x0
#define CHN7_LO0_EN_HB_OVR_LSB                                                 16
#define CHN7_LO0_EN_HB_OVR_MSB                                                 17
#define CHN7_LO0_EN_HB_OVR_MASK                                                0x30000
#define CHN7_LO0_EN_HB_OVR_GET(x)                                              (((x) & CHN7_LO0_EN_HB_OVR_MASK) >> CHN7_LO0_EN_HB_OVR_LSB)
#define CHN7_LO0_EN_HB_OVR_SET(x)                                              (((0 | (x)) << CHN7_LO0_EN_HB_OVR_LSB) & CHN7_LO0_EN_HB_OVR_MASK)
#define CHN7_LO0_EN_HB_OVR_RESET                                               0x0
#define CHN7_LO0_EN_LB_OVR_LSB                                                 14
#define CHN7_LO0_EN_LB_OVR_MSB                                                 15
#define CHN7_LO0_EN_LB_OVR_MASK                                                0xc000
#define CHN7_LO0_EN_LB_OVR_GET(x)                                              (((x) & CHN7_LO0_EN_LB_OVR_MASK) >> CHN7_LO0_EN_LB_OVR_LSB)
#define CHN7_LO0_EN_LB_OVR_SET(x)                                              (((0 | (x)) << CHN7_LO0_EN_LB_OVR_LSB) & CHN7_LO0_EN_LB_OVR_MASK)
#define CHN7_LO0_EN_LB_OVR_RESET                                               0x0
#define CHN7_LO0_LO_TXON_OVR_LSB                                               12
#define CHN7_LO0_LO_TXON_OVR_MSB                                               13
#define CHN7_LO0_LO_TXON_OVR_MASK                                              0x3000
#define CHN7_LO0_LO_TXON_OVR_GET(x)                                            (((x) & CHN7_LO0_LO_TXON_OVR_MASK) >> CHN7_LO0_LO_TXON_OVR_LSB)
#define CHN7_LO0_LO_TXON_OVR_SET(x)                                            (((0 | (x)) << CHN7_LO0_LO_TXON_OVR_LSB) & CHN7_LO0_LO_TXON_OVR_MASK)
#define CHN7_LO0_LO_TXON_OVR_RESET                                             0x0
#define CHN7_LO0_LO_RXON_OVR_LSB                                               10
#define CHN7_LO0_LO_RXON_OVR_MSB                                               11
#define CHN7_LO0_LO_RXON_OVR_MASK                                              0xc00
#define CHN7_LO0_LO_RXON_OVR_GET(x)                                            (((x) & CHN7_LO0_LO_RXON_OVR_MASK) >> CHN7_LO0_LO_RXON_OVR_LSB)
#define CHN7_LO0_LO_RXON_OVR_SET(x)                                            (((0 | (x)) << CHN7_LO0_LO_RXON_OVR_LSB) & CHN7_LO0_LO_RXON_OVR_MASK)
#define CHN7_LO0_LO_RXON_OVR_RESET                                             0x0
#define CHN7_LO0_EN_DIST_OVR_LSB                                               8
#define CHN7_LO0_EN_DIST_OVR_MSB                                               9
#define CHN7_LO0_EN_DIST_OVR_MASK                                              0x300
#define CHN7_LO0_EN_DIST_OVR_GET(x)                                            (((x) & CHN7_LO0_EN_DIST_OVR_MASK) >> CHN7_LO0_EN_DIST_OVR_LSB)
#define CHN7_LO0_EN_DIST_OVR_SET(x)                                            (((0 | (x)) << CHN7_LO0_EN_DIST_OVR_LSB) & CHN7_LO0_EN_DIST_OVR_MASK)
#define CHN7_LO0_EN_DIST_OVR_RESET                                             0x0
#define CHN7_LO0_DIST_ENCAP_OVR_EN_LSB                                         7
#define CHN7_LO0_DIST_ENCAP_OVR_EN_MSB                                         7
#define CHN7_LO0_DIST_ENCAP_OVR_EN_MASK                                        0x80
#define CHN7_LO0_DIST_ENCAP_OVR_EN_GET(x)                                      (((x) & CHN7_LO0_DIST_ENCAP_OVR_EN_MASK) >> CHN7_LO0_DIST_ENCAP_OVR_EN_LSB)
#define CHN7_LO0_DIST_ENCAP_OVR_EN_SET(x)                                      (((0 | (x)) << CHN7_LO0_DIST_ENCAP_OVR_EN_LSB) & CHN7_LO0_DIST_ENCAP_OVR_EN_MASK)
#define CHN7_LO0_DIST_ENCAP_OVR_EN_RESET                                       0x0
#define CHN7_LO0_DIST_ENCAP_OVR_VAL_LSB                                        4
#define CHN7_LO0_DIST_ENCAP_OVR_VAL_MSB                                        6
#define CHN7_LO0_DIST_ENCAP_OVR_VAL_MASK                                       0x70
#define CHN7_LO0_DIST_ENCAP_OVR_VAL_GET(x)                                     (((x) & CHN7_LO0_DIST_ENCAP_OVR_VAL_MASK) >> CHN7_LO0_DIST_ENCAP_OVR_VAL_LSB)
#define CHN7_LO0_DIST_ENCAP_OVR_VAL_SET(x)                                     (((0 | (x)) << CHN7_LO0_DIST_ENCAP_OVR_VAL_LSB) & CHN7_LO0_DIST_ENCAP_OVR_VAL_MASK)
#define CHN7_LO0_DIST_ENCAP_OVR_VAL_RESET                                      0x1
#define CHN7_LO0_GEN_ENCAP_OVR_EN_LSB                                          3
#define CHN7_LO0_GEN_ENCAP_OVR_EN_MSB                                          3
#define CHN7_LO0_GEN_ENCAP_OVR_EN_MASK                                         0x8
#define CHN7_LO0_GEN_ENCAP_OVR_EN_GET(x)                                       (((x) & CHN7_LO0_GEN_ENCAP_OVR_EN_MASK) >> CHN7_LO0_GEN_ENCAP_OVR_EN_LSB)
#define CHN7_LO0_GEN_ENCAP_OVR_EN_SET(x)                                       (((0 | (x)) << CHN7_LO0_GEN_ENCAP_OVR_EN_LSB) & CHN7_LO0_GEN_ENCAP_OVR_EN_MASK)
#define CHN7_LO0_GEN_ENCAP_OVR_EN_RESET                                        0x0
#define CHN7_LO0_GEN_ENCAP_OVR_VAL_LSB                                         0
#define CHN7_LO0_GEN_ENCAP_OVR_VAL_MSB                                         2
#define CHN7_LO0_GEN_ENCAP_OVR_VAL_MASK                                        0x7
#define CHN7_LO0_GEN_ENCAP_OVR_VAL_GET(x)                                      (((x) & CHN7_LO0_GEN_ENCAP_OVR_VAL_MASK) >> CHN7_LO0_GEN_ENCAP_OVR_VAL_LSB)
#define CHN7_LO0_GEN_ENCAP_OVR_VAL_SET(x)                                      (((0 | (x)) << CHN7_LO0_GEN_ENCAP_OVR_VAL_LSB) & CHN7_LO0_GEN_ENCAP_OVR_VAL_MASK)
#define CHN7_LO0_GEN_ENCAP_OVR_VAL_RESET                                       0x1
#define CHN7_LO0_ADDRESS                                                       (0x0 + __CHN7_SYN_LO_REG_CSR_BASE_ADDRESS)
#define CHN7_LO0_RSTMASK                                                       0xffffffff
#define CHN7_LO0_RESET                                                         0x10000011

// 0x4 (CHN7_LO1)
#define CHN7_LO1_PAL_EN_OVR_LSB                                                30
#define CHN7_LO1_PAL_EN_OVR_MSB                                                31
#define CHN7_LO1_PAL_EN_OVR_MASK                                               0xc0000000
#define CHN7_LO1_PAL_EN_OVR_GET(x)                                             (((x) & CHN7_LO1_PAL_EN_OVR_MASK) >> CHN7_LO1_PAL_EN_OVR_LSB)
#define CHN7_LO1_PAL_EN_OVR_SET(x)                                             (((0 | (x)) << CHN7_LO1_PAL_EN_OVR_LSB) & CHN7_LO1_PAL_EN_OVR_MASK)
#define CHN7_LO1_PAL_EN_OVR_RESET                                              0x0
#define CHN7_LO1_PAL_COMP_START_OVR_LSB                                        28
#define CHN7_LO1_PAL_COMP_START_OVR_MSB                                        29
#define CHN7_LO1_PAL_COMP_START_OVR_MASK                                       0x30000000
#define CHN7_LO1_PAL_COMP_START_OVR_GET(x)                                     (((x) & CHN7_LO1_PAL_COMP_START_OVR_MASK) >> CHN7_LO1_PAL_COMP_START_OVR_LSB)
#define CHN7_LO1_PAL_COMP_START_OVR_SET(x)                                     (((0 | (x)) << CHN7_LO1_PAL_COMP_START_OVR_LSB) & CHN7_LO1_PAL_COMP_START_OVR_MASK)
#define CHN7_LO1_PAL_COMP_START_OVR_RESET                                      0x0
#define CHN7_LO1_PAL_FLIP_MDIV_OVR_LSB                                         26
#define CHN7_LO1_PAL_FLIP_MDIV_OVR_MSB                                         27
#define CHN7_LO1_PAL_FLIP_MDIV_OVR_MASK                                        0xc000000
#define CHN7_LO1_PAL_FLIP_MDIV_OVR_GET(x)                                      (((x) & CHN7_LO1_PAL_FLIP_MDIV_OVR_MASK) >> CHN7_LO1_PAL_FLIP_MDIV_OVR_LSB)
#define CHN7_LO1_PAL_FLIP_MDIV_OVR_SET(x)                                      (((0 | (x)) << CHN7_LO1_PAL_FLIP_MDIV_OVR_LSB) & CHN7_LO1_PAL_FLIP_MDIV_OVR_MASK)
#define CHN7_LO1_PAL_FLIP_MDIV_OVR_RESET                                       0x0
#define CHN7_LO1_PAL_FLIP_RXDIV_OVR_LSB                                        24
#define CHN7_LO1_PAL_FLIP_RXDIV_OVR_MSB                                        25
#define CHN7_LO1_PAL_FLIP_RXDIV_OVR_MASK                                       0x3000000
#define CHN7_LO1_PAL_FLIP_RXDIV_OVR_GET(x)                                     (((x) & CHN7_LO1_PAL_FLIP_RXDIV_OVR_MASK) >> CHN7_LO1_PAL_FLIP_RXDIV_OVR_LSB)
#define CHN7_LO1_PAL_FLIP_RXDIV_OVR_SET(x)                                     (((0 | (x)) << CHN7_LO1_PAL_FLIP_RXDIV_OVR_LSB) & CHN7_LO1_PAL_FLIP_RXDIV_OVR_MASK)
#define CHN7_LO1_PAL_FLIP_RXDIV_OVR_RESET                                      0x0
#define CHN7_LO1_PAL_FLIP_TXDIV_OVR_LSB                                        22
#define CHN7_LO1_PAL_FLIP_TXDIV_OVR_MSB                                        23
#define CHN7_LO1_PAL_FLIP_TXDIV_OVR_MASK                                       0xc00000
#define CHN7_LO1_PAL_FLIP_TXDIV_OVR_GET(x)                                     (((x) & CHN7_LO1_PAL_FLIP_TXDIV_OVR_MASK) >> CHN7_LO1_PAL_FLIP_TXDIV_OVR_LSB)
#define CHN7_LO1_PAL_FLIP_TXDIV_OVR_SET(x)                                     (((0 | (x)) << CHN7_LO1_PAL_FLIP_TXDIV_OVR_LSB) & CHN7_LO1_PAL_FLIP_TXDIV_OVR_MASK)
#define CHN7_LO1_PAL_FLIP_TXDIV_OVR_RESET                                      0x0
#define CHN7_LO1_GEN_DIV3ON_OVR_LSB                                            20
#define CHN7_LO1_GEN_DIV3ON_OVR_MSB                                            21
#define CHN7_LO1_GEN_DIV3ON_OVR_MASK                                           0x300000
#define CHN7_LO1_GEN_DIV3ON_OVR_GET(x)                                         (((x) & CHN7_LO1_GEN_DIV3ON_OVR_MASK) >> CHN7_LO1_GEN_DIV3ON_OVR_LSB)
#define CHN7_LO1_GEN_DIV3ON_OVR_SET(x)                                         (((0 | (x)) << CHN7_LO1_GEN_DIV3ON_OVR_LSB) & CHN7_LO1_GEN_DIV3ON_OVR_MASK)
#define CHN7_LO1_GEN_DIV3ON_OVR_RESET                                          0x2
#define CHN7_LO1_PAL_RST_DLY_LSB                                               17
#define CHN7_LO1_PAL_RST_DLY_MSB                                               19
#define CHN7_LO1_PAL_RST_DLY_MASK                                              0xe0000
#define CHN7_LO1_PAL_RST_DLY_GET(x)                                            (((x) & CHN7_LO1_PAL_RST_DLY_MASK) >> CHN7_LO1_PAL_RST_DLY_LSB)
#define CHN7_LO1_PAL_RST_DLY_SET(x)                                            (((0 | (x)) << CHN7_LO1_PAL_RST_DLY_LSB) & CHN7_LO1_PAL_RST_DLY_MASK)
#define CHN7_LO1_PAL_RST_DLY_RESET                                             0x0
#define CHN7_LO1_RESERVED_0_LSB                                                4
#define CHN7_LO1_RESERVED_0_MSB                                                16
#define CHN7_LO1_RESERVED_0_MASK                                               0x1fff0
#define CHN7_LO1_RESERVED_0_GET(x)                                             (((x) & CHN7_LO1_RESERVED_0_MASK) >> CHN7_LO1_RESERVED_0_LSB)
#define CHN7_LO1_RESERVED_0_SET(x)                                             (((0 | (x)) << CHN7_LO1_RESERVED_0_LSB) & CHN7_LO1_RESERVED_0_MASK)
#define CHN7_LO1_RESERVED_0_RESET                                              0x0
#define CHN7_LO1_ABUS_SEL_LSB                                                  0
#define CHN7_LO1_ABUS_SEL_MSB                                                  3
#define CHN7_LO1_ABUS_SEL_MASK                                                 0xf
#define CHN7_LO1_ABUS_SEL_GET(x)                                               (((x) & CHN7_LO1_ABUS_SEL_MASK) >> CHN7_LO1_ABUS_SEL_LSB)
#define CHN7_LO1_ABUS_SEL_SET(x)                                               (((0 | (x)) << CHN7_LO1_ABUS_SEL_LSB) & CHN7_LO1_ABUS_SEL_MASK)
#define CHN7_LO1_ABUS_SEL_RESET                                                0x0
#define CHN7_LO1_ADDRESS                                                       (0x4 + __CHN7_SYN_LO_REG_CSR_BASE_ADDRESS)
#define CHN7_LO1_RSTMASK                                                       0xffffffff
#define CHN7_LO1_RESET                                                         0x200000

// 0x8 (CHN7_LO2)
#define CHN7_LO2_LO_DTOP_SPARE_LSB                                             0
#define CHN7_LO2_LO_DTOP_SPARE_MSB                                             31
#define CHN7_LO2_LO_DTOP_SPARE_MASK                                            0xffffffff
#define CHN7_LO2_LO_DTOP_SPARE_GET(x)                                          (((x) & CHN7_LO2_LO_DTOP_SPARE_MASK) >> CHN7_LO2_LO_DTOP_SPARE_LSB)
#define CHN7_LO2_LO_DTOP_SPARE_SET(x)                                          (((0 | (x)) << CHN7_LO2_LO_DTOP_SPARE_LSB) & CHN7_LO2_LO_DTOP_SPARE_MASK)
#define CHN7_LO2_LO_DTOP_SPARE_RESET                                           0x0
#define CHN7_LO2_ADDRESS                                                       (0x8 + __CHN7_SYN_LO_REG_CSR_BASE_ADDRESS)
#define CHN7_LO2_RSTMASK                                                       0xffffffff
#define CHN7_LO2_RESET                                                         0x0



#endif /* _CHN7_SYN_LO_REG_CSR_H_ */
