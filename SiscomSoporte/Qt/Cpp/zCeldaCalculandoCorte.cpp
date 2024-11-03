#include <zCeldaCalculandoCorte.h>
#include <zSiscomCampo.h>

zCeldaCalculandoCorte::zCeldaCalculandoCorte(int pintFila,
					     int pintColumna,
					     const char *pchrPtrColor):
					     intFila(pintFila),
					     intColumna(pintColumna)
{
(*this)					<<
new zSiscomCampo("Color",(const unsigned char *)pchrPtrColor);
}

int zCeldaCalculandoCorte::Fila()
{
return intFila;
}

int zCeldaCalculandoCorte::Columna()
{
 return intColumna;
}
