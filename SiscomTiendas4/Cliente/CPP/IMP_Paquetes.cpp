#include <IMP_Paquetes.h>
#include <QCtrlProductos3Qt.h>
#include <CQSisPaquetes.h>
#include <SiscomDatCom.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>

#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qtable.h>
QPaquetes *InstanciaPaquetes(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPaquetes((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPaquetes::QPaquetes(SiscomDatCom *pSisDatCom, 
			char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Paquetes(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QPaquetes::~QPaquetes()
{

}

void QPaquetes::ConectaSlots()
{

	connect(QLEClave,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDescripcion()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistraPaquete()));
	connect(QCtrProductos,
		SIGNAL(SignalSeleccionandoProducto(SiscomRegistro3 *)),
		SLOT(SlotSeleccionandoProducto(SiscomRegistro3 *)));
	connect(QCtrProductos,
		SIGNAL(SignalProductos(SiscomRegistro3 *)),
		SLOT(SlotProducto(SiscomRegistro3 *)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAnexarProducto()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexarProducto()));
	connect(QPBRProductos,
		SIGNAL(clicked()),
		SLOT(SlotRegistraProductos()));

}
void QPaquetes::SlotRegistraProductos()
{
	RegistraProductos();
	QPBRProductos->setEnabled(false);
	QPBAnexar->setEnabled(false);
	QPBRegistra->setEnabled(true);
	QCtrProductos->setEnabled(false);
	SReg3LstProductos.clear();
	QTDatos->setNumRows(0);
}
void QPaquetes::SlotAnexarProducto()
{
SiscomEscribeLog3Qt("Se anexara el Producto:%s",
		     (*SReg3Producto)["clave"]);
  SReg3LstProductos << SReg3Producto;
  AnexaProducto();
  SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
  QPBRProductos->setEnabled(true);
}
void QPaquetes::SlotPasaFocoAnexarProducto()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QPBAnexar);
}
void QPaquetes::SlotProducto(SiscomRegistro3 *pSReg3Producto)
{
	SReg3Producto=pSReg3Producto;
	QLECantidad->setEnabled(true);
	SiscomDesarrollo3Qt::PasaFocoControl(QLECantidad);
}
void QPaquetes::SlotSeleccionandoProducto(SiscomRegistro3 *pSRegistro3)
{
QTEDescripcion->setText((*pSRegistro3)["dscproducto"]);
}
void QPaquetes::SlotRegistraPaquete()
{
CQSisOpPaquetes lCQSOpPaquetes(SisDatCom);
lCQSOpPaquetes.RegistraPaquete(
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEClave),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QTEDescripcionP),
	chrArrIdPaquete);
	QCtrProductos->setEnabled(true);
	SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
   QPBRegistra->setEnabled(false);
   QPBAnexar->setEnabled(true); 
}
void QPaquetes::SlotPasaFocoDescripcion()
{
/*
	SiscomDesarrollo3Qt::PasaFocoControl(QTEDescripcionP);	
*/
	QTEDescripcionP->setFocus();
}
void QPaquetes::IniciaVariables()
{

	QCtrProductos->Servidor(SisDatCom);
	QCtrProductos->IniciaControl();
	SiscomDesarrollo3Qt::PasaFocoControl(QLEClave);
	QPBRProductos->setEnabled(false);
	QPBAnexar->setEnabled(false);
	QLECantidad->setEnabled(false);

}

void QPaquetes::AnexaProducto()
{
int lintFilas=SReg3LstProductos.count();
	QTDatos->setNumRows(lintFilas);
const char *lchrPtrCantidad;
lchrPtrCantidad=SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECantidad);
SiscomDesarrollo3Qt::RegistroALaTabla(
lintFilas-1,
QTDatos,
QStringList()        						<<
(*SReg3Producto)["clave"] 					<<
(*SReg3Producto)["dscproducto"] 				<<
lchrPtrCantidad							<<
"0.0"								<<
"0.0");
SReg3LstProductos+=new SiscomCampo3("Cantidad",lchrPtrCantidad);
SReg3LstProductos+=new SiscomCampo3("IdPaquete",chrArrIdPaquete);
SiscomDesarrollo3Qt::AjustaFilas(QTDatos);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}
void QPaquetes::RegistraProductos()
{
CQSisOpPaquetes lCQSOPaquetes(SisDatCom);
lCQSOPaquetes.ProductosAlPaquete(chrArrIdPaquete,
				 &SReg3LstProductos);
}

void QPaquetes::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
