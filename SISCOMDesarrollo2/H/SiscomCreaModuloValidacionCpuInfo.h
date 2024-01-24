#ifndef __SISCOMCREAMODULOVALIDACIONCPUINFO_H__
#define __SISCOMCREAMODULOVALIDACIONCPUINFO_H__
#include <stdio.h>
class SiscomCpuInfo;
class SiscomCreaModuloValidacionCpuInfo
{
private:
	const char *chrPtrDirTrabajo;
	const char *chrPtrMaquina;
	const char *chrPtrCpuInfo;
private:
	void CreaMakefile();
	void UtilizacionCPP();
	void UtilizacionH();
	void CpuInfoCPP();
	void CpuInfoH();
	SiscomCpuInfo *CpuInfo();
	void CreaCpuInfo(FILE *pFlePtrArchivo,
		         SiscomCpuInfo *);
	char *CambiaMayusculas(char *pchrPtrCadena);
public:

public:
	SiscomCreaModuloValidacionCpuInfo(const char *pchrPtrDirTrabajo,
					  const char *pchrPtrMaquina,
					  const char *pchrPtrCpuInfo);
};

#endif
