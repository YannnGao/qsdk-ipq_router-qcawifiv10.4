// Copyright (c) 2013 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  This file is automatically generated
//               These definitions are tied to a particular hardware layout


#ifndef _MPDU_QUEUE_EXT_COMMON_H_
#define _MPDU_QUEUE_EXT_COMMON_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	ampdu_flag[0], ba_flow_enabled[1], window_size[7:2], start_seq_num[19:8], partial_aid[28:20], reserved_0a[31:29]
//	1	seqnum_bitmap_31_0[31:0]
//	2	seqnum_bitmap_63_32[31:0]
//	3	start_pn_31_0[31:0]
//	4	start_pn_63_32[31:0]
//	5	start_pn_95_64[31:0]
//	6	start_pn_127_96[31:0]
//	7	retry_bitmap_31_0[31:0]
//	8	retry_bitmap_63_32[31:0]
//	9	frame_ctl[15:0], qos_ctl[31:16]
//	10	key_id[7:0], reserved_11[31:8]
//	11	pn_bitmap_31_0[31:0]
//	12	pn_bitmap_63_32[31:0]
//	13	pn_bitmap_95_64[31:0]
//	14	pn_bitmap_127_96[31:0]
//	15	pn_bitmap_159_128[31:0]
//	16	pn_bitmap_191_160[31:0]
//	17	pn_bitmap_223_192[31:0]
//	18	pn_bitmap_255_224[31:0]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_MPDU_QUEUE_EXT_COMMON 19

struct mpdu_queue_ext_common {
    volatile uint32_t ampdu_flag                      :  1, //[0]
                      ba_flow_enabled                 :  1, //[1]
                      window_size                     :  6, //[7:2]
                      start_seq_num                   : 12, //[19:8]
                      partial_aid                     :  9, //[28:20]
                      reserved_0a                     :  3; //[31:29]
    volatile uint32_t seqnum_bitmap_31_0              : 32; //[31:0]
    volatile uint32_t seqnum_bitmap_63_32             : 32; //[31:0]
    volatile uint32_t start_pn_31_0                   : 32; //[31:0]
    volatile uint32_t start_pn_63_32                  : 32; //[31:0]
    volatile uint32_t start_pn_95_64                  : 32; //[31:0]
    volatile uint32_t start_pn_127_96                 : 32; //[31:0]
    volatile uint32_t retry_bitmap_31_0               : 32; //[31:0]
    volatile uint32_t retry_bitmap_63_32              : 32; //[31:0]
    volatile uint32_t frame_ctl                       : 16, //[15:0]
                      qos_ctl                         : 16; //[31:16]
    volatile uint32_t key_id                          :  8, //[7:0]
                      reserved_11                     : 24; //[31:8]
    volatile uint32_t pn_bitmap_31_0                  : 32; //[31:0]
    volatile uint32_t pn_bitmap_63_32                 : 32; //[31:0]
    volatile uint32_t pn_bitmap_95_64                 : 32; //[31:0]
    volatile uint32_t pn_bitmap_127_96                : 32; //[31:0]
    volatile uint32_t pn_bitmap_159_128               : 32; //[31:0]
    volatile uint32_t pn_bitmap_191_160               : 32; //[31:0]
    volatile uint32_t pn_bitmap_223_192               : 32; //[31:0]
    volatile uint32_t pn_bitmap_255_224               : 32; //[31:0]
};

