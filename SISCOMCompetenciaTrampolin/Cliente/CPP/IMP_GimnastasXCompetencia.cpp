#include <IMP_GimnastasXCompetencia.h>
#include <IMP_ActDatCompGimnasta.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlCompetencias.h>
#include <QCtrlBuscaPersonas.h>
#include <CQSisCompetencias.h>
#include <CQSisConsultas.h>
#include <CQSisEntrenadores.h>
#include <CQSisGimnasios.h>
#include <CQSisClase.h>
#include <CQSisNivel.h>
#include <CQSisGrupo.h>

#include <qtable.h>
#include <qpushbutton.h>
QGimnastasXCompetencia *InstanciaGimnastasXCompetencia(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QGimnastasXCompetencia((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QGimnastasXCompetencia::QGimnastasXCompetencia(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				GimnastasXCompetencia(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
if(chrPtrArgumentos[26])
{
CQSCompetencia=(CQSisCompetencia *)chrPtrArgumentos[26];
SlotCompetencia(CQSCompetencia);
}
}

QGimnastasXCompetencia::~QGimnastasXCompetencia()
{

}

void QGimnastasXCompetencia::ConectaSlots()
{
/*
	connect(QCtrCompetencias,
		SIGNAL(SignalCompetencia(CQSisCompetencia *)),
		SLOT(SlotCompetencia(CQSisCompetencia *)));
*/
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotActualiza(int,int,int,const QPoint &)));
	connect(QPBADCompetencia,
		SIGNAL(clicked()),
		SLOT(SlotActDatComGimnasta()));
	connect(QPBAPantalla,
		SIGNAL(clicked()),
		SLOT(SlotActualizaPantalla()));

}
void QGimnastasXCompetencia::SlotActualizaPantalla()
{
	Consultando();
}
void QGimnastasXCompetencia::SlotActDatComGimnasta()
{
QActDatCompGimnasta lQADCGimnasta(SisDatCom,CQSCompitiendo);
				  
	QPBADCompetencia->setEnabled(false);
}
void QGimnastasXCompetencia::SlotActualiza(int pintGimnasta,
					   int,
					   int,
					   const QPoint &)
{

	if(pintGimnasta!=-1)
	{
	 CQSCompitiendo=CQSLCompitiendo.at(pintGimnasta);
	 QPBADCompetencia->setEnabled(true);
	}


}
void QGimnastasXCompetencia::SlotCompetencia(CQSisCompetencia *pCQSCompetencia)
{
	CQSCompetencia=pCQSCompetencia;
	Consultando();
}
void QGimnastasXCompetencia::Consultando()
{
    Consulta();
    MuestraGimnastas();
}
void QGimnastasXCompetencia::Consulta()
{
CQSisOpConsultas lCQSOConsultas(SisDatCom);
		lCQSOConsultas.GimnastasCompetencia(CQSCompetencia,
						    &CQSLCompitiendo);
}
void QGimnastasXCompetencia::IniciaVariables()
{
/*
	QCtrCompetencias->PonServidor(SisDatCom);
	QCtrCompetencias->IniciaControl();
*/
	QPBADCompetencia->setEnabled(false);
}
void QGimnastasXCompetencia::MuestraGimnastas()
{
CQSisCompitiendo *lCQSCompitiendo;
int lintContador;
QTDatos->setNumRows(CQSLCompitiendo.count());
for(lintContador=0,
    lCQSCompitiendo=CQSLCompitiendo.first();
    lCQSCompitiendo;
    lCQSCompitiendo=CQSLCompitiendo.next(),
    lintContador++)
   SiscomAnexarRegistroALaTabla(
   	lintContador,
	QTDatos,
	QStringList() 									<<
	QString(lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["Nombre"])	+ 
	" "							   		+
	lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["APaterno"]		+
	" "									+	
	lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["AMaterno"]			<<
	lCQSCompitiendo->ObtenGimnasio()->SRegistrosPro2["Gimnasio"]			<<
	QString((*lCQSCompitiendo->ObtenEntrenador())["Nombre"])		+
	" "									+
	(*lCQSCompitiendo->ObtenEntrenador())["APaterno"]			+
	" "									+
	(*lCQSCompitiendo->ObtenEntrenador())["AMaterno"]				<<
	lCQSCompitiendo->ObtenClase()->SRegistrosPro2["Clase"]				<<
	lCQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"]				<<
	lCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"]				<<
	(*lCQSCompitiendo->ObtenGrupo())["RangoEdad"]);
SiscomAjustaColumnas(QTDatos);
}
