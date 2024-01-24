#include <IMP_CapturaCantidad3Qt.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
QCapturaCantidad3Qt::QCapturaCantidad3Qt(SiscomRegistro3 *pSReg3ProdCotiza,
					       QWidget *pQWParent,
					       const char *pchrPtrName,
					       bool pbModal,
					       WFlags pWFlags):
				CapturaCantidad(pQWParent,pchrPtrName,pbModal,pWFlags),
				SReg3Producto(pSReg3ProdCotiza)
{
IniciaVariables();
ConectaSlots();
exec();
}
QCapturaCantidad3Qt::~QCapturaCantidad3Qt()
{

}
void QCapturaCantidad3Qt::IniciaVariables()
{
QLEClave->setText((*SReg3Producto)["Clave"]);
QLECantidad->setText((*SReg3Producto)["Cantidad"]);
QLCDNExistencia->display((*SReg3Producto)["Existencia"]);
QTEDescripcion->setText((*SReg3Producto)["Dsc"]);
SiscomDesarrollo3Qt::PasaFocoControl(QLECantidad);
}
void QCapturaCantidad3Qt::ConectaSlots()
{
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAceptar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
}

void QCapturaCantidad3Qt::SlotCancelar()
{
	intOpcion=0;
	done(0);
}
void QCapturaCantidad3Qt::SlotAceptar()
{
	SReg3Producto->SiscomActualizaCampo("Cantidad",
					    (const char *)QLECantidad->text());
	intOpcion=1;
	done(1);
					
}
void QCapturaCantidad3Qt::SlotPasaFocoAceptar()
{
	QPBAceptar->setEnabled(QLECantidad->text().toFloat()<=
			       QString((*SReg3Producto)["Existencia"]).toFloat());
	SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}

