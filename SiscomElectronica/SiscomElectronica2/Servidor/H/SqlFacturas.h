#ifndef __SQLFACTURAS_H__
#define __SQLFACTURAS_H__
#include <SiscomDesarrollo2.h>

void SqlRegistrandoFactura(SArgsSiscom *pSAgsSiscom);
void SqlRegistrandoFacturaPersonaFisica(SArgsSiscom *pSAgsSiscom);
void SqlRegistrandoFacturaPersonaMoral(SArgsSiscom *pSAgsSiscom);
void SqlRegistrandoDetalleFactura(SArgsSiscom *pSAgsSiscom);
void SqlFacturasComprasPeriodo(SArgsSiscom *);
void SqlDetalleFactura(SArgsSiscom *);
void SqlBuscaFacturas(SArgsSiscom *);
void AnalizaNumeroFactura(SArgsSiscom *pSAgsSiscom,
			  char *pchrPtrSql);
void SqlActualizaNumeroFactura(SArgsSiscom *);
void SqlGeneraActualizaNumeroFactura(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);





void SqlInsertaFacturasCompras(SArgsSiscom *);
void SqlGeneraInsertaFacturasCompras(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SqlInsertIntoFacturas(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubRegDat,
			   SArgsSiscom *pSAgsSiscom,
			   char *pchrPtrSql);
void SqlInsertIntoFacturasFisicas(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubRegDat,
			   SArgsSiscom *pSAgsSiscom,
			   char *pchrPtrSql);
void SqlInsertIntoFacturasMorales(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubRegDat,
			   SArgsSiscom *pSAgsSiscom,
			   char *pchrPtrSql);
void SqlInsertIntoDetalleFactura(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 SArgsSiscom *pSArgsSiscom,
				 char *pchrPtrSql);
#endif
