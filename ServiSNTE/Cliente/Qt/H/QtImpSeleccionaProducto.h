#ifndef __QTIMPSELECCIONAPRODUCTO_H__
#define __QTIMPSELECCIONAPRODUCTO_H__
#include <cstddef>
#include <SeleccionaProducto.h>

class zSiscomConexion;
class zSiscomRegistro;

class zDireccion;
class QtImpSeleccionaProducto:public SeleccionaProducto
{
Q_OBJECT
public:
	QtImpSeleccionaProducto(zSiscomConexion *pzSisConexion,
				zSiscomRegistro *pzSisProveedor,
				QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	int Aceptar();
	zSiscomRegistro *Producto();
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaVariables();
	void MuestraProductosTabla();
private:
	int intAceptar;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisProveedor;
	zSiscomRegistro *zSisProducto;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotProducto(zSiscomRegistro *);
	void SlotProducto(int,int,int,const QPoint &);
};




#endif
