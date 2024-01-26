#include <ClienteEnvio.h>
#include <zSiscomDesarrollo4.h>

FILE *gPtrFleArchivoLog;
void *gzSiscomConexion;
int main(int pintArgc,
	 char **pchrPtrArgv)
{
FILE *lFlePtrArchivo;
char lchrArrBuffer[1024];
gPtrFleArchivoLog=stdout;
if((lFlePtrArchivo=ObtenArchivo(pchrPtrArgv)))
{
   if(SiscomLeeLineaArchivo(lFlePtrArchivo,
   			    lchrArrBuffer))
   {
	LogSiscom("La Linea a enviar(%s)",
		   lchrArrBuffer);

   }
   			    

}


}

FILE *ObtenArchivo(char **pchrPtrArgv)
{
FILE *lFlePtrArchivo;
    if(*(pchrPtrArgv+1))
    {
	 if((lFlePtrArchivo=fopen(*(pchrPtrArgv+1),"r")))
	  return lFlePtrArchivo;
	  else
		LogSiscom("No se pudo abrir el archivo:%s",
			  *(pchrPtrArgv+1));
    }
    else
    return stdin;


}