/*

ampdu_flag
			
			0: Window size setting should be ignored, and MPDUs are
			only allowed to be sent out 1 at a time in NON A-MPDU format
			for legacy and 11n rate and in VHT single MPDU format for
			11ac rate.
			
			1: All MPDUs should be sent out using the A-MPDU format,
			even if window_size is set to 0
			
			
			
			Note that this bit should be clear to 0 in order to
			construct VHT single MPDU frame. VHT frame is all A-MPDU
			format but if this bit is clear for VHT frame, EOF bit is
			set to 1 for the first MPDU delimiter in A-MPDU, which is
			the indicator of VHT single MPDU and solicits ACK rather
			than BA as response frame. 

ba_flow_enabled
			
			Block Ack flow
			
			When set, a Block Ack flow is ongoing.

window_size
			
			The BA window size + 1
			
			0 => window is 1 => 1 frame (used for non BA sessions)
			
			1 => window is 2
			
			Etc. <legal all>

start_seq_num
			
			Indicates the sequence number of the head MPDU in the
			MPDU Queue. 

partial_aid
			
			This field in only used by the PDG. All other modules
			should ignore this field.
			
			
			
			This field is only valid in case of a transmission at
			VHT rates
			
			
			
			This field is the Partial AID to be filled in to the VHT
			preamble.

reserved_0a
			
			<legal 0>

seqnum_bitmap_31_0
			
			The Lower 32 bits of the 64 bit sequence number bitmap. 
			This field is used to specify the sequence numbers of all
			the MPDU in this PPDU based on the start_seq_num field.  Any
			time there is a 0 in the bitmap, the corresponding sequence
			number is skipped as we are following the MPDUs in the MPDU
			linked list.  For example: if start_seq_num is 0x100 and
			seq_num_bitmap is 0x0123.  Then the transmit queue contains
			the MPDU: 0x100, 0x101, 0x105, 0x108.  <legal all>

seqnum_bitmap_63_32
			
			Upper 32 bits of the 64 bit sequence number bitmap.  See
			description for seq_num_bitmap_31_0. <legal all>

start_pn_31_0
			
			start_pn_a is bits [31:0] of the 128 bit starting PN
			(Packet Number) which is used in conjunction with the
			pn_bitmap and key_id_octet to form the IV.  pn# represents
			one of the octets of the start packet number:
			
			pn0[7:0] = start_pn_a[7:0] 
			
			pn1[7:0] = start_pn_a[15:8] 
			
			pn2[7:0] = start_pn_a[23:16] 
			
			pn3[7:0] = start_pn_a[31:24] 
			
			. . .
			
			pn15[7:0] = start_pn_a[127:120]
			
			
			
			The PN between sequential frames increments according to
			the rule specified in global register  pn_incr_control
			<legal all>

start_pn_63_32
			
			Bits [63:32] of the 128 bit start PN.  See description
			for start_pn_31_0 <legal all>

start_pn_95_64
			
			Bits [95:64] of the 128 bit start PN.  See description
			for start_pn_31_0 <legal all>

start_pn_127_96
			
			Bits [127:96] of the 128 bit start PN.  See description
			for start_pn_31_0 <legal all>

retry_bitmap_31_0
			
			Lower 32 bits of the 64 bit bitmap indicating if the
			corresponding frame has been transmitted before or not. Used
			by OLE to insert the correct value for the retry bit in the
			Frame control field
			
			
			
			0: Frame not transmitted before
			
			1: Frame has been transmitted before

retry_bitmap_63_32
			
			Higher 32 bits of the 64 bit bitmap indicating if the
			corresponding frame has been transmitted before or not. Used
			by OLE to insert the correct value for the retry bit in the
			Frame control field
			
			
			
			0: Frame not transmitted before
			
			1: Frame has been transmitted before

frame_ctl
			
			802.11 Frame control field:
			
			fc [1:0]: Protocol Version
			
			fc [3:2]: Type
			
			fc [7:4]: Subtype
			
			fc [8]: To DS
			
			fc [9]: From DS
			
			fc [10]: More Frag
			
			fc [11]: Retry
			
			fc [12]: Pwr Mgt
			
			fc [13]: More Data
			
			fc [14]: Protected Frame
			
			fc [15]: Order
			
			Used by OLE during the encapsulation process for Native
			WiFi, Ethernet II, and 802.3.

qos_ctl
			
			QoS control field is valid if the type field is data and
			the upper bit of the subtype field is set.  The field decode
			is as below:
			
			qos_ctl[3:0]: TID
			
			qos_ctl[4]: EOSP (with some exceptions)
			
			qos_ctl[6:5]: Ack Policy
			
			0x0: Normal Ack or Implicit BAR
			
			0x1: No Ack
			
			0x2: No explicit Ack or PSMP Ack (not supported)
			
			0x3: Block Ack (Not supported)
			
			Qos_ctl[7]: A-MSDU Present (with some exceptions)
			
			Qos_ctl[15:8]: TXOP limit, AP PS buffer state, TXOP
			duration requested or queue size (Not supported)
			
			This field is inserted into the 802.11 header during the
			encapsulation process
			
			<legal[3:0]:0-7><legal[4]:0,1><legal[6:5]:0,
			1><legal[7]:0,1><legal[15:8]:0>

key_id
			
			The key_id_octet includes the key_id: key_id_octet[7:6]
			and the extended IV: key_id_octet[5] and reserved bits:
			key_id_octet[4:0].  Used by the OLE to create the IV field
			of the packet.

reserved_11
			
			Reserved: generator should set to 0 and consumer shall
			ignore. <legal 0>

pn_bitmap_31_0
			
			31-0 bits of the 256-bit packet number bitmap.  In
			concept the use of start_pn and pn_bitmap is very similar to
			start_seq_num and seq_num_bitmap.  The pn_shift_factor[3:0]
			is a register which indicates the increment in factors of
			2N.  This is necessary to provide different PN space for
			each TID.  PN should never be duplicated; however, it is
			allocated per destination not per TID like sequence numbers.
			If we allocated PN for each packet before the packets are
			split to the different connection queues, then the PN could
			not be represented as a start and bitmap.  By having the PN
			number space independent for each TID we can guarantee that
			the PN numbers for a connection queue will increment by the
			2pn_shift_factor for each subsequent packet.  This bitmap is
			not considered necessary because the seq_num_bitmap and the
			pn_bitmap should be identical, but this field exists just in
			case there is an issue.  Used by OLE to insert the IV into
			the packet.

pn_bitmap_63_32
			
			63-32 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.

pn_bitmap_95_64
			
			95-64 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.

pn_bitmap_127_96
			
			127-96 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.

pn_bitmap_159_128
			
			159-128 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.

pn_bitmap_191_160
			
			191-160 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.

pn_bitmap_223_192
			
			223-192 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.

pn_bitmap_255_224
			
			255-224 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.
*/


