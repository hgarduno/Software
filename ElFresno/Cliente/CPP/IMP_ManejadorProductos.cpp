#include <IMP_ManejadorProductos.h>
#include <IMP_MantenProductos.h>
#include <SISCOMComunicaciones++.h>
#include <Familias.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>
QManejadorProductos *InstanciaManejadorProductos(void *pCSisDatCom,
						void *pQWParent,
						const char *pchrPtrName,
						int pintWFlags)
{
	return new QManejadorProductos((CSISCOMDatComunicaciones *)pCSisDatCom,
				       (QWidget *)pQWParent,
				       pchrPtrName,
				       pintWFlags);
}

QManejadorProductos::QManejadorProductos(CSISCOMDatComunicaciones *pCSisDatCom,
					QWidget* parent, const char* name, WFlags fl )
    : ManejadorProductos( parent, name, fl ),
    CSisDatCom(pCSisDatCom),
	QWParent(parent)
{
	SDatCom=new SiscomDatCom(atoi(getenv("PtoComSvr2")),
	                                 CSisDatCom->ObtenDirIpSvr());
	IniciaVariables();
	ConectaSlots();
}

QManejadorProductos::~QManejadorProductos()
{
}
void QManejadorProductos::IniciaVariables()
{
	QLECFamilias=ColocaLineEditAlCombo(QCBFamilias,"QLECFamilias");
	QLECUnidades=ColocaLineEditAlCombo(QCBUnidades,"QLECUnidades");
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
	PasaFocoControl(QLECFamilias);
	QPBAnexar->setEnabled(false);
	QPBRegistrar->setEnabled(false);
	QLEProducto->setEnabled(false);
	QLEDescripcion->setEnabled(false);
	QLECUnidades->setEnabled(false);

}
void QManejadorProductos::S_SeleccionoUnidad(Unidad *pUnidad)
{
	U_Unidad=pUnidad;
	QLEProducto->setEnabled(true);
	PasaFocoControl(QLEProducto);
}
void QManejadorProductos::S_SeleccionoFamilia(Familia *pF_Familia)
{
	F_Familia=pF_Familia;
	QLECUnidades->setEnabled(true);
	PasaFocoControl(QLECUnidades);
}
void QManejadorProductos::ConectaSlots()
{
	connect(QLEProducto,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QPBMDatos,
		SIGNAL(clicked()),
		SLOT(S_ModificaProducto()));
}
void QManejadorProductos::S_ModificaProducto()
{
QMantenProductos lQMProductos(SDatCom,
			      CSisDatCom,
			      this);
}
void QManejadorProductos::S_PasaFocoUnidades()
{
	PasaFocoControl(QLECUnidades);
}
void QManejadorProductos::S_PasaFocoDescripcion()
{
	if(!QLEProducto->text().isEmpty())
	{
	QLEDescripcion->setEnabled(true);
	PasaFocoControl(QLEDescripcion);
	}
}
void QManejadorProductos::S_PasaFocoAnexar()
{
	if(!QLEDescripcion->text().isEmpty())
	{
	QPBAnexar->setEnabled(true);
	PasaFocoControl(QPBAnexar);
	}
}
void QManejadorProductos::S_Registrar()
{
if(CQ_Productos.count())
{
CQCtrProductos lCQCProductos(CSisDatCom,
			     CQCtrProductos::Registrar,
			     &CQ_Productos);
	QTDatos->setNumRows(0);
	CQ_Productos.clear();
	PasaFocoControl(QLECFamilias);
}
else
QMessageBox::information(this,"El Fresno","NO Se anexado un producto");
}
void QManejadorProductos::S_Anexar()
{
Producto *lP_Producto;
	AnexarRegistroALaTabla(QTDatos,
				QStringList()                <<
				QLEProducto->text ()         <<
				QLEDescripcion->text()       <<
				F_Familia->ObtenNmbFamilia() <<
				U_Unidad->ObtenAbreviatura()  );	
	lP_Producto=new Producto((const char *)QLEProducto->text(),
				 (const char *)QLEDescripcion->text());
	lP_Producto->PonFamilia(F_Familia);
	lP_Producto->PonUnidad(U_Unidad);
	CQ_Productos.append(lP_Producto);
	CQSFamilia->setFocus();

	QPBRegistrar->setEnabled(true);
	
}
