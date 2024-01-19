#include <ClienteEnvio.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomArchivosIni.h>
#include <string.h>
FILE *gPtrFleArchivoLog;
SiscomError gSiscomErrorSistema;
int gintSocketProtocoloLog;
SiscomDatosIni gSiscomDatIni;
SiscomRegistroProL *gSiscomRegProLPtrMemoria;
int main(int pintArgc,
	 char **pchrPtrArgv)
{
char *lchrPtrEdoConexion=0;
FILE *lFlePtrArchivo;
char lchrArrCadena[8192];
char lchrArrDirIp[28];
int lintPuerto,lintSocket;
gPtrFleArchivoLog=stdout;
if((lFlePtrArchivo=ArchivoLectura(pchrPtrArgv)))
{
   if((SiscomLeeLineaArchivo(lFlePtrArchivo,lchrArrCadena)))
   {
	LogSiscom("%s",lchrArrCadena);
	DatosServidor(pchrPtrArgv,lchrArrDirIp,&lintPuerto);

	if((lintSocket=SiscomConectateCliente(lchrArrDirIp,lintPuerto,&lchrPtrEdoConexion))>0)
	{
	    write(lintSocket,lchrArrCadena,strlen(lchrArrCadena));

	}
   }
}
}

void DatosServidor(char **pchrPtrArgv,char *pchrPtrDirIp,int *pintPtrPuerto)
{
      strcpy(pchrPtrDirIp,*(pchrPtrArgv+2));
      *pintPtrPuerto=atoi(*(pchrPtrArgv+3));

}
FILE *ArchivoLectura(char **pchrPtrArgv)
{
FILE *lFlePtrArchivo;

if(*(pchrPtrArgv+1))
{
if((lFlePtrArchivo=fopen(*(pchrPtrArgv+1),"r")))
   return lFlePtrArchivo;
else
{
   LogSiscom("NO se encontro el archivo:%s",*(pchrPtrArgv+1));
   return 0;
}
}
else
  return stdin;
}
