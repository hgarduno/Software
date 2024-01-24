#include <QCtrlExpendiosSE.h>

#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>

QCtrlExpendiosSE::QCtrlExpendiosSE(
				QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlExpendiosSE::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QIVExpendios=new QIconView(this);
QHBLayout->addWidget(QIVExpendios);
}
void QCtrlExpendiosSE::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
}
void QCtrlExpendiosSE::Expendio(const char *pchrPtrIdExpendio)
{
	chrPtrIdExpendio=pchrPtrIdExpendio;
}
void QCtrlExpendiosSE::IniciaControl()
{
	ConsultaExpendios();
	MuestraExpendios();
}
void QCtrlExpendiosSE::ConectaSlots()
{
connect(QIVExpendios,
	SIGNAL(clicked(QIconViewItem *)),
	SLOT(SlotExpendio(QIconViewItem *)));
}

void QCtrlExpendiosSE::SlotExpendio(QIconViewItem *pQIVIExpendio)
{
if(pQIVIExpendio)
{
QIconViewItemExpendioSE *lQIVIExpendio=(QIconViewItemExpendioSE *)pQIVIExpendio;
emit SignalExpendio(lQIVIExpendio->Expendio());
}
}
void QCtrlExpendiosSE::ConsultaExpendios()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ExpendiosSiscom");
lzSisElectronica.Expendios(&zExpsSiscom);
}
void QCtrlExpendiosSE::MuestraExpendios()
{
/*
SiscomRegistro3 *lSReg3Expendio;
QIconViewItemExpendio *lQIVIExpendio;
for(lSReg3Expendio=SReg3LstExpendios.first();
    lSReg3Expendio;
    lSReg3Expendio=SReg3LstExpendios.next())
{
   lQIVIExpendio=new QIconViewItemExpendio(lSReg3Expendio,QIVExpendios);
   QIVExpendios->insertItem(lQIVIExpendio);
}
*/
}

void QCtrlExpendiosSE::setFocus()
{
 QIconViewItem *lQIVIExpendio=QIVExpendios->firstItem();
 QIVExpendios->setSelected(lQIVIExpendio,true);
}
QIconViewItemExpendioSE::QIconViewItemExpendioSE(zExpendio *pzExpendio,
					     QIconView *pQIVControl):
			QIconViewItem(pQIVControl),
			zExpSiscom(pzExpendio)
{
	/*
	setText(QString((*SReg3Expendio)["razonsocial"]));
	*/
}
zExpendio *QIconViewItemExpendioSE::Expendio()
{
	return zExpSiscom;
}
