#include <IMP_Competencia.h>
#include <IMP_SelGimnasio.h>
#include<SISCOMComunicaciones++.h>
#include <IMP_QControlFecha.h>
#include <QCtrlTipoCompetencia.h>
#include <QSisSepomex.h>
#include <CQSisGimnasios.h>
#include <CQSisCompetencias.h>
#include <CQSisTipoCompetencia.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qbuttongroup.h>

QCompetencia *InstanciaCompetencia(void *pSisDatCom,
                 void *pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCompetencia((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCompetencia::QCompetencia(SiscomDatCom *pSisDatCom, 
			            void *pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Competencia(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QCompetencia::~QCompetencia()
{

}

void QCompetencia::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoFecha()));
	connect(QCtrFecha,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoFechaInicio()));
	connect(QCtrFechaIni,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoFechaFin()));
	connect(QCtrFechaFin,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoTipoCompetencia()));	
	connect(QBGOrganizador,
		SIGNAL(clicked(int)),
		SLOT(SlotOrganizador(int)));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
	connect(QCtrTCompetencia,
		SIGNAL(SignalTipoCompetencia(CQSisTipoCompetencia *)),
		SLOT(SlotTipoCompetencia(CQSisTipoCompetencia *)));
		

}
void QCompetencia::SlotTipoCompetencia(CQSisTipoCompetencia *pCQSTCompetencia)
{
	CQSTCompetencia=pCQSTCompetencia;
	SiscomPasaFocoControl(QBGOrganizador);

}
void QCompetencia::SlotPasaFocoTipoCompetencia()
{
	QCtrTCompetencia->PonServidor(SisDatCom);
	QCtrTCompetencia->IniciaControl();
	QCtrTCompetencia->setFocus();
}
void QCompetencia::SlotPasaFocoFecha()
{
	QCtrFecha->setFocus();
}
void QCompetencia::FormaCompetencia(CQSisCompetencia **pCQSCompetencia)
{
   *pCQSCompetencia=new CQSisCompetencia(
   			SiscomObtenInformacionDelEdit(QLENombre),
			(const char *)QCtrFecha->ObtenFecha(),
			"",
			CQSTCompetencia->SRegistrosPro2["IdTipoCompetencia"]);
  (*pCQSCompetencia)->PonFechaIniInscripcion(
  			(const char *)QCtrFechaIni->ObtenFecha());
  (*pCQSCompetencia)->PonFechaFinInscripcion(
  			(const char *)QCtrFechaFin->ObtenFecha());
  (*pCQSCompetencia)->PonDescripcion(
  			 SiscomObtenInformacionDelEdit(QTEDescripcion));
  (*pCQSCompetencia)->PonBases(
  			 SiscomObtenInformacionDelEdit(QTEBases));
}
void QCompetencia::SlotRegistrar()
{
CQSisCompetencia *lCQSCompetencia;
SiscomRegistrosPro2 *lSRegistrosPro2;
	FormaCompetencia(&lCQSCompetencia);
CQSisOpCompetencia lCQSOpCompetencia(SisDatCom);

		lCQSOpCompetencia.InsertaCompetencia(lCQSCompetencia,
						   &lSRegistrosPro2);

}
void QCompetencia::SlotOrganizador(int pintOrganizador)
{
	(this->*Organizadores[pintOrganizador])();	
}
void QCompetencia::SlotPasaFocoDescripcion()
{
	SiscomPasaFocoControl(QTEDescripcion);
}
void QCompetencia::SlotPasaFocoFechaInicio()
{
	SiscomPasaFocoControl(QCtrFechaIni);
}
void QCompetencia::SlotPasaFocoFechaFin()
{
	SiscomPasaFocoControl(QCtrFechaFin);
}
void QCompetencia::SlotPasaFocoOrganizador()
{
	SiscomPasaFocoControl(QRBGimnasios);
}
void QCompetencia::IniciaVariables()
{
	SiscomPasaFocoControl(QLENombre);
	if(SisDatCom)
	{
	  QSSepomex->PonServidor(SisDatCom);
	  QSSepomex->IniciaControl();
	}
	QCtrFecha->ColocaFechaHoy();
	QCtrFechaIni->ColocaFechaHoy();
	QCtrFechaFin->ColocaFechaHoy();
	Organizadores[0]=&QCompetencia::OrganizadoresGimnasios;
	Organizadores[1]=&QCompetencia::OrganizadoresParticular;
}
void QCompetencia::OrganizadoresGimnasios()
{
QSelGimnasio lQSGimnasio(SisDatCom);
	if((CQSGimnasio=lQSGimnasio.ObtenGimnasio()))
	{
	  QLEOrganizador->setText(CQSGimnasio->SRegistrosPro2["Gimnasio"]);
	  QSSepomex->setFocus();
	}
}
void QCompetencia::OrganizadoresParticular()
{
printf("Particular \n");
}