/* Description		MPDU_QUEUE_EXT_COMMON_0_AMPDU_FLAG
			
			0: Window size setting should be ignored, and MPDUs are
			only allowed to be sent out 1 at a time in NON A-MPDU format
			for legacy and 11n rate and in VHT single MPDU format for
			11ac rate.
			
			1: All MPDUs should be sent out using the A-MPDU format,
			even if window_size is set to 0
			
			
			
			Note that this bit should be clear to 0 in order to
			construct VHT single MPDU frame. VHT frame is all A-MPDU
			format but if this bit is clear for VHT frame, EOF bit is
			set to 1 for the first MPDU delimiter in A-MPDU, which is
			the indicator of VHT single MPDU and solicits ACK rather
			than BA as response frame. 
*/
#define MPDU_QUEUE_EXT_COMMON_0_AMPDU_FLAG_OFFSET                    0x00000000
#define MPDU_QUEUE_EXT_COMMON_0_AMPDU_FLAG_LSB                       0
#define MPDU_QUEUE_EXT_COMMON_0_AMPDU_FLAG_MASK                      0x00000001

/* Description		MPDU_QUEUE_EXT_COMMON_0_BA_FLOW_ENABLED
			
			Block Ack flow
			
			When set, a Block Ack flow is ongoing.
*/
#define MPDU_QUEUE_EXT_COMMON_0_BA_FLOW_ENABLED_OFFSET               0x00000000
#define MPDU_QUEUE_EXT_COMMON_0_BA_FLOW_ENABLED_LSB                  1
#define MPDU_QUEUE_EXT_COMMON_0_BA_FLOW_ENABLED_MASK                 0x00000002

