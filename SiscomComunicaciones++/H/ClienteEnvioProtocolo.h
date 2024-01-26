#ifndef __CLIENTEENVIOPROTOCOLO_H__
#define __CLIENTEENVIOPROTOCOLO_H__
#include <stdio.h>


class zSiscomConexion;
void LeeArchivo(FILE *pFlePtrArchivo,char *pchrPtrArchivo);
FILE *AbreArchivo(int pintArgc,char **pchrPtrArgv);

zSiscomConexion *Conectate(char **pchrPtrArgv);
void Enviando(const char *pchrPtrCadena,
	      zSiscomConexion *pzSiscomConexion);

#endif
