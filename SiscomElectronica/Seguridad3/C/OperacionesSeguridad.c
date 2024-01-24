#include <OperacionesSeguridad.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>
#include <unistd.h>
int Conectate(StcSiscomOpciones *pStcPtrSisOpciones,
	      const char *pchrPtrModulo,
	      const char *pchrPtrFuncion)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrEnvio=0;
char *lchrPtrEdoConexion;
int lintSocket;

if((lintSocket=SiscomConectateCliente(SiscomOpcionAChar("DirIp",pStcPtrSisOpciones),
				      SiscomOpcionAInt("Puerto",pStcPtrSisOpciones),
				      &lchrPtrEdoConexion))>0)
{
LogSiscom("Se Conecto al servidor %s:%d (%d)(%s)",
	    SiscomOpcionAChar("DirIp",pStcPtrSisOpciones),
	    SiscomOpcionAInt("Puerto",pStcPtrSisOpciones),
	   lintSocket,
	   lchrPtrEdoConexion ? lchrPtrEdoConexion:"");
ComunicacionServidor(pchrPtrModulo,pchrPtrFuncion,&lSisRegProLPtrEnvio);
RegistroUsuario(pStcPtrSisOpciones,lSisRegProLPtrEnvio);
EnviaVersionProtocolo(lintSocket);
SiscomEnviaRegistroSocket(lintSocket,lchrArrBuffer,lSisRegProLPtrEnvio);
return lintSocket;
}


}
void EnviaVersionProtocolo(int pintSocket)
{
char lchrArrCadena[16];
sprintf(lchrArrCadena,"%05d%05d%05d",4,0,0);
write(pintSocket,lchrArrCadena,15);
}
void ComunicacionServidor(const char *pchrPtrModulo,
		          const char *pchrPtrFuncion,
			  SiscomRegistroProL **pSisRegProLPtrRegreso)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrAct=0,
		   *lSisRegProLPtrModuloPrim=0,
		   *lSisRegProLPtrModuloAct=0;


SiscomAnexaRegistroPro(pSisRegProLPtrRegreso,
		       &lSisRegProLPtrAct,
		       lchrArrBuffer,
		       "ModuloServidor,"
		       "Configuracion,"
		       "Envio,",
		       (const char *)0,
		       (const char *)0,
		       (const char *)0);
ModuloServidor(pchrPtrModulo,pchrPtrFuncion,&lSisRegProLPtrModuloPrim,&lSisRegProLPtrModuloAct);
SiscomRegistrosAlCampo("ModuloServidor",
			    lSisRegProLPtrModuloPrim,
			    lSisRegProLPtrModuloAct,
			    lSisRegProLPtrAct);

}
void ModuloServidor(const char *pchrPtrModulo,
		   const char *pchrPtrFuncion,
		   SiscomRegistroProL **pSisRegProLPtrModuloPrim,
		   SiscomRegistroProL **pSisRegProLPtrModuloAct)
{
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(pSisRegProLPtrModuloPrim,
		       pSisRegProLPtrModuloAct,
		       lchrArrBuffer,
		       "Modulo,"
		       "Funcion,",
		       pchrPtrModulo,
		       pchrPtrFuncion);
}

void RegistroUsuario(StcSiscomOpciones *pStcPtrSisOpciones,
		     SiscomRegistroProL *pSisRegProLPtrEnvio)
{
char lchrArrBuffer[512];
SiscomRegistroProL *lSisRegProLPtrAct=0,
		   *lSisRegProLPtrPrim=0;

SiscomAnexaRegistroPro(&lSisRegProLPtrPrim,
		       &lSisRegProLPtrAct,
		       lchrArrBuffer,
		       "Firma,"
		       "Password,"
		       "Nombre,"
		       "APaterno,"
		       "AMaterno,"
		       "IdPersona,"
		       "TipoPersona,"
		       "RFC,"
		       "Perfil,"
		       "Aplicacion,"
		       "IdExpendio,",
		       SiscomOpcionAChar("Firma",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Password",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Nombre",pStcPtrSisOpciones),
		       SiscomOpcionAChar("APaterno",pStcPtrSisOpciones),
		       SiscomOpcionAChar("AMaterno",pStcPtrSisOpciones),
		       "",
		       "",
		       "RFC",
		       SiscomOpcionAChar("Perfil",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Aplicacion",pStcPtrSisOpciones),
		       SiscomOpcionAChar("IdExpendio",pStcPtrSisOpciones));
SiscomRegistrosAlCampo("Envio",lSisRegProLPtrPrim,lSisRegProLPtrAct,pSisRegProLPtrEnvio);
}
