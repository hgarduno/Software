#include <zReporteVentas.h>

#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
zReporteVentas::zReporteVentas()
{
(*this)						<<
new zSiscomCampo("FechaInicio") 		<<
new zSiscomCampo("FechaFin")	  		<<
new zSiscomCampo("IdExpendio")			<<
new zSiscomCampo("ImporteVentas")		<<
new zSiscomCampo("ImporteApartados")		<<
new zSiscomCampo("ImportePedidos")		<<
new zSiscomCampo("ImporteTarjeta")		<<
new zSiscomCampo("ImporteCancelaciones")	<<
new zSiscomCampo("ImporteCircuitosImpresos")	<<
new zSiscomCampo("TotalVentas")			<<
new zSiscomCampo("Totales")			<<
new zSiscomCampo("TotalTotalVentas")		<<
new zSiscomCampo("VentaEscuelas")		<<
new zSiscomCampo("PedidosPorEscuela")		<<
new zSiscomCampo("PagoTarjetaPorEscuela")	<<
new zSiscomCampo("MaterialEscuela");

}
zReporteVentas::zReporteVentas(const char *pchrPtrFechaInicio,
			       const char *pchrPtrFechaFin,
			       const char *pchrPtrIdExpendio)
{
(*this)										<<
new zSiscomCampo("FechaInicio",(const unsigned char *)pchrPtrFechaInicio) 	<<
new zSiscomCampo("FechaFin",(const unsigned char *)pchrPtrFechaFin)	  	<<
new zSiscomCampo("IdExpendio",(const unsigned char *)pchrPtrIdExpendio)		<<
new zSiscomCampo("ImporteVentas")						<<
new zSiscomCampo("ImporteApartados")						<<
new zSiscomCampo("ImportePedidos")						<<
new zSiscomCampo("ImporteTarjeta")						<<
new zSiscomCampo("ImporteCancelaciones")					<<
new zSiscomCampo("ImporteCircuitosImpresos")	<<
new zSiscomCampo("TotalVentas")							<<
new zSiscomCampo("Totales")							<<
new zSiscomCampo("TotalTotalVentas")						<<
new zSiscomCampo("VentaEscuelas")						<<
new zSiscomCampo("PedidosPorEscuela")						<<
new zSiscomCampo("PagoTarjetaPorEscuela")					<<
new zSiscomCampo("MaterialEscuela");
}
void zReporteVentas::FechaInicio(const char *pchrPtrFechaInicio)
{
	ActualizaCampo("FechaInicio",(const unsigned char *)pchrPtrFechaInicio);
}

void zReporteVentas::FechaFin(const char *pchrPtrFechaFin)
{
	ActualizaCampo("FechaFin",(const unsigned char *)pchrPtrFechaFin);
}

void zReporteVentas::Expendio(const char *pchrPtrExpendio)
{
	ActualizaCampo("Expendio",(const unsigned char *)pchrPtrExpendio);
}
void zReporteVentas::Reportes(zSiscomRegistro *pzSisRegReportes)
{
ImporteVentas((const char *)pzSisRegReportes->CampoAsociado("VentasTotales","ventastotales"));
ImporteApartados((const char *)pzSisRegReportes->CampoAsociado("VentasApartados","ventasapartado"));
ImportePedidos((const char *)pzSisRegReportes->CampoAsociado("VentasPedidos","ventaspedido"));
ImporteTarjeta((const char *)pzSisRegReportes->CampoAsociado("VentasTarjeta","ventastarjeta"));
TotalTotalVentas((const char *)pzSisRegReportes->CampoAsociado("TotalTotalVentas","total"));
VentasPorEscuela(pzSisRegReportes->AsociadosDelCampo("ImporteVentasPorEscuela"));
PedidosPorEscuela(pzSisRegReportes->AsociadosDelCampo("ImportePedidosPorEscuela"));
PagoTarjetaPorEscuela(pzSisRegReportes->AsociadosDelCampo("ImporteTarjetaPorEscuela"));
VentasTotales(pzSisRegReportes->AsociadosDelCampo("TotalVentas"));
Totales(pzSisRegReportes->AsociadosDelCampo("Totales"));
MaterialEscuela(pzSisRegReportes->AsociadosDelCampo("MaterialEscuela"));
}

