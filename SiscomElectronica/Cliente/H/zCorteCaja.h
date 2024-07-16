#ifndef __ZCORTECAJA_H__
#define __ZCORTECAJA_H__
#include <zSiscomRegistro.h>

class zCorteCaja:public zSiscomRegistro
{
 public:
	zCorteCaja();
	void CorteCaja(zSiscomRegistro *);
	void Fecha(const char *pchrPtrFecha);
	void IdCorte(const char *pchrPtrIdCorte);
	void Transferencias(const char *pchrPtrTranferencias);	
	void Tarjeta(const char *pchrPtrTranferencias);	
	void DineroEntroCaja(const char *pchrPtrTranferencias);	
	void Gastos(const char *pchrPtrTranferencias);	
	void Cajas(const char *pchrPtrTranferencias);	
	void IdEstado(const char *pchrPtrTranferencias);	

	const char *DineroEntroCaja();
	const char *Transferencias();
};
#endif
