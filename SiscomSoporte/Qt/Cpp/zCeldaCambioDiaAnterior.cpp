#include <zCeldaCambioDiaAnterior.h>
#include <zSiscomCampo.h>

zCeldaCambioDiaAnterior::zCeldaCambioDiaAnterior(int pintFila,
						 int pintColumna,
						 const char *pchrPtrColor):
						 intFila(pintFila),
						 intColumna(pintColumna)
{
(*this)								<<
new zSiscomCampo("Color",(const unsigned char *)pchrPtrColor) 	<<
new zSiscomCampo("Valor");

}
void zCeldaCambioDiaAnterior::Valor(const char *pchrPtrValor)
{
  ActualizaCampo("Valor",(const unsigned char *)pchrPtrValor);
}

const char *zCeldaCambioDiaAnterior::Valor()
{
 return (const char *)(*this)["Valor"];
}
int zCeldaCambioDiaAnterior::Columna()
{
  return intColumna;
}

int zCeldaCambioDiaAnterior::Fila()
{
 return intFila;

}
