/*
 * arch/arm/mach-tegra/tegra3_mc.h
 *
 * Memory controller bandwidth profiling interface
 *
 * Copyright (c) 2011, NVIDIA Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _INCLUDE_TEGRA3_MC_H_
#define _INCLUDE_TEGRA3_MC_H_

#define SAMPLE_ENABLE_DEFAULT					0
#define SAMPLE_LOG_SIZE						1024
#define SAMPLE_QUANTUM_DEFAULT_IN_MS				1000
#define CLIENT_ENABLED_DEFAULT					false
#define CLIENT_ON_SCHEDULE_LENGTH_IN_BYTES			1024
#define SHIFT_4K						12

#define MC_COUNTER_CLIENT_SIZE					256

/* MC_STAT reg difines */
#define MC_STAT_CONTROL_0					0x100
#define MC_STAT_CONTROL_0_EMC_GATHER_SHIFT			0
#define MC_STAT_CONTROL_0_EMC_GATHER_RST			0
#define MC_STAT_CONTROL_0_EMC_GATHER_DISABLE			2
#define MC_STAT_CONTROL_0_EMC_GATHER_ENABLE			3

#define MC_STAT_STATUS_0					0x104

#define MC_STAT_EMC_CLOCK_LIMIT_0				0x108
#define MC_STAT_EMC_CLOCK_LIMIT_MSBS_0				0x10c

#define MC_STAT_EMC_CLOCKS_0					0x110
#define MC_STAT_EMC_CLOCKS_MSBS_0				0x114

#define MC_STAT_EMC_FILTER_SET0_ADDR__LIMIT_LO_0		0x118
#define MC_STAT_EMC_FILTER_SET0_ADDR_LIMIT_HI_0			0x11c

#define MC_STAT_EMC_FILTER_SET0_SLACK_LIMIT_0			0x120

#define MC_STAT_EMC_FILTER_SET0_MISCELLANEOUS_0			0x124
#define MC_STAT_EMC_FILTER_SET0_MISCELLANEOUS_0_COALESCED_SHIFT	0
#define MC_STAT_EMC_FILTER_SET0_MISCELLANEOUS_0_COALESCED_DIS	0

#define MC_STAT_EMC_FILTER_SET0_CLIENT_0_0			0x128
#define MC_STAT_EMC_FILTER_SET0_CLIENT_1_0			0x12C
#define MC_STAT_EMC_FILTER_SET0_CLIENT_2_0			0x130

#define MC_STAT_EMC_SET0_COUNT_0				0x138
#define MC_STAT_EMC_SET0_COUNT_MSBS_0				0x13c

#define MC_STAT_EMC_SET0_SLACK_ACCUM_0				0x140
#define MC_STAT_EMC_SET0_SLACK_ACCUM__MSBS0			0x144

#define MC_STAT_EMC_SET0_HISTO_COUNT_0				0x148
#define MC_STAT_EMC_SET0_HISTO_COUNT_MSBS_0			0x14c

#define MC_STAT_EMC_SET0_MINIMUM_SLACK_OBSERVED_0		0x150

#define MC_STAT_EMC_FILTER_SET1_ADDR__LIMIT_LO_0		0x158
#define MC_STAT_EMC_FILTER_SET1_ADDR_LIMIT_HI_0			0x15c

#define MC_STAT_EMC_FILTER_SET1_SLACK_LIMIT_0			0x160
#define MC_STAT_EMC_FILTER_SET1_MISCELLANEOUS_0			0x164
#define MC_STAT_EMC_FILTER_SET1_MISCELLANEOUS_0_COALESCED_SHIFT	0
#define MC_STAT_EMC_FILTER_SET1_MISCELLANEOUS_0_COALESCED_DIS	0

#define MC_STAT_EMC_FILTER_SET1_CLIENT_0_0			0x168
#define MC_STAT_EMC_FILTER_SET1_CLIENT_1_0			0x16C
#define MC_STAT_EMC_FILTER_SET1_CLIENT_2_0			0x170

