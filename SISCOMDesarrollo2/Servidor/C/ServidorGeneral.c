#include <ServidorGeneral.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
/* Tepotzotlan Mexico a Domingo 13 de Marzo del 2016 
 * Archivos cabecera Siscom Electronica version 4
 */
#include <SiscomArchivosIni.h>




int errno;
FILE *gPtrFleArchivoLog;
FILE *gPtrFleArchivoLog;
StcSiscomConfiguracion gSSiscomConfiguracionSvr;
LCamposSiscomPro2 **gLCSiscomPro2Memoria;
/* Tepotzotlan Mexico a Domingo 13 de Marzo del 2016 
 * se integran las variables globales de la version 4
 * del sistema de desarollo Siscom Electronica
 *
 */
SiscomDatosIni gSiscomDatIni;
void *gSiscomRegProLPtrMemoria;
void *gSiscomErrorSistema;
int gintSocketProtocoloLog;

int gintTamArregloMemComun=0;
SSiscomOperaciones *gSSiscomOpSistema;

/* Domingo 7 de julio del 2013, se agrego 
 * la variable global que almacenara la direccion
 * ip del cliente que se conecto al servidor
 */
char gchrArrDirIpCliente[28]; 

int main(int pintArgc,
	 char **pchrPtrArgv)
{

struct sockaddr_in lSSocAddrInReg;
int lintSocket,
	lintTamano,
	lintSocketCliente,
	lintIdProceso;
	gPtrFleArchivoLog=stdout;
	InstalaManejadorDeSenales();  
	SiscomAnalizaArchivoConfiguracion(pchrPtrArgv[1],
					 (void (*)(SiscomDatosConfiguracion *,void *)) AsignaDatosArchivoAConfiguracion,
					  (void *)&gSSiscomConfiguracionSvr);
	AbreArchivoLog();
	IniciaMemoriaComunServidor();
	CargaFuncionesServidor();
	if((lintSocket=IniciaServidorComunicaciones(gSSiscomConfiguracionSvr.intPtoCom))<0)
	{
	   SiscomLog("IniciaServidorComunicaciones:"); 
	   
	}
	else
	{
	 lintTamano=sizeof(struct sockaddr_in);
	  signal(SIGCHLD,SIG_IGN);
	     if(!(gSSiscomConfiguracionSvr.intIdProceso=fork()))
	  {
	   while(1)
	   {
	         if((lintSocketCliente=accept(lintSocket,
					      (struct sockaddr *)&lSSocAddrInReg,
					      &lintTamano))<0)
	 	 {

		 }
		 else
		 {
		 if(!fork())
		 {
		  strcpy(gchrArrDirIpCliente,
		  	(char *)inet_ntoa(lSSocAddrInReg.sin_addr));
		  ProcesaInformacion(lintSocketCliente);
		  close(lintSocketCliente);
		  exit(0);
		 }
	         else
		   close(lintSocketCliente);
		}
					      
	   } 
	 }
	 else
	 {
	   	SiscomLog("Servidor Atendiento peticiones");
	  AlmacenaPid(gSSiscomConfiguracionSvr.intIdProceso);
	 }

	}
}
void CargaFuncionesServidor()
{
}
void AlmacenaPid(int pintIdProceso)
{
char lchrArrArchivoLog[1024];
FILE *lFlePtrArchivo;
	sprintf(lchrArrArchivoLog,
		"%s/PIDs/ServidorSiscom%dPid",
		gSSiscomConfiguracionSvr.chrPtrDirTrabajo,
		gSSiscomConfiguracionSvr.intPtoCom);
	if((lFlePtrArchivo=fopen(lchrArrArchivoLog,
				     "w")))
	{
	  fprintf(lFlePtrArchivo,"%d",pintIdProceso); 
	  fclose(lFlePtrArchivo);

	}
	else
	{
	 SiscomLog("No se pudo crear archivo Para almacenar el Pid (%s)",
			  lchrArrArchivoLog);
	exit(0);
	}


}
void AsignaDatosArchivoAConfiguracion(SiscomDatosConfiguracion *pSDatosConfig,
				      StcSiscomConfiguracion *pSSiscomConfg)
{
int lintContador;
	memset(&gSSiscomConfiguracionSvr,0,sizeof(StcSiscomConfiguracion));
	SiscomAsignaDatoConfiguracionINT(pSDatosConfig,
					 "PtoComunicaciones",
					 &pSSiscomConfg->intPtoCom);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "FuncionLibServidor",
					  &pSSiscomConfg->chrPtrFuncionLibServidor);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "LibServidor",
					  &pSSiscomConfg->chrPtrLibServidor);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "BaseDatos",
					  &pSSiscomConfg->chrPtrBaseDatos);

	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "PuertoBD",
					  &pSSiscomConfg->chrPtrPtoBD);

	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "DirTrabajo",
					  &pSSiscomConfg->chrPtrDirTrabajo);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "Demonio",
					  &pSSiscomConfg->chrPtrDemonio);
	SiscomAsignaDatoConfiguracionINT(pSDatosConfig,
					  "PtoAccesoDatos",
					  &pSSiscomConfg->intPtoAccesoDatos);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "DirIpAccesoDatos",
					  &pSSiscomConfg->chrPtrDirIpAccesoDatos);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "LibMemoriaComun",
					  &pSSiscomConfg->chrPtrLibMemoriaComun);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "FuncionLibMemoriaComun",
					  &pSSiscomConfg->chrPtrFuncionMemoriaComun);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "ClienteFrecuente",
					  &pSSiscomConfg->chrPtrClienteFrecuente);

	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "ModuloImpresion",
					  &pSSiscomConfg->chrPtrModuloImpresion);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "FuncionImpresion",
					  &pSSiscomConfg->chrPtrFuncionImpresion);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "HabilitarImpresion",
					  &pSSiscomConfg->chrPtrHabilitaImpresion);
	SiscomAsignaDatoConfiguracionCHAR(pSDatosConfig,
					  "DirIpAccesoDatos4",
					  &pSSiscomConfg->chrPtrDirIpAccesoDatos4);
	SiscomAsignaDatoConfiguracionINT(pSDatosConfig,
					  "PtoAccesoDatos4",
					  &pSSiscomConfg->intPuertoAccesoDatos4);
}
void ProcesaInformacion(int pintSocket)

