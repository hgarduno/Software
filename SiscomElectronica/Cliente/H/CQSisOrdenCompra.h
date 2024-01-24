#ifndef __CQSISORDENCOMPRA_H__
#define __CQSISORDENCOMPRA_H__
#include <SiscomOperaciones3.h>
#include <SiscomRegistros4.h>

class CQSisComprasProducto:public SiscomRegistro4
{
public:
	CQSisComprasProducto();
	const char *PrecioVenta();
	const char *Existencia();
	const char *ExBodegas();
	const char *Transferencias();
	const char *ComprasSemAnterior();
	const char *VentasSemAnterior();
	const char *ComprasSemActual();
	const char *VentasSemActual();
	SiscomRegistro3 *DiaCompra(int pintRegistro);
	SiscomRegistro3Lst *HistoricoCompras();
	SiscomRegistro3Lst *TransferenciasExpendios();

};

class CQSisOrdenCompra2:public SiscomRegistro4
{
public:
	CQSisOrdenCompra2();
	void Producto(SiscomRegistro3 *pSisReg3Compra);
	SiscomRegistro3Lst *Productos();

};

class CQSisOrdenCompraOp:public SiscomOperaciones3
{
public:
	CQSisOrdenCompraOp(SiscomDatCom *);
	void ComprasProducto(const char *pchrPtrIdExpendio,
			     const char *pchrPtrCveProducto,
			     CQSisComprasProducto *pCQComprasProducto);
				  


};

#endif