#define MC_STAT_EMC_SET1_COUNT_0				0x178
#define MC_STAT_EMC_SET1_COUNT_MSBS_0				0x17c

#define MC_STAT_EMC_SET1_SLACK_ACCUM_0				0x180
#define MC_STAT_EMC_SET1_SLACK_ACCUM__MSBS0			0x184

#define MC_STAT_EMC_SET1_HISTO_COUNT_0				0x188
#define MC_STAT_EMC_SET1_HISTO_COUNT_MSBS_0			0x18c

#define MC_STAT_EMC_SET1_MINIMUM_SLACK_OBSERVED_0		0x190

/* EMC_STAT reg difines */
#define EMC_STAT_CONTROL_0					0x160
#define EMC_STAT_CONTROL_0_DRAM_GATHER_SHIFT			16
#define EMC_STAT_CONTROL_0_DRAM_GATHER_RST			0
#define EMC_STAT_CONTROL_0_DRAM_GATHER_CLEAR			1
#define EMC_STAT_CONTROL_0_DRAM_GATHER_DISABLE			2
#define EMC_STAT_CONTROL_0_DRAM_GATHER_ENABLE			3

#define EMC_STAT_DRAM_CLOCK_LIMIT_LO_0				0x19c
#define EMC_STAT_DRAM_CLOCK_LIMIT_HI_0				0x1a0

#define EMC_STAT_DRAM_CLOCKS_LO_0				0x1a4
#define EMC_STAT_DRAM_CLOCKS_HI_0				0x1a8

// dram counters
// dev0
#define EMC_STAT_DRAM_DEV0_ACTIVATE_CNT_LO_0			0x1ac
#define EMC_STAT_DRAM_DEV0_ACTIVATE_CNT_HI_0			0x1b0

#define EMC_STAT_DRAM_DEV0_READ_CNT_LO_0			0x1b4
#define EMC_STAT_DRAM_DEV0_READ_CNT_HI_0			0x1b8

#define EMC_STAT_DRAM_DEV0_READ8_CNT_LO_0			0x1bc
#define EMC_STAT_DRAM_DEV0_READ8_CNT_HI_0			0x1c0

#define EMC_STAT_DRAM_DEV0_WRITE_CNT_LO_0			0x1c4
#define EMC_STAT_DRAM_DEV0_WRITE_CNT_HI_0			0x1c8

#define EMC_STAT_DRAM_DEV0_WRITE8_CNT_LO_0			0x1cc
#define EMC_STAT_DRAM_DEV0_WRITE8_CNT_HI_0			0x1d0

#define EMC_STAT_DRAM_DEV0_REF_CNT_LO_0				0x1d4
#define EMC_STAT_DRAM_DEV0_REF_CNT_HI_0				0x1d8

#define EMC_STAT_DRAM_DEV0_EXTCLKS_CKE_EQ0_NO_BANKS_ACTIVE_CLKS_LO_0	0x1dc
#define EMC_STAT_DRAM_DEV0_EXTCLKS_CKE_EQ0_NO_BANKS_ACTIVE_CLKS_HI_0	0x1e0

#define EMC_STAT_DRAM_DEV0_CLKSTOP_CKE_EQ0_NO_BANKS_ACTIVE_CLKS_LO_0	0x1e4
#define EMC_STAT_DRAM_DEV0_CLKSTOP_CKE_EQ0_NO_BANKS_ACTIVE_CLKS_HI_0	0x1e8

#define EMC_STAT_DRAM_DEV0_EXTCLKS_CKE_EQ1_NO_BANKS_ACTIVE_CLKS_LO_0	0x1ec
#define EMC_STAT_DRAM_DEV0_EXTCLKS_CKE_EQ1_NO_BANKS_ACTIVE_CLKS_HI_0	0x1f0

