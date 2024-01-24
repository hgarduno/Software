#include <IMP_SelIconos.h>

#include <SISCOMComunicaciones++.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qiconview.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qfiledialog.h>

CQSisSelIconos::CQSisSelIconos( QWidget* parent, const char* name, bool modal, WFlags fl )
    : SelIconos( parent, name, modal, fl )
{
	ConectaSlots();
	exec();
}

CQSisSelIconos::~CQSisSelIconos()
{
}
void CQSisSelIconos::ConectaSlots()
{
	connect(QPBSelDirectorio,
		SIGNAL(clicked()),
		SLOT(SlotSeleccionaDirectorio()));
	connect(QIVArchivos,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(SlotSeleccionaIcono(QIconViewItem *)));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
}
void CQSisSelIconos::SlotAceptar()
{
	Boton=BTN_Aceptar;
	done(0);
}
void CQSisSelIconos::SlotSeleccionaIcono(QIconViewItem *pQIVIDatos)
{
	QPIcono->setPixmap(QPixmap(QPBSelDirectorio->text() +
				   "/" +
				   pQIVIDatos->text()));
	QLEArchivo->setText(pQIVIDatos->text());
}
void CQSisSelIconos::SlotSeleccionaDirectorio()
{
QString lQSDirectorio;
QStringList lQSLArchivos;
	 SeleccionaDirectorio(lQSDirectorio);
	 CargaArchivos(lQSDirectorio,lQSLArchivos);
	 MuestraIconos(lQSDirectorio,lQSLArchivos);	
	 QPBSelDirectorio->setText(lQSDirectorio);
		       


}
void CQSisSelIconos::MuestraIconos(QString pQSDirectorio,
				   QStringList pQSLArchivos)
{
int lintContador;
	for(lintContador=0;lintContador<pQSLArchivos.size();lintContador++)
	new QIconViewItem(QIVArchivos,
			  pQSLArchivos[lintContador],
		          QPixmap(pQSDirectorio + 
				  "/"		+
				  pQSLArchivos[lintContador]));
}
void CQSisSelIconos::SeleccionaDirectorio(QString &pQSDirectorio)
{
QFileDialog *lQFDSelDirT=new QFileDialog(0,0,0);
            lQFDSelDirT->setMode(QFileDialog::Directory);
            lQFDSelDirT->exec();
            pQSDirectorio=lQFDSelDirT->selectedFile();    
 
}
void CQSisSelIconos::CargaArchivos(QString pQSDirectorio,
				   QStringList &pQSLArchivos)
{
QDir lQDirectorio(pQSDirectorio);
	pQSLArchivos=lQDirectorio.entryList("*.png");


}
CQSisSelIconos::BTN_SelIconos CQSisSelIconos::ObtenLaSeleccion()
{
	return Boton;
}
QString CQSisSelIconos::ObtenArchivo()
{
	return QLEArchivo->text();
}
