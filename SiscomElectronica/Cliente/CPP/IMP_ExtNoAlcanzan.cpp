#include <IMP_ExtNoAlcanzan.h>


#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


QExtNoAlcanzan::QExtNoAlcanzan( QWidget* parent, const char* name, WFlags fl )
    : ExtNoAlcanzan( parent, name, fl )
{
}

QExtNoAlcanzan::~QExtNoAlcanzan()
{
}

void QExtNoAlcanzan::PonProductos(const ProductosE &pProductos)
{

	PProductos=pProductos;
}
void QExtNoAlcanzan::MuestraProductos()
{
ProductoE *lProducto;
int lintContador;
	QTDatos->setNumRows(PProductos.count());
	for(lProducto=PProductos.first(),
	    lintContador=0;
	    lProducto;
	    lProducto=PProductos.next(),
	    lintContador++)
	  SiscomAnexarRegistroALaTabla(lintContador,
	  				QTDatos,
					QStringList() <<
					lProducto->SRegistrosPro2["CveProducto"] <<
					lProducto->SRegistrosPro2["Cantidad"]    <<
					lProducto->SRegistrosPro2["Existencia"]);

	

}

