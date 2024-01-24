#ifndef __CQSISORDENES_H__
#define __CQSISORDENES_H__
#include <SiscomOperaciones3.h>
class SiscomRegistro3;
class SiscomRegistro3Lst;
class CQSisOrdenesSiscom:public SiscomOperaciones3
{
public:
	CQSisOrdenesSiscom(SiscomDatCom *);
	void Ordenes(const char *pchrPtrIdExpendio,
		     const char *pchrPtrFechaIni,
		     const char *pchrPtrFechaFin,
		     SiscomRegistro3Lst *pSisReg3LstOrdenes);
	void DetalleOrden(const char *pchrPtrIdExpendio,
			  SiscomRegistro3 *pSisReg3Orden,
			  SiscomRegistro3Lst *pSisReg3Productos);
	void AnexarOrdenContabilidad(const char *pchrPtrIdExpendio,
				     SiscomRegistro3 *pSisReg3Orden);
};
#endif
