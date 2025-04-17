#include <SiscomEnviaArchivo.h>
#include <SiscomDesarrolloMacros.h>
#include <unistd.h>


void SiscomEnviaArchivo(int pintSocket,SiscomBloqueArchivoL *pSiscomBloArLPtrDato)
{
char lchrArrBuffer[20];
int lintNBytesEnvio;
LogSiscom("Se enviaran %d Bloques\n",pSiscomBloArLPtrDato->intNBloques);

SiscomEnviaIntSocket(pintSocket,
		    10,
		    pSiscomBloArLPtrDato->intNBloques);
for(;
     pSiscomBloArLPtrDato;
     pSiscomBloArLPtrDato=pSiscomBloArLPtrDato->SiscomBloArcPtrSig)
{
 
 SiscomEnviaIntSocket(pintSocket,
 		       10,
		       SiscomTamanoBloque(pSiscomBloArLPtrDato));
   
 if((lintNBytesEnvio=write(pintSocket,
 			   SiscomDatoBloqueArchivo(pSiscomBloArLPtrDato),
			   SiscomTamanoBloque(pSiscomBloArLPtrDato)))!=SiscomTamanoBloque(pSiscomBloArLPtrDato))
 {
   LogSiscom("Se enviaron solo %d bytes de %d ",
   	      lintNBytesEnvio,
	      SiscomTamanoBloque(pSiscomBloArLPtrDato));

 }
}
}
