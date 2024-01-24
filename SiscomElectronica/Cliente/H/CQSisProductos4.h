#ifndef __CQSISPRODUCTOS4_H__
#define __CQSISPRODUCTOS4_H__


#include <SiscomRegistros4.h>


class ProductoE;
class CQSisProducto4:public SiscomRegistro4
{
public:
	CQSisProducto4(SiscomRegistro3 *pSisReg3Expendio,
		       SiscomRegistro3 *pSisReg3Producto);
	CQSisProducto4();

	CQSisProducto4(const char *pchrPtrIdExpendio);
	void AgregaProducto(ProductoE *pProductoE);
	void MotivoSalida(SiscomRegistro3 *pSisReg3Motivo);

	void Expendio(SiscomRegistro3 *pSisReg3Expendio);
	void Producto(SiscomRegistro3 *pSisReg3Producto);
private:
	SiscomRegistro3 *Expendio(const char *pchrPtrIdExpendio);
	SiscomRegistro3 *Producto(ProductoE *);
};

#endif
