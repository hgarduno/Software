#ifndef __QTIMPRIMIENDORELACIONCHEQUESPAGAR_H__
#define __QTIMPRIMIENDORELACIONCHEQUESPAGAR_H__
#include <QtImprimiendoReporte.h>

class QVBoxLayout;
class QPushButton;
class zSiscomRegistros;
class zSiscomConexion;
class zImpresionRelacionChequesPagar;
class QtImprimiendoRelacionChequesPagar:public QtImprimiendoReporte
{
Q_OBJECT
public:
	QtImprimiendoRelacionChequesPagar(zSiscomConexion *pzSisConexion,
					zImpresionRelacionChequesPagar *pzRelacionChequesPagar,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0,
					bool pbModal=false,
					WFlags pWFlags=false);
private:
	QtImprimeReporte *ControlReporte();
private:
	zSiscomConexion *zSisConexion;
	zImpresionRelacionChequesPagar *zRelCheqPagar;

};

#endif

	
					
