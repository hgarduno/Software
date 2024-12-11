#ifndef __QTABONOAAPARTADO_H__
#define __QTABONOAAPARTADO_H__
#include <UIC_H_AbonoAApartado.h>


class zOrdenVenta;
class zAbonoAApartado;
class QtAbonoAApartado:public AbonoAApartado
{
Q_OBJECT

public:
	QtAbonoAApartado(zOrdenVenta *pzOrden,
			 QWidget *pQWParent=0,
			 const char *pchrPtrName=0,
			 bool pbModal=false,
			 WFlags pWFlags=false);
	zAbonoAApartado *AbonoAApartadoD();
	zOrdenVenta *Orden();
private:
	void IniciaVariables();
	void ConectaSlots();
	virtual void Registrar();
private:
	zAbonoAApartado *zAAApartado;
	zOrdenVenta *zOrden;
private slots:
	void SlotFocoARegistrar();
	void SlotRegistrar();

};

#endif
