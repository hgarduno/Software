#include <zDenominacion.h>
#include <zSiscomCampo.h>
#include <string.h>

zDenominacion::zDenominacion(int pintFila,
			     int pintColumna,
			     const char *pchrPtrValor,
			     const char *pchrPtrCantidad,
			     const char *pchrPtrImporte,
			     const char *pchrPtrColor):
			     intFila(pintFila),
			     intColumna(pintColumna)
{
(*this)									<<
new zSiscomCampo("Valor",(const unsigned char *)pchrPtrValor)		<<
new zSiscomCampo("Cantidad",(const unsigned char *)pchrPtrCantidad)	<<
new zSiscomCampo("Importe",(const unsigned char *)pchrPtrImporte)	<<
new zSiscomCampo("Color",(const unsigned char *)pchrPtrColor);
}
zDenominacion::zDenominacion(zSiscomRegistro *pzSisRegDato)
{
(*this)									<<
new zSiscomCampo("Valor",(*pzSisRegDato)["valor"])			<<
new zSiscomCampo("Cantidad",(*pzSisRegDato)["cantidad"])		<<
new zSiscomCampo("Importe",(*pzSisRegDato)["importe"])			<<
new zSiscomCampo("Color");
}
int zDenominacion::Fila()
{
   return intFila;
}

int zDenominacion::Columna()
{
  return intColumna;
}

const char *zDenominacion::Valor()
{

	return (const char *)(*this)["Valor"];
}

const char *zDenominacion::Cantidad()
{

	return (const char *)(*this)["Cantidad"];
}
const char *zDenominacion::Importe()
{

	return (const char *)(*this)["Importe"];
}
const char *zDenominacion::Color()
{

	return (const char *)(*this)["Color"];
}

void zDenominacion::Cantidad(const char *pchrPtrCantidad)
{
     ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
void zDenominacion::Importe(const char *pchrPtrImporte)
{
   ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}
bool operator==(zDenominacion &pzDenoA,zDenominacion &pzDenoB)
{
   return !strcmp(pzDenoA.Valor(),pzDenoB.Valor());
}
