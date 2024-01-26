#ifndef __QTIMPRIMIENDOREPSTOCKDEPARTAMENTOPROVEEDOR_H__
#define __QTIMPRIMIENDOREPSTOCKDEPARTAMENTOPROVEEDOR_H__
#include <qdialog.h>

class QVBoxLayout;
class QPushButton;
class QtImprimeRepStockDepartamentoProveedor;
class zSiscomRegistros;
class zSiscomConexion;
class QtImprimiendoRepStockDepartamentoProveedor:public QDialog
{
Q_OBJECT
public:
	QtImprimiendoRepStockDepartamentoProveedor(zSiscomConexion *pzSisConexion,
						   zSiscomRegistros *pzSisRegsInformacion,
						   QWidget *pQWParent=0,
						   const char *pchrPtrName=0,
						   bool pbModal=false,
						   WFlags pWFlags=false);
private:
	QVBoxLayout *QVBLayout;
	QPushButton *QPBImprimir;
	QtImprimeRepStockDepartamentoProveedor *QtImpRepStockProv;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsInformacion;
	
private:
	void ColocaControles();

};
#endif
