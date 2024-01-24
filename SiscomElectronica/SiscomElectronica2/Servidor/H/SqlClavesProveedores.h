#ifndef __SQLCLAVESPROVEEDORES_H__
#define __SQLCLAVESPROVEEDORES_H__
#include <SiscomDesarrollo2.h>
void SqlClavesProveedores(SArgsSiscom *pSAgsSiscom);;
void SqlActualizaClaveProveedor(SArgsSiscom *pSAgsSiscom);
void SqlInsertaClaveProveedor(SArgsSiscom *pSAgsSiscom);
void SqlUpdateClavesProveedores(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				      int *pintPtrNRegistros);

void SqlInsertClavesProveedores(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				      int *pintPtrNRegistros);
#endif