#define EMC_STAT_DRAM_DEV0_CLKSTOP_CKE_EQ1_NO_BANKS_ACTIVE_CLKS_LO_0	0x1f4
#define EMC_STAT_DRAM_DEV0_CLKSTOP_CKE_EQ1_NO_BANKS_ACTIVE_CLKS_HI_0	0x1f8

#define EMC_STAT_DRAM_DEV0_EXTCLKS_CKE_EQ0_SOME_BANKS_ACTIVE_CLKS_LO_0	0x1fc
#define EMC_STAT_DRAM_DEV0_EXTCLKS_CKE_EQ0_SOME_BANKS_ACTIVE_CLKS_HI_0	0x200

#define EMC_STAT_DRAM_DEV0_CLKSTOP_CKE_EQ0_SOME_BANKS_ACTIVE_CLKS_LO_0	0x204
#define EMC_STAT_DRAM_DEV0_CLKSTOP_CKE_EQ0_SOME_BANKS_ACTIVE_CLKS_HI_0	0x208

#define EMC_STAT_DRAM_DEV0_EXTCLKS_CKE_EQ1_SOME_BANKS_ACTIVE_CLKS_LO_0	0x20c
#define EMC_STAT_DRAM_DEV0_EXTCLKS_CKE_EQ1_SOME_BANKS_ACTIVE_CLKS_HI_0	0x210

#define EMC_STAT_DRAM_DEV0_CLKSTOP_CKE_EQ1_SOME_BANKS_ACTIVE_CLKS_LO_0	0x214
#define EMC_STAT_DRAM_DEV0_CLKSTOP_CKE_EQ1_SOME_BANKS_ACTIVE_CLKS_HI_0	0x218

#define EMC_STAT_DRAM_DEV0_SR_CKE_EQ0_CLKS_LO_0				0x21c
#define EMC_STAT_DRAM_DEV0_SR_CKE_EQ0_CLKS_HI_0				0x220

#define EMC_STAT_DRAM_DEV0_DSR_0					0x224

// dev1
#define EMC_STAT_DRAM_DEV1_ACTIVATE_CNT_LO_0			0x228
#define EMC_STAT_DRAM_DEV1_ACTIVATE_CNT_HI_0			0x22c

#define EMC_STAT_DRAM_DEV1_READ_CNT_LO_0			0x230
#define EMC_STAT_DRAM_DEV1_READ_CNT_HI_0			0x234

#define EMC_STAT_DRAM_DEV1_READ8_CNT_LO_0			0x238
#define EMC_STAT_DRAM_DEV1_READ8_CNT_HI_0			0x23c

#define EMC_STAT_DRAM_DEV1_WRITE_CNT_LO_0			0x240
#define EMC_STAT_DRAM_DEV1_WRITE_CNT_HI_0			0x244

#define EMC_STAT_DRAM_DEV1_WRITE8_CNT_LO_0			0x248
#define EMC_STAT_DRAM_DEV1_WRITE8_CNT_HI_0			0x24c

#define EMC_STAT_DRAM_DEV1_REF_CNT_LO_0				0x250
#define EMC_STAT_DRAM_DEV1_REF_CNT_HI_0				0x254

#define EMC_STAT_DRAM_DEV1_EXTCLKS_CKE_EQ0_NO_BANKS_ACTIVE_CLKS_LO_0	0x258
#define EMC_STAT_DRAM_DEV1_EXTCLKS_CKE_EQ0_NO_BANKS_ACTIVE_CLKS_HI_0	0x25c

#define EMC_STAT_DRAM_DEV1_CLKSTOP_CKE_EQ0_NO_BANKS_ACTIVE_CLKS_LO_0	0x260
#define EMC_STAT_DRAM_DEV1_CLKSTOP_CKE_EQ0_NO_BANKS_ACTIVE_CLKS_HI_0	0x264

