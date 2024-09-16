#ifndef __ZCAJA_H__
#define __ZCAJA_H__
#include <zSiscomRegistro.h>

class zEncabezadoCaja;
class zPagoTarjeta;
class zGasto;

class zDenominaciones;
class zEncabezadosCaja;
class zGastos;
class zDenominacion;
class zCaja:public zSiscomRegistro
{
public:
	zCaja(const char *pchrPtrCaja,const char *pchrPtrNombre);
	void Dinero(zDenominaciones *pzDenoSDinero);
	void EncabezadosCaja(zEncabezadosCaja *);
	void Total(const char *);
	void TotalGastos(const char *);
	void PagoTarjeta(const char *);
	void Transferencias(const char *);
	void Nombre(const char *);
	void TotalEfectivo(const char *);
	void CambioDiaAnterior(const char *);
	void VentasTotales(const char *);
	void CalculandoCorte(const char *);
	const char *Nombre();
	const char *Caja();
	zDenominaciones *Dinero();
	zEncabezadosCaja *EncabezadosCaja();
	zEncabezadoCaja *EncabezadoTotal();
	zGastos *Gastos();
	const char *Total();
	const char *TotalGastos();
	const char *PagoTarjeta();
	const char *Transferencias();
	const char *TotalEfectivo();
	const char *CambioDiaAnterior();
	const char *VentasTotales();
	const char *CalculandoCorte();
	
	void Actualiza(zSiscomRegistro *);
	friend bool operator==(zCaja &,zCaja &);
	
	void Gasto(zGasto *);
	zGasto *Gasto(int,int);
	
private:
	int EsElGasto(zGasto *,int,int);

};

#endif
