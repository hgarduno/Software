#include <zCeldaPagoTarjeta.h>
#include <zSiscomCampo.h>
zCeldaPagoTarjeta::zCeldaPagoTarjeta(int pintFila,
			   int pintColumna,
			   const char *pchrPtrColor):intFila(pintFila),
			   		    intColumna(pintColumna)
{
(*this)								<<
new zSiscomCampo("Color",(const unsigned char *)pchrPtrColor);
}
int zCeldaPagoTarjeta::Fila()
{
  return intFila;
}

int zCeldaPagoTarjeta::Columna()
{
  return intColumna;
}

bool operator==(zCeldaPagoTarjeta &pzPTarjeta,
		zCeldaPagoTarjeta &pzPTarjeta1)
{
return ((pzPTarjeta.Fila()==pzPTarjeta1.Fila())    &&	
       (pzPTarjeta.Columna()==pzPTarjeta1.Columna()));

}
