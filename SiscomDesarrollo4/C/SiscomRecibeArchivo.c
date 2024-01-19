#include <SiscomRecibeArchivo.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomDesarrolloMacros.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

void SiscomMemoriaNodoBloqueArchivo(const SiscomBloqueArchivo *pSiscomBloArcPtrDato,
				    SiscomBloqueArchivoL **pSiscomBloArcLPtrDato)
{

 if((*pSiscomBloArcLPtrDato=(SiscomBloqueArchivoL *)malloc(sizeof(SiscomBloqueArchivoL))))
 {
   (*pSiscomBloArcLPtrDato)->zSiscomBloqueArchivo=*pSiscomBloArcPtrDato;
   (*pSiscomBloArcLPtrDato)->SiscomBloArcPtrSig=0;
   (*pSiscomBloArcLPtrDato)->intNBloques=0;
 }

}

void SiscomNodoBloqueArchivo(const SiscomBloqueArchivo *pSiscomBloArPtrDato,
			     SiscomBloqueArchivoL **pSiscomBloArLPtrPrim,
			     SiscomBloqueArchivoL **pSiscomBloArLPtrAct)
{
SiscomBloqueArchivoL *lSiscomBloArLPtrDato=0;
SiscomMemoriaNodoBloqueArchivo(pSiscomBloArPtrDato,&lSiscomBloArLPtrDato);
if(!*pSiscomBloArLPtrPrim)
*pSiscomBloArLPtrPrim=*pSiscomBloArLPtrAct=lSiscomBloArLPtrDato;
else
{
 (*pSiscomBloArLPtrAct)->SiscomBloArcPtrSig=lSiscomBloArLPtrDato;
 (*pSiscomBloArLPtrAct)=(*pSiscomBloArLPtrAct)->SiscomBloArcPtrSig;
}
 (*pSiscomBloArLPtrPrim)->intNBloques++; 

}

void SiscomLeeBloque(int pintSocket,
		     SiscomBloqueArchivo *pSiscomBloArBloque)
{
char lchrArrBuffer[20];
int lintNBytes,lintContador;
pSiscomBloArBloque->intTamanoBloque=SiscomLeeCaracteresSocketInt(pintSocket,
								 10,
								 lchrArrBuffer);
if((pSiscomBloArBloque->chrPtrBloque=(unsigned char *)malloc(pSiscomBloArBloque->intTamanoBloque+10)))
{
/*
 if((lintNBytes=read(pintSocket,
      pSiscomBloArBloque->chrPtrBloque,
      pSiscomBloArBloque->intTamanoBloque))!=pSiscomBloArBloque->intTamanoBloque)
   LogSiscom("Se leyeron solo %d Bytes",lintNBytes);

*/
for(lintContador=0;
    lintContador<pSiscomBloArBloque->intTamanoBloque;
    lintContador++)
    read(pintSocket,pSiscomBloArBloque->chrPtrBloque+lintContador,1);
}


}


void SiscomRecibeArchivo(int pintSocket,
			 SiscomBloqueArchivoL **pSiscomBloArLPtrArchivo)
{
SiscomBloqueArchivoL *lSiscomBloArLPtrActual=0;
SiscomBloqueArchivo *lSiscomBloArDato;
char lchrArrBuffer[20];
int lintNBloques=SiscomLeeCaracteresSocketInt(pintSocket,10,lchrArrBuffer);
int lintContador;
*pSiscomBloArLPtrArchivo=0;
for(lintContador=0;
    lintContador<lintNBloques;
    lintContador++)
{
   lSiscomBloArDato=(SiscomBloqueArchivo *)malloc(sizeof(SiscomBloqueArchivo));
   SiscomLeeBloque(pintSocket,lSiscomBloArDato);
   SiscomNodoBloqueArchivo(lSiscomBloArDato,
   			   pSiscomBloArLPtrArchivo,
			   &lSiscomBloArLPtrActual);

}

}
/* Jueves 25 de diciembre del 2014
 * Se debera programar otra funcion que 
 * pueda crear un archivo con permisos de ejecucion
 */
void SiscomEscribeArchivoSocket(const char *pchrPtrNombre,
				SiscomBloqueArchivoL *pSiscomBloArLPtrDato)
{
FILE *lFlePtrArchivo;
if((lFlePtrArchivo=fopen(pchrPtrNombre,"w")))
{
LogSiscom("Se Abrio el archivo:%s",pchrPtrNombre);
  for(;
       pSiscomBloArLPtrDato;
      pSiscomBloArLPtrDato=pSiscomBloArLPtrDato->SiscomBloArcPtrSig)
      fwrite(pSiscomBloArLPtrDato->zSiscomBloqueArchivo.chrPtrBloque,
      	     pSiscomBloArLPtrDato->zSiscomBloqueArchivo.intTamanoBloque,
	     1,
	     lFlePtrArchivo);
fclose(lFlePtrArchivo);
}
else
LogSiscom("No se pudo abrir el archivo:%s",pchrPtrNombre);
}

int SiscomTamanoBloque(SiscomBloqueArchivoL *pSiscomBloArLPtrDato)
{
return pSiscomBloArLPtrDato->zSiscomBloqueArchivo.intTamanoBloque;
}
const unsigned char *SiscomDatoBloqueArchivo(SiscomBloqueArchivoL *pSiscomBloArLPtrDato)
{
 return pSiscomBloArLPtrDato->zSiscomBloqueArchivo.chrPtrBloque;
}

int SiscomNumeroBloques(SiscomBloqueArchivoL *pSiscomBloArLPtrDato)
{
 return pSiscomBloArLPtrDato->intNBloques;
}
