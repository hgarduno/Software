#ifndef __QTSISIMPRIMETABLA_H__
#define __QTSISIMPRIMETABLA_H__
#include <qscrollview.h>

class SiscomRegistro3Lst;
class SiscomRegistro3;
class QWidget;
class QPaintDeviceMetrics;
class QPainter;
class QPrinter;
class QtSisImprimeMargen;
class QtSisImprimeEncabezados;
class QtSisImprimeHoja;
class QtSisImprimeTabla:public QScrollView
{
public:
	QtSisImprimeTabla(QWidget *pQWParent,
			  const char *pchrPtrName);

	void Columnas(char **pchrPtrColumnas);
	void TitulosColumnas(char **pchrPtrTitulosColumna);
	void RegistrosSiscom(SiscomRegistro3Lst *pSisReg3LstDatos);
	void CaracteresColumna(int *pintCaracteresC);
	void MargenSuperior(int pintX,
			    int pintY);
	void MargenInferior(int pintX,
			    int pintY);
	void TamanoHoja(int pintAncho,int pintAlto);
private:
	void CalculaHojaTrabajo();
	void drawContents(QPainter *,
			  int,
			  int,
			  int,
			  int);
	void HojaTrabajo(QPainter *,
			 SiscomRegistro3Lst *pSisReg3LstDatos,
			 int pintHoja,
			 int pintPagina);
	void DibujaHojaTrabajo(QPainter *pQDibuja,int pintHoja,int pintPagina);
	void Dibujando(QPainter *);
	void RenglonesHoja(int pintNRenglones,
			   SiscomRegistro3Lst *pSisReg3LstRenglones);

	int AltoTextoPx(QPainter *);
	void Encabezado(QPainter *pQPDibuja,int pintHoja,int pintPagina);
	 void MuestraDatos(QPainter *pQPDibuja,
	 		   SiscomRegistro3Lst *pSisReg3LstDatos,
			   int pintPagina,
			   int pintHoja);
	 void MuestraRenglon(QPainter *pQPDibuja,
	 		     int pintY1,
	 		     int pintPagina,
			     int pintHoja,
	 		     SiscomRegistro3 *pSisReg3Renglon);
	void MuestraNumeroPagina(QPainter *pQPDibuja,
				 int pintPagina,
				 int pintContadorY);
	void DibujaLineaY(QPainter *pQPDibuja,int pintContadorY);
	void DibujaLineaX(QPainter *pQPDibuja,
			  int pintHoja,
			  int pintPagina,
			  int pintContadorX);
	 void keyPressEvent(QKeyEvent *);
public:
	 void MedidasDispositivo(QPainter *pQPDibuja);
	 int PixelesAMM(int pintPixeles);
	 int MMAPixeles(int pintMilimetros);
	 void CambiaMargenAPixeles();
	 int ObtenNumeroRenglones(QPainter *,int pintHoja,int pintPagina);

	void Dibujando(QPainter *,QPrinter *);
	 		     

private:

	  QPaintDeviceMetrics *QPDMMedidas;
	  char **chrPtrColumnas;
	  char **chrPtrTitulosColumna;
	  int *intPtrCaracteresC;
	  SiscomRegistro3Lst *SisReg3LstDatos;

	  int intAnchoHoja;
	  int intAltoHoja;

	  int intMargenSuperiorX;
	  int intMargenSuperiorY;
	  int intMargenInferiorX;
	  int intMargenInferiorY;
private:
	  int intYaMedidasDispositivo;
	  QtSisImprimeMargen *QtSisImpMSup;
	  QtSisImprimeMargen *QtSisImpMInf;
	  QtSisImprimeHoja *QtSisImpHoja;
	  QtSisImprimeHoja *QtSisImpHojaT;
	  QtSisImprimeEncabezados *QtSisImpEncabezados;

};

#endif














