#ifndef __QTIMPRIMERESOPORTECOMPRAS_H__
#define __QTIMPRIMERESOPORTECOMPRAS_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionSoporteCompras;
class zSoporteCompras;
class QPushButton;
class QPainter;


class QtImprimeSoporteCompras:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeSoporteCompras(zSiscomConexion *pzSisConexion,
				    zImpresionSoporteCompras *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
//	int MuestraProductos(int ,zSoporteCompras *);
//	int MuestraTotalProveedor(int ,zSiscomRegistros *,zSoporteCompras *);
//	int SeAgregaALaLista(zSoporteCompras *);
private:
	zImpresionSoporteCompras *zImpSoporteCompras;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
