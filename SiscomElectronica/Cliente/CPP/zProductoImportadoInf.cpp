#include <zProductoImportadoInf.h>
#include <zSiscomCampo.h>
#include <zCompraImportacion.h>
zProductoImportadoInf::zProductoImportadoInf():zProductoImportado()
{
  (*this) 				<<
  new zSiscomCampo("UltimaCompra");
}

void zProductoImportadoInf::Actualiza(zSiscomRegistro *pzSisRegRegreso)
{
ActualizaUltimaCompra(pzSisRegRegreso);
ActualizaPeso(pzSisRegRegreso);
ActualizaClaveProveedor(pzSisRegRegreso);
}
zCompraImportacion *zProductoImportadoInf::Compra()
{
 return (zCompraImportacion *)AsociadoDelCampo("UltimaCompra");
}

void zProductoImportadoInf::ActualizaPeso(zSiscomRegistro *pzSisRegRegreso)
{
zSiscomRegistro *lzSisRegPeso;
if((lzSisRegPeso=pzSisRegRegreso->AsociadoDelCampo("PesoProducto")))
zProductoImportado::Peso((const char *)(*lzSisRegPeso)["peso"]);
}
void zProductoImportadoInf::ActualizaUltimaCompra(zSiscomRegistro *pzSisRegRegreso)
{
zCompraImportacion *lzComImportacion=new zCompraImportacion;
zSiscomRegistro *lzSisRegUltCo;
if((lzSisRegUltCo=pzSisRegRegreso->AsociadoDelCampo("UltimaCompra")))
{
Cantidad((const char *)(*lzSisRegUltCo)["cantidad"]);
CostoUnitarioDolares((const char *)(*lzSisRegUltCo)["costounitario"]);
lzComImportacion->Fecha((const char *)(*lzSisRegUltCo)["fecha"]);
lzComImportacion->IdCompraImportacion((const char *)(*lzSisRegUltCo)["idcompraimportacion"]);
ActualizaCampo("UltimaCompra",lzComImportacion);
}
}
void zProductoImportadoInf::ActualizaClaveProveedor(zSiscomRegistro *pzSisRegRegreso)
{
zSiscomRegistro *lzSisRegRegreso;
if((lzSisRegRegreso=pzSisRegRegreso->AsociadoDelCampo("ClaveProveedor")))
  ActualizaCampo("CveProveedor",(*lzSisRegRegreso)["cveproveedor"]);
}
