
#ifndef __IMP_CAPTURADATOSFACTURA_H__
#define __IMP_CAPTURADATOSFACTURA_H__
#include <UIC_H_CapturaDatosFactura.h>
class zFactura;
class QCapturaDatosFactura:public CapturaDatosFactura
{
 Q_OBJECT
public:
	QCapturaDatosFactura(
		zFactura *pzFactura,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCapturaDatosFactura();
private:
	zFactura *zFacturaD;
private:
	void ConectaSlots();
	void IniciaVariables();
	zFactura *Factura();
private slots:
	void SlotFocoAImporte();
	void SlotFocoATotal();
	void SlotFocoAAceptar();
	void SlotFocoAIVA();
	void SlotAceptar();
};
#endif
