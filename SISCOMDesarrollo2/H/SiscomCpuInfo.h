#ifndef __SISCOMCPUINFO_H__
#define __SISCOMCPUINFO_H__
#include <stdio.h>
typedef enum EnuCpuInfo
{
			
	processor,
	vendor_id,
	cpu_family,
	model,
	model_name,
	stepping,
	cpu_MHz,
	cache_size,
	physical_id,
	siblings,
	core_id,
	cpu_cores,
	apicid,
	initial_apicid,
	fpu,
	fpu_exception,
	cpuid_level,
	wp,
	flags,
	clflush_size,
	cache_alignment,
	address_sizes,
	power_management
}SiscomEnumCpuInfo;
typedef struct CpuInfo
{
   char chrArrCpuInfo[50][256];
}StcSiscomCpuInfo;

extern char *gchrPtrCpuInfo[30];

int SiscomParametrosCpuInfo(FILE *pFlePtrArchivo,
		      StcSiscomCpuInfo *);

#endif
