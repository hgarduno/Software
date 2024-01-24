
#include <QGimnastasAparato.h>

#include <CQSisAparatoCompetencia.h>
#include <CQSisCompitiendo.h>
#include <CQSisAparato.h>
#include <CQSisEntrenadores.h>
#include <CQSisClase.h>
#include <CQSisNivel.h>
#include <CQSisGrupo.h>
#include <CQSisCompitiendo.h>


#include <qtable.h>
#include <qlayout.h>
QGimnastasAparato::QGimnastasAparato(
		CQSisAparatoCompetencia *pCQSACompetencia,
		QWidget *pQWParent,
		const char *pchrPtrName,
		WFlags pWFlags):
	CQSACompetencia(pCQSACompetencia),
	QWidget(pQWParent,pchrPtrName,pWFlags)
{
	IniciaTabla();
	IniciaVariables();
	ConectaSlots();

}
void QGimnastasAparato::IniciaVariables()
{
QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QHBLayout->addWidget(QTDatos);
CQSLCompitiendo=new CQSisLstCompitiendo;
}
void QGimnastasAparato::IniciaTabla()
{

	QTDatos=new QTable(this);

	QTDatos->setNumCols(6);
	QTDatos->horizontalHeader()->setLabel(0,"Gimnasta");
	QTDatos->horizontalHeader()->setLabel(1,"Entrenador");
	QTDatos->horizontalHeader()->setLabel(2,"Clase");
	QTDatos->horizontalHeader()->setLabel(3,"Nivel");
	QTDatos->horizontalHeader()->setLabel(4,"Grupo");
	QTDatos->horizontalHeader()->setLabel(5,"Rango Edad");

	QTDatos->setReadOnly(true);


}
void QGimnastasAparato::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(SlotGimnasta(int,int,int,const QPoint &)));
}
void QGimnastasAparato::SlotGimnasta(int pintNGimnasta,
				     int,
				     int,
				     const QPoint &)
{
	printf("Se Eliminara el gimnastas :%d (%d)\n",
		pintNGimnasta,
		CQSLCompitiendo->count());

	if(pintNGimnasta>=0)
	{
	CQSLCompitiendo->remove(CQSLCompitiendo->at(pintNGimnasta));
	QTDatos->removeRow(pintNGimnasta);
	}
	printf("%d \n",CQSLCompitiendo->count());
}
CQSisAparatoCompetencia *QGimnastasAparato::ObtenAparato()
{
	return CQSACompetencia;
}
void QGimnastasAparato::AnexaGimnastaAparatoRonda(CQSisCompitiendo *pCQSCompitiendo)
{
int lintNFila=QTDatos->numRows();
	QTDatos->setNumRows(lintNFila+1);

	SiscomAnexarRegistroALaTabla(
		lintNFila,
		QTDatos,
		QStringList() 								<<
		QString(pCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["Nombre"]) +
		" "								    +
		pCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["APaterno"]	    +
		" "								    +
		pCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["AMaterno"]	    	<<
		QString(pCQSCompitiendo->ObtenEntrenador()->SRegistrosPro2["Nombre"]) +
		" "								      +
		pCQSCompitiendo->ObtenEntrenador()->SRegistrosPro2["APaterno"]		<<
		pCQSCompitiendo->ObtenClase()->SRegistrosPro2["Clase"]			<<
		pCQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"]			<<
		pCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"]			<<
		pCQSCompitiendo->ObtenGrupo()->SRegistrosPro2["RangoEdad"]);
	SiscomAjustaColumnas(QTDatos);
	(*CQSLCompitiendo) << pCQSCompitiendo;
}
CQSisLstCompitiendo *QGimnastasAparato::ObtenGimnastas()
{
	return CQSLCompitiendo;
}
QGimnastasAparatoLst::QGimnastasAparatoLst()
{

}
QGimnastasAparatoLst &QGimnastasAparatoLst::operator<<(QGimnastasAparato *pQGmnsAparato)
{
	append(pQGmnsAparato);
	return *this;
}
QGimnastasAparato *QGimnastasAparatoLst::operator[](CQSisAparatoCompetencia *pCQSACompetencia)
{
QGimnastasAparato *lQGmnsAparato;
CQSisAparatoCompetencia *lCQSACompetencia;
	for(lQGmnsAparato=first();
	    lQGmnsAparato;
	    lQGmnsAparato=next())
	{
	   lCQSACompetencia=lQGmnsAparato->ObtenAparato();
	   if(!strcmp(lCQSACompetencia->ObtenAparato()->SRegistrosPro2["Aparato"],
	   	      pCQSACompetencia->ObtenAparato()->SRegistrosPro2["Aparato"]))
	    return lQGmnsAparato;

	}

return 0;

}
