#ifndef __ZENCABEZADOCAJA_H__
#define __ZENCABEZADOCAJA_H__
#include <zSiscomRegistro.h>
class zEncabezadoCaja:public zSiscomRegistro
{
public:
	zEncabezadoCaja(int,int,const char *,const char *,const char *);
	int Fila();
	int Columna();
	const char *Nombre();
	const char *Color();
	const char *Valor();
	friend bool operator==(zEncabezadoCaja &,zEncabezadoCaja &);
	friend bool operator==(const char *,zEncabezadoCaja &);
private:
	int intFila;
	int intColumna;
};
#endif
