#include <QResCompetencia.h>
#include <CQSisCompitiendo.h>
#include <CQSisEntrenadores.h>
#include <CQSisCalificaciones.h>
#include <CQSisGimnasios.h>
#include <SISCOMComunicaciones++.h>
#include <qtable.h>
#include <qlayout.h>

QResCompetencia::QResCompetencia(CQSisLstCompitiendo *pCQSLCompitiendo,
				 QWidget *pQWParent,
				 const char *pchrPtrName,
				 WFlags pWFlags):
			 CQSLCompitiendo(pCQSLCompitiendo),
			 QWidget(pQWParent,pchrPtrName,pWFlags)
{

	IniciaTabla();
	IniciaVariables();
	MuestraGimnastas();
	SiscomAjustaColumnas(QTDatos);

}

void QResCompetencia::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QHBLayout->addWidget(QTDatos);
}
void QResCompetencia::IniciaTabla()
{

	QTDatos=new QTable(0,3,this,"QTDatos");
	QTDatos->horizontalHeader()->setLabel(0,"Gimnasta");
	QTDatos->horizontalHeader()->setLabel(1,"Gimnasio");
	QTDatos->horizontalHeader()->setLabel(2,"Calificacion Final");
	QTDatos->setReadOnly(true);
}
void QResCompetencia::MuestraGimnastas()
{
CQSisCompitiendo *lCQSCompitiendo;
int lintContador;
	QTDatos->setNumRows(CQSLCompitiendo->count());
	for(lintContador=0,
	    lCQSCompitiendo=CQSLCompitiendo->first();
	    lCQSCompitiendo;
	    lCQSCompitiendo=CQSLCompitiendo->next(),
	    lintContador++)
	{
	 SiscomAnexarRegistroALaTabla(
	    lintContador,
	    QTDatos,
	    QStringList() 								<<
	     QString(lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["Nombre"])+
	     " "								+
	     lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["APaterno"]	+
	     "	"								+
	     lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["AMaterno"] 		<<
	     lCQSCompitiendo->ObtenGimnasio()->SRegistrosPro2["Gimnasio"]		<<
	     lCQSCompitiendo->ObtenCalificacion()->SRegistrosPro2["NotaFinal"]);
	 }
}

QResCompetenciaLst::QResCompetenciaLst()
{

}
QResCompetenciaLst &QResCompetenciaLst::operator<<(QResCompetencia *pQRCompetencia)
{
	append(pQRCompetencia);
	return *this;
}
