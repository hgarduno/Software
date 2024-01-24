#include <IMP_EjecutaCompetencia.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisCGimnastas.h>
#include <QCalCompetencia.h>
#include <QCtrlCompetencias.h>
#include <QSisRonda.h>
#include <CQSisAparatoCompetencia.h>
#include <CQSisAparato.h>

#include <qtabwidget.h>
QEjecutaCompetencia *InstanciaEjecutaCompetencia(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QEjecutaCompetencia((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QEjecutaCompetencia::QEjecutaCompetencia(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				EjecutaCompetencia(pQWParent,pchrPtrName,pWFlags),
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

QEjecutaCompetencia::~QEjecutaCompetencia()
{

}

void QEjecutaCompetencia::ConectaSlots()
{
connect(QPBRotacion,
	SIGNAL(clicked()),
	SLOT(SlotRotacion()));
}
void QEjecutaCompetencia::SlotRotacion()
{
EliminaRondas();
ConsultaRondas();
MuestraInformacion();
}
void QEjecutaCompetencia::SlotCompetencia(CQSisCompetencia *pCQSCompetencia)
{
	CQSCompetencia=pCQSCompetencia;
	ConsultaRondas();
	MuestraInformacion();
}
void QEjecutaCompetencia::MuestraInformacion()
{
CQSisLstRonda *lCQSLRonda;
CQSisRonda *lCQSRonda;
QCalCompetencia *lQCCompetencia;
QSisRonda *lQSRonda;

QTWRondas->removePage(QTWRondas->currentPage());
for(lCQSLRonda=CQSLLRonda.first();
    lCQSLRonda;
    lCQSLRonda=CQSLLRonda.next())
{
/*   
  for(lCQSRonda=lCQSLRonda->first(); 
      lCQSRonda;
      lCQSRonda=lCQSLRonda->next())
  {
     lQCCompetencia=new QCalCompetencia(lCQSRonda->Compitiendo(),
     					lCQSRonda->Aparato()->ObtenAparato(),
					SisDatCom,
					this);
     lQCCompetencia->setEnabled(false);
     QCLCompetencia << lQCCompetencia;
     connect(lQCCompetencia,
     	     SIGNAL(SignalActualizoCalificacion()),
	     SLOT(SlotActualizaCalificacion()));
     QTWAparatos->addTab(lQCCompetencia,(*lCQSRonda->Aparato()->ObtenAparato())["Aparato"]);

  }
  */
  
  lQSRonda=new QSisRonda(lCQSLRonda,SisDatCom,chrPtrArgumentos,this);
  connect(lQSRonda,
  	  SIGNAL(SignalActualizoCalificacion(QCalCompetencia *,
	  				     CQSisLstRonda *)),
	  SLOT(SlotActualizoCalificacion(QCalCompetencia *,
	  				 CQSisLstRonda *)));
  QTWRondas->addTab(lQSRonda,lCQSLRonda->Nombre());

}
QTWRondas->setCurrentPage(0);
}
void QEjecutaCompetencia::SlotActualizoCalificacion(QCalCompetencia *pQCCompetencia,
						    CQSisLstRonda *pCQSLRonda)
{
CQSisLstRonda *lCQSLRonda;
CQSisRonda *lCQSRonda;
   ConsultaRondas();
for(lCQSLRonda=CQSLLRonda.first();
    lCQSLRonda;
    lCQSLRonda=CQSLLRonda.next())
{
if((*lCQSLRonda)==pCQSLRonda)        
{
for(lCQSRonda=lCQSLRonda->first();
    lCQSRonda;
    lCQSRonda=lCQSLRonda->next())
{
	if(!strcmp((*lCQSRonda->Aparato()->ObtenAparato())["Aparato"],
		   (*pQCCompetencia->Aparato())["Aparato"]))
         pQCCompetencia->ActualizaInformacion(lCQSRonda->Compitiendo());
}
}
}
}
void QEjecutaCompetencia::ConsultaRondas()
{
CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
CQSLLRonda.clear();
lCQSOGCompitiendo.CalificaRonda(
		  CQSCompetencia,
		  &CQSLLRonda);

}
void QEjecutaCompetencia::IniciaVariables()
{
}
void QEjecutaCompetencia::EliminaRondas()
{
QWidget *lQWRonda;
int lintContador;

CQSLLRonda.clear();
for(lintContador=0;
    lintContador<QTWRondas->count();
    lintContador++)
{
  QTWRondas->removePage((lQWRonda=QTWRondas->page(lintContador)));
  delete lQWRonda;
}
}
