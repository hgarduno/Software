#ifndef __QTIMPPUNTODEVENTA_H__
#define __QTIMPPUNTODEVENTA_H__
#include <cstddef>
#include <PuntoDeVenta.h>
#include <zProductos.h>
#include <zOrden.h>
#include <zVenta.h>
#include <zCredito.h>
class zSiscomConexion;
class zSiscomRegistro;

class zCliente;
class zDireccion;
class zProducto;
class QtImpPuntoDeVenta:public PuntoDeVenta
{
Q_OBJECT
public:
	QtImpPuntoDeVenta(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	void IniciaVariables();
	void RegistraDireccion();
	void VeSiSeHabilitaFinanciera();
	void VeSiSeHabilitaConcepto();
	void FocoACapturaDireccion();
	void FocoAFormaEntrega();
	void MuestraDatosCliente();
	void MuestraDatosDireccion();
	void MuestraInformacionCredito();
	void CotizaProducto();
	void CotizaOrden();
	void MuestraProductoCotizado();
	void MuestraCotizandoOrden();
	void CotizandoProducto();
	void CotizandoOrden();
	void AgregaProductoOrden();
	void RegistrandoVenta();
	void HabilitaInstruccionesEntrega();
	void EnviaDatosALogSiscom();
	void EnviaProductosLog();

	void ValidandoCliente();
	void HabilitaAnexarProducto(bool pbSePuedeVender);
	void MuestraMensajeSePuedeVender(const char *pchrPtrMensaje);
    	void imprimeFactura();

	void ReIniciaVenta();
	void SeleccionandoProducto(int);
	void AgregaVentaACredito();
	void DireccionCliente();
	void PorClaveProveedor();
	void ObtenProductoProveedorNumProducto();

	void ActualizaDireccion();
	void ObtenFolio();
	void ObtenFolioFacturaCredito();
	void ObtenFolioFacturaApartado();
	void CancelarFolio();

        int LineEditValido(QLineEdit *);

private:
	zSiscomRegistro *zSiscomTipoVenta;
	zSiscomRegistro *zSiscomFinanciadora;
	zSiscomRegistro *zSiscomPlazo;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSiscomConceptosExis;
	zSiscomRegistro *zSiscomTiendasEntrega;
	zSiscomRegistro *zSiscomVendedor;
	zSiscomRegistro *zSiscomFormaEntrega; 
	zSiscomRegistro *zSiscomRegProveedor;
	zCliente *zPerCliente;
	zDireccion *zPerDireccion;
	zProducto *zProdCotizar;
	zProducto *zProdCambiar;
	zProductos zProdsOrden;
	zOrden zOrdenVenta;
	zVenta zVentaOrden;
	zCredito zVentaCredito;
	/* SISCOM Electronica 
	 * Martes 28 Junio 2016 
	 * Esta variable nos servira para controlar una direccion
	 * ya registrada y una actualizada 
	 * si es 1 es registrada y no se actualiza 
	 * si es 2 la direccion se debe actualizar 
	 */
	int intClienteRegistrado;
	int intProductoSeleccionado;

	int intPorCodigoBarras;
	int intPorClaveProveedor;
private slots:
	void SlotTipoVenta(zSiscomRegistro *pzSiscomTipoVenta);
	void SlotFinanciadora(zSiscomRegistro *pzSiscomFinanciadora);
	void SlotPlazo(zSiscomRegistro *pzSiscomPlazo);
	void SlotConcepto(zSiscomRegistro *pzSiscomConcepto);
	void SlotTienda(zSiscomRegistro *pzSiscomTiendasEntrega);
	void SlotVendedor(zSiscomRegistro *pzSiscomVendedor);
	void SlotFocoAFecha();
	void SlotCapturaCliente();
	void SlotCapturaDireccion();
	void SlotFocoACapturaCliente();
	void SlotFormaEntrega(zSiscomRegistro *pzSisFormaEntrega );
	void SlotCodigoBarras();
	void SlotAgregarOrden();
	void SlotRegistraVenta();
	void SlotImprimeFactura();
	void SlotCambiarPrecio();
	void SlotSeleccionaProducto(int,int,int,const QPoint &);
	void SlotFocoACodigoBarras();
	void SlotNuevaOrden();
	void SlotEliminaProducto();
	void SlotSeleccionaProveedor(zSiscomRegistro *);
	void SlotFocoAFormaEntrega();
	void SlotProductosProveedor();
	void SlotCapturoNumeroProducto();
	void SlotCancelarFolio();
	void SlotCapturandoTelefono(const QString &pQStrTelefono);
};
#endif
