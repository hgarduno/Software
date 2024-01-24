
#ifndef __IMP_FORMAPAGO_H__
#define __IMP_FORMAPAGO_H__
#include <UIC_H_FormaPago.h>

#include <zFormaPago.h>
#include <IMP_ComoPago.h>
class QFormaPago:public FormaPago
{
 Q_OBJECT
public:
	QFormaPago(QComoPago::FormaDePago pQCPForma,
	zOrdenVenta *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QFormaPago();
	zFormaPago *ObtenFormaPago();
private:
	zFormaPago *zFPago;
	QComoPago::FormaDePago QCPForma;
	zOrdenVenta *zOVenta;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ActivaFormaPago();
	zOrdenVenta *Orden();
private slots:

	void SlotAceptar();
	void SlotCancelar();
};
#endif
