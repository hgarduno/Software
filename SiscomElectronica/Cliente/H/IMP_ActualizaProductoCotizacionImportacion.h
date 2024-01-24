
#ifndef __IMP_ACTUALIZAPRODUCTOCOTIZACIONIMPORTACION_H__
#define __IMP_ACTUALIZAPRODUCTOCOTIZACIONIMPORTACION_H__
#include <UIC_H_ActualizaProductoCotizacionImportacion.h>

class zSiscomConexion;
class zProductoCotImp;
class QActualizaProductoCotizacionImportacion:public ActualizaProductoCotizacionImportacion
{
 Q_OBJECT
public:
	QActualizaProductoCotizacionImportacion(
	    zProductoCotImp *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QActualizaProductoCotizacionImportacion();
	int SeActualizoAlgo();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zProductoCotImp *zProdCotImp;
	int intSeModificoCantidad;
	int intSeModificoPrecio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraProducto();
	void reject();
	void ActualizaDatos();
private slots:
	void SlotCancelar();
	void SlotFocoAPrecio();
	void SlotFocoAAceptar();
	void SlotAceptar();
	void SlotCapturandoPrecio(const QString &);
	void SlotCapturandoCantidad(const QString &);
};
#endif
