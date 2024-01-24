
#include <QCtrlRecetas.h>
#include <QSisReceta.h>
#include <CQSisConsultas.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>
#include <qtabwidget.h>


QCtrlRecetas::QCtrlRecetas( QWidget *parent, const char *name )
    : QWidget( parent, name ),
      intNumWidgets(0)
{
	IniciaVariables();
}
void QCtrlRecetas::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QTWRecetas=new QTabWidget(this);
	QHBLayout->addWidget(QTWRecetas);
}
void QCtrlRecetas::MuestraRecetas()
{
if(CQSLReceta.count())
{
CQSisReceta *lCQSReceta;
for(lCQSReceta=CQSLReceta.first();
    lCQSReceta;
    lCQSReceta=CQSLReceta.next())
  QTWRecetas->addTab(CreaReceta(lCQSReceta),(*lCQSReceta)["FolioRegistrado"]); 
}
else
CargaRecetaVacia();
}
void QCtrlRecetas::OtroFolio()
{
CargaRecetaVacia();
}
void QCtrlRecetas::IniciaControl()
{
	ConsultaRecetas();
	MuestraRecetas();
}
void QCtrlRecetas::ConsultaRecetas()
{
CQSisOpReceta lCQSOReceta(SisDatCom);
lCQSOReceta.Receta((*CQSConsulta)["IdConsulta"],
		   &CQSLReceta);
}
int QCtrlRecetas::HayRecetas(SiscomDatCom *pSisDatCom,
			      const char *pchrPtrIdConsulta)

{
CQSisLstReceta lCQSLReceta;
	CQSisOpReceta lCQSOReceta(pSisDatCom);
lCQSOReceta.Receta(pchrPtrIdConsulta,
		   &lCQSLReceta);
return lCQSLReceta.count();
}
void QCtrlRecetas::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlRecetas::Consulta(CQSisConsulta *pCQSConsulta)
{
	CQSConsulta=pCQSConsulta;
}
void QCtrlRecetas::ConectaSlots()
{
}
void QCtrlRecetas::SlotCambiaFolio(const QString &pQSFolio,
				   int pintIdWidgetReceta)
{
QTWRecetas->setTabLabel(QTWRecetas->page(pintIdWidgetReceta),pQSFolio);

}
void QCtrlRecetas::setFocus()
{
	
}
void QCtrlRecetas::CargaRecetaVacia()
{
QTWRecetas->addTab(CreaReceta(),"Sin Folio");
QTWRecetas->setCurrentPage(intNumWidgets-1);
}
QSisReceta *QCtrlRecetas::CreaReceta(CQSisReceta *pCQSReceta)
{
QSisReceta *lQSReceta;
lQSReceta=new QSisReceta(pCQSReceta,this,(*pCQSReceta)["Folio"]);
lQSReceta->Consulta(CQSConsulta);
lQSReceta->Servidor(SisDatCom);
lQSReceta->IdWidgetReceta(intNumWidgets++);
	connect(lQSReceta,
		SIGNAL(SignalCambiaFolio(const QString &,int)),
		SLOT(SlotCambiaFolio(const QString &,int)));
return lQSReceta;

}
QSisReceta *QCtrlRecetas::CreaReceta()
{
QSisReceta *lQSReceta;
lQSReceta=new QSisReceta(this,"RecetaVacia");
lQSReceta->Consulta(CQSConsulta);
lQSReceta->Servidor(SisDatCom);
lQSReceta->IdWidgetReceta(intNumWidgets++);
	connect(lQSReceta,
		SIGNAL(SignalCambiaFolio(const QString &,int)),
		SLOT(SlotCambiaFolio(const QString &,int)));
	connect(lQSReceta,
		SIGNAL(SignalRegistroReceta(QSisReceta *)),
		SLOT(SlotRegistroReceta(QSisReceta *)));
return lQSReceta;

}
void QCtrlRecetas::SlotRegistroReceta(QSisReceta *pQSReceta)
{
	emit SignalRegistroReceta(pQSReceta);
}
int QCtrlRecetas::Recetas()
{
	return CQSLReceta.count();
}
