#ifndef __CQSISGANANCIAS_H__
#define __CQSISGANANCIAS_H__
#include <SiscomOperaciones3.h>

class CQSisGanando:public SiscomOperaciones3
{
public:
	CQSisGanando(SiscomDatCom *);
	void GananciasPeriodo(const char *pchrPtrIdExpendio,
			     const char *pchrPtrFechaInicio,
			     const char *pchrPtrFechaFin,
			     SiscomRegistro3Lst *pSisReg3Resumen,
			     SiscomRegistro3Lst *pSisReg3GProducto,
			     SiscomRegistro3Lst *pSisReg3GFecha);
			
};

#endif
