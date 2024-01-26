#include <ContratosBeneficios.h>
#include <SqlContratosBeneficios.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomReplicacion.h>
#include <string.h>
#include <stdio.h>

void CreditosBeneficiosIntegrales(int pintSocket,
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
SiscomAgregaOperacion(SqlCreditosBeneficiosIntegrales,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCreditosBeneficiosIntegrales,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



void RegistraContratoBeneficios(int pintSocket,
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
SiscomAgregaOperacion(GeneraIdContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(GeneraFechaContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(ContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(EjecutaContratoBeneficiosATienda,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdContratoBeneficiosRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaContratosBeneficios(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaContratosBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(EnviaContratosBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaContenidoContratoBeneficios(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaInformacionContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(EnviaContenidoContratoBeneficiosPrueba,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ActualizaEstadoContratoBeneficios(int pintSocket,
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
SiscomAgregaOperacion(PreparaActualizacionContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaEstadoContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdContratoBeneficiosActualizada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RecibeContratoBeneficios(int pintSocket,
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
SiscomAgregaOperacion(PreparaActualizacionContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(SqlRecibeContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdContratoBeneficiosActualizada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RecibeContratoBeneficiosParcial(int pintSocket,
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
SiscomAgregaOperacion(PreparaActualizacionContratoBeneficiosParcial,&lSiscomProDat);
//SiscomAgregaOperacion(SqlRecibeContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdContratoBeneficiosActualizada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaContratoBeneficios(int pintSocket,
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
SiscomAgregaOperacion(SqlInformacionContratoBeneficiosIntegrales,&lSiscomProDat);
SiscomAgregaOperacion(EnviaContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);


}


int EnviaIdContratoBeneficiosRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
           *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[512];
const char *lchrPtrIdContratoBeneficios,
       *lchrPtrFecha;
char lchrArrAnio[5],
    lchrArrMes[3],
    lchrArrDia[3];

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

lchrPtrIdContratoBeneficios=SiscomCampoAsociadoEntradaOperacion("Envio",
                             "IdContratoBeneficios",
                             pSiscomOpePtrDato);

lchrPtrFecha=SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato);
DatosFecha(lchrPtrFecha,lchrArrAnio,lchrArrMes,lchrArrDia);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
               &lSiscomRegProLPtrAct,
               lchrArrBuffer,
               "IdContratoBeneficios,Mensajes,Fecha,Dia,Mes,Anio,",
               lchrPtrIdContratoBeneficios,
               "Registro Exitoso",
               lchrPtrFecha,
               lchrArrAnio,
               lchrArrMes,
               lchrArrDia);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
               lchrArrBuffer,
               lSiscomRegProLPtrPrim);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);

SiscomAsociadosArgumentoLog("SqlInsertaContratoBeneficios",
                "SentenciasSql",
                lchrArrBuffer,
                pSiscomOpePtrDato);
}

int GeneraIdContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdContratoBeneficios",pSiscomOpePtrDato);
}

int ContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato)
{
    LogSiscom("");
    SiscomRegistroProL *lSiscomRegProLPtrContratoBeneficios,
           *lSiscomRegProLPtrProductosPrim=0,
           *lSiscomRegProLPtrProductosAct=0;
    char lchrArrBuffer[256];
    lSiscomRegProLPtrContratoBeneficios=SiscomRegistrosAsociadoEntradaOperacion("Envio",
                                pSiscomOpePtrDato);

    SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrContratoBeneficios);

    lSiscomRegProLPtrProductosPrim=SiscomObtenRegistrosCampoProL("Productos",lSiscomRegProLPtrContratoBeneficios);

    SiscomAgregaArgumentoOperacion("ProductosContratoBeneficios",
                   lSiscomRegProLPtrProductosPrim,
                   lSiscomRegProLPtrProductosAct,
                   pSiscomOpePtrDato);

    SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProductosPrim);
}

int GeneraFechaContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato)
{
    SiscomAsignaFechaAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
}

int PreparaActualizacionContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato)
{
    SiscomAgregaCampoAsociadoEntrada("Fecha",
                "",
                "Envio",
                pSiscomOpePtrDato);
    SiscomAsignaFechaAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
}

int PreparaActualizacionContratoBeneficiosParcial(SiscomOperaciones *pSiscomOpePtrDato)
{
    SiscomAgregaCampoAsociadoEntrada("Fecha",
                "",
                "Envio",
                pSiscomOpePtrDato);
    SiscomAsignaFechaAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
    
}

int EjecutaContratoBeneficiosATienda(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
const char *lchrPtrIdTienda=SiscomCampoAsociadoEntradaOperacion(
						"Envio",
						"IdTienda",
						pSiscomOpePtrDato);
LogSiscom("Transfiriendo a %s",lchrPtrIdTienda);
SiscomReplicaMaquinaSistema(lchrPtrIdTienda,
			    "SqlInsertaContratoBeneficios",
			    lchrArrBuffer,
			    gSiscomRegProLPtrMemoria,
			    0,
			    pSiscomOpePtrDato);
}

int EnviaContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("ContratosBeneficios",pSiscomOpePtrDat))
    SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
               SiscomRegistrosCampoO("ContratosBeneficios",pSiscomOpePtrDat));

else
    RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

int EnviaContenidoContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat)
{

}

int EnviaContenidoContratoBeneficiosPrueba(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[256];
    SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}

int EnviaIdContratoBeneficiosActualizada(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
           *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[512];
const char *lchrPtrIdContratoBeneficios,
       *lchrPtrFecha;
char lchrArrAnio[5],
    lchrArrMes[3],
    lchrArrDia[3];

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

lchrPtrIdContratoBeneficios=SiscomCampoAsociadoEntradaOperacion("Envio",
                             "IdContratoBeneficios",
                             pSiscomOpePtrDato);

lchrPtrFecha=SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato);
DatosFecha(lchrPtrFecha,lchrArrAnio,lchrArrMes,lchrArrDia);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
               &lSiscomRegProLPtrAct,
               lchrArrBuffer,
               "IdContratoBeneficios,Mensajes,Fecha,Dia,Mes,Anio,",
               lchrPtrIdContratoBeneficios,
               "Actualizacion Exitosa",
               lchrPtrFecha,
               lchrArrAnio,
               lchrArrMes,
               lchrArrDia);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
               lchrArrBuffer,
               lSiscomRegProLPtrPrim);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
}

int EnviaContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDat);
SiscomAsociadoRespuestaLog("GeneralesContrato",lchrArrBuffer,pSiscomOpePtrDat);
SiscomAsociadoRespuestaLog("DatosCasa",lchrArrBuffer,pSiscomOpePtrDat);
SiscomAsociadoRespuestaLog("DatosNacimiento",lchrArrBuffer,pSiscomOpePtrDat);
SiscomAsociadoRespuestaLog("Identificacion",lchrArrBuffer,pSiscomOpePtrDat);
SiscomAsociadoRespuestaLog("TelefonosCliente",lchrArrBuffer,pSiscomOpePtrDat);
SiscomAsociadoRespuestaLog("CorreosCliente",lchrArrBuffer,pSiscomOpePtrDat);
SiscomAsociadoRespuestaLog("Empleo",lchrArrBuffer,pSiscomOpePtrDat);
SiscomAsociadoRespuestaLog("ReferenciasPersonales",lchrArrBuffer,pSiscomOpePtrDat);
SiscomAsociadoRespuestaLog("CentroTrabajo",lchrArrBuffer,pSiscomOpePtrDat);

SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);

}


int EnviaCreditosBeneficiosIntegrales(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
SiscomAsociadoRespuestaLog("CreditosBeneficios",lchrArrBuffer,pSiscomOpePtrDat);
}
