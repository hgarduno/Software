#ifndef __QTIMPRIMEREREPDATOSCOMPRA_H__
#define __QTIMPRIMEREREPDATOSCOMPRA_H__
#include <QtImprimeReporte.h>



class zSiscomConexion;
class zImpresionDatosCompra;
class zDatosCompra;
class QPushButton;
class QPainter;


class QtImprimeRepDatosCompra:public QtImprimeReporte
{
Q_OBJECT
public:
	QtImprimeRepDatosCompra(zSiscomConexion *pzSisConexion,
				    zImpresionDatosCompra *pzLstPrecios,
				    QWidget *pQWParent=0,
				    const char *pchrPtrName=0);
private:
	void Imprimiendo();
	void Cabecera();
	void ConsultaPosiciones();
	void Reporte();
	void Departamento();
	void Proveedor();
	void Telefonos();
	void Productos();
private:
	zImpresionDatosCompra *zImpDatosCompra;
	zSiscomRegistros *zSisRegsPosiciones;
	int intIncrementoY;
private slots:

};

#endif
