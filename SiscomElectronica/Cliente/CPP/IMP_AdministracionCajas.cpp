#include <IMP_AdministracionCajas.h>
#include <IMP_CorteCaja.h>
#include <IMP_VentasPorCaja.h>
#include <IMP_SeguridadCajaVentas.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSis3QtComunes.h>
#include <CQSisCajas.h>
#include <qtabwidget.h>
QAdministracionCajas *InstanciaAdministracionCajas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QAdministracionCajas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QAdministracionCajas::QAdministracionCajas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				AdministracionCajas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QAdministracionCajas::~QAdministracionCajas()
{

}

void QAdministracionCajas::ConectaSlots()
{
connect(QTCajasRegistradas,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionandoCaja(int,int,int,const QPoint &)));
connect(QLEImporteCaja,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoRegistrarImporte()));
connect(QPBRegistrarImporte,
	SIGNAL(clicked()),
	SLOT(SlotRegistrarImporte()));
}
void QAdministracionCajas::SlotRegistrarImporte()
{
RegistraImporteCaja();
ConsultandoCajasRegistradas();
}
void QAdministracionCajas::SlotPasaFocoRegistrarImporte()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistrarImporte);
}
void QAdministracionCajas::SlotSeleccionandoCaja(int pintNFila,
						int,
						int,
						const QPoint &)
{
	QTCajasRegistradas->selectRow(pintNFila);
	SisReg3Caja=SisReg3Cajas[pintNFila];
	SiscomDesarrollo3Qt::PasaFocoControl(QLEImporteCaja);
}
void QAdministracionCajas::IniciaVariables()
{
	ConsultandoCajasRegistradas();
	AgregaCorteCajas();
	AgregaVentasPorCaja();
	AgregaSeguridadCaja();
}
void QAdministracionCajas::ConsultandoCajasRegistradas()
{
	ConsultaCajasRegistradas();
	MuestraCajasRegistradas();
}
void QAdministracionCajas::ConsultaCajasRegistradas()
{
CQSis3QtComunes lCQS3QtComun(SisDatCom);
SisReg3Cajas.SiscomElimina();
lCQS3QtComun.CajasRegistradas(chrPtrArgumentos[0],&SisReg3Cajas);
}
void QAdministracionCajas::MuestraCajasRegistradas()
{
const char *lchrArrCamposM[]={"descripcion",
			"importe",
			0
			};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCamposM,
				       QTCajasRegistradas,
				       &SisReg3Cajas);
SiscomDesarrollo3Qt::AjustaColumnas(QTCajasRegistradas);
}

CQSisCaja *QAdministracionCajas::ImporteCaja()
{
CQSisCaja *lCQSCaja;
	lCQSCaja=new CQSisCaja((*SisReg3Caja)["idcaja"],
			       "",
			       "",
			       (const char *)QLEImporteCaja->text(),
			       chrPtrArgumentos[0]);
return lCQSCaja;
}
void QAdministracionCajas::RegistraImporteCaja()
{
CQSisOpCajas lCQSOpCajas(SisDatCom);
lCQSOpCajas.RegistraImporteCaja(ImporteCaja());
}

void QAdministracionCajas::AgregaCorteCajas()
{
QCorteCaja *lQCCaja;

lQCCaja=new QCorteCaja(SisDatCom,
		       chrPtrArgumentos,
			QTWOCajas,
		       "QCCorteCaja");
QTWOCajas->addTab(lQCCaja,"Corte De Caja");

}
void QAdministracionCajas::AgregaVentasPorCaja()
{
QVentasPorCaja *lQVPorCaja=new QVentasPorCaja(SisDatCom,
			   chrPtrArgumentos,
			   QTWOCajas,
			   "lQVPorCaja");
QTWOCajas->addTab(lQVPorCaja,"Ventas Por Caja");
}
void QAdministracionCajas::AgregaSeguridadCaja()
{
QSeguridadCajaVentas *lQSegCajasVenta;
lQSegCajasVenta=new QSeguridadCajaVentas(SisDatCom,
					 chrPtrArgumentos,
					 QTWOCajas,
					 "lQSegCajaVenta");
QTWOCajas->addTab(lQSegCajasVenta,"Seguridad Cajas");
}
void QAdministracionCajas::closeEvent(QCloseEvent *)
{
	emit SignalTerminar(this);
}
