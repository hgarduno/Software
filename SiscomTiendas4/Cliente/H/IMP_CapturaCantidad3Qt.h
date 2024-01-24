#ifndef __IMPCAPTURACANTIDAD3QT_H__
#define __IMPCAPTURACANTIDAD3QT_H__
#include <UIC_H_CapturaCantidad.h>

class SiscomDatCom;
class SiscomRegistro3;


class QCapturaCantidad3Qt:public CapturaCantidad
{
Q_OBJECT
public:
	QCapturaCantidad3Qt(SiscomRegistro3 *pSis3ProdCot3Qt,
			    QWidget *pQWParent=0,
			    const char *pchrPtrName=0,
			    bool pbModal=false,
			    WFlags pWFlags=0);
	~QCapturaCantidad3Qt();
private:
	void IniciaVariables();
	void ConectaSlots();
private:
	SiscomRegistro3 *SReg3Producto;
	int intOpcion;
private slots:
	void SlotAceptar();
	void SlotCancelar();
	void SlotPasaFocoAceptar();
};

#endif
