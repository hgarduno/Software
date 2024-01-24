#ifndef __ZEMPRESA_H__
#define __ZEMPRESA_H__
#include <zSiscomRegistro.h>
class SiscomRegistro3;
class zEmpresa:public zSiscomRegistro
{
public:
	zEmpresa(const char *pchrPtrIdEmpresa,const char *pchrPtrRazonSocial);
	const char *RazonSocial();
	const char *IdEmpresa();
	void IdEmpresa(const char *pchrPtrIdEmpresa);
	void RegimenFiscal(const char *pchrPtrRegimenFiscal);

	static zEmpresa *DeConsultaEmpresas(zSiscomRegistro *pzSisRegEmpresa);
	static zEmpresa *DeSiscomRegistro3(SiscomRegistro3 *);
};

#endif
