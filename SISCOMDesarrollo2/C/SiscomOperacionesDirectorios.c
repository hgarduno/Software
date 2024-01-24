#include <SiscomOperacionesDirectorios.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
void SiscomObtenNombre(char *pchrPtrNombre)
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
void SiscomCreaNodoArchivo(STCNmbArchivo pSTCNmbArchivo,
			   LTANmbsArchivo **pLTANsArchivo)
{
	*pLTANsArchivo=(LTANmbsArchivo *)malloc(sizeof(LTANmbsArchivo));
	(*pLTANsArchivo)->SNArchivo=pSTCNmbArchivo;
	(*pLTANsArchivo)->NMSArchivoSig=0;
	(*pLTANsArchivo)->NMSArchivoAnt=0;
}
void SiscomAnexaNodoArchivo(STCNmbArchivo pSTCNmbArchivo,
			    LTANmbsArchivo **pLTANsArchivoPrim,
			    LTANmbsArchivo **pLTANsArchivoAct)
{
LTANmbsArchivo *lLTANsArchivo=0;
	SiscomCreaNodoArchivo(pSTCNmbArchivo,&lLTANsArchivo);
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
			      STCNmbArchivo *pSTCNmbArchivo)
{
	strcpy(pSTCNmbArchivo->chrArrDirectorio,pchrPtrDirectorio);
	strcpy(pSTCNmbArchivo->chrArrArchivo,pchrPtrArchivo);
}
void SiscomEliminaArchivoLista(LTANmbsArchivo *pLTANArchivoAnterior,
			       LTANmbsArchivo *pLTANArchivo)
{
LTANmbsArchivo *lLTANArchivo=pLTANArchivo->NMSArchivoSig;



}

void SiscomBuscaArchivos(const char *pchrPtrDirectorio,
			 const char *pchrPtrCadenaNombre,
			 const char *pchrPtrExtension,
			 LTANmbsArchivo **pLNArchivoPrim,
			 LTANmbsArchivo **pLNArchivoActual)
{

struct dirent **lSDRegreso;
int lintNRegreso;
int lintContador;
char lchrArrArchivo[1024];
STCNmbArchivo lSTCNmbArchivo;
	
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
	     if(strstr(lchrArrArchivo,pchrPtrCadenaNombre) &&
	        strstr(lchrArrArchivo,pchrPtrExtension))
	     {
	     SiscomObtenNombre(lchrArrArchivo); 
	    
	     SiscomCopiaNombreArchivo(pchrPtrDirectorio,
	     			      lchrArrArchivo,
				      &lSTCNmbArchivo);
	     SiscomAnexaNodoArchivo(lSTCNmbArchivo,
	     			    pLNArchivoPrim,
				    pLNArchivoActual);
	     }
	     

	  }

	}



}
			    



