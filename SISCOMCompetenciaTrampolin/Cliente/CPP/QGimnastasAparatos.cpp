#include <QGimnastasAparatos.h>
#include <CQSisAparatoCompetencia.h>
#include <CQSisAparato.h>
#include <QGimnastasAparato.h>

#include <qtabwidget.h>
#include <qlayout.h>
QGimnastasAparatos::QGimnastasAparatos(CQSisLstAparatoCompetencia *pCQSLACompetencia,
		   const char *pchrPtrIdRonda,
		   const char *pchrPtrNmbRonda,
		   const char *pchrPtrIdCompetencia,
		   QWidget *pQWParent,
		   const char *pchrPtrName,
		   WFlags pWFlags):
		   CQSLACompetencia(pCQSLACompetencia),
		   QWidget(pQWParent,pchrPtrName,pWFlags),
		   chrPtrIdRonda(pchrPtrIdRonda),
		   chrPtrNmbRonda(pchrPtrNmbRonda),
		   chrPtrIdCompetencia(pchrPtrIdCompetencia)
{
	IniciaVariables();
	IniciaAparatos();

}

void QGimnastasAparatos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QTWApGimnastas=new QTabWidget(this);
	QHBLayout->addWidget(QTWApGimnastas);
}

void QGimnastasAparatos::IniciaAparatos()
{
CQSisAparatoCompetencia *lCQSACompetencia;
QGimnastasAparato *QGmnAparato;

for(lCQSACompetencia=CQSLACompetencia->first();
    lCQSACompetencia;
    lCQSACompetencia=CQSLACompetencia->next())
{
QGmnAparato=new QGimnastasAparato(lCQSACompetencia);
QTWApGimnastas->insertTab(
	QGmnAparato,
	lCQSACompetencia->ObtenAparato()->SRegistrosPro2["Aparato"]);
	  QGmnsAparatoLst << QGmnAparato;
	}
}

void QGimnastasAparatos::ActivaAparato(CQSisAparatoCompetencia *pCQSACompetencia)
{
QGimnastasAparato *lQGmnsAparato;
	if((lQGmnsAparato=QGmnsAparatoLst[pCQSACompetencia]))
	QTWApGimnastas->showPage(lQGmnsAparato);
}

void QGimnastasAparatos::AsignaGimnastaAparato(CQSisAparatoCompetencia *pCQSACompetencia,
					       CQSisCompitiendo *pCQSCompitiendo)
{
QGimnastasAparato *lQGmnsAparato;
	if((lQGmnsAparato=QGmnsAparatoLst[pCQSACompetencia]))
	{
	   lQGmnsAparato->AnexaGimnastaAparatoRonda(pCQSCompitiendo);
	}
}
const CQSisLstRonda &QGimnastasAparatos::ObtenGimnastasPorAparato()
{
QGimnastasAparato *lQGmnsAparato;
for(lQGmnsAparato=QGmnsAparatoLst.first();
    lQGmnsAparato;
    lQGmnsAparato=QGmnsAparatoLst.next())
 CQSLRonda << new CQSisRonda(
 			chrPtrIdRonda,
			chrPtrNmbRonda,
			chrPtrIdCompetencia,
			lQGmnsAparato->ObtenAparato(),
			lQGmnsAparato->ObtenGimnastas());

return CQSLRonda;

}

QGimnastasAparatosLst::QGimnastasAparatosLst()
{

}
QGimnastasAparatosLst &QGimnastasAparatosLst::operator<<(QGimnastasAparatos *pQGmnsAparatos)
{
	append(pQGmnsAparatos);
	return *this;
}
