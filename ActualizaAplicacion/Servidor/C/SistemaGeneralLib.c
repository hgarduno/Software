#include <SistemaGeneralLib.h>
#include <ServidorGeneral.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

FILE *gPtrFleArchivoLog; 
int errno;
StcSiscomConfiguracion gSSiscomConfiguracionSvr;
void Principal(int pintSocket,
	       FILE *pPtrFleArchivoLog,
	       StcSiscomConfiguracion pSSiscomConfiguracionSvr)
{
SSiscomOperaciones *lSSiscomOp=0;
int lintContador;
char *lchrPtrOperacion=0;
int lintNRegistros;
	gPtrFleArchivoLog=pPtrFleArchivoLog;
	gSSiscomConfiguracionSvr=pSSiscomConfiguracionSvr;
	OperacionesSistemaGeneral(&lSSiscomOp);
	SiscomVersionProtocolo(pintSocket);
	SiscomLeeNumeroRegistros(pintSocket,
				 &lintNRegistros);	
	SiscomLeeOperacion(pintSocket,
                           &lchrPtrOperacion);
	for(lintContador=0;
            lintContador<lSSiscomOp->intNumOperaciones;
            lintContador++)
        if(!strcmp((lSSiscomOp+lintContador)->chrPtrOperacion,
                   lchrPtrOperacion))
        {
             (lSSiscomOp+lintContador)->Operacion(pintSocket,lintNRegistros);
             return ;
        }
        SiscomMensajesLog(gPtrFleArchivoLog,"MAIN:Operacion {%s} No Soportada",
                lchrPtrOperacion);


}

void OperacionesSistemaGeneral(SSiscomOperaciones **pSSiscomOp)
{

	SiscomIniciaOperaciones(6,pSSiscomOp);
	SiscomAnexaOperacion("CreaDirectorioTrabajo",
			     OP_CreaDirectorioTrabajo,
			     pSSiscomOp);	
	SiscomAnexaOperacion("CopiaModulo",
			     OP_CopiaModulo,
			     pSSiscomOp);	
	SiscomAnexaOperacion("ObtenEstaciones",
			     OP_ObtenEstaciones,
			     pSSiscomOp);	
	SiscomAnexaOperacion("InsertaEstacion",
			     InsertaEstacion,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaEstaciones",
			     ConsultaEstaciones,
			     pSSiscomOp);
	SiscomAnexaOperacion("TransfiereAEstaciones",
			     TransfiereAEstaciones,
			     pSSiscomOp);

}

char *CreaDirectorio(const char *pchrPtrDirHome,
		   const char *pchrPtrNmbDirectorio)
{
char lchrArrDirTrabajo[1024];

	sprintf(lchrArrDirTrabajo,
		"%s/%s",
		pchrPtrDirHome,
		pchrPtrNmbDirectorio);
	if(mkdir(lchrArrDirTrabajo,S_IRWXU|S_IRWXO))
	return (char *)strerror(errno);
	else
	return 0;
	
	     
}
void CreaDirectorios(const char *pchrPtrDirHome,
		     const char *pchrPtrDirInstalacion,
		     const char *pchrPtrDirServidor,
		     char **pchrPtrEdoCDirInstalacion,
		     char **pchrPtrEdoCDirConfiguracion)
{
char lchrArrNmbDirectorio[1024];
	*pchrPtrEdoCDirInstalacion=CreaDirectorio(pchrPtrDirHome,pchrPtrDirInstalacion);
	*pchrPtrEdoCDirConfiguracion=CreaDirectorio(pchrPtrDirHome,pchrPtrDirServidor);
}
const char *ValidaError(const char *pchrPtrEdoOperacion)
{
	return pchrPtrEdoOperacion ? pchrPtrEdoOperacion :"OK";
}
void NotificaEdoCreacion(const char *pchrPtrEdoCInstalacion,
			 const char *pchrPtrEdoCConfiguracion,
			 int pintSocket)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
		  *lLCSiscomPro2Act=0;
int lintNRegistros=0;
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
                        &lLCSiscomPro2Act,         
			&lintNRegistros,
                        "EdoCreacionInstalacion,               \
                         EdoCreacionConfiguracion" ,
			 pchrPtrEdoCInstalacion,	
			 pchrPtrEdoCConfiguracion);
SiscomEnviaAlServidor(pintSocket,
		      lintNRegistros,		      
                      "NotificacionEdoCrearDirectorios",
                      lLCSiscomPro2Prim);	
