#ifndef __QTIMPREGISTROCOMPRAS_H__
#define __QTIMPREGISTROCOMPRAS_H__
#include <cstddef>
#include <RegistroCompras.h>
#include <zCompra.h>
#include <zProductos.h>
#include <zOrden.h>
class zSiscomConexion;
class zSiscomRegistro;
class zCosto;

class QtImpRegistroCompras:public RegistroCompras
{
Q_OBJECT
public:
	QtImpRegistroCompras(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
private:
	void IniciaControles();
	void HabilitaTipoDocumento();
	void HabilitaSerieFactura();
	void HabilitaStockYProductos();
	void FocoASerieProducto();
	void AgregaProductoCompra();
	void MuestraCompra();
	void HabilitaRegistraCompra();
	void RegistraCompra();
	void IniciaRegistroCompra();

	void AgregandoProducto();
	void ProductosALaCompra();
	void ObtenFechaCompra();
	void ReIniciaCompras();
	void CambiaCantidad(int pintNProducto);
	void CambiandoCantidad(int pintNProducto);
	void CreaListaProductos(QString &pQStrProductos);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisProveedor;
	zSiscomRegistro *zSisTipoDocumento;
	zSiscomRegistro *zSisConcepto;
	zSiscomRegistro *zSisProducto;
	zCompra zCompraC;
	zProductos zProdsOrden;
	zOrden zOrdenCompra;

	int intProductoSeleccionado;

	int intFechaCompraRegistrada;

private slots:

	void SlotProveedor(zSiscomRegistro *pzSisProveedor);
	void SlotTipoDocumento(zSiscomRegistro *pzSisTipoDocumento);
	void SlotConcepto(zSiscomRegistro *pzSisConcepto);
	void SlotProducto(zSiscomRegistro *pzSisProducto);
	void SlotFocoAFolio();
	void SlotFocoAConcepto();
	void SlotFocoAAgregar();
	void SlotFocoACantidad();
	void SlotHabilitaBotonAgregar();
	void SlotAgregarProducto();
	void SlotRegistraCompra();

	void SlotProductoOrden(int pintNFila,int,int,const QPoint &);
	void SlotEliminarProductoOrden();
	void SlotCambiaCantidad(int pintFila,int pintColumna,int ,const QPoint &);
	void SlotFocoATipoDocumento();

	void SlotCopiar();
				
};



#endif
