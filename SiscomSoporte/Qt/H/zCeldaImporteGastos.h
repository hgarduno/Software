#ifndef __ZCELDAIMPORTEGASTOS_H__
#define __ZCELDAIMPORTEGASTOS_H__

#include <zSiscomRegistro.h>

class zCeldaImporteGastos:public zSiscomRegistro
{
public:
	zCeldaImporteGastos(int,int);
	int Columna();
	int Fila();
private:
	int intFila;
	int intColumna;
};

#endif
