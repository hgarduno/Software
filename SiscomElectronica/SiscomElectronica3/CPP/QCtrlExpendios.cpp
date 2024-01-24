#include <QCtrlExpendios.h>


#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <SiscomParametroConsulta3.h>
#include <SiscomDatCom.h>
#include <qlayout.h>
#include <qiconview.h>

QCtrlExpendios::QCtrlExpendios(
				QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
gPtrFleArchivoLog3Qt=stdout;
IniciaVariables();
ConectaSlots();

}
void QCtrlExpendios::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QIVExpendios=new QIconView(this);
QHBLayout->addWidget(QIVExpendios);
}
void QCtrlExpendios::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlExpendios::Expendio(const char *pchrPtrIdExpendio)
{
	chrPtrIdExpendio=pchrPtrIdExpendio;
}
void QCtrlExpendios::IniciaControl()
{
	ConsultaExpendios();
	MuestraExpendios();
}
void QCtrlExpendios::ConectaSlots()
{
connect(QIVExpendios,
	SIGNAL(clicked(QIconViewItem *)),
	SLOT(SlotExpendio(QIconViewItem *)));
}

void QCtrlExpendios::SlotExpendio(QIconViewItem *pQIVIExpendio)
{
if(pQIVIExpendio)
{
QIconViewItemExpendio *lQIVIExpendio=(QIconViewItemExpendio *)pQIVIExpendio;
emit SignalExpendio(lQIVIExpendio->Expendio());
}
}
void QCtrlExpendios::ConsultaExpendios()
{

SiscomOperaciones3 lSOp3Expendios(SisDatCom);
SReg3LstExpendios.clear();
QIVExpendios->clear();
lSOp3Expendios.SiscomEnvia("ConsultasSiscomElectronica2",
			   &SReg3LstExpendios,
			   "%s%s",
			   "ExpendiosSiscom",
			   chrPtrIdExpendio);
}
void QCtrlExpendios::MuestraExpendios()
{
SiscomRegistro3 *lSReg3Expendio;
QIconViewItemExpendio *lQIVIExpendio;
for(lSReg3Expendio=SReg3LstExpendios.first();
    lSReg3Expendio;
    lSReg3Expendio=SReg3LstExpendios.next())
{
   lQIVIExpendio=new QIconViewItemExpendio(lSReg3Expendio,QIVExpendios);
   QIVExpendios->insertItem(lQIVIExpendio);
}
}

void QCtrlExpendios::setFocus()
{
 QIconViewItem *lQIVIExpendio=QIVExpendios->firstItem();
 QIVExpendios->setSelected(lQIVIExpendio,true);
}
QIconViewItemExpendio::QIconViewItemExpendio(SiscomRegistro3 *pSReg3Expendio,
					     QIconView *pQIVControl):
			QIconViewItem(pQIVControl),
			SReg3Expendio(pSReg3Expendio)
{
	setText(QString((*SReg3Expendio)["razonsocial"]));
}
SiscomRegistro3 *QIconViewItemExpendio::Expendio()
{
	return SReg3Expendio;
}
