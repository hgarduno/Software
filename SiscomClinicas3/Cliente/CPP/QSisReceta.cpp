#include <QSisReceta.h>
#include <CQSisConsultas.h>
#include <CQSisRecetas.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qmessagebox.h>
QSisReceta::QSisReceta(CQSisReceta *pCQSReceta,
		       QWidget *pQWParent,
		       const char *pchrPtrNombre,
		       WFlags pWFlags):
		  QWidget(pQWParent,pchrPtrNombre,pWFlags),
		  CQSReceta(pCQSReceta)
{
IniciaVariables();
ConectaSlots();
MuestraReceta();
show();
}
QSisReceta::QSisReceta(QWidget *pQWParent,
		       const char *pchrPtrNombre,
		       WFlags pWFlags):
		  QWidget(pQWParent,pchrPtrNombre,pWFlags),
		  CQSReceta(0)
{

IniciaVariables();
ConectaSlots();
MuestraReceta();
show();
}
void QSisReceta::Consulta(CQSisConsulta *pCQSConsulta)
{
	CQSConsulta=pCQSConsulta;
}
void QSisReceta::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QSisReceta::IdWidgetReceta(int pintIdWidgetReceta)
{
	intIdWidgetReceta=pintIdWidgetReceta;
}
void QSisReceta::ConectaSlots()
{
	connect(QLEFolio,
		SIGNAL(textChanged(const QString &)),
		SLOT(SlotCambiaFolio(const QString &)));
	connect(QLEFolio,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoReceta()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(SlotActualiza()));
}
void QSisReceta::SlotActualiza()
{
Actualiza();
}
void QSisReceta::SlotRegistra()
{
if(!QLEFolio->text().isEmpty() &&
   !QTEReceta->text().isEmpty() )
{
Registra();
emit SignalRegistroReceta(this);
}
else
QMessageBox::information(this,
			"Siscom Clinicas3",
			"No se ha capturado el Folio o la receta");
}
void QSisReceta::SlotPasaFocoReceta()
{
	SiscomPasaFocoControl(QTEReceta);
}
void QSisReceta::SlotCambiaFolio(const QString &pQSFolio)
{
	emit SignalCambiaFolio(pQSFolio,intIdWidgetReceta);
}
void QSisReceta::IniciaVariables()
{
	QGLRegilla=new QGridLayout(this,3,1,1,2,"QGLRegilla");
	QSHEFolio=new QSisHEspacio(0,1,1,"QSHEFolio");
	QSHEReceta=new QSisHEspacio(0,1,1,"QSHEReceta");
	QSHEBotones=new QSisHEspacio(0,1,1,"QSHEBotones");

	(*QSHEFolio)+=SiscomCreaEspacioVerticalEtiquetaEdit(
				this,
				"Folio",
				"Folio",
				"QLEFolio",
				&QLEFolio,
				&QLFolio);
	(*QSHEReceta)+=SiscomCreaEspacioVerticalEtiquetaTextEdit(
			this,
			"Receta",
			"Receta",
			"QTEReceta",
			&QTEReceta,
			&QLReceta);
	(*QSHEBotones)+=SiscomCreaEspacioVerticalButton(
			  this,
			  "Registrar",
			  "QPBRegistrar",
			  &QPBRegistrar);
	
	(*QSHEBotones)+=SiscomCreaEspacioVerticalButton(
			  this,
			  "Actualizar",
			  "QPBActualizar",
			  &QPBActualizar);
	QPBRegistrar->setAutoDefault(false);
	QPBActualizar->setAutoDefault(false);
	QGLRegilla->addItem(QSHEFolio,0,0);
	QGLRegilla->addItem(QSHEReceta,1,0);
	QGLRegilla->addItem(QSHEBotones,2,0);
	SiscomPasaFocoControl(QLEFolio);
}
void QSisReceta::MuestraReceta()
{

if(CQSReceta)
{
QLEFolio->setReadOnly(true);
QLEFolio->setText((*CQSReceta)["FolioRegistrado"]);
QTEReceta->setText((*CQSReceta)["Receta"]);
QPBRegistrar->setEnabled(false);
QPBActualizar->setEnabled(true);
}
else
{
QPBRegistrar->setEnabled(true);
QPBActualizar->setEnabled(false);
}

}
CQSisReceta *QSisReceta::Receta()
{
return new CQSisReceta(
		(*CQSConsulta)["IdConsulta"],
		"",
		SiscomObtenInformacionDelEdit(QLEFolio),
		"",
		SiscomObtenInformacionDelEdit(QTEReceta));
}
void QSisReceta::Registra()
{
CQSisOpReceta lCQSOReceta(SisDatCom);
lCQSOReceta.Registra(Receta());
}
void QSisReceta::Actualiza()
{
CQSisOpReceta lCQSOReceta(SisDatCom);
lCQSOReceta.Actualiza(Receta());
}
