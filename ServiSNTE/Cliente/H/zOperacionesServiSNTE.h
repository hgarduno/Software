#ifndef __ZOPERACIONESSERVISNTE_H__
#define __ZOPERACIONESSERVISNTE_H__
#include <zSiscomOperaciones.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zSiscomEnviaArchivo;
class zPersona;
class zDireccion;
class zEmpresa;

class zCamion;
class zDepartamento;

class zCosto;
class zProducto;
class zDescuento;
class zProductos;
class zOrden;
class zVenta;
class zCompra;
class zInventario;
class zTransferencia;
class zCreditosCliente;
class zContratoBeneficios;

class zCostos;
class zDescuentos;
class zTelefonos;
class zDatosGenerales;
class zEmpleo;
class zCargoPublico;
class zGeneralesBeneficios;
class zCorreo;
class zReferenciasPersonales;
class zCentroTrabajo;
class zDatosComunicacion;
class zCliente;
class zVentas;
class zReciboApartado;
class zFolio;
class zUsuario;
class zPrecio;
class zOperacionesServiSNTE:public zSiscomOperaciones 
{
public:
	zOperacionesServiSNTE(zSiscomConexion *pzSisConexion,
			   const char *pchrPtrFuncion,
			   const char *pchrPtrModulo="libSiscomServiSNTE.so");
	zOperacionesServiSNTE(zSiscomConexion *pzSisConexion,
			   const char *pchrPtrFuncion,
			   zSiscomRegistro *pzSisRegEnvio,
			   const char *pchrPtrModulo="libSiscomServiSNTE.so");
	void EnviaArchivoNomina(const char *pchrPtrArchivo,
				zSiscomEnviaArchivo *pzSisEnviaArchivo);
	zSiscomRegistros *ConceptosExistencias();
	zSiscomRegistros *TiendasEntrega();
	zSiscomRegistros *Vendedores(const char *pchrPtrTipoPersona);
	zSiscomRegistros *PerfilesSS(const char *pchrPtrTipoPersona);
	zSiscomRegistros *TipoDocumentos();
	zSiscomRegistros *Estados();
	zSiscomRegistros *TipoVentas();
	zSiscomRegistros *FormasEntrega();
	zSiscomRegistros *Financiadoras();
	zSiscomRegistros *ProveedoresSS();
	zSiscomRegistros *Plazos();
	zSiscomRegistros *Camiones();
	zSiscomRegistros *ReporteVentas(const char *pchrPtrRangoFecha,
					zSiscomRegistro *pzSisRegTienda,
					zSiscomRegistro *pzSisRegTipoVenta);
	zVentas *Ventas(const char *pchrPtrRFC);	
	
	zSiscomRegistros *ProductosSS(zSiscomRegistro *pzSisProveedor);
	zSiscomRegistros *ProductosCodigoBarras(zSiscomRegistro *pzSisProveedor);
	zSiscomRegistros *ProductosCodigoBarrasFechaCompra(const char *pchrPtrFecha);
	zSiscomRegistros *ProductosCodigoBarrasTodos();
	zSiscomRegistros *DepartamentosSS();
    	zSiscomRegistros *SumaProductosCodigoBarras(zSiscomRegistros *pzProductos);
    	zSiscomRegistros *DireccionesPersona(zPersona *pzPersona);
	zSiscomRegistro *ProductoCodigoBarras(const char *pchrPtrCodigoBarras);
	zSiscomRegistro *ProductoProveedor(const char *pchrPtrCodigoBarras);
	zSiscomRegistro *ProductoProveedor(zSiscomRegistro *pzSiscomRegEmpresa,
					   const char *pchrPtrNumProducto);
	zCliente *ValidaRfcParaVenta(const char *pchrPtrRFC,
                    const char *pchrPtrIdTipoVenta);
	int RegistraCliente(zPersona *pzPersona,char **pchrPtrRegreso);
	int ActualizaRFC(const char *pchrPtrIdPersona,const char *pchrPtrRFC);
	void RegistraDireccion(zDireccion *pzDireccion);
	void ActualizaDireccion(zDireccion *pzDireccion);
	void RegistraCamion(zCamion *pzCamion);
	void RegistraDepartamento(zDepartamento *pzDepartamento);
	void CalculaCostoProveedor(zCosto *pzCosto,zDescuento *);
	void CalculaPrecios(zPrecio *pzPrecio,zPrecio *pzPrecioForaneo,zCosto *);
	int CalculaPorcentajeGanancia(zCosto *pzCosto,const char *,char *pchrPtrGanancia);
			
