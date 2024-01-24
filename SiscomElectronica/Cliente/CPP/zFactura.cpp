#include <zFactura.h>
#include <zSiscomCampo.h>


#include <zCliente.h>
#include <zOrdenes.h>
zFactura::zFactura()
{
   (*this) 				<<
   new zSiscomCampo("IdFactura")	<<
   new zSiscomCampo("Cliente")	 	<<
   new zSiscomCampo("Importe")		<<
   new zSiscomCampo("Total")		<<
   new zSiscomCampo("Iva")		<<
   new zSiscomCampo("TotalLetra") 	<<
   new zSiscomCampo("FormaPago")	<<
   new zSiscomCampo("MetodoPago")	<<
   new zSiscomCampo("UsoFactura")	<<
   new zSiscomCampo("Productos")	<<
   new zSiscomCampo("Ordenes");
}
void zFactura::Cliente(zCliente *pzCliente)
{
  AsociadoAlCampo("Cliente",pzCliente);
}
void zFactura::FormaPago(zSiscomRegistro *pzSisRegFormaPago)
{
   ActualizaCampo("FormaPago",pzSisRegFormaPago);
}
void zFactura::MetodoPago(zSiscomRegistro *pzSisRegMetodoPago)
{
   ActualizaCampo("MetodoPago",pzSisRegMetodoPago);
}
void zFactura::UsoFactura(zSiscomRegistro *pzSisRegUsoFactura)
{
  ActualizaCampo("UsoFactura",pzSisRegUsoFactura);
}
void zFactura::Productos(zSiscomRegistros *pzSisRegsProductos)
{
 AsociadosAlCampo("Productos",pzSisRegsProductos);
}
void zFactura::Ordenes(zOrdenes *pzOrdenes)
{
	AsociadosAlCampo("Ordenes",pzOrdenes);
}
zSiscomRegistros *zFactura::Productos()
{
   return AsociadosDelCampo("Productos");
}
void zFactura::Importe(const char *pchrPtrImporte)
{
  ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}

void zFactura::Total(const char *pchrPtrTotal)
{
  ActualizaCampo("Total",(const unsigned char *)pchrPtrTotal);
}
void zFactura::Iva(const char *pchrPtrIva)
{
  ActualizaCampo("Iva",(const unsigned char *)pchrPtrIva);
}
void zFactura::TotalLetra(const char *pchrPtrImporteLetra)
{
  ActualizaCampo("TotalLetra",(const unsigned char *)pchrPtrImporteLetra);
}
const char *zFactura::Importe()
{
  return (const char *)Campo("Importe");
}

const char *zFactura::Total()
{
  return (const char *)Campo("Total");
}
float zFactura::TotalFloat()
{
  return CampoFloat("Total");
}
const char *zFactura::Iva()
{
  return (const char *)Campo("Iva");
}
