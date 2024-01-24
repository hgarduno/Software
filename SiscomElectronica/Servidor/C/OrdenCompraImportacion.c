#include <OrdenCompraImportacion.h>
#include <SqlOrdenCompraImportacion.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>

void ProductoCompraImportacion(int pintSocket,
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
SiscomAgregaOperacion(SqlProductoCompraImportacion,&lSiscomProDat); 
SiscomAgregaOperacion(ObtenProductoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CalculandoPesoImporteTotal(int pintSocket,
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
SiscomAgregaOperacion(CalculaPesoImporteTotal,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int ObtenProductoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
SiscomAsociadoRespuestaLog("ProductoProveedor",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("Compras",lchrArrBuffer,pSiscomOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
return 0;
}
int PuedeMultiplicar(const char *pchrPtrCampo,SiscomOperaciones *pSiscomOpePtrDato)
{
  return SiscomCampoAsociadoEntradaOperacion("Envio",pchrPtrCampo,pSiscomOpePtrDato) ? 1 :0 ;
}
int PuedeMultiplicarPrecio(SiscomOperaciones *pSiscomOpePtrDato)
{
return PuedeMultiplicar("Precio",pSiscomOpePtrDato) &&
       PuedeMultiplicar("Cantidad",pSiscomOpePtrDato);
}
int PuedeMultiplicarPeso(SiscomOperaciones *pSiscomOpePtrDato)
{
return PuedeMultiplicar("Peso",pSiscomOpePtrDato) &&
       PuedeMultiplicar("Cantidad",pSiscomOpePtrDato);
}

int CalculaPesoImporteTotal(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
if(PuedeMultiplicarPrecio(pSiscomOpePtrDato))
SiscomMultiplicaCamposACampoEntrada("Envio",
				    "Precio",
				    "Cantidad",
				    "PrecioTotal",
				    "%.5f",
				    pSiscomOpePtrDato);
if(PuedeMultiplicarPeso(pSiscomOpePtrDato))
SiscomMultiplicaCamposACampoEntrada("Envio",
				    "Peso",
				    "Cantidad",
				    "PesoTotal",
				    "%.5f",
				    pSiscomOpePtrDato);
SiscomEnviaAsociadoEntradaCliente("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}
