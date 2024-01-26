#include <QtImpConsultaVentas.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qmessagebox.h>
#include <zOperacionesServiSNTE.h>
#include <zVentas.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>
QtImpConsultaVentas::QtImpConsultaVentas(QWidget *pQWParent,
					 const char *pchrPtrName):
					 ConsultaVentas(pQWParent,pchrPtrName)
{

    Conexion((zSiscomConexion *)gzSiscomConexion);
    IniciaVariables();
    ConectaSlots();


}

void QtImpConsultaVentas::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpConsultaVentas::ConectaSlots()
{
  connect(QLERFC,
  	  SIGNAL(returnPressed()),
	  SLOT(SlotFocoAConsultaVentas()));
  connect(QPBConsultaVentas,
  	  SIGNAL(clicked()),
	  SLOT(SlotConsultaVentas()));
}
void QtImpConsultaVentas::SlotFocoAConsultaVentas()
{
  zSiscomQt3::Foco(QPBConsultaVentas);
}
void QtImpConsultaVentas::SlotConsultaVentas()
{
 ConsultandoVentas();
}
void QtImpConsultaVentas::IniciaVariables()
{


}
void QtImpConsultaVentas::ConsultandoVentas()
{
	Consulta();
	if(zVentasCliente)
	{
	MuestraCliente();
	MuestraVentas();
	}
	else
	QMessageBox::information(this,"Aviso del Sistema","No se encontro Informacion del RFC");
}
void QtImpConsultaVentas::Consulta()
{
 zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"VentasCliente");
 zVentasCliente=lzOpServiSNTE.Ventas(zSiscomQt3::Texto(QLERFC));
}
void QtImpConsultaVentas::MuestraVentas()
{
QTVentas->setNumRows(zVentasCliente->NoVentas());
int lintContador=0;
do
{
  QTVentas->setText(lintContador,0,zVentasCliente->Fecha());
  QTVentas->setText(lintContador,1,zVentasCliente->Folio());
  QTVentas->setText(lintContador,2,zVentasCliente->TipoVenta());
  QTVentas->setText(lintContador,3,zVentasCliente->Plazo());
  QTVentas->setText(lintContador,4,zVentasCliente->Financiadora());
  QTVentas->setText(lintContador,5,zVentasCliente->Vencimiento());
  QTVentas->setText(lintContador,6,zVentasCliente->Importe());
  lintContador++;
}while(zVentasCliente->Siguiente());
}
void QtImpConsultaVentas::MuestraCliente()
{
QTEDatosCliente->setText(QString("Nombre\n")		   +
			  zVentasCliente->Nombre()	   +
			 " "				   +
			 zVentasCliente->APaterno() 	   +
			 " "				   +
			 zVentasCliente->AMaterno());

}
