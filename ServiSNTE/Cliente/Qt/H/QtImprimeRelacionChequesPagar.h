#ifndef __QTIMPRIMERESTOCKTIENDA_H__
#define __QTIMPRIMERESTOCKTIENDA_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionRelacionChequesPagar;
class zRelacionChequesPagar;
class QPushButton;
class QPainter;


class QtImprimeRelacionChequesPagar:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRelacionChequesPagar(zSiscomConexion *pzSisConexion,
				    zImpresionRelacionChequesPagar *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
//	int MuestraProductos(int ,zRelacionChequesPagar *);
//	int MuestraTotalProveedor(int ,zSiscomRegistros *,zRelacionChequesPagar *);
//	int SeAgregaALaLista(zRelacionChequesPagar *);
private:
	zImpresionRelacionChequesPagar *zImpRelacionChequesPagar;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
