#ifndef __ZPRODUCTOSTRANSFERIR_H__
#include <zSiscomRegistro.h>
class zProductoTransferir;
class zProductosTransferir:public zSiscomRegistro
{

public:
	zProductosTransferir();
	void Agrega(zProductoTransferir *pzProducto);
	void ExpendioO(const char *pchrPtrIdExpendioO);
	void ExpendioD(const char *pchrPtrIdExpendioD);
	void IdEmpleado(const char *pchrPtrIdEmpleado);
	zSiscomRegistros *Productos();
	void EliminaProducto(int );
	void Cantidad(int pintNProducto,const char *pchrPtrCantidad);
};

#endif