printf("El Servidor Notifico al cliente\n");
}
void OP_CreaDirectorioTrabajo(int pintSocket,
			      int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
char *lchrPtrEdoCDInstalacion,
     *lchrPtrEdoCDConfiguracion;

	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lLCSiscomPro2);
	CreaDirectorios(SiscomObtenDato(lLCSiscomPro2,"DirHome"),
			SiscomObtenDato(lLCSiscomPro2,"DirectorioInstalacion"),
		        SiscomObtenDato(lLCSiscomPro2,"DirectorioServidor"),
			&lchrPtrEdoCDInstalacion,
			&lchrPtrEdoCDConfiguracion);	
	printf("OP_CreaDirectorioTrabajo:Instalacion(%s}\tConfiguracion(%s)\n",
		ValidaError(lchrPtrEdoCDInstalacion),
		ValidaError(lchrPtrEdoCDConfiguracion));	
	NotificaEdoCreacion(lchrPtrEdoCDInstalacion,
			    lchrPtrEdoCDConfiguracion,
			    pintSocket);	
        close(pintSocket);
}

int CreaArchivoEscribir(const char *pchrPtrNmbArchivo,
			 const char *pchrPtrDirectorio,
			 const char *pchrPtrHome,
			 int *pintPtrArchivo,
			 char *pchrPtrArchivo)
{


	sprintf(pchrPtrArchivo,
		"%s/%s/%s",
		pchrPtrHome,
		pchrPtrDirectorio,
		pchrPtrNmbArchivo);

	if((*pintPtrArchivo=open(pchrPtrArchivo,
				 O_WRONLY|O_CREAT,
				 S_IRWXU|S_IROTH|S_IXOTH))<0)
	{
	  SiscomMensajesLog(gPtrFleArchivoLog,
			    "CreaArchivoEscribir:{%s}{%s}",
		 pchrPtrArchivo,
		 strerror(errno));
	  return 0;
	}
	else
	return 1;
	


}
void AlmacenaArchivo(LCamposSiscomPro2 *pLCSiscomPro2,
		     const char *pchrPtrArchivo)
{
char lchrArrInsertaArchivo[4196];
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
		  *lLCSiscomPro2InsAct=0;
int lintNRegistros=0;
char *lchrPtrEdoConexion=0;
int lintSocketAD;
sprintf(lchrArrInsertaArchivo,
	"insert into Archivos values('%s','%s','%s','%s');",
	 SiscomObtenDato(pLCSiscomPro2,"Origen"),
	 pchrPtrArchivo,
	 SiscomObtenDato(pLCSiscomPro2,"Comentario"),
	 SiscomObtenDato(pLCSiscomPro2,"Destino"));
	     SiscomAnexaRegistroPro2(
			&lLCSiscomPro2Ins,
                        &lLCSiscomPro2InsAct,
                        &lintNRegistros, 
			"ComandoSQL",
			lchrArrInsertaArchivo);
SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  "Inserciones",
			  lintNRegistros,
			  lLCSiscomPro2Ins,
			  &lchrPtrEdoConexion,
			  &lintSocketAD);
	
}
void TransfiereArchivo(LCamposSiscomPro2 *pLCSiscomPro2,
		       int pintSocket,
		       char *pchrPtrArchivo)
{
int lintModulo;
int lintNBytes;
char lchrArrBuffer[4197];
	if(CreaArchivoEscribir(SiscomObtenDato(pLCSiscomPro2,"Destino"),
			       SiscomObtenDato(pLCSiscomPro2,"DirTrabajo"),
			       SiscomObtenDato(pLCSiscomPro2,"Home"),
			       &lintModulo,
			       pchrPtrArchivo))
	{
	    while((lintNBytes=read(pintSocket,
				     lchrArrBuffer,
				     4196)))
		write(lintModulo,lchrArrBuffer,lintNBytes); 
	    close(lintModulo);
	}
		

}
void OP_CopiaModulo(int pintSocket,
		    int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
char lchrArrArchivo[1024];
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lLCSiscomPro2);
	TransfiereArchivo(lLCSiscomPro2,pintSocket,lchrArrArchivo);
	AlmacenaArchivo(lLCSiscomPro2,lchrArrArchivo);
}
void ObtenInformacionDelArchivo(int pintSocket,
			    LCamposSiscomPro2 *pLCSiscomPro2,
			    char *pchrPtrContenido)
{
int lintArchivo;
int lintNBytes;
char lchrArrNmbArchivo[1024];
	sprintf(lchrArrNmbArchivo,
		"%s/%s/%s",
		SiscomObtenDato(pLCSiscomPro2,"Home"),
		SiscomObtenDato(pLCSiscomPro2,"DirTrabajo"),
		SiscomObtenDato(pLCSiscomPro2,"Archivo"));
	if((lintArchivo=open(lchrArrNmbArchivo,O_RDONLY,0))<0)
	{
	  printf("ObtenInformacionDelArchivo:{%s}\n",
		  strerror(errno));
	  pchrPtrContenido[0]=0;
	}
	else
	{
	lintNBytes=read(lintArchivo,pchrPtrContenido,4192);
	pchrPtrContenido[lintNBytes]=0;
	}

}
void ObtenEstacion(const char *pchrPtrLinea,
		   char **pchrPtrDirIp,
		   char **pchrPtrPtoCom,
		   char **pchrPtrDirTrabajo,
		   char **pchrPtrHome)
{
char **lchrPtrDatos;
char lchrArrBuffer[1024];
	if((SiscomAnalizaCadenas(pchrPtrLinea,
				 '\t',
				 lchrArrBuffer,
				 &lchrPtrDatos)))
	{
		 *pchrPtrDirIp=lchrPtrDatos[0];
		 *pchrPtrPtoCom=lchrPtrDatos[1];
		 *pchrPtrDirTrabajo=lchrPtrDatos[2];
		 *pchrPtrHome=lchrPtrDatos[3];
	}
				 

}
void EnviaEstaciones(int pintSocket,
		     const char *pchrPtrArchivo)
{
char **lchrPtrLineas,
      *lchrPtrDirIp,
      *lchrPtrPtoCom,
      *lchrPtrDirTrabajo,
      *lchrPtrHome;
char lchrArrBuffer[4192];
int lintContador;
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
		  *lLCSiscomPro2Act=0;
int lintNRegistros=0;

	if((SiscomAnalizaCadenas(pchrPtrArchivo,
				 '\n',
				 lchrArrBuffer,
				 &lchrPtrLineas)))
	{
	   for(lintContador=0;
	       lchrPtrLineas[lintContador];
	       lintContador++)
	   {
	     ObtenEstacion(lchrPtrLineas[lintContador],
			    &lchrPtrDirIp,
			    &lchrPtrPtoCom,
			    &lchrPtrDirTrabajo,
			    &lchrPtrHome);
	      SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
                        &lLCSiscomPro2Act,         
			&lintNRegistros,
			"DirIp,			\
			 PtoCom,		\
			 DirTrabajo,		\
			 Home",
			lchrPtrDirIp,
			lchrPtrPtoCom,
			lchrPtrDirTrabajo,
			lchrPtrHome);

	   }
	  SiscomEnviaAlServidor(pintSocket,
			        lintNRegistros,
				"Estaciones",
				lLCSiscomPro2Prim);
	}
}
void OP_ObtenEstaciones(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
char lchrArrDatosArchivo[4192];
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lLCSiscomPro2);
	ObtenInformacionDelArchivo(pintSocket,
				   lLCSiscomPro2,
				   lchrArrDatosArchivo);
	EnviaEstaciones(pintSocket,lchrArrDatosArchivo);
	close(pintSocket);
}
void InsertaEstacion(int pintSocket,
		     int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
		  *lLCSiscomPro2InsAct=0;
int lintSocketAD;
char *lchrPtrEdoConexion=0;
int lintNRegistros=0;
char lchrArrInsercion[1024];
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lLCSiscomPro2);
	for(;
	     lLCSiscomPro2;
	     lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
	{
	  
	   sprintf(lchrArrInsercion,
		   "insert into estaciones values('%s',%s,'%s','%s');",
		   SiscomObtenDato(lLCSiscomPro2,"DirIp"),
                   SiscomObtenDato(lLCSiscomPro2,"PtoCom"),
                   SiscomObtenDato(lLCSiscomPro2,"DirTrabajo"),
                   SiscomObtenDato(lLCSiscomPro2,"Home"));
	   SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
				   &lLCSiscomPro2InsAct,
				   &lintNRegistros,
				   "ComandoSQL",
				   lchrArrInsercion);
	}
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD); 
	if(lchrPtrEdoConexion)
	 SiscomMensajesLog(gPtrFleArchivoLog,
			   "Error Al Enviar:%s",
			   lchrPtrEdoConexion);
}
void ConsultaEstacionesBD(LCamposSiscomPro2 **pLCSiscomPro2Reg)
{
int lintSocketAD,
    lintNRegistros=0,
    lintNRegistrosRes=0;
char lchrArrConsultaSQL[1024];
char *lchrPtrEdoConexion=0,
     *lchrPtrOperacionRes=0;

LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
		  *lLCSiscomPro2InsAct=0;
sprintf(lchrArrConsultaSQL,
		     "select * from estaciones");
	     SiscomAnexaRegistroPro2(
			&lLCSiscomPro2Ins,
                        &lLCSiscomPro2InsAct,
                        &lintNRegistros, 
			"ConsultaSQL",
			lchrArrConsultaSQL);
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Consultas",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD); 
	if(lchrPtrEdoConexion)
	 SiscomMensajesLog(gPtrFleArchivoLog,
			   "Error Al Enviar:%s",
			   lchrPtrEdoConexion);
	else
	{
	SiscomLeeNumeroRegistros(lintSocketAD,
				 &lintNRegistrosRes);
	SiscomLeeOperacion(lintSocketAD,
			   &lchrPtrOperacionRes);
	SiscomLeeInformacionProtocolo(lintSocketAD,
				      lintNRegistrosRes,
				      pLCSiscomPro2Reg);
	}

}
			  
