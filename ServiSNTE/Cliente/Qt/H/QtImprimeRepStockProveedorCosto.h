#ifndef __QTIMPRIMERESTOCKPROVEEDORCOSTO_H__
#define __QTIMPRIMERESTOCKPROVEEDORCOSTO_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionStockProveedorCosto;
class zStockProveedorCosto;
class QPushButton;
class QPainter;


class QtImprimeRepStockProveedorCosto:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepStockProveedorCosto(zSiscomConexion *pzSisConexion,
				    zImpresionStockProveedorCosto *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
	int MuestraStockTienda(int ,zStockProveedorCosto *);
	int AgregaColumnasTiendas(zStockProveedorCosto *);
private:
	zImpresionStockProveedorCosto *zImpStockProveedorCosto;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