#define EMC_STAT_DRAM_DEV1_EXTCLKS_CKE_EQ1_NO_BANKS_ACTIVE_CLKS_LO_0	0x268
#define EMC_STAT_DRAM_DEV1_EXTCLKS_CKE_EQ1_NO_BANKS_ACTIVE_CLKS_HI_0	0x26c

#define EMC_STAT_DRAM_DEV1_CLKSTOP_CKE_EQ1_NO_BANKS_ACTIVE_CLKS_LO_0	0x270
#define EMC_STAT_DRAM_DEV1_CLKSTOP_CKE_EQ1_NO_BANKS_ACTIVE_CLKS_HI_0	0x274

#define EMC_STAT_DRAM_DEV1_EXTCLKS_CKE_EQ0_SOME_BANKS_ACTIVE_CLKS_LO_0	0x278
#define EMC_STAT_DRAM_DEV1_EXTCLKS_CKE_EQ0_SOME_BANKS_ACTIVE_CLKS_HI_0	0x27c

#define EMC_STAT_DRAM_DEV1_CLKSTOP_CKE_EQ0_SOME_BANKS_ACTIVE_CLKS_LO_0	0x280
#define EMC_STAT_DRAM_DEV1_CLKSTOP_CKE_EQ0_SOME_BANKS_ACTIVE_CLKS_HI_0	0x284

#define EMC_STAT_DRAM_DEV1_EXTCLKS_CKE_EQ1_SOME_BANKS_ACTIVE_CLKS_LO_0	0x288
#define EMC_STAT_DRAM_DEV1_EXTCLKS_CKE_EQ1_SOME_BANKS_ACTIVE_CLKS_HI_0	0x28c

#define EMC_STAT_DRAM_DEV1_CLKSTOP_CKE_EQ1_SOME_BANKS_ACTIVE_CLKS_LO_0	0x290
#define EMC_STAT_DRAM_DEV1_CLKSTOP_CKE_EQ1_SOME_BANKS_ACTIVE_CLKS_HI_0	0x294

#define EMC_STAT_DRAM_DEV1_SR_CKE_EQ0_CLKS_LO_0				0x298
#define EMC_STAT_DRAM_DEV1_SR_CKE_EQ0_CLKS_HI_0				0x29c

#define EMC_STAT_DRAM_DEV1_DSR_0					0x2a0

typedef enum {
	FILTER_NONE,
	FILTER_ADDR,
	FILTER_CLIENT,
} FILTER_MODE;

typedef struct tegra_mc_counter {
	/* constants during sampling */
	bool		enabled;
	bool		reschedule;
	u32		period;
	FILTER_MODE	mode;
	u32		address_low;
	u32		address_length_1; /* This represents (length - 1) */
	u32		address_window_size_1; /* This represents (size - 1) */
	u8		num_clients;
	u8		clients[MC_COUNTER_CLIENT_SIZE];

	/* variables during sampling */
	bool		address_range_change;
	u32		current_address_low;
	u32		current_address_high;
	u64		value;
	u8		current_client;
	u32		sample_count;
} tegra_mc_counter_t;

typedef struct tegra_emc_dram_counter {
	/* constants during sampling */
	bool	enabled;
	u8	device_mask;

	/* variables during sampling */
	u32	value;
} tegra_emc_dram_counter_t;

#pragma pack(push)
#pragma pack(1)
#define LOG_EVENT_NUMBER_MAX		16
#define MILLISECONDS_TO_TIME_QUANTUM	10
typedef struct {
	u16	time_quantum;
	u16	event_state_change;
} log_header_t;

typedef struct {
	struct _word0 {
		u32 enabled			: 1; /* 0:0 */
		u32 address_range_change	: 1; /* 1:1 */
		u32 reserved1			: 2; /* 3:2 */
		u32 event_id			: 8; /* 11:4 */
		u32 address_range_low_pfn	: 20; /* 31:12 */
	} word0;
	struct _word1 {
		u32 address_range_length_pfn	: 20; /* 19:0 */
		u32 reserved1			: 12; /* 31:20 */
	} word1;
} log_event_t;
#pragma pack(pop)

