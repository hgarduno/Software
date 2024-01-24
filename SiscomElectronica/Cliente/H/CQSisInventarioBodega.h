#ifndef __CQSISINVENTARIOBODEGA_H__
#define __CQSISINVENTARIOBODEGA_H__
#include <SiscomRegistros3.h>
class CQSisInventarioBodega:public SiscomRegistro3
{
public:
	CQSisInventarioBodega(const char *pchrPtrIdExpendio,
			      const char *pchrPtrIdEmpleado,
			      const char *pchrPtrCantidad,
			      SiscomRegistro3 *pSisReg3Bodega,
			      SiscomRegistro3 *pSisRegProdBodega);
			      

};

#endif
