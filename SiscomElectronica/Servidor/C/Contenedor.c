#include <Contenedor.h>

#include <ComunSiscomElectronica4.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomDesarrolloMacros.h>

#include <string.h>
void AgregaFacturaContenedor(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(AgregandoFacturaContenedor,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}
void AgregandoProductosCompraImportacion(SiscomRegistroProL *pSisRegProLPtrCompra,
					 SiscomRegistroProL **pSisRegProLPtrProdCPrim,
					 SiscomRegistroProL **pSisRegProLPtrProdCAct)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrProductos;
if((lSisRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",pSisRegProLPtrCompra)))
{
 for(;
     lSisRegProLPtrProductos;
     lSisRegProLPtrProductos=lSisRegProLPtrProductos->SiscomRegProLPtrSig)
    SiscomNodoRegistroPro(lSisRegProLPtrProductos->SiscomCamProLPtrDato,
    			  pSisRegProLPtrProdCPrim,
			  pSisRegProLPtrProdCAct);
}
}

void CompraProductosFacturas(SiscomRegistroProL *pSisRegProLPtrCompras,
			     SiscomRegistroProL **pSisRegProLPtrProdsC)
{
SiscomRegistroProL *lSisRegProLPtrCompra,
		   *lSisRegProLPtrProdsContenedorAct=0;
char lchrArrBuffer[256];
*pSisRegProLPtrProdsC=0;
if((lSisRegProLPtrCompra=SiscomObtenRegistrosCampoProL("Compras",pSisRegProLPtrCompras)))
{
    for(;
    	lSisRegProLPtrCompra;
	lSisRegProLPtrCompra=lSisRegProLPtrCompra->SiscomRegProLPtrSig)
    {
       LogSiscom("Agregando Productos de %s",
       		  SiscomObtenCampoRegistroProLChar("NumFactura",lSisRegProLPtrCompra));
      AgregandoProductosCompraImportacion(lSisRegProLPtrCompra,
      					  pSisRegProLPtrProdsC,
      					  &lSisRegProLPtrProdsContenedorAct);
    }
}
}
void SumaProductosFacturas(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrContenedor;
char lchrArrBuffer[256];
if((lSisRegProLPtrContenedor=SiscomRegistrosAsociadoEntradaOperacion("Envio",pSisOpePtrDato)))
{
  SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrContenedor);
  CompraProductosFacturas(lSisRegProLPtrContenedor,
  			  &pSisOpePtrDato->SiscomRegProLPtrPrimRes);
}
}
int AgregandoFacturaContenedor(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256];
SumaProductosFacturas(pSisOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSisOpePtrDato,lchrArrBuffer);
return 0;
}
