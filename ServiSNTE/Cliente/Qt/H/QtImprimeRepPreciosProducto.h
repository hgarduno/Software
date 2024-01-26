#ifndef __QTIMPRIMEREPRECIOSPRODUCTO_H__
#define __QTIMPRIMEREPRECIOSPRODUCTO_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionListaPrecios;
class zListaPrecios;
class QPushButton;
class QPainter;


class QtImprimeRepPreciosProducto:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepPreciosProducto(zSiscomConexion *pzSisConexion,
				    zImpresionListaPrecios *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
	int MuestraProductos(int ,zListaPrecios *);
	int SeAgregaALaLista(zListaPrecios *);
private:
	zImpresionListaPrecios *zImpListaPrecios;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
