/* Copyright (c) 2016-2018, Linaro Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#include "config.h"

#include <odp_sysinfo_internal.h>
#include <odp_debug_internal.h>
#include <string.h>

#define DUMMY_MAX_MHZ 1400

int cpuinfo_parser(FILE *file ODP_UNUSED, system_info_t *sysinfo)
{
	int i;

	ODP_DBG("Warning: use dummy values for freq and model string\n");
	for (i = 0; i < CONFIG_NUM_CPU; i++) {
		ODP_PRINT("WARN: cpu[%i] uses dummy max frequency %u MHz\n",
			  i, DUMMY_MAX_MHZ);
		sysinfo->cpu_hz_max[i] = DUMMY_MAX_MHZ * 1000000;
		strcpy(sysinfo->model_str[i], "UNKNOWN");
	}

	return 0;
}

void sys_info_print_arch(void)
{
}

uint64_t odp_cpu_arch_hz_current(int id ODP_UNUSED)
{
	return 0;
}
