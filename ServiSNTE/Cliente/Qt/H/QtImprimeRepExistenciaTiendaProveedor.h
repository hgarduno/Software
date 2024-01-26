#ifndef __QTIMPRIMEREPEXISTENCIATIENDAPROVEEDOR_H__
#define __QTIMPRIMEREPEXISTENCIATIENDAPROVEEDOR_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionExistenciaTiendaProveedor;
class zExistenciaTiendaProveedor;
class QPushButton;
class QPainter;


class QtImprimeRepExistenciaTiendaProveedor:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepExistenciaTiendaProveedor(zSiscomConexion *pzSisConexion,
				    zImpresionExistenciaTiendaProveedor *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
/*	int MuestraProductos(int ,zExistenciaTiendaProveedor *);
	int MuestraTotalProveedor(int ,zSiscomRegistros *,zExistenciaTiendaProveedor *);
	int SeAgregaALaLista(zExistenciaTiendaProveedor *);
	int Producto(int pintDesplazamiento,
		      zSiscomRegistros *pzSisRegsCampos,
		      zSiscomRegistro *pzSisRegProducto);
	int SeImprimeElCampo(zSiscomRegistro *pzSisRegProducto);*/
private:
	zImpresionExistenciaTiendaProveedor *zImpExistenciaTiendaProveedor;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
