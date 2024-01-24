
#ifndef __IMP_SEPAGAORDENIMPRESO_H__
#define __IMP_SEPAGAORDENIMPRESO_H__
#include <UIC_H_SePagaOrdenImpreso.h>

class zOrdenVenta;
class QSePagaOrdenImpreso:public SePagaOrdenImpreso
{
 Q_OBJECT
public:
	QSePagaOrdenImpreso(
	    zOrdenVenta *pzOrdVenta,
	    int pintNImpresos,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QSePagaOrdenImpreso();
	int SePagaCompleto();
	void ACuenta(char *pchrPtrAdelanto);
private:
	zOrdenVenta *zOrdVenta;
	int intImpresosOrden;
	int intSePagaCompleto;
private:
	void ConectaSlots();
	void IniciaVariables();
	void reject();
private slots:
	void SlotSePagaCompleto();
	void SlotSeDaAdelanto();
	void SlotAceptar();
	void SlotFocoAAceptar();
};
#endif
