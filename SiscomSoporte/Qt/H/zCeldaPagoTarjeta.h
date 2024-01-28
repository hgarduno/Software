#ifndef __ZCELDAPAGOTARJETA_H__
#define __ZCELDAPAGOTARJETA_H__
#include <zSiscomRegistro.h>


class zCeldaPagoTarjeta:public zSiscomRegistro
{
public:
	zCeldaPagoTarjeta(int pintFila,
		     int pintColumna,
		     const char *pchrPtrColor="gray");
	void Importe(const char *);
	int Fila();
	int Columna();
friend bool operator==(zCeldaPagoTarjeta &pzPTarjeta1,
		       zCeldaPagoTarjeta &pzPTarjeta2);
private:
	int intFila;
	int intColumna;
};

#endif
