#ifndef __ZCREDITO_H__
#define __ZCREDITO_H__
#include <zSiscomRegistro.h>

class zCredito:public zSiscomRegistro
{
public:
	zCredito();
	void IdVenta(const unsigned char *pchrPtrIdVenta);
	void IdFinanciadora(const unsigned char *pchrPtrIdFinanciadora);
	void IdPlazo(const unsigned char *pchrPtrIdPlazo);
	void Tasa(const unsigned char *pchrPtrTasa);
	void PagoQuincenal(const unsigned char *pchrPtrPagoQuincenal);
	void PagoTotal(const unsigned char *pchrPtrPagoTotal);
	void NumeroPagos(const unsigned char *pchrPtrNumeroPagos);
};

#endif