{
void *lvidAncla;
void (*Principal)(int);
	if(!(lvidAncla=dlopen(gSSiscomConfiguracionSvr.chrPtrLibServidor,RTLD_NOW))) 
	{
	  SiscomLog("ProcesaInformacion:dlopen(%s)",
		  dlerror()); 
	}
	else
	if(!(Principal=dlsym(lvidAncla,gSSiscomConfiguracionSvr.chrPtrFuncionLibServidor)))
	  SiscomLog("ProcesaInformacion:dlsym(%s)",
		  dlerror()); 
	else
	{
	 Principal(pintSocket); 
	 dlclose(lvidAncla);
	}
	 
	
}
int IniciaServidorComunicaciones(int pintPtoCom)
{
int lintSocket;
int lintTamano;
struct sockaddr_in lSSocAddrInDir;


	if((lintSocket=socket(PF_INET,SOCK_STREAM,0) )<0)
	{
	  fprintf(gPtrFleArchivoLog,
		  "SOCKET:%s\n",
		  strerror(errno));
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
	  fprintf(gPtrFleArchivoLog,
		  "BIND:%s\n",
		  strerror(errno));
	  return -1;	


	 }
	 else
 	   if(listen(lintSocket,100)<0)
	  {
		fprintf(gPtrFleArchivoLog,
		  "LISTEN:%s\n",
		  strerror(errno));
	  return -1;	

	  }

	 
	}
	return lintSocket;	
}
void AbreArchivoLog()
{
char lchrArrArchivoLog[1024];

	sprintf(lchrArrArchivoLog,
		"%s/LOGs/ServidorSiscom%dLog",
		gSSiscomConfiguracionSvr.chrPtrDirTrabajo,
		gSSiscomConfiguracionSvr.intPtoCom);
	if((gPtrFleArchivoLog=fopen(lchrArrArchivoLog,
				     "a")))
	{
	   SiscomLog("Servidor SISCOM Version2 Iniciando Operacion");
	   SiscomLog("El Servidor SISCOM Es Propiedad Intelectual De");
	   SiscomLog("Heli Garduno Esquivel");

	}
	else
	{
	gPtrFleArchivoLog=stdout;
	SiscomLog("Error Al crear El Log:%s",lchrArrArchivoLog);
	exit(0);
	}
		
}
void ControladorSignal16(int pintNoSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(16,ControladorSignal16);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);

	SiscomLog("ControladorSignal16:Deteniendo el servidor...");
	kill(gSSiscomConfiguracionSvr.intIdProceso,SIGTERM);
}
void ControladorSIGPIPE(int pintNoSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(SIGPIPE,ControladorSIGPIPE);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);

	SiscomLog("Se perdio la conexion");
	exit(1);

}
void ControladorSIGSEGV(int pintNoSenal)
{
sigset_t lSigset_tMask,lSigset_tAnterior;
signal(SIGSEGV,ControladorSIGSEGV);
sigfillset(&lSigset_tMask);
sigprocmask(SIG_SETMASK,&lSigset_tMask,&lSigset_tAnterior);
SiscomLog("ControladorSIGSEGV:El Sistema Trono");
	exit(1);

}
void InstalaManejadorDeSenales()
{
	  signal(SIGSEGV,ControladorSIGSEGV);
	  signal(SIGPIPE,ControladorSIGPIPE);
	  signal(16,ControladorSignal16);
}
void IniciaMemoriaComunServidor()
{
void *lvidAncla;
LCamposSiscomPro2 **(*CargaInformacion)(int,const char *,int *);
	SiscomLog("IniciaMemoriaComunServidor");
	if(gSSiscomConfiguracionSvr.chrPtrLibMemoriaComun &&
	   gSSiscomConfiguracionSvr.chrPtrFuncionMemoriaComun)
	{
	SiscomLog("Iniciando Area De Memoria Comun ServidorSiscom:{%s->%s}",
			  gSSiscomConfiguracionSvr.chrPtrLibMemoriaComun,
			  gSSiscomConfiguracionSvr.chrPtrFuncionMemoriaComun);
	if(!(lvidAncla=dlopen(gSSiscomConfiguracionSvr.chrPtrLibMemoriaComun,RTLD_NOW))) 
	{
	  SiscomLog("ProcesaInformacion:dlopen(%s)",
		  dlerror()); 
	}
	else
	if(!(CargaInformacion=dlsym(lvidAncla,gSSiscomConfiguracionSvr.chrPtrFuncionMemoriaComun)))
	  SiscomLog("ProcesaInformacion:dlsym(%s)",
		  dlerror()); 
	else
	{
	 gLCSiscomPro2Memoria=CargaInformacion(
	 		gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	 		gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			 &gintTamArregloMemComun);
	 dlclose(lvidAncla);
	}
	}
	else
	SiscomLog("No Se cuenta con informacion para iniciar Memoria Comun");
}
