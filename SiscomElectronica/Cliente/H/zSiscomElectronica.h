#ifndef __ZSISCOMELECTRONICA_H__
#define __ZSISCOMELECTRONICA_H__
#include <zSiscomOperaciones.h>

class zSiscomConexion;
class zOrdenVenta;
class zOrdenes;
class zFactura;
class zCliente;
class zCotizacion;
class zPersona;
class zEmpresa;
class zCorreos;
class zPersona;
class zClienteSiscom;
class zExistenciaExpendios;
class zProductos;
class zPractica;
class zDireccion;
class zReporteVentas;
class zProductosTransferir;
class zCircuitoImpreso;
class zOrdenCompra;
class zDatosReEnvioFactura;
class zClaveSat;
class zPedidoExpendio;
class zProductoPedido;
class zExpendio;
class zExpendios;
class zCierreCaja;
class zCompraImportacion;
class zProductosImportados;
class zProductoImportado;
class zProducto;
class zProductoSiscom;
class zPreciosExpendios;
class zPreciosProductos;
class zPrecios2Productos;
class zCotizacionImportacion;
class zCotizacionesImportacion;
class zDirecciones;
class zComprasImportacion;
class zDevolucion;
class zClavesProveedor;
class zClaveProveedor;
class zProductoCompraImportacion;
class zCajaMaterial;
class zProductoImportadoInf;
class zOrdenesFavoritas;
class zCajas;
class zPuntoEntrega;
class zEscuelas;
class zContenedor;
class zProductoPrecioExpendios;
class zListaExpendios;
class zCondicionConsultaOrdenes;
class zBodegas;
class zExistenciaBodega;
class zBodega;
class zTransfiereBodegaBodega;
class zClientesSiscom;
class zConCuantoPago;
class zCambiosCaja;
class zCambioCaja;
class zCorteCaja;
class zCompraParcialImportacion;
class zAbonoAApartado;
class zExistenciaVenta;
class zCompras;
class zSiscomElectronica:public zSiscomOperaciones 
{
public:
	zSiscomElectronica(zSiscomConexion *pzSisConexion,
			   const char *pchrPtrFuncion,
			   const char *pchrPtrModulo="libSiscomElectronica4.so");
	~zSiscomElectronica();

	zSiscomRegistros *OrdenesPendientes(const char *pchrPtrFechaInicio,const char *pchrPtrFechaFin);
	zSiscomRegistros *Productos(const char *pchrPtrCriterio);
	zSiscomRegistros *Escuelas(const char *pchrPtrCriterio);
	zSiscomRegistros *TiposProducto(const char *pchrPtrCriterio);
	zSiscomRegistros *EstadosImpresos(const char *pchrPtrCriterio);
	zSiscomRegistros *EstadosPedidos(const char *pchrPtrCriterio);
	zSiscomRegistros *Gastos(const char *pchrPtrCriterio);
	int CotizaOrden(zOrdenVenta *pzOrdenVenta,zSiscomRegistro **);
	zOrdenes *Ordenes(const char *pchrPtrFechaInicio,
			  const char *pchrPtrFechaFin,
			  const char *pchrPtrIdTipoOrden);
	zOrdenes *OrdenesParaFacturar(const char *pchrPtrFechaInicio,
			  const char *pchrPtrFechaFin);

	zOrdenes *OrdenParaFacturar(const char *pchrPtrIdVenta);

	zOrdenes *Ordenes2(const char *pchrPtrFechaInicio,
			  const char *pchrPtrFechaFin,
			  const char *pchrPtrIdTipoOrden);

	zOrdenes *Ordenes(zCondicionConsultaOrdenes *);

	int CalculaFactura(zOrdenes *pzOrdenes,zFactura *pzFactura);
	void RegistraCliente(zCliente *pzCliente);
	int RegistraCliente(zClienteSiscom *pzSisCliSiscom,zClientesSiscom **);
	int RegistraCelularAlumno(zClienteSiscom *pzSisCliSiscom);
	int RegistraCorreoAlumno(zClienteSiscom *pzSisCliSiscom);
	int RegistraDireccionAlumno(zClienteSiscom *pzSisCliSiscom);
	int Factura(zFactura *pzFactura,char **pchrPtrEstadoOperacion);
	int ClienteRegistrado(const char *pchrPtrRFC,zCliente *pzCliente);
	void AgregaCorreoCliente(zPersona *pzPersona,
				zEmpresa *pzEmpresa,
				zCorreos *pzCorreos);
	void ExistenciaExpendios(zProductos *pzProductos,zExistenciaExpendios *pzExExpendios);
	void ExistenciaExpendios(zSiscomRegistro *,zExistenciaExpendios *pzExExpendios);
	void ExistenciaExpendios(zExistenciaVenta *);
	void ExistenciaSiscom(zExistenciaVenta*);
	int ValidaReCaptura(const char *pchrPtrCaptura1,const char *pchrPtrCaptura2);
	void ImprimeTicketVenta(zOrdenVenta *);
	int IdNuevaOrden(char **pchrPtrIdNuevaOrden);
	void RegistraOrden(zOrdenVenta *pzOrdVenta);
	zSiscomRegistro *PublicoEnGeneral();
	zSiscomRegistros *Apartados(const char *pchrPtrFechaIni,const char *pchrPtrFechaFin);
	void CierraApartado(zSiscomRegistro *pzSisRegApartado);
	zSiscomRegistros *ProductoEnApartados(const char *pchrPtrClave);
	const char *RegistraPractica(zPractica *pzPractica);
	zOrdenVenta *ConsultaOrden(const char *pchrPtrIdOrden,
				   const char *pchrPtrTipoOrden,
				   zOrdenes **pzOrden);
	zDireccion *Escuela(zSiscomRegistro *pzSisRegEscuela);

