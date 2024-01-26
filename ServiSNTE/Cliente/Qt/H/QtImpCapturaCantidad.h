#ifndef __QTIMPCAPTURACANTIDAD_H__
#define __QTIMPCAPTURACANTIDAD_H__
#include <cstddef>
#include <CapturaCantidad.h>

class QtImpCapturaCantidad:public CapturaCantidad
{
Q_OBJECT
public:
	QtImpCapturaCantidad(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	int Aceptar();
	void Cantidad(QString *);
private:
	void ConectaSlots();
private:
	int intAceptar;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotCantidad();

};
#endif
