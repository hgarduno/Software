#include <QCtrlBodegas.h>


#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <SiscomParametroConsulta3.h>
#include <SiscomDatCom.h>
#include <qlayout.h>
#include <qiconview.h>

QCtrlBodegas::QCtrlBodegas(
				QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
gPtrFleArchivoLog3Qt=stdout;
IniciaVariables();
ConectaSlots();

}
void QCtrlBodegas::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QIVBodegas=new QIconView(this);
QHBLayout->addWidget(QIVBodegas);
}
void QCtrlBodegas::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlBodegas::Expendio(const char *pchrPtrIdExpendio)
{
	chrPtrIdExpendio=pchrPtrIdExpendio;
}
void QCtrlBodegas::IniciaControl()
{
	ConsultaBodegas();
	MuestraBodegas();
}
void QCtrlBodegas::ConectaSlots()
{
connect(QIVBodegas,
	SIGNAL(clicked(QIconViewItem *)),
	SLOT(SlotBodega(QIconViewItem *)));
}

void QCtrlBodegas::SlotBodega(QIconViewItem *pQIVIBodega)
{
QIconViewItemBodega *lQIVIBodega=(QIconViewItemBodega *)pQIVIBodega;
if(lQIVIBodega)
emit SignalBodega(lQIVIBodega->Bodega());
}
void QCtrlBodegas::ConsultaBodegas()
{
SiscomOperaciones3 lSOp3Bodegas(SisDatCom);
lSOp3Bodegas.SiscomEnvia("ConsultasSiscomElectronica2",
			   &SReg3LstBodegas,
			   "%s%s",
			   "BodegasExpendio",
			   chrPtrIdExpendio);
}
void QCtrlBodegas::MuestraBodegas()
{
SiscomRegistro3 *lSReg3Bodega;
QIconViewItemBodega *lQIVIBodega;
for(lSReg3Bodega=SReg3LstBodegas.first();
    lSReg3Bodega;
    lSReg3Bodega=SReg3LstBodegas.next())
{
   lQIVIBodega=new QIconViewItemBodega(lSReg3Bodega,QIVBodegas);
   QIVBodegas->insertItem(lQIVIBodega);
}
}


QIconViewItemBodega::QIconViewItemBodega(SiscomRegistro3 *pSReg3Bodega,
					     QIconView *pQIVControl):
			QIconViewItem(pQIVControl),
			SReg3Bodega(pSReg3Bodega)
{
	setText(QString((*SReg3Bodega)["bodega"]));
}
SiscomRegistro3 *QIconViewItemBodega::Bodega()
{
	return SReg3Bodega;
}
