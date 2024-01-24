#ifndef __CQSISDATOSORDENCAJA_H__
#define __CQSISDATOSORDENCAJA_H__
#include <SiscomRegistros.h>

class CQSisDatosOrdenCaja:public SiscomRegistro4
{
public:
	CQSisDatosOrdenCaja(const char *pchrPtrIdExpendio);
	CQSisDatosOrdenCaja(const char *pchrPtrIdExpendio,
			    const char *pchrPtrPago,
			    const char *pchrPtrCambio,
			    SiscomRegistro3 *);
	CQSisDatosOrdenCaja *OrdenesPendientes(const char *);
private:
	SiscomRegistro3 *DatosOrdenesPendientes(const char *);
	SiscomRegistro3 *DatosPago(const char *pchrPtrPago,const char *pchrPtrCambio);
};

#endif
