#include <IMP_Rondas.h>
#include<SISCOMComunicaciones++.h>
#include <SISCOMVentanaPrincipal3.h>


#include <QCtrlCompetencias.h>
#include <QCtrlAparatoCompetencia.h>
#include <CQSisCompetencias.h>
#include <CQSisConsultas.h>
#include <CQSisEntrenadores.h>
#include <CQSisNivel.h>
#include <CQSisGrupo.h>
#include <CQSisClase.h>
#include <CQSisGimnasios.h>
#include <QGimnastasAparatos.h>
#include <CQSisAparato.h>
#include <CQSisCGimnastas.h>
#include <QCompetenciaAparato.h>
#include <QSoloAparatos.h>

#include <qtabwidget.h>
#include <qpushbutton.h>
QRondas *InstanciaRondas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRondas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRondas::QRondas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Rondas(pQWParent,pchrPtrName,pWFlags),
				QWParent(pQWParent),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				intNoRonda(0)
{
IniciaVariables();
ConectaSlots();
if(chrPtrArgumentos[26])
{
CQSCompetencia=(CQSisCompetencia *)chrPtrArgumentos[26];
SlotCompetencia(CQSCompetencia);
}
}
QRondas::QRondas(SiscomDatCom *pSisDatCom,
		 CQSisCompetencia *pCQSCompetencia,
		 QWidget *pQWParent,
		 const char *pchrPtrName):
	   Rondas(pQWParent,pchrPtrName),
	   CQSCompetencia(pCQSCompetencia),
	   SisDatCom(pSisDatCom)
{
ConectaSlots();
ConsultaGimnastas();
MuestraGimnastas();
SiscomAjustaColumnas(QTGimnastas);
ConsultandoRondas();
show();

}
QRondas::~QRondas()
{

}

