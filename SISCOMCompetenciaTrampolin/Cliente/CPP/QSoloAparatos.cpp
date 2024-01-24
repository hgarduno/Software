#include <QSoloAparatos.h>
#include <QCtrlAparatoCompetencia.h>
#include <CQSisAparatoCompetencia.h>
#include <SISCOMComunicaciones++.h>
#include <SISCOMVentanaPrincipal3.h>
#include <IMP_Rondas.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qdockwindow.h>

QSoloAparatos *InstanciaSoloAparatos(void *pSisDatCom,
				     char **pchrPtrArgumentos,
				     void *pQWParent,
				     const char *pchrPtrName,
				     int pintWFlags)
{
 return new QSoloAparatos((SiscomDatCom *)pSisDatCom,
 			  pchrPtrArgumentos,
			  (QWidget *)pQWParent,
			  pchrPtrName,
			  pintWFlags);

}

QSoloAparatos::QSoloAparatos(SiscomDatCom *pSisDatCom,
			     char **pchrPtrArgumentos,
			     QWidget *pQWParent,
			     const char *pchrPtrName,
			     WFlags piWFlags):
			  QWidget(pQWParent,pchrPtrName,piWFlags),
			  chrPtrArgumentos(pchrPtrArgumentos),
			  SisDatCom(pSisDatCom)
{

IniciaInterfaz();
IniciaVariables();
CreaAreaVentana();
ConectaSlots();
}
void QSoloAparatos::IniciaInterfaz()
{
QVBoxLayout *lQVBox;

lQVBox=new QVBoxLayout(this);
QLAparatos=new QLabel("Aparatos",this,"QLAparatos");
QCtrACompetencia=new QCtrlAparatoCompetencia(this,"QCtrACompetenciaS");
lQVBox->addWidget(QLAparatos);
lQVBox->addWidget(QCtrACompetencia);

}
void QSoloAparatos::IniciaVariables()
{
 chrPtrArgumentos[27]=(char *)this;
 QSisVentanaP=(SISCOMVentanaPrincipal *)chrPtrArgumentos[25];
 QSisVentanaP->ActualizaParametro(chrPtrArgumentos[27],27);

 
}
void QSoloAparatos::CreaAreaVentana()
{
	QDockWindow *dw=new QDockWindow( QDockWindow::InDock,this);
	dw->setResizeEnabled( TRUE );
	dw->setVerticalStretchable( TRUE );
	QSisVentanaP->addDockWindow( dw, DockLeft );
	/*
	QVPrincipal->setDockEnabled( dw, DockTop, FALSE );
	QVPrincipal->setDockEnabled( dw, DockBottom, FALSE );
	*/
	dw->setCloseMode( QDockWindow::Always );
	QPoint lQPDonde(10,10);
	reparent(dw,lQPDonde);
	dw->setWidget(this);
	dw->setCaption("Aparatos");

}
void QSoloAparatos::Aparatos()
{
QSCompetencia=(CQSisCompetencia *)chrPtrArgumentos[26];
QCtrACompetencia->PonServidor(SisDatCom);
QCtrACompetencia->PonCompetencia(QSCompetencia);
QCtrACompetencia->IniciaControl();
QCtrACompetencia->setEnabled(chrPtrArgumentos[97][0]=='1');
}

void QSoloAparatos::ConectaSlots()
{
connect(QCtrACompetencia,
	SIGNAL(SignalAparatoCompetencia(CQSisAparatoCompetencia *)),
	SLOT(SlotAparatoCompetencia(CQSisAparatoCompetencia *)));
}
void QSoloAparatos::SlotAparatoCompetencia(CQSisAparatoCompetencia *pCQSACompetencia)
{

	if(chrPtrArgumentos[28])
	{
	 QRondas *lQRondas=(QRondas *)chrPtrArgumentos[28];
	 lQRondas->AparatoCompetencia(pCQSACompetencia);
	}

}
const CQSisLstAparatoCompetencia &QSoloAparatos::AparatosCompetencia()
{
  return QCtrACompetencia->ObtenAparatos();
}
