#include <Departamentos.h>
#include <SqlDepartamentos.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void RegistraDepartamento(int pintSocket,
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
SiscomAgregaOperacion(GeneraIdDepartamento,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraDepartamento,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdDepartamentoRegistrado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int GeneraIdDepartamento(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
  SiscomIdARegistrosAsociadosEntrada("Envio","IdDepartamento",pSiscomOpePtrDato);
LogSiscom("");
}

int EnviaIdDepartamentoRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrIdDepartamento;
lchrPtrIdDepartamento=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdDepartamento",
						     pSiscomOpePtrDato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdDepartamento,Mensajes,",
		       lchrPtrIdDepartamento,
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomAsociadosArgumentoLog("SqlInsertaDepartamento",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
}
