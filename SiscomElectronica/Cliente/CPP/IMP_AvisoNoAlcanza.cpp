#include <IMP_AvisoNoAlcanza.h>
#include <IMP_CapturaDato.h>
#include <ProductosE.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qlcdnumber.h>

QAvisoNoAlcanza::QAvisoNoAlcanza(ProductoE *pProducto,
				QWidget* parent,
				const char* name,
				bool modal, 
				WFlags fl )
    : AvisoNoAlcanza( parent, name, modal, fl ),
    PProducto(pProducto),
    intOpcion(1)
{
	MuestraDatos();
	ConectaSlots();
	exec();
}

QAvisoNoAlcanza::~QAvisoNoAlcanza()
{
}
void QAvisoNoAlcanza::MuestraDatos()
{
	QLEProducto->setText(PProducto->SRegistrosPro2["CveProducto"]);
	QLEDescripcion->setText(PProducto->SRegistrosPro2["DscProducto"]);
	QLECantidad->setText(PProducto->SRegistrosPro2["Cantidad"]);
	QLCNExistencia->display(PProducto->SRegistrosPro2["Existencia"]);

}
void QAvisoNoAlcanza::ConectaSlots()
{
	connect(QPBVende,
		SIGNAL(clicked()),
		SLOT(S_VendoLoQueHay()));
	connect(QPBCCantidad,
		SIGNAL(clicked()),
		SLOT(S_CambiaCantidad()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(S_Eliminar()));
}
void QAvisoNoAlcanza::S_Eliminar()
{
	intOpcion=0;
	done(1);
}
void QAvisoNoAlcanza::S_VendoLoQueHay()
{
 PProducto->SiscomActualizaCampo("Cantidad",
 				 PProducto->SRegistrosPro2["Existencia"]);
done(1);
}
void QAvisoNoAlcanza::S_CambiaCantidad()
{
QCapturaDato lQCDato("Cambia Cantidad",
		     "Cantidad");
char lchrArrCantidad[15];

	lQCDato.ObtenDato(lchrArrCantidad);
 PProducto->SiscomActualizaCampo("Cantidad",
 				 lchrArrCantidad);
done(1);
}
int QAvisoNoAlcanza::Opcion()
{
	return intOpcion;
}
