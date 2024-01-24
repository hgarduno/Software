#ifndef __ZCOMPRASIMPORTACIONPRODUCTO_H__
#define __ZCOMPRASIMPORTACIONPRODUCTO_H__
#include <zSiscomRegistros.h>

class zCompraImportacionProducto;
class zComprasImportacionProducto:public zSiscomRegistros
{
public:
	zComprasImportacionProducto();
	zComprasImportacionProducto &operator<<(zCompraImportacionProducto *);
	zCompraImportacionProducto *Ultima();
};
#endif
