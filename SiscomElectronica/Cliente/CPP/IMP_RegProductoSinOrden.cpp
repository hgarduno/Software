#include <IMP_RegProductoSinOrden.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlProdSiscomElectronica.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisProductosE3Qt.h>
#include <CQSisProductosSinOrden.h>
QRegProductoSinOrden::QRegProductoSinOrden(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RegProductoSinOrden(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QRegProductoSinOrden::~QRegProductoSinOrden()
{

}

void QRegProductoSinOrden::ConectaSlots()
{

	connect(QCtrProductos,
		SIGNAL(SignalSeleccionando(SiscomRegistro3 *)),
		SLOT(SlotSeleccionando(SiscomRegistro3 *)));
	connect(QCtrProductos,
		SIGNAL(SignalSelecciono(SiscomRegistro3 *)),
		SLOT(SlotSelecciono(SiscomRegistro3 *)));
	connect(QLEProducto,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistrar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));

}
void QRegProductoSinOrden::SlotRegistrar()
{
CQSisProductoE3 *lCQSProductoE3=new CQSisProductoE3(SisReg3Producto);
CQSisProductosSinOrden lCQSProdSinOrden(SisDatCom);
lCQSProdSinOrden.Registra(chrPtrArgumentos[0],
			  lCQSProductoE3);
}
void QRegProductoSinOrden::SlotPasaFocoRegistrar()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistrar);
}
void QRegProductoSinOrden::SlotSelecciono(SiscomRegistro3 *pSisReg3Producto)
{
SisReg3Producto=pSisReg3Producto;
QLEProducto->setText((*SisReg3Producto)["cveproducto"]);
SiscomDesarrollo3Qt::PasaFocoControl(QLEProducto);
}
void QRegProductoSinOrden::SlotSeleccionando(SiscomRegistro3 *pSisReg3Producto)
{
QTEDescripcion->setText((*pSisReg3Producto)["dscproducto"]);

}
void QRegProductoSinOrden::IniciaVariables()
{
	QCtrProductos->Servidor(SisDatCom);
	QCtrProductos->IniciaControl();
	SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
}
