#include <Compras.h>
#include <SqlCompras.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>


void CalculaTotalCompra(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(SumatoriaCompra,&lSiscomProDat);
SiscomAgregaOperacion(EnviaTotalesCompra,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RegistraCompra(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdCompra,&lSiscomProDat);
SiscomAgregaOperacion(GeneraFechaCompra,&lSiscomProDat);
SiscomAgregaOperacion(OrdenCompra,&lSiscomProDat); 
SiscomAgregaOperacion(SqlRegistraCompra,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdCompraRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void RegistraPrecioCompra(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraPrecioCompra,&lSiscomProDat);
SiscomAgregaOperacion(EnviaEstadoRegistroPrecioCompra,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int GeneraIdCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdCompra",pSiscomOpePtrDato);
}

int EnviaIdCompraRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrIdCompra;
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
lchrPtrIdCompra=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdCompra",
						     pSiscomOpePtrDato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdCompra,Mensajes,",
		       lchrPtrIdCompra,
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomAsociadosArgumentoLog("SqlInsertaCompra",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
}

int GeneraFechaCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
/*
 *
 Queretaro a 24 de febrero del 2016
 Se integro la fecha como un dato de captura 
 se elimina fijar fecha de compra ...
const char *lchrPtrFechaCompra;
lchrPtrFechaCompra=SiscomCampoAsociadoEntradaOperacion("Envio",
						       "Fecha",
							pSiscomOpePtrDato);
LogSiscom("%x (%s)",lchrPtrFechaCompra,lchrPtrFechaCompra);
if(*lchrPtrFechaCompra)
SiscomActualizaCampoAsociadoEntrada("Envio","Fecha",(char *)lchrPtrFechaCompra,pSiscomOpePtrDato);
else
SiscomAsignaFechaAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
*/
}
int OrdenCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrOrden,
		   *lSiscomRegProLPtrProductosPrim=0,
		   *lSiscomRegProLPtrProductosAct=0;
char lchrArrBuffer[256];
lSiscomRegProLPtrOrden=SiscomRegistrosAsociadosCampoEntrada("Envio",
							    "Orden",
							    pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrOrden);
lSiscomRegProLPtrProductosPrim=SiscomObtenRegistrosCampoProL("Productos",lSiscomRegProLPtrOrden);
SiscomAgregaArgumentoOperacion("ProductosOrden",
			       lSiscomRegProLPtrProductosPrim,
			       lSiscomRegProLPtrProductosAct,
			       pSiscomOpePtrDato);
SiscomAgregaCampoRegistros("IdCostoBruto",0,lSiscomRegProLPtrProductosPrim);
SiscomIdUnicoRegistros("IdCostoBruto",lSiscomRegProLPtrProductosPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProductosPrim);
}

int SumatoriaCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
float lfltTotalOrden;
SiscomRegistroProL *lSiscomRegProLPtrOrden;
lSiscomRegProLPtrOrden=SiscomRegistrosAsociadosCampoEntrada("Envio","Productos",pSiscomOpePtrDato);
lfltTotalOrden=SiscomObtenSumatoriaRegistros("CostoBruto",lSiscomRegProLPtrOrden);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","Total",lfltTotalOrden,pSiscomOpePtrDato);
}

int EnviaTotalesCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(
	&lSiscomRegProLPtrPrim,
	&lSiscomRegProLPtrAct,
	lchrArrBuffer,
	"Total,Iva,SubTotal,",
	SiscomCampoAsociadoEntradaOperacion("Envio","Total",pSiscomOpePtrDato),
	"0",
	"0");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
}

int EnviaEstadoRegistroPrecioCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlInsertaPrecio",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
}

int PreparaDatosCosto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrCosto=SiscomRegistrosAsociadosCampoEntrada("Envio","Costo",pSiscomOpePtrDato);
/*SiscomRegistrosLog(lchrArrBuffer,lSisRegProLPtrCosto); */
}
