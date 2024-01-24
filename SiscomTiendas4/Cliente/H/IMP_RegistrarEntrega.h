
#ifndef __IMP_REGISTRARENTREGA_H__
#define __IMP_REGISTRARENTREGA_H__
#include <UIC_H_RegistrarEntrega.h>
#include <CQSisPedidos.h>
class SiscomDatCom;
class CQSisCliente;
class QRegistrarEntrega:public RegistrarEntrega
{
 Q_OBJECT
public:
	QRegistrarEntrega(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistrarEntrega();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisCliente *CQSCliente;
	CQSisLstPedido CQSLPedidos;
	SiscomRegistrosPro2 *SRegistrosPro2Pedidos;
	CQSisPedido *CQSPedido;
private:
	void ConectaSlots();
	void IniciaVariables();
	const char *IdCliente();
	void ConsultandoPedidos();
	void MuestraPedidos();
	void ConsultaPedidos();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotClienteFisica(CQSisCliente *);
	void SlotRegistra();
	void SlotSeleccionandoPedido(int ,int,int,const QPoint &);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QRegistrarEntrega *InstanciaRegistrarEntrega(void *,char **,void *,const char *,int);
#endif
