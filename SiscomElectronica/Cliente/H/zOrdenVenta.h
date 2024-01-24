#ifndef __ZORDENVENTA_H__
#define __ZORDENVENTA_H__
#include <zSiscomRegistro.h>

class zProductos;
class zProductoCotizar;
class zSiscomRegistros;
class zClienteSiscom;
class zApartado;
class zCotizacion;
class zPedido;
class zCircuitoImpreso;
class zMaterialAAreaDiseno;
class zDonacionMaterial;
class zExpendio;
class zConexionExpendio;
class zFormaPago;
class zOrdenVenta:public zSiscomRegistro
{

public:
	zOrdenVenta(const char *pchrPtrIdVenta,const char *pchrPtrIdExpendio);
	zOrdenVenta();
	zOrdenVenta(zOrdenVenta *);
	zOrdenVenta(zSiscomRegistro *pzSisRegOrdenVenta);
	~zOrdenVenta();
	zOrdenVenta *ConsultaOrdenes2(zSiscomRegistro *);
	void AsignaOrdenVenta(zSiscomRegistro *);
	void AsignaOrdenConsultada(zSiscomRegistro *pzSisOrden);
	void AgregaProducto(zProductoCotizar *pzProdCotizar);
	void AgregandoProductos(zSiscomRegistros *pzSisRegsProductos,zOrdenVenta *);
	void Descripcion(const char *pchrPtrDescripcion);
	/* Tepotzotlan Mexico A 25/10/2020
	 * En plena crisis del COVID-19 
	 */
	void AgregandoProductos(zSiscomRegistros *);
	void ActualizaOrden(zSiscomRegistro *pzSisRegRespuesta);
	void IdVenta(const char *pchrPtrIdVenta);
	void IdExpendio(const char *pchrPtrIdExpendio);
	void IdVendedor(const char *pchrPtrIdVendedor);
	void Importe(const char *pchrPtrImporte);
	void Cliente(zClienteSiscom *pzCliSiscom);
	void Juegos(const char *pchrPtrJuegos);
	void JuegosNuevo(const char *pchrPtrJuegos);
	void JuegosSeparados(const char *pchrPtrJuegos);
	void JuegosNuevoSeparados(const char *pchrPtrJuegos);
	void DescuentoOrden(const char *pchrPtrDescuento);
	void IdTipoOrden(const char *pchrPtrIdTipoOrden);
	void NumProductos(int);
	void Apartado(zApartado *pzApartado);
	void Cotizacion(zCotizacion *pzCotizacion);
	void Pedido(zPedido *pzPedido);
	void CircuitoImpreso(zCircuitoImpreso *pzCirImpreso);
	void MaterialAAreaDiseno(zMaterialAAreaDiseno *pzMatAADiseno);
	void DonacionMaterial(zDonacionMaterial *pzDonacionM);
	void SeImprimeTicket(const char *pchrPtrSeImprimeTicket);

	void FormaPago(zFormaPago *);
	void Fecha(const char *pchrPtrFecha);
	zPedido *Pedido();
	zClienteSiscom *Cliente();
	zCotizacion *Cotizacion();
	zCircuitoImpreso *CircuitoImpreso();
	const char *Clave(int pintNProducto);
	const char *Cantidad(int pintNProducto);
	const char *Existencia(int pintNProducto);
	const char *ExBodega(int pintNProducto);
	const char *Precio(int pintNProducto);
	const char *Importe(int pintNProducto);
	const char *Descripcion(int pintNProducto);
	const char *IdTipoOrden();
	const char *IdExpendio();
	int IdTipoOrdenInt();
	zProductoCotizar *Producto(int pintNProducto);
	zProductoCotizar *ProductoPorIdConsecutivo(int pintIdConsecutivo);
        int ProductosCotizados();
	int NumKitsPracticasEtc();
	int NumProductos();
	const char *ImporteOrden();
	const char *IdVenta();
	const char *Juegos();
	const char *JuegosNuevo();
	const char *DescuentoOrden();
	const char *Descripcion();
	const char *Fecha();
	void EliminaProducto(zProductoCotizar *pzProdCotizar);
	void EliminaProductos(zProductos *pzProductos);
	void AsignaProductos(zSiscomRegistros *pzSisRegProductos);
	void ProductosALaOrden(zSiscomRegistros *pzSisRegsProductos);
	zSiscomRegistros *Productos();
	void EliminaProductosOrden();
	zOrdenVenta *DuplicaOrden();
	int SePuedeVender();
	void SePuedeVender(const char *);
	void OrdenPrecioEspecial();
	zConexionExpendio *Expendio();
	void Expendio(zConexionExpendio *);
	int EsCotizacion();
	int SePagoConTransferencia();
	zFormaPago *FormaPago();
private:
	void ActualizaDatosProductos(zSiscomRegistros *pzSisRegsProdsRespuesta);
	void ActualizaProducto(zSiscomRegistro *pzSisRegProducto);

	const char *CampoProducto(int pintNProducto,const char *pchrPtrCampo);

};
void ImprimeOrdenVenta(const char *pchrPtrArchivo,
		       const char *pchrPtrFuncion,
		       int pintNoLinea,
		       zOrdenVenta *pzSisOrdenVenta);

#define LogOrdenVenta(pzOrdenVenta) \
	ImprimeOrdenVenta(__FILE__,__FUNCTION__,__LINE__,pzOrdenVenta);
#endif
