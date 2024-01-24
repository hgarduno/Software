#include <QtSisImprimeFacturaFecha.h>
#include <QtSisPuntoImpresion.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpainter.h>
QtSisImprimeFacturaFecha::QtSisImprimeFacturaFecha(QtSisImprimeFactura *pQtSisImpFactura):
	QtSisImpFactura(pQtSisImpFactura)
{
ObtenFechaHoy();
}
void QtSisImprimeFacturaFecha::DibujaDia(int pintXmm,
					 int pintYmm,
					 int pintX1mm,
					 int pintY1mm,
					 QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "FechaDia",
				     chrArrDia,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		       lQtSisPtoImp->Ypx(),
		       chrArrDia);
}


void QtSisImprimeFacturaFecha::DibujaMes(int pintXmm,
					 int pintYmm,
					 int pintX1mm,
					 int pintY1mm,
					 QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "FechaMes",
				     chrArrMes,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		       lQtSisPtoImp->Ypx(),
		       chrArrMes);

}
void QtSisImprimeFacturaFecha::DibujaA_o(int pintXmm,
					 int pintYmm,
					 int pintX1mm,
					 int pintY1mm,
					 QPainter *pQPDibuja)
{

QtSisPuntoImpresion *lQtSisPtoImp;
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "FechaA_o",
				     chrArrA_o,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		       lQtSisPtoImp->Ypx(),
		       chrArrA_o);
}
void QtSisImprimeFacturaFecha::ObtenFechaHoy()
{
SiscomDesarrollo3Qt::FechaHoy(chrArrDia,
			      chrArrMes,
			      chrArrA_o);
}