/* Description		MPDU_QUEUE_EXT_COMMON_0_WINDOW_SIZE
			
			The BA window size + 1
			
			0 => window is 1 => 1 frame (used for non BA sessions)
			
			1 => window is 2
			
			Etc. <legal all>
*/
#define MPDU_QUEUE_EXT_COMMON_0_WINDOW_SIZE_OFFSET                   0x00000000
#define MPDU_QUEUE_EXT_COMMON_0_WINDOW_SIZE_LSB                      2
#define MPDU_QUEUE_EXT_COMMON_0_WINDOW_SIZE_MASK                     0x000000fc

/* Description		MPDU_QUEUE_EXT_COMMON_0_START_SEQ_NUM
			
			Indicates the sequence number of the head MPDU in the
			MPDU Queue. 
*/
#define MPDU_QUEUE_EXT_COMMON_0_START_SEQ_NUM_OFFSET                 0x00000000
#define MPDU_QUEUE_EXT_COMMON_0_START_SEQ_NUM_LSB                    8
#define MPDU_QUEUE_EXT_COMMON_0_START_SEQ_NUM_MASK                   0x000fff00

/* Description		MPDU_QUEUE_EXT_COMMON_0_PARTIAL_AID
			
			This field in only used by the PDG. All other modules
			should ignore this field.
			
			
			
			This field is only valid in case of a transmission at
			VHT rates
			
			
			
			This field is the Partial AID to be filled in to the VHT
			preamble.
*/
#define MPDU_QUEUE_EXT_COMMON_0_PARTIAL_AID_OFFSET                   0x00000000
#define MPDU_QUEUE_EXT_COMMON_0_PARTIAL_AID_LSB                      20
#define MPDU_QUEUE_EXT_COMMON_0_PARTIAL_AID_MASK                     0x1ff00000

/* Description		MPDU_QUEUE_EXT_COMMON_0_RESERVED_0A
			
			<legal 0>
*/
#define MPDU_QUEUE_EXT_COMMON_0_RESERVED_0A_OFFSET                   0x00000000
#define MPDU_QUEUE_EXT_COMMON_0_RESERVED_0A_LSB                      29
#define MPDU_QUEUE_EXT_COMMON_0_RESERVED_0A_MASK                     0xe0000000

/* Description		MPDU_QUEUE_EXT_COMMON_1_SEQNUM_BITMAP_31_0
			
			The Lower 32 bits of the 64 bit sequence number bitmap. 
			This field is used to specify the sequence numbers of all
			the MPDU in this PPDU based on the start_seq_num field.  Any
			time there is a 0 in the bitmap, the corresponding sequence
			number is skipped as we are following the MPDUs in the MPDU
			linked list.  For example: if start_seq_num is 0x100 and
			seq_num_bitmap is 0x0123.  Then the transmit queue contains
			the MPDU: 0x100, 0x101, 0x105, 0x108.  <legal all>
*/
#define MPDU_QUEUE_EXT_COMMON_1_SEQNUM_BITMAP_31_0_OFFSET            0x00000004
#define MPDU_QUEUE_EXT_COMMON_1_SEQNUM_BITMAP_31_0_LSB               0
#define MPDU_QUEUE_EXT_COMMON_1_SEQNUM_BITMAP_31_0_MASK              0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_2_SEQNUM_BITMAP_63_32
			
			Upper 32 bits of the 64 bit sequence number bitmap.  See
			description for seq_num_bitmap_31_0. <legal all>
