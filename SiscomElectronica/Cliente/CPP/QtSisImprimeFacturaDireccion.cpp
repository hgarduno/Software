#include <QtSisImprimeFacturaDireccion.h>

QtSisImprimeFacturaDireccion::QtSisImprimeFacturaDireccion(QtSisImprimeFactura *pQtSisImpFactura):
 QtSisImpFactura(pQtSisImpFactura)
{


}




void QtSisImprimeFacturaDireccion::PuntoInicio(int pintXmm,
					     int pintYmm)
{
intXmm=pintXmm;
intYmm=pintYmm;
intXpx=QtSisImpFactura->MMAPixeles(intXmm);
intYpx=QtSisImpFactura->MMAPixeles(intYmm);
}
void QtSisImprimeFacturaDireccion::PuntoFin(int pintX1mm,
					  int pintY1mm)
{
intX1mm=pintX1mm;
intY1mm=pintY1mm;
intX1px=QtSisImpFactura->MMAPixeles(pintX1mm);
intY1px=QtSisImpFactura->MMAPixeles(pintY1mm);
}
