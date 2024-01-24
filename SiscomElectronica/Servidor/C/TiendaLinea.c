#include <TiendaLinea.h>
#include <SqlTiendaLinea.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>


#include <SiscomOperaciones.h>
#include <SiscomInsercionesSql.h>

#include <SqlSiscomElectronica.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <ComunSiscomElectronica4.h>
#include <SoporteTiendaLinea.h>

#include <SqlTiendaLinea.h>

void AgrupaOrdenesProductosTiendaLinea(SiscomOperaciones *pSisOpePtrDato)
{
char *lchrPtrCampos[]={"ordenid",
			     "ordenfecha",
			     "clienteid",
			     "clientenombre",
			     "clienteapellido",
			     "clientecelular",
			     "direccioncalle",
			     "direccionnoexterior",
			     "direccioncp",
			     "direccionestado",
			     "ordenmetodopago",
			     0};

char *lchrPtrProductos[]={"itemid",
			  "productocodigo",
			  "productostock",
			  "itemcantidad",
			  "productodescripcioncorta",
			  0};
char lchrArrBuffer[512];
SiscomRegistroProL *lSisRegProLPtrOrdenAPrim=0,
		   *lSisRegProLPtrOrdenAAct=0,
		   *lSisRegProLPtrOrdenes=0;

lSisRegProLPtrOrdenes=SiscomObtenArgumentoPrimAsociadoOperaciones("PedidosTiendaLinea",
								  "Ordenes",
								  pSisOpePtrDato);
SiscomAgrupaPorCampo("ordenid",
		     "Productos",
		     lchrPtrCampos,
		     lchrPtrProductos,
		     lSisRegProLPtrOrdenes,
		     &lSisRegProLPtrOrdenAPrim,
		     &lSisRegProLPtrOrdenAAct);
SiscomAgregaArgumentoOperacion("OrdenesTiendaLinea",
				lSisRegProLPtrOrdenAPrim,
				lSisRegProLPtrOrdenAAct,
				pSisOpePtrDato);

}
int OrdenesTiendaLinea(SiscomOperaciones *pSisOpePtrDato)
{
 AgrupaOrdenesProductosTiendaLinea(pSisOpePtrDato);
}
void AgregaOrdenesTiendaLinea(SiscomRegistroProL *pSisRegProLPtrOrdenes,
			      SiscomOperaciones *pSisOpePtrDato)
{


}
