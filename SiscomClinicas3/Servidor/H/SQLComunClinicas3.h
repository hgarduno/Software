#ifndef __SQLCOMUNCLINICAS3_H__
#define __SQLCOMUNCLINICAS3_H__
#include <SiscomDesarrollo2.h>

void SQLPreciosServicio(const char *pchrPtrArgumento,
			SArgsSiscom *pSAgsSiscom);

void SQLGeneraRegistroPreciosServicio(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SQLPreciosServicioMedico(const char *pchrPtrArgumento,
			SArgsSiscom *pSAgsSiscom);

void SQLGeneraRegistroPreciosServicioMedico(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

#endif
