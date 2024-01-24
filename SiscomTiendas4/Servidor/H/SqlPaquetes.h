#ifndef __SQLPAQUETES_H__
#define __SQLPAQUETES_H__
#include <SiscomDesarrollo2.h>

void SQLRegistraPaquete(SArgsSiscom *pSAgsSiscom);
void SQLGeneraRegistraPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);


void SQLRegistraProductosPaquete(SArgsSiscom *pSAgsSiscom);
void SQLGeneraRegistraProductosPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SqlEliminaPaquete(SArgsSiscom *pSAgsSiscom);
void SqlGeneraRegistraEliminaPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
void SqlEliminaProductoPaquete(SArgsSiscom *pSAgsSiscom);
void SqlGeneraRegistraEliminaProductoPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);




void SqlAnexarProductoPaquete(SArgsSiscom *pSAgsSiscom);
void SqlGeneraRegistraAnexarProductoPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);


void SqlPaquetesDisponibles(SArgsSiscom *pSAgsSiscom);
void SqlProductosPaquete(SArgsSiscom *pSAgsSiscom);
#endif