*/
#define MPDU_QUEUE_EXT_COMMON_2_SEQNUM_BITMAP_63_32_OFFSET           0x00000008
#define MPDU_QUEUE_EXT_COMMON_2_SEQNUM_BITMAP_63_32_LSB              0
#define MPDU_QUEUE_EXT_COMMON_2_SEQNUM_BITMAP_63_32_MASK             0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_3_START_PN_31_0
			
			start_pn_a is bits [31:0] of the 128 bit starting PN
			(Packet Number) which is used in conjunction with the
			pn_bitmap and key_id_octet to form the IV.  pn# represents
			one of the octets of the start packet number:
			
			pn0[7:0] = start_pn_a[7:0] 
			
			pn1[7:0] = start_pn_a[15:8] 
			
			pn2[7:0] = start_pn_a[23:16] 
			
			pn3[7:0] = start_pn_a[31:24] 
			
			. . .
			
			pn15[7:0] = start_pn_a[127:120]
			
			
			
			The PN between sequential frames increments according to
			the rule specified in global register  pn_incr_control
			<legal all>
*/
#define MPDU_QUEUE_EXT_COMMON_3_START_PN_31_0_OFFSET                 0x0000000c
#define MPDU_QUEUE_EXT_COMMON_3_START_PN_31_0_LSB                    0
#define MPDU_QUEUE_EXT_COMMON_3_START_PN_31_0_MASK                   0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_4_START_PN_63_32
			
			Bits [63:32] of the 128 bit start PN.  See description
			for start_pn_31_0 <legal all>
*/
#define MPDU_QUEUE_EXT_COMMON_4_START_PN_63_32_OFFSET                0x00000010
#define MPDU_QUEUE_EXT_COMMON_4_START_PN_63_32_LSB                   0
#define MPDU_QUEUE_EXT_COMMON_4_START_PN_63_32_MASK                  0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_5_START_PN_95_64
			
			Bits [95:64] of the 128 bit start PN.  See description
			for start_pn_31_0 <legal all>
*/
#define MPDU_QUEUE_EXT_COMMON_5_START_PN_95_64_OFFSET                0x00000014
#define MPDU_QUEUE_EXT_COMMON_5_START_PN_95_64_LSB                   0
#define MPDU_QUEUE_EXT_COMMON_5_START_PN_95_64_MASK                  0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_6_START_PN_127_96
			
			Bits [127:96] of the 128 bit start PN.  See description
			for start_pn_31_0 <legal all>
*/
#define MPDU_QUEUE_EXT_COMMON_6_START_PN_127_96_OFFSET               0x00000018
#define MPDU_QUEUE_EXT_COMMON_6_START_PN_127_96_LSB                  0
#define MPDU_QUEUE_EXT_COMMON_6_START_PN_127_96_MASK                 0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_7_RETRY_BITMAP_31_0
			
			Lower 32 bits of the 64 bit bitmap indicating if the
			corresponding frame has been transmitted before or not. Used
			by OLE to insert the correct value for the retry bit in the
			Frame control field
			
			
			
			0: Frame not transmitted before
			
			1: Frame has been transmitted before
*/
#define MPDU_QUEUE_EXT_COMMON_7_RETRY_BITMAP_31_0_OFFSET             0x0000001c
#define MPDU_QUEUE_EXT_COMMON_7_RETRY_BITMAP_31_0_LSB                0
#define MPDU_QUEUE_EXT_COMMON_7_RETRY_BITMAP_31_0_MASK               0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_8_RETRY_BITMAP_63_32
			
			Higher 32 bits of the 64 bit bitmap indicating if the
			corresponding frame has been transmitted before or not. Used
			by OLE to insert the correct value for the retry bit in the
			Frame control field
			
			
			
			0: Frame not transmitted before
			
			1: Frame has been transmitted before
