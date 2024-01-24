#include <Practicas.h>
#include <SqlPracticas.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>

void RegistraPractica(int pintSocket,
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
SiscomAgregaOperacion(AgregaIdProducto,&lSiscomProDat);
SiscomAgregaOperacion(AgregaArgumentoPracticas,&lSiscomProDat);
SiscomAgregaOperacion(SqlPractica,&lSiscomProDat); 
SiscomAgregaOperacion(SqlProductoPorTipoProductoPractica,&lSiscomProDat); 
SiscomAgregaOperacion(EnviandoRegistroPractica,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PracticaRegistrada(int pintSocket,
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
SiscomAgregaOperacion(SqlPracticaRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPracticaRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviandoRegistroPractica(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlPractica",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
return 0;
}
int AgregaIdProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
 SiscomAgregaCampoAsociadoEntrada("IdProducto",0,"Envio",pSiscomOpePtrDato);
 SiscomIdARegistrosAsociadosEntrada("Envio","IdProducto",pSiscomOpePtrDato);
 return 0;
}
int AgregaArgumentoPracticas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlPractica",
				   pSiscomOpePtrDato->chrArrBaseDatos,
				   pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				   lchrArrBuffer,
				   pSiscomOpePtrDato);
return 0;
}

int EnviaPracticaRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("");
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("DefProducto",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("Practica",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("Profesor",lchrArrBuffer,pSiscomOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
return 0;
}
