#ifndef __SISCOMIMPRIME_H__
#define __SISCOMIMPRIME_H__
#include <qscrollview.h>

class QPainter;
class QPaintEvernt;
class QPaintDevice;
class QRect;
class QScrollBar;


class SiscomImprime:public QScrollView
{
Q_OBJECT
public:
	SiscomImprime(QWidget *pQWParent=0,
		      const char *pchrPtrName=0);

	void TamanoHoja(int,int);

private:
	
	void drawContents(QPainter *,int,int,int,int);
	void Dibuja(QPainter *);
	void ObtenMedidas(QPainter *);
	void Mide();
	int MMAPixeles(int );
	int PixelesAMM(int);
	int TrasladaX(int );
	int TrasladaY(int );
	void Imprime();
	void DibujaHoja(QPainter *,int);
	void Texto(QPainter *,int ,int,const char *);
	void PonCadenaEnFormatoHTML(const char *,char *);
	void IniciaVariables();
private:
	QPaintDeviceMetrics *QPDMedidas;
	int intXInicio;
	int intYInicio;

	int intMargenX;
	int intMargenY;
	int intMargenX1;
	int intMargenY1;


	int intTamXMM;
	int intTamYMM;


	QFont *QFLetra; 
	QRect *QRArea;

	int intTamSaltoLinea;

	QScrollBar *QSBDesplaza;


};
#endif
