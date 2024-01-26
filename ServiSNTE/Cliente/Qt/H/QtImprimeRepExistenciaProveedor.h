#ifndef __QTIMPRIMERESTOCKTIENDA_H__
#define __QTIMPRIMERESTOCKTIENDA_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionExistenciaProveedor;
class zExistenciaProveedor;
class QPushButton;
class QPainter;


class QtImprimeRepExistenciaProveedor:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepExistenciaProveedor(zSiscomConexion *pzSisConexion,
				    zImpresionExistenciaProveedor *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
	int MuestraProductos(int ,zExistenciaProveedor *);
	int MuestraTotalProveedor(int ,zSiscomRegistros *,zExistenciaProveedor *);
	int SeAgregaALaLista(zExistenciaProveedor *);
	void Empresa();
	int MuestraExistenciaTiendas(int pintDesplazamientoY,zExistenciaProveedor *);
	int MuestraTotalExistencia(int ,zExistenciaProveedor *);
private:
	zImpresionExistenciaProveedor *zImpExistenciaProveedor;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
