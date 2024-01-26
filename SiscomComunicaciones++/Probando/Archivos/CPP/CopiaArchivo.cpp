#include <CopiaArchivo.h>
#include <zSiscomArchivo.h>
FILE *gPtrFleArchivoLog;
void *gzSiscomConexion;
int main(int pintArgc,
	 char **pchrPtrArgv)
{
gPtrFleArchivoLog=stdout;
zSiscomArchivo lzSisArchivo(*(pchrPtrArgv+1));
printf("Se crearon %d Bloques para el archivo\n",
	lzSisArchivo.NNodos());
lzSisArchivo.Copia(*(pchrPtrArgv+2));
}
