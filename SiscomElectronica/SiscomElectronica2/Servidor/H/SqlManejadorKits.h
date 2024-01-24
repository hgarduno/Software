#ifndef __SQLMANEJADORKITS_H__
#define __SQLMANEJADORKITS_H__
#include <SiscomDesarrollo2.h>
void SqlRegistraTipoProducto(SArgsSiscom *pSAgsSiscom);
void SqlRegistraProductosTipoProducto(SArgsSiscom *pSAgsSiscom);

void SqlInsertIntoProductoPorTipoProducto(SArgsSiscom *pSAgsSiscom,
				 	  char *pchrPtrBufferSql,
					  LCamposSiscomPro2 *pLCSiscomPro2Dat);
void SqlInsertIntoDefinicionTiposProducto(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					   SArgsSiscom *pSAgsSiscom,
					   char *pchrPtrSql);
#endif
