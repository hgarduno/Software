#ifndef __ZREPORTEVENTAS_H__
#define __ZREPORTEVENTAS_H__
#include <zSiscomRegistro.h>

class zSiscomRegistros;
class zReporteVentas:public zSiscomRegistro
{
public:
	zReporteVentas();
	zReporteVentas(const char *pchrPtrFechaInicio,
		       const char *pchrPtrFechaFin,
		       const char *pchrPtrIdExpendio);
	void CierreDia(zSiscomRegistro *pzSisRegCierreDia);
	void Reportes(zSiscomRegistro *pzSisRegReportes);
	void FechaInicio(const char *pchrPtrFechaInicio);
	void FechaFin(const char *pchrPtrFechaFin);
	void Expendio(const char *pchrPtrExpendio);

	void ImporteVentas(const char *pchrPtrImporteVentas);
	void ImporteApartados(const char *pchrPtrImporteApartados);
	void ImportePedidos(const char *pchrPtrImportePedidos);
	void ImporteTarjeta(const char *pchrPtrImporteTarjeta);

	void TotalTotalVentas(const char *pchrPtrTotalVentas);

	const char *ImporteVentas();
	const char *ImportePedidos();
	const char *ImporteTarjeta();
	const char *ImporteApartados();

	const char *TotalTotalVentas();

	void VentasPorEscuela(zSiscomRegistros *pzSisRegsDatos);
	void PedidosPorEscuela(zSiscomRegistros *pzSisRegsDatos);
	void PagoTarjetaPorEscuela(zSiscomRegistros *pzSisRegDatos);
	void VentasTotales(zSiscomRegistros *pzSisRegDatos);
	void Totales(zSiscomRegistros *pzSisRegDatos);
	void MaterialEscuela(zSiscomRegistros *pzSisRegsDatos);
	zSiscomRegistros *VentasPorEscuela();
	zSiscomRegistros *PedidosPorEscuela();
	zSiscomRegistros *PagoTarjetaPorEscuela();
	zSiscomRegistros *VentasTotales();
	zSiscomRegistros *Totales();
	zSiscomRegistros *MaterialEscuela();
};

#endif
