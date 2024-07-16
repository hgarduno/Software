#include <zCeldaImporteTransferencias.h>
#include <zSiscomCampo.h>
zCeldaImporteTransferencias::zCeldaImporteTransferencias(int pintFila,
							 int pintColumna,
							 const char *pchrPtrColor):
							 intFila(pintFila),
							 intColumna(pintColumna)
{
(*this)						<<
new zSiscomCampo("Color",(const unsigned char *)pchrPtrColor);
}

int zCeldaImporteTransferencias::Fila()
{
	return intFila;
}

int zCeldaImporteTransferencias::Columna()
{
	return intColumna;
}
bool operator==(zCeldaImporteTransferencias &pzCImporteT1,
		zCeldaImporteTransferencias &pzCImporteT2)
{
return ((pzCImporteT1.Fila()==pzCImporteT2.Fila()) && 
        (pzCImporteT1.Columna()==pzCImporteT2.Columna()));
}
