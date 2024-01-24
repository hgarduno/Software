#ifndef __ZPRODUCTO_H__
#define __ZPRODUCTO_H__
#include <zSiscomRegistro.h>

class zProducto:public zSiscomRegistro
{
public:
	zProducto();
	zProducto(const char *pchrPtrClave);
	zProducto(zSiscomRegistro *pzSisRegProducto);
	void Clave(const char *pchrPtrClave);
	void Descripcion(const char *pchrPtrDescripcion);
	void ExiBodega(const char *pchrPtrExiBodega);
	void DefinicionProducto(zSiscomRegistros *pzSisRegsDefinicion);	

	const char *Clave();
	const char *Descripcion();
	const char *TipoProducto();
	int TipoProductoInt();
	const char *Existencia();
	const char *ExiBodega();
	const char *IdCaja();
	const char *Caja();
	zSiscomRegistros *DefinicionProducto();
	bool operator==(const char *pchrPtrCveProducto);
	bool operator==(zSiscomRegistro *);
	
};


#endif


