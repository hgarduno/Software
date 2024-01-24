#ifndef __EXISTENCIAEXPENDIO_H__
#define __EXISTENCIAEXPENDIO_H__
#include <zSiscomRegistro.h>


class zExistenciaExpendio:public zSiscomRegistro
{
public:
	zExistenciaExpendio(const char *pchrPtrCveProducto);
	zExistenciaExpendio();

};

#endif
