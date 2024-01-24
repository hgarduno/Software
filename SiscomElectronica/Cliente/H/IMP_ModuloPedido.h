
#ifndef __IMP_MODULOPEDIDO_H__
#define __IMP_MODULOPEDIDO_H__
#include <IMP_ManejadorOrden.h>
class SiscomDatCom;

class QClientePedido;
class QModuloPedido:public QManejadorOrden
{
 Q_OBJECT
public:
	QModuloPedido(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QModuloPedido();
private:
	char **chrPtrArgumentos;
	int intDatosPedido;
	zPedido *zPedSiscom;
private:
	void NuevaOrden();
	void Redimensiona();
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDatosCliente();
	void CapturaDatosPedido();
	void Registrar();
	void RegistraOrden();
	void Imprimir();
	void closeEvent(QCloseEvent *);	

	void PedidoDesdeCero(QClientePedido *);

	void EliminaPedido();
private slots:
	void SlotDatosPedido();
signals:
	void SignalActualizaMenu(const QString &);
	void SignalTerminar(QWidget *);

};
extern "C" QModuloPedido *InstanciaModuloPedido(void *,char **,void *,const char *,int);
#endif
