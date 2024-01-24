#ifndef __QTDATOSPEDIDO_H__
#define __QTDATOSPEDIDO_H__
#include <UIC_H_DatosPedido.h>


class zOrdenVenta;
class QtDatosPedido:public DatosPedido
{
Q_OBJECT
public:
	QtDatosPedido(zOrdenVenta *pzOrdVenta,
		      QWidget *pQWParent=0,
		      const char *pchrPtrName=0,
		      bool pbModal=0,
		      WFlags pWFlags=false);

	void MuestraDatosPedido();
	void IniciaVariables();
	void FormaDatosPedido();

	virtual int CambioPago(const char *pchrPtrePagaCon,
				const char *pchrPtrImporte,
				  char *pchrPtrCambio,
				  char *);
	zOrdenVenta *Orden();
private:
	void ConectaSlots();
	void HabilitandoAceptar();
	
private:
	zOrdenVenta *zOrdVenta;

private slots:
	
	void SlotFocoAPagaCon();
	void SlotFocoAAceptar();
	void SlotFocoAObservaciones();
	void SlotCapturandoPagaCon(const QString &);
private slots:
	virtual void SlotAceptar();
	virtual void SlotCancelar();
};

#endif
