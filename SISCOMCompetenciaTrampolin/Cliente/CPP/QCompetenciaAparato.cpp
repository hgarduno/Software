#include <IMP_Rondas.h>
#include <QCompetenciaAparato.h>
#include <SISCOMComunicaciones++.h>
#include <qlabel.h>
#include <QCtrlAparatoCompetencia.h>
#include <QCtrlCompetencias.h>
#include <CQSisCompetencias.h>
#include <qlayout.h>
#include <qmainwindow.h>
#include <SISCOMVentanaPrincipal3.h>
#include <QSoloAparatos.h>
#include <QOperacionesGenerales.h>


QCompetenciasAparatos *InstanciaCompetenciasAparatos(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCompetenciasAparatos((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCompetenciasAparatos::QCompetenciasAparatos(SiscomDatCom *pSisDatCom,
					     char **pchrPtrArgumentos,
					     QWidget *pQWParent,
					     const char *pchrPtrNombre,
					     WFlags pWFlags):
				QWidget(pQWParent,pchrPtrNombre,pWFlags),
				QWParent(pQWParent),
				chrPtrArgumentos(pchrPtrArgumentos),
				SisDatCom(pSisDatCom)
{
IniciaInterfaz();
ColocaArea();
IniciaVariables();
ConectaSlots();
}
void QCompetenciasAparatos::ConectaSlots()
{
	connect(QCtrCompetencias,
		SIGNAL(SignalCompetencia(CQSisCompetencia *)),
		SLOT(SlotCompetencia(CQSisCompetencia *)));
}
void QCompetenciasAparatos::SlotCompetencia(CQSisCompetencia *pCQSCompetencia)
{
    CQSCompetencia=pCQSCompetencia;
    chrPtrArgumentos[26]=(char *)CQSCompetencia;
    AsignaCompetencia();
    IniciaAparatos();
    /*
    MuestraAparatos();
    CargaInterfazRondas();

    */

}
void QCompetenciasAparatos::MuestraAparatos()
{
	QCtrACompetencia->PonServidor(SisDatCom);
	QCtrACompetencia->PonCompetencia(CQSCompetencia);
	QCtrACompetencia->IniciaControl();
}
void QCompetenciasAparatos::IniciaInterfaz()
{
QVBoxLayout *lQVBox;

lQVBox=new QVBoxLayout(this);
lQVBox->setMargin(0);
QLCompetencias=new QLabel("Competencias",this,"QLCompetencias");
QCtrCompetencias=new QCtrlCompetencias(this,"QCtrCompetencias");
lQVBox->addWidget(QLCompetencias);
lQVBox->addWidget(QCtrCompetencias);
QVPrincipal=(SISCOMVentanaPrincipal *)chrPtrArgumentos[25];
}
void QCompetenciasAparatos::IniciaVariables()
{
QCtrCompetencias->PonServidor(SisDatCom);
QCtrCompetencias->IniciaControl();
}
void QCompetenciasAparatos::ColocaArea()
{

	QDockWindow *dw=new QDockWindow( QDockWindow::InDock,this);

	dw->setResizeEnabled( TRUE );
	dw->setVerticalStretchable( TRUE );
	QVPrincipal->addDockWindow( dw, DockLeft );
	/*
	QVPrincipal->setDockEnabled( dw, DockTop, FALSE );
	QVPrincipal->setDockEnabled( dw, DockBottom, FALSE );
	*/
	dw->setCloseMode( QDockWindow::Always );
	QPoint lQPDonde(90,10);
	reparent(dw,lQPDonde);
	dw->setWidget(this);
	dw->setCaption("Competencias Registradas");

}
void QCompetenciasAparatos::AsignaCompetencia()
{
QOperacionesGenerales *lQOGenerales=(QOperacionesGenerales *)chrPtrArgumentos[29];
  QVPrincipal->ActualizaParametro(chrPtrArgumentos[26],26); 
  lQOGenerales->Competencia(CQSCompetencia);

}
void QCompetenciasAparatos::IniciaAparatos()
{
QSoloAparatos *lQSAparatos=(QSoloAparatos *)chrPtrArgumentos[27];
lQSAparatos->Aparatos();
}