void ConsultaEstaciones(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
		  *lLCSiscomPro2InsAct=0;
LCamposSiscomPro2 *lLCSiscomPro2Consulta=0;

int lintSocketAD;
char *lchrPtrEdoConexion=0,
     *lchrPtrOperacionRes=0;
int lintNRegistros=0,lintNRegistrosRes;
char lchrArrConsultaSQL[1024];
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lLCSiscomPro2);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "ConsultaEstaciones:%s",
			  SiscomObtenDato(lLCSiscomPro2,"Parametro")); 
	if(!strcmp(SiscomObtenDato(lLCSiscomPro2,"Parametro"),"Todas"))
	{
	     sprintf(lchrArrConsultaSQL,
		     "select * from estaciones");
	     SiscomAnexaRegistroPro2(
			&lLCSiscomPro2Ins,
                        &lLCSiscomPro2InsAct,
                        &lintNRegistros, 
			"ConsultaSQL",
			lchrArrConsultaSQL);
	}
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Consultas",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD); 
	if(lchrPtrEdoConexion)
	 SiscomMensajesLog(gPtrFleArchivoLog,
			   "Error Al Enviar:%s",
			   lchrPtrEdoConexion);
	else
	{
	SiscomLeeNumeroRegistros(lintSocketAD,
				 &lintNRegistrosRes);
	SiscomLeeOperacion(lintSocketAD,
			   &lchrPtrOperacionRes);
	SiscomLeeInformacionProtocolo(lintSocketAD,
				      lintNRegistrosRes,
				      &lLCSiscomPro2Consulta);
	SiscomImprimeContenidoProtocolo("Prueba",
				        gPtrFleArchivoLog,
					lLCSiscomPro2Consulta);
	SiscomEnviaAlServidor(pintSocket,
			      lintNRegistrosRes,
			      "ObtenEstaciones",
			      lLCSiscomPro2Consulta);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Se envio al cliente ");
	
	
	}
}
void TransfiereArchivoALaEstacion(LCamposSiscomPro2 *pLCSiscomPro2E,
				  LCamposSiscomPro2 *pLCSiscomPro2A)
{
int lintArchivo,
    lintNBytes,
    lintNEscritura;
char lchrArrBuffer[4197];
SiscomOperacionesServidor lSOpServidor;
	SiscomIniciaComunicacionesSrv(SiscomObtenDato(pLCSiscomPro2E,"dirip"),
				      atoi(SiscomObtenDato(pLCSiscomPro2E,"ptocom")),
				      &lSOpServidor);
	SiscomInformacionOperaciones("No Se Usa",
				     "ActualizaEstacion",
				     &lSOpServidor);
	SiscomAnexaRegistroPro2(&lSOpServidor.LCSiscomPro2EPrim,
				&lSOpServidor.LCSiscomPro2EAct,
				&lSOpServidor.intNRegistros,
				"Archivo,	\
				Home,		\
				DirTrabajo",
				SiscomObtenDato(pLCSiscomPro2A,
						"archivosolo"),
				SiscomObtenDato(pLCSiscomPro2E,
						"home"),
				SiscomObtenDato(pLCSiscomPro2E,
						"dirtrabajo"));
	SiscomOperacionesServidores(&lSOpServidor);	
	if((lintArchivo=open(SiscomObtenDato(pLCSiscomPro2A,"archivo"),	
			     O_RDONLY,
				 0))>0)
	{
	     while((lintNBytes=read(lintArchivo,lchrArrBuffer,4196)))
	      write(lSOpServidor.intSocket,
		    lchrArrBuffer,
		    lintNBytes);
	     close(lintArchivo);
	}
	else
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "No Se Pudo Abrir El Archivo,%s->%s",
			  strerror(errno),
			  SiscomObtenDato(pLCSiscomPro2A,"archivo"));
	close(lSOpServidor.intSocket);
}
void NotificaEstadoTransmision(int pintSocketCliente,
			       const char *pchrPtrEdoTransmision,
			       LCamposSiscomPro2 *pLCSiscomPro2E,
			       LCamposSiscomPro2 *pLCSiscomPro2A)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
		  *lLCSiscomPro2Act=0;
