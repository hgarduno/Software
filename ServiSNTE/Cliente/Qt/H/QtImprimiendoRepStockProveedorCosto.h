#ifndef __QTIMPRIMIENDOREPSTOCKPROVEEDORCOSTO_H__
#define __QTIMPRIMIENDOREPSTOCKPROVEEDORCOSTO_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionStockProveedorCosto;
class QtImprimiendoRepStockProveedorCosto:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRepStockProveedorCosto(zSiscomConexion *pzSisConexion,
					zImpresionStockProveedorCosto *pzStockProveedorCosto,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionStockProveedorCosto *zStkTienda;

};

#endif

	
					
