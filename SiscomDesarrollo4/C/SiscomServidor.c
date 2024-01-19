/* Lunes 23 de abril del 2012
 * Se inicia la programacion de la nueva version del modelo
 * SiscomDesarrollo 
 * Programando todo desde cero
 */

#include <SiscomServidor.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomArchivosIni.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <dlfcn.h>
#include <unistd.h>

FILE *gPtrFleArchivoLog;
SiscomError gSiscomErrorSistema;
SiscomDatosIni gSiscomDatIni;
void *gvidPtrAncla;
SiscomOpGestionEstatica *gSiscomOpGesEstDat;
/* Lunes 22 de diciembre del 2014
 * Espacio de memoria que inicia el demonio
 */
SiscomRegistroProL *gSiscomRegProLPtrMemoria;

int gintSocketProtocoloLog;
int gintPidServidor;
int main(int pintArgc,
	  char **pchrPtrArgv)
{
gvidPtrAncla=0;
gSiscomRegProLPtrMemoria=0;
gPtrFleArchivoLog=stdout;
CargaArchivoIni(pchrPtrArgv);
AbreArchivoLog();
AlmacenaPidServidor();
CargandoMemoria();
CargaFuncionesGestionEstatica();
/*ManejadorSenales(); */
SiscomServidorComunicaciones(SiscomVariableIniAInt("Puerto",&gSiscomDatIni));
LogSiscom("Termino algo");
}
void ManejadorSenales()
{
 signal(SIGSEGV,SiscomSIGSEGV);
}
void AbreArchivoLog()
{
char lchrArrNmbArchivo[512];
const char *lchrPtrDirectorioConfiguracion;
if((lchrPtrDirectorioConfiguracion=getenv("DirectorioConfiguracion")))
{

 sprintf(lchrArrNmbArchivo,
 	 "%s/LOGs/ServidorSiscom%dLog",
	 lchrPtrDirectorioConfiguracion,
 	 SiscomVariableIniAInt("Puerto",&gSiscomDatIni)); 	
 if(gPtrFleArchivoLog=fopen(lchrArrNmbArchivo,"a+"))
   LogSiscom("Archivo Log %s",lchrArrNmbArchivo);
 else
 {
    gPtrFleArchivoLog=stdout;
    LogSiscom("Error Al crear El Log:%s",lchrArrNmbArchivo);
    exit(0);
 }

}
else
{
LogSiscom("El script de inicio requerie contar con la variable DirectorioConfiguracion");
exit(1);
}
}
void AsignaMemoriaFuncionesGestionEstatica(int pintNFunciones)
{
int lintTamano;
lintTamano=sizeof(SiscomOpGestionEstatica)*(pintNFunciones+1);
gSiscomOpGesEstDat=(SiscomOpGestionEstatica *)malloc(lintTamano);
memset(gSiscomOpGesEstDat,0,lintTamano);
}
void CargaFuncionGestionEstatica(void *pvidPtrAncla,
				 const SiscomVariableIni *pSiscomVarIniPtrDat,
				 SiscomOpGestionEstatica *pSiscomOpGesEstPtrDat)
{
 if(!(pSiscomOpGesEstPtrDat->gSiscomGestionEstatica=(SiscomGestionEstatica )dlsym(pvidPtrAncla,pSiscomVarIniPtrDat->chrArrDato)))
 {
   LogSiscom("No se encontro %s (%s)",
	      pSiscomVarIniPtrDat->chrArrDato,
	      dlerror());
 }
 else
  strcpy(pSiscomOpGesEstPtrDat->chrArrOperacion,pSiscomVarIniPtrDat->chrArrNombre);
}
void FuncionesGestionEstatica(void *pvidPtrAncla)
{
SiscomVariableIniArregloL *lSiscomVarIniArrLPtrDat;
SiscomVariablesIniL *lSiscomVarIniPtrDat;
int lintContador=0;
if(SiscomObtenInformacionVariableArreglo("FuncionGestionEstatica",
					 &gSiscomDatIni,
					 &lSiscomVarIniArrLPtrDat))
{
LogSiscom("Cargando la funciones de gestion estatica:%d",
	  lSiscomVarIniArrLPtrDat->intNDatosArreglo);
AsignaMemoriaFuncionesGestionEstatica(lSiscomVarIniArrLPtrDat->intNDatosArreglo);
lSiscomVarIniPtrDat=lSiscomVarIniArrLPtrDat->SiscomVILPtrDatos;
 while(lSiscomVarIniPtrDat)
 {
   CargaFuncionGestionEstatica(pvidPtrAncla,
   			       &lSiscomVarIniPtrDat->SiscomVIni,
			       (gSiscomOpGesEstDat+lintContador));
   lintContador++;
   lSiscomVarIniPtrDat=(void *)lSiscomVarIniPtrDat->SiscomVIniLPtrSig;
 }
}

}
void CargaFuncionesGestionEstatica()
{
char lchrArrDato[28];
  if(ModoOperacionGestionEstatica())
  {
    LogSiscom("Cargando ...");
    SiscomVariableIniAChar("ModuloSistema",&gSiscomDatIni,lchrArrDato);
     if((gvidPtrAncla=dlopen(lchrArrDato,RTLD_LAZY)))
        FuncionesGestionEstatica(gvidPtrAncla); 
     else
     LogSiscom("dlopen(%s)",dlerror());
  }
}
int ModoOperacionGestionEstatica()
{
 return SiscomVariableIniAInt("GestionEstatica",&gSiscomDatIni);
}
int CargaArchivoIni(char **pchrPtrArgv)
{
   SiscomAnalizaArchivoIni(pchrPtrArgv[1],&gSiscomDatIni);
   gintSocketProtocoloLog=SiscomObtenVariableArregloIniAInt(
   				"LogServidor",
				"SocketProtocolo",
				&gSiscomDatIni);
}

