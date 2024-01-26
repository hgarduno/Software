#ifndef __QTIMPRIMIENDOREPEXISTENCIATIENDAPROVEEDOR_H__
#define __QTIMPRIMIENDOREPEXISTENCIATIENDAPROVEEDOR_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionExistenciaTiendaProveedor;
class QtImprimiendoRepExistenciaTiendaProveedor:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRepExistenciaTiendaProveedor(zSiscomConexion *pzSisConexion,
					zImpresionExistenciaTiendaProveedor *pzExistenciaTiendaProveedor,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionExistenciaTiendaProveedor *zExtTiendaProveedor;

};

#endif

	
					
