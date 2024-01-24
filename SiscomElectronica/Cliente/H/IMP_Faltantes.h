
#ifndef __IMP_FALTANTES_H__
#define __IMP_FALTANTES_H__
#include <UIC_H_Faltantes.h>
class zProductoCotizar;
class QFaltantes:public Faltantes
{
 Q_OBJECT
public:
	QFaltantes(zProductoCotizar *pzProductoCot,
					char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QFaltantes();
private:
	char **chrPtrArgumentos;
	zProductoCotizar *zProdCotizar;
private:
	void ConectaSlots();
	void IniciaVariables();
	zProductoCotizar *Producto();
	void TipoProducto();
	void MuestraProductoRegistrado();
	void MuestraNuevoProducto();
private slots:
};
#endif
