#include <RegistraUsuario.h>
#include <SqlRegistraUsuario.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <Facturando4.h>
#include <Clientes4.h>

#include <string.h>

void RegistraUsuarioSiscom(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoSiscomSeguridad3,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdPersonaCliente,&lSiscomProDat);
SiscomAgregaOperacion(SqlExpendiosSiscomElectronica,&lSiscomProDat);  
SiscomAgregaOperacion(EnviandoRegistroSeguridad3,&lSiscomProDat); 
SiscomAgregaOperacion(SqlRegistraUsuarioSiscom,&lSiscomProDat); 
SiscomAgregaOperacion(RegistrandoUsuarioSiscom,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int RegistrandoUsuarioSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
  SiscomAsociadosArgumentoLog("SqlCliente","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

int EnviandoRegistroSeguridad3(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
char *lchrPtrIdPerfil;
SiscomOperaciones lSisOpeDatos;
lSisOpeDatos=*pSiscomOpePtrDato;
strcpy(lSisOpeDatos.chrArrBaseDatos,"Seguridad3");
SqlDatosAplicacion(&lSisOpeDatos);
lchrPtrIdPerfil=(char *)SiscomCampoAsociadoRespuestaOperacion("Perfil","idperfil",&lSisOpeDatos);
SqlRegistraSeguridad3(&lSisOpeDatos);
/*
SiscomAsociadosArgumentoLog("SqlSeguridad3","SentenciasSql",lchrArrBuffer,&lSisOpeDatos);
SiscomAsociadoRespuestaLog("Servidores",lchrArrBuffer,&lSisOpeDatos);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisOpeDatos.SiscomRegProLPtrPrimRes);
*/
SiscomActualizaCampoAsociadoEntrada("Envio","TipoPersona",lchrPtrIdPerfil,pSiscomOpePtrDato);
return 0;
}
int ArgumentoSiscomSeguridad3(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];

SiscomAgregaArgumentoInsercionSql("SqlSeguridad3",
				  "Seguridad3",
				  0,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