	int ReporteVentas(const char *pchrPtrIdExpendio,
			  const char *pchrPtrFechaInicio,
			  const char *pchrPtrFechaFin,
			  char *pchrPtrDesEstadoReporte,
			  zReporteVentas *pzRepVentas);
	int VentasSiscom(const char *pchrPtrFechaInicio,
			 const char *pchrPtrFechaFin,
			 zReporteVentas *pzRepVentas);
			 
	int ValidaExistenciaATransferir(const char *pchrPtrCantidad,
					const char *pchrPtrCantComprada,
					const char *pchrPtrCveProducto,
					const char **pchrPtrMensaje);
	int ExistenciaExpendioOrigenDestino(const char *pchrPtrIdExpendioO,
					     const char *pchrPtrIdExpendioD,
					     zSiscomRegistro *pzSisRegProducto,
					     zSiscomRegistro **pzSisRegExistencias);
	int ValidandoTransferenciaExpendioOrigen(zSiscomRegistro *pzSisRegEnvio);
	void TransfiereProductosExpendioExpendio(zProductosTransferir *);
	zSiscomRegistros *ProductosTransferenciaOtrosExpendios();
	void ImprimeTransferenciaOtrosExpendios();
	void RegistraImpreso(zCircuitoImpreso *pzCircuitoImpreso);
	void CircuitosImpresosRegistrados(zSiscomRegistros **pzSisRegsImpresosR);
	void CircuitosImpresosPorEstadoFecha(const char *pchrPtrFechaInicio,
					   const char *pchrPtrFechaFin,
					   zSiscomRegistro *pzSisRegEstado,
					   zSiscomRegistros **pzSisRegsImpresos);
	void CircuitoImpresoActualizaEstado(zSiscomRegistro *pzSisRegEstado,
					   zSiscomRegistro *pzSisImpreso);

	void RegistraOrdenCompra(zOrdenCompra *pzOrdCompra);
	void DatosParaReEnvioFactura(const char *pchrPtrIdFactura,
				    zDatosReEnvioFactura **pzDatReEnvFactura);

	void ReEnviaFactura(const char *pchrPtrIdFactura,
			   const char *pchrPtrCorreo,
			   zSiscomRegistro **pzSisRegEdoReEnvio);
	void RegistraClaveSat(zClaveSat *pzClaveSat);
	int ClaveSat(const char *pchrPtrClave,zClaveSat *pzCveSat);

	int PedidoExpendioHoy(const char *pchrPtrIdExpendio,zPedidoExpendio *pzPedidoExpendio);
	int ProductoAPedidoExpendioHoy(zProductoPedido *pzProdPedido);
	int RegistrandoPedido(zPedidoExpendio *pzProdPedido);
	int ActualizaProductoPedido(zProductoPedido *pzProdPedido);
	int ActualizaObservacionesPedido(zPedidoExpendio *pzPedExpendio,const char *pchrPtrObservaciones);

	int IniciaPedidoExpendioHoy(const char *pchrPtrIdExpendio);

	int EliminaProductoPedido(const char *pchrPtrIdExpendio,
				  const char *pchrPtrIdPedido);

	int Expendios(zExpendios *);

	int CierreHoy(zCierreCaja *);

	int InventarioExpendio(const char *pchrPtrIdExpendio,
			       const char *pchrPtrFechaBase,
			       zProductos *pzProductos);
	int Proveedores(zSiscomRegistros **);
	int PesoProducto(zSiscomRegistro *,char *pchrPtrPeso);
	int RegistraPesoProducto(zSiscomRegistro *,const char *pchrPtrPeso);
	int ActualizaPesoProducto(zProductoImportado *pzProdImportado);
	int CalculaProductoImportacion(zCompraImportacion *pzComImportacion,char *);
	int RegistraCompraImportacion(zCompraImportacion *pzComImportacion);
	int RegistroParcialCompraImportacionFaltaronProductos(zCompraParcialImportacion *);
	int ActualizaCompraImportacionRegistrada(zCompraImportacion *);

