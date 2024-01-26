#ifndef __QTIMPRIMEREREPDATOSCOMPRA_H__
#define __QTIMPRIMEREREPDATOSCOMPRA_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionProveedores;
class zProveedores;
class QPushButton;
class QPainter;


class QtImprimeRepProveedores:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepProveedores(zSiscomConexion *pzSisConexion,
				    zImpresionProveedores *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
	void Proveedores();
	void TelefonosProveedor(int pintDesplazamientoY);
private:
	zImpresionProveedores *zImpProveedores;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
