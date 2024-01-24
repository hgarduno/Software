#include <QtSisImprimeHoja.h>
#include <QtSisImprimeMargen.h>
#include <QtSisImprimeEncabezados.h>

#include <SiscomDesarrollo3Qt++.h>
#include <qpaintdevicemetrics.h>
QtSisImprimeHoja::QtSisImprimeHoja(QPaintDeviceMetrics *pQPDMMedidas):
			QPDMMedidas(pQPDMMedidas)
{

}
void QtSisImprimeHoja::Encabezados(QtSisImprimeEncabezados *pQtSisImpEncabezados)
{
	QtSisImpEncabezados=pQtSisImpEncabezados;
}
void QtSisImprimeHoja::MargenSuperior(QtSisImprimeMargen *pQtSisImpMargSup)
{
	QtSisImpMarSup=pQtSisImpMargSup;
}
void QtSisImprimeHoja::MargenInferior(QtSisImprimeMargen *pQtSisImpMarInf)
{
	QtSisImpMarInf=pQtSisImpMarInf;
}
void QtSisImprimeHoja::mmAncho(int pintAncho)
{
	intAnchoMM=pintAncho;
}
void QtSisImprimeHoja::mmAlto(int pintAlto)
{
	intAltoMM=pintAlto;
}
int QtSisImprimeHoja::mmAlto()
{
	return intAltoMM;
}

int QtSisImprimeHoja::mmAncho()
{
	return intAnchoMM;
}
int QtSisImprimeHoja::pxAncho()
{
	return MMAPixeles(intAnchoMM);
}
int QtSisImprimeHoja::Xpx()
{
    return QtSisImpMarSup->Xpx();
}
int QtSisImprimeHoja::Ypx(int pintHoja,int pintPagina)
{
  return pintPagina==1 ?  
         HojaDelEncabezadoYpx(pintHoja) :
	 (pxAlto()*pintHoja)+QtSisImpMarSup->Ypx();
  	
}
int QtSisImprimeHoja::X1px()
{
	return pxAncho();
}
int QtSisImprimeHoja::Y1px(int pintHoja)
{
          return pxAlto()*(pintHoja+1); 

}
int QtSisImprimeHoja::pxAlto()
{
	return MMAPixeles(intAltoMM);
}
int QtSisImprimeHoja::PixelesAMM(int pintPixeles)
{
	return pintPixeles/MMAPixeles(pintPixeles);
}
int QtSisImprimeHoja::MMAPixeles(int pintMilimetros)
{
return (int )((pintMilimetros/25.4)*QPDMMedidas->logicalDpiX());
}

int QtSisImprimeHoja::HojaDelEncabezadoYpx(int pintHoja)
{
           return QtSisImpEncabezados->Y1px();
}
int QtSisImprimeHoja::HojaDelEncabezadoY1px(int pintHoja)
{
	 return pxAlto()-QtSisImpEncabezados->Y1px();
}
