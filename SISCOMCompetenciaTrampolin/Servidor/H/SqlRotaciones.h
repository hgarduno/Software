#ifndef __SQLROTACIONES_H__
#define __SQLROTACIONES_H__
#include <SiscomDesarrollo2.h>

void SqlAparatosCompetencia(SArgsSiscom *);
void SqlGimnastasAparatoRonda(SArgsSiscom *);
void SqlRondasCompetencia(SArgsSiscom *);

void SqlEjecutaRotacion(const char *,
			LCamposSiscomPro2 *,
			LCamposSiscomPro2 **,
			LCamposSiscomPro2 **,
			int *);
void SqlEjecutaRotacion(const char *pchrPtrIdAparatoPasa,
			LCamposSiscomPro2 *pLCSiscomPro2GimsRonda,
			LCamposSiscomPro2 **pLCSiscomPro2RotacionPrim,
			LCamposSiscomPro2 **pLCSiscompro2RotacionAct,
			int *pintPtrNRegRotacion);
#endif
