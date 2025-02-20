#include <ComprasSiscom.h>
#include <SqlComprasSiscom.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomReplicacion.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void ConsultaComprasSiscom(int pintSocket,
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
SiscomAgregaOperacion(SqlComprasSiscom,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoComprasSiscom,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

SiscomRegistroProL *AgregandoProductosALaCompra(
				 SiscomRegistroProL *pSisRegProLPtrCompra,
				 SiscomRegistroProL *pSisRegProLPtrDetalle)
{
SiscomRegistroProL *lSisRegProLPtrProdPrim=0,
		   *lSisRegProLPtrProdAct=0;
for(;
     pSisRegProLPtrDetalle;
     pSisRegProLPtrDetalle=pSisRegProLPtrDetalle->SiscomRegProLPtrSig)
{
  if(!SiscomComparaCampoRegistrosProL("idcompra",
  				     pSisRegProLPtrCompra,
				     pSisRegProLPtrDetalle))
  SiscomNodoRegistroPro(pSisRegProLPtrDetalle->SiscomCamProLPtrDato,
  			&lSisRegProLPtrProdPrim,
			&lSisRegProLPtrProdAct);

}
return lSisRegProLPtrProdPrim;
}
void AgregandoProductosCompraDelDia(SiscomRegistroProL *pSisRegProLPtrCompras,
				     SiscomRegistroProL *pSisRegProLPtrDetalle)
{
SiscomRegistroProL *lSisRegProLPtrProds;
char lchrArrBuffer[128];
 for(;pSisRegProLPtrCompras;
      pSisRegProLPtrCompras=pSisRegProLPtrCompras->SiscomRegProLPtrSig)
 {

	lSisRegProLPtrProds=AgregandoProductosALaCompra(pSisRegProLPtrCompras,
				    pSisRegProLPtrDetalle);
	SiscomAgregaCampoRegistros("Productos",0,pSisRegProLPtrCompras);
	SiscomRegistrosAlCampo("Productos",
				lSisRegProLPtrProds,
				0,
				pSisRegProLPtrCompras);
 }
}

				    
int EnviandoComprasSiscom(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrCompras,
		   *lSisRegProLPtrDetalleCompras;
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);

lSisRegProLPtrCompras=SiscomObtenRegistrosCampoRespuesta("Compras",
							    pSisOpePtrDato);
lSisRegProLPtrDetalleCompras=SiscomObtenRegistrosCampoRespuesta("DetalleCompras",
								pSisOpePtrDato);
AgregandoProductosCompraDelDia(lSisRegProLPtrCompras,
			       lSisRegProLPtrDetalleCompras);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrCompras);
SiscomEnviaRegistrosSocket(pSisOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSisRegProLPtrCompras);

}
