#include <zExistenciaBodega.h>
#include <zBodega.h>

#include <zSiscomCampo.h>

zExistenciaBodega::zExistenciaBodega(zBodega *pzBodega,
				     const char *pchrPtrCveProducto,
				     const char *pchrPtrExistencia)
{

  (*this)  									<<
  new zSiscomCampo("Bodega",pzBodega) 						<<
  new zSiscomCampo("CveProducto",(const unsigned char *)pchrPtrCveProducto)	<<
  new zSiscomCampo("Existencia",(const unsigned char *)pchrPtrExistencia) 	<<
  new zSiscomCampo("Cantidad");
}
zExistenciaBodega::zExistenciaBodega(zBodega *pzBodega) 
{
  (*this)  									<<
  new zSiscomCampo("Bodega",pzBodega) 						<<
  new zSiscomCampo("CveProducto")						<<
  new zSiscomCampo("Existencia")						<<
  new zSiscomCampo("Cantidad");
}
zExistenciaBodega::zExistenciaBodega()
{
  (*this)  				<<
  new zSiscomCampo("Bodega") 		<<
  new zSiscomCampo("CveProducto")	<<
  new zSiscomCampo("Existencia")	<<
  new zSiscomCampo("Cantidad");
}
void zExistenciaBodega::Producto(const char *pchrPtrCveProducto)
{
ActualizaCampo("CveProducto",(const unsigned char *)pchrPtrCveProducto);
}
void zExistenciaBodega::Bodega(zBodega *pzBodega)
{
  ActualizaCampo("Bodega",pzBodega);
}
void zExistenciaBodega::Existencia(const char *pchrPtrExistencia)
{
 ActualizaCampo("Existencia",(const unsigned char *)pchrPtrExistencia);
}

void zExistenciaBodega::Cantidad(const char *pchrPtrCantidad)
{
 ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}

zBodega *zExistenciaBodega::Bodega()
{
 return (zBodega *)AsociadoDelCampo("Bodega");
}
const char *zExistenciaBodega::Existencia()
{
  return (const char *)(*this)["Existencia"];
}
const char *zExistenciaBodega::Cantidad()
{
  return (const char *)(*this)["Cantidad"];
}
const char *zExistenciaBodega::Producto()
{
  return (const char *)(*this)["CveProducto"];
}
