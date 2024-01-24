#include <zCompraContenedor.h>
#include <zCompraImportacion.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>

zCompraContenedor::zCompraContenedor()
{
 (*this) 					<<
 new zSiscomCampo("IdCompra")			<<
 new zSiscomCampo("Contenedor")			<<
 new zSiscomCampo("CostoEnvio")			<<
 new zSiscomCampo("CostoDolar")			<<
 new zSiscomCampo("CostoAdministrativo")	<<
 new zSiscomCampo("Facturas");
}

void zCompraContenedor::Factura(zCompraImportacion *pzComImportacion)
{
   AsociadoAlCampo("Facturas",(zSiscomRegistro *)pzComImportacion);
}
zComprasImportacion *zCompraContenedor::Facturas()
{
	return (zComprasImportacion *)AsociadosDelCampo("Facturas");
}

void zCompraContenedor::CostoDolar(const char *pchrPtrCostoDolar)
{
	ActualizaCampo("CostoDolar",(const unsigned char *)pchrPtrCostoDolar);
}
void zCompraContenedor::CostoAdministrativo(const char *pchrPtrCostoAdministrativo)
{
ActualizaCampo("CostoAdministrativo",(const unsigned char *)pchrPtrCostoAdministrativo);
}

void zCompraContenedor::CostoEnvio(const char *pchrPtrCostoEnvio)
{
ActualizaCampo("CostoEnvio",(const unsigned char *)pchrPtrCostoEnvio);
}

zCompraImportacion *zCompraContenedor::Factura(int pintNFactura)
{
zSiscomRegistros *lzSisRegsFacturas;

    lzSisRegsFacturas=AsociadosDelCampo("Facturas");
    if(lzSisRegsFacturas)
    return (zCompraImportacion *)(*lzSisRegsFacturas)[pintNFactura];
    else
    return 0;
}
const char *zCompraContenedor::CostoDolar()
{
   return (const char *)Campo("CostoDolar");
}


const char *zCompraContenedor::CostoAdministrativo()
{
   return (const char *)Campo("CostoAdministrativo");
}
const char *zCompraContenedor::CostoEnvio()
{
   return (const char *)Campo("CostoEnvio");
}

void zCompraContenedor::DatosEnvioFactura(int pintNFactura)
{
 Factura(pintNFactura)->CostoDolar(CostoDolar());
 Factura(pintNFactura)->CostoEnvio(CostoEnvio());
 Factura(pintNFactura)->CostoAdministrativo(CostoAdministrativo());
}
