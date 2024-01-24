#include <QOperacionesGenerales.h>
#include <QRotaciones.h>
#include <CQSisCompetencias.h>
#include <qlayout.h>
#include <qtoolbox.h>
#include <qdockwindow.h>

#include <SISCOMComunicaciones++.h>
#include <SISCOMVentanaPrincipal3.h>

QOperacionesGenerales *InstanciaOperacionesGenerales(
				void *pSisDatCom,
				char **pchrPtrArgumentos,
				void *pQWParent,
				const char *pchrPtrName,
				int pintWFlags)
{
return new QOperacionesGenerales((SiscomDatCom *)pSisDatCom,
				 pchrPtrArgumentos,
				 (QWidget *)pQWParent,
				 pchrPtrName,
				 pintWFlags);
}
QOperacionesGenerales::QOperacionesGenerales(SiscomDatCom *pSisDatCom,
					     char **pchrPtrArgumentos,
						QWidget *pQWParent,
					     const char *pchrPtrName,
					     WFlags pWFlags):
				QWidget(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaInterfaz();
IniciaVariables();
CreaAreaVentana();
}

void QOperacionesGenerales::IniciaInterfaz()
{
QVBoxLayout *lQVBox;
lQVBox=new QVBoxLayout(this);
lQVBox->setMargin(0);
QTBOperaciones=new QToolBox(this,"QTBOperaciones");
QORotaciones=new QRotaciones(SisDatCom,
			      this,
			     "QORotaciones");
QORotaciones->setEnabled(chrPtrArgumentos[97][0]=='1');
lQVBox->addWidget(QTBOperaciones);
QTBOperaciones->addItem(QORotaciones,"Rotaciones");
}
void QOperacionesGenerales::CreaAreaVentana()
{

	QDockWindow *dw=new QDockWindow( QDockWindow::InDock,this);
	dw->setResizeEnabled( TRUE );
	dw->setVerticalStretchable( TRUE );
	QSisVentanaP->addDockWindow( dw, DockLeft );
	dw->setCloseMode( QDockWindow::Always );
	QPoint lQPDonde(10,10);
	reparent(dw,lQPDonde);
	dw->setWidget(this);
	dw->setCaption("Operaciones Generales");

}
void QOperacionesGenerales::IniciaVariables()
{
 chrPtrArgumentos[29]=(char *)this;
 QSisVentanaP=(SISCOMVentanaPrincipal *)chrPtrArgumentos[25];
 QSisVentanaP->ActualizaParametro(chrPtrArgumentos[29],29);
}
void QOperacionesGenerales::Competencia(CQSisCompetencia *pCQSCompetencia)
{
	QORotaciones->Competencia(pCQSCompetencia);
}
