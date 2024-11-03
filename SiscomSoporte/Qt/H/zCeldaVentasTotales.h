#ifndef __ZCELDAVENTASTOTALES_H__
#define __ZCELDAVENTASTOTALES_H__
#include <zSiscomRegistro.h> 

class zCeldaVentasTotales:public zSiscomRegistro
{
public:
	zCeldaVentasTotales(int,int,const char *pchrPtrColor="gray");
	int Fila();
	int Columna();
private:
	int intFila;
	int intColumna;


};

#endif