int SiscomServidorComunicaciones(int pintPtoCom)
{
int lintSocket;
int lintSocketCliente;
int lintPidServidor;
char lchrArrDirIpCliente[25];
  if((lintSocket=SiscomIniciaSocketComunicaciones(pintPtoCom))<0)
  {
     LogSiscom("No se ha podido iniciar el servidor");
     exit(10);
  }
  else
  {
      signal(SIGCHLD,SIG_IGN);
      if(!(gintPidServidor=lintPidServidor=fork()))
	while(1)
	{
	    if((lintSocketCliente=SiscomEsperaConexionServidor(
	    				lintSocket,
	    				lchrArrDirIpCliente))>0)
	    AtiendeCliente(lintSocketCliente,lchrArrDirIpCliente);
	    close(lintSocketCliente);
      }
      else
      {
      LogSiscom("Iniciando el servidor Siscom:%d",lintPidServidor);
      AlmacenaPidServidor();
      close(lintSocket);
      close(lintSocketCliente);
      }
  }
}
void AlmacenaPidServidor()
{
FILE *lFlePtrArchivo;
char lchrArrArchivo[256];
const char *lchrPtrDirectorioConfiguracion;
if((lchrPtrDirectorioConfiguracion=getenv("DirectorioConfiguracion")))
{
sprintf(lchrArrArchivo,
	"%s/PIDs/ServidorSiscom%dPid",
	lchrPtrDirectorioConfiguracion,
	SiscomVariableIniAInt("Puerto",&gSiscomDatIni));
if((lFlePtrArchivo=fopen(lchrArrArchivo,"w")))
{
fprintf(lFlePtrArchivo,"%d",gintPidServidor);
fclose(lFlePtrArchivo);
}
else
{
   LogSiscom("No Se pudo abrir el archivo %s",lchrArrArchivo);
   exit(1);
}
}
else
{
LogSiscom("El script de inicio debe declarar la variable DirectorioConfiguracion");
exit(1);
}
}
void ObtenDatosModuloIni(char *pchrPtrModulo,
			 char *pchrPtrFuncion)
{
SiscomVariableIni lSiscomVarIniModulo,
		  lSiscomVarIniFuncion;
SiscomObtenVariableIni("ModuloSistema",
		       &gSiscomDatIni,
		       &lSiscomVarIniModulo);
SiscomObtenVariableIni("FuncionModuloSistema",
			&gSiscomDatIni,
			&lSiscomVarIniFuncion);
strcpy(pchrPtrModulo,lSiscomVarIniModulo.chrArrDato);
strcpy(pchrPtrFuncion,lSiscomVarIniFuncion.chrArrDato);
}
void CargaModuloSistema(int pintSocket,const char *pchrPtrDirIpCliente)
{
void *lvidPtrAncla;
void (*lvidPtrSiscomSistema)(const char *pchrPtrDirIpCliente,
		      void *pvidPtrAncla,
		      int pintSocket);
char lchrArrModulo[1024];
char lchrArrFuncion[1024];
ObtenDatosModuloIni(lchrArrModulo,lchrArrFuncion);
if((lvidPtrAncla=dlopen(lchrArrModulo,RTLD_LAZY)))
{
 if((lvidPtrSiscomSistema=(void (*)(const char *,void *,int))dlsym(lvidPtrAncla,lchrArrFuncion)))
 {
   lvidPtrSiscomSistema(pchrPtrDirIpCliente,
   		 lvidPtrAncla,
		 pintSocket);
    LogSiscom("::-::-::-::-:: Terminando   ::-::-::-::-::");
 }
 else
 LogSiscom("dlsym(%s)",dlerror());
}
else
LogSiscom("dlopen(%s)",dlerror());

   dlclose(lvidPtrAncla);
}
void CorreFuncionGestionEstatica(const char *pchrPtrDirIp,
				 void *pvidPtrAncla,
				 int pintSocket,
				 SiscomOpGestionEstatica *pSiscomOpGesEstDat,
				 SiscomRegistroProL *pSiscomRegProLPtrPrim,
				 SiscomRegistroProL *pSiscomRegProLPtrAct)
{
  while(pSiscomOpGesEstDat->gSiscomGestionEstatica)
  {
    if(!strcmp(pSiscomOpGesEstDat->chrArrOperacion,
    	       SiscomCampoRegistro("Operacion",pSiscomRegProLPtrPrim)))
     pSiscomOpGesEstDat->gSiscomGestionEstatica(pintSocket,
     						gvidPtrAncla,
						pSiscomRegProLPtrPrim,
						pSiscomRegProLPtrAct);

     pSiscomOpGesEstDat++;
  }

}
/* Miercoles 9 de Mayo del 2012
 * Se debera evaluar la posibilidad de ejecutar varias sentencias 
 * Sql de consulta 
 */
