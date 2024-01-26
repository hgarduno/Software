#ifndef __QTIMPRIMEREPORTE_H__
#define __QTIMPRIMEREPORTE_H__ 
#include <qwidget.h>
#include <qscrollview.h>
#include <QtBaseMedidas.h>

class zSiscomConexion;
class zSiscomRegistros;
class QPushButton;
class QPainter;

class QtImprimeReporte:public QScrollView,
		       public QtBaseMedidas
{
Q_OBJECT
public:
	QtImprimeReporte(zSiscomConexion *pzSisConexion,
			 zSiscomRegistros *pzSisRegsInformacion,
			 QWidget *pQWParent=0,
			const char *pchrPtrName=0);
	void Nombre(const char *pchrPtrNombre);
	const char *Nombre();
	zSiscomRegistros *Informacion();
	void ContadorPagina(int *pintPtrY,
			    int *pintPtrContadorY,
			    int *pintPtrContadorPagina);
	zSiscomConexion *Conexion();
	void Imprime(QPainter *);
virtual void Imprimiendo();
private:
	void ObtenTipoLetra(QFont *);
	void drawContents(QPainter *,int,int,int,int);
	int EsDispositivoExterno();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsInformacion;
	QPainter *QPDibujando;
	const char *chrPtrNombre;
private slots:

};

#endif