void zReporteVentas::CierreDia(zSiscomRegistro *pzSisRegReportes)
{
ImporteVentas((const char *)pzSisRegReportes->CampoAsociado("VentasEfectivo","ventasefectivo"));
ImportePedidos((const char *)pzSisRegReportes->CampoAsociado("VentasPedidos","ventaspedido"));
ImporteTarjeta((const char *)pzSisRegReportes->CampoAsociado("VentasTarjeta","ventastarjeta"));
TotalTotalVentas((const char *)pzSisRegReportes->CampoAsociado("TotalCaja","ventastotales"));
}
void zReporteVentas::ImporteVentas(const char *pchrPtrImporteVentas)
{
	ActualizaCampo("ImporteVentas",(const unsigned char *)pchrPtrImporteVentas);
}
void zReporteVentas::ImporteApartados(const char *pchrPtrImporteApartados)
{
	ActualizaCampo("ImporteApartados",(const unsigned char *)pchrPtrImporteApartados);
}

void zReporteVentas::ImportePedidos(const char *pchrPtrImportePedidos)
{
	ActualizaCampo("ImportePedidos",(const unsigned char *)pchrPtrImportePedidos);
}
void zReporteVentas::ImporteTarjeta(const char *pchrPtrImporteTarjeta)
{
	ActualizaCampo("ImporteTarjeta",(const unsigned char *)pchrPtrImporteTarjeta);
}
void zReporteVentas::TotalTotalVentas(const char *pchrPtrTotalTotalVentas)
{
	ActualizaCampo("TotalTotalVentas",(const unsigned char *)pchrPtrTotalTotalVentas);
}
void zReporteVentas::VentasPorEscuela(zSiscomRegistros *pzSisRegsDatos)
{
   AsociadosAlCampo("VentaEscuelas",pzSisRegsDatos);
}
void zReporteVentas::PedidosPorEscuela(zSiscomRegistros *pzSisRegsDatos)
{
   AsociadosAlCampo("PedidosPorEscuela",pzSisRegsDatos);
}
void zReporteVentas::PagoTarjetaPorEscuela(zSiscomRegistros *pzSisRegsDatos)
{
   AsociadosAlCampo("PagoTarjetaPorEscuela",pzSisRegsDatos);
}
void zReporteVentas::VentasTotales(zSiscomRegistros *pzSisRegsDatos)
{
	AsociadosAlCampo("TotalVentas",pzSisRegsDatos);
}
void zReporteVentas::Totales(zSiscomRegistros *pzSisRegsDatos)
{
	AsociadosAlCampo("Totales",pzSisRegsDatos);
}
void zReporteVentas::MaterialEscuela(zSiscomRegistros *pzSisRegsDatos)
{
	AsociadosAlCampo("MaterialEscuela",pzSisRegsDatos);
}
const char *zReporteVentas::ImporteVentas()
{
	return (const char *)(*this)["ImporteVentas"];
}
const char *zReporteVentas::ImporteApartados()
{
	return (const char *)(*this)["ImporteApartados"];
}

const char *zReporteVentas::ImportePedidos()
{
	return (const char *)(*this)["ImportePedidos"];
}
const char *zReporteVentas::ImporteTarjeta()
{
	return (const char *)(*this)["ImporteTarjeta"];
}

const char *zReporteVentas::TotalTotalVentas()
{
	return (const char *)(*this)["TotalTotalVentas"];
}

zSiscomRegistros *zReporteVentas::VentasPorEscuela()
{
     return AsociadosDelCampo("VentaEscuelas");
}
zSiscomRegistros *zReporteVentas::PedidosPorEscuela()
{
     return AsociadosDelCampo("PedidosPorEscuela");
}
zSiscomRegistros *zReporteVentas::PagoTarjetaPorEscuela()
{
     return AsociadosDelCampo("PagoTarjetaPorEscuela");
}
zSiscomRegistros *zReporteVentas::VentasTotales()
{
	return AsociadosDelCampo("TotalVentas");
}
zSiscomRegistros *zReporteVentas::Totales()
{
	return AsociadosDelCampo("Totales");
}
zSiscomRegistros *zReporteVentas::MaterialEscuela()
{
	return AsociadosDelCampo("MaterialEscuela");
}
