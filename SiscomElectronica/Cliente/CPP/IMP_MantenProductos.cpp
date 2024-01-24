
#include <IMP_MantenProductos.h>


#include <ProductosE.h>
#include <Familias.h>
#include <Unidades.h>


#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QMantenProductos::QMantenProductos(SiscomDatCom *pSisDatCom,
				   const char *pchrPtrIdExpendio,
				   QWidget* parent,
				   const char* name,
				   bool modal, 
				   WFlags fl )
    : MantenProductos( parent, name, modal, fl ),
    SisDatCom(pSisDatCom),
    chrPtrIdExpendio(pchrPtrIdExpendio)
{
	IniciaVariables();
	ConectaSlots();
	exec();
}

QMantenProductos::~QMantenProductos()
{
}
void QMantenProductos::ConectaSlots()
{
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_SelProducto(ProductoE *)));
	connect(MFamilias,
		SIGNAL(SignalFamilia(Familia *)),
		SLOT(S_SelFamilia(Familia *)));
	connect(MUnidades,
		SIGNAL(SignalUnidad(Unidad *)),
		SLOT(S_SelUnidad(Unidad *)));
	connect(QPBModificar,
		SIGNAL(clicked()),
		SLOT(S_ModificaProducto()));

}
void QMantenProductos::S_ModificaProducto()
{
ConsultaProductosE lCnsProductos(SisDatCom);
ProductosE lProductos;

PProducto->SiscomActualizaCampo("IdUnidad",UUnidad->SRegistrosPro2["IdUnidad"]);
PProducto->SiscomActualizaCampo("IdFamilia",FFamilia->SRegistrosPro2["IdFamilia"]);
PProducto->SiscomActualizaCampo("DscProducto",(const char *)QLEDescripcion->text());

	lProductos << PProducto;
	lCnsProductos.ActualizaDatosProductos(lProductos);
}
void QMantenProductos::S_SelUnidad(Unidad *pUnidad)
{
	UUnidad=pUnidad;
	SiscomPasaFocoControl(QLEDescripcion);
}
void QMantenProductos::IniciaVariables()
{
	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	QLECFamilias=SiscomColocaEditAlCombo(QCBFamilias,"QLECFamilias");
	QLECUnidades=SiscomColocaEditAlCombo(QCBUnidades,"QLECUnidades");

	QMProductos=new QManProductos(SisDatCom,
				      chrPtrIdExpendio,
				      QCBProductos,
				      QLECProductos,
				      QLEDescripcion,
				      this,
				      "QMProductos");
	MFamilias=new ManFamilias(SisDatCom,
				  QCBFamilias,
				  QLECFamilias,
				  0,
				  this,
				  "MFamilias");
	MUnidades=new ManUnidades(SisDatCom,
				  QCBUnidades,
				  QLECUnidades,
				  0,
				  0,
				  this,
				  "MUNidades");
	SiscomPasaFocoControl(QLECProductos);

}
void QMantenProductos::S_SelFamilia(Familia *pFamilia)
{
	FFamilia=pFamilia;
	SiscomPasaFocoControl(QLECUnidades);
}
void QMantenProductos::S_SelProducto(ProductoE *pProducto)
{
ProductosE lProductos;
ConsultaProductosE lCnsProductos(SisDatCom);;
	 lCnsProductos.ObtenDatosProducto(chrPtrIdExpendio,
	 				  (*pProducto)["CveProducto"],
					  "Total",
					  lProductos);
	PProducto=lProductos.at(0);
	if(PProducto)
	{
	MuestraDatos();
	SiscomPasaFocoControl(QLECFamilias);
	FFamilia=PProducto->ObtenFamilia();
	UUnidad=PProducto->ObtenUnidad();
	}

}
void QMantenProductos::MuestraDatos()
{
	QLEFamilia->setText(PProducto->SRegistrosPro2["NmbFamilia"]);
	QLEUnidades->setText(PProducto->SRegistrosPro2["NmbUnidad"]);
	QLEDescripcionB->setText(PProducto->SRegistrosPro2["DscProducto"]);
	QLEDescripcion->setText(PProducto->SRegistrosPro2["DscProducto"]);
}
