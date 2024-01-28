#ifndef __ZENCABEZADOSCAJA_H__
#define __ZENCABEZADOSCAJA_H__
#include <zSiscomRegistros.h>


class zEncabezadoCaja;

class zEncabezadosCaja:public zSiscomRegistros
{
public:
	zEncabezadosCaja();
	zEncabezadosCaja &operator<<(zEncabezadoCaja *);
	zEncabezadosCaja &operator+=(zEncabezadosCaja &);
	zEncabezadoCaja *Encabezado(const char *pchrPtrNombre);
	
};
#endif
