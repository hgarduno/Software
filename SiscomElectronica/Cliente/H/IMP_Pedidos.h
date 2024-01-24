#ifndef __IMP_PEDIDOS_H__
#define __IMP_PEDIDOS_H__
#include <UIC_H_Pedidos.h>
#include <zOrdenVenta.h>

class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;

class zClienteSiscom;

class QPedidos:public Pedidos
{
 Q_OBJECT
public:
	QPedidos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPedidos();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;


	zOrdenVenta *zOrdVenta;
	zOrdenVenta *zOrdCotProducto;
	zProductoCotizar *zProdCotizar;
	zClienteSiscom *zSisCliSiscom;
	int intIdConsecutivo;
	zSiscomRegistro *zSisRegEdoCotizacion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraPuntoVenta();
	void CargaArchivoHtmlPuntoVenta();
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void CotizandoProducto(zSiscomRegistro *pzSisRegProducto);
	void MuestraCotizacionProducto(zOrdenVenta *pzOrdVenta);
	void IniciaOrden();
	void CotizandoOrden();
	void CotizaOrden();
	void MuestraOrdenCotizada(zOrdenVenta *pzOrdenVenta);
	void MuestraDatosCliente();
	void MuestraProducto(int pintNProducto,zProductoCotizar *);
	void MuestraDefinicionProducto(zProductoCotizar *);
	int NoEsProducto(zProductoCotizar *pzProdCotizar);
	void MuestraProductos(zOrdenVenta *);
	void MuestraNoProductos(zOrdenVenta *);
private slots:
	void SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto);
	void SlotAnexarOrden();
	void SlotFocoAProducto();
	void SlotDatosCliente();
	
};
extern "C" QPedidos *InstanciaPedidos(void *,char **,void *,const char *,int);
#endif
