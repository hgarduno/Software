#ifndef __QTIMPCAPTURAPRECIOIVA_H__
#define __QTIMPCAPTURAPRECIOIVA_H__
#include <cstddef>
#include <CapturaPrecioIva.h>

class QtImpCapturaPrecioIva:public CapturaPrecioIva
{
Q_OBJECT
public:
	QtImpCapturaPrecioIva(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	int Aceptar();
	void Cantidad(QString *);
	void PrecioIva(QString *pQSPrecio,QString *pQSIva);
private:
	void ConectaSlots();
	void IniciaVariables();
private:
	int intAceptar;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotCantidad();
	void SlotFocoAIva();
	void SlotFocoAceptar();

};
#endif
