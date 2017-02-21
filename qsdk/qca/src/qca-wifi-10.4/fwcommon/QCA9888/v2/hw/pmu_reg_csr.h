/*
 * Copyright (c) 2015 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#ifndef _PMU_REG_CSR_H_
#define _PMU_REG_CSR_H_


#ifndef __PMU_REG_CSR_BASE_ADDRESS
#define __PMU_REG_CSR_BASE_ADDRESS (0x91fc0)
#endif


// 0x0 (PM0)
#define PM0_ABUCKC_CLK_SEL_CFG_LSB                                             30
#define PM0_ABUCKC_CLK_SEL_CFG_MSB                                             31
#define PM0_ABUCKC_CLK_SEL_CFG_MASK                                            0xc0000000
#define PM0_ABUCKC_CLK_SEL_CFG_GET(x)                                          (((x) & PM0_ABUCKC_CLK_SEL_CFG_MASK) >> PM0_ABUCKC_CLK_SEL_CFG_LSB)
#define PM0_ABUCKC_CLK_SEL_CFG_SET(x)                                          (((0 | (x)) << PM0_ABUCKC_CLK_SEL_CFG_LSB) & PM0_ABUCKC_CLK_SEL_CFG_MASK)
#define PM0_ABUCKC_CLK_SEL_CFG_RESET                                           0x2
#define PM0_ABUCKC_CLK_DIV_XO_LSB                                              21
#define PM0_ABUCKC_CLK_DIV_XO_MSB                                              29
#define PM0_ABUCKC_CLK_DIV_XO_MASK                                             0x3fe00000
#define PM0_ABUCKC_CLK_DIV_XO_GET(x)                                           (((x) & PM0_ABUCKC_CLK_DIV_XO_MASK) >> PM0_ABUCKC_CLK_DIV_XO_LSB)
#define PM0_ABUCKC_CLK_DIV_XO_SET(x)                                           (((0 | (x)) << PM0_ABUCKC_CLK_DIV_XO_LSB) & PM0_ABUCKC_CLK_DIV_XO_MASK)
#define PM0_ABUCKC_CLK_DIV_XO_RESET                                            0x78
#define PM0_ABUCKC_CLK_DIV_SDM_CFG_LSB                                         19
#define PM0_ABUCKC_CLK_DIV_SDM_CFG_MSB                                         20
#define PM0_ABUCKC_CLK_DIV_SDM_CFG_MASK                                        0x180000
#define PM0_ABUCKC_CLK_DIV_SDM_CFG_GET(x)                                      (((x) & PM0_ABUCKC_CLK_DIV_SDM_CFG_MASK) >> PM0_ABUCKC_CLK_DIV_SDM_CFG_LSB)
#define PM0_ABUCKC_CLK_DIV_SDM_CFG_SET(x)                                      (((0 | (x)) << PM0_ABUCKC_CLK_DIV_SDM_CFG_LSB) & PM0_ABUCKC_CLK_DIV_SDM_CFG_MASK)
#define PM0_ABUCKC_CLK_DIV_SDM_CFG_RESET                                       0x0
#define PM0_ABUCKC_TRIM_LSB                                                    16
#define PM0_ABUCKC_TRIM_MSB                                                    18
#define PM0_ABUCKC_TRIM_MASK                                                   0x70000
#define PM0_ABUCKC_TRIM_GET(x)                                                 (((x) & PM0_ABUCKC_TRIM_MASK) >> PM0_ABUCKC_TRIM_LSB)
#define PM0_ABUCKC_TRIM_SET(x)                                                 (((0 | (x)) << PM0_ABUCKC_TRIM_LSB) & PM0_ABUCKC_TRIM_MASK)
#define PM0_ABUCKC_TRIM_RESET                                                  0x0
#define PM0_ABUCKC_XO_FREQ_CFG_LSB                                             12
#define PM0_ABUCKC_XO_FREQ_CFG_MSB                                             15
#define PM0_ABUCKC_XO_FREQ_CFG_MASK                                            0xf000
#define PM0_ABUCKC_XO_FREQ_CFG_GET(x)                                          (((x) & PM0_ABUCKC_XO_FREQ_CFG_MASK) >> PM0_ABUCKC_XO_FREQ_CFG_LSB)
#define PM0_ABUCKC_XO_FREQ_CFG_SET(x)                                          (((0 | (x)) << PM0_ABUCKC_XO_FREQ_CFG_LSB) & PM0_ABUCKC_XO_FREQ_CFG_MASK)
#define PM0_ABUCKC_XO_FREQ_CFG_RESET                                           0xc
#define PM0_ABUCKC_PFM_HYST_SEL_LSB                                            10
#define PM0_ABUCKC_PFM_HYST_SEL_MSB                                            11
#define PM0_ABUCKC_PFM_HYST_SEL_MASK                                           0xc00
#define PM0_ABUCKC_PFM_HYST_SEL_GET(x)                                         (((x) & PM0_ABUCKC_PFM_HYST_SEL_MASK) >> PM0_ABUCKC_PFM_HYST_SEL_LSB)
#define PM0_ABUCKC_PFM_HYST_SEL_SET(x)                                         (((0 | (x)) << PM0_ABUCKC_PFM_HYST_SEL_LSB) & PM0_ABUCKC_PFM_HYST_SEL_MASK)
#define PM0_ABUCKC_PFM_HYST_SEL_RESET                                          0x1
#define PM0_ABUCKC_RAMP_PK_LSB                                                 8
#define PM0_ABUCKC_RAMP_PK_MSB                                                 9
#define PM0_ABUCKC_RAMP_PK_MASK                                                0x300
#define PM0_ABUCKC_RAMP_PK_GET(x)                                              (((x) & PM0_ABUCKC_RAMP_PK_MASK) >> PM0_ABUCKC_RAMP_PK_LSB)
#define PM0_ABUCKC_RAMP_PK_SET(x)                                              (((0 | (x)) << PM0_ABUCKC_RAMP_PK_LSB) & PM0_ABUCKC_RAMP_PK_MASK)
#define PM0_ABUCKC_RAMP_PK_RESET                                               0x2
#define PM0_ABUCKP33_ZX_TRIM_LSB                                               3
#define PM0_ABUCKP33_ZX_TRIM_MSB                                               7
#define PM0_ABUCKP33_ZX_TRIM_MASK                                              0xf8
#define PM0_ABUCKP33_ZX_TRIM_GET(x)                                            (((x) & PM0_ABUCKP33_ZX_TRIM_MASK) >> PM0_ABUCKP33_ZX_TRIM_LSB)
#define PM0_ABUCKP33_ZX_TRIM_SET(x)                                            (((0 | (x)) << PM0_ABUCKP33_ZX_TRIM_LSB) & PM0_ABUCKP33_ZX_TRIM_MASK)
#define PM0_ABUCKP33_ZX_TRIM_RESET                                             0x4
#define PM0_RESERVED_0_LSB                                                     0
#define PM0_RESERVED_0_MSB                                                     2
#define PM0_RESERVED_0_MASK                                                    0x7
#define PM0_RESERVED_0_GET(x)                                                  (((x) & PM0_RESERVED_0_MASK) >> PM0_RESERVED_0_LSB)
#define PM0_RESERVED_0_SET(x)                                                  (((0 | (x)) << PM0_RESERVED_0_LSB) & PM0_RESERVED_0_MASK)
#define PM0_RESERVED_0_RESET                                                   0x0
#define PM0_ADDRESS                                                            (0x0 + __PMU_REG_CSR_BASE_ADDRESS)
#define PM0_RSTMASK                                                            0xffffffff
#define PM0_RESET                                                              0x8f00c620

// 0x4 (PM1)
#define PM1_ABUCKC_VSET_LSB                                                    25
#define PM1_ABUCKC_VSET_MSB                                                    31
#define PM1_ABUCKC_VSET_MASK                                                   0xfe000000
#define PM1_ABUCKC_VSET_GET(x)                                                 (((x) & PM1_ABUCKC_VSET_MASK) >> PM1_ABUCKC_VSET_LSB)
#define PM1_ABUCKC_VSET_SET(x)                                                 (((0 | (x)) << PM1_ABUCKC_VSET_LSB) & PM1_ABUCKC_VSET_MASK)
#define PM1_ABUCKC_VSET_RESET                                                  0x58
#define PM1_ABUCKC_CLK_DIV_LPO_LSB                                             16
#define PM1_ABUCKC_CLK_DIV_LPO_MSB                                             24
#define PM1_ABUCKC_CLK_DIV_LPO_MASK                                            0x1ff0000
#define PM1_ABUCKC_CLK_DIV_LPO_GET(x)                                          (((x) & PM1_ABUCKC_CLK_DIV_LPO_MASK) >> PM1_ABUCKC_CLK_DIV_LPO_LSB)
#define PM1_ABUCKC_CLK_DIV_LPO_SET(x)                                          (((0 | (x)) << PM1_ABUCKC_CLK_DIV_LPO_LSB) & PM1_ABUCKC_CLK_DIV_LPO_MASK)
#define PM1_ABUCKC_CLK_DIV_LPO_RESET                                           0x64
#define PM1_ABUCKC_C1_LSB                                                      12
#define PM1_ABUCKC_C1_MSB                                                      15
#define PM1_ABUCKC_C1_MASK                                                     0xf000
#define PM1_ABUCKC_C1_GET(x)                                                   (((x) & PM1_ABUCKC_C1_MASK) >> PM1_ABUCKC_C1_LSB)
#define PM1_ABUCKC_C1_SET(x)                                                   (((0 | (x)) << PM1_ABUCKC_C1_LSB) & PM1_ABUCKC_C1_MASK)
#define PM1_ABUCKC_C1_RESET                                                    0x1
#define PM1_ABUCKC_C2_LSB                                                      8
#define PM1_ABUCKC_C2_MSB                                                      11
#define PM1_ABUCKC_C2_MASK                                                     0xf00
#define PM1_ABUCKC_C2_GET(x)                                                   (((x) & PM1_ABUCKC_C2_MASK) >> PM1_ABUCKC_C2_LSB)
#define PM1_ABUCKC_C2_SET(x)                                                   (((0 | (x)) << PM1_ABUCKC_C2_LSB) & PM1_ABUCKC_C2_MASK)
#define PM1_ABUCKC_C2_RESET                                                    0x2
#define PM1_ABUCKC_C3_LSB                                                      4
#define PM1_ABUCKC_C3_MSB                                                      7
#define PM1_ABUCKC_C3_MASK                                                     0xf0
#define PM1_ABUCKC_C3_GET(x)                                                   (((x) & PM1_ABUCKC_C3_MASK) >> PM1_ABUCKC_C3_LSB)
#define PM1_ABUCKC_C3_SET(x)                                                   (((0 | (x)) << PM1_ABUCKC_C3_LSB) & PM1_ABUCKC_C3_MASK)
#define PM1_ABUCKC_C3_RESET                                                    0x3
#define PM1_ABUCKC_R1_LSB                                                      0
#define PM1_ABUCKC_R1_MSB                                                      3
#define PM1_ABUCKC_R1_MASK                                                     0xf
#define PM1_ABUCKC_R1_GET(x)                                                   (((x) & PM1_ABUCKC_R1_MASK) >> PM1_ABUCKC_R1_LSB)
#define PM1_ABUCKC_R1_SET(x)                                                   (((0 | (x)) << PM1_ABUCKC_R1_LSB) & PM1_ABUCKC_R1_MASK)
#define PM1_ABUCKC_R1_RESET                                                    0x6
#define PM1_ADDRESS                                                            (0x4 + __PMU_REG_CSR_BASE_ADDRESS)
#define PM1_RSTMASK                                                            0xffffffff
#define PM1_RESET                                                              0xb0641236

// 0x8 (PM2)
#define PM2_DBUCKC_CLK_SEL_CFG_LSB                                             30
#define PM2_DBUCKC_CLK_SEL_CFG_MSB                                             31
#define PM2_DBUCKC_CLK_SEL_CFG_MASK                                            0xc0000000
#define PM2_DBUCKC_CLK_SEL_CFG_GET(x)                                          (((x) & PM2_DBUCKC_CLK_SEL_CFG_MASK) >> PM2_DBUCKC_CLK_SEL_CFG_LSB)
#define PM2_DBUCKC_CLK_SEL_CFG_SET(x)                                          (((0 | (x)) << PM2_DBUCKC_CLK_SEL_CFG_LSB) & PM2_DBUCKC_CLK_SEL_CFG_MASK)
#define PM2_DBUCKC_CLK_SEL_CFG_RESET                                           0x2
#define PM2_DBUCKC_CLK_DIV_XO_LSB                                              21
#define PM2_DBUCKC_CLK_DIV_XO_MSB                                              29
#define PM2_DBUCKC_CLK_DIV_XO_MASK                                             0x3fe00000
#define PM2_DBUCKC_CLK_DIV_XO_GET(x)                                           (((x) & PM2_DBUCKC_CLK_DIV_XO_MASK) >> PM2_DBUCKC_CLK_DIV_XO_LSB)
#define PM2_DBUCKC_CLK_DIV_XO_SET(x)                                           (((0 | (x)) << PM2_DBUCKC_CLK_DIV_XO_LSB) & PM2_DBUCKC_CLK_DIV_XO_MASK)
#define PM2_DBUCKC_CLK_DIV_XO_RESET                                            0x3c
#define PM2_DBUCKC_CLK_DIV_SDM_CFG_LSB                                         19
#define PM2_DBUCKC_CLK_DIV_SDM_CFG_MSB                                         20
#define PM2_DBUCKC_CLK_DIV_SDM_CFG_MASK                                        0x180000
#define PM2_DBUCKC_CLK_DIV_SDM_CFG_GET(x)                                      (((x) & PM2_DBUCKC_CLK_DIV_SDM_CFG_MASK) >> PM2_DBUCKC_CLK_DIV_SDM_CFG_LSB)
#define PM2_DBUCKC_CLK_DIV_SDM_CFG_SET(x)                                      (((0 | (x)) << PM2_DBUCKC_CLK_DIV_SDM_CFG_LSB) & PM2_DBUCKC_CLK_DIV_SDM_CFG_MASK)
#define PM2_DBUCKC_CLK_DIV_SDM_CFG_RESET                                       0x0
#define PM2_DBUCKC_TRIM_LSB                                                    16
#define PM2_DBUCKC_TRIM_MSB                                                    18
#define PM2_DBUCKC_TRIM_MASK                                                   0x70000
#define PM2_DBUCKC_TRIM_GET(x)                                                 (((x) & PM2_DBUCKC_TRIM_MASK) >> PM2_DBUCKC_TRIM_LSB)
#define PM2_DBUCKC_TRIM_SET(x)                                                 (((0 | (x)) << PM2_DBUCKC_TRIM_LSB) & PM2_DBUCKC_TRIM_MASK)
#define PM2_DBUCKC_TRIM_RESET                                                  0x0
#define PM2_DBUCKC_XO_FREQ_CFG_LSB                                             12
#define PM2_DBUCKC_XO_FREQ_CFG_MSB                                             15
#define PM2_DBUCKC_XO_FREQ_CFG_MASK                                            0xf000
#define PM2_DBUCKC_XO_FREQ_CFG_GET(x)                                          (((x) & PM2_DBUCKC_XO_FREQ_CFG_MASK) >> PM2_DBUCKC_XO_FREQ_CFG_LSB)
#define PM2_DBUCKC_XO_FREQ_CFG_SET(x)                                          (((0 | (x)) << PM2_DBUCKC_XO_FREQ_CFG_LSB) & PM2_DBUCKC_XO_FREQ_CFG_MASK)
#define PM2_DBUCKC_XO_FREQ_CFG_RESET                                           0xc
#define PM2_DBUCKC_PFM_HYST_SEL_LSB                                            10
#define PM2_DBUCKC_PFM_HYST_SEL_MSB                                            11
#define PM2_DBUCKC_PFM_HYST_SEL_MASK                                           0xc00
#define PM2_DBUCKC_PFM_HYST_SEL_GET(x)                                         (((x) & PM2_DBUCKC_PFM_HYST_SEL_MASK) >> PM2_DBUCKC_PFM_HYST_SEL_LSB)
#define PM2_DBUCKC_PFM_HYST_SEL_SET(x)                                         (((0 | (x)) << PM2_DBUCKC_PFM_HYST_SEL_LSB) & PM2_DBUCKC_PFM_HYST_SEL_MASK)
#define PM2_DBUCKC_PFM_HYST_SEL_RESET                                          0x1
#define PM2_DBUCKC_RAMP_PK_LSB                                                 8
#define PM2_DBUCKC_RAMP_PK_MSB                                                 9
#define PM2_DBUCKC_RAMP_PK_MASK                                                0x300
#define PM2_DBUCKC_RAMP_PK_GET(x)                                              (((x) & PM2_DBUCKC_RAMP_PK_MASK) >> PM2_DBUCKC_RAMP_PK_LSB)
#define PM2_DBUCKC_RAMP_PK_SET(x)                                              (((0 | (x)) << PM2_DBUCKC_RAMP_PK_LSB) & PM2_DBUCKC_RAMP_PK_MASK)
#define PM2_DBUCKC_RAMP_PK_RESET                                               0x2
#define PM2_LDOOTP_VSET_LSB                                                    1
#define PM2_LDOOTP_VSET_MSB                                                    7
#define PM2_LDOOTP_VSET_MASK                                                   0xfe
#define PM2_LDOOTP_VSET_GET(x)                                                 (((x) & PM2_LDOOTP_VSET_MASK) >> PM2_LDOOTP_VSET_LSB)
#define PM2_LDOOTP_VSET_SET(x)                                                 (((0 | (x)) << PM2_LDOOTP_VSET_LSB) & PM2_LDOOTP_VSET_MASK)
#define PM2_LDOOTP_VSET_RESET                                                  0x64
#define PM2_RESERVED_0_LSB                                                     0
#define PM2_RESERVED_0_MSB                                                     0
#define PM2_RESERVED_0_MASK                                                    0x1
#define PM2_RESERVED_0_GET(x)                                                  (((x) & PM2_RESERVED_0_MASK) >> PM2_RESERVED_0_LSB)
#define PM2_RESERVED_0_SET(x)                                                  (((0 | (x)) << PM2_RESERVED_0_LSB) & PM2_RESERVED_0_MASK)
#define PM2_RESERVED_0_RESET                                                   0x0
#define PM2_ADDRESS                                                            (0x8 + __PMU_REG_CSR_BASE_ADDRESS)
#define PM2_RSTMASK                                                            0xffffffff
#define PM2_RESET                                                              0x8780c6c8

// 0xc (PM3)
#define PM3_DBUCKC_VSET_LSB                                                    25
#define PM3_DBUCKC_VSET_MSB                                                    31
#define PM3_DBUCKC_VSET_MASK                                                   0xfe000000
#define PM3_DBUCKC_VSET_GET(x)                                                 (((x) & PM3_DBUCKC_VSET_MASK) >> PM3_DBUCKC_VSET_LSB)
#define PM3_DBUCKC_VSET_SET(x)                                                 (((0 | (x)) << PM3_DBUCKC_VSET_LSB) & PM3_DBUCKC_VSET_MASK)
#define PM3_DBUCKC_VSET_RESET                                                  0x58
#define PM3_DBUCKC_CLK_DIV_LPO_LSB                                             16
#define PM3_DBUCKC_CLK_DIV_LPO_MSB                                             24
#define PM3_DBUCKC_CLK_DIV_LPO_MASK                                            0x1ff0000
#define PM3_DBUCKC_CLK_DIV_LPO_GET(x)                                          (((x) & PM3_DBUCKC_CLK_DIV_LPO_MASK) >> PM3_DBUCKC_CLK_DIV_LPO_LSB)
#define PM3_DBUCKC_CLK_DIV_LPO_SET(x)                                          (((0 | (x)) << PM3_DBUCKC_CLK_DIV_LPO_LSB) & PM3_DBUCKC_CLK_DIV_LPO_MASK)
#define PM3_DBUCKC_CLK_DIV_LPO_RESET                                           0x32
#define PM3_DBUCKC_C1_LSB                                                      12
#define PM3_DBUCKC_C1_MSB                                                      15
#define PM3_DBUCKC_C1_MASK                                                     0xf000
#define PM3_DBUCKC_C1_GET(x)                                                   (((x) & PM3_DBUCKC_C1_MASK) >> PM3_DBUCKC_C1_LSB)
#define PM3_DBUCKC_C1_SET(x)                                                   (((0 | (x)) << PM3_DBUCKC_C1_LSB) & PM3_DBUCKC_C1_MASK)
#define PM3_DBUCKC_C1_RESET                                                    0x1
#define PM3_DBUCKC_C2_LSB                                                      8
#define PM3_DBUCKC_C2_MSB                                                      11
#define PM3_DBUCKC_C2_MASK                                                     0xf00
#define PM3_DBUCKC_C2_GET(x)                                                   (((x) & PM3_DBUCKC_C2_MASK) >> PM3_DBUCKC_C2_LSB)
#define PM3_DBUCKC_C2_SET(x)                                                   (((0 | (x)) << PM3_DBUCKC_C2_LSB) & PM3_DBUCKC_C2_MASK)
#define PM3_DBUCKC_C2_RESET                                                    0x2
#define PM3_DBUCKC_C3_LSB                                                      4
#define PM3_DBUCKC_C3_MSB                                                      7
#define PM3_DBUCKC_C3_MASK                                                     0xf0
#define PM3_DBUCKC_C3_GET(x)                                                   (((x) & PM3_DBUCKC_C3_MASK) >> PM3_DBUCKC_C3_LSB)
#define PM3_DBUCKC_C3_SET(x)                                                   (((0 | (x)) << PM3_DBUCKC_C3_LSB) & PM3_DBUCKC_C3_MASK)
#define PM3_DBUCKC_C3_RESET                                                    0x3
#define PM3_DBUCKC_R1_LSB                                                      0
#define PM3_DBUCKC_R1_MSB                                                      3
#define PM3_DBUCKC_R1_MASK                                                     0xf
#define PM3_DBUCKC_R1_GET(x)                                                   (((x) & PM3_DBUCKC_R1_MASK) >> PM3_DBUCKC_R1_LSB)
#define PM3_DBUCKC_R1_SET(x)                                                   (((0 | (x)) << PM3_DBUCKC_R1_LSB) & PM3_DBUCKC_R1_MASK)
#define PM3_DBUCKC_R1_RESET                                                    0x6
#define PM3_ADDRESS                                                            (0xc + __PMU_REG_CSR_BASE_ADDRESS)
#define PM3_RSTMASK                                                            0xffffffff
#define PM3_RESET                                                              0xb0321236

// 0x10 (PM4)
#define PM4_DBUCKP33_EN_CL_CFG_LSB                                             31
#define PM4_DBUCKP33_EN_CL_CFG_MSB                                             31
#define PM4_DBUCKP33_EN_CL_CFG_MASK                                            0x80000000
#define PM4_DBUCKP33_EN_CL_CFG_GET(x)                                          (((x) & PM4_DBUCKP33_EN_CL_CFG_MASK) >> PM4_DBUCKP33_EN_CL_CFG_LSB)
#define PM4_DBUCKP33_EN_CL_CFG_SET(x)                                          (((0 | (x)) << PM4_DBUCKP33_EN_CL_CFG_LSB) & PM4_DBUCKP33_EN_CL_CFG_MASK)
#define PM4_DBUCKP33_EN_CL_CFG_RESET                                           0x1
#define PM4_DBUCKP33_CL_SEL_CFG_LSB                                            28
#define PM4_DBUCKP33_CL_SEL_CFG_MSB                                            30
#define PM4_DBUCKP33_CL_SEL_CFG_MASK                                           0x70000000
#define PM4_DBUCKP33_CL_SEL_CFG_GET(x)                                         (((x) & PM4_DBUCKP33_CL_SEL_CFG_MASK) >> PM4_DBUCKP33_CL_SEL_CFG_LSB)
#define PM4_DBUCKP33_CL_SEL_CFG_SET(x)                                         (((0 | (x)) << PM4_DBUCKP33_CL_SEL_CFG_LSB) & PM4_DBUCKP33_CL_SEL_CFG_MASK)
#define PM4_DBUCKP33_CL_SEL_CFG_RESET                                          0x1
#define PM4_DBUCKP33_SKIP_1ST_CL_LSB                                           27
#define PM4_DBUCKP33_SKIP_1ST_CL_MSB                                           27
#define PM4_DBUCKP33_SKIP_1ST_CL_MASK                                          0x8000000
#define PM4_DBUCKP33_SKIP_1ST_CL_GET(x)                                        (((x) & PM4_DBUCKP33_SKIP_1ST_CL_MASK) >> PM4_DBUCKP33_SKIP_1ST_CL_LSB)
#define PM4_DBUCKP33_SKIP_1ST_CL_SET(x)                                        (((0 | (x)) << PM4_DBUCKP33_SKIP_1ST_CL_LSB) & PM4_DBUCKP33_SKIP_1ST_CL_MASK)
#define PM4_DBUCKP33_SKIP_1ST_CL_RESET                                         0x0
#define PM4_DBUCKP33_DELAY_N_MIN_LSB                                           24
#define PM4_DBUCKP33_DELAY_N_MIN_MSB                                           26
#define PM4_DBUCKP33_DELAY_N_MIN_MASK                                          0x7000000
#define PM4_DBUCKP33_DELAY_N_MIN_GET(x)                                        (((x) & PM4_DBUCKP33_DELAY_N_MIN_MASK) >> PM4_DBUCKP33_DELAY_N_MIN_LSB)
#define PM4_DBUCKP33_DELAY_N_MIN_SET(x)                                        (((0 | (x)) << PM4_DBUCKP33_DELAY_N_MIN_LSB) & PM4_DBUCKP33_DELAY_N_MIN_MASK)
#define PM4_DBUCKP33_DELAY_N_MIN_RESET                                         0x3
#define PM4_DBUCKP33_DELAY_P_MIN_LSB                                           21
#define PM4_DBUCKP33_DELAY_P_MIN_MSB                                           23
#define PM4_DBUCKP33_DELAY_P_MIN_MASK                                          0xe00000
#define PM4_DBUCKP33_DELAY_P_MIN_GET(x)                                        (((x) & PM4_DBUCKP33_DELAY_P_MIN_MASK) >> PM4_DBUCKP33_DELAY_P_MIN_LSB)
#define PM4_DBUCKP33_DELAY_P_MIN_SET(x)                                        (((0 | (x)) << PM4_DBUCKP33_DELAY_P_MIN_LSB) & PM4_DBUCKP33_DELAY_P_MIN_MASK)
#define PM4_DBUCKP33_DELAY_P_MIN_RESET                                         0x3
#define PM4_DBUCKP33_ZX_TRIM_LSB                                               16
#define PM4_DBUCKP33_ZX_TRIM_MSB                                               20
#define PM4_DBUCKP33_ZX_TRIM_MASK                                              0x1f0000
#define PM4_DBUCKP33_ZX_TRIM_GET(x)                                            (((x) & PM4_DBUCKP33_ZX_TRIM_MASK) >> PM4_DBUCKP33_ZX_TRIM_LSB)
#define PM4_DBUCKP33_ZX_TRIM_SET(x)                                            (((0 | (x)) << PM4_DBUCKP33_ZX_TRIM_LSB) & PM4_DBUCKP33_ZX_TRIM_MASK)
#define PM4_DBUCKP33_ZX_TRIM_RESET                                             0x4
#define PM4_DBUCKP33_LPM_SEG_EN_LSB                                            12
#define PM4_DBUCKP33_LPM_SEG_EN_MSB                                            15
#define PM4_DBUCKP33_LPM_SEG_EN_MASK                                           0xf000
#define PM4_DBUCKP33_LPM_SEG_EN_GET(x)                                         (((x) & PM4_DBUCKP33_LPM_SEG_EN_MASK) >> PM4_DBUCKP33_LPM_SEG_EN_LSB)
#define PM4_DBUCKP33_LPM_SEG_EN_SET(x)                                         (((0 | (x)) << PM4_DBUCKP33_LPM_SEG_EN_LSB) & PM4_DBUCKP33_LPM_SEG_EN_MASK)
#define PM4_DBUCKP33_LPM_SEG_EN_RESET                                          0x1
#define PM4_DBUCKC_EN_OVR_LSB                                                  10
#define PM4_DBUCKC_EN_OVR_MSB                                                  11
#define PM4_DBUCKC_EN_OVR_MASK                                                 0xc00
#define PM4_DBUCKC_EN_OVR_GET(x)                                               (((x) & PM4_DBUCKC_EN_OVR_MASK) >> PM4_DBUCKC_EN_OVR_LSB)
#define PM4_DBUCKC_EN_OVR_SET(x)                                               (((0 | (x)) << PM4_DBUCKC_EN_OVR_LSB) & PM4_DBUCKC_EN_OVR_MASK)
#define PM4_DBUCKC_EN_OVR_RESET                                                0x0
#define PM4_PMCORE_V2I_RESCODE_LSB                                             4
#define PM4_PMCORE_V2I_RESCODE_MSB                                             9
#define PM4_PMCORE_V2I_RESCODE_MASK                                            0x3f0
#define PM4_PMCORE_V2I_RESCODE_GET(x)                                          (((x) & PM4_PMCORE_V2I_RESCODE_MASK) >> PM4_PMCORE_V2I_RESCODE_LSB)
#define PM4_PMCORE_V2I_RESCODE_SET(x)                                          (((0 | (x)) << PM4_PMCORE_V2I_RESCODE_LSB) & PM4_PMCORE_V2I_RESCODE_MASK)
#define PM4_PMCORE_V2I_RESCODE_RESET                                           0x20
#define PM4_PMCORE_VDDAO_TRIM_LSB                                              1
#define PM4_PMCORE_VDDAO_TRIM_MSB                                              3
#define PM4_PMCORE_VDDAO_TRIM_MASK                                             0xe
#define PM4_PMCORE_VDDAO_TRIM_GET(x)                                           (((x) & PM4_PMCORE_VDDAO_TRIM_MASK) >> PM4_PMCORE_VDDAO_TRIM_LSB)
#define PM4_PMCORE_VDDAO_TRIM_SET(x)                                           (((0 | (x)) << PM4_PMCORE_VDDAO_TRIM_LSB) & PM4_PMCORE_VDDAO_TRIM_MASK)
#define PM4_PMCORE_VDDAO_TRIM_RESET                                            0x0
#define PM4_RESERVED_0_LSB                                                     0
#define PM4_RESERVED_0_MSB                                                     0
#define PM4_RESERVED_0_MASK                                                    0x1
#define PM4_RESERVED_0_GET(x)                                                  (((x) & PM4_RESERVED_0_MASK) >> PM4_RESERVED_0_LSB)
#define PM4_RESERVED_0_SET(x)                                                  (((0 | (x)) << PM4_RESERVED_0_LSB) & PM4_RESERVED_0_MASK)
#define PM4_RESERVED_0_RESET                                                   0x0
#define PM4_ADDRESS                                                            (0x10 + __PMU_REG_CSR_BASE_ADDRESS)
#define PM4_RSTMASK                                                            0xffffffff
#define PM4_RESET                                                              0x93641200

// 0x14 (PM5)
#define PM5_ABUCKC_HYST_EN_OVR_LSB                                             30
#define PM5_ABUCKC_HYST_EN_OVR_MSB                                             31
#define PM5_ABUCKC_HYST_EN_OVR_MASK                                            0xc0000000
#define PM5_ABUCKC_HYST_EN_OVR_GET(x)                                          (((x) & PM5_ABUCKC_HYST_EN_OVR_MASK) >> PM5_ABUCKC_HYST_EN_OVR_LSB)
#define PM5_ABUCKC_HYST_EN_OVR_SET(x)                                          (((0 | (x)) << PM5_ABUCKC_HYST_EN_OVR_LSB) & PM5_ABUCKC_HYST_EN_OVR_MASK)
#define PM5_ABUCKC_HYST_EN_OVR_RESET                                           0x0
#define PM5_ABUCKC_UV_TRIG_SS_LSB                                              29
#define PM5_ABUCKC_UV_TRIG_SS_MSB                                              29
#define PM5_ABUCKC_UV_TRIG_SS_MASK                                             0x20000000
#define PM5_ABUCKC_UV_TRIG_SS_GET(x)                                           (((x) & PM5_ABUCKC_UV_TRIG_SS_MASK) >> PM5_ABUCKC_UV_TRIG_SS_LSB)
#define PM5_ABUCKC_UV_TRIG_SS_SET(x)                                           (((0 | (x)) << PM5_ABUCKC_UV_TRIG_SS_LSB) & PM5_ABUCKC_UV_TRIG_SS_MASK)
#define PM5_ABUCKC_UV_TRIG_SS_RESET                                            0x1
#define PM5_ABUCKC_MODE_FSM_MASK_EN_LSB                                        28
#define PM5_ABUCKC_MODE_FSM_MASK_EN_MSB                                        28
#define PM5_ABUCKC_MODE_FSM_MASK_EN_MASK                                       0x10000000
#define PM5_ABUCKC_MODE_FSM_MASK_EN_GET(x)                                     (((x) & PM5_ABUCKC_MODE_FSM_MASK_EN_MASK) >> PM5_ABUCKC_MODE_FSM_MASK_EN_LSB)
#define PM5_ABUCKC_MODE_FSM_MASK_EN_SET(x)                                     (((0 | (x)) << PM5_ABUCKC_MODE_FSM_MASK_EN_LSB) & PM5_ABUCKC_MODE_FSM_MASK_EN_MASK)
#define PM5_ABUCKC_MODE_FSM_MASK_EN_RESET                                      0x0
#define PM5_ABUCKC_MODE_FSM_MASK_VALUE_LSB                                     25
#define PM5_ABUCKC_MODE_FSM_MASK_VALUE_MSB                                     27
#define PM5_ABUCKC_MODE_FSM_MASK_VALUE_MASK                                    0xe000000
#define PM5_ABUCKC_MODE_FSM_MASK_VALUE_GET(x)                                  (((x) & PM5_ABUCKC_MODE_FSM_MASK_VALUE_MASK) >> PM5_ABUCKC_MODE_FSM_MASK_VALUE_LSB)
#define PM5_ABUCKC_MODE_FSM_MASK_VALUE_SET(x)                                  (((0 | (x)) << PM5_ABUCKC_MODE_FSM_MASK_VALUE_LSB) & PM5_ABUCKC_MODE_FSM_MASK_VALUE_MASK)
#define PM5_ABUCKC_MODE_FSM_MASK_VALUE_RESET                                   0x0
#define PM5_ABUCKC_SS_EN_LSB                                                   24
#define PM5_ABUCKC_SS_EN_MSB                                                   24
#define PM5_ABUCKC_SS_EN_MASK                                                  0x1000000
#define PM5_ABUCKC_SS_EN_GET(x)                                                (((x) & PM5_ABUCKC_SS_EN_MASK) >> PM5_ABUCKC_SS_EN_LSB)
#define PM5_ABUCKC_SS_EN_SET(x)                                                (((0 | (x)) << PM5_ABUCKC_SS_EN_LSB) & PM5_ABUCKC_SS_EN_MASK)
#define PM5_ABUCKC_SS_EN_RESET                                                 0x1
#define PM5_ABUCKC_VS_EN_LSB                                                   23
#define PM5_ABUCKC_VS_EN_MSB                                                   23
#define PM5_ABUCKC_VS_EN_MASK                                                  0x800000
#define PM5_ABUCKC_VS_EN_GET(x)                                                (((x) & PM5_ABUCKC_VS_EN_MASK) >> PM5_ABUCKC_VS_EN_LSB)
#define PM5_ABUCKC_VS_EN_SET(x)                                                (((0 | (x)) << PM5_ABUCKC_VS_EN_LSB) & PM5_ABUCKC_VS_EN_MASK)
#define PM5_ABUCKC_VS_EN_RESET                                                 0x1
#define PM5_ABUCKC_STEPPER_FORCE_TARGET_LSB                                    22
#define PM5_ABUCKC_STEPPER_FORCE_TARGET_MSB                                    22
#define PM5_ABUCKC_STEPPER_FORCE_TARGET_MASK                                   0x400000
#define PM5_ABUCKC_STEPPER_FORCE_TARGET_GET(x)                                 (((x) & PM5_ABUCKC_STEPPER_FORCE_TARGET_MASK) >> PM5_ABUCKC_STEPPER_FORCE_TARGET_LSB)
#define PM5_ABUCKC_STEPPER_FORCE_TARGET_SET(x)                                 (((0 | (x)) << PM5_ABUCKC_STEPPER_FORCE_TARGET_LSB) & PM5_ABUCKC_STEPPER_FORCE_TARGET_MASK)
#define PM5_ABUCKC_STEPPER_FORCE_TARGET_RESET                                  0x0
#define PM5_ABUCKC_STEPPER_DELAY_LSB                                           19
#define PM5_ABUCKC_STEPPER_DELAY_MSB                                           21
#define PM5_ABUCKC_STEPPER_DELAY_MASK                                          0x380000
#define PM5_ABUCKC_STEPPER_DELAY_GET(x)                                        (((x) & PM5_ABUCKC_STEPPER_DELAY_MASK) >> PM5_ABUCKC_STEPPER_DELAY_LSB)
#define PM5_ABUCKC_STEPPER_DELAY_SET(x)                                        (((0 | (x)) << PM5_ABUCKC_STEPPER_DELAY_LSB) & PM5_ABUCKC_STEPPER_DELAY_MASK)
#define PM5_ABUCKC_STEPPER_DELAY_RESET                                         0x4
#define PM5_ABUCKC_STEPPER_STEP_LSB                                            17
#define PM5_ABUCKC_STEPPER_STEP_MSB                                            18
#define PM5_ABUCKC_STEPPER_STEP_MASK                                           0x60000
#define PM5_ABUCKC_STEPPER_STEP_GET(x)                                         (((x) & PM5_ABUCKC_STEPPER_STEP_MASK) >> PM5_ABUCKC_STEPPER_STEP_LSB)
#define PM5_ABUCKC_STEPPER_STEP_SET(x)                                         (((0 | (x)) << PM5_ABUCKC_STEPPER_STEP_LSB) & PM5_ABUCKC_STEPPER_STEP_MASK)
#define PM5_ABUCKC_STEPPER_STEP_RESET                                          0x0
#define PM5_ABUCKC_DFT_PWM_MUX_LSB                                             15
#define PM5_ABUCKC_DFT_PWM_MUX_MSB                                             16
#define PM5_ABUCKC_DFT_PWM_MUX_MASK                                            0x18000
#define PM5_ABUCKC_DFT_PWM_MUX_GET(x)                                          (((x) & PM5_ABUCKC_DFT_PWM_MUX_MASK) >> PM5_ABUCKC_DFT_PWM_MUX_LSB)
#define PM5_ABUCKC_DFT_PWM_MUX_SET(x)                                          (((0 | (x)) << PM5_ABUCKC_DFT_PWM_MUX_LSB) & PM5_ABUCKC_DFT_PWM_MUX_MASK)
#define PM5_ABUCKC_DFT_PWM_MUX_RESET                                           0x0
#define PM5_ABUCKC_DTEST0_CFG_LSB                                              11
#define PM5_ABUCKC_DTEST0_CFG_MSB                                              14
#define PM5_ABUCKC_DTEST0_CFG_MASK                                             0x7800
#define PM5_ABUCKC_DTEST0_CFG_GET(x)                                           (((x) & PM5_ABUCKC_DTEST0_CFG_MASK) >> PM5_ABUCKC_DTEST0_CFG_LSB)
#define PM5_ABUCKC_DTEST0_CFG_SET(x)                                           (((0 | (x)) << PM5_ABUCKC_DTEST0_CFG_LSB) & PM5_ABUCKC_DTEST0_CFG_MASK)
#define PM5_ABUCKC_DTEST0_CFG_RESET                                            0x0
#define PM5_ABUCKC_DTEST1_CFG_LSB                                              7
#define PM5_ABUCKC_DTEST1_CFG_MSB                                              10
#define PM5_ABUCKC_DTEST1_CFG_MASK                                             0x780
#define PM5_ABUCKC_DTEST1_CFG_GET(x)                                           (((x) & PM5_ABUCKC_DTEST1_CFG_MASK) >> PM5_ABUCKC_DTEST1_CFG_LSB)
#define PM5_ABUCKC_DTEST1_CFG_SET(x)                                           (((0 | (x)) << PM5_ABUCKC_DTEST1_CFG_LSB) & PM5_ABUCKC_DTEST1_CFG_MASK)
#define PM5_ABUCKC_DTEST1_CFG_RESET                                            0x0
#define PM5_ABUCKC_ATB_SEL_LSB                                                 5
#define PM5_ABUCKC_ATB_SEL_MSB                                                 6
#define PM5_ABUCKC_ATB_SEL_MASK                                                0x60
#define PM5_ABUCKC_ATB_SEL_GET(x)                                              (((x) & PM5_ABUCKC_ATB_SEL_MASK) >> PM5_ABUCKC_ATB_SEL_LSB)
#define PM5_ABUCKC_ATB_SEL_SET(x)                                              (((0 | (x)) << PM5_ABUCKC_ATB_SEL_LSB) & PM5_ABUCKC_ATB_SEL_MASK)
#define PM5_ABUCKC_ATB_SEL_RESET                                               0x0
#define PM5_ABUCKC_EN_OVR_LSB                                                  3
#define PM5_ABUCKC_EN_OVR_MSB                                                  4
#define PM5_ABUCKC_EN_OVR_MASK                                                 0x18
#define PM5_ABUCKC_EN_OVR_GET(x)                                               (((x) & PM5_ABUCKC_EN_OVR_MASK) >> PM5_ABUCKC_EN_OVR_LSB)
#define PM5_ABUCKC_EN_OVR_SET(x)                                               (((0 | (x)) << PM5_ABUCKC_EN_OVR_LSB) & PM5_ABUCKC_EN_OVR_MASK)
#define PM5_ABUCKC_EN_OVR_RESET                                                0x0
#define PM5_RESERVED_0_LSB                                                     0
#define PM5_RESERVED_0_MSB                                                     2
#define PM5_RESERVED_0_MASK                                                    0x7
#define PM5_RESERVED_0_GET(x)                                                  (((x) & PM5_RESERVED_0_MASK) >> PM5_RESERVED_0_LSB)
#define PM5_RESERVED_0_SET(x)                                                  (((0 | (x)) << PM5_RESERVED_0_LSB) & PM5_RESERVED_0_MASK)
#define PM5_RESERVED_0_RESET                                                   0x0
#define PM5_ADDRESS                                                            (0x14 + __PMU_REG_CSR_BASE_ADDRESS)
#define PM5_RSTMASK                                                            0xffffffff
#define PM5_RESET                                                              0x21a00000

// 0x18 (PM6)
#define PM6_ABUCKP33_DTEST0_CFG_LSB                                            29
#define PM6_ABUCKP33_DTEST0_CFG_MSB                                            31
#define PM6_ABUCKP33_DTEST0_CFG_MASK                                           0xe0000000
#define PM6_ABUCKP33_DTEST0_CFG_GET(x)                                         (((x) & PM6_ABUCKP33_DTEST0_CFG_MASK) >> PM6_ABUCKP33_DTEST0_CFG_LSB)
#define PM6_ABUCKP33_DTEST0_CFG_SET(x)                                         (((0 | (x)) << PM6_ABUCKP33_DTEST0_CFG_LSB) & PM6_ABUCKP33_DTEST0_CFG_MASK)
#define PM6_ABUCKP33_DTEST0_CFG_RESET                                          0x0
#define PM6_ABUCKP33_DTEST1_CFG_LSB                                            26
#define PM6_ABUCKP33_DTEST1_CFG_MSB                                            28
#define PM6_ABUCKP33_DTEST1_CFG_MASK                                           0x1c000000
#define PM6_ABUCKP33_DTEST1_CFG_GET(x)                                         (((x) & PM6_ABUCKP33_DTEST1_CFG_MASK) >> PM6_ABUCKP33_DTEST1_CFG_LSB)
#define PM6_ABUCKP33_DTEST1_CFG_SET(x)                                         (((0 | (x)) << PM6_ABUCKP33_DTEST1_CFG_LSB) & PM6_ABUCKP33_DTEST1_CFG_MASK)
#define PM6_ABUCKP33_DTEST1_CFG_RESET                                          0x0
#define PM6_ABUCKP33_ZX_EN_CFG_LSB                                             24
#define PM6_ABUCKP33_ZX_EN_CFG_MSB                                             25
#define PM6_ABUCKP33_ZX_EN_CFG_MASK                                            0x3000000
#define PM6_ABUCKP33_ZX_EN_CFG_GET(x)                                          (((x) & PM6_ABUCKP33_ZX_EN_CFG_MASK) >> PM6_ABUCKP33_ZX_EN_CFG_LSB)
#define PM6_ABUCKP33_ZX_EN_CFG_SET(x)                                          (((0 | (x)) << PM6_ABUCKP33_ZX_EN_CFG_LSB) & PM6_ABUCKP33_ZX_EN_CFG_MASK)
#define PM6_ABUCKP33_ZX_EN_CFG_RESET                                           0x2
#define PM6_ABUCKP33_SEG_ENABLE_LSB                                            20
#define PM6_ABUCKP33_SEG_ENABLE_MSB                                            23
#define PM6_ABUCKP33_SEG_ENABLE_MASK                                           0xf00000
#define PM6_ABUCKP33_SEG_ENABLE_GET(x)                                         (((x) & PM6_ABUCKP33_SEG_ENABLE_MASK) >> PM6_ABUCKP33_SEG_ENABLE_LSB)
#define PM6_ABUCKP33_SEG_ENABLE_SET(x)                                         (((0 | (x)) << PM6_ABUCKP33_SEG_ENABLE_LSB) & PM6_ABUCKP33_SEG_ENABLE_MASK)
#define PM6_ABUCKP33_SEG_ENABLE_RESET                                          0xf
#define PM6_ABUCKP33_ZX_SAMPLE_DELAY_LSB                                       18
#define PM6_ABUCKP33_ZX_SAMPLE_DELAY_MSB                                       19
#define PM6_ABUCKP33_ZX_SAMPLE_DELAY_MASK                                      0xc0000
#define PM6_ABUCKP33_ZX_SAMPLE_DELAY_GET(x)                                    (((x) & PM6_ABUCKP33_ZX_SAMPLE_DELAY_MASK) >> PM6_ABUCKP33_ZX_SAMPLE_DELAY_LSB)
#define PM6_ABUCKP33_ZX_SAMPLE_DELAY_SET(x)                                    (((0 | (x)) << PM6_ABUCKP33_ZX_SAMPLE_DELAY_LSB) & PM6_ABUCKP33_ZX_SAMPLE_DELAY_MASK)
#define PM6_ABUCKP33_ZX_SAMPLE_DELAY_RESET                                     0x1
#define PM6_ABUCKP33_ADAPTIVE_ZX_EN_LSB                                        17
#define PM6_ABUCKP33_ADAPTIVE_ZX_EN_MSB                                        17
#define PM6_ABUCKP33_ADAPTIVE_ZX_EN_MASK                                       0x20000
#define PM6_ABUCKP33_ADAPTIVE_ZX_EN_GET(x)                                     (((x) & PM6_ABUCKP33_ADAPTIVE_ZX_EN_MASK) >> PM6_ABUCKP33_ADAPTIVE_ZX_EN_LSB)
#define PM6_ABUCKP33_ADAPTIVE_ZX_EN_SET(x)                                     (((0 | (x)) << PM6_ABUCKP33_ADAPTIVE_ZX_EN_LSB) & PM6_ABUCKP33_ADAPTIVE_ZX_EN_MASK)
#define PM6_ABUCKP33_ADAPTIVE_ZX_EN_RESET                                      0x0
#define PM6_ABUCKP33_SKIP_1ST_CL_LSB                                           16
#define PM6_ABUCKP33_SKIP_1ST_CL_MSB                                           16
#define PM6_ABUCKP33_SKIP_1ST_CL_MASK                                          0x10000
#define PM6_ABUCKP33_SKIP_1ST_CL_GET(x)                                        (((x) & PM6_ABUCKP33_SKIP_1ST_CL_MASK) >> PM6_ABUCKP33_SKIP_1ST_CL_LSB)
#define PM6_ABUCKP33_SKIP_1ST_CL_SET(x)                                        (((0 | (x)) << PM6_ABUCKP33_SKIP_1ST_CL_LSB) & PM6_ABUCKP33_SKIP_1ST_CL_MASK)
#define PM6_ABUCKP33_SKIP_1ST_CL_RESET                                         0x0
#define PM6_ABUCKP33_EN_CL_CFG_LSB                                             15
#define PM6_ABUCKP33_EN_CL_CFG_MSB                                             15
#define PM6_ABUCKP33_EN_CL_CFG_MASK                                            0x8000
#define PM6_ABUCKP33_EN_CL_CFG_GET(x)                                          (((x) & PM6_ABUCKP33_EN_CL_CFG_MASK) >> PM6_ABUCKP33_EN_CL_CFG_LSB)
#define PM6_ABUCKP33_EN_CL_CFG_SET(x)                                          (((0 | (x)) << PM6_ABUCKP33_EN_CL_CFG_LSB) & PM6_ABUCKP33_EN_CL_CFG_MASK)
#define PM6_ABUCKP33_EN_CL_CFG_RESET                                           0x1
#define PM6_ABUCKP33_CL_SEL_CFG_LSB                                            12
#define PM6_ABUCKP33_CL_SEL_CFG_MSB                                            14
#define PM6_ABUCKP33_CL_SEL_CFG_MASK                                           0x7000
#define PM6_ABUCKP33_CL_SEL_CFG_GET(x)                                         (((x) & PM6_ABUCKP33_CL_SEL_CFG_MASK) >> PM6_ABUCKP33_CL_SEL_CFG_LSB)
#define PM6_ABUCKP33_CL_SEL_CFG_SET(x)                                         (((0 | (x)) << PM6_ABUCKP33_CL_SEL_CFG_LSB) & PM6_ABUCKP33_CL_SEL_CFG_MASK)
#define PM6_ABUCKP33_CL_SEL_CFG_RESET                                          0x7
#define PM6_ABUCKP33_DELAY_N_MIN_LSB                                           9
#define PM6_ABUCKP33_DELAY_N_MIN_MSB                                           11
#define PM6_ABUCKP33_DELAY_N_MIN_MASK                                          0xe00
#define PM6_ABUCKP33_DELAY_N_MIN_GET(x)                                        (((x) & PM6_ABUCKP33_DELAY_N_MIN_MASK) >> PM6_ABUCKP33_DELAY_N_MIN_LSB)
#define PM6_ABUCKP33_DELAY_N_MIN_SET(x)                                        (((0 | (x)) << PM6_ABUCKP33_DELAY_N_MIN_LSB) & PM6_ABUCKP33_DELAY_N_MIN_MASK)
#define PM6_ABUCKP33_DELAY_N_MIN_RESET                                         0x4
#define PM6_ABUCKP33_DELAY_P_MIN_LSB                                           6
#define PM6_ABUCKP33_DELAY_P_MIN_MSB                                           8
#define PM6_ABUCKP33_DELAY_P_MIN_MASK                                          0x1c0
#define PM6_ABUCKP33_DELAY_P_MIN_GET(x)                                        (((x) & PM6_ABUCKP33_DELAY_P_MIN_MASK) >> PM6_ABUCKP33_DELAY_P_MIN_LSB)
#define PM6_ABUCKP33_DELAY_P_MIN_SET(x)                                        (((0 | (x)) << PM6_ABUCKP33_DELAY_P_MIN_LSB) & PM6_ABUCKP33_DELAY_P_MIN_MASK)
#define PM6_ABUCKP33_DELAY_P_MIN_RESET                                         0x4
#define PM6_RESERVED_0_LSB                                                     0
#define PM6_RESERVED_0_MSB                                                     5
#define PM6_RESERVED_0_MASK                                                    0x3f
#define PM6_RESERVED_0_GET(x)                                                  (((x) & PM6_RESERVED_0_MASK) >> PM6_RESERVED_0_LSB)
#define PM6_RESERVED_0_SET(x)                                                  (((0 | (x)) << PM6_RESERVED_0_LSB) & PM6_RESERVED_0_MASK)
#define PM6_RESERVED_0_RESET                                                   0x0
#define PM6_ADDRESS                                                            (0x18 + __PMU_REG_CSR_BASE_ADDRESS)
#define PM6_RSTMASK                                                            0xffffffff
#define PM6_RESET                                                              0x2f4f900

// 0x1c (PM7)
#define PM7_DBUCKC_HYST_EN_OVR_LSB                                             30
#define PM7_DBUCKC_HYST_EN_OVR_MSB                                             31
#define PM7_DBUCKC_HYST_EN_OVR_MASK                                            0xc0000000
#define PM7_DBUCKC_HYST_EN_OVR_GET(x)                                          (((x) & PM7_DBUCKC_HYST_EN_OVR_MASK) >> PM7_DBUCKC_HYST_EN_OVR_LSB)
#define PM7_DBUCKC_HYST_EN_OVR_SET(x)                                          (((0 | (x)) << PM7_DBUCKC_HYST_EN_OVR_LSB) & PM7_DBUCKC_HYST_EN_OVR_MASK)
#define PM7_DBUCKC_HYST_EN_OVR_RESET                                           0x0
#define PM7_DBUCKC_UV_TRIG_SS_LSB                                              29
#define PM7_DBUCKC_UV_TRIG_SS_MSB                                              29
#define PM7_DBUCKC_UV_TRIG_SS_MASK                                             0x20000000
#define PM7_DBUCKC_UV_TRIG_SS_GET(x)                                           (((x) & PM7_DBUCKC_UV_TRIG_SS_MASK) >> PM7_DBUCKC_UV_TRIG_SS_LSB)
#define PM7_DBUCKC_UV_TRIG_SS_SET(x)                                           (((0 | (x)) << PM7_DBUCKC_UV_TRIG_SS_LSB) & PM7_DBUCKC_UV_TRIG_SS_MASK)
#define PM7_DBUCKC_UV_TRIG_SS_RESET                                            0x1
#define PM7_DBUCKC_MODE_FSM_MASK_EN_LSB                                        28
#define PM7_DBUCKC_MODE_FSM_MASK_EN_MSB                                        28
#define PM7_DBUCKC_MODE_FSM_MASK_EN_MASK                                       0x10000000
#define PM7_DBUCKC_MODE_FSM_MASK_EN_GET(x)                                     (((x) & PM7_DBUCKC_MODE_FSM_MASK_EN_MASK) >> PM7_DBUCKC_MODE_FSM_MASK_EN_LSB)
#define PM7_DBUCKC_MODE_FSM_MASK_EN_SET(x)                                     (((0 | (x)) << PM7_DBUCKC_MODE_FSM_MASK_EN_LSB) & PM7_DBUCKC_MODE_FSM_MASK_EN_MASK)
#define PM7_DBUCKC_MODE_FSM_MASK_EN_RESET                                      0x0
#define PM7_DBUCKC_MODE_FSM_MASK_VALUE_LSB                                     25
#define PM7_DBUCKC_MODE_FSM_MASK_VALUE_MSB                                     27
#define PM7_DBUCKC_MODE_FSM_MASK_VALUE_MASK                                    0xe000000
#define PM7_DBUCKC_MODE_FSM_MASK_VALUE_GET(x)                                  (((x) & PM7_DBUCKC_MODE_FSM_MASK_VALUE_MASK) >> PM7_DBUCKC_MODE_FSM_MASK_VALUE_LSB)
#define PM7_DBUCKC_MODE_FSM_MASK_VALUE_SET(x)                                  (((0 | (x)) << PM7_DBUCKC_MODE_FSM_MASK_VALUE_LSB) & PM7_DBUCKC_MODE_FSM_MASK_VALUE_MASK)
#define PM7_DBUCKC_MODE_FSM_MASK_VALUE_RESET                                   0x0
#define PM7_DBUCKC_SS_EN_LSB                                                   24
#define PM7_DBUCKC_SS_EN_MSB                                                   24
#define PM7_DBUCKC_SS_EN_MASK                                                  0x1000000
#define PM7_DBUCKC_SS_EN_GET(x)                                                (((x) & PM7_DBUCKC_SS_EN_MASK) >> PM7_DBUCKC_SS_EN_LSB)
#define PM7_DBUCKC_SS_EN_SET(x)                                                (((0 | (x)) << PM7_DBUCKC_SS_EN_LSB) & PM7_DBUCKC_SS_EN_MASK)
#define PM7_DBUCKC_SS_EN_RESET                                                 0x1
#define PM7_DBUCKC_VS_EN_LSB                                                   23
#define PM7_DBUCKC_VS_EN_MSB                                                   23
#define PM7_DBUCKC_VS_EN_MASK                                                  0x800000
#define PM7_DBUCKC_VS_EN_GET(x)                                                (((x) & PM7_DBUCKC_VS_EN_MASK) >> PM7_DBUCKC_VS_EN_LSB)
#define PM7_DBUCKC_VS_EN_SET(x)                                                (((0 | (x)) << PM7_DBUCKC_VS_EN_LSB) & PM7_DBUCKC_VS_EN_MASK)
#define PM7_DBUCKC_VS_EN_RESET                                                 0x1
#define PM7_DBUCKC_STEPPER_FORCE_TARGET_LSB                                    22
#define PM7_DBUCKC_STEPPER_FORCE_TARGET_MSB                                    22
#define PM7_DBUCKC_STEPPER_FORCE_TARGET_MASK                                   0x400000
#define PM7_DBUCKC_STEPPER_FORCE_TARGET_GET(x)                                 (((x) & PM7_DBUCKC_STEPPER_FORCE_TARGET_MASK) >> PM7_DBUCKC_STEPPER_FORCE_TARGET_LSB)
#define PM7_DBUCKC_STEPPER_FORCE_TARGET_SET(x)                                 (((0 | (x)) << PM7_DBUCKC_STEPPER_FORCE_TARGET_LSB) & PM7_DBUCKC_STEPPER_FORCE_TARGET_MASK)
#define PM7_DBUCKC_STEPPER_FORCE_TARGET_RESET                                  0x0
#define PM7_DBUCKC_STEPPER_DELAY_LSB                                           19
#define PM7_DBUCKC_STEPPER_DELAY_MSB                                           21
#define PM7_DBUCKC_STEPPER_DELAY_MASK                                          0x380000
#define PM7_DBUCKC_STEPPER_DELAY_GET(x)                                        (((x) & PM7_DBUCKC_STEPPER_DELAY_MASK) >> PM7_DBUCKC_STEPPER_DELAY_LSB)
#define PM7_DBUCKC_STEPPER_DELAY_SET(x)                                        (((0 | (x)) << PM7_DBUCKC_STEPPER_DELAY_LSB) & PM7_DBUCKC_STEPPER_DELAY_MASK)
#define PM7_DBUCKC_STEPPER_DELAY_RESET                                         0x4
#define PM7_DBUCKC_STEPPER_STEP_LSB                                            17
#define PM7_DBUCKC_STEPPER_STEP_MSB                                            18
#define PM7_DBUCKC_STEPPER_STEP_MASK                                           0x60000
#define PM7_DBUCKC_STEPPER_STEP_GET(x)                                         (((x) & PM7_DBUCKC_STEPPER_STEP_MASK) >> PM7_DBUCKC_STEPPER_STEP_LSB)
#define PM7_DBUCKC_STEPPER_STEP_SET(x)                                         (((0 | (x)) << PM7_DBUCKC_STEPPER_STEP_LSB) & PM7_DBUCKC_STEPPER_STEP_MASK)
#define PM7_DBUCKC_STEPPER_STEP_RESET                                          0x0
#define PM7_DBUCKC_DFT_PWM_MUX_LSB                                             15
#define PM7_DBUCKC_DFT_PWM_MUX_MSB                                             16
#define PM7_DBUCKC_DFT_PWM_MUX_MASK                                            0x18000
#define PM7_DBUCKC_DFT_PWM_MUX_GET(x)                                          (((x) & PM7_DBUCKC_DFT_PWM_MUX_MASK) >> PM7_DBUCKC_DFT_PWM_MUX_LSB)
#define PM7_DBUCKC_DFT_PWM_MUX_SET(x)                                          (((0 | (x)) << PM7_DBUCKC_DFT_PWM_MUX_LSB) & PM7_DBUCKC_DFT_PWM_MUX_MASK)
#define PM7_DBUCKC_DFT_PWM_MUX_RESET                                           0x0
#define PM7_DBUCKC_DTEST0_CFG_LSB                                              11
#define PM7_DBUCKC_DTEST0_CFG_MSB                                              14
#define PM7_DBUCKC_DTEST0_CFG_MASK                                             0x7800
#define PM7_DBUCKC_DTEST0_CFG_GET(x)                                           (((x) & PM7_DBUCKC_DTEST0_CFG_MASK) >> PM7_DBUCKC_DTEST0_CFG_LSB)
#define PM7_DBUCKC_DTEST0_CFG_SET(x)                                           (((0 | (x)) << PM7_DBUCKC_DTEST0_CFG_LSB) & PM7_DBUCKC_DTEST0_CFG_MASK)
#define PM7_DBUCKC_DTEST0_CFG_RESET                                            0x0
#define PM7_DBUCKC_DTEST1_CFG_LSB                                              7
#define PM7_DBUCKC_DTEST1_CFG_MSB                                              10
#define PM7_DBUCKC_DTEST1_CFG_MASK                                             0x780
#define PM7_DBUCKC_DTEST1_CFG_GET(x)                                           (((x) & PM7_DBUCKC_DTEST1_CFG_MASK) >> PM7_DBUCKC_DTEST1_CFG_LSB)
#define PM7_DBUCKC_DTEST1_CFG_SET(x)                                           (((0 | (x)) << PM7_DBUCKC_DTEST1_CFG_LSB) & PM7_DBUCKC_DTEST1_CFG_MASK)
#define PM7_DBUCKC_DTEST1_CFG_RESET                                            0x0
#define PM7_DBUCKC_ATB_SEL_LSB                                                 5
#define PM7_DBUCKC_ATB_SEL_MSB                                                 6
#define PM7_DBUCKC_ATB_SEL_MASK                                                0x60
#define PM7_DBUCKC_ATB_SEL_GET(x)                                              (((x) & PM7_DBUCKC_ATB_SEL_MASK) >> PM7_DBUCKC_ATB_SEL_LSB)
#define PM7_DBUCKC_ATB_SEL_SET(x)                                              (((0 | (x)) << PM7_DBUCKC_ATB_SEL_LSB) & PM7_DBUCKC_ATB_SEL_MASK)
#define PM7_DBUCKC_ATB_SEL_RESET                                               0x0
#define PM7_RESERVED_0_LSB                                                     0
#define PM7_RESERVED_0_MSB                                                     4
#define PM7_RESERVED_0_MASK                                                    0x1f
#define PM7_RESERVED_0_GET(x)                                                  (((x) & PM7_RESERVED_0_MASK) >> PM7_RESERVED_0_LSB)
#define PM7_RESERVED_0_SET(x)                                                  (((0 | (x)) << PM7_RESERVED_0_LSB) & PM7_RESERVED_0_MASK)
#define PM7_RESERVED_0_RESET                                                   0x0
#define PM7_ADDRESS                                                            (0x1c + __PMU_REG_CSR_BASE_ADDRESS)
#define PM7_RSTMASK                                                            0xffffffff
#define PM7_RESET                                                              0x21a00000

// 0x20 (PM8)
#define PM8_DBUCKP33_DTEST0_CFG_LSB                                            29
#define PM8_DBUCKP33_DTEST0_CFG_MSB                                            31
#define PM8_DBUCKP33_DTEST0_CFG_MASK                                           0xe0000000
#define PM8_DBUCKP33_DTEST0_CFG_GET(x)                                         (((x) & PM8_DBUCKP33_DTEST0_CFG_MASK) >> PM8_DBUCKP33_DTEST0_CFG_LSB)
#define PM8_DBUCKP33_DTEST0_CFG_SET(x)                                         (((0 | (x)) << PM8_DBUCKP33_DTEST0_CFG_LSB) & PM8_DBUCKP33_DTEST0_CFG_MASK)
#define PM8_DBUCKP33_DTEST0_CFG_RESET                                          0x0
#define PM8_DBUCKP33_DTEST1_CFG_LSB                                            26
#define PM8_DBUCKP33_DTEST1_CFG_MSB                                            28
#define PM8_DBUCKP33_DTEST1_CFG_MASK                                           0x1c000000
#define PM8_DBUCKP33_DTEST1_CFG_GET(x)                                         (((x) & PM8_DBUCKP33_DTEST1_CFG_MASK) >> PM8_DBUCKP33_DTEST1_CFG_LSB)
#define PM8_DBUCKP33_DTEST1_CFG_SET(x)                                         (((0 | (x)) << PM8_DBUCKP33_DTEST1_CFG_LSB) & PM8_DBUCKP33_DTEST1_CFG_MASK)
#define PM8_DBUCKP33_DTEST1_CFG_RESET                                          0x0
#define PM8_DBUCKP33_ZX_EN_CFG_LSB                                             24
#define PM8_DBUCKP33_ZX_EN_CFG_MSB                                             25
#define PM8_DBUCKP33_ZX_EN_CFG_MASK                                            0x3000000
#define PM8_DBUCKP33_ZX_EN_CFG_GET(x)                                          (((x) & PM8_DBUCKP33_ZX_EN_CFG_MASK) >> PM8_DBUCKP33_ZX_EN_CFG_LSB)
#define PM8_DBUCKP33_ZX_EN_CFG_SET(x)                                          (((0 | (x)) << PM8_DBUCKP33_ZX_EN_CFG_LSB) & PM8_DBUCKP33_ZX_EN_CFG_MASK)
#define PM8_DBUCKP33_ZX_EN_CFG_RESET                                           0x2
#define PM8_DBUCKP33_SEG_ENABLE_LSB                                            20
#define PM8_DBUCKP33_SEG_ENABLE_MSB                                            23
#define PM8_DBUCKP33_SEG_ENABLE_MASK                                           0xf00000
#define PM8_DBUCKP33_SEG_ENABLE_GET(x)                                         (((x) & PM8_DBUCKP33_SEG_ENABLE_MASK) >> PM8_DBUCKP33_SEG_ENABLE_LSB)
#define PM8_DBUCKP33_SEG_ENABLE_SET(x)                                         (((0 | (x)) << PM8_DBUCKP33_SEG_ENABLE_LSB) & PM8_DBUCKP33_SEG_ENABLE_MASK)
#define PM8_DBUCKP33_SEG_ENABLE_RESET                                          0xf
#define PM8_DBUCKP33_ZX_SAMPLE_DELAY_LSB                                       18
#define PM8_DBUCKP33_ZX_SAMPLE_DELAY_MSB                                       19
#define PM8_DBUCKP33_ZX_SAMPLE_DELAY_MASK                                      0xc0000
#define PM8_DBUCKP33_ZX_SAMPLE_DELAY_GET(x)                                    (((x) & PM8_DBUCKP33_ZX_SAMPLE_DELAY_MASK) >> PM8_DBUCKP33_ZX_SAMPLE_DELAY_LSB)
#define PM8_DBUCKP33_ZX_SAMPLE_DELAY_SET(x)                                    (((0 | (x)) << PM8_DBUCKP33_ZX_SAMPLE_DELAY_LSB) & PM8_DBUCKP33_ZX_SAMPLE_DELAY_MASK)
#define PM8_DBUCKP33_ZX_SAMPLE_DELAY_RESET                                     0x1
#define PM8_DBUCKP33_ADAPTIVE_ZX_EN_LSB                                        17
#define PM8_DBUCKP33_ADAPTIVE_ZX_EN_MSB                                        17
#define PM8_DBUCKP33_ADAPTIVE_ZX_EN_MASK                                       0x20000
#define PM8_DBUCKP33_ADAPTIVE_ZX_EN_GET(x)                                     (((x) & PM8_DBUCKP33_ADAPTIVE_ZX_EN_MASK) >> PM8_DBUCKP33_ADAPTIVE_ZX_EN_LSB)
#define PM8_DBUCKP33_ADAPTIVE_ZX_EN_SET(x)                                     (((0 | (x)) << PM8_DBUCKP33_ADAPTIVE_ZX_EN_LSB) & PM8_DBUCKP33_ADAPTIVE_ZX_EN_MASK)
#define PM8_DBUCKP33_ADAPTIVE_ZX_EN_RESET                                      0x0
#define PM8_RESERVED_0_LSB                                                     0
#define PM8_RESERVED_0_MSB                                                     16
#define PM8_RESERVED_0_MASK                                                    0x1ffff
#define PM8_RESERVED_0_GET(x)                                                  (((x) & PM8_RESERVED_0_MASK) >> PM8_RESERVED_0_LSB)
#define PM8_RESERVED_0_SET(x)                                                  (((0 | (x)) << PM8_RESERVED_0_LSB) & PM8_RESERVED_0_MASK)
#define PM8_RESERVED_0_RESET                                                   0x0
#define PM8_ADDRESS                                                            (0x20 + __PMU_REG_CSR_BASE_ADDRESS)
#define PM8_RSTMASK                                                            0xffffffff
#define PM8_RESET                                                              0x2f40000

// 0x24 (PM9)
#define PM9_LDOOTP_EN_OVR_LSB                                                  30
#define PM9_LDOOTP_EN_OVR_MSB                                                  31
#define PM9_LDOOTP_EN_OVR_MASK                                                 0xc0000000
#define PM9_LDOOTP_EN_OVR_GET(x)                                               (((x) & PM9_LDOOTP_EN_OVR_MASK) >> PM9_LDOOTP_EN_OVR_LSB)
#define PM9_LDOOTP_EN_OVR_SET(x)                                               (((0 | (x)) << PM9_LDOOTP_EN_OVR_LSB) & PM9_LDOOTP_EN_OVR_MASK)
#define PM9_LDOOTP_EN_OVR_RESET                                                0x0
#define PM9_LDOOTP_EN_SS_LSB                                                   29
#define PM9_LDOOTP_EN_SS_MSB                                                   29
#define PM9_LDOOTP_EN_SS_MASK                                                  0x20000000
#define PM9_LDOOTP_EN_SS_GET(x)                                                (((x) & PM9_LDOOTP_EN_SS_MASK) >> PM9_LDOOTP_EN_SS_LSB)
#define PM9_LDOOTP_EN_SS_SET(x)                                                (((0 | (x)) << PM9_LDOOTP_EN_SS_LSB) & PM9_LDOOTP_EN_SS_MASK)
#define PM9_LDOOTP_EN_SS_RESET                                                 0x1
#define PM9_LDOOTP_STEPPER_FORCE_TARGET_LSB                                    28
#define PM9_LDOOTP_STEPPER_FORCE_TARGET_MSB                                    28
#define PM9_LDOOTP_STEPPER_FORCE_TARGET_MASK                                   0x10000000
#define PM9_LDOOTP_STEPPER_FORCE_TARGET_GET(x)                                 (((x) & PM9_LDOOTP_STEPPER_FORCE_TARGET_MASK) >> PM9_LDOOTP_STEPPER_FORCE_TARGET_LSB)
#define PM9_LDOOTP_STEPPER_FORCE_TARGET_SET(x)                                 (((0 | (x)) << PM9_LDOOTP_STEPPER_FORCE_TARGET_LSB) & PM9_LDOOTP_STEPPER_FORCE_TARGET_MASK)
#define PM9_LDOOTP_STEPPER_FORCE_TARGET_RESET                                  0x0
#define PM9_LDOOTP_STEPPER_DELAY_LSB                                           25
#define PM9_LDOOTP_STEPPER_DELAY_MSB                                           27
#define PM9_LDOOTP_STEPPER_DELAY_MASK                                          0xe000000
#define PM9_LDOOTP_STEPPER_DELAY_GET(x)                                        (((x) & PM9_LDOOTP_STEPPER_DELAY_MASK) >> PM9_LDOOTP_STEPPER_DELAY_LSB)
#define PM9_LDOOTP_STEPPER_DELAY_SET(x)                                        (((0 | (x)) << PM9_LDOOTP_STEPPER_DELAY_LSB) & PM9_LDOOTP_STEPPER_DELAY_MASK)
#define PM9_LDOOTP_STEPPER_DELAY_RESET                                         0x4
#define PM9_LDOOTP_STEPPER_STEP_LSB                                            23
#define PM9_LDOOTP_STEPPER_STEP_MSB                                            24
#define PM9_LDOOTP_STEPPER_STEP_MASK                                           0x1800000
#define PM9_LDOOTP_STEPPER_STEP_GET(x)                                         (((x) & PM9_LDOOTP_STEPPER_STEP_MASK) >> PM9_LDOOTP_STEPPER_STEP_LSB)
#define PM9_LDOOTP_STEPPER_STEP_SET(x)                                         (((0 | (x)) << PM9_LDOOTP_STEPPER_STEP_LSB) & PM9_LDOOTP_STEPPER_STEP_MASK)
#define PM9_LDOOTP_STEPPER_STEP_RESET                                          0x0
#define PM9_LDOOTP_ATB_EN_LSB                                                  22
#define PM9_LDOOTP_ATB_EN_MSB                                                  22
#define PM9_LDOOTP_ATB_EN_MASK                                                 0x400000
#define PM9_LDOOTP_ATB_EN_GET(x)                                               (((x) & PM9_LDOOTP_ATB_EN_MASK) >> PM9_LDOOTP_ATB_EN_LSB)
#define PM9_LDOOTP_ATB_EN_SET(x)                                               (((0 | (x)) << PM9_LDOOTP_ATB_EN_LSB) & PM9_LDOOTP_ATB_EN_MASK)
#define PM9_LDOOTP_ATB_EN_RESET                                                0x0
#define PM9_LPO2M_EN_OVR_LSB                                                   20
#define PM9_LPO2M_EN_OVR_MSB                                                   21
#define PM9_LPO2M_EN_OVR_MASK                                                  0x300000
#define PM9_LPO2M_EN_OVR_GET(x)                                                (((x) & PM9_LPO2M_EN_OVR_MASK) >> PM9_LPO2M_EN_OVR_LSB)
#define PM9_LPO2M_EN_OVR_SET(x)                                                (((0 | (x)) << PM9_LPO2M_EN_OVR_LSB) & PM9_LPO2M_EN_OVR_MASK)
#define PM9_LPO2M_EN_OVR_RESET                                                 0x0
#define PM9_PMCORE_AO_PWD_LSB                                                  19
#define PM9_PMCORE_AO_PWD_MSB                                                  19
#define PM9_PMCORE_AO_PWD_MASK                                                 0x80000
#define PM9_PMCORE_AO_PWD_GET(x)                                               (((x) & PM9_PMCORE_AO_PWD_MASK) >> PM9_PMCORE_AO_PWD_LSB)
#define PM9_PMCORE_AO_PWD_SET(x)                                               (((0 | (x)) << PM9_PMCORE_AO_PWD_LSB) & PM9_PMCORE_AO_PWD_MASK)
#define PM9_PMCORE_AO_PWD_RESET                                                0x0
#define PM9_PMCORE_ATB_EN_LSB                                                  18
#define PM9_PMCORE_ATB_EN_MSB                                                  18
#define PM9_PMCORE_ATB_EN_MASK                                                 0x40000
#define PM9_PMCORE_ATB_EN_GET(x)                                               (((x) & PM9_PMCORE_ATB_EN_MASK) >> PM9_PMCORE_ATB_EN_LSB)
#define PM9_PMCORE_ATB_EN_SET(x)                                               (((0 | (x)) << PM9_PMCORE_ATB_EN_LSB) & PM9_PMCORE_ATB_EN_MASK)
#define PM9_PMCORE_ATB_EN_RESET                                                0x0
#define PM9_PMCORE_ATB_ISEL_LSB                                                16
#define PM9_PMCORE_ATB_ISEL_MSB                                                17
#define PM9_PMCORE_ATB_ISEL_MASK                                               0x30000
#define PM9_PMCORE_ATB_ISEL_GET(x)                                             (((x) & PM9_PMCORE_ATB_ISEL_MASK) >> PM9_PMCORE_ATB_ISEL_LSB)
#define PM9_PMCORE_ATB_ISEL_SET(x)                                             (((0 | (x)) << PM9_PMCORE_ATB_ISEL_LSB) & PM9_PMCORE_ATB_ISEL_MASK)
#define PM9_PMCORE_ATB_ISEL_RESET                                              0x0
#define PM9_PMCORE_ATB_ON_LSB                                                  15
#define PM9_PMCORE_ATB_ON_MSB                                                  15
#define PM9_PMCORE_ATB_ON_MASK                                                 0x8000
#define PM9_PMCORE_ATB_ON_GET(x)                                               (((x) & PM9_PMCORE_ATB_ON_MASK) >> PM9_PMCORE_ATB_ON_LSB)
#define PM9_PMCORE_ATB_ON_SET(x)                                               (((0 | (x)) << PM9_PMCORE_ATB_ON_LSB) & PM9_PMCORE_ATB_ON_MASK)
#define PM9_PMCORE_ATB_ON_RESET                                                0x0
#define PM9_PMCORE_ATB_VSEL_LSB                                                13
#define PM9_PMCORE_ATB_VSEL_MSB                                                14
#define PM9_PMCORE_ATB_VSEL_MASK                                               0x6000
#define PM9_PMCORE_ATB_VSEL_GET(x)                                             (((x) & PM9_PMCORE_ATB_VSEL_MASK) >> PM9_PMCORE_ATB_VSEL_LSB)
#define PM9_PMCORE_ATB_VSEL_SET(x)                                             (((0 | (x)) << PM9_PMCORE_ATB_VSEL_LSB) & PM9_PMCORE_ATB_VSEL_MASK)
#define PM9_PMCORE_ATB_VSEL_RESET                                              0x0
#define PM9_PMCORE_BG_VSEL_LSB                                                 11
#define PM9_PMCORE_BG_VSEL_MSB                                                 12
#define PM9_PMCORE_BG_VSEL_MASK                                                0x1800
#define PM9_PMCORE_BG_VSEL_GET(x)                                              (((x) & PM9_PMCORE_BG_VSEL_MASK) >> PM9_PMCORE_BG_VSEL_LSB)
#define PM9_PMCORE_BG_VSEL_SET(x)                                              (((0 | (x)) << PM9_PMCORE_BG_VSEL_LSB) & PM9_PMCORE_BG_VSEL_MASK)
#define PM9_PMCORE_BG_VSEL_RESET                                               0x2
#define PM9_DTEST_IO_CFG_LSB                                                   9
#define PM9_DTEST_IO_CFG_MSB                                                   10
#define PM9_DTEST_IO_CFG_MASK                                                  0x600
#define PM9_DTEST_IO_CFG_GET(x)                                                (((x) & PM9_DTEST_IO_CFG_MASK) >> PM9_DTEST_IO_CFG_LSB)
#define PM9_DTEST_IO_CFG_SET(x)                                                (((0 | (x)) << PM9_DTEST_IO_CFG_LSB) & PM9_DTEST_IO_CFG_MASK)
#define PM9_DTEST_IO_CFG_RESET                                                 0x0
#define PM9_RESERVED_0_LSB                                                     0
#define PM9_RESERVED_0_MSB                                                     8
#define PM9_RESERVED_0_MASK                                                    0x1ff
#define PM9_RESERVED_0_GET(x)                                                  (((x) & PM9_RESERVED_0_MASK) >> PM9_RESERVED_0_LSB)
#define PM9_RESERVED_0_SET(x)                                                  (((0 | (x)) << PM9_RESERVED_0_LSB) & PM9_RESERVED_0_MASK)
#define PM9_RESERVED_0_RESET                                                   0x0
#define PM9_ADDRESS                                                            (0x24 + __PMU_REG_CSR_BASE_ADDRESS)
#define PM9_RSTMASK                                                            0xffffffff
#define PM9_RESET                                                              0x28001000

// 0x28 (PM10)
#define PM10_PMU_SPARE_LSB                                                     0
#define PM10_PMU_SPARE_MSB                                                     31
#define PM10_PMU_SPARE_MASK                                                    0xffffffff
#define PM10_PMU_SPARE_GET(x)                                                  (((x) & PM10_PMU_SPARE_MASK) >> PM10_PMU_SPARE_LSB)
#define PM10_PMU_SPARE_SET(x)                                                  (((0 | (x)) << PM10_PMU_SPARE_LSB) & PM10_PMU_SPARE_MASK)
#define PM10_PMU_SPARE_RESET                                                   0x0
#define PM10_ADDRESS                                                           (0x28 + __PMU_REG_CSR_BASE_ADDRESS)
#define PM10_RSTMASK                                                           0xffffffff
#define PM10_RESET                                                             0x0



#endif /* _PMU_REG_CSR_H_ */
