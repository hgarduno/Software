#ifndef __CELDACAMBIODIAANTERIOR_H__
#define __CELDACAMBIODIAANTERIOR_H__

#include <zSiscomRegistro.h>


class zCeldaCambioDiaAnterior:public zSiscomRegistro
{
public:
	zCeldaCambioDiaAnterior(int,int,const char *pchrPtrColor="gray");
	void Valor(const char *);
	int Fila();
	int Columna();
	const char *Valor();
private:
	int intFila;
	int intColumna;
};

#endif
