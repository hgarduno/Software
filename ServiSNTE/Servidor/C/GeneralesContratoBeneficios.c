#include <GeneralesContratoBeneficios.h>
#include <ComunSiscomServiSNTE.h>
#include <SqlGeneralesContratoBeneficios.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>

#include <string.h>
void RegistraGeneralesContratoBeneficios(int pintSocket,
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
SiscomAgregaOperacion(SqlInsertaGeneralesContratoBeneficios,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaEstadoRegistroGeneralesContratoBeneficios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviaEstadoRegistroGeneralesContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
if(ValidaEstadoRegistroGeneralesContratoBeneficios(pSiscomOpePtrDato))
RespondeRegistroExitoso(pSiscomOpePtrDato);

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlGeneralesContratoBeneficios","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDato); 
return 0;
}

int ValidaEstadoRegistroGeneralesContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato)
{

return 1;
}
