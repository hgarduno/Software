#include <zSiscomRecibeArchivo.h>
#include <zSiscomConexion.h>

#include <zSiscomDesarrollo4.h>
#include <stdlib.h>
#include <unistd.h>
zSiscomRecibeArchivo::zSiscomRecibeArchivo(zSiscomConexion *pzSiscomConexion):
				zSiscomConexionN(pzSiscomConexion)
{
 Carga();
}
void zSiscomRecibeArchivo::Nodo()
{
unsigned char *lchrPtrBuffer;
int lintTamano=Caracteres(10),
    lintNBytesRegreso;
LogSiscom("Tamano del bloque %d",lintTamano);
lchrPtrBuffer=(unsigned char *)malloc(lintTamano);
CaracteresSinNulo(lintTamano,lchrPtrBuffer);

(*this) << zSiscomArchivo::NodoArchivo(lchrPtrBuffer,lintTamano);
}
void zSiscomRecibeArchivo::Carga()
{
int lintNBloques=Caracteres(10),
    lintContador;
LogSiscom("Se leeran %d Bloques",lintNBloques);
for(lintContador=0; 
    lintContador<lintNBloques;
    lintContador++)
  Nodo();  

}
int zSiscomRecibeArchivo::Caracteres(int pintNBytes)
{
unsigned char lchrArrBuffer[25];
   Caracteres(pintNBytes,lchrArrBuffer);
 
 return atoi((const char *)lchrArrBuffer);
}
void zSiscomRecibeArchivo::Caracteres(int pintBytes,
				      unsigned char *pchrPtrRegreso)
{
int lintNBytesLeidos;
    if((lintNBytesLeidos=read(zSiscomConexionN->Socket(),
    			    pchrPtrRegreso,
			    pintBytes))!=pintBytes)
    {
	LogSiscom("solo se leyeron %d bytes",lintNBytesLeidos);       

    }
    else
     *(pchrPtrRegreso+pintBytes)=0;
}

void zSiscomRecibeArchivo::CaracteresSinNulo(int pintBytes,
				      unsigned char *pchrPtrRegreso)
{
int lintNBytesLeidos;
    if((lintNBytesLeidos=read(zSiscomConexionN->Socket(),
    			    pchrPtrRegreso,
			    pintBytes))!=pintBytes)
    {
	LogSiscom("solo se leyeron %d bytes",lintNBytesLeidos);       

    }
}
