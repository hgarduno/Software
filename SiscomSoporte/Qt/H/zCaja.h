#ifndef __ZCAJA_H__
#define __ZCAJA_H__
#include <zSiscomRegistro.h>

class zEncabezadoCaja;
class zPagoTarjeta;
class zGasto;

class zDenominaciones;
class zEncabezadosCaja;
class zGastos;

class zCaja:public zSiscomRegistro
{
public:
	zCaja(const char *pchrPtrNombre);
	void Dinero(zDenominaciones *pzDenoSDinero);
	void EncabezadosCaja(zEncabezadosCaja *);
	void Total(const char *);
	void TotalGastos(const char *);
	void PagoTarjeta(const char *);
	const char *Caja();
	zDenominaciones *Dinero();
	zEncabezadosCaja *EncabezadosCaja();
	zEncabezadoCaja *EncabezadoTotal();
	zGastos *Gastos();
	const char *Total();
	const char *TotalGastos();
	const char *PagoTarjeta();
	void Actualiza(zSiscomRegistro *);
	friend bool operator==(zCaja &,zCaja &);
	void Gasto(zGasto *);
	zGasto *Gasto(int,int);
	
private:
	int EsElGasto(zGasto *,int,int);

};

#endif