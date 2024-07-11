#ifndef __IMP_COMOPAGO_H__
#define __IMP_COMOPAGO_H__
#include <UIC_H_ComoPago.h>

class zOrdenVenta;
class zFormaPago;
class zSiscomConexion;
class zConCuantoPago;
class QComoPago:public ComoPago
{
 Q_OBJECT
public:
	QComoPago(zOrdenVenta *pzOrdenVenta,
		 QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QComoPago();

	zOrdenVenta *Orden();
public:
	enum FormaDePago
	{	
		Cancelar=-1,
		Efectivo=0,
		Transferencia=2,
		Tarjeta=3
	};
	FormaDePago ComoPague();
private:
	zOrdenVenta *zOVenta;
	FormaDePago FrmPago;
	zConCuantoPago *zConCPago;
private:
	void ConectaSlots();
	void IniciaVariables();
	void reject();
	void Pagando(FormaDePago );
	zFormaPago *FormaPago();
	void PagandoEfectivo();
	int VerificandoConCuantoPago();
	void VerificoConCuantoPago();
	zSiscomConexion *Conexion();
	zConCuantoPago *ConCuantoPago();
private slots:
	void SlotAceptar();
	void SlotComoPago(int);
	void SlotCancelar();
	void SlotFocoAAceptar();
	void SlotCapturandoConCuantoPaga(const QString &);
};
#endif
