#include <SiscomOperacionesDirectorios.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
void SiscomObtenNombreArchivo(char *pchrPtrNombre)
{
int lintContador,
    lintContadorJ,
    lintPosicionSepDirectorio;
     for(lintContador=0;pchrPtrNombre[lintContador];lintContador++)
      if(pchrPtrNombre[lintContador]=='/')
       lintPosicionSepDirectorio=lintContador+1;
     strcpy(pchrPtrNombre,pchrPtrNombre+lintPosicionSepDirectorio);
}
int SiscomEsDirectorio(const char *pchrPtrDirectorio)
{
	return (int )opendir(pchrPtrDirectorio); 
}
void SiscomCreaNodoArchivo(SiscomArchivoDirectorio pSiscomArchivoDirectorio,
			   SiscomArchivosDirectorio **pLTANsArchivo)
{
	*pLTANsArchivo=(SiscomArchivosDirectorio *)malloc(sizeof(SiscomArchivosDirectorio));
	(*pLTANsArchivo)->SNArchivo=pSiscomArchivoDirectorio;
	(*pLTANsArchivo)->NMSArchivoSig=0;
	(*pLTANsArchivo)->NMSArchivoAnt=0;
}
void SiscomAnexaNodoArchivo(SiscomArchivoDirectorio pSiscomArchivoDirectorio,
			    SiscomArchivosDirectorio **pLTANsArchivoPrim,
			    SiscomArchivosDirectorio **pLTANsArchivoAct)
{
SiscomArchivosDirectorio *lLTANsArchivo=0;
	SiscomCreaNodoArchivo(pSiscomArchivoDirectorio,&lLTANsArchivo);
	if(!*pLTANsArchivoPrim)
	 *pLTANsArchivoPrim=*pLTANsArchivoAct=lLTANsArchivo;
	 else
	 {
	  (*pLTANsArchivoAct)->NMSArchivoSig=lLTANsArchivo;
	  (*pLTANsArchivoAct)=(*pLTANsArchivoAct)->NMSArchivoSig;
	 }
}
void SiscomCopiaNombreArchivo(const char *pchrPtrDirectorio,
			      const char *pchrPtrArchivo,
			      SiscomArchivoDirectorio *pSiscomArchivoDirectorio)
{
	strcpy(pSiscomArchivoDirectorio->chrArrDirectorio,pchrPtrDirectorio);
	strcpy(pSiscomArchivoDirectorio->chrArrArchivo,pchrPtrArchivo);
}
void SiscomEliminaArchivoLista(SiscomArchivosDirectorio *pLTANArchivoAnterior,
			       SiscomArchivosDirectorio *pLTANArchivo)
{
SiscomArchivosDirectorio *lLTANArchivo=pLTANArchivo->NMSArchivoSig;



}

void SiscomBuscaArchivos(const char *pchrPtrDirectorio,
			 const char *pchrPtrCadenaNombre,
			 const char *pchrPtrExtension,
			 SiscomArchivosDirectorio **pLNArchivoPrim,
			 SiscomArchivosDirectorio **pLNArchivoActual)
{

struct dirent **lSDRegreso;
int lintNRegreso;
int lintContador;
char lchrArrArchivo[1024];
SiscomArchivoDirectorio lSiscomArchivoDirectorio;
	
	if((lintNRegreso=scandir(pchrPtrDirectorio,
				 &lSDRegreso,
				 0,
				 alphasort))>0)
	{
	  for(lintContador=0;
	      lintContador<lintNRegreso;
	      lintContador++)
	  {
	    sprintf(lchrArrArchivo,
	    	    "%s/%s",
		    pchrPtrDirectorio,
		    lSDRegreso[lintContador]->d_name);
	    if(strcmp(lSDRegreso[lintContador]->d_name, ".") &&
	       strcmp(lSDRegreso[lintContador]->d_name,"..") &&
	       	  
		SiscomEsDirectorio(lchrArrArchivo))
		SiscomBuscaArchivos(lchrArrArchivo,
				    pchrPtrCadenaNombre,
				    pchrPtrExtension,
				    pLNArchivoPrim,
				    pLNArchivoActual);
	    else
	     if(/*strstr(lchrArrArchivo,pchrPtrCadenaNombre) && */
	        strstr(lchrArrArchivo,pchrPtrExtension))
	     {
	     SiscomObtenNombreArchivo(lchrArrArchivo); 
	    
	     SiscomCopiaNombreArchivo(pchrPtrDirectorio,
	     			      lchrArrArchivo,
				      &lSiscomArchivoDirectorio);
	     SiscomAnexaNodoArchivo(lSiscomArchivoDirectorio,
	     			    pLNArchivoPrim,
				    pLNArchivoActual);
	     }
	     

	  }

	}



}
			    



