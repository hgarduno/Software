#ifndef __QTIMPRIMIENDOREPEXISTENCIAPROVEEDOR_H__
#define __QTIMPRIMIENDOREPEXISTENCIAPROVEEDOR_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionExistenciaProveedor;
class QtImprimiendoRepExistenciaProveedor:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRepExistenciaProveedor(zSiscomConexion *pzSisConexion,
					zImpresionExistenciaProveedor *pzExistenciaProveedor,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionExistenciaProveedor *zStkTienda;

};

#endif

	
					
