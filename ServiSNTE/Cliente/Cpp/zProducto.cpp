#include <zProducto.h>
#include <zCostos.h> 
#include <zCosto.h>
#include <zSiscomCampo.h>
#include <zDescuento.h>
#include <zCosto.h>
#include <zPrecio.h>
zProducto::zProducto()
{

}
zProducto::zProducto(zSiscomRegistro *pzSisProducto)
{
     (*this)=*((zProducto *)(pzSisProducto));
}
zProducto::zProducto(zSiscomRegistro *pzSisProducto,
		     const char *pchrPtrSerie,
		     const char *pchrPtrCantidad)
{
	(*this)=*((zProducto *)(pzSisProducto));
       (*this) 	<<
       new zSiscomCampo("Serie",(const unsigned char *)pchrPtrSerie)			<<
       new zSiscomCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
zProducto::zProducto(zSiscomRegistro *pzSisRegProveedor,
		     zSiscomRegistro *pzSisRegDepartamento,
		     const char *pchrPtrIdProducto,
		     const char *pchrPtrNombre,
		     const char *pchrPtrModelo,
		     const char *pchrPtrNumeroProducto)
{
   (*this) 				<<
   new zSiscomCampo("IdProveedor",(*pzSisRegProveedor)["idempresa"])		<<
   new zSiscomCampo("IdDepartamento",(*pzSisRegDepartamento)["iddepartamento"])	<<
   new zSiscomCampo("IdProducto",(const unsigned char *)pchrPtrIdProducto)	<<
   new zSiscomCampo("Nombre",(const unsigned char *)pchrPtrNombre)		<<
   new zSiscomCampo("Modelo",(const unsigned char *)pchrPtrModelo)		<<
   new zSiscomCampo("NumeroProducto",(const unsigned char *)pchrPtrNumeroProducto);

}
zProducto::zProducto(zSiscomRegistro *pzSisRegProveedor,
		     zSiscomRegistro *pzSisRegDepartamento,
		     const char *pchrPtrIdProducto,
		     const char *pchrPtrNombre,
		     const char *pchrPtrModelo,
		     const char *pchrPtrNumeroProducto,
		     const char *pchrPtrPrecio,
		     zDescuento *pzDescuento,
		     zCosto *pzCosto)
{
   (*this) 				<<
   new zSiscomCampo("IdProveedor",(*pzSisRegProveedor)["idempresa"])		<<
   new zSiscomCampo("IdDepartamento",(*pzSisRegDepartamento)["iddepartamento"])	<<
   new zSiscomCampo("IdProducto",(const unsigned char *)pchrPtrIdProducto)	<<
   new zSiscomCampo("Nombre",(const unsigned char *)pchrPtrNombre)		<<
   new zSiscomCampo("Modelo",(const unsigned char *)pchrPtrModelo)		<<
   new zSiscomCampo("NumeroProducto",(const unsigned char *)pchrPtrNumeroProducto) <<
   new zSiscomCampo("Precio",(const unsigned char *)pchrPtrPrecio);

   AgregaCampo("Descuento",pzDescuento);
   AgregaCampo("Costo",pzCosto);
}

void zProducto::AgregaCostos(zCostos *pzCCBruto,
			     zCostos *pzCCGeneral,
			     zCostos *pzCCForaneo,
			     zDescuento *pzDescuentos)
{
   (*this)  				<< 
    new zSiscomCampo("CostoBruto")	<<
    new zSiscomCampo("CostoGeneral")	<<
    new zSiscomCampo("CostoForaneo");
    if(pzCCBruto) 
    AsociadosAlCampo("CostoBruto",pzCCBruto);
    if(pzCCGeneral)
    AsociadosAlCampo("CostoGeneral",pzCCGeneral);
    if(pzCCForaneo)
    AsociadosAlCampo("CostoForaneo",pzCCForaneo);
    if(pzDescuentos)
    AsociadoAlCampo("Descuentos",pzDescuentos);

}
void zProducto::AgregaCostoBruto(const char *pchrPtrCosto)
{
   (*this)				<<
   new zSiscomCampo("CostoBruto",(const unsigned char *)pchrPtrCosto);
}

void zProducto::ParaInventario(const char *pchrPtrCantidad,
				    const  char *pchrPtrCodigoBarras)
{

   (*this) <<
   new zSiscomCampo("Cantidad",(const unsigned char *)pchrPtrCantidad) 	<<
   new zSiscomCampo("CodigoBarras",(const unsigned char *)pchrPtrCodigoBarras);
}
const char *zProducto::CodigoBarras()
{
  return (const char *)(*this)["codigobarras"];
}
const char *zProducto::SePuedeVender()
{
   if(!CampoInt("SePuedeVender"))
   return (const char *)Campo("Mensaje");
   else
   return 0;
}
void zProducto::Costo(zCosto *pzCosto)
{
 AgregaCampo("Costo",pzCosto);
}
void zProducto::Precio(zPrecio *pzPrecio)
{
 AgregaCampo("Precio",pzPrecio);
}
void zProducto::PrecioForaneo(zPrecio *pzPrecioForaneo)
{
  AgregaCampo("PrecioForaneo",pzPrecioForaneo);
}
