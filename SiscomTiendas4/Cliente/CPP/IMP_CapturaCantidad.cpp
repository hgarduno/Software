#include <IMP_CapturaCantidad.h>

#include <CQSisProdCotiza.h>
#include <CQSisProductos.h>
#include<SISCOMComunicaciones++.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
QCapturaCantidad::QCapturaCantidad(CQSisProdCotiza *pCQSPCotiza,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaCantidad(pQWParent,pchrPtrName,pbModal,pWFlags),
				CQSPCotiza(pCQSPCotiza),
				intOpcion(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaCantidad::~QCapturaCantidad()
{

}

void QCapturaCantidad::ConectaSlots()
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
void QCapturaCantidad::SlotCancelar()
{
	intOpcion=0;
	done(0);
}
void QCapturaCantidad::SlotAceptar()
{
	CQSPCotiza->SRegistrosPro2.SiscomActualizaCampo(
			"Cantidad",
			(const char *)QLECantidad->text());
	intOpcion=1;
	done(1);
					
}
void QCapturaCantidad::SlotPasaFocoAceptar()
{
	QPBAceptar->setEnabled(QLECantidad->text().toFloat()<=
			       QString(CQSPCotiza->SRegistrosPro2["Existencia"]).toFloat());
	SiscomPasaFocoControl(QPBAceptar);
}
void QCapturaCantidad::IniciaVariables()
{
QLEClave->setText(CQSPCotiza->Producto()->SRegistrosPro2["Clave"]);
QLECantidad->setText(CQSPCotiza->SRegistrosPro2["Cantidad"]);
QTEDescripcion->setText(CQSPCotiza->Producto()->SRegistrosPro2["Dsc"]);
QLCDNExistencia->display(CQSPCotiza->SRegistrosPro2["Existencia"]);

SiscomPasaFocoControl(QLECantidad);
}
int QCapturaCantidad::Opcion()
{
	return intOpcion;
}
void QCapturaCantidad::closeEvent(QCloseEvent *)
{

}
