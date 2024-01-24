#ifndef __SISCOMOPERACIONESDIRECTORIOS_H__
#define __SISCOMOPERACIONESDIRECTORIOS_H__
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct NmbArchivo
{
 char chrArrArchivo[256];
 char chrArrDirectorio[1024];
 off_t lngTamano;

}STCNmbArchivo;
typedef struct NmbsArchivo
{
	STCNmbArchivo SNArchivo;
	struct NmbsArchivo *NMSArchivoSig;
	struct NmbsArchivo *NMSArchivoAnt;
}LTANmbsArchivo;
void SiscomObtenNombre(char *);
void SiscomCopiaNombreArchivo(const char *,const char *,STCNmbArchivo *);
void SiscomCreaNodoArchivo(STCNmbArchivo,LTANmbsArchivo **);
void SiscomAnexaNodoArchivo(STCNmbArchivo,LTANmbsArchivo **,LTANmbsArchivo **);
void SiscomBuscaArchivos(const char *,const char *,const char *,LTANmbsArchivo **,LTANmbsArchivo **);
int SiscomEsDirectorio(const char *);
void SiscomEliminaArchivoLista(LTANmbsArchivo *,LTANmbsArchivo *);
#endif
