#ifndef __ORDENESAFACTURAR_H__
#define __ORDENESAFACTURAR_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OpOrdenesAFacturar();
void OrdenesParaFacturar(SArgsSiscom *pSAgsSiscom);
void CalculaFactura(SArgsSiscom *pSAgsSiscom,
		    LCamposSiscomPro2Agrupados *pLCSisPro2AgruFact);
void TotalesPorProducto(LCamposSiscomPro2Agrupados *pLCSisPro2AgruFact);
void RespuestaTotalFacturacion(LCamposSiscomPro2Agrupados *pLCSisPro2AgruFact,
		    LCamposSiscomPro2 **pLCSiscomPro2Reg,
		    int *pintPtrNRegistros);
void CalculaTotalesFacturacion(LCamposSiscomPro2 *pLCSiscomPro2Dat);
void ProdParaFacturarProdOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			       LCamposSiscomPro2 **pLCSiscomPro2ProdFact,
			       LCamposSiscomPro2 **pLCSiscomPro2ProdOrden,
			       int *pintPtrNProdOrden);
void AgregaProductosOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			  int pintNProdOrden,
			  SArgsSiscom *pSAgsSiscom);
#endif
