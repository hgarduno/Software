#ifndef __CELDAIMPORTEEFECTIVOCAJA_H__
#define __CELDAIMPORTEEFECTIVOCAJA_H__
#include <zSiscomRegistros.h>

class zCeldaImporteEfectivoCaja:public zSiscomRegistro
{
public:
	zCeldaImporteEfectivoCaja(int,int,const char *pchrPtrColor="white");

	int Fila();
	int Columna();
private:
	int intFila;
	int intColumna;
};
#endif
