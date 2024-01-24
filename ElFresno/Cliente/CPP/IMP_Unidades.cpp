#include <IMP_Unidades.h>
#include <IMP_MantenUnidad.h>
#include <CQSiscomCom.h>
#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

QUnidades *InstanciaUnidades(void *pCSisDatCom,
			     void *pQWParent,
			     const char *pchrPtrName,
			     int pintWFlags)
{

	return new QUnidades((CSISCOMDatComunicaciones *)pCSisDatCom,
			     (QWidget *)pQWParent,
			     pchrPtrName,
			     pintWFlags);
}

QUnidades::QUnidades(CSISCOMDatComunicaciones *pCSisDatCom,
		      QWidget* parent, const char* name, WFlags fl )
    : Unidades( parent, name, fl ),
	CSisDatCom(pCSisDatCom)
{
	SDatCom=new SiscomDatCom(atoi(getenv("PtoComSvr2")),
	                                 CSisDatCom->ObtenDirIpSvr());
	IniciaVariables();
	ConsultaUnidades();
	ConectaSlots();
}

QUnidades::~QUnidades()
{
}
void QUnidades::ConectaSlots()
{
	connect(QLEUnidad,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAbreviatura()));
	connect(QLEAbreviatura,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_SeleccionaUnidad(int,int,int,const QPoint &)));
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(S_ModificaUnidad(int,int,int,const QPoint &)));
}
void QUnidades::S_SeleccionaUnidad(int pintNFila,
				   int,
				   int,
				   const QPoint &)
{
	if(pintNFila!=-1)
	 QTDatos->selectRow(pintNFila);
}
void QUnidades::S_ModificaUnidad(int pintNFila,
				 int,
				 int,
				 const QPoint &)
{
QMantenUnidad lQMUnidad(SDatCom,
			CQ_Unidades.at(pintNFila));

}
void QUnidades::IniciaVariables()
{
	PasaFocoControl(QLEUnidad);
}
void QUnidades::S_Registrar()
{
CQCtrUnidades lCQCUnidades(CSisDatCom,
			   CQCtrUnidades::Registrar,
			   &CQ_Unidades);
}
void QUnidades::S_Anexar()
{
	AnexarRegistroALaTabla(QTDatos,
				QStringList () <<
				QLEUnidad->text() <<
				QLEAbreviatura->text());
	CQ_Unidades.append(new Unidad("",
				      (const char *)QLEUnidad->text(),
				      (const char *)QLEAbreviatura->text()));
	PasaFocoControl(QLEUnidad);
}
void QUnidades::S_PasaFocoAnexar()
{
	PasaFocoControl(QPBAnexar);
}
void QUnidades::S_PasaFocoAbreviatura()
{
	PasaFocoControl(QLEAbreviatura);
}
void QUnidades::ConsultaUnidades()
{
CQCtrUnidades lCQCUnidades(CSisDatCom,
			   CQCtrUnidades::Consultar,
			   &CQ_Unidades);
Unidad *lU_Unidad;

	for(lU_Unidad=CQ_Unidades.first();
	    lU_Unidad;
	    lU_Unidad=CQ_Unidades.next())
	AnexarRegistroALaTabla(QTDatos,
			      QStringList () <<
				lU_Unidad->ObtenNmbUnidad() <<
				lU_Unidad->ObtenAbreviatura());
	
}
