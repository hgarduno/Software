#ifndef __CQSISPRODBODEXPENDIO_H__
#define __CQSISPRODBODEXPENDIO_H__
#include <SiscomRegistros3.h>

class SiscomRegistro3;
class CQSisProdBodExpendio:public SiscomRegistro3
{
public:
	CQSisProdBodExpendio(const char *pchrPtrCantidad,
			     const char *pchrPtrIdExpendioFisico,
			     const char *pchrPtrIdEmpleado,
			     SiscomRegistro3 *pSisReg3Producto,
			     SiscomRegistro3 *pSisReg3Expendio,
			     SiscomRegistro3 *pSisReg3Bodega);

};

#endif
