#include <QtSisPuntoImpresion.h>
#include <QtSisImprimeFactura.h>
QtSisPuntoImpresion::QtSisPuntoImpresion(QtSisImprimeFactura *pQtSisImpFactura,
					 const char *pchrPtrNombre,
					 const char *pchrPtrDato,
					 int pintXmm,
					 int pintYmm,
					 int pintX1mm,
					 int pintY1mm):
				   QtSisImpFactura(pQtSisImpFactura),
				   intXmm(pintXmm),
				   intYmm(pintYmm),
				   intX1mm(pintX1mm),
				   intY1mm(pintY1mm)
{
  strcpy(chrArrNombre,pchrPtrNombre);
  strcpy(chrArrDato,pchrPtrDato);
  intXpx=pQtSisImpFactura->MMAPixeles(intXmm-12);
  intYpx=pQtSisImpFactura->MMAPixeles(intYmm-12);
  intX1px=pQtSisImpFactura->MMAPixeles(intX1mm);
  intY1px=pQtSisImpFactura->MMAPixeles(intY1mm);
}

int QtSisPuntoImpresion::Xmm()
{
/*
 * Se restan los 12 mm apartir de los cuales la impresora inicia
 * la escritura
 */
  return intXmm;
}
int QtSisPuntoImpresion::Ymm()
{
  return intYmm;
}
int QtSisPuntoImpresion::X1mm()
{
  return intX1mm;
}
int QtSisPuntoImpresion::Y1mm()
{
  return intY1mm;
}
int QtSisPuntoImpresion::Xpx()
{
  return intXpx;
}
int QtSisPuntoImpresion::Ypx()
{
  return intYpx;
}
int QtSisPuntoImpresion::X1px()
{
  return intX1px;
}
int QtSisPuntoImpresion::Y1px()
{
  return intY1px;
}


QtSisPuntosImpresion::QtSisPuntosImpresion()
{


}
