#ifndef __ZCELDACALCULANDOCORTE_H__
#define __ZCELDACALCULANDOCORTE_H__

#include <zSiscomRegistro.h>

class zCeldaCalculandoCorte:public zSiscomRegistro
{
public:
	zCeldaCalculandoCorte(int,int,const char *pchrPtrColor="gray");
	int Fila();
	int Columna();
private:
	int intFila;
	int intColumna;
};


#endif
