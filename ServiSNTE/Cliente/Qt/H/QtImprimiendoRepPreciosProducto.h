#ifndef __QTIMPRIMIENDOREPPRECIOSPRODUCTO_H__
#define __QTIMPRIMIENDOREPPRECIOSPRODUCTO_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionListaPrecios;
class QtImprimiendoRepPreciosProducto:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRepPreciosProducto(zSiscomConexion *pzSisConexion,
					zImpresionListaPrecios *pzLstPrecios,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionListaPrecios *zLstPrecios;

};

#endif

	
					
