#ifndef __ZCOMPRASIMPORTACION_H__
#define __ZCOMPRASIMPORTACION_H__
#include <zSiscomRegistros.h>

class zCompraImportacion;
class zComprasImportacion:public zSiscomRegistros
{
public:
	zComprasImportacion();
	zComprasImportacion &operator<<(zCompraImportacion *);

};

#endif
