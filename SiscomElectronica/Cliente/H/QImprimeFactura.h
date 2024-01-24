#ifndef __QIMPRIMEFACTURA_H__
#define __QIMPRIMEFACTURA_H__
#include <qwidget.h>
#include <qscrollview.h>
#include <ProductosE.h>

class QPrinter;
class QPaintEvent;
class QPushButton;
class QPaintDevice;
class QRect;
class QFont;
class QScrollBar;


#define __QSCROLLBAR__
class QImprimeFactura:public QScrollView
{
Q_OBJECT
public:
	QImprimeFactura(const char *pchrPtrCliente,
			const char *pchrPtrRFC,
			const ProductosE &,
			QWidget *pQWParent=0,
			const char *pchrPtrName=0);	
	void PonTamanoFactura(int ,int);
protected:
	#ifndef __QSCROLLBAR__
	void paintEvent(QPaintEvent *);
	#else
	void drawContents(QPainter *,int,int,int,int);
	#endif
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
	void DatosCliente(QPainter *);
	void Productos(QPainter *);
	void IniciaVariables();
private:
	QPaintDeviceMetrics *QPDMedidas;
	int intXInicio;
	int intYInicio;

	int intMargenX;
	int intMargenY;
	int intMargenX1;
	int intMargenY1;


	const char *chrPtrCliente;
	const char *chrPtrRFC;

	ProductosE PProductos;

	int intTamXMM;
	int intTamYMM;


	QFont *QFLetra; 
	QRect *QRArea;

	int intTamSaltoLinea;

	QScrollBar *QSBDesplaza;

};

#endif
