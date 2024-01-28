#include <zEncabezadosCaja.h>
#include <zEncabezadoCaja.h>

#include <zSiscomDesarrollo4.h>
zEncabezadosCaja::zEncabezadosCaja()
{

}

zEncabezadosCaja &zEncabezadosCaja::operator<<(zEncabezadoCaja *pzEncaCaja)
{
    Agrega(pzEncaCaja);
    return *this;
}
zEncabezadosCaja &zEncabezadosCaja::operator+=(zEncabezadosCaja &pzEncaSCaja)
{
zEncabezadoCaja *lzEncaCaja;
for(lzEncaCaja=(zEncabezadoCaja *)pzEncaSCaja.Primer();
    lzEncaCaja;
    lzEncaCaja=(zEncabezadoCaja *)pzEncaSCaja.Siguiente())
  Agrega(lzEncaCaja);

  return *this;
}
zEncabezadoCaja *zEncabezadosCaja::Encabezado(const char *pchrPtrNombre)
{
zEncabezadoCaja *lzEncabezado;
for(lzEncabezado=(zEncabezadoCaja *)Primer(); 
    lzEncabezado;
    lzEncabezado=(zEncabezadoCaja *)Siguiente())
{
if( pchrPtrNombre==(*lzEncabezado))
   return lzEncabezado;
}


return 0;
}
