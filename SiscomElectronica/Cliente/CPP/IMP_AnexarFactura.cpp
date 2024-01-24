#include <IMP_AnexarFactura.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <CQSisFacturas.h>
QAnexarFactura::QAnexarFactura(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				AnexarFactura(pQWParent,
					      pchrPtrName,
					      pbModal,
					      pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				intOpcion(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QAnexarFactura::~QAnexarFactura()
{

}

void QAnexarFactura::ConectaSlots()
{
	connect(QLENumFactura,
		SIGNAL(returnPressed()),
		SLOT(SlotConsultaFactura()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QTFacturas,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaFactura(int,int,int,const QPoint &)));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));

}
void QAnexarFactura::SlotCancelar()
{
	intOpcion=0;
	done(1);
}
void QAnexarFactura::SlotSeleccionaFactura(int pintNFactura,
					   int,
					   int,
					   const QPoint &)
{
	QTFacturas->selectRow(pintNFactura);
	SisReg3Factura=SisReg3LstFacturas[pintNFactura];
	SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);

}
void QAnexarFactura::SlotAceptar()
{
	intOpcion=1;
	done(1);
}
void QAnexarFactura::SlotConsultaFactura()
{
Consultando();
QueHagoDespuesConsulta();
}
void QAnexarFactura::IniciaVariables()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLENumFactura);
}
void QAnexarFactura::Consultando()
{
Consulta();
Muestra();
}
void QAnexarFactura::Consulta()
{
CQSisFacturando lCQSFacturando(SisDatCom);
lCQSFacturando.BuscaFacturas(
   chrPtrArgumentos[0],		
   SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENumFactura),
   &SisReg3LstFacturas);
}
void QAnexarFactura::Muestra()
{
const char *lchrPtrCampos[]={
			"numfactura",
			"fecha",
			"proveedor",
			0
			};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					     QTFacturas,
					     &SisReg3LstFacturas);
SiscomDesarrollo3Qt::AjustaColumnas(QTFacturas);
}
int QAnexarFactura::Opcion()
{
return intOpcion;
}
SiscomRegistro3 *QAnexarFactura::Factura()
{
return SisReg3Factura;
}
void QAnexarFactura::QueHagoDespuesConsulta()
{
  if(SisReg3LstFacturas.count()==1)
  {
	SisReg3Factura=SisReg3LstFacturas[0];
	SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
  }
}
void QAnexarFactura::closeEvent(QCloseEvent *)
{

}
