#ifndef __QTIMPRIMIENDOSOPORTEVENTAS_H__
#define __QTIMPRIMIENDOSOPORTEVENTAS_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionSoporteVentas;
class QtImprimiendoSoporteVentas:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoSoporteVentas(zSiscomConexion *pzSisConexion,
					zImpresionSoporteVentas *pzSoporteVentas,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionSoporteVentas *zSptVentas;

};

#endif
