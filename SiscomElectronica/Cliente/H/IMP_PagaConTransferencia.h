
#ifndef __IMP_PAGACONTRANSFERENCIA_H__
#define __IMP_PAGACONTRANSFERENCIA_H__
#include <UIC_H_PagaConTransferencia.h>
class zOrdenVenta;
class zFormaPagoTransferencia;
class QPagaConTransferencia:public PagaConTransferencia
{
 Q_OBJECT
public:
	QPagaConTransferencia(
	    zOrdenVenta *pzOVenta,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QPagaConTransferencia();
	zOrdenVenta *Orden();
	zFormaPagoTransferencia *Transferencia();
public:
	enum EdoTransferencia
	{
		YaSeReflejo=0,
		NoSeReflejo=1
	};
public:
	QPagaConTransferencia::EdoTransferencia EstadoTransferencia();
private:
	zOrdenVenta *zOVenta;
	EdoTransferencia lEdoTrans;
	zFormaPagoTransferencia *zFrmPgoT;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Telefono();
	void MostrandoDatos();
	zFormaPagoTransferencia *IniciaTransferencia();
private slots:
	void SlotAceptar();
	void SlotFocoASeReflejo();
	void SlotEstadoTransferencia(int);
};
#endif
