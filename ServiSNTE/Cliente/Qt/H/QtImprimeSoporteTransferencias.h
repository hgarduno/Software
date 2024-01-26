#ifndef __QTIMPRIMESOPORTETRANSFERENCIAS_H__
#define __QTIMPRIMESOPORTETRANSFERENCIAS_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionSoporteTransferencias;
class zSoporteTransferencias;
class QPushButton;
class QPainter;


class QtImprimeSoporteTransferencias:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeSoporteTransferencias(zSiscomConexion *pzSisConexion,
				    zImpresionSoporteTransferencias *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
/*	int MuestraProductos(int ,zSoporteTransferencias *);
	int MuestraTotalProveedor(int ,zSiscomRegistros *,zSoporteTransferencias *);
	int SeAgregaALaLista(zSoporteTransferencias *);
	int Producto(int pintDesplazamiento,
		      zSiscomRegistros *pzSisRegsCampos,
		      zSiscomRegistro *pzSisRegProducto);
	int SeImprimeElCampo(zSiscomRegistro *pzSisRegProducto);*/
private:
	zImpresionSoporteTransferencias *zImpSoporteTransferencias;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
