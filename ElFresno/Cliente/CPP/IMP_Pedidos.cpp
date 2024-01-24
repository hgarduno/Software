#include <IMP_Pedidos.h>
#include <IMP_QControlFecha.h>
#include <CQSiscomCom.h>
#include <SISCOMComunicaciones++.h>
#include <Pedidos.h>
#include <Empresas.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qlineedit.h>

QPedidos *InstanciaPedidos(void *pCSisDatCom,
			 void *pQWParent,
			 const char *pchrPtrName,
			 int pintWFlags)
{

	return new QPedidos((CSISCOMDatComunicaciones *)pCSisDatCom,
			   (QWidget *)pQWParent,
			   pchrPtrName,
			   pintWFlags);
}

QPedidos::QPedidos(CSISCOMDatComunicaciones *pCSisDatCom,
		 QWidget *pQWParent,
		 const char *pchrPtrName,
		 int pintWFlags):
		QVentasPedidos(pCSisDatCom,
			       pQWParent,
			       pchrPtrName,
			       pintWFlags),
		CSisDatCom(pCSisDatCom)
{
	IniciaVariables();
	ObtenDatosMatriz();
	ConectaSlotsPedidos();

}
void QPedidos::ObtenDatosMatriz()
{
CQEmpresas lCQERegreso;
CQCtrEmpresas lCQCMatriz(CSisDatCom,
			 QStringList() <<
			 QString("ConsultaEmpresas") <<
			 "Matriz",
			 &lCQERegreso);
E_Matriz=lCQERegreso.at(0);
setCaption(QString("Manejador De Pedidos:") +
	   E_Matriz->ObtenRazonSocial());	
PonExpendio(E_Matriz);
}
void QPedidos::ConectaSlotsPedidos()
{
	connect(QPBROperacion,
		SIGNAL(clicked()),
		SLOT(S_RegistraPedido()));
}
void QPedidos::S_RegistraPedido()
{
if(ObtenUsuario())
{
CQPedidos lCQPedidos;
Pedido *lP_Pedido;
CQProductosCotizacion lCQPCotizacion=ObtenProductos();

lP_Pedido=new Pedido(ObtenCliente(),
		     &lCQPCotizacion,
		     ObtenUsuario()->ObtenIdPersona());
lP_Pedido->PonFechaEntrega(strdup((const char *)QCFechaEntrega->ObtenFecha()));
lP_Pedido->PonContactoCliente(SISCOMObtenInformacionDelEdit(QLECCliente));
lCQPedidos.append(lP_Pedido);
CQCtrPedidos lCQCPedido(CSisDatCom,
			CQCtrPedidos::Registrar,
			&lCQPedidos);
EliminaProductosCotizacion();
}
else
 QMessageBox::information(this,
		          "Sistema El Fresno",
			  "El Usuario NO tiene una firma en la base del sistema");
			
}
void QPedidos::IniciaVariables()
{
		QPBROperacion->setText("Registra \nPedidos");
		//QPBROperacion->setEnabled(ObtenUsuario());
		QCFechaEntrega->setEnabled(true);
		QLECCliente->setEnabled(true);
}