	void AgregaPrecios(zProducto *pzProducto);
	void RegistraPrecios(zProducto *pzProducto);
	zProducto *CotizaProducto(const char *pchrPtrCantidad,
				    const char *pchrPtrCodigo);
	void CotizaOrden(zOrden *pzOrden);
	void RegistraVenta(zVenta *pzVenta);
	void RegistraCompra(zCompra *pzCompra);
	void CalculaTotalCompra(zOrden *pzOrden);
	void ProgramaInventario(zInventario *pzInventario);
	void PreRegistraInventario(zInventario *pzInventario);
	void RegistraInventario(zInventario *pzInventario);
	void ProgramaInventarioAlmacen(zInventario *pzInventario);
	void PreRegistraInventarioAlmacen(zInventario *pzInventario);
	void RegistraInventarioAlmacen(zInventario *pzInventario);
	void RegistraProducto(zProducto *pzProducto);
    	zSiscomRegistro *TransfiereATienda(zTransferencia *pzTransferencia);
	int ApartadosCliente(const char *,
		    zSiscomRegistro **pzSisRegTienda,
                    zSiscomRegistro **pzSisPersona,
                    zSiscomRegistros **,
		    char **pchrPtrFechaHoy);
	void AbonoAApartado(zSiscomRegistro *pzSisRegVenta,zReciboApartado *pzReciboApartado);
	void FijaFechaCompra(zSiscomRegistro *pzSisProveedor,
			     const char *pchrPtrFechaAFijar);
    int FechaCompraProveedor(zSiscomRegistro *pzSisProveedor,char *pchrPtrFechaCompra);
    zSiscomRegistros *ConsultaTransferencias(); 
    zSiscomRegistros *ConsultaContenidoTransferencia(zSiscomRegistro *pzSisRegTransferencia); 
    zSiscomRegistros *DetalleTransferencia(const char *pchrPtrIdTransferencia); 
    void ActualizaEstadoTransferencia(const char *pchrPtrIdTransferencia,
                    		      const char *pchrPtrIdEstado,
				      const char *pchrPtrIdTiendaEntrega);
    void RecibeTransferencia(zSiscomRegistros *pzSisRegsTransferencia);
    void RecibeTransferenciaParcial(zSiscomRegistros *pzProductosRecibidos,
                    zSiscomRegistros *pzProductosDevueltos); 
	zSiscomRegistro *VerificarInventarioEnCurso();
    void CancelaCapturaInventario(const char *pchrPtrIdInventario);
    zSiscomRegistros *RecuperaInventario(const char *pchrPtrIdInventario); 
    zSiscomRegistros *RecuperaInventarioAlmacen(const char *pchrPtrIdInventario); 
    zSiscomRegistro *VerificarInventarioEnCursoAlmacen();
    zCreditosCliente *CreditosCliente(const char *pchrPtrRFC);
    zSiscomRegistros *TipoViviendaSS();
    zSiscomRegistros *FrecuenciaPagosSS();
    zSiscomRegistros *FrecuenciaTransaccionalSS();
    zSiscomRegistros *ConsultaAbonosVenta(const char *pchrPtrIdVenta); 
    void CancelaAApartado(zSiscomRegistro *pzSisRegAbono);
    void CancelaApartado(zSiscomRegistro *pzSisRegApartado);
    int PreciosDescuentosProducto(zSiscomRegistro *,
    				  zCostos *pzCostosBruto,
				  zCostos *pzCostosGeneral,
				  zCostos *pzCostosForaneo,
				  zDescuentos *pzDescuentos);
    void ValidaLiquidacionApartado(zSiscomRegistro *pzSisRegApartado);
    zSiscomRegistro *RegistraContratoBeneficios(zContratoBeneficios *pzContBeneficios);

