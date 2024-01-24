#include <IMP_CotizaPractica.h>
#include <IMP_ExtNoAlcanzan.h>
#include <SISCOMComunicaciones++.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
QCotizaPractica::QCotizaPractica(SiscomDatCom *pSisDatCom,
				 const char *pchrPtrIdExpendio,
				 const char *pchrPtrNmbTipoPrecio,
				 QWidget* parent,
				 const char* name,
				 bool modal, WFlags fl )
    : CotizaPractica( parent, name, modal, fl ),
      SisDatCom(pSisDatCom),
      chrPtrIdExpendio(pchrPtrIdExpendio),
      chrPtrNmbTipoPrecio(pchrPtrNmbTipoPrecio)
{
	IniciaVariables();
	ConsultaLasEscuelas();
	ConectaSlots();
	exec();
}

QCotizaPractica::~QCotizaPractica()
{
}
ProductosE &QCotizaPractica::ObtenProductos()
{
	return  PProductos ;
}
void QCotizaPractica::IniciaVariables()
{
int lintContador;

	QLEEscuelas=SiscomColocaEditAlCombo(QCBEscuelas,"QLEEscuelas");
	QLEMaterias=SiscomColocaEditAlCombo(QCBMaterias,"QLEMaterias");
	QLEPracticas=SiscomColocaEditAlCombo(QCBPracticas,"QLEPracticas");
	for(lintContador=1;
	    lintContador<QTDatos->numCols();
	    lintContador++)
	  QTDatos->adjustColumn(lintContador);
	  SiscomPasaFocoControl(QLEEscuelas);
}
void QCotizaPractica::ConectaSlots()
{
	connect(QLEEscuelas,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoEscuela()));
	connect(QLEMaterias,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoMateria()));
	connect(QLEPracticas,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoPractica()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_AnexarALaOrden()));
	connect(QPBVende,
		SIGNAL(clicked()),
		SLOT(S_VendeLoQueHay()));
	
}
void QCotizaPractica::S_AnexarALaOrden()
{
	intSeleccion=1;	
	done(1);
}
void QCotizaPractica::S_VendeLoQueHay()
{
	intSeleccion=1;
	done(1);

}
void QCotizaPractica::S_SeleccionoPractica()
{
ProductosE lProductos;
PPractica=PPracticas.at(QCBPracticas->currentItem());
PProductos.clear();


ConsultaPracticas lCnsPractica(SisDatCom,
			       PPractica->SRegistrosPro2["IdPractica"],
			       chrPtrIdExpendio,
			       chrPtrNmbTipoPrecio,
			       lProductos);
ProductoE *lProducto;
int lintContador;
	QTDatos->setNumRows(lProductos.count()-1);
	for(lProducto=lProductos.first(),
	    lintContador=0;
	    lintContador<lProductos.count()-1;
	    lProducto=lProductos.next(),
	    lintContador++)
	{
	SiscomAnexarRegistroALaTabla(lintContador,
				     QTDatos,
				     QStringList() <<
				     lProducto->SRegistrosPro2["CveProducto"] <<
				     lProducto->SRegistrosPro2["SePuedeVender"] <<
				     lProducto->SRegistrosPro2["Existencia"]  <<
				     lProducto->SRegistrosPro2["Cantidad"]    <<
				     lProducto->SRegistrosPro2["Precio"]      <<
				     lProducto->SRegistrosPro2["Importe"]  );
	if(!strcmp(lProducto->SRegistrosPro2["SePuedeVender"],"Si"))
	PProductos<< lProducto;
	else
	   PProdLoQueHay << lProducto;
	}
	 
	    QLCNTotal->display(lProducto->SRegistrosPro2["Importe"]);
	    /* Por culpa del la forma en la que se anexa, una lista 
	     * de productos a la orden
	     */
	    PProductos<<lProducto;
	    QPBAnexar->setEnabled(!PProdLoQueHay.count());
	    QPBVende->setEnabled(PProdLoQueHay.count());
	    if(PProdLoQueHay.count())
	     ColocaExtension();

}
void QCotizaPractica::S_SeleccionoMateria()
{
	MMateria=MMaterias.at(QCBMaterias->currentItem());
	ConsultaPracticasDeLaMateria();
	SiscomPasaFocoControl(QLEPracticas);
}
void QCotizaPractica::S_SeleccionoEscuela()
{
	EEscuela=EEscuelas.at(QCBEscuelas->currentItem());
	ConsultaMateriasDeLaEscuela();
	SiscomPasaFocoControl(QLEMaterias);
}
void QCotizaPractica::ConsultaLasEscuelas()
{

ConsultaEscuelas lCnsEscuelas(SisDatCom,
			      EEscuelas);
Escuela *lEscuela;
	for(lEscuela=EEscuelas.first();
	    lEscuela;
	    lEscuela=EEscuelas.next())
	 QCBEscuelas->insertItem(lEscuela->SRegistrosPro2["Nombre"]);
}
void QCotizaPractica::ConsultaMateriasDeLaEscuela()
{
MMaterias.clear();
ConsultaMaterias lCnsMaterias(SisDatCom,
			      EEscuela->SRegistrosPro2["IdEscuela"],
			      MMaterias);	
Materia *lMateria;
	QCBMaterias->clear();
	
	for(lMateria=MMaterias.first();
	    lMateria;
	    lMateria=MMaterias.next())
	   QCBMaterias->insertItem(lMateria->SRegistrosPro2["Nombre"]);
}
void QCotizaPractica::ConsultaPracticasDeLaMateria()
{
PPracticas.clear();
ConsultaPracticas lCnsPracticas(SisDatCom,
				MMateria->SRegistrosPro2["IdMateria"],
				PPracticas);
Practica *lPractica;
	QCBPracticas->clear();
	for(lPractica=PPracticas.first();
	    lPractica;
	    lPractica=PPracticas.next())
	  QCBPracticas->insertItem(lPractica->SRegistrosPro2["Nombre"]);

}
int QCotizaPractica::ObtenSeleccion()
{
	return intSeleccion;
}
void QCotizaPractica::ColocaExtension()
{
QExtNoAlcanzan *lQENoAlcanzan=new QExtNoAlcanzan;
		lQENoAlcanzan->PonProductos(PProdLoQueHay);
		lQENoAlcanzan->MuestraProductos();
		setExtension(lQENoAlcanzan);
		showExtension(true);

}
