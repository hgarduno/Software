#ifndef __QTIMPRIMIENDOSOPORTETRANSFERENCIAS_H__
#define __QTIMPRIMIENDOSOPORTETRANSFERENCIAS_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionSoporteTransferencias;
class QtImprimiendoSoporteTransferencias:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoSoporteTransferencias(zSiscomConexion *pzSisConexion,
					zImpresionSoporteTransferencias *pzSoporteTransferencias,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionSoporteTransferencias *zSptTransferencias;

};

#endif

	
					
