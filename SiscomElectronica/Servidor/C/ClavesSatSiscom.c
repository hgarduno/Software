#include <ClavesSatSiscom.h>
#include <SqlClavesSatSiscom.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <ComunSiscomElectronica4.h>
#include <SiscomInsercionesSql.h>
#include <string.h>
#include <stdarg.h>

void RegistraClaveSat(int pintSocket,
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
SiscomAgregaOperacion(GeneraIdClaveSat,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoRegistroClaveSat,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraClaveSatSiscom,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoClaveSat,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void ClaveSat(int pintSocket,
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
SiscomAgregaOperacion(SqlClaveSat,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoClaveSat,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



int RegistrandoClaveSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("Registrando La Clave Sat");
SiscomAsociadosArgumentoLog("SqlClaveSat",
                            "SentenciasSql",
                            lchrArrBuffer,
                            pSiscomOpePtrDato);
}



int EnviandoClaveSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
if(SiscomRegistrosAsociadoRespuestaOperacion("ClaveSat",pSiscomOpePtrDato))
SiscomEnviaAsociadoRespuestaCliente("ClaveSat",
                                    lchrArrBuffer,
                                    pSiscomOpePtrDato);
else
{
pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
pSiscomOpePtrDato->SiscomRegProLPtrActRes=0;
SiscomFormaEnviaRegistroRespuesta(pSiscomOpePtrDato,
                                 lchrArrBuffer,
                                 "Estado,Descripcion"
                                 "0",
				 "NO Hay Clave del Sat");
}
return 0;
}
int GeneraIdClaveSat(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","Id",pSiscomOpePtrDato);
return 0;
}
int ArgumentoRegistroClaveSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlClaveSat",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
