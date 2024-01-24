#ifndef __SQLCAJACENTRALIZADA_H__
#define __SQLCAJACENTRALIZADA_H__
#include <SiscomDesarrollo2.h>
void SqlOrdenesPendientes(SArgsSiscom *pSAgsSiscom);
void SqlDatosCliente(SArgsSiscom *pSAgsSiscom);
void SqlProductosOrdenCajaCentral(SArgsSiscom *pSAgsSiscom);
void SqlActualizaEstadoVenta(SArgsSiscom *pSAgsSiscom);
void SqlActualizaExistenciaPorOrdenCaja(SArgsSiscom *pSAgsSiscom);
void SqlInsertaVentaCaja(SArgsSiscom *pSAgsSiscom);
void SqlActualizaEstadoOrdenCaja(SArgsSiscom *pSAgsSiscom);
void SqlSentenciaEstadoVenta(LCamposSiscomPro2 *pLCSiscomPro2DatOrden, char *pchrPtrSql);
void SqlSentenciaActualizaExistencia(SArgsSiscom *pSAgsSiscom,
				     LCamposSiscomPro2 *pLCSiscomPro2Dat,
				     char *pchrPtrSql);
void SqlSentenciaInsertaVentasCaja(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				   char *pchrPtrSql);
				   
void SqlSentenciaActualizaEstadoOrdenCaja(
		LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
		char *pchrPtrSql);
#endif
