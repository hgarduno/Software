#include <CargoPublico.h>
#include <ComunSiscomServiSNTE.h>
#include <SqlCargoPublico.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>

#include <string.h>
void RegistraCargoPublico(int pintSocket,
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
SiscomAgregaOperacion(AgregaIdCargoPublico,&lSiscomProDat);
SiscomAgregaOperacion(SqlInsertaCargoPublico,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaEstadoRegistroCargoPublico,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviaEstadoRegistroCargoPublico(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
if(ValidaEstadoRegistroCargoPublico(pSiscomOpePtrDato))
RespondeRegistroExitoso(pSiscomOpePtrDato);


SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlCargoPublico","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDato); 
return 0;
}

int AgregaIdCargoPublico(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdCargoPublico",pSiscomOpePtrDato);
return 0;
}
int ValidaEstadoRegistroCargoPublico(SiscomOperaciones *pSiscomOpePtrDato)
{

return 1;
}
