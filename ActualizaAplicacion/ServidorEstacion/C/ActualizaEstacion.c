#include <ActualizaEstacion.h>
#include <ServidorGeneral.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

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

	SiscomIniciaOperaciones(1,pSSiscomOp);
	SiscomAnexaOperacion("ActualizaEstacion",
			     ActualizaEstacion,
			     pSSiscomOp);

}
void EnviaConfirmacion(int pintSocket)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
                  *lLCSiscomPro2Act=0;
int lintNRegistros=0;                 
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
                        &lLCSiscomPro2Act,         
                        &lintNRegistros,
                        "Confirmacion",        
                         "IniciaLaTransmision");
SiscomEnviaAlServidor(pintSocket,
                      lintNRegistros,               
                      "IniciaTransmision",
                      lLCSiscomPro2Prim);

}
void ActualizaEstacion(int pintSocket,
		       int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
int lintArchivo;
char lchrArrArchivo[1024];
char lchrArrBuffer[4197];
int lintNBytes;
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lLCSiscomPro2);
	sprintf(lchrArrArchivo,
		"%s/%s/%s",
		SiscomObtenDato(lLCSiscomPro2,"Home"),
		SiscomObtenDato(lLCSiscomPro2,"DirTrabajo"),
		SiscomObtenDato(lLCSiscomPro2,"Archivo"));
	EnviaConfirmacion(pintSocket);	
	if((lintArchivo=open(lchrArrArchivo,
	                O_WRONLY|O_CREAT,
                                 S_IRWXU|S_IROTH|S_IXOTH))>0)
        {
	      while((lintNBytes=read(pintSocket,
				     lchrArrBuffer,
				     4196)))
		write(lintArchivo,lchrArrBuffer,lintNBytes); 
		close(lintArchivo);
	}	
	else
	{
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "No Se pudo Abri el archivo %s",
			  lchrArrArchivo);
	close(pintSocket);
	}
}
