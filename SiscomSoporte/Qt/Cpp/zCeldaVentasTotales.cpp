#include <zCeldaVentasTotales.h>
#include <zSiscomCampo.h>
zCeldaVentasTotales::zCeldaVentasTotales(int pintFila,
					 int pintColumna,
					 const char *pchrPtrColor):
					 intFila(pintFila),
					 intColumna(pintColumna)
{
(*this)								<<
new zSiscomCampo("Color",(const unsigned char *)pchrPtrColor) ;
}

int zCeldaVentasTotales::Columna()
{
 return intColumna;
}
int zCeldaVentasTotales::Fila()
{
return intFila;
}
