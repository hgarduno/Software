#include <zSiscomEnviaArchivo.h>
#include <zSiscomConexion.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


/* Jueves 25 de dicimebre del 2014 
 * Para el envio de archivos atraves del socket
 * ademas de los cambios en la informacion del protocolo 
 * para poder enviar unsigned char datos, se define un 
 * protocolo de envio de los bloques del archivo.
 *
 * 0000000000 ----> Numero de bloques a enviar 
 * 0000000000 ----> tamano del bloque a enviar 
 * xxxxxxxxxxxxxxxxx ----> Datos a enviar en unsigned char *
 */
zSiscomEnviaArchivo::zSiscomEnviaArchivo(const char *pchrPtrNombre,
					 zSiscomConexion *pzSiscomConexion):
				zSiscomArchivo(pchrPtrNombre),
				zSiscomConexionN(pzSiscomConexion)
{
}
void zSiscomEnviaArchivo::Envia()
{
zSiscomRegistro *lzSiscomRegBloque;
Caracteres(zSiscomArchivo::NNodos());
for(lzSiscomRegBloque=Primer();
    lzSiscomRegBloque;
    lzSiscomRegBloque=Siguiente())
   Caracteres(lzSiscomRegBloque);

}
void zSiscomEnviaArchivo::Caracteres(zSiscomRegistro *pzSiscomRegistro)
{
int lintTamano=atoi((const char *)pzSiscomRegistro->Campo("Tamano"));
int lintNBytes;
  Caracteres(lintTamano);
  if((lintNBytes=write(zSiscomConexionN->Socket(),pzSiscomRegistro->Campo("Nodo"),lintTamano))==lintTamano)
  {
  }
  else
  {
     printf("Error se enviaron solo %d bytes\n",lintNBytes);
  }
}
void zSiscomEnviaArchivo::Caracteres(const char *pchrPtrEnvio)
{
int lintTamano=strlen(pchrPtrEnvio);
if(write(zSiscomConexionN->Socket(),pchrPtrEnvio,lintTamano)==lintTamano)
{

}
else
{

}

}

void zSiscomEnviaArchivo::Caracteres(int pintDato)
{
char lchrArrDato[11];
sprintf(lchrArrDato,"%010d",pintDato);
Caracteres(lchrArrDato);
}
