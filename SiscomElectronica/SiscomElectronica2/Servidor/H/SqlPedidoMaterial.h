#ifndef __SQLPEDIDOMATERIAL_H__
#define __SQLPEDIDOMATERIAL_H__
#include <SiscomDesarrollo2.h>

void SqlRegistraEstadosPedidoRecibioEnExpendio(SArgsSiscom *pSAgsSiscom);
void SqlActualizaExistenciasPorEntregaPedido(SArgsSiscom *pSAgsSiscom);
void SqlRegistraRecibePedido(SArgsSiscom *pSAgsSiscom);
void SqlExistenciaExpendio(SArgsSiscom *pSAgsSiscom);
void SqlImprimePedido(SArgsSiscom *pSAgsSiscom);
void SqlDetallePedidoExpendio(SArgsSiscom *pSAgsSiscom);
void SqlPedidosExpendios(SArgsSiscom *pSAgsSiscom);
void SqlRegistraPedidoMaterial(SArgsSiscom *pSAgsSiscom);
void SqlRegistraDetallePedidoMaterial(SArgsSiscom *pSAgsSiscom);
void SqlRegistraEstadosPedidoMaterial(SArgsSiscom *pSAgsSiscom);
void SqlRegistraUltimoEstadoPedido(SArgsSiscom *pSAgsSiscom);
void SqlActualizaEstadoPedido(SArgsSiscom *pSAgsSiscom);
void SqlActualizaCantidadProductoPedido(SArgsSiscom *pSAgsSiscom);
void SqlPedidosPendientesPorEnviarAMatriz(SArgsSiscom *pSAgsSiscom);
void SqlDetallePedidoPendientePorEnviarAMatriz(SArgsSiscom *pSAgsSiscom);
void SqlDetallePedidoPendientePorEnviarAMatriz2(SArgsSiscom *pSAgsSiscom);

void SqlInsertIntoPedidoMaterial(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				 SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql);
void SqlInsertIntoEstadosPedidoMaterialRecibioEnExpendio(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				 SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql);

void SqlInsertIntoEstadosPedidoMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql);

void SqlInsertIntoDetallePedidoMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				SArgsSiscom *pSAgsSiscom,
				char *pchrPtrSql);

void SqlUpdateDetallePedidoMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				SArgsSiscom *pSAgsSiscom,
				char *pchrPtrSql);

void SqlUpdateExistenciasPorEntregaMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				SArgsSiscom *pSAgsSiscom,
				char *pchrPtrSql);
void SqlInsertIntoUltimoEstadoPedido(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql);
void SqlActualizaEstadoPedidoMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				      int *pintPtrNRegistros);

void SqlUpdateDetallePedidoCantidad(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				      int *pintPtrNRegistros);

#endif