    int RegistraTelefonos(zTelefonos *pzTelefonos);
    int RegistraGenerales(zDatosGenerales *pzDatGenerales);
    int RegistraEmpleo(zEmpleo *pzEmpleo);
    int RegistraDatosCasa(const char *pchrPtrIdDireccion,
    			  const char *pchrPtrIdTipoVivienda,
			  const char *pchrPtrTiempoResidir);
    int RegistraCargoPublico(zCargoPublico *pzCargoPublico);
    int RegistraGeneralesBeneficios(zGeneralesBeneficios *pzGenBeneficios);
    int RegistraReferenciasPersonales(zReferenciasPersonales *pzRefsPersonales);
    int RegistraCentroTrabajo(zCentroTrabajo *pzCentroTrabajo);
/*
    int ActualizaGenerales(zDatosGenerales *pzDatGenerales);
    int ActualizaDatosComunicacion(zDatosComunicacion *pzSisDatComunicacion);
*/
    int CompletaContratoBeneficiosIntegrales(zContratoBeneficios *pzConBeneficios);
    zPersona *PersonaRegistrada(const char *pchrPtrNombre,
    				const char *pchrPtrAPaterno,
				const char *pchrPtrAMaterno);
    zEmpresa *EmpresaRegistrada(const char *pchrPtrRazonSocial);
    zSiscomRegistro *CreditosBeneficiosIntegrales();
    zSiscomRegistros *ExistenciasTienda(zSiscomRegistro *pzSisRegTienda);
    zSiscomRegistros *ExistenciaTiendaProducto(zSiscomRegistro *pzSisRegTienda,zSiscomRegistro *pzSisRegProducto);
    zSiscomRegistros *ExistenciasTiendaProveedor(zSiscomRegistro *pzSisRegProducto);
    zSiscomRegistros *ExistenciasTiendaListaProductos(const char *pchrPtrIdTienda,
    						      const char *pchrPtrListaProductos);
    zSiscomRegistros *ExistenciasAlmacen();
    zSiscomRegistros *ExistenciaAlmacenProducto(zSiscomRegistro *pzSisRegProducto);
    zSiscomRegistros *ExistenciasAlmacenProveedor(zSiscomRegistro *pzSisRegProveedor);
    zSiscomRegistros *ExistenciasAlmacenListaProductos(const char *pchrPtrListaProductos);
    zSiscomRegistros *ReporteCompras(const char *pchrPtrRangoFechas);
    zSiscomRegistros *ReporteComprasDetalle(zSiscomRegistro *pzSisRegCompra);
    void ActualizaPrecioCompra(zSiscomRegistro *pzSisRegActPrecioCompra);
    zSiscomRegistros *TransferenciasEnviadas(const char *pchrPtrRangoFecha);
    zSiscomRegistros *CamposImpresionPuntoVenta();
    zSiscomRegistros *CamposImpresionReciboApartado();
    zSiscomRegistros *CamposImpresionTransferencia();
    zSiscomRegistros *CamposImpresionListaPrecios();
    zSiscomRegistros *CamposImpresionListaPreciosComprador();
    zSiscomRegistros *CamposImpresionStockTienda();
    zSiscomRegistros *CamposImpresionExistenciaProveedor();
    zSiscomRegistros *CamposImpresionExistenciaTiendaProveedor();
    zSiscomRegistros *CamposImpresionRelacionChequesPagar();
    zSiscomRegistros *CamposImpresionSoporteCompras();
    zSiscomRegistros *CamposImpresionSoporteVentas();
    zSiscomRegistros *CamposImpresionDatosCompra();
    zSiscomRegistros *CamposImpresionCuentasPagar();
    zSiscomRegistros *CamposImpresionStockProveedorCosto();
    zSiscomRegistros *CamposImpresionProveedores();
    zSiscomRegistros *CamposImpresionSoporteTransferencias();
    void CostoPrecioTransferencia(zOrden *pzOrden);
    void RegistraFolio(zFolio *pzFolio);  
    zSiscomRegistros *TiposFolio();
    int FolioActualFactura(const char *pchrPtrIdTipoFolio,char *pchrPtrFolio);
    int CancelarFolioFactura(zVenta *pzVenta,
    			     const char *pchrPtrNuevoFolio,
			     const char *pchrPtrMotivo);

     zSiscomRegistros *FoliosCanceladosPorTienda(zSiscomRegistro *pzSisRegTienda, 
							const char *pchrPtrFechaInicio,
							const char *pchrPtrFechaFinal);
    int RFCRegistradoBaseDatos(const char *pchrPtrRFC);
    zSiscomRegistro *RegistraUsuario(zUsuario *pzUsuario);
    int ActivaDesactivaServidor(const char *pchrPtrIdTienda,
    				const char *pchrPtrActivo);
     int ActualizaStock(zSiscomRegistro *pzSisRegTienda,
			 zSiscomRegistro *pzSisRegProducto,
			 const char *pchrPtrCantidad);
private:
	void AgregaGeneralesContrato(zSiscomRegistro *pzSisRegDatos,
				     zContratoBeneficios *pzConBeneficios);
	void AgregaGeneralesBeneficios(zSiscomRegistro *pzSisRegDatos,
					zContratoBeneficios *pzConBeneficios);
	void AgregaDatosCasa(zSiscomRegistro *pzSisRegDatos,
			     zContratoBeneficios *pzConBeneficios);
	void AgregaDatosComunicacion(zSiscomRegistro *pzSisRegDatos,
				     zContratoBeneficios *pzConBeneficios);
	void AgregaDatosEmpleo(zSiscomRegistro *pzSisRegDatos,
			       zContratoBeneficios *pzConBeneficios);
	void AgregaReferenciasPersonales(zSiscomRegistro *pzSisRegDatos,
	 				  zContratoBeneficios *pzConBeneficios);
	void AgregaCentroTrabajo(zSiscomRegistro *pzSisRegDatos,
	 			  zContratoBeneficios *pzConBeneficios);
	
	  
};
#endif
