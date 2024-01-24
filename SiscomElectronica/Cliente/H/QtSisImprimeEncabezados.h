#ifndef __QTSISIMPRIMEENCABEZADOS_H__
#define __QTSISIMPRIMEENCABEZADOS_H__

class QPainter;
class QPaintDeviceMetrics;
class QtSisImprimeMargen;
class QtSisImprimeEncabezados
{
public:
	QtSisImprimeEncabezados(QPaintDeviceMetrics *pQPDMMedidas,
				QtSisImprimeMargen *pQtSisImpMarSup,
				char **pchrPtrTitulosColumnas,
				int *pintPtrCaracteresC);
	void DibujaEncabezado(QPainter *);
	int Y1px();
	int Columnas();
	 int AnchoColumnaPx(QPainter *,int pintNCaracteres);
private:
	QPaintDeviceMetrics *QPDMMedidas;
	QtSisImprimeMargen *QtSisImpMarSup;
	char **chrPtrTitulosColumnas;
	int *intPtrCaracteresC;
private:
	int intAltoTexto;
	int intY1;
	int intNColumnas;
private:
	 int PixelesAMM(int pintPixeles);
	 int MMAPixeles(int pintMilimetros);
private:
	void MuestraTitulos();
};


#endif
