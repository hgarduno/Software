#ifndef __QTIMPRIMEPUNTOVENTA_H__
#define __QTIMPRIMEPUNTOVENTA_H__
#include <qwidget.h>
#include <QtBaseMedidas.h>

class zSiscomConexion;
class zSiscomRegistros;
class zImpresionPuntoVenta;
class QtImprimePuntoVenta:public QWidget,
			  public QtBaseMedidas
{
Q_OBJECT
public:
	QtImprimePuntoVenta(zSiscomConexion *pzSisConexion,
				QWidget *pQWParent=0,
			    const  char *pchrPtrName=0);
	void Venta(zImpresionPuntoVenta *pzImpPuntoVenta);
	void Imprime();
private:
	void ConsultaPosiciones();
	void ImprimeFacturaPuntoVenta();
	void ImprimeProductosFactura(zSiscomRegistros *pzSisRegsCamposRegistro);
	void ImprimeCamposProducto(int pintDesplazamientoY,zSiscomRegistros *pzSisRegsCamposRegistro);
	int ImprimeAArchivo();

	int TamanoLetra();
	void ObtenTipoLetra(QFont *pQFTipoLetra);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsPosiciones;
	zImpresionPuntoVenta *zImpPuntoVenta;

private slots:


};


#endif
