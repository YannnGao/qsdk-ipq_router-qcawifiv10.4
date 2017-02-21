//
// -----------------------------------------------------------------------------
// Copyright (c) 2011-2014 Qualcomm Atheros, Inc.  All rights reserved.
// -----------------------------------------------------------------------------
// FILE         : tiered_sm3_table_map
// DESCRIPTION  : Software Header File for WiFi 2.0
// THIS FILE IS AUTOMATICALLY GENERATED BY DENALI BLUEPRINT, DO NOT EDIT
// -----------------------------------------------------------------------------
//

#ifndef __REG_TIERED_SM3_TABLE_MAP_H__
#define __REG_TIERED_SM3_TABLE_MAP_H__

#include "tiered_sm3_table_map_macro.h"

struct sm3_table_map {
  volatile u_int32_t BB_sm3_tables_dummy1;        /*        0x0 - 0x4        */
  volatile unsigned int pad__0[0xbf];             /*        0x4 - 0x300      */
  volatile u_int32_t BB_dc_dac_mem_b3[52];        /*      0x300 - 0x3d0      */
  volatile unsigned int pad__1[0x3cc];            /*      0x3d0 - 0x1300     */
  volatile u_int32_t BB_sm3_hc_preemp_lut[412];   /*     0x1300 - 0x1970     */
  volatile u_int32_t BB_sm3_tables_dummy2;        /*     0x1970 - 0x1974     */
};

struct tiered_sm3_table_map {
  struct sm3_table_map sm3_table_map;             /*        0x0 - 0x1974     */
};

#endif /* __REG_TIERED_SM3_TABLE_MAP_H__ */
