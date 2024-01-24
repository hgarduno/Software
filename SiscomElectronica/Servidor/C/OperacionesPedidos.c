#include <OperacionesPedidos.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
const char *NombrePuntoEntrega(SiscomRegistroProL *pSisRegProLPtrPedido)
{
SiscomRegistroProL *lSisRegPEntrega;
const char *lchrPtrNombre=0;
if((lSisRegPEntrega=SiscomObtenRegistrosCampoProL("PuntoEntrega",pSisRegProLPtrPedido)))
lchrPtrNombre=SiscomObtenCampoRegistroProLChar("PuntoEntrega",lSisRegPEntrega);
else
LogSiscom("El pedido se envio a la direccion del cliente");
return lchrPtrNombre;
}
SiscomRegistroProL *DireccionEntregaPedido(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrDireccion,
		   *lSisRegProLPtrPEntrega;
int lintTipoEntrega;
char lchrArrBuffer[256];
if((lSisRegProLPtrPEntrega=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
								       "Pedido",
								       "PuntoEntrega",
								       pSisOpePtrDato)))
{
 if((lSisRegProLPtrDireccion=SiscomObtenRegistrosCampoProL("Direccion",
 							    lSisRegProLPtrPEntrega)))
 return lSisRegProLPtrDireccion;
 else
 {
 LogSiscom("NO llego direccion en el punto de entrega");
 return 0;
 }
}
else
return 0;
}

const char *IdDireccionEntregaPedido(SiscomOperaciones *pSisOpePtrDato)
{
   return SiscomObtenCampoRegistroProLChar("IdDireccion0",
   			DireccionEntregaPedido(pSisOpePtrDato));
}
const char *ObtenTipoEntregaPedido(SiscomRegistroProL *pSisRegProLPtrPedido)
{
 if(NombrePuntoEntrega(pSisRegProLPtrPedido))
 return "0";
 else
 return "1";
}
