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

}SiscomArchivoDirectorio;
typedef struct NmbsArchivo
{
	SiscomArchivoDirectorio SNArchivo;
	struct NmbsArchivo *NMSArchivoSig;
	struct NmbsArchivo *NMSArchivoAnt;
}SiscomArchivosDirectorio;
void SiscomObtenNombreArchivo(char *);
void SiscomCopiaNombreArchivo(const char *,const char *,SiscomArchivoDirectorio *);
void SiscomCreaNodoArchivo(SiscomArchivoDirectorio,SiscomArchivosDirectorio **);
void SiscomAnexaNodoArchivo(SiscomArchivoDirectorio,SiscomArchivosDirectorio **,SiscomArchivosDirectorio **);
void SiscomBuscaArchivos(const char *,
			 const char *,
			 const char *,
			 SiscomArchivosDirectorio **,
			 SiscomArchivosDirectorio **);
int SiscomEsDirectorio(const char *);
void SiscomEliminaArchivoLista(SiscomArchivosDirectorio *,SiscomArchivosDirectorio *);
#endif
