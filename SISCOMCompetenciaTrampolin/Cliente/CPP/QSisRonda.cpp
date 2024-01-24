#include <QSisRonda.h>
#include <CQSisRonda.h>
#include <CQSisAparatoCompetencia.h>
#include <CQSisAparato.h>
#include <QCalCompetencia.h>
#include <SISCOMComunicaciones++.h>
#include <qtabwidget.h>
QSisRonda::QSisRonda(CQSisLstRonda *pCQSLRonda,
		     SiscomDatCom *pSisDatCom,
		     char **pchrPtrArgumentos,
		     QWidget *pQWParent,
		     const char *pchrPtrName):
		 QWidget(pQWParent,pchrPtrName),
		 CQSLRonda(pCQSLRonda),
		 SisDatCom(pSisDatCom),
		 chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaInterfaz();
MuestraAparatosCompetencia();
}
void QSisRonda::IniciaInterfaz()
{
QHBoxLayout *lQHBLayout;

lQHBLayout=new QHBoxLayout(this);
QTWAparatos=new QTabWidget(this,"QTWAparatosR");
lQHBLayout->setMargin(0);
lQHBLayout->addWidget(QTWAparatos);

}
void QSisRonda::MuestraAparatosCompetencia()
{
CQSisRonda *lCQSRonda;
QCalCompetencia *lQCCompetencia;
for(lCQSRonda=CQSLRonda->first();
    lCQSRonda;
    lCQSRonda=CQSLRonda->next())
{
  lQCCompetencia=new QCalCompetencia(lCQSRonda->Compitiendo(),
                                     lCQSRonda->Aparato()->ObtenAparato(),
				     SisDatCom,
				     this);
   if(strcmp(chrPtrArgumentos[97],"Todos"))  
   lQCCompetencia->setEnabled(!strcmp(chrPtrArgumentos[97],
   				     (*lCQSRonda->Aparato()->ObtenAparato())["Aparato"]));
   connect(lQCCompetencia,
   	   SIGNAL(SignalActualizoCalificacion(QCalCompetencia *)),
	   SLOT(SlotActualizoCalificacion(QCalCompetencia *)));
   QTWAparatos->addTab(lQCCompetencia,
   		       (*lCQSRonda->Aparato()->ObtenAparato())["Aparato"]);
   
}
}
void QSisRonda::SlotActualizoCalificacion(QCalCompetencia *pQCCompetencia)
{
emit SignalActualizoCalificacion(pQCCompetencia,CQSLRonda);
}
