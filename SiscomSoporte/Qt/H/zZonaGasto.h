#ifndef __ZZONAGASTO_H__
#define __ZZONAGASTO_H__
#include <zSiscomRegistro.h>

class zZonaGasto:public zSiscomRegistro
{
public:
	zZonaGasto(int pintFila,int pintColumna);
	int Fila();
	int Columna();
	friend bool operator==(zZonaGasto &,zZonaGasto &);
private:
	int intFila;
	int intColumna;
};

#endif
