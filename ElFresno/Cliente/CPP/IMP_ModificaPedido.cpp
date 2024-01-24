#include <IMP_ModificaPedido.h>
#include <Pedidos.h>
#include <Empresas.h>

#include <qpushbutton.h>
#include <qlcdnumber.h>

QModificaPedido::QModificaPedido(Empresa *pEExpendio,
				const char *pchrPtrNumPedido,
				CSISCOMDatComunicaciones *pCSisDatCom,
				 QWidget *pQWParent,
				 const char *pchrPtrName,
				 WFlags pWFlags):
		QVentasPedidos(pCSisDatCom,pQWParent,pchrPtrName,pWFlags),
		CSisDatCom(pCSisDatCom),
		chrPtrNumPedido(pchrPtrNumPedido)
{
	PonExpendio(pEExpendio);
	IniciaVariables();
	ConsultaDetallePedido();
	ConectaSlots();
}
void QModificaPedido::ConectaSlots()
{
	connect(QPBROperacion,
		SIGNAL(clicked()),
		SLOT(S_ModificaPedido()));
}
void QModificaPedido::IniciaVariables()
{
QPBROperacion->setText("Registra \nModificaciones");
	HabilitaDesHabilitaControles("%W1%W1",
				      QPBROperacion,
				      QLECantidad);
}
void QModificaPedido::S_ModificaPedido()
{
CQProductosCotizacion lCQPCotizacion=ObtenProductos();

	CQ_Pedidos.at(0)->PonProductos(&lCQPCotizacion);
	CQ_Pedidos.at(0)->PonImportePedido(strdup((const char *)QString().sprintf("%.2f",
					   QLCNTotal->value())));
CQCtrPedidos lCQPedidos(CSisDatCom,
			CQCtrPedidos::ActualizaPedido,
			&CQ_Pedidos);
	emit Signal_ModificoPedido();
}
void QModificaPedido::ConsultaDetallePedido()
{
CQProductosCotizacion lCQPCotizacion;
CQProductosCotizacion *lCQPCotizacionPtr;
CQCtrPedidos lCQCPDetalle(CSisDatCom,
			  CQCtrPedidos::DetallePedido,
			  QStringList() <<
			  "DetalleDelPedido" <<
			  chrPtrNumPedido,
			  &CQ_Pedidos);
lCQPCotizacionPtr=CQ_Pedidos.at(0)->ObtenProductos();
AsignaProductos(*lCQPCotizacionPtr,
		CQ_Pedidos.at(0)->ObtenCliente());
printf("QModificaPedido::ConsultaDetallePedido:{%s,%s,%s}\n",
	CQ_Pedidos.at(0)->ObtenCliente()->ObtenNombre(),
	CQ_Pedidos.at(0)->ObtenCliente()->ObtenAPaterno(),
	CQ_Pedidos.at(0)->ObtenCliente()->ObtenIdPersona());
}

