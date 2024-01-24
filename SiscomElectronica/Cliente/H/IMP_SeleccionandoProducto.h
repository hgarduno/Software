
#ifndef __IMP_SELECCIONANDOPRODUCTO_H__
#define __IMP_SELECCIONANDOPRODUCTO_H__
#include <UIC_H_SeleccionandoProducto.h>
class zSiscomConexion;
class zSiscomRegistro;
class QSeleccionandoProducto:public SeleccionandoProducto
{
 Q_OBJECT
public:
	QSeleccionandoProducto(
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QSeleccionandoProducto();
	int Aceptar();
	zSiscomRegistro *Producto();
private:
	zSiscomConexion *zSisConexion;
	int intAceptar;
	zSiscomRegistro *zSisRegProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
	void reject();
	void MuestraDescripcion(zSiscomRegistro *pzSisRegProducto);	
private slots:
	void SlotAceptar();
	void SlotCancelar();
	void SlotSeleccionoProducto(zSiscomRegistro *);
};
#endif
