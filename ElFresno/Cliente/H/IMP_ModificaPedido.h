#ifndef __IMP_MODIFICAPEDIDO_H__
#define __IMP_MODIFICAPEDIDO_H__
#include <IMP_VentasPedidos.h>
#include <Pedidos.h>
class CSISCOMDatComunicaciones;
class Empresa;
class QModificaPedido:public QVentasPedidos
{
Q_OBJECT
public:
	QModificaPedido(Empresa *,
			const char *,
			CSISCOMDatComunicaciones *,
			QWidget *,
			const char *,
			WFlags );
	void MuestraPedido();
private:
	CSISCOMDatComunicaciones *CSisDatCom;
	const char *chrPtrNumPedido;
	CQPedidos CQ_Pedidos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaDetallePedido();

private slots:
	void S_ModificaPedido();
signals:
	void Signal_ModificoPedido();
};



#endif
