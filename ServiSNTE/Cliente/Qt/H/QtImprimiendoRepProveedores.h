#ifndef __QTIMPRIMIENDOREPPROVEEDORES_H__
#define __QTIMPRIMIENDOREPPROVEEDORES_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionProveedores;
class QtImprimiendoRepProveedores:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRepProveedores(zSiscomConexion *pzSisConexion,
					zImpresionProveedores *pzProveedores,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionProveedores *zImpDatCompra;

};

#endif
