#include <zInventario.h>
#include <zSiscomCampo.h>
#include <zProducto.h>
#include <zProductos.h>
zInventario::zInventario(const char *pchrPtrIdInventario,
			 const char *pchrPtrIdMotivoInventario)
{
  (*this)	<< 
  new zSiscomCampo("IdInventario",(const unsigned char *)pchrPtrIdInventario)		<<
  new zSiscomCampo("IdMotivoInventario",(const unsigned char *)pchrPtrIdMotivoInventario)	<<
  new zSiscomCampo("Fecha")	<<
  new zSiscomCampo("Producto")   <<
  new zSiscomCampo("Productos");
}

void zInventario::Producto(zProducto *pzProducto)
{
  zSiscomRegistros *lzSisRegsProducto=AsociadosDelCampo("Producto");
  if(lzSisRegsProducto)
    lzSisRegsProducto->Libera();
  AsociadoAlCampo("Productos",pzProducto);
  AsociadoAlCampo("Producto",pzProducto);
}

void zInventario::Productos(zProductos *pzProductos)
{
  zSiscomRegistros *lzSisRegsProductos=AsociadosDelCampo("Productos");
  if(lzSisRegsProductos)
    lzSisRegsProductos->Libera();
  AsociadosAlCampo("Productos",pzProductos);
}

void zInventario::IdMotivoInventario(const char * pchrPtrMotivoInventario)
{
    ActualizaCampo("IdMotivoInventario",(const unsigned char *)pchrPtrMotivoInventario);
}