void QRondas::ConectaSlots()
{
/*
	connect(QCtrCompetencias,
		SIGNAL(SignalCompetencia(CQSisCompetencia *)),
		SLOT(SlotCompetencia(CQSisCompetencia *)));
*/
/*
	connect(QCtrAparatos,
		SIGNAL(SignalAparatoCompetencia(CQSisAparatoCompetencia *)),
		SLOT(SlotAparatoCompetencia(CQSisAparatoCompetencia *)));
*/
	connect(QTGimnastas,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(SlotGimnastaAparato(int,int,int,const QPoint &)));
	connect(QPBRRondas,
		SIGNAL(clicked()),
		SLOT(SlotRegistraRondas()));
	connect(QPBARonda,
		SIGNAL(clicked()),
		SLOT(SlotARonda()));
	connect(QTWRondas,
		SIGNAL(currentChanged(QWidget *)),
		SLOT(SlotCambiaRonda(QWidget *)));

}
void QRondas::SlotCambiaRonda(QWidget *pQWRonda)
{
	QGmnsAparatos=(QGimnastasAparatos *)pQWRonda;
}
void QRondas::SlotARonda()
{
char lchrArrNmbRonda[25];
QGimnastasAparatos *lQGAparatos;
CQSisLstAparatoCompetencia lCQSLACompetencia;
QSoloAparatos *lQSAparatos=(QSoloAparatos *)chrPtrArgumentos[27];
sprintf(lchrArrNmbRonda,"Ronda %d",++intNoRonda);
lCQSLACompetencia=lQSAparatos->AparatosCompetencia();
lQGAparatos=new QGimnastasAparatos(&lCQSLACompetencia,
				   "",
				   strdup(lchrArrNmbRonda),
				   (*CQSCompetencia)["IdCompetencia"]);
QTWRondas->insertTab(lQGAparatos,lchrArrNmbRonda);
QTWRondas->setCurrentPage(intNoRonda-1);
}
void QRondas::SlotRegistraRondas()
{
CQSisLstRonda lCQSLRonda;
CQSisRonda *lCQSRonda;
QGimnastasAparatos *lQGmnsAparatos;
CQSLRonda.clear();
AsignaPaginasRonda();
	for(lQGmnsAparatos=QGmsApRondas.first();
	    lQGmnsAparatos;
	    lQGmnsAparatos=QGmsApRondas.next())
	{
	lCQSLRonda=lQGmnsAparatos->ObtenGimnastasPorAparato();
	 for(lCQSRonda=lCQSLRonda.first();
	     lCQSRonda;
	     lCQSRonda=lCQSLRonda.next())
	  CQSLRonda << lCQSRonda; 
	}
CQSisOpRonda lCQSORonda(SisDatCom);
	lCQSORonda.RegistraRondas(&CQSLRonda);
}
void QRondas::SlotGimnastaAparato(int pintNumGimnasta,
				   int ,
				   int ,
				   const QPoint &)
{
	if((CQSCompitiendo=CQSLCompitiendo.at(pintNumGimnasta)))
	{
	AsignaGimnastaAparatoRonda();
	MarcaGimnasta(pintNumGimnasta);

	}
}
void QRondas::SlotAparatoCompetencia(CQSisAparatoCompetencia *pCQSACompetencia)
{
	CQSACompetencia=pCQSACompetencia;
	QTGimnastas->setEnabled(true);
	ActivaAparatoRonda();
}
void QRondas::SlotCompetencia(CQSisCompetencia *pCQSCompetencia)
{
	CQSCompetencia=pCQSCompetencia;
	ConsultaGimnastas();
	MuestraGimnastas();
	SiscomAjustaColumnas(QTGimnastas);
	MuestraAparatos();
	/*
	IniciaRondas();

	*/
	ConsultandoRondas();
	MarcaGimnastasAparato();
}
void QRondas::IniciaRondas()
{
}
void QRondas::MuestraAparatos()
{

}
void QRondas::IniciaVariables()
{
	QVPrincipal=(SISCOMVentanaPrincipal *)chrPtrArgumentos[25];
	chrPtrArgumentos[28]=(char *)this;
	QVPrincipal->ActualizaParametro(chrPtrArgumentos[28],28);
}
void QRondas::MuestraGimnastas()
{
int lintContador;
CQSisCompitiendo *lCQSCompitiendo;
QString lQSGimnasta,
	lQSEntrenador;
	QTGimnastas->setNumRows(CQSLCompitiendo.count());
for(lintContador=0,
    lCQSCompitiendo=CQSLCompitiendo.first();
    lCQSCompitiendo;
    lintContador++,
    lCQSCompitiendo=CQSLCompitiendo.next())
{
  GeneraNombre(lCQSCompitiendo->ObtenGimnasta(),lQSGimnasta);
  GeneraNombre(lCQSCompitiendo->ObtenEntrenador(),lQSEntrenador);
  SiscomAnexarRegistroALaTabla(
  	lintContador,
	QTGimnastas,
	QStringList()				<<
	lQSGimnasta				<<
	(*lCQSCompitiendo->ObtenGimnasio())["Gimnasio"]	<<
	lQSEntrenador				<<
	lCQSCompitiendo->ObtenClase()->SRegistrosPro2["Clase"] <<
	lCQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"] <<
	lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"] <<
	lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["RangoEdad"]);
}

}
void QRondas::MarcaGimnastasAparato()
{
CQSisCompitiendo *lCQSCompitiendo;
CQSisAparatoCompetencia *lCQSACompetencia;
QHeader *lQHVertical=QTGimnastas->verticalHeader();
int lintContador;
lQHVertical->setFont(QFont("Helvetica",4));
for(lCQSCompitiendo=CQSLCompitiendo.first(),
    lintContador=0;
    lCQSCompitiendo;
    lCQSCompitiendo=CQSLCompitiendo.next(),
    lintContador++)
{
   if(lCQSACompetencia=CQSLLRonda.AparatoGimnasta(lCQSCompitiendo))
   lQHVertical->setLabel(lintContador,
   			 (*lCQSACompetencia->ObtenAparato())["Aparato"]);
}

}
void QRondas::ConsultaGimnastas()
{
CQSisOpConsultas lCQSOConsultas(SisDatCom);
lCQSOConsultas.GimnastasCompetencia(
		CQSCompetencia,
		&CQSLCompitiendo);
}
void QRondas::GeneraNombre(CQSisEntrenador *pCQSEntrenador,
			   QString &pQSNombre)
{
	pQSNombre=
	QString(pCQSEntrenador->SRegistrosPro2["Nombre"])	+
	" "							+
	pCQSEntrenador->SRegistrosPro2["APaterno"];
}
void QRondas::ActivaAparatoRonda()
{
QGimnastasAparatos *lQGmnsAparatos;
lQGmnsAparatos=(QGimnastasAparatos *)QTWRondas->currentPage();
lQGmnsAparatos->ActivaAparato(CQSACompetencia);

}
void QRondas::AsignaGimnastaAparatoRonda()
{
QGimnastasAparatos *lQGmnsAparatos;
lQGmnsAparatos=(QGimnastasAparatos *)QTWRondas->currentPage();
lQGmnsAparatos->AsignaGimnastaAparato(CQSACompetencia,CQSCompitiendo);
}
void QRondas::MarcaGimnasta(int pintNumGimnasta)
{
QHeader *lQHVertical=QTGimnastas->verticalHeader();
QFont lQFAntes;
 lQHVertical->setFont(QFont("Helvetica",4));
	QTGimnastas->verticalHeader()->setLabel(pintNumGimnasta,
						(*CQSACompetencia->ObtenAparato())["Aparato"]);
}

