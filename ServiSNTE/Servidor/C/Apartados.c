#include <Apartados.h>
#include <SqlApartados.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomFuncionesComunes.h>
#include <string.h>

void ApartadosCliente(int pintSocket,
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
SiscomAgregaOperacion(SqlApartadosCliente,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaRespuestaApartadosCliente,&lSiscomProDat);
SiscomAgregaOperacion(EnviaApartadosCliente,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CancelaApartado(int pintSocket,
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
SiscomAgregaOperacion(SqlCancelaApartado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void AbonoAApartado(int pintSocket,
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
SiscomAgregaOperacion(AgregaCampoFecha,&lSiscomProDat);
SiscomAgregaOperacion(SqlAbonoAApartado,&lSiscomProDat);
SiscomAgregaOperacion(EstadoAbonoAApartado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CancelaAApartado(int pintSocket,
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
SiscomAgregaOperacion(SqlCancelaAApartado,&lSiscomProDat);
SiscomAgregaOperacion(EstadoAbonoAApartado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaAbonosVenta(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaAbonos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaAbonosVenta,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int AgregaCampoFecha(SiscomOperaciones *pSiscomOpePtrDato)
{
    char lchrArrFecha[20];
    SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
    SiscomAgregaCampoAsociadoEntrada("Fecha",
				lchrArrFecha,
				"Envio",
				pSiscomOpePtrDato);
}

int AgregaFechaRespuestaApartadosCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrFecha[20];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomAgregaCampoRegistro("FechaHoy",
			   lchrArrFecha,
			   pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
}
int EnviaApartadosCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
SiscomRegistroProL *lSiscomRegProLPersona,
		   *lSiscomRegProLApartados;
    lSiscomRegProLPersona=SiscomObtenRegistrosCampoRespuesta("Persona",pSiscomOpePtrDato);
    lSiscomRegProLApartados=SiscomObtenRegistrosCampoRespuesta("Apartados",pSiscomOpePtrDato);
    if(SiscomObtenRegistrosCampoRespuesta("Tienda",pSiscomOpePtrDato))
    {
    if(lSiscomRegProLPersona && lSiscomRegProLApartados)
        SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
                           lchrArrBuffer,
			               pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
    else
        RespondeConsultaSinRegistros(pSiscomOpePtrDato);
    }
    else
	MSGAviso("1","No Se encontro una entrada en la tabla Tienda",pSiscomOpePtrDato);
}

int EnviaAbonosVenta(SiscomOperaciones *pSiscomOpePtrDato)
{
    char lchrArrBuffer[1024];
    if(SiscomObtenRegistrosCampoRespuesta("Abonos",pSiscomOpePtrDato))
    SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
                           lchrArrBuffer,
               SiscomRegistrosCampoO("Abonos",pSiscomOpePtrDato));
    else
        RespondeConsultaSinRegistros(pSiscomOpePtrDato);
}

int EstadoAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDato)
{
    char lchrArrBuffer[1024];
    LogSiscom("_------_");
}

