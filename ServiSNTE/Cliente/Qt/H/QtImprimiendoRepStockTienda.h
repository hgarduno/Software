#ifndef __QTIMPRIMIENDOREPSTOCKTIENDA_H__
#define __QTIMPRIMIENDOREPSTOCKTIENDA_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionStockTienda;
class QtImprimiendoRepStockTienda:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRepStockTienda(zSiscomConexion *pzSisConexion,
					zImpresionStockTienda *pzStockTienda,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionStockTienda *zStkTienda;

};

#endif

	
					