void QRondas::ConsultandoRondas()
{

ConsultaRondas();
MuestraRondas();

}
void QRondas::MuestraRondas()
{
CQSisLstRonda *lCQSLRonda;
CQSisRonda *lCQSRonda;
CQSisCompitiendo *lCQSCompitiendo;
QGimnastasAparatos *lQGAparatos;
CQSisLstAparatoCompetencia lCQSLACompetencia;
QTWRondas->removePage(QTWRondas->currentPage());
for(lCQSLRonda=CQSLLRonda.first();
    lCQSLRonda;
    lCQSLRonda=CQSLLRonda.next())
{
lCQSLACompetencia=lCQSLRonda->Aparatos();
lQGAparatos=new QGimnastasAparatos(&lCQSLACompetencia,
				   lCQSLRonda->IdRonda(),
				   lCQSLRonda->Nombre(),
				   (*CQSCompetencia)["IdCompetencia"]);

QTWRondas->insertTab(lQGAparatos,lCQSLRonda->Nombre());
QTWRondas->setCurrentPage(0);
for(lCQSRonda=lCQSLRonda->first();
    lCQSRonda;
    lCQSRonda=lCQSLRonda->next())
   for(lCQSCompitiendo=lCQSRonda->Compitiendo()->first();
       lCQSCompitiendo;
       lCQSCompitiendo=lCQSRonda->Compitiendo()->next())
     lQGAparatos->AsignaGimnastaAparato(lCQSRonda->Aparato(),
     					lCQSCompitiendo);

QGmsApRondas << lQGAparatos;
}
intNoRonda=QTWRondas->count();
}
void QRondas::ConsultaRondas()
{
CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
CQSLLRonda.clear();
lCQSOGCompitiendo.CalificaRonda(
		  CQSCompetencia,
		  &CQSLLRonda);
}
void QRondas::AparatoCompetencia(CQSisAparatoCompetencia *pCQSACompetencia)
{
SlotAparatoCompetencia(pCQSACompetencia);
}

void QRondas::AsignaPaginasRonda()
{
int lintContador;
int lintNPaginas=QTWRondas->count();
for(lintContador=0;
    lintContador<lintNPaginas;
    lintContador++)
 QGmsApRondas<< (QGimnastasAparatos *)QTWRondas->page(lintContador);
}
