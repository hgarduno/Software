#ifndef __QTIMPRIMERESTOCKTIENDA_H__
#define __QTIMPRIMERESTOCKTIENDA_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionStockTienda;
class zStockTienda;
class QPushButton;
class QPainter;


class QtImprimeRepStockTienda:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepStockTienda(zSiscomConexion *pzSisConexion,
				    zImpresionStockTienda *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
	int MuestraProductos(int ,zStockTienda *);
	int MuestraTotalProveedor(int ,zSiscomRegistros *,zStockTienda *);
	int SeAgregaALaLista(zStockTienda *);
	int Producto(int pintDesplazamiento,
		      zSiscomRegistros *pzSisRegsCampos,
		      zSiscomRegistro *pzSisRegProducto);
	int SeImprimeElCampo(zSiscomRegistro *pzSisRegProducto);
private:
	zImpresionStockTienda *zImpStockTienda;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
