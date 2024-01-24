#include <IMP_MantenProductos.h>
#include <SISCOMComunicaciones++.h>
#include <CQSiscomCom.h>
#include <Productos.h>
#include <ProductosProt2.h>
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
				   CSISCOMDatComunicaciones *pCSisDatCom,
				   QWidget* parent,
				   const char* name,
				   bool modal,
				   WFlags fl )
    : MantenProductos( parent, name, modal, fl ),
     SDatCom(pSisDatCom),
     CSisDatCom(pCSisDatCom),
     QWParent(parent)
{
	ConectaSlots();
	IniciaVariables();
	exec();
}


QMantenProductos::~QMantenProductos()
{
}
void QMantenProductos::ConectaSlots()
{
	connect(QPBModificar,
		SIGNAL(clicked()),
		SLOT(S_ModificaProducto()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
}
void QMantenProductos::S_Cancelar()
{
	done(1);
}
void QMantenProductos::S_ModificaProducto()
{
ProductosProt2 lProductosProt2;

	       lProductosProt2  <<
	       new ProductoProt2(PProducto->ObtenClave(),
	       			 (const char *)QLEDescripcion->text(),
				 FFamilia->ObtenIdFamilia(),
				 UUnidad->ObtenUnidad());
SiscomGeneralOperacionesSrv lSGenOperaciones(SDatCom,
					     (QPtrList<SiscomInformacion> *)&lProductosProt2);
			lSGenOperaciones.SiscomEjecutaEnvio("ModificaProducto");
}
void QMantenProductos::IniciaVariables()
{
	QLECFamilias=ColocaLineEditAlCombo(QCBFamilias,"QLECFamilias");
	QLECUnidades=ColocaLineEditAlCombo(QCBUnidades,"QLECUnidades");
	QLECProducto=ColocaLineEditAlCombo(QCBProductos,"QLECProducto");
	CQSFamilia=new CQSeleccionaFamilia(CSisDatCom,
					   QWParent,
					   "CQSFamilia",
					   QLECFamilias,
					   0,
					   QCBFamilias);
	connect(CQSFamilia,
		SIGNAL(Signal_Familia(Familia *)),
		SLOT(S_SeleccionoFamilia(Familia *)));
	CQSUnidades=new CQSeleccionaUnidades(CSisDatCom,
                                             QWParent,
                                             "CQSUnidades",
                                             QLECUnidades,
                                             QLEAbreviatura,
                                             QCBUnidades);
	connect(CQSUnidades,
		SIGNAL(Signal_SUnidad(Unidad *)),
		SLOT(S_SeleccionoUnidad(Unidad *)));	
	CQSProducto=new CQSeleccionaProducto(CSisDatCom,
					     QWParent,
					     "CQSProducto",
					     QLECProducto,
					     QLEDescripcion,
					     QLEAbreviatura,
					     QCBProductos);
	connect(CQSProducto,
		SIGNAL(Signal_SProducto(Producto *)),
		SLOT(S_SeleccionoProducto(Producto *)));

	PasaFocoControl(QLECFamilias);
}
void QMantenProductos::S_SeleccionoProducto(Producto *pProducto)
{
 PProducto=pProducto;
 QLEFamilia->setText(pProducto->ObtenFamilia()->ObtenNmbFamilia()); 
 QLEUnidades->setText(pProducto->ObtenUnidad()->ObtenNmbUnidad());
 QLEDescripcionB->setText(pProducto->ObtenDescripcion());
 UUnidad=pProducto->ObtenUnidad();
 FFamilia=pProducto->ObtenFamilia();
}
void QMantenProductos::S_SeleccionoUnidad(Unidad *pUnidad)
{
	UUnidad=pUnidad;
}
void QMantenProductos::S_SeleccionoFamilia(Familia *pFamilia)
{
	FFamilia=pFamilia;
}