*/
#define MPDU_QUEUE_EXT_COMMON_8_RETRY_BITMAP_63_32_OFFSET            0x00000020
#define MPDU_QUEUE_EXT_COMMON_8_RETRY_BITMAP_63_32_LSB               0
#define MPDU_QUEUE_EXT_COMMON_8_RETRY_BITMAP_63_32_MASK              0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_9_FRAME_CTL
			
			802.11 Frame control field:
			
			fc [1:0]: Protocol Version
			
			fc [3:2]: Type
			
			fc [7:4]: Subtype
			
			fc [8]: To DS
			
			fc [9]: From DS
			
			fc [10]: More Frag
			
			fc [11]: Retry
			
			fc [12]: Pwr Mgt
			
			fc [13]: More Data
			
			fc [14]: Protected Frame
			
			fc [15]: Order
			
			Used by OLE during the encapsulation process for Native
			WiFi, Ethernet II, and 802.3.
*/
#define MPDU_QUEUE_EXT_COMMON_9_FRAME_CTL_OFFSET                     0x00000024
#define MPDU_QUEUE_EXT_COMMON_9_FRAME_CTL_LSB                        0
#define MPDU_QUEUE_EXT_COMMON_9_FRAME_CTL_MASK                       0x0000ffff

/* Description		MPDU_QUEUE_EXT_COMMON_9_QOS_CTL
			
			QoS control field is valid if the type field is data and
			the upper bit of the subtype field is set.  The field decode
			is as below:
			
			qos_ctl[3:0]: TID
			
			qos_ctl[4]: EOSP (with some exceptions)
			
			qos_ctl[6:5]: Ack Policy
			
			0x0: Normal Ack or Implicit BAR
			
			0x1: No Ack
			
			0x2: No explicit Ack or PSMP Ack (not supported)
			
			0x3: Block Ack (Not supported)
			
			Qos_ctl[7]: A-MSDU Present (with some exceptions)
			
			Qos_ctl[15:8]: TXOP limit, AP PS buffer state, TXOP
			duration requested or queue size (Not supported)
			
			This field is inserted into the 802.11 header during the
			encapsulation process
			
			<legal[3:0]:0-7><legal[4]:0,1><legal[6:5]:0,
			1><legal[7]:0,1><legal[15:8]:0>
*/
#define MPDU_QUEUE_EXT_COMMON_9_QOS_CTL_OFFSET                       0x00000024
#define MPDU_QUEUE_EXT_COMMON_9_QOS_CTL_LSB                          16
#define MPDU_QUEUE_EXT_COMMON_9_QOS_CTL_MASK                         0xffff0000

/* Description		MPDU_QUEUE_EXT_COMMON_10_KEY_ID
			
			The key_id_octet includes the key_id: key_id_octet[7:6]
			and the extended IV: key_id_octet[5] and reserved bits:
			key_id_octet[4:0].  Used by the OLE to create the IV field
			of the packet.
*/
#define MPDU_QUEUE_EXT_COMMON_10_KEY_ID_OFFSET                       0x00000028
#define MPDU_QUEUE_EXT_COMMON_10_KEY_ID_LSB                          0
#define MPDU_QUEUE_EXT_COMMON_10_KEY_ID_MASK                         0x000000ff

/* Description		MPDU_QUEUE_EXT_COMMON_10_RESERVED_11
			
			Reserved: generator should set to 0 and consumer shall
			ignore. <legal 0>
*/
#define MPDU_QUEUE_EXT_COMMON_10_RESERVED_11_OFFSET                  0x00000028
#define MPDU_QUEUE_EXT_COMMON_10_RESERVED_11_LSB                     8
#define MPDU_QUEUE_EXT_COMMON_10_RESERVED_11_MASK                    0xffffff00

