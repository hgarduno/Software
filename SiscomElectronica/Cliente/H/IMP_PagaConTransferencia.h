
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
		NoSeReflejo=1,
		Cancelar=-1
	};
	int Aceptar();
public:
	QPagaConTransferencia::EdoTransferencia EstadoTransferencia();
private:
	zOrdenVenta *zOVenta;
	QPagaConTransferencia::EdoTransferencia lEdoTrans;
	zFormaPagoTransferencia *zFrmPgoT;
	int intAceptar;
	int intYaFormaPago;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Telefono();
	void MostrandoDatos();
	zFormaPagoTransferencia *IniciaTransferencia();
	void reject();
	int SeHabilitaAceptar();
	void HabilitandoAceptar();
	void YaSeReflejoTransferencia();
	void NoSeReflejoTransferencia();
private slots:
	void SlotAceptar();
	void SlotCancelar();
	void SlotFocoASeReflejo();
	void SlotEstadoTransferencia(int);
	void SlotCapturandoTelefono(const QString &);
};
#endif
