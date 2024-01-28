#include <zGasto.h>
#include <zSiscomCampo.h>
zGasto::zGasto(int pintFila,int pintColumna):
				intFila(pintFila),
				intColumna(pintColumna)
{
(*this)					<<
new zSiscomCampo("Color")		<<
new zSiscomCampo("IdGasto")		<<
new zSiscomCampo("Gasto")		<<
new zSiscomCampo("Importe");
}
void zGasto::Gasto(const char *pchrPtrGasto)
{
   ActualizaCampo("Gasto",(const unsigned char *)pchrPtrGasto);
}

void zGasto::Importe(const char *pchrPtrImporte)
{
   ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}
void zGasto::Color(const char *pchrPtrColor)
{
   ActualizaCampo("Color",(const unsigned char *)pchrPtrColor);
}

const char *zGasto::Gasto()
{
   return (const char *)(*this)["Gasto"];
}

const char *zGasto::Importe()
{
   return (const char *)(*this)["Importe"];
}

const char *zGasto::Color()
{
   return (const char *)(*this)["Color"];
}
int zGasto::Fila()
{
   return intFila;
}

int zGasto::Columna()
{
   return intColumna;
}
