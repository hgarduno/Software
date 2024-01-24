#include <QCtrlBodegas4.h>

#include <SiscomDesarrollo3Qt++.h>

#include <zSiscomElectronica.h>
#include <zBodega.h>
#include <zExpendio.h>
#include <zBodegas.h>

#include <zSiscomDesarrollo4.h>
#include <SiscomDatCom.h>
#include <qlayout.h>
#include <qiconview.h>

QCtrlBodegas4::QCtrlBodegas4(QWidget *pQWParent,
			const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
gPtrFleArchivoLog3Qt=stdout;
IniciaVariables();
ConectaSlots();
}
void QCtrlBodegas4::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QIVBodegas=new QIconView(this);
QHBLayout->addWidget(QIVBodegas);
}
void QCtrlBodegas4::Servidor(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QCtrlBodegas4::IniciaControl()
{
	ConsultaBodegas();
	MuestraBodegas();
}
void QCtrlBodegas4::ConectaSlots()
{
connect(QIVBodegas,
	SIGNAL(clicked(QIconViewItem *)),
	SLOT(SlotBodega(QIconViewItem *)));
}

void QCtrlBodegas4::SlotBodega(QIconViewItem *pQIVIBodega)
{
QIconViewItemBodega4 *lQIVIBodega=(QIconViewItemBodega4 *)pQIVIBodega;
if(lQIVIBodega)
emit SignalBodega(lQIVIBodega->Bodega());
}
void QCtrlBodegas4::ConsultaBodegas()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"BodegasExpendios");
lzSisElectronica.BodegasExpendios(&zBodegasE);
}
void QCtrlBodegas4::MuestraBodegas()
{
QIconViewItemBodega4 *lQIVIBodega;
zBodega *lzBodega;
for(lzBodega=(zBodega *)zBodegasE->Primer();
    lzBodega;
    lzBodega=(zBodega *)zBodegasE->Siguiente())
{
   lQIVIBodega=new QIconViewItemBodega4(lzBodega,QIVBodegas);
   QIVBodegas->insertItem(lQIVIBodega);
}
}
QIconViewItemBodega4::QIconViewItemBodega4(zBodega *pzBodega,QIconView *pQIVControl):
			QIconViewItem(pQIVControl),
			zBodegaE(pzBodega)
{
QString lQStrTexto(QString(zBodegaE->Bodega()) 		+
                    "\n\n" 				+
		   zBodegaE->Expendio()->RazonSocial());
	setText(lQStrTexto);
}
zBodega *QIconViewItemBodega4::Bodega()
{
	return zBodegaE;
}