/* Description		MPDU_QUEUE_EXT_COMMON_11_PN_BITMAP_31_0
			
			31-0 bits of the 256-bit packet number bitmap.  In
			concept the use of start_pn and pn_bitmap is very similar to
			start_seq_num and seq_num_bitmap.  The pn_shift_factor[3:0]
			is a register which indicates the increment in factors of
			2N.  This is necessary to provide different PN space for
			each TID.  PN should never be duplicated; however, it is
			allocated per destination not per TID like sequence numbers.
			If we allocated PN for each packet before the packets are
			split to the different connection queues, then the PN could
			not be represented as a start and bitmap.  By having the PN
			number space independent for each TID we can guarantee that
			the PN numbers for a connection queue will increment by the
			2pn_shift_factor for each subsequent packet.  This bitmap is
			not considered necessary because the seq_num_bitmap and the
			pn_bitmap should be identical, but this field exists just in
			case there is an issue.  Used by OLE to insert the IV into
			the packet.
*/
#define MPDU_QUEUE_EXT_COMMON_11_PN_BITMAP_31_0_OFFSET               0x0000002c
#define MPDU_QUEUE_EXT_COMMON_11_PN_BITMAP_31_0_LSB                  0
#define MPDU_QUEUE_EXT_COMMON_11_PN_BITMAP_31_0_MASK                 0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_12_PN_BITMAP_63_32
			
			63-32 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.
*/
#define MPDU_QUEUE_EXT_COMMON_12_PN_BITMAP_63_32_OFFSET              0x00000030
#define MPDU_QUEUE_EXT_COMMON_12_PN_BITMAP_63_32_LSB                 0
#define MPDU_QUEUE_EXT_COMMON_12_PN_BITMAP_63_32_MASK                0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_13_PN_BITMAP_95_64
			
			95-64 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.
*/
#define MPDU_QUEUE_EXT_COMMON_13_PN_BITMAP_95_64_OFFSET              0x00000034
#define MPDU_QUEUE_EXT_COMMON_13_PN_BITMAP_95_64_LSB                 0
#define MPDU_QUEUE_EXT_COMMON_13_PN_BITMAP_95_64_MASK                0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_14_PN_BITMAP_127_96
			
			127-96 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.
*/
#define MPDU_QUEUE_EXT_COMMON_14_PN_BITMAP_127_96_OFFSET             0x00000038
#define MPDU_QUEUE_EXT_COMMON_14_PN_BITMAP_127_96_LSB                0
#define MPDU_QUEUE_EXT_COMMON_14_PN_BITMAP_127_96_MASK               0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_15_PN_BITMAP_159_128
			
			159-128 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.
*/
#define MPDU_QUEUE_EXT_COMMON_15_PN_BITMAP_159_128_OFFSET            0x0000003c
#define MPDU_QUEUE_EXT_COMMON_15_PN_BITMAP_159_128_LSB               0
#define MPDU_QUEUE_EXT_COMMON_15_PN_BITMAP_159_128_MASK              0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_16_PN_BITMAP_191_160
			
			191-160 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.
*/
#define MPDU_QUEUE_EXT_COMMON_16_PN_BITMAP_191_160_OFFSET            0x00000040
#define MPDU_QUEUE_EXT_COMMON_16_PN_BITMAP_191_160_LSB               0
#define MPDU_QUEUE_EXT_COMMON_16_PN_BITMAP_191_160_MASK              0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_17_PN_BITMAP_223_192
			
			223-192 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.
*/
#define MPDU_QUEUE_EXT_COMMON_17_PN_BITMAP_223_192_OFFSET            0x00000044
#define MPDU_QUEUE_EXT_COMMON_17_PN_BITMAP_223_192_LSB               0
#define MPDU_QUEUE_EXT_COMMON_17_PN_BITMAP_223_192_MASK              0xffffffff

/* Description		MPDU_QUEUE_EXT_COMMON_18_PN_BITMAP_255_224
			
			255-224 bits of the 256-bit packet number bitmap.  See
			description for pn_bitmap_31_0.
*/
#define MPDU_QUEUE_EXT_COMMON_18_PN_BITMAP_255_224_OFFSET            0x00000048
#define MPDU_QUEUE_EXT_COMMON_18_PN_BITMAP_255_224_LSB               0
#define MPDU_QUEUE_EXT_COMMON_18_PN_BITMAP_255_224_MASK              0xffffffff


#endif // _MPDU_QUEUE_EXT_COMMON_H_
