#ifndef __ZCLAVESPROVEEDOR_H__
#define __ZCLAVESPROVEEDOR_H__
#include <zSiscomRegistros.h>

class zClaveProveedor;
class zClavesProveedor:public zSiscomRegistros
{
public:
	zClavesProveedor();
	zClavesProveedor &operator<<(zClaveProveedor *);
};
#endif
