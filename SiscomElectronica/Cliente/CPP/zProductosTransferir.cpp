#include <zProductosTransferir.h>
#include <zProductoTransferir.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
#include <zProducto.h>
zProductosTransferir::zProductosTransferir()
{
   (*this) 				<< 
   new zSiscomCampo("Productos") 	<<
   new zSiscomCampo("ExpendioD")	<<
   new zSiscomCampo("ExpendioO")	<<
   new zSiscomCampo("IdEmpleado");
   
}
void zProductosTransferir::Agrega(zProductoTransferir *pzProducto)
{
    AsociadoAlCampo("Productos",pzProducto); 
}
void zProductosTransferir::ExpendioD(const char *pchrPtrIdExpendioD)
{
     ActualizaCampo("ExpendioD",(const unsigned char *)pchrPtrIdExpendioD);
}

void zProductosTransferir::ExpendioO(const char *pchrPtrIdExpendioO)
{
     ActualizaCampo("ExpendioO",(const unsigned char *)pchrPtrIdExpendioO);
}
void zProductosTransferir::IdEmpleado(const char *pchrPtrIdEmpleado)
{
	ActualizaCampo("IdEmpleado",(const unsigned char *)pchrPtrIdEmpleado);
}
zSiscomRegistros *zProductosTransferir::Productos()
{
  return AsociadosDelCampo("Productos");
}
void zProductosTransferir::EliminaProducto(int pintNProducto)
{
   Productos()->Elimina(pintNProducto); 
}
void zProductosTransferir::Cantidad(int pintNProducto,const char *pchrPtrCantidad)
{
zSiscomRegistro *lzSisRegProducto;
zSiscomRegistros *lzSisRegsProductos;
if((lzSisRegsProductos=Productos()))
{
  if((lzSisRegProducto=(*lzSisRegsProductos)[pintNProducto]))
  lzSisRegProducto->ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
}
