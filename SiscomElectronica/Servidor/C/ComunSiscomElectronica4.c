#include <ComunSiscomElectronica4.h>
#include <SiscomConfiguracionServidor.h>

#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomReplicacion.h>
#include <ComunSiscomElectronica4.h>
#include <SqlSiscomElectronica.h>

#include <string.h>



/* Tepotzotlan Mexico 20 de noviembre 2022
 * 
 * La funcion tomara del  Argumento Expendios, la 
 * lista de expendios de los que obtendra los datos
 * de comunicacion de acceso a datos
 */

void AgregaIdExpendioParaLaConsulta(SiscomRegistroProL *pSisRegProLPtrDato,
				    char *pchrPtrCadena)
{
 if(pSisRegProLPtrDato->SiscomRegProLPtrSig)
 sprintf(pchrPtrCadena,
 	"%s,",
	  SiscomObtenCampoRegistroProLChar("IdEmpresa",pSisRegProLPtrDato));

  else
  sprintf(pchrPtrCadena,
  	  "%s);",
	  SiscomObtenCampoRegistroProLChar("IdEmpresa",pSisRegProLPtrDato));
}
int CondicionConsultaUnosExpendios(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrExpendios;
char lchrArrBuffer[128];
char lchrArrCondicion[1024],lchrArrPaso[128];
if((lSisRegProLPtrExpendios=SiscomObtenArgumentoPrimOperaciones("Expendios",pSisOpePtrDato)))
{
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrExpendios);
strcpy(lchrArrCondicion,"where idempresa in(");
for(;
    lSisRegProLPtrExpendios;
    lSisRegProLPtrExpendios=lSisRegProLPtrExpendios->SiscomRegProLPtrSig)
{
     AgregaIdExpendioParaLaConsulta(lSisRegProLPtrExpendios,lchrArrPaso);
     strcat(lchrArrCondicion,lchrArrPaso);
}
SiscomActualizaCampoAsociadoEntrada("Envio",
				    "Condicion",
				    lchrArrCondicion,
				    pSisOpePtrDato);
}
}
int AgregaCampoCondicionConsultaUnosExpendios(const char *pchrPtrEnvio,
					      SiscomOperaciones *pSisOpePtrDato)
{
SiscomAgregaCampoAsociadoEntrada("Condicion",
				 0,
				 pchrPtrEnvio,
				 pSisOpePtrDato);
return 0;
}
					      
int CopiaExpendiosAArgumento(const char *pchrPtrEnvio,
			     const char *pchrPtrAsociado,
			     SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrExpendios;
if((lSisRegProLPtrExpendios=SiscomRegistrosAsociadosCampoEntrada(pchrPtrEnvio,
								 pchrPtrAsociado,
								 pSisOpePtrDato)))
{
SiscomAsignaRegistrosArgumentoOperaciones(lSisRegProLPtrExpendios,
					  lSisRegProLPtrExpendios,
					  "Expendios",
					  pSisOpePtrDato);
}
}
int ArgumentoConsultaUnosExpendios(SiscomOperaciones *pSisOpePtrDato)
{
SiscomAgregaArgumentoOperacion("Expendios",
                                (SiscomRegistroProL *)0,
                                (SiscomRegistroProL *)0,
                                pSisOpePtrDato);
return 0;
}

int AccesoDatosSeguridad3(SiscomOperaciones *pSiscomOpePtrDato)
{

strcpy(pSiscomOpePtrDato->chrArrDirIpSvrAccesoDatos,gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos4);
pSiscomOpePtrDato->intPuertoSvrAccesoDatos=gSSiscomConfiguracionSvr.intPuertoAccesoDatos4;
strcpy(pSiscomOpePtrDato->chrArrBaseDatos,"Seguridad3");

return 0;
}

int AccesoDatosSiscomElectronica4(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("Cliente conectado %s",gchrArrDirIpCliente);
strcpy(pSiscomOpePtrDato->chrArrDirIpSvrAccesoDatos,gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos4);
pSiscomOpePtrDato->intPuertoSvrAccesoDatos=gSSiscomConfiguracionSvr.intPuertoAccesoDatos4;
strcpy(pSiscomOpePtrDato->chrArrBaseDatos,gSSiscomConfiguracionSvr.chrPtrBaseDatos);
return 0;
}

