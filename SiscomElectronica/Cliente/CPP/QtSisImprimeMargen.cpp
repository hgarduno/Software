#include <QtSisImprimeMargen.h>
#include <qpaintdevicemetrics.h>
QtSisImprimeMargen::QtSisImprimeMargen(QPaintDeviceMetrics *pQPDMMedidas):
				QPDMMedidas(pQPDMMedidas)
{

}
void QtSisImprimeMargen::X(int pintX)
{
	intXmm=pintX;
}
void QtSisImprimeMargen::Y(int pintY)
{
	intYmm=pintY;
}
int QtSisImprimeMargen::Xmm()
{
	return intXmm;
}
int QtSisImprimeMargen::Ymm()
{
	return intYmm;
}
int QtSisImprimeMargen::Xpx()
{
	return MMAPixeles(intXmm);
}
int QtSisImprimeMargen::Ypx()
{
	return MMAPixeles(intYmm);
}
int QtSisImprimeMargen::PixelesAMM(int pintPixeles)
{
	return pintPixeles/MMAPixeles(pintPixeles);
}
int QtSisImprimeMargen::MMAPixeles(int pintMilimetros)
{
return (int )((pintMilimetros/25.4)*QPDMMedidas->logicalDpiX());
}
