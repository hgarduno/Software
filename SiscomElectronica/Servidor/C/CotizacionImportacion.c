#include <CotizacionImportacion.h>

#include <SqlCotizacionImportacion.h>
#include <ComunSiscomElectronica4.h>


#include <string.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomInsercionesSql.h>
#include <SiscomMacrosInsercionesSql.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>

void SeleccionoCotizaImportacion(int pintSocket,
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
SiscomAgregaOperacion(SqlDetalleCotizacionImportacion,&lSiscomProDat);
SiscomAgregaOperacion(SeleccionandoCotizacionImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RegistraProductoCotizaImportacion(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCotizacionImportacion,&lSiscomProDat);
SiscomAgregaOperacion(CalculandoPrecioImporteProductosCotizados,&lSiscomProDat);
SiscomAgregaOperacion(CalculandoImporteCotizacion,&lSiscomProDat);
SiscomAgregaOperacion(CalculandoPesoCotizacion,&lSiscomProDat);
SiscomAgregaOperacion(SqlAnexaProductoCotizacionImportacion,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoProductoCotizaImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultandoCotizacionImportacion(int pintSocket,
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
SiscomAgregaOperacion(SqlCotizacionesImportacion,&lSiscomProDat);
SiscomAgregaOperacion(ConsultaCotizacionImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RegistrandoCotizacionImportacion(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCotizacionImportacion,&lSiscomProDat);
SiscomAgregaOperacion(AgregaIdCotizacionImportacion,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCotizacionImportacion,&lSiscomProDat);
SiscomAgregaOperacion(RegistraCotizacionImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int RegistraCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("Registrando La cotizacion");
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomArgumentoInsercionSqlLog("SqlCotizacionImportacion",
				lchrArrBuffer,
				pSiscomOpePtrDato);
pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
pSiscomOpePtrDato->SiscomRegProLPtrActRes=0;
SiscomFormaEnviaRegistroRespuesta(pSiscomOpePtrDato,
				  lchrArrBuffer,
				  "Estado,IdCotizacion,",
				  "0",
				  SiscomCampoAsociadoEntradaOperacion("Envio",
				  				      "IdCotizacion",
								      pSiscomOpePtrDato));
}

int ConsultaCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("Consultando La cotizacion");
SiscomEnviaAsociadoRespuestaCliente("CotizacionImportacion",lchrArrBuffer,pSiscomOpePtrDato);
}



int AgregaIdCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdCotizacion",pSiscomOpePtrDato);
return 0;
}

int ArgumentoCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlCotizacionImportacion",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}

int RegistrandoProductoCotizaImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256]; 
/*SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);*/ 
SiscomEnviaAsociadoEntradaCliente("Envio",lchrArrBuffer,pSiscomOpePtrDato);
/*
SiscomArgumentoInsercionSqlLog("SqlCotizacionImportacion",
				lchrArrBuffer,
				pSiscomOpePtrDato);
*/
return 0;
}

int CalculandoPrecioImporteProductosCotizados(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrProductos;
if((lSisRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								   "Productos",
								   pSiscomOpePtrDato)))
{
for( ; lSisRegProLPtrProductos;lSisRegProLPtrProductos=lSisRegProLPtrProductos->SiscomRegProLPtrSig)
{
SiscomMultiplicaCamposACampo("Cantidad","Precio","Importe","%.3f",lSisRegProLPtrProductos);
SiscomMultiplicaCamposACampo("Cantidad","Peso","PesoTotal","%.3f",lSisRegProLPtrProductos);
}
}
return 0;
}
int SeleccionandoCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomEnviaAsociadoRespuestaCliente("DetalleCotizacionImportacion",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

int CalculandoImporteCotizacion(SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltPrecioCotizacion;
SiscomRegistroProL *lSisRegProLPtrProductos;
if((lSisRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								   "Productos",
								   pSiscomOpePtrDato)))
lfltPrecioCotizacion=SiscomObtenSumatoriaRegistros("Importe",lSisRegProLPtrProductos);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","ImporteTotal",lfltPrecioCotizacion,pSiscomOpePtrDato);
return 0;
}
int CalculandoPesoCotizacion(SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltPesoCotizacion;
SiscomRegistroProL *lSisRegProLPtrProductos;
if((lSisRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								   "Productos",
								   pSiscomOpePtrDato)))
lfltPesoCotizacion=SiscomObtenSumatoriaRegistros("PesoTotal",lSisRegProLPtrProductos);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","PesoTotal",lfltPesoCotizacion,pSiscomOpePtrDato);
return 0;
}
