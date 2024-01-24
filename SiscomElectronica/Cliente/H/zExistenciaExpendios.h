#ifndef __ZEXISTENCIAEXPENDIOS_H__
#define __ZEXISTENCIAEXPENDIOS_H__

#include <zSiscomRegistros.h>

class zExistenciaExpendios:public zSiscomRegistros
{
public:
	zExistenciaExpendios();
	zExistenciaExpendios(const char *pchrPtrCveProducto);
	void Productos(zSiscomRegistros *pzSisRegsProductos);

};

#endif
