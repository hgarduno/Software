#ifndef __QTIMPRIMETRANSFERENCIA2_H__
#define __QTIMPRIMETRANSFERENCIA2_H__
#include <qwidget.h>
#include <QtBaseMedidas.h>

class zSiscomConexion;
class zSiscomRegistros;
class zImpresionTransferencia;
class QtImprimeTransferencia2:public QWidget,
			  public QtBaseMedidas
{
Q_OBJECT
public:
	QtImprimeTransferencia2(zSiscomConexion *pzSisConexion,
				QWidget *pQWParent=0,
			    	const  char *pchrPtrName=0);
	void ImpresionTransferencia2(zImpresionTransferencia *pzImpTransferencia2);
	void Imprime();
private:
	void ConsultaPosiciones();
	void ImprimeTransferencia2();
	int ImprimeAArchivo();
	void ImprimeProductosTransferencia(zSiscomRegistros *pzSisRegsProductos);
	void ImprimeCamposProducto(int pintDesplazamientoY,zSiscomRegistros *);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsPosiciones;
	zImpresionTransferencia *zImpTransferencia2;
private slots:


};


#endif
