#include <ClienteEnvioProtocolo.h>
#include <zSiscomConexion.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

FILE *gPtrFleArchivoLog;
zSiscomConexion *gzSiscomConexion;
int main(int pintArgc,
	 char **pchrPtrArgv)
{
FILE *lFlePtrArchivo;
char lchrArrBuffer[1024];
zSiscomConexion *lzSiscomConexion;

gPtrFleArchivoLog=stdout;
gzSiscomConexion=0;
lFlePtrArchivo=AbreArchivo(pintArgc,pchrPtrArgv);
LeeArchivo(lFlePtrArchivo,lchrArrBuffer);
lzSiscomConexion=Conectate(pchrPtrArgv);
Enviando(lchrArrBuffer,lzSiscomConexion);
}

zSiscomConexion *Conectate(char **pchrPtrArgv)
{
zSiscomConexion *lzSiscomCon;
lzSiscomCon=new zSiscomConexion(*(pchrPtrArgv+1),
				atoi(*(pchrPtrArgv+2)));
lzSiscomCon->Conectate();
return lzSiscomCon;
}
void Enviando(const char *pchrPtrCadena,
	      zSiscomConexion *pzSiscomConexion)
{
int lintTamano=strlen(pchrPtrCadena);

if(write(pzSiscomConexion->Socket(),pchrPtrCadena,lintTamano)==lintTamano)
{
   

}

  

}
FILE *AbreArchivo(int pintArgc,char **pchrPtrArgv)
{
return stdin;
}

void LeeArchivo(FILE *pFlePtrArchivo,
	        char *pchrPtrArchivo)
{

while((*pchrPtrArchivo=getc(pFlePtrArchivo))!=EOF)
  pchrPtrArchivo++;
*pchrPtrArchivo=0;

}
