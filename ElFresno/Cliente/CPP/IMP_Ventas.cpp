#include <IMP_Ventas.h>

#include <Ventas.h>
#include <Empresas.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QVentas *InstanciaVentas(void *pCSisDatCom,
			 void *pQWParent,
			 const char *pchrPtrName,
			 int pintWFlags)
{

	return new QVentas((CSISCOMDatComunicaciones *)pCSisDatCom,
			   (QWidget *)pQWParent,
			   pchrPtrName,
			   pintWFlags);
}

QVentas::QVentas(CSISCOMDatComunicaciones *pCSisDatCom,
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
	PonModificarPrecio(0);
	ConectaSlots();

}
void QVentas::IniciaVariables()
{

	QPBROperacion->setText("Registra \nVenta");
}

void QVentas::ConectaSlots()
{
	connect(QPBROperacion,
		SIGNAL(clicked()),
		SLOT(S_RealizaVenta()));
}

void QVentas::S_RealizaVenta()
{
CQ_Persona *lCQVendedor=ObtenUsuario();
CQProductosCotizacion lCQPCotizacion=ObtenProductos();

if(lCQVendedor)
{
CQCtrVentas lCQCVentas(CSisDatCom,
		       CQCtrVentas::RegistrarVenta,
		       new Venta(&lCQPCotizacion,
				 ObtenCliente(),
				 lCQVendedor,
				 ObtenExpendio()));
EliminaProductosCotizacion();
}
else
QMessageBox::information(this,
			 "Sistema El Fresno",
			 "El usuario no tiene una firma en el sistema");
}