	int ProductosImportadosPorFiltro(const char *pchrPtrFiltro,
					 const char *pchrPtrCantidad,
					 const char *pchrPtrCostoUnitario,
					 const char *pchrPtrPeso,
					zProductosImportados **pzProdsImportados);
	int CierreDia(const char *pchrPtrIdExpendio,
			const char *pchrPtrFechaIni,
		        const char *pchrPtrFechaFin,
		        zReporteVentas *pzRepVentas);
 	zClienteSiscom *OrdenEscuelaPrincipal(const char *pchrPtrIdExpendio);
	zClienteSiscom *OrdenOtro(const char *pchrPtrIdExpendio);
	void ClientesMayoreo(zSiscomRegistros **);
	static zClienteSiscom *ClientePublicoEnGeneral(zSiscomConexion *);
	void DefinicionProducto(zProducto *pzProdSiscom);
	void ComprandoProductoSiscom(zProductoSiscom *pzCompProdSiscom);
	void ValidandoCompraProductoSiscom(zProductoSiscom *);
	const char *IdCompraProductoSiscom();
	int Practica(zSiscomRegistro *pzSisRegProducto,zPractica *);
	int ConsultaCompraImportacion(const char *pchrPtrIdCompra,zCompraImportacion *,char *);
	int ConsultaComprasImportacion(const char *pchrPtrFechaIni,
				       const char *pchrPtrFechaFin,
				       zComprasImportacion *pzCompsImportacion);
	int GuardaCompraImportacion(zCompraImportacion *);
	int GuardaCompraImportacionComo(zCompraImportacion *);
	int ActualizaInventarioParaPedido(const char *pchrPtrIdExpendio,
					  const char *pchrPtrCveProducto,
					  const char *pchrPtrCantidad);

	int TransfiereBodegaAExpendioParaPedido(const char *pchrPtrIdExpendio,
					      const char *pchrPtrIdEmpleado,
					      const char *pchrPtrIdBodega,
					      const char *pchrPtrCveProducto,
					      const char *pchrPtrCantidad,
					      zSiscomRegistro **);
	int PreciosExpendios(const char *pchrPtrIdExpendioO,
			     const char *pchrPtrIdExpendioD,
			     zPreciosExpendios *pzPreciosE); 
	int Precios2Productos(zEmpresa *pzExpendioO,
			    zEmpresa *pzExpendioD,
			    zPrecios2Productos *pzPrecios2Prods);

	int RegistrandoCotizacionImportacion(zCotizacionImportacion *);
	int CotizacionesImportacion(zCotizacionesImportacion *);
	
	int RegistraProductoCotizaImportacion(zCotizacionImportacion *);
	int SeleccionoCotizacionImportacion(zCotizacionImportacion *pzCompraImp);
	int Direcciones(zClienteSiscom *,zDirecciones *pzDirecciones);

	zSiscomRegistros *RFCs(const char *pchrPtrCriterio);
	zSiscomRegistros *FormasPagoSat(const char *pchrPtrCriterio);
	zSiscomRegistros *UsoFacturaSat(const char *pchrPtrCriterio);
	zSiscomRegistros *MetodoPagoSat(const char *pchrPtrCriterio);
	zSiscomRegistros *RegimenFiscal(const char *pchrPtrCriterio);

	int Devolucion(zDevolucion *pzDevolucion);
	int RegistraClavesProveedor(zClavesProveedor *);

	int ClavesProveedor(const char *pchrPtrCveProducto,
			    const char *pchrPtrIdProveedor,
			    zClavesProveedor *);

	int ValidaClaveRegistrada(zSiscomRegistro *pzSisRegProducto,
				  zSiscomRegistro *,
				  zClaveProveedor **pzClaveProveedor);


	int ProductoCompraImportacion(zSiscomRegistro *pzSisRegProducto,
				      zSiscomRegistro *pzSisRegProveedor,
				      zProductoCompraImportacion **pzProdComImp);

	int CalculaPesoImporteTotal(zProductoCompraImportacion *pzProdComImp);
	zSiscomRegistros *Materias(const char *pchrPtrIdEscuela);
	zSiscomRegistros *CajasMaterial();
	zSiscomRegistros *Estantes();
	int RegistraCajaMaterial(zCajaMaterial *);
	int AsignaCajaProducto(zSiscomRegistro *);
	int UbicacionDeLaDescripcion();
	int ProductoImportadoInf(zSiscomRegistro *,
				 zSiscomRegistro *,
				 zProductoImportadoInf *);
	int RegistraOrdenesFavoritas(zOrdenesFavoritas *);
	int ConsultaOrdenesFavoritas(zOrdenesFavoritas *);
	int EliminaOrdenesFavoritas(zOrdenesFavoritas *);
	int CalculaCorteCaja(zCorteCaja *);
	int RegistraCambioCaja(zCajas *);

