#ifndef __ZGASTO_H__
#define __ZGASTO_H__
#include <zSiscomRegistro.h>


class zGasto:public zSiscomRegistro
{
public:
	zGasto(int pintFila,int pintColumna);
	const char *Gasto();
	const char *Importe();
	const char *Color();
	int Fila();
	int Columna();

	void Gasto(const char *);
	void Importe(const char *);
	void Color(const char *pchrPtrColor);
private:
	int intFila;
	int intColumna;
};

#endif
