#ifndef __QTSISIMPRIME_H__
#define __QTSISIMPRIME_H__
#include <qscrollview.h>

class QPaintDeviceMetrics;
class QPainter;
class QPrinter;
class SiscomRegistro3Lst;
class SiscomRegistro3;
class QtSisImprime:public QScrollView
{
public:
	QtSisImprime(SiscomRegistro3Lst *pSisReg3LstDatos,
		     char **pchrPtrColumnas,
		     char **pchrPtrTitulosColumna,
		     int *pintPtrCaracteresC,
		QWidget *pQWParent,
		     const char *pchrPtrName);
	void Margen(int pintX,int pintY,int pintX1,int pintY1);
	void NumeroHojas(int pintNHojas);
	int MMAPixeles(int pintMilimetros);
	int PixelesAMM(int pintPixeles);
	void DibujaHoja(QPainter *,int);
	void DibujaHoja(QPainter *,
			SiscomRegistro3Lst *pSisReg3Dato,
		         int pintPagina,
			 int pintNFilas,
			 int pintNColumnas);
	void Dibujando(QPainter *);
	void Dibujando(QPainter *,QPrinter *);
	void DibujandoHoja(QPainter *,
			   SiscomRegistro3Lst *,
			   int pintRengolones,
			   int pintColumnas,
			   int pintPagina);
	void drawContents(QPainter *pQPADibujo,int,int,int,int);
	int ObtenAltoTexto(QPainter *);


	void RectanguloHojaY(int pintPagina,
			     int pintAltoHoja,
			     int &pintY);
	void TamanoHojaTrabajo(int pintMargen,
			       int pintAnchoTotal,
			       int pintAltoTotal,
			       int &pintAnchoHojaT,
			       int &pintAltoHojaT);

	void RectanguloHojaTrabajo(int pintPagina,
				   int pintMargen,
				   int pintAltoHojaT,
				   int &pintX,
				   int &pintY);
				   
	int AnchoColumna(QPainter *,int pintNCaracteres);
	int AnchoColumnaMM(QPainter *,int pintNCaracteres);
	void MuestraTitulosColumna(int pintXHojaT,
				   int pintNColumnas,
				   int pintTamRenglon,
				   QPainter *,
				   int &pintYHojaT);
private:
	int intMX;
	int intMY;
	int intMX1;
	int intMY1;
	int intNHojas;
	int intTamanoX;
	int intTamanoY;
	int intPagina;
	int intMargen;
	SiscomRegistro3Lst *SisReg3LstDatos;
	char **chrPtrColumnas;
	char **chrPtrTitulosColumnas;
	int *intPtrCaracteresC;
	int intTitulosYa;
protected:
	void ObtenMedidas(QPainter *);

private:
	QPaintDeviceMetrics *QPDMedidas;
private:
	void TamanoHoja();

};

#endif
