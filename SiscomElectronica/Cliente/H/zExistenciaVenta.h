#ifndef __ZEXISTENCIAVENTA_H__
#define __ZEXISTENCIAVENTA_H__

#include <zSiscomRegistro.h> 


class zProductos;
class zExistenciaVenta:public zSiscomRegistro
{
public:
	zExistenciaVenta();
	zExistenciaVenta(const char *pchrPtrFechaIni,
			 const char *pchrPtrFechaFin);
	void Productos(zProductos *);
	void FechaIni(const char *);
	void FechaFin(const char *);
	void IdExpendio(const char *);

	zProductos *Productos();
};

#endif