int AccesoDatosSiscomMatriz(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomOperaciones lSiscomOpePtrDato;
lSiscomOpePtrDato=*pSiscomOpePtrDato;
SqlComunicacionMatriz(&lSiscomOpePtrDato);
strcpy(pSiscomOpePtrDato->chrArrDirIpSvrAccesoDatos,
       SiscomCampoAsociadoRespuesta("Matriz","diripsvrad",&lSiscomOpePtrDato));
strcpy(pSiscomOpePtrDato->chrArrBaseDatos,
       SiscomCampoAsociadoRespuesta("Matriz","basedatos",&lSiscomOpePtrDato));
pSiscomOpePtrDato->intPuertoSvrAccesoDatos=SiscomCampoAsociadoRespuestaOperacionInt("Matriz",
								"puerto",&lSiscomOpePtrDato);
return 0;
}

void ExpendiosSiscom(int pintSocket,
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
SiscomAgregaOperacion(SqlComunicacionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExpendios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ValidaReCaptura(int pintSocket,
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
SiscomAgregaOperacion(ValidandoReCaptura,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



void ValidaExistenciaATransferir(int pintSocket,
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
SiscomAgregaOperacion(ValidandoExistenciaATransferir,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
      

}
int ValidandoReCaptura(SiscomOperaciones *pSiscomOpePtrDato)
{
if(!SiscomComparaCamposAsociadoEntrada("Envio",
				      "CapturaUno",
				      "CapturaDos",
				      pSiscomOpePtrDato))
EnviaCampoIgual(pSiscomOpePtrDato);
else
EnviaCampoDesIgual(pSiscomOpePtrDato);
return 0;
}
void EnviaTransferenciaMayorCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
ArmaMensajeRegreso(&lSiscomRegProLPtrPrim,
		   &lSiscomRegProLPtrAct,
		   "Cantidad a Transferir, Mayor que la que se compro",
		   "1");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
}
void EnviaCantidadATransferirBien(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
ArmaMensajeRegreso(&lSiscomRegProLPtrPrim,
		   &lSiscomRegProLPtrAct,
		   "Cantidad a Transferir Valida",
		   "0");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
}
int ValidandoExistenciaATransferir(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrCantidad,
	   *lchrPtrCantidadComprada,
	   *lchrPtrCveProducto;
int lintCantidad,
	lintCantidadComprada;

lintCantidad=SiscomCampoAsociadoEntradaOperacionInt("Envio","Cantidad",pSiscomOpePtrDato);
lintCantidadComprada=SiscomCampoAsociadoEntradaOperacionInt("Envio",
							    "CantidadComprada",
							    pSiscomOpePtrDato);
lchrPtrCveProducto=SiscomCampoAsociadoEntradaOperacion("Envio","CveProducto",pSiscomOpePtrDato);
if(lintCantidad>lintCantidadComprada)
EnviaTransferenciaMayorCompra(pSiscomOpePtrDato);
else
EnviaCantidadATransferirBien(pSiscomOpePtrDato);

/*
 *
LogSiscom("La Cantidad %d a transferir del producto %s y se compro %d",
	  lintCantidad,
	  lchrPtrCveProducto,
	  lintCantidadComprada);
LogSiscom("Procesando de la free scale :)");	

write(pSiscomOpePtrDato->intSocket,
	"Conectando desde del Servidor SISCOM :) OK",
	43);
*/
}


void ArmaMensajeRegreso(SiscomRegistroProL **pSiscomRegProLPtrRegPrim,
			SiscomRegistroProL **pSiscomRegProLPtrRegAct,
			const char *pchrPtrMensaje,
			const char *pchrPtrEstado)
{

char lchrArrBuffer[128];
SiscomAnexaRegistroPro(pSiscomRegProLPtrRegPrim,
		       pSiscomRegProLPtrRegAct,
		       lchrArrBuffer,
		       "Mensaje,Estado,",
		       pchrPtrMensaje,
		       pchrPtrEstado);

}

void EnviaCampoIgual(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
ArmaMensajeRegreso(&lSiscomRegProLPtrPrim,
		   &lSiscomRegProLPtrAct,
		   "El Campo Es igual",
		   "1");
LogSiscom("El Campo Es Igual");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
}
void EnviaCampoDesIgual(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrRegresoPrim=0,
		   *lSiscomRegProLPtrRegresoAct=0;

ArmaMensajeRegreso(&lSiscomRegProLPtrRegresoPrim,
		   &lSiscomRegProLPtrRegresoAct,
		   "El Campo NO ES IGUAL",
		   "0");
LogSiscom("El Campo NO Es Igual");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrRegresoPrim);

}
int EnviaExpendios(SiscomOperaciones *pSiscomOpePtrDato)
{

return 0;
}
int ActualizaMatrizConsultaExpendios(SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLPtrMatriz;
SiscomRegistroProL *lSisRegProLPtrExpendios,*lSisRegProLPtrExpendio;
char *lchrPtrDirIpMatriz;
if((lSisRegProLPtrExpendios=SiscomObtenArgumentoPrimAsociadoOperaciones("Expendios",
  								        "Servidores",
									pSiscomOpePtrDatos)))
{
}
if((lSisRegProLPtrMatriz=SiscomObtenArgumentoPrimOperaciones("Matriz",pSiscomOpePtrDatos)))
{
}
for(lSisRegProLPtrExpendio=lSisRegProLPtrExpendios;
    lSisRegProLPtrExpendio;
    lSisRegProLPtrExpendio=lSisRegProLPtrExpendio->SiscomRegProLPtrSig)
{
  if(!SiscomComparaCampoRegistrosProL("idempresa",lSisRegProLPtrMatriz,lSisRegProLPtrExpendio))
  {
     lchrPtrDirIpMatriz=(char *)SiscomObtenCampoRegistroProLChar("diripsvrad",lSisRegProLPtrMatriz);
     SiscomActualizaCampoAsignaMemoria2("dirip",lchrPtrDirIpMatriz,lSisRegProLPtrExpendio);
     return 0;
  }
}
return 0;
}


void LogOrden(const char *pchrPtrArchivo,
	      const char *pchrPtrFuncion,
	      int pintNLinea,
	      SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrLinea[256];
const char *lchrPtrIdVenta,
	   *lchrPtrIdTipoOrden;
SiscomRegistroProL *lSisRegProLPtrProductos;
lchrPtrIdVenta=SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato);
lchrPtrIdTipoOrden=SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoOrden",pSiscomOpePtrDato);
sprintf(lchrArrLinea,
	"%-15s%-12s%-12s%-12s%-22s%-10s%-13s%-13s",
	"Punto de venta",
	"IdOrden",
	"IdTipoOrden",
	"Consecutivo",
	"Producto",
	"Cantidad",
	"Precio",
	"Se Puede Vender");

SiscomMensajesLog4(pchrPtrArchivo,pchrPtrFuncion,pintNLinea,"%s",lchrArrLinea);
if((lSisRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio","Productos",pSiscomOpePtrDato)))
{

for(;
     lSisRegProLPtrProductos;
     lSisRegProLPtrProductos=lSisRegProLPtrProductos->SiscomRegProLPtrSig)
{
sprintf(lchrArrLinea,
	"%-15s%-12s%-12s%-12s%-22s%-10s%-13s%-13s",
	gchrArrDirIpCliente,
	lchrPtrIdVenta,
	lchrPtrIdTipoOrden,
	SiscomObtenCampoRegistroProLChar("IdConsecutivo",lSisRegProLPtrProductos),
	SiscomObtenCampoRegistroProLChar("Clave",lSisRegProLPtrProductos),
	SiscomObtenCampoRegistroProLChar("Cantidad",lSisRegProLPtrProductos),
	SiscomObtenCampoRegistroProLChar("Precio",lSisRegProLPtrProductos),
	SiscomObtenCampoRegistroProLChar("SePuedeVender",lSisRegProLPtrProductos));
SiscomMensajesLog4(pchrPtrArchivo,pchrPtrFuncion,pintNLinea,"%s",lchrArrLinea);
}
sprintf(lchrArrLinea,
	"%82s%7s",
	"Importe",
	SiscomCampoAsociadoEntradaOperacion("Envio","Importe",pSiscomOpePtrDato));

SiscomMensajesLog4(pchrPtrArchivo, pchrPtrFuncion, pintNLinea,"%s",lchrArrLinea);

}
}



void SiscomRespuestaEstado(SiscomOperaciones *pSisOpePtrDato,
			  const char *pchrPtrEstado,
			  const char *pchrPtrDescripcion)
{
char lchrArrBuffer[256];
pSisOpePtrDato->SiscomRegProLPtrPrimRes=0;
pSisOpePtrDato->SiscomRegProLPtrActRes=0;
SiscomAnexaRegistroPro(&pSisOpePtrDato->SiscomRegProLPtrPrimRes,
                       &pSisOpePtrDato->SiscomRegProLPtrActRes,
                       lchrArrBuffer,
                       "Estado,Descripcion,",
                       pchrPtrEstado,
                       pchrPtrDescripcion);
  SiscomEnviaRegistrosRespuesta(pSisOpePtrDato,lchrArrBuffer);
}

void LogAsociadoEnvio(const char *pchrPtrArchivo,
		      const char *pchrPtrFuncion,
		      int pintNLinea,
		      char *pchrPtrBuffer,
		      SiscomOperaciones *pSisOpePtrDato)
{
 SiscomAsociadoEntrada(pchrPtrArchivo,
 		       pchrPtrFuncion,
		       pintNLinea,
		       "Envio",
		       pchrPtrBuffer,
		       pSisOpePtrDato);
}


