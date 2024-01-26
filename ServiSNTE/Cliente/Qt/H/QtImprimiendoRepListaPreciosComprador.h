#ifndef __QTIMPRIMIENDOREPLISTAPRECIOSCOMPRADOR_H__
#define __QTIMPRIMIENDOREPLISTAPRECIOSCOMPRADOR_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionListaPreciosComprador;
class QtImprimiendoRepListaPreciosComprador:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRepListaPreciosComprador(zSiscomConexion *pzSisConexion,
					zImpresionListaPreciosComprador *pzListaPreciosComprador,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionListaPreciosComprador *zStkTienda;

};

#endif

	
					
