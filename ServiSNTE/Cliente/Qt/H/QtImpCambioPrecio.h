#ifndef __QTIMPCAMBIOPRECIO_H__
#define __QTIMPCAMBIOPRECIO_H__
#include <cstddef>
#include <CambioPrecio.h>


class zProducto;
class QtImpCambioPrecio:public CambioPrecio
{
Q_OBJECT
public:
	QtImpCambioPrecio(zProducto *pzProducto,
			  QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	int Aceptar();
private:
	void ConectaSlots();
	void MuestraInformacion();
	void CambiaPrecio();
private:
	int intAceptar;
	zProducto *zProdCambiar;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotAMotivoCambio();

};
#endif
