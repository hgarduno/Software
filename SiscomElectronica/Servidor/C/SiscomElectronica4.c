#include <SiscomElectronica4.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>

#include <SistemaPedidos.h>
#include <ProductosSE.h>
#include <EscuelasSE.h>
#include <Cotizando4.h>
#include <OrdenesVendidas.h>
#include <Facturando4.h>
#include <ExistenciaExpendios.h>
#include <Clientes4.h>
#include <ImpresionTicketVenta.h>
#include <RegistraOrden.h>
#include <OrdenesVendidas.h>
#include <Practicas.h>
#include <ReportesSiscom.h>
#include <TransferenciasExpendioAExpendio.h>
#include <ImpresionTransferencias.h>
#include <CircuitosImpresos.h>
#include <ClavesSatSiscom.h>
#include <GastosExpendio.h>
#include <PedidosExpendio.h>
#include <Proveedores4.h>
#include <PesoProducto.h>
#include <CompraImportacion.h>
#include <OrdenRapida.h>
#include <ProductosSiscom.h>
#include <RegistraUsuario.h>
#include <Seguridad3.h>
#include <Precios.h>
#include <CotizacionImportacion.h>
#include <Empresas.h>
#include <CatalogosSat.h>
#include <Devoluciones4.h>
#include <ClavesProveedor.h>
#include <OrdenCompraImportacion.h>
#include <UbicacionMaterial.h>
#include <OrdenesFavoritas.h>
#include <CorteCaja.h>
#include <PuntosEntrega.h>
#include <JTExpress.h>
#include <PedidosCliente.h>
#include <Contenedor.h>
#include <SincronizaExpendios.h>
#include <Bodegas4.h>
#include <FormaPago.h>
#include <AbonoAApartado.h>
#include <ComprasSiscom.h>
typedef struct  siscomElectronica4
{
  char *chrPtrFuncion;
  void (*SiscomElectronica4)(int pintSocket,
  			  SiscomRegistroProL *pSiscomRegProLPtrPrim,
			  SiscomRegistroProL *pSiscomRegProLPtrAct);
}StcSiscomElectronica4;



int EjecutaFuncionProtocolo4(StcSiscomElectronica4 *pStcSiscomElectronica4,
			      const char *pchrPtrFuncion,
			      int pintSocket,
			      SiscomRegistroProL *pSiscomRegProLPtrPrim,
			      SiscomRegistroProL *pSiscomRegProLPtrAct)
{

    while(pStcSiscomElectronica4->chrPtrFuncion)
    {
	if(!strcmp(pStcSiscomElectronica4->chrPtrFuncion,pchrPtrFuncion))
	{
	pStcSiscomElectronica4->SiscomElectronica4(pintSocket,
					           pSiscomRegProLPtrPrim,
						   pSiscomRegProLPtrAct);
	 return 1;
	}
	pStcSiscomElectronica4++;
    }

return 0;
}


