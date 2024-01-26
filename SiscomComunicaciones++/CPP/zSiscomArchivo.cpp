#include <zSiscomArchivo.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistro.h>

#include <stdlib.h>
zSiscomArchivo::zSiscomArchivo(const char *pchrPtrArchivo):
			chrPtrArchivo(pchrPtrArchivo)
{
Carga(pchrPtrArchivo);
}
zSiscomArchivo::zSiscomArchivo()
{

}

void zSiscomArchivo::Carga(const char *pchrPtrArchivo)
{
FILE *lFlePtrArchivo;
unsigned char lchrArrBuffer[1025];
unsigned char *lchrPtrBuffer,*lchrPtrPaso;
int lintTamano;
int lintTamanoTotal=0;
int lintTamanoBloque=1024;
int lintContador;
if((lFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
{
	do
	{
	lchrPtrPaso=lchrPtrBuffer=(unsigned char *)malloc(lintTamanoBloque);
	for(lintContador=0;
	    !feof(lFlePtrArchivo) && 
	     lintContador<lintTamanoBloque;
	    lintContador++,
	    lchrPtrBuffer++)
	   *lchrPtrBuffer=getc(lFlePtrArchivo); 
	(*this) << NodoArchivo(lchrPtrPaso,lintContador);
	}while(!feof(lFlePtrArchivo));
fclose(lFlePtrArchivo);
}
else
{

}
}

zSiscomRegistro *zSiscomArchivo::NodoArchivo(const unsigned char *pchrPtrLectura,
					     int pintTamano)
{
char lchrArrTamano[25];
zSiscomRegistro *lzSiscomRegNodo=new zSiscomRegistro;
zSiscomCampo *lzSisCampoNodo=new zSiscomCampo;
sprintf(lchrArrTamano,"%d",pintTamano);
  lzSisCampoNodo->Nombre("Nodo");
  lzSisCampoNodo->Dato(pchrPtrLectura);
(*lzSiscomRegNodo) 	<< 
   lzSisCampoNodo 	<<
   new zSiscomCampo("Tamano",(unsigned char *)lchrArrTamano);
return lzSiscomRegNodo;
}
void zSiscomArchivo::Copia(const char *pchrPtrDestino)
{
FILE *lFlePtrArchivo;
zSiscomRegistro *lzSisRegistro;
const unsigned char *lchrPtrBuffer;
int lintBytes;
int lintContador;
if((lFlePtrArchivo=fopen(pchrPtrDestino,"w")))
{
for(lzSisRegistro=Primer();
    lzSisRegistro;
    lzSisRegistro=Siguiente())
{
  lintBytes=atoi((const char *)lzSisRegistro->Campo("Tamano"));
  lchrPtrBuffer=lzSisRegistro->Campo("Nodo");
    fwrite(lzSisRegistro->Campo("Nodo"),lintBytes,1,lFlePtrArchivo);
}
fclose(lFlePtrArchivo);
}
}
