#ifndef __QTIMPRIMIENDOSOPORTECOMPRAS_H__
#define __QTIMPRIMIENDOSOPORTECOMPRAS_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionSoporteCompras;
class QtImprimiendoSoporteCompras:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoSoporteCompras(zSiscomConexion *pzSisConexion,
					zImpresionSoporteCompras *pzSoporteCompras,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionSoporteCompras *zSopComp;

};

#endif
