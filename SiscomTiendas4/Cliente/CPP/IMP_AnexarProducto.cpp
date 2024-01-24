#include <IMP_AnexarProducto.h>
#include <QCtrlProductos3Qt.h>
#include <SiscomDatCom.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisPaquetes.h>

#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlineedit.h>
QAnexarProducto::QAnexarProducto(SiscomDatCom *pSisDatCom, 
			         char **pchrPtrArgumentos, 
				 const char *pchrPtrIdPaquete,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				AnexarProducto(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				chrPtrIdPaquete(pchrPtrIdPaquete)
{
IniciaVariables();
ConectaSlots();
exec();
}

QAnexarProducto::~QAnexarProducto()
{

}

void QAnexarProducto::IniciaVariables()
{
QCtrProductos->Servidor(SisDatCom);
QCtrProductos->IniciaControl();
QCtrProductos->setFocus();
}
void QAnexarProducto::ConectaSlots()
{
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
		SLOT(SlotAnexar()));

}
void QAnexarProducto::SlotAnexar()
{
	done(1);	
}
void QAnexarProducto::SlotPasaFocoAnexarProducto()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QPBAnexar);
}
void QAnexarProducto::SlotProducto(SiscomRegistro3 *pSisReg3Producto)
{
	SisReg3Producto=pSisReg3Producto;
	SiscomDesarrollo3Qt::PasaFocoControl(QLECantidad);
}
void QAnexarProducto::SlotSeleccionandoProducto(SiscomRegistro3 *pSisReg3Producto)
{
QTEDescripcion->setText((*pSisReg3Producto)["dscproducto"]);
}
CQSisPaqueteProducto *QAnexarProducto::Producto()
{
return new CQSisPaqueteProducto(chrPtrIdPaquete,
			      (*SisReg3Producto)["idproducto"],
			      SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECantidad));
}
