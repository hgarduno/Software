#include <ClavesProveedor.h>
#include <SqlClavesProveedor.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>

void ValidaClaveRegistrada(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoClavesProveedor,&lSiscomProDat);
SiscomAgregaOperacion(SqlConsultaClaveProveedor,&lSiscomProDat);
SiscomAgregaOperacion(ValidandoClaveRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RegistraClavesProveedor(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoClavesProveedor,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraClavesProveedor,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoClavesProveedor,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ActualizaClaveProveedor(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoClavesProveedor,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaClaveProveedor,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoClavesProveedor,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int EnviandoClavesProveedor(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}
void FormaRegistroRespuesta(SiscomRegistroProL *pSisRegProLPtrProducto,
			    SiscomRegistroProL **pSisRegProLPtrRegPrim,
			    SiscomRegistroProL **pSisRegProLPtrRegAct)
{
char lchrArrBuffer[256];

SiscomAnexaRegistroPro(pSisRegProLPtrRegPrim,
		       pSisRegProLPtrRegAct,
		       lchrArrBuffer,
		       "EdoConsulta,ClaveProveedor,",
		       pSisRegProLPtrProducto ? "1" : "0",
		       (char *)0);
if(pSisRegProLPtrProducto)
SiscomRegistrosAlCampo("ClaveProveedor",
			pSisRegProLPtrProducto,
			pSisRegProLPtrProducto,
			*pSisRegProLPtrRegPrim);
}
int ValidandoClaveRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrProducto,
		   *lSisRegProLPtrRegPrim=0,
		   *lSisRegProLPtrRegAct=0;
lSisRegProLPtrProducto=SiscomObtenRegistrosCampoRespuesta("ClaveProveedor",pSiscomOpePtrDato);
FormaRegistroRespuesta(lSisRegProLPtrProducto,&lSisRegProLPtrRegPrim,&lSisRegProLPtrRegAct);
/* Se deberia realizar una funcion en Siscom Operaciones 
 * que tome un SiscomRegistroProL y lo envie al cliente
 * SiscomEnviaCliente(SiscomOperaciones *,char *pchrPtrBuffer,SiscomRegistroProL *);
 */
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,lchrArrBuffer,lSisRegProLPtrRegPrim);
return 0;
}


int ArgumentoClavesProveedor(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlClavesProveedor",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}
