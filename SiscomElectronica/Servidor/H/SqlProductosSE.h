#ifndef __SQLSQLPRODUCTOSSE_H__
#define __SQLSQLPRODUCTOSSE_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlDefinicionProductoSE(SiscomOperaciones *pSiscomOpePtrDato);
int SqlTiposProductoSE(SiscomOperaciones *pSiscomOpePtrDato);
int SqlProductosSiscomElectronica(SiscomOperaciones *pSiscomOpePtrDato);
int SqlProductosSimilares(SiscomOperaciones *pSiscomOpePtrDato);
int SqlProductosSE(SiscomOperaciones *pSiscomPtrDato);
int SqlDefinicionProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto,
			  SiscomOperaciones *pSiscomOpePtrDato);
#endif
