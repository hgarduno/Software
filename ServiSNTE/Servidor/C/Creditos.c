#include <Creditos.h>
#include <SqlCreditos.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void CreditosCliente(int pintSocket,
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
SiscomAgregaOperacion(SqlCreditosCliente,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCreditosCliente,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void AbonoACredito(int pintSocket,
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
SiscomAgregaOperacion(SqlAbonoACredito,&lSiscomProDat);
SiscomAgregaOperacion(EstadoAbonoACredito,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
/*
int AgregaCampoFecha(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrFecha[20];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomAgregaCampoAsociadoEntrada("Fecha",
				lchrArrFecha,
				"Envio",
				pSiscomOpePtrDato);
}
*/
int EnviaCreditosCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
if(SiscomObtenRegistrosCampoRespuesta("Persona",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
                           lchrArrBuffer,
			   pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
else
RespondeConsultaSinRegistros(pSiscomOpePtrDato);
}


int EstadoAbonoACredito(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
LogSiscom("_------_");
}
