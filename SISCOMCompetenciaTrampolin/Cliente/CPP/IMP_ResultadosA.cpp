#include <IMP_ResultadosA.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisCompetencias.h>
#include <CQSisAparatoCompetencia.h>
#include <QCtrlClase.h>
#include <QCtrlGrupo.h>
#include <QCtrlNivel.h>
#include <QCtrlAparatoCompetencia.h>
#include <QResCompetencia.h>
#include <CQSisClase.h>
#include <CQSisGrupo.h>
#include <CQSisNivel.h>
#include <QListBoxItemGimnasia.h>
#include <qtabwidget.h>
#include <qlistbox.h>
QResultadosA *InstanciaResultadosA(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QResultadosA((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QResultadosA::QResultadosA(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ResultadosA(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSACompetencia(0)
{
if(chrPtrArgumentos[26])
CQSCompetencia=(CQSisCompetencia *)chrPtrArgumentos[26];
IniciaVariables();
ConectaSlots();
}

QResultadosA::~QResultadosA()
{

}

void QResultadosA::ConectaSlots()
{
	connect(QLBClases,
		SIGNAL(selected(QListBoxItem *)),
		SLOT(SlotClase(QListBoxItem *)));
	connect(QLBINiveles,
		SIGNAL(selected(QListBoxItem *)),
		SLOT(SlotNivel(QListBoxItem *)));
	connect(QLBIGrupos,
		SIGNAL(selected(QListBoxItem *)),
		SLOT(SlotGrupo(QListBoxItem *)));
	connect(QCtrACompetencia,
		SIGNAL(SignalAparatoCompetencia(CQSisAparatoCompetencia *)),
		SLOT(SlotAparatoCompetencia(CQSisAparatoCompetencia *)));
}
void QResultadosA::SlotAparatoCompetencia(CQSisAparatoCompetencia *pCQSACompetencia)
{
CQSACompetencia=pCQSACompetencia;
ResultadosAparato(CQSACompetencia);
}
void QResultadosA::SlotGrupo(QListBoxItem *pQLBItem)
{
QListBoxItemGrupo *lQBLIGrupo=(QListBoxItemGrupo *)pQLBItem;
CQSisLstLstCompitiendo lCQSLLCompitiendo;
CQSGrupo=lQBLIGrupo->Grupo();
CQSLLCompitiendo.Gimnastas(CQSCNivel,CQSGrupo,&lCQSLLCompitiendo);
EliminaTabWidget();
MuestraResultados(lCQSLLCompitiendo.first());
}
void QResultadosA::SlotNivel(QListBoxItem *pQLBItem)
{
QListBoxItemNivel *lQLBItemNivel=(QListBoxItemNivel *)pQLBItem;
CQSisLstGrupo lCQSLGrupo;
CQSisGrupo *lCQSGrupo;
CQSLLCompitiendo.Grupos(lQLBItemNivel->ClaseNivel(),&lCQSLGrupo);
CQSCNivel=lQLBItemNivel->ClaseNivel();
QLBIGrupos->clear();
for(lCQSGrupo=lCQSLGrupo.first();
    lCQSGrupo;
    lCQSGrupo=lCQSLGrupo.next())
 QLBIGrupos->insertItem(new QListBoxItemGrupo(lCQSGrupo));


}
void QResultadosA::SlotClase(QListBoxItem *pQLBItem)
{
QListBoxItemClase *lQLBItemClase=(QListBoxItemClase *)pQLBItem;
CQSisLstClaseNivel *lCQSLCNivel;
CQSisClaseNivel *lCQSCNivel;
lCQSLCNivel=CQSLCNivel[(*lQLBItemClase->Clase())["Clase"]];
CQSClase=lQLBItemClase->Clase();
QLBINiveles->clear();
for(lCQSCNivel=lCQSLCNivel->first();
    lCQSCNivel;
    lCQSCNivel=lCQSLCNivel->next())
 QLBINiveles->insertItem(new QListBoxItemNivel(lCQSCNivel));
delete lCQSLCNivel;
}
void QResultadosA::IniciaVariables()
{
ConsultaResultados();
ConsultaResultadosAparato();
ClasesCompetencia();
NivelesClase();
MuestraAparatosCompetencia();
}
void QResultadosA::MuestraAparatosCompetencia()
{
QCtrACompetencia->PonServidor(SisDatCom);
QCtrACompetencia->PonCompetencia(CQSCompetencia);
QCtrACompetencia->IniciaControl();
}

void QResultadosA::ConsultaResultados()
{
CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
		lCQSOGCompitiendo.ObtenCompetenciaGeneral(
					CQSCompetencia,
					&CQSLLCompitiendo);


}
void QResultadosA::ConsultaResultadosAparato()
{
CQSisOpGmnCompitiendo lCQSOGCompitiendo(SisDatCom);
		lCQSOGCompitiendo.ObtenResultadosPorAparato(
					CQSCompetencia,
					&CQSLLCompitiendoAparatos);

}
void QResultadosA::ClasesCompetencia()
{
CQSisClase *lCQSClase;
CQSLLCompitiendo.Clases(&CQSLClasesCompetencia);
for(lCQSClase=CQSLClasesCompetencia.first();
    lCQSClase;
    lCQSClase=CQSLClasesCompetencia.next())
 QLBClases->insertItem(new QListBoxItemClase(lCQSClase));
}
void QResultadosA::NivelesClase()
{
CQSisClaseNivel *lCQSCNivel;
CQSLLCompitiendo.Niveles(0,&CQSLCNivel);
for(lCQSCNivel=CQSLCNivel.first();
    lCQSCNivel;
    lCQSCNivel=CQSLCNivel.next())
{
SiscomEscribeLog3Qt("{%s}{%s}",
		  (*lCQSCNivel->Clase())["Clase"],
		  (*lCQSCNivel->Nivel())["Nivel"]);
		 
}
}
void QResultadosA::EliminaTabWidget()
{
QWidget *lQWGimnastas;
lQWGimnastas=QTWResultados->currentPage();
QTWResultados->removePage(lQWGimnastas);
delete lQWGimnastas;
}
void QResultadosA::MuestraResultados(CQSisLstCompitiendo *pCQSLCompitiendo)
{
QResCompetencia *lQRCompetencia;
lQRCompetencia=new QResCompetencia(pCQSLCompitiendo);
QTWResultados->addTab(lQRCompetencia,"Resultado");
QTWResultados->setCurrentPage(0);
}
void QResultadosA::ResultadosAparato(CQSisAparatoCompetencia *pCQSACompetencia)
{
CQSisLstLstCompitiendo lCQSLLCompitiendo;
CQSLLCompitiendoAparatos.Gimnastas(CQSCNivel,
				   CQSGrupo,
				   pCQSACompetencia,
				   &lCQSLLCompitiendo);
EliminaTabWidget();
MuestraResultados(lCQSLLCompitiendo.first());

}
