// SPDX-License-Identifier: GPL-2.0+
/*
 *  Copyright (C) 2008-2009 Samsung Electronics
 *  Minkyu Kang <mk7.kang@samsung.com>
 *  Kyungmin Park <kyungmin.park@samsung.com>
 */

#include <common.h>
#include <asm/gpio.h>
#include <asm/arch/mmc.h>
#include <dm.h>
#include <asm/arch/cpu.h>
#include <samsung/misc.h>
#include <asm/mach-types.h>

DECLARE_GLOBAL_DATA_PTR;

u32 get_board_rev(void)
{
	return 0;
}

int board_init(void)
{
	/* Set Initial global variables */
	gd->bd->bi_arch_number = MACH_TYPE_GONI;
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x100;

	return 0;
}

int dram_init(void)
{
	gd->ram_size = PHYS_SDRAM_1_SIZE + PHYS_SDRAM_2_SIZE +
			PHYS_SDRAM_3_SIZE;

	return 0;
}

int dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size = PHYS_SDRAM_1_SIZE;
	gd->bd->bi_dram[1].start = PHYS_SDRAM_2;
	gd->bd->bi_dram[1].size = PHYS_SDRAM_2_SIZE;
	gd->bd->bi_dram[2].start = PHYS_SDRAM_3;
	gd->bd->bi_dram[2].size = PHYS_SDRAM_3_SIZE;

	return 0;
}
