#ifndef __ZIMPRESIONPUNTOVENTA_H__
#define __ZIMPRESIONPUNTOVENTA_H__

class zOrden;
class zVenta;
class zSiscomRegistro;
class zImpresionPuntoVenta
{
public:
	zImpresionPuntoVenta();
	void Orden(zOrden *pzOrdenVenta);
	void Venta(zVenta *pzVenta);
	const char *Dato(const char *pchrPtrCampo);
	const char *NombreCompleto();
	const char *CalleNo();
	const char *TipoVentaContado();
	const char *TipoVentaCredito();
	const char *TipoVentaApartado();
	const char *EntregaTienda();
	const char *EntregaBodegaGeneral();
	const char *EntregaTransporteCliente();
	const char *EntregaCompania();
	const char *FormaEntrega();
	const char *InstruccionEntrega();
	const char *Referencias();
	const char *CampoProducto(const char *pchrPtrCampo);

	int SiguienteProducto();
	void PrimerProducto();
private:
	 zOrden *zOrdenV;
	 zVenta *zVentaV;
	 zSiscomRegistro *zSisRegProducto;
private:
	 const char *NumProductoModelo(zSiscomRegistro *pzSisRegProducto);
	 const char *DescripcionProducto(zSiscomRegistro *pzSisRegProducto);
	 const char *CampoCredito(const char *pchrPtrCampo);
	 const char *PagoTotal();
	 const char *DescuentoQuincenal();
	 const char *Plazo();
	 const char *DigitoAnio();
};

#endif
