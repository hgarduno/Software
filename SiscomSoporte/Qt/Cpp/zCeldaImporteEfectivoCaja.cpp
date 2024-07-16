#include <zCeldaImporteEfectivoCaja.h>
#include <zSiscomCampo.h>

zCeldaImporteEfectivoCaja::zCeldaImporteEfectivoCaja(int pintFila,
						     int pintColumna,
						     const char *pchrPtrColor):
						     intFila(pintFila),
						     intColumna(pintColumna)
{
(*this)				<<
new zSiscomCampo("Color",(const unsigned char *)pchrPtrColor);

}

int zCeldaImporteEfectivoCaja::Columna()
{
return intColumna;

}

int zCeldaImporteEfectivoCaja::Fila()
{
return intFila;
}