void SiscomProtocoloVersion4(int pintSocket)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
StcSiscomElectronica4 lStcSiscomElectronica4[]=
		     { 
			{"OrdenesPendientes",OrdenesPendientes},
			{"ProductosSE",ProductosSE},
			{"EscuelasSE",EscuelasSE},
			{"EstadosImpresosSE",EstadosImpresosSE},
			{"CotizandoProductos4",CotizandoProductos4},
			{"OrdenesVendidas",OrdenesVendidas},
			{"OrdenesVendidas2",OrdenesVendidas2},
			{"CalculaFactura",CalculaFactura},
			{"RegistraClienteFacturacion",RegistraClienteFacturacion},
			{"RealizaFactura",RealizaFactura},
			{"ValidaRfcRegistrado",ValidaRfcRegistrado},
			{"AgregaCorreoCliente",AgregaCorreoCliente},
			{"ExistenciaExpendios",ExistenciaExpendios},
			{"ValidaReCaptura",ValidaReCaptura},
			{"RegistraClientePersona",RegistraClientePersona},
			{"RegistraCelularAlumno",RegistraCelularAlumno},
			{"RegistraCorreoAlumno",RegistraCorreoAlumno},
			{"RegistraDireccionAlumno",RegistraDireccionAlumno},
			{"ImprimeTicketVenta4",ImprimeTicketVenta4},
			{"ObtenIdOrden",ObtenIdOrden},
			{"RegistraOrden",RegistraOrden},
			{"PublicoEnGeneral",PublicoEnGeneral},
			{"OrdenesApartados",OrdenesApartados},
			{"DireccionEscuela",DireccionEscuela},
			{"PagarApartado",PagarApartado},
			{"ProductoEnApartados",ProductoEnApartados},
			{"RegistraPractica",RegistraPractica},
			{"ConsultaOrden",ConsultaOrdenVendida},
			{"ReporteVentas4",ReporteVentas4},
			{"ValidaCantidadATransferir",ValidaExistenciaATransferir},
			{"ExistenciaExpendioOrigenDestino",ExistenciaExpendioOrigenDestino},
			{"ValidandoTransferenciaExpendioOrigen",ValidandoTransferenciaExpendioOrigen},
			{"TransfiereExpendioAExpendio",TransfiereExpendioAExpendio},
			{"TransferenciaOtrosExpendios",TransferenciaOtrosExpendios},
			{"ImprimePedidoOtrosExpendios",ImprimePedidoOtrosExpendios},
			{"RegistraCircuitoImpreso",RegistraCircuitoImpreso},
			{"CircuitosImpresosPendientes",CircuitosImpresosPendientes},
			{"ImpresosPorEstadoFecha",ImpresosPorEstadoFecha},
			{"CircuitoImpresoActualizaEdo",CircuitoImpresoActualizaEdo},
			{"TiposProductoSE",TiposProductoSE},
			{"DatosParaReEnvioFactura",DatosParaReEnvioFactura},
			{"ReEnviaFactura",ReEnviaFactura},
			{"RegistraClaveSat",RegistraClaveSat},
			{"ClaveSat",ClaveSat},
			{"GastosSiscom",GastosSiscom},
			{"PedidoExpendioHoy",PedidoExpendioHoy},
			{"IniciaPedidoExpendioHoy",IniciaPedidoExpendioHoy},
			{"ProductoAPedidoExpendio",ProductoAPedidoExpendio},
			{"EliminaProductoPedido",EliminaProductoPedido},
			{"ActualizaProductoPedido",ActualizaProductoPedido},
			{"RegistraPedido",RegistraPedido},
			{"ActualizaObservacionesPedido",ActualizaObservacionesPedido},
			{"OrdenesParaFacturar",OrdenesParaFacturar},
			{"ExpendiosSiscom",ExpendiosSiscom},
			{"ProveedoresSE",Proveedores4},
			{"PesoProducto",PesoProducto},
			{"RegistraPesoProducto",RegistraPesoProducto},
			{"CompraImportacion",CompraImportacion},
			{"RegistraCompraImportacion",RegistraCompraImportacion},
			{"ProductosPorFiltroComprasImportacion",ProductosPorFiltroComprasImportacion},
			{"CierraDia",CierraDia},
			{"OrdenEscuelaPrincipal",OrdenEscuelaPrincipal},
			{"ClientesMayoreo",ClientesMayoreo},
			{"DefinicionProducto",ObtenDefinicionProducto},
			{"ComprandoProductoSiscom",ComprandoProductoSiscom},
			{"IdCompraProductoSiscom",IdCompraProductoSiscom},
			{"RegistraUsuario",RegistraUsuarioSiscom},
			{"PerfilesAplicacion",PerfilesAplicacion},
			{"PracticaRegistrada",PracticaRegistrada},
			{"ConsultaCompraImportacion",ConsultaCompraImportacion},
			{"ActualizaInventarioParaPedido",ActualizaInventarioParaPedido},
			{"TransfiereBodegaExpendioParaPedido",TransfiereBodegaExpendioParaPedido},
			{"PreciosExpendios",PreciosExpendios},
			{"Precios2Productos",Precios2Productos},
			{"ConsultandoCotizacionImportacion",ConsultandoCotizacionImportacion},
			{"RegistrandoCotizacionImportacion",RegistrandoCotizacionImportacion},
			{"RegistraProductoCotizaImportacion",RegistraProductoCotizaImportacion},
			{"SeleccionoCotizaImportacion",SeleccionoCotizaImportacion},
			{"Direcciones",Direcciones},
			{"RFCs",RFCs},
			{"FormasPagoSat",FormasPagoSat},
			{"MetodoPagoSat",MetodoPagoSat},
			{"UsoFacturaSat",UsoFacturaSat},
			{"GuardaCompraImportacion",GuardaCompraImportacion},
			{"GuardaCompraImportacionComo",GuardaCompraImportacionComo},
			{"ComprasImportacion",ConsultaComprasImportacion},
			{"DevolucionOrden",DevolucionOrden},
			{"RegistraClavesProveedor",RegistraClavesProveedor},
			{"ValidaClaveRegistrada",ValidaClaveRegistrada},
			{"ProductoCompraImportacion",ProductoCompraImportacion},
			{"CalculandoPesoImporteTotal",CalculandoPesoImporteTotal},
			{"ActualizaPeso",ActualizaPesoProducto},
			{"CajasMaterial",CajasMaterial},
			{"RegistraCajaMaterial",RegistraCajaMaterial},
			{"AsignaCajaProducto",AsignaCajaProducto},
			{"UbicacionDeLaDescripcion",UbicacionDeLaDescripcion},
			{"Estantes",Estantes},
			{"ProductoImportadoInf",ProductoImportadoInf},
			{"RegistraOrdenesFavoritas",RegistraOrdenesFavoritas},
			{"ConsultaOrdenesFavoritas",ConsultaOrdenesFavoritas},
			{"EliminaOrdenesFavoritas",EliminaOrdenesFavoritas},
			{"CalculaCorteCaja",CalculaCorteCaja},
			{"ValidandoCompraProductoSiscom",ValidandoCompraProductoSiscom},
			{"OrdenOtro",OrdenOtro},
			{"RegistraPuntoEntrega",RegistraPuntoEntrega},
			{"PuntosEntrega",PuntosEntrega},
			{"CalculaCambioPago",CalculaCambioPago},
			{"JTExpressCobertura",JTExpressCobertura},
			{"EstadosPedidosCliente",EstadosPedidosCliente},
			{"ActualizaEstadoPedidoCliente",ActualizaEstadoPedidoCliente},
			{"EntregaEscuela",EntregaEscuela},
			{"ActualizaDescripcionCotizacion",ActualizaDescripcionCotizacion},
			{"ActualizaClaveProveedor",ActualizaClaveProveedor},
			{"AgregaFacturaContenedor",AgregaFacturaContenedor},
			{"CompletaProductosImportacion",CompletaProductosImportacion},
			{"ActualizaPrecioExpendios",ActualizaPrecioExpendios},
			{"SincronizaProductosExpendio",SincronizaProductosExpendio},
			{"RegistroParcialCompraImportacionFaltaronProductos",RegistroParcialCompraImportacionFaltaronProductos},
			{"RegimenFiscal",RegimenFiscal},
			{"RegistraRegimenFiscal",RegistraRegimenFiscal},
			{"BodegasExpendios",BodegasExpendios},
			{"ExistenciaBodega4",ExistenciaBodega4},
			{"ActualizaExistenciaBodega4",ActualizaExistenciaBodega4},
			{"OrdenParaFacturar",OrdenParaFacturar},
			{"TransfiereBodegaBodega",TransfiereBodegaBodega},
			{"YaSeReflejoTransferencia",YaSeReflejoTransferencia},
			{"VerificaConCuantoPago",VerificaConCuantoPago},
			{"RegistraCambioCaja",RegistraCambioCaja},
			{"CambiosCaja",CambiosCaja},
			{"ConsultaCambioCaja",ConsultaCambioCaja},
			{"CambiosRegistrados",CambiosRegistrados},
			{"ActualizacionCompraRegistrada",ActualizaCompraImportacionRegistrada},
			{"RegistraCorteCajaSucursal",RegistraCorteCajaSucursal},
			{"ValidaExistenciaBodega",ValidaExistenciaBodega},
			{"AbonoAApartado",AbonoAApartado},
			{"ExistenciaSiscom",ExistenciaSiscom},
			{"ExistenciaSiscomT",ExistenciaSiscomT},
			{"ConsultaComprasSiscom",ConsultaComprasSiscom},
			{0,0}
		     };
const char *lchrPtrFuncion;
SiscomLeeRegistrosSocket(pintSocket,
			 lchrArrBuffer,
			 &lSiscomRegProLPtrPrim,
			 &lSiscomRegProLPtrAct);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"ModuloServidor",lSiscomRegProLPtrPrim);
lchrPtrFuncion=SiscomCampoRegistroAsociado("ModuloServidor",
					   "Funcion",
					   lSiscomRegProLPtrAct);
if(!EjecutaFuncionProtocolo4(lStcSiscomElectronica4,
			     lchrPtrFuncion,
			     pintSocket,
			    lSiscomRegProLPtrPrim,
			    lSiscomRegProLPtrAct))
LogSiscom("La Funcion %s No Esta en el arreglo",lchrPtrFuncion); 
}

