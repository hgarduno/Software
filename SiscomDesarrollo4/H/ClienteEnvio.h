#ifndef __CLIENTEENVIO_H__
#define __CLIENTEENVIO_H__
#include <stdio.h>


FILE *ArchivoLectura(char **pchrPtrArgv);
void DatosServidor(char **pchrPtrArgv,char *pchrPtrDirIp,int *pintPtrPuerto);

#endif
