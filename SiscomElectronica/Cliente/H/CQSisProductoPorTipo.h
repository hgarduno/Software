#ifndef __CQSISPRODUCTOPORTIPO_H__
#define __CQSISPRODUCTOPORTIPO_H__
#include <SiscomRegistros4.h>
#include <SiscomOperaciones3.h>

class CQSisProductoPorTipo:public SiscomRegistro4
{
public:
	CQSisProductoPorTipo();
	void Producto(const char *pchrPtrProducto,const char *pchrPtrIdProducto);
	void AgregaProducto(const char *pchrPtrCveProducto,const char *pchrPtrCantidad);
	SiscomRegistro3Lst *Productos();
	void EliminaProducto(int pintNProducto);
private:
};

class CQSisProductoPorTipoOp:public SiscomOperaciones3
{
public:
	CQSisProductoPorTipoOp(SiscomDatCom *pSisDatCom);
	void ProductosAlTipoProducto(CQSisProductoPorTipo *);
};
#endif