/* client ids of mc/emc */
typedef enum {
	MC_STAT_BEGIN = 0,
	CBR_PTCR = 0,
	CBR_DISPLAY0A,
	CBR_DISPLAY0AB,
	CBR_DISPLAY0B,
	CBR_DISPLAY0BB,
	CBR_DISPLAY0C = 5,
	CBR_DISPLAY0CB,
	CBR_DISPLAY1B,
	CBR_DISPLAY1BB,
	CBR_EPPUP = 9,
	CBR_G2PR,
	CBR_G2SR,
	CBR_MPEUNIFBR,
	CBR_VIRUV = 13,
	CBR_AIFR = 14,
	CSR_AVPCARM7R,
	CSR_DISPLAYHC,
	CSR_DISPLAYHCB,
	CSR_FDCDRD = 18,
	CSR_FDCDRD2,
	CSR_G2DR = 20,
	CSR_HDAR,
	CSR_HOST1XDMAR,
	CSR_HOST1XR,
	CSR_IDXSRD = 24,
	CSR_IDXSRD2 = 25,
	CSR_MPE_IPRED,
	CSR_MPEAMEMRD = 27,
	CSR_MPECSRD,
	CSR_PPCSAHBDMAR,
	CSR_PPCSAHBSLVR = 30,
	CSR_SATAR = 31,
	CSR_TEXSRD,
	CSR_TEXSRD2 = 33,
	CSR_VDEBSEVR,
	CSR_VDEMBER,
	CSR_VDEMCER,
	CSR_VDETPER,
	CSR_MPCORELPR = 38,
	CSR_MPCORER = 39,
	CBW_EPPU,
	CBW_EPPV,
	CBW_EPPY,
	CBW_MPEUNIFBW = 43,
	CBW_VIWSB,
	CBW_VIWU,
	CBW_VIWV,
	CBW_VIWY,
	CCW_G2DW = 48,
	CCW_AFIW,
	CSW_AVPCARM7W = 50,
	CSW_FDCDWR,
	CSW_FDCDWR_2 = 52,
	CSW_HDAW,
	CSW_HOST1XW,
	CSW_ISPW = 55,
	CSW_MPCORELPW,
	CSW_MPCOREW = 57,
	CSW_MPECSWR,
	CSW_PPCSAHBDMAW,
	CSW_PPCSAHBSLVW,
	CSW_SATAW = 61,
	CSW_VDEBSEVW,
	CSW_VDEDBGW = 63,
	CSW_VDEMBEW,
	CSW_VDETPMW = 65,
	MC_STAT_END,
	EMC_DRAM_STAT_BEGIN = 128,
	ACTIVATE_CNT = 128,
	READ_CNT,
	READ8_CNT,
	WRITE_CNT,
	WRITE8_CNT,
	REF_CNT,
	EXTCLKS_CKE_EQ0_NO_BANKS_ACTIVE,
	CLKSTOP_CKE_EQ0_NO_BANKS_ACTIVE,
	EXTCLKS_CKE_EQ1_NO_BANKS_ACTIVE,
	CLKSTOP_CKE_EQ1_NO_BANKS_ACTIVE,
	EXTCLKS_CKE_EQ0_SOME_BANKS_ACTIVE,
	CLKSTOP_CKE_EQ0_SOME_BANKS_ACTIVE,
	EXTCLKS_CKE_EQ1_SOME_BANKS_ACTIVE,
	CLKSTOP_CKE_EQ1_SOME_BANKS_ACTIVE,
	SR_CKE_EQ0_CLKS,
	DSR,
	EMC_DRAM_STAT_END,
	MC_STAT_OVERALL_START      = 252,
	MC_STAT_OVERALL_READTALLY  = 253,
	MC_STAT_OVERALL_WRITETALLY = 254,
	MC_STAT_OVERALL_AGGREGATE  = 255,
} device_id;

#endif
