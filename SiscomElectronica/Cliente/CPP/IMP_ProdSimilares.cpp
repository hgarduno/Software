#include <IMP_ProdSimilares.h>

#include <SISCOMComunicaciones++.h>
#include <qvariant.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


QProdSimilares::QProdSimilares(const ProductosE &pProductos,
				QWidget* parent,
				const char* name,
				bool modal,
				WFlags fl )
    : ProdSimilares( parent, name, modal, fl ),
    PProductos(pProductos),
    Producto(0)
{
	ConectaSlots();
	MuestraProductos();
	exec();
}

QProdSimilares::~QProdSimilares()
{
}
void QProdSimilares::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(S_SeleccionoProducto(int,int,int,const QPoint &)));
}
void QProdSimilares::S_SeleccionoProducto(int pintNFila,
					  int ,
					  int ,
					  const QPoint &)
{
	if(pintNFila!=-1)
	{
	Producto=PProductos.at(pintNFila)	;
	done(1);
	}

}
ProductoE *QProdSimilares::ObtenProducto()
{
	return Producto;
}
void QProdSimilares::MuestraProductos()
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
				      QString(lProducto->SRegistrosPro2["Existencia"]) <<
				      (*lProducto)["Precio"]			       <<
				      lProducto->SRegistrosPro2["CveProducto"]	       <<
				      lProducto->SRegistrosPro2["DscProducto"]         <<
				      lProducto->SRegistrosPro2["NmbFamilia"]);
SiscomAjustaColumnas(QTDatos);
SiscomAjustaFilas(QTDatos);
}