void EjecutaFuncionGestionEstatica(int pintSocket,
				   const char *pchrPtrDirIpCliente)
{
char lchrArrBuffer[8192];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
SiscomLeeRegistrosSocket(pintSocket,
			 lchrArrBuffer,
			 &lSiscomRegProLPtrPrim,
			 &lSiscomRegProLPtrAct);
LogSiscom("La Operacion:%s",SiscomCampoRegistro("Operacion",lSiscomRegProLPtrPrim));

CorreFuncionGestionEstatica(pchrPtrDirIpCliente,
			    gvidPtrAncla,
			    pintSocket,
			    gSiscomOpGesEstDat,
			    lSiscomRegProLPtrPrim,
			    lSiscomRegProLPtrAct);
LogSiscom("::-::-::-::-:: Terminando   ::-::-::-::-::");
}
void CargandoModuloSistema(int pintSocket,const char *pchrPtrDirIpCliente)
{
  if(ModoOperacionGestionEstatica())
  EjecutaFuncionGestionEstatica(pintSocket,pchrPtrDirIpCliente);
  else
  CargaModuloSistema(pintSocket,pchrPtrDirIpCliente);
}
void CargandoMemoria()
{
/* Lunes 22 de diciembre del 2014
 */ 
  if(SiscomVariableIniAInt("CargaMemoria",&gSiscomDatIni))
  {
  LogSiscom("Se inicia memoria comun");
  CargaInformacionMemoria();
  }
}
void CargaInformacionMemoria()
{
void *lvidPtrModulo;
void (*CargaMemoria)();
char lchrArrModulo[128],
      lchrArrFuncion[128];
SiscomVariableIniAChar2("ModuloMemoria",&gSiscomDatIni,lchrArrModulo);
SiscomVariableIniAChar2("FuncionModuloMemoria",&gSiscomDatIni,lchrArrFuncion);
if((lvidPtrModulo=dlopen(lchrArrModulo,RTLD_LAZY)))
{
  if((CargaMemoria=(void (*)())dlsym(lvidPtrModulo,lchrArrFuncion)))
	  CargaMemoria();
   else
   LogSiscom("%s",dlerror());

}
else
{
LogSiscom("dlopen(%s)=%s",lchrArrModulo,dlerror());
exit(0);
}

dlclose(lvidPtrModulo);

}
void AtiendeCliente(int pintSocket,char *pchrPtrDirIpCliente)
{
int lintPidACliente;
LogSiscom("::-::-::-::-:: Conexion de  %s ::-::-::-::-:: ",pchrPtrDirIpCliente);
if(!(lintPidACliente=fork()))
{
CargandoModuloSistema(pintSocket,pchrPtrDirIpCliente);
close(pintSocket);
exit(0);
}
else
{
close(pintSocket);
}

}
int SiscomEsperaConexionServidor(int pintSocket,
				 char *pchrPtrDirIpCliente)
{
struct sockaddr_in lSSocAddrInReg;
int lintTamano;
int lintSocketCliente;
lintTamano=sizeof(struct sockaddr_in);

if((lintSocketCliente=accept(pintSocket,
                             (struct sockaddr *)&lSSocAddrInReg,
			     &lintTamano))<0)
LogSiscom("accept(%s)",strerror(errno));
strcpy(pchrPtrDirIpCliente,(char *)inet_ntoa(lSSocAddrInReg.sin_addr));
return lintSocketCliente;
}
int SiscomIniciaSocketComunicaciones(int pintPtoCom)
{
int lintSocket;
int lintTamano;
struct sockaddr_in lSSocAddrInDir;
	if((lintSocket=socket(PF_INET,SOCK_STREAM,0) )<0)
	{
	  LogSiscom("socket(%s)",strerror(errno));
	  return -1;	
	}
	else
	{
	 lSSocAddrInDir.sin_port=htons(pintPtoCom);
	 lSSocAddrInDir.sin_family=AF_INET;
	 lSSocAddrInDir.sin_addr.s_addr=INADDR_ANY;
	 if(bind(lintSocket,
		 (struct sockaddr *)&lSSocAddrInDir,
		 sizeof(struct sockaddr_in))<0)
	 {
	  LogSiscom("bind:(%s)",strerror(errno));
	  return -1;	
	 }
	 else
 	   if(listen(lintSocket,100)<0)
	  {
	    LogSiscom("listen:%s",strerror(errno));
	    return -1;	
	  }
	}
	return lintSocket;	
}
void SiscomSIGSEGV(int pintSignal)
{
LogSiscom("El servidor recibio SIGSEGV");
exit(2);
}
