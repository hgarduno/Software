#ifndef __ZCORTECAJA_H__
#define __ZCORTECAJA_H__
#include <zSiscomRegistro.h>

#include <zCajas.h>
class zCorteCaja:public zSiscomRegistro
{
 public:
	zCorteCaja();
	void CorteCaja(zSiscomRegistro *);
	void FechaInicio(const char *pchrPtrFecha);
	void FechaFin(const char *pchrPtrFecha);
	void IdCorte(const char *pchrPtrIdCorte);
	void Transferencias(const char *pchrPtrTranferencias);	
	void Tarjeta(const char *pchrPtrTranferencias);	
	void DineroEntroCaja(const char *pchrPtrTranferencias);	
	void Cajas(const char *pchrPtrTranferencias);	
	void IdEstado(const char *pchrPtrTranferencias);	
	void CambioDiaAnterior(const char *pchrPtrTranferencias);	
	void VentasTotales(const char *pchrPtrVentasTotales);
	void CalculandoCorte(const char *pchrPtrCalculandoCorte);
	void TotalGastos(const char *pchrPtrTotalGastos);
	void EdoCuentaCambio(const char *pchrPtrEdoCuentaCambio);

	void Cajas(zCajas *);

	const char *DineroEntroCaja();
	const char *Transferencias();
	const char *VentasTotales();
	const char *CalculandoCorte();
	const char *TotalGastos();
	const char *CambioDiaAnterior();
	const char *EdoCuentaCambio();
	const char *Corte();

	int EdoCuentaCambioInt();

	zCajas *Cajas();
};
#endif
