#include <IMP_GimnastasCompetencia.h>
#include <IMP_CalificaGimnasta.h>
#include <QCtrlCompetencias.h>
#include <QCtrlAparatoCompetencia.h>
#include <CQSisConsultas.h>
#include <CQSisEntrenadores.h>
#include <CQSisClase.h>
#include <CQSisNivel.h>
#include <CQSisGrupo.h>
#include <CQSisCalificaciones.h>
#include <CQSisAparato.h>
#include <QCalCompetencia.h>
#include<SISCOMComunicaciones++.h>

#include <qtabwidget.h>
QGimnastasCompetencia *InstanciaGimnastasCompetencia(void *pSisDatCom,
                 void *pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QGimnastasCompetencia((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QGimnastasCompetencia::QGimnastasCompetencia(SiscomDatCom *pSisDatCom, 
			            void *pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				GimnastasCompetencia(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QGimnastasCompetencia::~QGimnastasCompetencia()
{

}

void QGimnastasCompetencia::ConectaSlots()
{
	connect(QCtrCompetencias,
		SIGNAL(SignalCompetencia(CQSisCompetencia *)),
		SLOT(SlotCompetencia(CQSisCompetencia *)));
/*
	connect(QIVGrupos,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(SlotGrupo(QIconViewItem *)));
*/
	connect(QIVGrupos,
		SIGNAL(selectionChanged(QIconViewItem *)),
		SLOT(SlotGrupo(QIconViewItem *)));
	connect(QCtrACompetencia,
		SIGNAL(SignalAparatoCompetencia(CQSisAparatoCompetencia *)),
		SLOT(SlotAparatoCompetencia(CQSisAparatoCompetencia *)));
}
void QGimnastasCompetencia::SlotAparatoCompetencia(
				CQSisAparatoCompetencia *pCQSACompetencia)
{
	CQSACompetencia=pCQSACompetencia;
	ConsultandoGimnastasPorClase();
	QLEAparato->setText(pCQSACompetencia->ObtenAparato()->SRegistrosPro2["Aparato"]);
}
void QGimnastasCompetencia::SlotGrupo(QIconViewItem *pQIVItemGrupo)
{

	if(pQIVItemGrupo)
	QTWGmnClase->showPage(
	 ((QIconViewItemGrupo *)pQIVItemGrupo)->ObtenGrupo());
}
void QGimnastasCompetencia::SlotCompetencia(CQSisCompetencia *pCQSCompetencia)
{
	CQSCompetencia=pCQSCompetencia;
	/*ConsultandoGimnastasPorClase(); */
	ConsultaAparatosCompetencia();
	QTWInformacion->setCurrentPage(1);
	QLECompetencia->setText(pCQSCompetencia->SRegistrosPro2["Competencia"]);
}
void QGimnastasCompetencia::IniciaVariables()
{
	QCtrCompetencias->PonServidor(SisDatCom);
	QCtrCompetencias->IniciaControl();

}

void QGimnastasCompetencia::ConsultandoGimnastasPorClase()
{
	ConsultaGimnastasPorClase();
	MuestraGimnastasPorClase();
}
void QGimnastasCompetencia::ConsultaGimnastasPorClase()
{

CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
	CQSLLCompitiendo.clear();
	lCQSOGCompitiendo.ObtenClasificacionGmn(
			CQSCompetencia,
			CQSACompetencia,
			&CQSLLCompitiendo);

}
void QGimnastasCompetencia::ConsultaAparatosCompetencia()
{
	QCtrACompetencia->PonServidor(SisDatCom);
	QCtrACompetencia->PonCompetencia(CQSCompetencia);
	QCtrACompetencia->IniciaControl();
}
void QGimnastasCompetencia::MuestraGimnastasPorClase()
{
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
QString lQSClaseNivel;
QCalCompetencia *lQCCompetencia;
	QTWGmnClase->removePage(QTWGmnClase->currentPage());
	QIVGrupos->clear();
	LimpiaControles();
	QCCompetenciaLst.clear();
	for(lCQSLCompitiendo=CQSLLCompitiendo.first();
	    lCQSLCompitiendo;
	    lCQSLCompitiendo=CQSLLCompitiendo.next())
	{
	  lCQSCompitiendo=lCQSLCompitiendo->at(0);
	  lQSClaseNivel=QString("Clase ")					+
	  		lCQSCompitiendo->ObtenClase()->SRegistrosPro2["Clase"]	+
			" "							+
			"Nivel "						+
			lCQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"]  +
			" "							+
			lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"]	+
			" "							+
			lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["RangoEdad"];
	  lQCCompetencia=new QCalCompetencia(
	  			lCQSLCompitiendo,
	  			CQSACompetencia->ObtenAparato(),
				SisDatCom);	
	  connect(lQCCompetencia,
	  	  SIGNAL(SignalActualizoCalificacion()),
		  SLOT(SlotActualizoCalificacion()));
	  QTWGmnClase->addTab(lQCCompetencia,lQSClaseNivel);
	  QIVGrupos->insertItem(new QIconViewItemGrupo(lQCCompetencia,
	  					       lQSClaseNivel,
						       QIVGrupos));
	  QCCompetenciaLst << lQCCompetencia;
	  }
	QTWGmnClase->setCurrentPage(0);	
}
void QGimnastasCompetencia::SlotActualizoCalificacion()
{
QCalCompetencia *lQCCompetencia;
CQSisLstCompitiendo *lCQSLCompitiendo;
	ConsultaGimnastasPorClase();
for(lQCCompetencia=QCCompetenciaLst.first(),
    lCQSLCompitiendo=CQSLLCompitiendo.first();
    lQCCompetencia;
    lQCCompetencia=QCCompetenciaLst.next(),
    lCQSLCompitiendo=CQSLLCompitiendo.next())
    lQCCompetencia->ActualizaInformacion(lCQSLCompitiendo);
}
void QGimnastasCompetencia::LimpiaControles()
{
	LimpiaTabWidget();
}
void QGimnastasCompetencia::LimpiaTabWidget()
{
QCalCompetencia *lQCCompetencia;
	for(lQCCompetencia=QCCompetenciaLst.first();
	    lQCCompetencia;
	    lQCCompetencia=QCCompetenciaLst.next())
	 QTWGmnClase->removePage(lQCCompetencia);
}

QIconViewItemGrupo::QIconViewItemGrupo(QWidget *pQWGrupo,
				       QString pQSTexto,
				       QIconView *pQWIVParent):
		QIconViewItem(pQWIVParent),
		QWGrupo(pQWGrupo)
{
	setText(pQSTexto);
}				    
QWidget *QIconViewItemGrupo::ObtenGrupo()
{
	return QWGrupo;
}
