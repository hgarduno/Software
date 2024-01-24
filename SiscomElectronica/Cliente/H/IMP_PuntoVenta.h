#ifndef __IMP_PUNTOVENTA_H__
#define __IMP_PUNTOVENTA_H__
#include <UIC_H_PuntoVenta.h>
#include <zOrdenVenta.h>
class zSiscomConexion;
class SiscomDatCom;
class zSiscomRegistro;

class QPuntoVenta:public PuntoVenta
{
 Q_OBJECT
public:
	QPuntoVenta(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPuntoVenta();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	char chrArrArchivoHtmlPuntoVenta[16132];
	char chrArrEncabezadoPuntoVenta[16132];
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;

	zOrdenVenta *zOrdVenta;
	zOrdenVenta *zOrdCotProducto;
	zProductoCotizar *zProdCotizar;
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
	void MuestraOrdenCotizada(zOrdenVenta *pzOrdVenta);
private slots:
	void SlotCargaArchivoHtml();
	void SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto);
	void SlotFocoAProductos();
	void SlotIncrementaTexto();
	void SlotDecrementaTexto();
	
	void SlotSeleccionoLink(const QString &);
	void SlotClicked(int,int);
	void SlotSeleccionoLink(const QString &,const QString &);
	void SlotAnexarOrden();

};
extern "C" QPuntoVenta *InstanciaPuntoVenta(void *,char **,void *,const char *,int);
#endif
