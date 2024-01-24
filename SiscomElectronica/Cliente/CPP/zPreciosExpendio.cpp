#include <zPreciosExpendio.h>
#include <zEmpresa.h>
#include <zSiscomCampo.h>
zPreciosExpendio::zPreciosExpendio(zEmpresa *pzExpendio)
{
  (*this) 
  << new zSiscomCampo("Expendio",pzExpendio) 
  << new zSiscomCampo("Productos");
}
void zPreciosExpendio::ProductosPrecio(zSiscomRegistros *pzSisRegsProductosPre)
{
  AsociadosAlCampo("Productos",pzSisRegsProductosPre);
}
zEmpresa *zPreciosExpendio::Expendio()
{
  return (zEmpresa *)AsociadoDelCampo("Expendio"); 
}

zSiscomRegistros *zPreciosExpendio::Precios()
{
  return AsociadosDelCampo("Productos");
}
