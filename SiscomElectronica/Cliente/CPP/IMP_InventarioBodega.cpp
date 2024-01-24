#include <IMP_InventarioBodega.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisInventarioBodega.h>
#include <CQSis3QtOperaciones.h>
#include <QCtrlBodegas.h>
#include <QCtrlProdSiscomElectronica.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qtable.h>

QInventarioBodega *InstanciaInventarioBodega(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QInventarioBodega((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QInventarioBodega::QInventarioBodega(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				InventarioBodega(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QInventarioBodega::~QInventarioBodega()
{

}

void QInventarioBodega::ConectaSlots()
{
	connect(QCtrBodegas,
		SIGNAL(SignalBodega(SiscomRegistro3 *)),
		SLOT(SlotBodega(SiscomRegistro3 *)));
	connect(QCtrProductos,
		SIGNAL(SignalSeleccionando(SiscomRegistro3 *)),
		SLOT(SlotSeleccionando(SiscomRegistro3 *)));
	connect(QCtrProductos,
		SIGNAL(SignalSelecciono(SiscomRegistro3 *)),
		SLOT(SlotSelecciono(SiscomRegistro3 *)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistra()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
	connect(QPBActivaBodegas,
		SIGNAL(clicked()),
		SLOT(SlotActivaBodegas()));

}
void QInventarioBodega::SlotActivaBodegas()
{

	QCtrBodegas->setEnabled(true);
}
void QInventarioBodega::SlotRegistra()
{
	AnexaProducto();
	SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
}
void QInventarioBodega::SlotPasaFocoRegistra()
{
 SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistrar);
}
void QInventarioBodega::SlotSelecciono(SiscomRegistro3 *pSisReg3Producto)
{
	SisReg3Producto=pSisReg3Producto;
	if(SisReg3Producto)
	{
	QTEDescripcion->setText((*SisReg3Producto)["dscproducto"]);
	SiscomDesarrollo3Qt::PasaFocoControl(QLECantidad);
	ExistenciaActual();
	QCtrBodegas->setEnabled(false);
	}
}
void QInventarioBodega::SlotSeleccionando(SiscomRegistro3 *pSisReg3Producto)
{
	SisReg3Producto=pSisReg3Producto;
	QTEDescripcion->setText((*SisReg3Producto)["dscproducto"]);
}
void QInventarioBodega::SlotBodega(SiscomRegistro3 *pSisReg3Bodega)
{
	SisReg3Bodega=pSisReg3Bodega;
	SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
}
void QInventarioBodega::IniciaVariables()
{
	QCtrProductos->Servidor(SisDatCom);
	QCtrProductos->IdExpendio(*chrPtrArgumentos);
	QCtrProductos->IniciaControl();
	QCtrBodegas->Servidor(SisDatCom);
	QCtrBodegas->Expendio(chrPtrArgumentos[0]);
	QCtrBodegas->IniciaControl();
}
void QInventarioBodega::ExistenciaActual()
{
SiscomRegistro3Lst lSisReg3LstProdBodega;
CQSis3QtOperaciones lCQSis3QtOperacion(SisDatCom);
lCQSis3QtOperacion.ExistenciaProductoBodega(chrPtrArgumentos[0],
					    SisReg3Bodega,
					    SisReg3Producto,
					    &lSisReg3LstProdBodega);
if((SisReg3ProdBodega=lSisReg3LstProdBodega[0]))
QLEExistencia->setText((*lSisReg3LstProdBodega[0])["existencia"]);
}
void QInventarioBodega::AnexaProducto()
{
CQSisInventarioBodega *lCQSInvBodega;
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
lCQSInvBodega=RegistroInventarioBodega();
lCQS3QtOperaciones.InventarioBodegaSiscom(lCQSInvBodega);
}
void QInventarioBodega::closeEvent(QCloseEvent *)
{
	emit SignalTerminar(this);
}

CQSisInventarioBodega *QInventarioBodega::RegistroInventarioBodega()
{
if(SisReg3ProdBodega)
return new CQSisInventarioBodega(
		chrPtrArgumentos[0],
		chrPtrArgumentos[1],
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECantidad),
		SisReg3Bodega,
		SisReg3ProdBodega);
else
{
SiscomEscribeLog3Qt("Producto Nulo");
return 0;
}
}

