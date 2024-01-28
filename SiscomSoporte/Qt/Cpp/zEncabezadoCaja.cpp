#include <zEncabezadoCaja.h>
#include <zSiscomCampo.h>


#include <string.h>

zEncabezadoCaja::zEncabezadoCaja(int pintFila,
				 int pintColumna,
				 const char *pchrPtrNombre,
				 const char *pchrPtrColor,
				 const char *pchrPtrValor):
				 intFila(pintFila),
				 intColumna(pintColumna)
{
(*this)								<<
new zSiscomCampo("Nombre",(const unsigned char *)pchrPtrNombre)	<<
new zSiscomCampo("Color",(const unsigned char *)pchrPtrColor)	<<
new zSiscomCampo("Valor",(const unsigned char *)pchrPtrValor);
}
int zEncabezadoCaja::Fila()
{
  return intFila;
}
int zEncabezadoCaja::Columna()
{
  return intColumna;
}

const char *zEncabezadoCaja::Nombre()
{
  return (const char *)(*this)["Nombre"];
}
const char *zEncabezadoCaja::Color()
{
  return (const char *)(*this)["Color"];
}

const char *zEncabezadoCaja::Valor()
{
  return (const char *)(*this)["Valor"];
}

bool operator==(zEncabezadoCaja &pzEncabezado1,
		zEncabezadoCaja &pzEncabezado2)
{
   return !strcmp(pzEncabezado1.Nombre(),
   		  pzEncabezado2.Nombre());
}
bool operator==(const char *pchrPtrNombre,zEncabezadoCaja &pzEncabezado)
{
   return pzEncabezado.Nombre() && 
          !strcmp(pchrPtrNombre,pzEncabezado.Nombre());
}
