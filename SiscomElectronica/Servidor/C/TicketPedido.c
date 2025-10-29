#include <TicketPedido.h>
#include <SiscomDesarrolloMacros.h>
#include <OperacionesPedidos.h>
void FormaTextoDireccionEntrega(SiscomOperaciones *pSisOpePtrDato,
				 char *pchrPtrDireccion)
{
SiscomRegistroProL *lSisRegProLPtrPedido,
		   *lSisRegProLPtrPEntrega,
		   *lSisRegProLPtrCliente;
char lchrArrBuffer[1024];
*pchrPtrDireccion=0;
LogSiscom("Analizando el punto de entrega");

lSisRegProLPtrPedido=SiscomRegistroAsociadoEntradaOperacion("Envio",
							    "Pedido",
							    pSisOpePtrDato);
lSisRegProLPtrPEntrega=SiscomObtenRegistrosCampoProL("PuntoEntrega",lSisRegProLPtrPedido);
lSisRegProLPtrCliente=SiscomRegistroAsociadoEntradaOperacion("Envio",
							     "Cliente",
							     pSisOpePtrDato);
/*
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrPedido);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrPEntrega);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrCliente);
SiscomRegistroProtocoloLog(lchrArrBuffer,DireccionEntregaPedido(pSisOpePtrDato));
*/
sprintf(pchrPtrDireccion,
	"Se entrega en: %s",
	SiscomObtenCampoRegistroProLChar("PuntoEntrega",lSisRegProLPtrPEntrega));
}


