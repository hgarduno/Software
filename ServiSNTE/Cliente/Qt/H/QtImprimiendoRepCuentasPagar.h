#ifndef __QTIMPRIMIENDOREPCUENTASPAGAR_H__
#define __QTIMPRIMIENDOREPCUENTASPAGAR_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionCuentasPagar;
class QtImprimiendoRepCuentasPagar:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRepCuentasPagar(zSiscomConexion *pzSisConexion,
					zImpresionCuentasPagar *pzCuentasPagar,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionCuentasPagar *zCtsPagar;

};

#endif

	
					
