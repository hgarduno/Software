#include <IMP_ActualizaPantalla.h>
#include <CQSiscomCom.h>
#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qfiledialog.h>
CQSisActualizaPantalla::CQSisActualizaPantalla(CSISCOMDatComunicaciones *pCSisDatCom,
					       QWidget* parent,
					       const char* name,
					       WFlags fl )
    : ActualizaPantalla( parent, name, fl ),
	CSisDatCom(pCSisDatCom)
{
	ConectaSlots();
}

CQSisActualizaPantalla::~CQSisActualizaPantalla()
{
}
void CQSisActualizaPantalla::ConectaSlots()
{
	connect(QPBSArchivo,
		SIGNAL(clicked()),
		SLOT(S_SeleccionaArchivo()));
}
void CQSisActualizaPantalla::PonDirectorioQT(QString pQSDirectorio)
{
	QSDirectorioQT=pQSDirectorio;
}
void CQSisActualizaPantalla::PonNombreAplicacion(QString pQSNmbAplicacion)
{
	QLENmbAplicacion->setText(pQSNmbAplicacion);
}
void CQSisActualizaPantalla::PonIdAplicacion(QString pQSIdAplicacion)
{
	QSIdAplicacion=pQSIdAplicacion;
}
void CQSisActualizaPantalla::S_SeleccionaArchivo()
{
QString lQSArchivoUI;
	lQSArchivoUI=QFileDialog::getOpenFileName(QSDirectorioQT,
						 "*.ui",
						 this,
						 "Actualiza Pantalla",
						 "Selecciona Un Archivo");
	QLEArchivoUI->setText(lQSArchivoUI);
QSiscomArchivoUI lQSisArchivoUI(lQSArchivoUI);	
	  QLEClase->setText(lQSisArchivoUI.ObtenClase());
	  QLEPantalla->setText(lQSisArchivoUI.ObtenNmbForma());
	  QPLObjetos=lQSisArchivoUI.ObtenControlesArchivo();

	QSiscomArchivoUI::ImprimeObjetos(QPLObjetos,"Objetos");
}
