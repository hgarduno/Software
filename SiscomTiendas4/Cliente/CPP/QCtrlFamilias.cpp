#include <QCtrlFamilias.h>
#include <CQSisOpTiendas4.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>


QCtrlFamilias::QCtrlFamilias( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlFamilias::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBFamilias=new QComboBox(this);
	QHBLayout->addWidget(QCBFamilias);
	QLEFamilias=SiscomColocaEditAlCombo(QCBFamilias,"QLEFamilias");
	QCBFamilias->setAutoCompletion(true);
	QCBFamilias->setDuplicatesEnabled(false);
	QCBFamilias->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlFamilias::MuestraFamilias()
{
CQSisFamilia *lCQSFamilia;
for(lCQSFamilia=CQSLFamilias.first();
    lCQSFamilia;
    lCQSFamilia=CQSLFamilias.next())
  QCBFamilias->insertItem(lCQSFamilia->SRegistrosPro2["Dsc"]);
}
void QCtrlFamilias::IniciaControl()
{
	ConsultaFamilias();
	MuestraFamilias();
}
void QCtrlFamilias::ConsultaFamilias()
{
CQSisOpTiendas4 lCQSOT4Familias(SisDatCom);
	lCQSOT4Familias.Familias(&CQSLFamilias);
	QCBFamilias->clear();
}
void QCtrlFamilias::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlFamilias::PonFamiliaActual(CQSisFamilia *pCQSFamilia)
{
	QCBFamilias->setCurrentText(pCQSFamilia->SRegistrosPro2["Familia"]);
	SiscomPasaFocoControl(QLEFamilias);
}
void QCtrlFamilias::ConectaSlots()
{
	connect(QCBFamilias,
		SIGNAL(activated(int)),
		SLOT(SlotFamilia(int)));
	connect(QCBFamilias,
		SIGNAL(textChanged(const QString &)),
		SLOT(SlotCambiandoFamilia(const QString &)));
}
void QCtrlFamilias::SlotCambiandoFamilia(const QString &)
{
	emit SignalCambiandoFamilia();
}
void QCtrlFamilias::SlotFamilia(int pintNFamilia)
{
	emit SignalFamilia(CQSLFamilias.at(pintNFamilia));
}
void QCtrlFamilias::setFocus()
{
	SiscomPasaFocoControl(QLEFamilias);	
}

void QCtrlFamilias::Limpia()
{
}






