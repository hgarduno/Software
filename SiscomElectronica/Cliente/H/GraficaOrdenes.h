#ifndef __GRAFICAORDENES_H__
#define __GRAFICAORDENES_H__
#include <qwidget.h>
#include <OrdenesHora.h>
#include <PuntosHoras.h>

class SiscomDatCom;


/*
 *
 *
 */

typedef struct SiscomRGB
{
	int intR;
	int intG;
	int intB;
}StcSiscomRGB;


class QGraficaOrdenes:public QWidget
{
public:
	QGraficaOrdenes(SiscomDatCom *,char **,QWidget *,const char *);
protected:
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);
private:	
	void IniciaVariables();
	void ColocaEjes(QPainter *);
	void ColocaEjeX(QPainter *);
	void ColocaEjeY(QPainter *);
	void ColocaTextoDias(QPainter *);
	int EspacioEntreDias();
	void ObtenAreaTrabajo();
	void mouseDoubleClickEvent(QMouseEvent *);
	void ConsultaOrdenes();
	void DibujaLinea(const QColor&,QPainter *,QLinea *);
	void ColocaMarcasHoras(const char *,int,int,QPainter *);
	void IniciaDiasHorasPuntos();
	QPuntosDia *IniciaPuntosDias(const char *);
	void RealizaGrafica(QPainter *);
	float ObtenMaximo(float *,int );
	float ObtenEscala();
	void Grafica(QPainter *,QColor,CSisDatoDia *,float );
private:
	QRect QRArea;
	char chrArrFechaIni[15];
	char chrArrFechaFin[15];
	char **chrPtrArgumentos;

	OrdenesHora OHora;
	QPuntosSemana QPSemana;
	SiscomDatCom *SisDatCom;
	QLinea *QLEjeX;
	QLinea *QLEjeY;
	QColor QCEjes;
	int intIniciaEjeX;
	int intTerminaEjeX;
	int intIniciaEjeXPosY;
	int intIniciaEjeY;
	int intHoraInicio;
	int intHoraFin;
	int intTamElipseX;
	int intTamElipseY;
	int intTamMarcaDia;
	int intPosTextoDia;
	QPainter *QPDibuja;

	CSisDatosSemanas CSDtsSemanas;
};



#endif
