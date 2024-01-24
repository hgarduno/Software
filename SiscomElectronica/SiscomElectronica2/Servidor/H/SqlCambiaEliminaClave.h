#ifndef __SQLCAMBIAELIMINACLAVE_H__
#define __SQLCAMBIAELIMINACLAVE_H__
#include <SiscomDesarrollo2.h>

void SqlFormaInsertaCveNueva(SArgsSiscom *pSAgsSiscom);




void SqlInsertandoCveNueva(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);


void SqlFormaActualizaPrecios(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaTransfiereMaterial(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaBodegaAExpendio(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaCompras(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaDetallePedido(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaDetallePractica(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaInventario(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaInventarioBodega(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaMaterialBodega(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaTicketImpresoHistorial(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaExistencias(SArgsSiscom *pSAgsSiscom);
void SqlFormaActualizaVentas(SArgsSiscom *pSAgsSiscom);

void SqlFormaEliminaProductos(SArgsSiscom *pSAgsSiscom);
void SqlFormaEliminaDesajusteInventario(SArgsSiscom *pSAgsSiscom);
void SqlFormaEliminaTransfiereMaterial(SArgsSiscom *pSAgsSiscom);
void SqlFormaEliminaBodegaAExpendio(SArgsSiscom *pSAgsSiscom);
void SqlFormaEliminaClaveSat(SArgsSiscom *pSAgsSiscom);

void SqlActualizandoCveTabla(const char *pchrPtrTabla,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlActualizandoPrecios(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlActualizandoTransfiereMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlActualizandoBodegaAExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlActualizandoCompras(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlActualizandoDetallePedido(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlActualizandoDetallePractica(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlActualizandoInventario(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlActualizandoInventarioBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlActualizandoMaterialBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlActualizandoTicketImpresoHistorial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlActualizandoExistencias(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlActualizandoVentas(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlEliminandoProductos(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlEliminandoClaveSat(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlEliminandoDesajusteInventario(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);



void SqlEliminandoProductosTabla(const char *pchrPtrTabla,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlEliminandoTransfiereMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlEliminandoBodegaAExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlFormaEliminaPrecios(SArgsSiscom *pSAgsSiscom);
void SqlEliminandoPrecios(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlFormaEliminaMaterialBodega(SArgsSiscom *pSAgsSiscom);
void SqlEliminandoMaterialBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);


void SqlFormaEliminaCompras(SArgsSiscom *pSAgsSiscom);
void SqlEliminandoCompras(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);


void SqlFormaEliminaInventario(SArgsSiscom *pSAgsSiscom);
void SqlEliminandoInventario(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);



void SqlFormaEliminaTicketImpresoHistorial(SArgsSiscom *pSAgsSiscom);
void SqlEliminandoTicketImpresoHistorial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);


void SqlFormaEliminaDetallePractica(SArgsSiscom *pSAgsSiscom);
void SqlEliminandoDetallePractica(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);


void SqlFormaEliminaInventarioBodega(SArgsSiscom *pSAgsSiscom);
void SqlEliminandoInventarioBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
#endif