	int CalculaCambioPago(const char *pchrPtrPago,
			      const char *pchrPtrImporte,
			      char *pchrPtrCambio,
			      char *pchrPtrDescripcion);


	int EntregaEscuela(zEscuelas *);
	int ActualizaDescripcionCotizacion(zOrdenVenta *pzOrden);
	int ActualizaClaveProveedor4(zClaveProveedor *);

	int AgregaFacturaContenedor(zContenedor *,zCompraImportacion *);
	int CompletaProductosImportacion(zCompraImportacion *);
	int ActualizaPrecioExpendios(zProductoPrecioExpendios *);
	int SincronizaProductosExpendio(zListaExpendios *);
	int SincronizaPreciosExpendio(zListaExpendios *);
	int RegistraRegimenFiscal(const char *,const char *);
	int BodegasExpendios(zBodegas **);
	int ExistenciaBodega(zExistenciaBodega *);
	int ActualizaExistenciaBodega(zExistenciaBodega *);
	int TransfiereBodegaBodega(zTransfiereBodegaBodega *pzTransfiereBB);
	int SeReflejoTransferencia(const char *pchrPtrEdo,const char *pchrPtrIdVenta);

	int VerificaConCuantoPago(zConCuantoPago *);
	int CambiosCaja(zCambiosCaja *);
	int CambioCaja(zCambioCaja *);
	int ValidaExistenciaBodega(const char *,zExistenciaBodega *);
	int AbonoAApartado(zAbonoAApartado *);
	int ConsultaComprasSiscom(const char *pchrPtrFechaIni,
			  	  const char *pchrPtrFechaFin,
			  	  zCompras *pzCompras);
private:
	void CambiaNoJuegos(zOrdenVenta *);
	void NoSePuedeVenderPorNoTenerPrecio(zOrdenVenta *);
private:
	zSiscomRegistro *FormaRegistroAgregarCorreo(zPersona *pzPersona,
						    zEmpresa *pzEmpresa,
						    zCorreos *pzCorreos);

	void AsignandoOrdenes(zSiscomRegistros *pzSisRegsOrden,
			 zOrdenes *pzOrdenes);
	void ProcesaErrorCambioDatosOrdenVenta(zSiscomRegistro *pzSiscomRegistro,
					       zOrdenVenta *pzOrdenVenta);

	void AsignandoDatosOrden(zSiscomRegistro *pzSisRegCotizacion,
			         zOrdenVenta *pzOrden);
	void AsignaDatosCotizacion(zSiscomRegistro *pzSisRegCotizacion,zOrdenVenta *pzOrden);
	void AsignaDatosApartado(zSiscomRegistro *pzSisRegCotizacion,zOrdenVenta *pzOrden);
	void AsignaDatosVenta(zSiscomRegistro *pzSisRegCotizacion,zOrdenVenta *);
	void AsignaDatosCancelacion(zSiscomRegistro *pzSisRegCotizacion,zOrdenVenta *);
	void AsignaDatosPedido(zSiscomRegistro *,zOrdenVenta *);
	void AsignaDatosNoDefinido(zSiscomRegistro *pzSisRegCotizacion,zOrdenVenta *);
	void AsignaDatosPagoTransferencia(zSiscomRegistro *pzSisRegCotizacion,zOrdenVenta *);
	void AsignaCompraImportacion(zSiscomRegistro *pzSisRegComImp,zCompraImportacion *);
	void AsignaComprasImportacion(zSiscomRegistros *pzSisRegsComImp,zComprasImportacion *);
	void AsignaProductosImportados(zSiscomRegistros *,zCompraImportacion *);
	void AsignaProveedoresCompraImportacion(zSiscomRegistros *,zCompraImportacion *);
	zProductoImportado *FormaProductoImportado(zSiscomRegistro *);

	int ObtenProductosSiscomProveedor(zProductosImportados *);
	int CambiosEnCaja(zCambiosCaja *);


private:
	void (zSiscomElectronica::*ErrorCambioDatosOrdenVenta[4])(zOrdenVenta *);
	void (zSiscomElectronica::*DatosTipoOrden[15])(zSiscomRegistro *,zOrdenVenta *);
	void IniciaAsignandoDatosOrden();
	void FormaProductoImportadoInf(zSiscomRegistro *, zProductoImportadoInf *);
	void FormaPesoProductoImportadoInf(zSiscomRegistro *,zProductoImportadoInf *);
	void FormaEscuelas(zSiscomRegistros *,zEscuelas *);
				
};
#endif
