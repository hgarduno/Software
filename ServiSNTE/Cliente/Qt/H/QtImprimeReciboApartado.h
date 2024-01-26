#ifndef __QTIMPRIMERECIBOAPARTADO_H__
#define __QTIMPRIMERECIBOAPARTADO_H__
#include <qwidget.h>
#include <QtBaseMedidas.h>

class zSiscomConexion;
class zSiscomRegistros;
class zImpresionApartado;
class QtImprimeReciboApartado:public QWidget,
			  public QtBaseMedidas
{
Q_OBJECT
public:
	QtImprimeReciboApartado(zSiscomConexion *pzSisConexion,
				QWidget *pQWParent=0,
			    const  char *pchrPtrName=0);
	void ImpresionApartado(zImpresionApartado *pzImpReciboApartado);
	void Imprime();
private:
	void ConsultaPosiciones();
	void ImprimeReciboApartado();
	void ImprimeProductosFactura(zSiscomRegistros *pzSisRegsCamposRegistro);
	int ImprimeAArchivo();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsPosiciones;
	zImpresionApartado *zImpReciboApartado;

private slots:


};


#endif
