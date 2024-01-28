#ifndef __ZCORTECAJA_H__
#define __ZCORTECAJA_H__
#included <zSiscomRegistro.h>

class zCorteCaja:public
{
 public:
 	zCorteCaja();
	void Dinero(zDenominaciones *pzDenoSDinero);
	void CambioACaja(zDenominaciones *pzDenoSDinero);
	void Gastos();

	const char *TotalDinero();
	const char *TotalCambioACaja();
	const char *TotalGastos();


};
#endif
