#ifndef __CQSISCORTECAJA_H__
#define __CQSISCORTECAJA_H__
#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>

class CQSisCorteCaja:public SiscomRegistro3
{
public:
	CQSisCorteCaja(const char *pchrPtrIdCaja,
		       const char *pchrPtrFechaHora,
		       const char *pchrPtrImporte,
		       const char *pchrPtrDenominacion,
		       const char *pchrPtrCantidad,
		       const char *pchrPtrIdEmpleado,
		       const char *pchrPtrImporteActualCaja,
		       const char *pchrPtrIdExpendio,
		       const char *pchrPtrIdReporte);
};

class CQSisOpCorteCaja:public SiscomOperaciones3
{
public:
	CQSisOpCorteCaja(SiscomDatCom *);
	void ImporteDenominacion(SiscomRegistro3Lst *);
	void RegistraCorteCaja(SiscomRegistro3Lst *);
};
#endif
