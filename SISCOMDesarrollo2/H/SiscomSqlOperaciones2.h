#ifndef __SISCOMSQLOPERACIONES_H__
#define __SISCOMSQLOPERACIONES_H__
#include <SiscomDesarrollo2.h>
void SiscomSqlInsercionesDatosEntrada(SArgsSiscom *pSAgsSiscom,
				const char *pchrPtrArgumentoSalida,
				char *pchrPtrBufferSql,
				void (*SentenciaSql)(SArgsSiscom *pSAgsSiscom,
						    char *pchrPtrBuffer,
						     LCamposSiscomPro2 *pLCSiscomPro2Dat));
#endif
