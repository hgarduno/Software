#ifndef __QTSISIMPRIMEHOJA_H__
#define __QTSISIMPRIMEHOJA_H__
class QPaintDeviceMetrics;
class QtSisImprimeEncabezados;
class QtSisImprimeMargen;
class QtSisImprimeHoja
{
public:
	QtSisImprimeHoja(QPaintDeviceMetrics *);
	void MargenSuperior(QtSisImprimeMargen *);
	void MargenInferior(QtSisImprimeMargen *);
	void Encabezados(QtSisImprimeEncabezados *);
	void mmAncho(int pintAncho);
	void mmAlto(int pintAlto);
	int mmAncho();
	int mmAlto();
	int pxAncho();
	int pxAlto();
	
	int Xpx();
	int Ypx(int pintHoja,int pintPagina);
	int X1px();
	int Y1px(int pintHoja);
private:
	 int PixelesAMM(int pintPixeles);
	 int MMAPixeles(int pintMilimetros);
	 int HojaDelEncabezadoYpx(int pintHoja);
	 int HojaDelEncabezadoY1px(int pintHoja);
private:
	QPaintDeviceMetrics *QPDMMedidas;
	int intAltoMM;
	int intAnchoMM;
	QtSisImprimeMargen *QtSisImpMarSup;
	QtSisImprimeMargen *QtSisImpMarInf;
	QtSisImprimeEncabezados *QtSisImpEncabezados;
};

#endif
