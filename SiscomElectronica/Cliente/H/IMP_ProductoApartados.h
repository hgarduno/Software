
#ifndef __IMP_PRODUCTOAPARTADOS_H__
#define __IMP_PRODUCTOAPARTADOS_H__
#include <UIC_H_ProductoApartados.h>


class zProductoCotizar;
class zSiscomRegistros;
class zSiscomConexion;
class QProductoApartados:public ProductoApartados
{
 Q_OBJECT
public:
	QProductoApartados(
		zProductoCotizar *pzProdCotizar,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProductoApartados();
private:
	zSiscomRegistros *zSisRegsProdEnApartados;
	zSiscomConexion *zSisConexion;
	zProductoCotizar *zProdCotizar;
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
	int Consulta();
	void Muestra();
	int Consultando();
	void reject();
private slots:
	void SlotAceptar();
	void SlotCancelar();
};
#endif
