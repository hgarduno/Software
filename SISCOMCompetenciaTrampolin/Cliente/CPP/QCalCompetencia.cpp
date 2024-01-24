#include <IMP_CalificaGimnasta.h>
#include <QCalCompetencia.h>
#include <CQSisCompitiendo.h>
#include <CQSisEntrenadores.h>
#include <CQSisGimnasios.h>
#include <CQSisCalificaciones.h>
#include <CQSisNivel.h>
#include <CQSisGrupo.h>
#include <CQSisClase.h>
#include <qtable.h>
#include <qlayout.h>
QCalCompetencia::QCalCompetencia(CQSisLstCompitiendo *pCQSLCompitiendo,
				 CQSisAparato *pCQSAparato,
				SiscomDatCom *pSisDatCom,
				QWidget *pQWParent,
				 const char *pchrPtrName,
				 WFlags pWFlags):
			QWidget(pQWParent,pchrPtrName,pWFlags),
			CQSLCompitiendo(pCQSLCompitiendo),
			CQSAparato(pCQSAparato),
			SisDatCom(pSisDatCom)
{

	IniciaTabla();
	MuestraGimnastas();
	IniciaVariables();
	SiscomAjustaColumnas(QTDatos);
	ConectaSlots();

}
void QCalCompetencia::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(SlotCalificaGimnasta(int,int,int,const QPoint &)));

}
void QCalCompetencia::SlotCalificaGimnasta(int pintNGimnasta,
					   int pintJuez,
					   int,
					   const QPoint &)
{
 if(pintJuez>=3 && pintJuez<=4)
 {
 (this->*Jueces[pintJuez])(CQSLCompitiendo->at(pintNGimnasta));	
 emit SignalActualizoCalificacion(this);
 }

}
CQSisAparato *QCalCompetencia::Aparato()
{
return CQSAparato;
}
void QCalCompetencia::ActualizaInformacion(CQSisLstCompitiendo *pCQSLCompitiendo)
{
CQSisCompitiendo *lCQSCompitiendo;
	CQSLCompitiendo=pCQSLCompitiendo;
	MuestraGimnastas();
}
void QCalCompetencia::MuestraGimnastas()
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
	    QStringList() <<
	     QString(lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["Nombre"])+
	     " "								+
	     lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["APaterno"]	+
	     "	"								+
	     lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["AMaterno"] <<
	     (*lCQSCompitiendo->ObtenClase())["Clase"]			  <<
	     (*lCQSCompitiendo->ObtenNivel())["Nivel"]			  <<
	     lCQSCompitiendo->ObtenCalificacion()->SRegistrosPro2["Ejecucion"]	<<
	     lCQSCompitiendo->ObtenCalificacion()->SRegistrosPro2["Dificultad"]	<<
	     lCQSCompitiendo->ObtenCalificacion()->SRegistrosPro2["NotaFinal"]);
	 }
	 QTDatos->setReadOnly(true);
}
void QCalCompetencia::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QHBLayout->addWidget(QTDatos);


	Jueces[0]=&QCalCompetencia::OpcionInvalida;
	Jueces[1]=&QCalCompetencia::OpcionInvalida;
	Jueces[2]=&QCalCompetencia::OpcionInvalida;
	Jueces[3]=&QCalCompetencia::Ejecucion;
	Jueces[4]=&QCalCompetencia::Dificultad;
	Jueces[5]=&QCalCompetencia::NotaFinal;
}

void QCalCompetencia::OpcionInvalida(CQSisCompitiendo *pCQSCompitiendo)
{
printf("Opcion Invalida\n");
}
void QCalCompetencia::Ejecucion(CQSisCompitiendo *pCQSCompitiendo)
{
QCalificaGimnasta lQCGimnasta(QCalificaGimnasta::Ejecucion,
			      SisDatCom,
			      pCQSCompitiendo,
			      CQSAparato);
}
void QCalCompetencia::Dificultad(CQSisCompitiendo *pCQSCompitiendo)
{
QCalificaGimnasta lQCGimnasta(QCalificaGimnasta::Dificultad,
			      SisDatCom,
			      pCQSCompitiendo,
			      CQSAparato);
}
void QCalCompetencia::NotaFinal(CQSisCompitiendo *pCQSCompitiendo)
{
QCalificaGimnasta lQCGimnasta(QCalificaGimnasta::NotaFinal,
			      SisDatCom,
			      pCQSCompitiendo,
			      CQSAparato);
}
void QCalCompetencia::IniciaTabla()
{

	QTDatos=new QTable(0,6,this,"QTDatos");
	QTDatos->horizontalHeader()->setLabel(0,"Gimnasta");
	QTDatos->horizontalHeader()->setLabel(1,"Clase");
	QTDatos->horizontalHeader()->setLabel(2,"Nivel");
	QTDatos->horizontalHeader()->setLabel(3,"Ejecucion");
	QTDatos->horizontalHeader()->setLabel(4,"Dificultad");
	QTDatos->horizontalHeader()->setLabel(5,"Nota Final");
}

QCalCompetenciaLst::QCalCompetenciaLst()
{

}
QCalCompetenciaLst &QCalCompetenciaLst::operator<<(QCalCompetencia *pQCCompetencia)
{
	append(pQCCompetencia);
	return *this;
}
