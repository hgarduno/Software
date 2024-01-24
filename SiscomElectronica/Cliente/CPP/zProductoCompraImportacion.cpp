#include <zProductoCompraImportacion.h>
#include <zComprasImportacionProducto.h>
#include <zCompraImportacionProducto.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
zProductoCompraImportacion::zProductoCompraImportacion():zProductoCompra()
{
  (*this) 						<<
  new zSiscomCampo("Peso")				<<
  new zSiscomCampo("PesoTotal")				<<
  new zSiscomCampo("Proveedor")				<<
  new zSiscomCampo("Compras");
}

void zProductoCompraImportacion::Peso(const char *pchrPtrPeso)
{
   ActualizaCampo("Peso",(const unsigned char *)pchrPtrPeso);
}
void zProductoCompraImportacion::PesoTotal(const char *pchrPtrPeso)
{
   ActualizaCampo("PesoTotal",(const unsigned char *)pchrPtrPeso);
}

const char *zProductoCompraImportacion::Peso()
{
   return (const char *)(*this)["Peso"];
}
const char *zProductoCompraImportacion::PesoTotal()
{
   return (const char *)(*this)["PesoTotal"];
}

zProductoCompraImportacion *zProductoCompraImportacion::Producto(zSiscomRegistro *pzSisRegRegreso)
{
zSiscomRegistro *lzSisRegProducto;
if((lzSisRegProducto=pzSisRegRegreso->AsociadoDelCampo("ProductoProveedor")))
{
zProductoCompraImportacion *lzProdComImp=new zProductoCompraImportacion;
lzProdComImp->Clave((const char *)(*lzSisRegProducto)["cveproducto"]);
lzProdComImp->ClaveProveedor((const char *)(*lzSisRegProducto)["cveproveedor"]);
lzProdComImp->Peso((const char *)(*lzSisRegProducto)["peso"]);
lzProdComImp->DscProveedor((const char *)(*lzSisRegProducto)["descripcion"]);
if(pzSisRegRegreso->AsociadosDelCampo("Compras"))
lzProdComImp->Compras(pzSisRegRegreso->AsociadosDelCampo("Compras"));
return lzProdComImp;
}
else
return 0;
}
void zProductoCompraImportacion::Compras(zSiscomRegistros *pzSisRegsCompras)
{
zSiscomRegistro *lzSisRegCompra;
zComprasImportacionProducto *lzComsProImp=new zComprasImportacionProducto;
for(lzSisRegCompra=pzSisRegsCompras->Primer();
    lzSisRegCompra;
    lzSisRegCompra=pzSisRegsCompras->Siguiente())
    (*lzComsProImp) << zCompraImportacionProducto::Compra(lzSisRegCompra);
AsociadosAlCampo("Compras",lzComsProImp);
}
zComprasImportacionProducto *zProductoCompraImportacion::Compras()
{
   return (zComprasImportacionProducto *)AsociadosDelCampo("Compras");
}
