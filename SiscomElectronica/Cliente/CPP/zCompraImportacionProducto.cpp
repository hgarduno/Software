#include <zCompraImportacionProducto.h>
#include <zSiscomCampo.h>
zCompraImportacionProducto::zCompraImportacionProducto()
{
 (*this) 			<< 
 new zSiscomCampo("Fecha")	<<
 new zSiscomCampo("IdCompra")	<<
 new zSiscomCampo("Cantidad")	<<
 new zSiscomCampo("Costo")	<<
 new zSiscomCampo("CostoTotal");
}


void zCompraImportacionProducto::Fecha(const char *pchrPtrFecha)
{
   ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}


void zCompraImportacionProducto::IdCompra(const char *pchrPtrIdCompra)
{
   ActualizaCampo("IdCompra",(const unsigned char *)pchrPtrIdCompra);
}
void zCompraImportacionProducto::Cantidad(const char *pchrPtrCantidad)
{
   ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
void zCompraImportacionProducto::Costo(const char *pchrPtrCosto)
{
   ActualizaCampo("Costo",(const unsigned char *)pchrPtrCosto);
}
void zCompraImportacionProducto::CostoTotal(const char *pchrPtrCostoTotal)
{
   ActualizaCampo("CostoTotal",(const unsigned char *)pchrPtrCostoTotal);
}
const char *zCompraImportacionProducto::Fecha()
{
   return (const char *)(*this)["Fecha"];
}

const char *zCompraImportacionProducto::IdCompra()
{
   return (const char *)(*this)["IdCompra"];
}
const char *zCompraImportacionProducto::Cantidad()
{
   return (const char *)(*this)["Cantidad"];
}
const char *zCompraImportacionProducto::Costo()
{
   return (const char *)(*this)["Costo"];
}
const char *zCompraImportacionProducto::CostoTotal()
{
   return (const char *)(*this)["CostoTotal"];
}

zCompraImportacionProducto *zCompraImportacionProducto::Compra(zSiscomRegistro *pzSisRegCompra)
{
  zCompraImportacionProducto *lzComImpPro=new zCompraImportacionProducto;
  lzComImpPro->Fecha((const char *)(*pzSisRegCompra)["fecha"]);
  lzComImpPro->IdCompra((const char *)(*pzSisRegCompra)["idcompraimportacion"]);
  lzComImpPro->Cantidad((const char *)(*pzSisRegCompra)["cantidad"]);
  lzComImpPro->Costo((const char *)(*pzSisRegCompra)["costounitario"]);
  lzComImpPro->CostoTotal((const char *)(*pzSisRegCompra)["costototal"]);
  return lzComImpPro;
}
