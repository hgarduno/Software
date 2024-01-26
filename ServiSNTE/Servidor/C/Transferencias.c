#include <Transferencias.h>
#include <Ventas.h>
#include <SqlTransferencias.h>
#include <SqlVentas.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomReplicacion.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void RegistraTransferencia(int pintSocket,
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
SiscomAgregaOperacion(GeneraIdTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(GeneraFechaTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(Transferencia,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(EjecutaTransferenciaATienda,&lSiscomProDat);
SiscomAgregaOperacion(SqlDatosTiendaVenta,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaIdTransferenciaRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaTransferencias(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaTransferencias,&lSiscomProDat);
SiscomAgregaOperacion(EnviaTransferencias,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaContenidoTransferencia(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaInformacionTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(EnviaContenidoTransferenciaPrueba,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ActualizaEstadoTransferencia(int pintSocket,
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
SiscomAgregaOperacion(PreparaActualizacionTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaEstadoTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(EjecutaActEstadoATienda,&lSiscomProDat);
/*SiscomAgregaOperacion(EnviaIdTransferenciaActualizada,&lSiscomProDat); */
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RecibeTransferencia(int pintSocket,
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
SiscomAgregaOperacion(PreparaActualizacionTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(SqlRecibeTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdTransferenciaActualizada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RecibeTransferenciaParcial(int pintSocket,
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
SiscomAgregaOperacion(PreparaActualizacionTransferenciaParcial,&lSiscomProDat);
//SiscomAgregaOperacion(SqlRecibeTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdTransferenciaActualizada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void TransferenciasEnviadas(int pintSocket,
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
SiscomAgregaOperacion(SqlTransferenciasEnviadas,&lSiscomProDat);
SiscomAgregaOperacion(EnviaTransferencias,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void DetalleTransferencia(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaDetalleTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(EnviaTransferencias,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CostoPrecioTransferencia(int pintSocket,
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
SiscomAgregaOperacion(SqlCostoPrecioTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCostoPrecioTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviaIdTransferenciaRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
           *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[512];
const char *lchrPtrIdTransferencia,
       *lchrPtrFecha;
char lchrArrAnio[5],
    lchrArrMes[3],
    lchrArrDia[3];

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

lchrPtrIdTransferencia=SiscomCampoAsociadoEntradaOperacion("Envio",
                             "IdTransferencia",
                             pSiscomOpePtrDato);

lchrPtrFecha=SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato);
DatosFecha(lchrPtrFecha,lchrArrAnio,lchrArrMes,lchrArrDia);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
               &lSiscomRegProLPtrAct,
               lchrArrBuffer,
               "IdTransferencia,Mensajes,Fecha,Dia,Mes,Anio,Tienda,",
               lchrPtrIdTransferencia,
               "Registro Exitoso",
               lchrPtrFecha,
               lchrArrDia,
               lchrArrMes,
               lchrArrAnio,
	       (char *)0);
AgregandoTiendaVenta(lSiscomRegProLPtrPrim,pSiscomOpePtrDato); 
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
               lchrArrBuffer,
               lSiscomRegProLPtrPrim);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
/*
SiscomAsociadosArgumentoLog("SqlInsertaTransferencia",
                "SentenciasSql",
                lchrArrBuffer,
                pSiscomOpePtrDato);
	*/
}

int GeneraIdTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdTransferencia",pSiscomOpePtrDato);
}

int Transferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrTransferencia,
           *lSiscomRegProLPtrProductosPrim=0,
           *lSiscomRegProLPtrProductosAct=0;
char lchrArrBuffer[1024];

    lSiscomRegProLPtrTransferencia=SiscomRegistrosAsociadoEntradaOperacion("Envio",pSiscomOpePtrDato);
    SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrTransferencia);
    lSiscomRegProLPtrProductosPrim=SiscomObtenRegistrosCampoProL("Productos",lSiscomRegProLPtrTransferencia);
    SiscomAgregaArgumentoOperacion("ProductosTransferencia",
                   lSiscomRegProLPtrProductosPrim,
                   lSiscomRegProLPtrProductosAct,
                   pSiscomOpePtrDato);
    SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProductosPrim);
}

int GeneraFechaTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
    SiscomAsignaFechaHoraAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
}

int PreparaActualizacionTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
    SiscomAgregaCampoAsociadoEntrada("Fecha",
                "",
                "Envio",
                pSiscomOpePtrDato);
   SiscomAsignaFechaHoraAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
    
    /*SiscomAgregaCampoAsociadoEntrada("IdEstado","2","Envio",pSiscomOpePtrDato); */
}

int PreparaActualizacionTransferenciaParcial(SiscomOperaciones *pSiscomOpePtrDato)
{
    SiscomAgregaCampoAsociadoEntrada("Fecha",
                "",
                "Envio",
                pSiscomOpePtrDato);
    SiscomAsignaFechaAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
}
int SeTransfiereAPiso(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
const char *lchrPtrIdTipoTransferencia,
	   *lchrPtrTiendaATransferir;

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato); 

lchrPtrIdTipoTransferencia=SiscomCampoAsociadoEntradaOperacion("Envio",
								"IdTipoTransferencia",
								pSiscomOpePtrDato);
lchrPtrTiendaATransferir=SiscomCampoAsociadoEntradaOperacion("Envio",
								"IdTienda",
								pSiscomOpePtrDato);
LogSiscom("IdTipoTransferencia(%s) TiendaATransferir(%x)",
	lchrPtrIdTipoTransferencia,
	lchrPtrTiendaATransferir);
if(!lchrPtrTiendaATransferir)
return 1;
else 
return 0;

/*
return SiscomCampoAsociadoEntradaOperacionInt("Envio",
					      "IdTipoTransferencia",
					      pSiscomOpePtrDato);
*/
}
int EjecutaTransferenciaATienda(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
const char *lchrPtrIdTienda;

LogSiscom("------");

if(!SeTransfiereAPiso(pSiscomOpePtrDato))
{
lchrPtrIdTienda=SiscomCampoAsociadoEntradaOperacion("Envio",
				     "IdTienda",
				     pSiscomOpePtrDato);
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
LogSiscom("Transfiriendo a %s",lchrPtrIdTienda);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Servidores",gSiscomRegProLPtrMemoria);
SiscomReplicaMaquinaSistema(lchrPtrIdTienda,
			    "SqlInsertaTransferencia",
			    lchrArrBuffer,
			    gSiscomRegProLPtrMemoria,
			    0,
			    pSiscomOpePtrDato);
}
else
LogSiscom("La Transferencia es al Piso ");
}

int EjecutaActEstadoATienda(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
const char *lchrPtrIdTienda=SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDato);
LogSiscom("Transfiriendo a %s",lchrPtrIdTienda);
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

SiscomReplicaMaquinaSistema(lchrPtrIdTienda,
			    "SqlActualizaTransferencia",
			    lchrArrBuffer,
			    gSiscomRegProLPtrMemoria,
			    0,
			    pSiscomOpePtrDato);
}

int EnviaTransferencias(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Transferencias",pSiscomOpePtrDat))
    SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
               SiscomRegistrosCampoO("Transferencias",pSiscomOpePtrDat));

else
    RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

int EnviaContenidoTransferencia(SiscomOperaciones *pSiscomOpePtrDat)
{

}

int EnviaContenidoTransferenciaPrueba(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[256];
    SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}

int EnviaIdTransferenciaActualizada(SiscomOperaciones *pSiscomOpePtrDato)
{
/*
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
           *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[512];
const char *lchrPtrIdTransferencia,
       *lchrPtrFecha;
char lchrArrAnio[5],
    lchrArrMes[3],
    lchrArrDia[3];
LogSiscom("Se Recibe la transferencia");
LogSiscom("---------------");
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

lchrPtrIdTransferencia=SiscomCampoAsociadoEntradaOperacion("Envio",
                             "IdTransferencia",
                             pSiscomOpePtrDato);

lchrPtrFecha=SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato);
DatosFecha(lchrPtrFecha,lchrArrAnio,lchrArrMes,lchrArrDia);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
               &lSiscomRegProLPtrAct,
               lchrArrBuffer,
               "IdTransferencia,Mensajes,Fecha,Dia,Mes,Anio,",
               lchrPtrIdTransferencia,
               "Actualizacion Exitosa",
               lchrPtrFecha,
               lchrArrAnio,
               lchrArrMes,
               lchrArrDia);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
               lchrArrBuffer,
               lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
*/
char lchrArrBuffer[128];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
LogSiscom("Ahora actualizando el almacen central");
SqlActualizaAlmacenCentral(pSiscomOpePtrDato);
}
void FormaCondicionConsultaPrecioCosto(SiscomOperaciones *pSiscomOpePtrDato,
				       char **pchrPtrCondicion)
{
char lchrArrBuffer[128],
	lchrArrPaso[56];
int lintTamano;
SiscomRegistroProL *lSisRegProLPtrProductos;
lSisRegProLPtrProductos=SiscomRegistrosAsociadosCampoEntrada("Envio","Productos",pSiscomOpePtrDato);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrProductos);
sprintf(lchrArrPaso,"where a.idproducto in(");
*pchrPtrCondicion=strdup(lchrArrPaso);
while(lSisRegProLPtrProductos)
{
   if(lSisRegProLPtrProductos->SiscomRegProLPtrSig)
   sprintf(lchrArrPaso,"%s,",SiscomObtenCampoRegistroProLChar("idproducto",lSisRegProLPtrProductos));
   else
   sprintf(lchrArrPaso,"%s",SiscomObtenCampoRegistroProLChar("idproducto",lSisRegProLPtrProductos));
   lintTamano=strlen(*pchrPtrCondicion)+strlen(lchrArrPaso);
   *pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,lintTamano);
   strcat(*pchrPtrCondicion,lchrArrPaso);
   lSisRegProLPtrProductos=lSisRegProLPtrProductos->SiscomRegProLPtrSig;
}
 strcat(*pchrPtrCondicion,")");
}
void AsignaPrecioCostoProducto(SiscomOperaciones *pSiscomOpePtrDato,
			       SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
SiscomRegistroProL *lSiscomRegProLPtrCostoPrecio;
float lfltImporte;
lSiscomRegProLPtrCostoPrecio=SiscomRegistrosAsociadoRespuestaOperacion("SqlCostoPrecioTransferencia",
									pSiscomOpePtrDato);
for(;lSiscomRegProLPtrCostoPrecio;
     lSiscomRegProLPtrCostoPrecio=lSiscomRegProLPtrCostoPrecio->SiscomRegProLPtrSig)
{
   if(!SiscomComparaCampoRegistrosProL("idproducto",
   				      lSiscomRegProLPtrCostoPrecio,
				      pSiscomRegProLPtrProducto))
   {
      lfltImporte=SiscomObtenCampoRegistroProLFloat("preciogeneral",lSiscomRegProLPtrCostoPrecio)*
      		  SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrProducto);
      SiscomActualizaCampoRegistro(
      			"Precio",
      			(char *)SiscomObtenCampoRegistroProLChar("preciogeneral", lSiscomRegProLPtrCostoPrecio),
			pSiscomRegProLPtrProducto);
      SiscomActualizaCampoRegistro(
      			"Costo",
      			(char *)SiscomObtenCampoRegistroProLChar("costobruto",lSiscomRegProLPtrCostoPrecio),
				    pSiscomRegProLPtrProducto);
     SiscomActualizaCampoFloatRegistroActual("Importe","%.2f",lfltImporte,pSiscomRegProLPtrProducto);
     break;
   }
}
}
int EnviaCostoPrecioTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[252];
SiscomRegistroProL *lSiscomRegProLPtrCostoPrecio,
		   *lSiscomRegProLPtrProductos,
		   *lSiscomRegProLPtrProductosPaso;
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
lSiscomRegProLPtrProductosPaso=lSiscomRegProLPtrProductos=SiscomRegistrosAsociadosCampoEntrada("Envio",
								"Productos",
								pSiscomOpePtrDato);
for(;lSiscomRegProLPtrProductos;
     lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
  AsignaPrecioCostoProducto(pSiscomOpePtrDato,lSiscomRegProLPtrProductos);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProductosPaso);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   pSiscomOpePtrDato->SiscomRegProLPtrPrimEnt);
}

