#ifndef __QTIMPRIMEREPCUENTASPAGAR_H__
#define __QTIMPRIMEREPCUENTASPAGAR_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionCuentasPagar;
class zCuentasPagar;
class QPushButton;
class QPainter;


class QtImprimeRepCuentasPagar:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepCuentasPagar(zSiscomConexion *pzSisConexion,
				    zImpresionCuentasPagar *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
	/*int MuestraProductos(int ,zCuentasPagar *);
	int MuestraTotalProveedor(int ,zSiscomRegistros *,zCuentasPagar *);
	int SeAgregaALaLista(zCuentasPagar *);*/
private:
	zImpresionCuentasPagar *zImpCuentasPagar;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
