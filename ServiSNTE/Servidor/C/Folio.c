#include <Folio.h>

#include <SqlFolio.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomOperaciones.h>

#include <string.h>

void RegistraFolio(int pintSocket,
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
SiscomAgregaOperacion(GeneraIdFolio,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraFolio,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdFolioRegistrado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}

void FolioActual(int pintSocket,
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
SiscomAgregaOperacion(SqlFolioActual,&lSiscomProDat);
SiscomAgregaOperacion(EnviaFolioActual,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaIdFolioRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("Registrando el folio");

}
int GeneraIdFolio(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdFolio",pSiscomOpePtrDato);
}
void RegresaFolio(int pintSocket,
		  const char *pchrPtrCampo,
		  SiscomRegistroProL *pSiscomRegProLPtrRegreso)
{
char lchrArrBuffer[128];
const char *lchrPtrFolioActual;
SiscomRegistroProL *lSiscomRegProLPtrRegPrim=0,
  		   *lSiscomRegProLPtrRegAct=0;
                  	 

lchrPtrFolioActual=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,
				pSiscomRegProLPtrRegreso);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrRegPrim,
		       &lSiscomRegProLPtrRegAct,
		       lchrArrBuffer,
		       "FolioActual,",
		       lchrPtrFolioActual);
SiscomEnviaRegistrosSocket(pintSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrRegPrim);


}
void RegresaFolioActual(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrRegreso)
{
RegresaFolio(pintSocket,"folio",pSiscomRegProLPtrRegreso);
}
void RegresaFolioActualInicio(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrRegreso)
{
RegresaFolio(pintSocket,
	     "inicio",
	     pSiscomRegProLPtrRegreso);
}
int EnviaFolioActual(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrFolioActual;
if((lSiscomRegProLPtrFolioActual=SiscomRegistrosAsociadoRespuestaOperacion(
					"FolioActual",
					pSiscomOpePtrDato)))
  RegresaFolioActual(pSiscomOpePtrDato->intSocket,
  		     lSiscomRegProLPtrFolioActual);
else
{
LogSiscom("No hay informacion folio actual");
if((lSiscomRegProLPtrFolioActual=SiscomRegistrosAsociadoRespuestaOperacion(
					"FolioTienda",
					pSiscomOpePtrDato)))
 RegresaFolioActualInicio(pSiscomOpePtrDato->intSocket,
 			  lSiscomRegProLPtrFolioActual);
else
LogSiscom("MMMM tampoco hay registro de inicio");


}
}
