#ifndef __QTIMPRIMERELISTAPRECIOSCOMPRADOR_H__
#define __QTIMPRIMERELISTAPRECIOSCOMPRADOR_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionListaPreciosComprador;
class zListaPreciosComprador;
class QPushButton;
class QPainter;


class QtImprimeRepListaPreciosComprador:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepListaPreciosComprador(zSiscomConexion *pzSisConexion,
				    zImpresionListaPreciosComprador *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
	int MuestraProductos(int ,zListaPreciosComprador *);
	int MuestraTotalProveedor(int ,zSiscomRegistros *,zListaPreciosComprador *);
private:
	zImpresionListaPreciosComprador *zImpListaPreciosComprador;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
