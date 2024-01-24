#ifndef __SQLPROMOCIONESELECTRONICA_H__
#define __SQLPROMOCIONESELECTRONICA_H__
#include <SiscomDesarrollo2.h>


void SqlRegistraPromocion(SArgsSiscom *pSAgsSiscom);

void SqlInsertaPromocion(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);
#endif