int lintNRegistros=0;
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
                        &lLCSiscomPro2Act,         
			&lintNRegistros,
                        "EdoTransmision,\
			 Archivo,       \
			 Estacion,      \
			 Puerto",
			 pchrPtrEdoTransmision,
			 SiscomObtenDato(pLCSiscomPro2A,"archivosolo"),
			 SiscomObtenDato(pLCSiscomPro2E,"dirip"),
			 SiscomObtenDato(pLCSiscomPro2E,"ptocom"));
SiscomEnviaAlServidor(pintSocketCliente,
		      lintNRegistros,		      
                      "NotificaEdoTransmision",
                      lLCSiscomPro2Prim);	


}
void NotificaFinTransferencia(int pintSocketCliente)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
		  *lLCSiscomPro2Act=0;
int lintNRegistros=0;
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
                        &lLCSiscomPro2Act,         
			&lintNRegistros,
                        "EdoTransmision",
			"FinTransferencia");
SiscomEnviaAlServidor(pintSocketCliente,
		      lintNRegistros,		      
                      "NotificaEdoTransmision",
                      lLCSiscomPro2Prim);	


}
void ActualizaEstaciones(int pintSocketCliente,
			LCamposSiscomPro2 *pLCSiscomPro2)
{
SiscomOperacionesServidor lSOpServidor;
LCamposSiscomPro2 *lLCSiscomPro2=0;
	
char lchrArrConsulta[]="select *				    \
			from archivos				    \
			where comentario in('ModuloCliente',        \
					    'AplicacionCliente',    \
					    'ConfiguracionCliente', \
					    'EscriptCliente');";

	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				   gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				   &lSOpServidor);
	SiscomInformacionOperaciones("ConsultaSQL",
				     "Consultas",
				     &lSOpServidor);
	SiscomAnexaRegistroPro2(&lSOpServidor.LCSiscomPro2EPrim,
				&lSOpServidor.LCSiscomPro2EAct,
				&lSOpServidor.intNRegistros,
				"ConsultaSQL",
				lchrArrConsulta);	
	SiscomOperacionesServidores(&lSOpServidor);
	for(;
	    pLCSiscomPro2;
	    pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
	  for(lLCSiscomPro2=lSOpServidor.LCSiscomPro2;
	      lLCSiscomPro2;
	      lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
	  {
	   NotificaEstadoTransmision(pintSocketCliente,
				      "Inicia Envio",
				      pLCSiscomPro2,
				      lLCSiscomPro2);
				       
	   TransfiereArchivoALaEstacion(pLCSiscomPro2,
				        lLCSiscomPro2);
	   NotificaEstadoTransmision(pintSocketCliente,
				     "Fin Transmision",
				      pLCSiscomPro2,
				      lLCSiscomPro2);
	  }
	     
	}
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Se terminaron los archivos y estaciones");
	NotificaFinTransferencia(pintSocketCliente);
}
void EsperaNotificacionCliente(int pintSocket)
{
char lchrArrFin[4196];
int lintNBytes=0;
	
	lintNBytes=read(pintSocket,lchrArrFin,4196);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Si La Notificacion %d",lintNBytes);

}
void TransfiereAEstaciones(int pintSocket,
			   int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "TransfiereAEstaciones:");
	ConsultaEstacionesBD(&lLCSiscomPro2Reg);
	ActualizaEstaciones(pintSocket,lLCSiscomPro2Reg);
	EsperaNotificacionCliente(pintSocket);
	close(pintSocket);		
	


}
