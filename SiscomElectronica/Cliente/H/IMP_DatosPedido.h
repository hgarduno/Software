
#ifndef __IMP_DATOSPEDIDO_H__
#define __IMP_DATOSPEDIDO_H__
#include <QtDatosPedido.h>

class zPedido;
class QDatosPedido:public QtDatosPedido
{
 Q_OBJECT
public:
	QDatosPedido(zOrdenVenta *pzOrdVenta,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QDatosPedido();
	int Aceptar();
private:	
	int intAceptar;
	zOrdenVenta *zOrdVenta;
private:
	void ConectaSlots();
	int CambioPago(const char *,const char *,char *,char *);
private slots:
	void SlotAceptar();
	void SlotCancelar();
};
#endif
