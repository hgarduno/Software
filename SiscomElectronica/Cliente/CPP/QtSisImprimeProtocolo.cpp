#include <QtSisImprimeProtocolo.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
QtSisImprimeProtocolo::QtSisImprimeProtocolo(
		SiscomRegistro3Lst *pSisReg3LstDato,
		QWidget *pQWParent,
		const char *pchrPtrName):
		QtSisImprime(pQWParent,pchrPtrName)
{
SiscomEscribeLog3Qt("");
viewport()->setBackgroundMode( PaletteBase );
setVScrollBarMode(QScrollView::AlwaysOn);
show();
/*
DibujaHoja(1);
DibujaHoja(2);
DibujaHoja(3);
DibujaHoja(4);
DibujaHoja(5);
*/
}
