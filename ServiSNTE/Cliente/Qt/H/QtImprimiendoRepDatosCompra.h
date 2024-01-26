#ifndef __QTIMPRIMIENDOREPDATOSCOMPRA_H__
#define __QTIMPRIMIENDOREPDATOSCOMPRA_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionDatosCompra;
class QtImprimiendoRepDatosCompra:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRepDatosCompra(zSiscomConexion *pzSisConexion,
					zImpresionDatosCompra *pzDatosCompra,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionDatosCompra *zImpDatCompra;

};

#endif
