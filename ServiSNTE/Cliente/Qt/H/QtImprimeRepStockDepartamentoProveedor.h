#ifndef __QTIMPRIMEREPSTOCKDEPARTAMENTOPROVEEDOR_H__
#define __QTIMPRIMEREPSTOCKDEPARTAMENTOPROVEEDOR_H__
#include <QtImprimeReporte.h>

class zSiscomConexion;
class zSiscomRegistros;
class QPushButton;
class QPainter;

class QtImprimeRepStockDepartamentoProveedor:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepStockDepartamentoProveedor(zSiscomConexion *pzSisConexion,
					       zSiscomRegistros *pzSisRegsInformacion,
					       QWidget *pQWParent=0,
					       const char *pchrPtrName=0);
					       
private:
	void Imprimiendo();
private:
private slots:

};

#endif
