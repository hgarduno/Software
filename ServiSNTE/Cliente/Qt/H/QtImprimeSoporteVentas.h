#ifndef __QTIMPRIMERESOPORTEVENTAS_H__
#define __QTIMPRIMERESOPORTEVENTAS_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionSoporteVentas;
class zSoporteVentas;
class QPushButton;
class QPainter;


class QtImprimeSoporteVentas:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeSoporteVentas(zSiscomConexion *pzSisConexion,
				    zImpresionSoporteVentas *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
//	int MuestraProductos(int ,zSoporteVentas *);
//	int MuestraTotalProveedor(int ,zSiscomRegistros *,zSoporteVentas *);
//	int SeAgregaALaLista(zSoporteVentas *);
private:
	zImpresionSoporteVentas *zImpSoporteVentas;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
