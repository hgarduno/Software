
#ifndef __IMP_CAPTURAOBSERVACIONPEDIDOPRODUCTO_H__
#define __IMP_CAPTURAOBSERVACIONPEDIDOPRODUCTO_H__
#include <UIC_H_CapturaObservacionPedidoProducto.h>
class SiscomDatCom;
class QCapturaObservacionPedidoProducto:public CapturaObservacionPedidoProducto
{
 Q_OBJECT
public:
	QCapturaObservacionPedidoProducto(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaObservacionPedidoProducto();
	int Aceptar();
	void  Observaciones(char *pchrPtrObservaciones);
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
	void reject();
private slots:
	void SlotAceptar();
	void SlotCancelar();
};
#endif
