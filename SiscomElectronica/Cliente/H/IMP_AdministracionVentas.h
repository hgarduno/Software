
#ifndef __IMP_ADMINISTRACIONVENTAS_H__
#define __IMP_ADMINISTRACIONVENTAS_H__
#include <UIC_H_AdministracionVentas.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;
class zOrdenVenta;
class zProductoCotizar;
class QAdministracionVentas:public AdministracionVentas
{
 Q_OBJECT
public:
	QAdministracionVentas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QAdministracionVentas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;

	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	zOrdenVenta *zOrdVenta;
	zOrdenVenta *zOrdCotProducto;
	zProductoCotizar *zProdCotizar;
private:
	void ConectaSlots();
	void IniciaVariables();
	void CotizandoProducto(zSiscomRegistro *pzSisRegProducto);
	void MuestraCotizacionProducto(zOrdenVenta *pzOrdVenta);
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void CotizaOrden();
	void CotizandoOrden();
	void MuestraOrdenCotizada(zOrdenVenta *);
	void IniciaOrden();
private slots:
	void SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto);
	void SlotFocoAProductos();
	void SlotAnexarOrden();
};
extern "C" QAdministracionVentas *InstanciaAdministracionVentas(void *,
								char **,
								void *,
								const char *,
								int);
#endif
