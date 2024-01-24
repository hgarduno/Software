#ifndef __CQSISPEDIDOMATERIAL_H__
#define __CQSISPEDIDOMATERIAL_H__

#include <SiscomRegistros4.h>
#include <SiscomOperaciones3.h>


class SiscomRegistro3Lst;
class CQSisPedidoMaterial:public SiscomRegistro4
{

public:
	CQSisPedidoMaterial();
	CQSisPedidoMaterial(const char *pchrPtrIdExpendio,
			    const char *pchrPtrIdPedido,
			    SiscomRegistro3Lst *pSisReg3LstProductos);  
	void Expendio(const char *pchrPtrIdExpendio);
	void AgregaProducto(const char *pchrPtrCveProducto,
			    const char *pchrPtrCantidad,
			    const char *pchrPtrObservaciones);
	void Observaciones(const char *pchrPtrObservaciones);
	const char *IdPedido(int pintNumeroPedido);
	const char *CveProducto(int pintNumeroPedido,int pintNProducto);
	const char *IdProducto(int pintNumeroPedido,int pintNProducto);
	const char *Cantidad(int pintNumeroPedido,int pintNProducto);
	const char *IdEstado(int pintNumeroPedido);
	const char *Observaciones(int pintNumeroPedido);
	void EliminaProducto(int pintNRegistro,int pintProducto);
	void Cantidad(int pintPedido,int pintProducto,const char *pchrPtrCantidad);
	SiscomRegistro3Lst *Productos(int pintPedido);
};

class CQSisPedidoMaterialOp:public SiscomOperaciones3
{
public:
	CQSisPedidoMaterialOp(SiscomDatCom *pSisDatCom);
	void PedidosExpendios(const char *pchrPtrFechaInicio,
			      const char *pchrPtrFechaFin,
			      const char *pchrPtrIdExpendio,
			      CQSisPedidoMaterial *pCQSPedidoMaterial);
	SiscomRegistro3 *Registra(CQSisPedidoMaterial *pCQSPedidoMaterial);
	void PedidosExpendios(CQSisPedidoMaterial *pCQSPedidoMaterial,
			      const char *pchrPtrFechaIni,
			      const char *pchrPtrFechaFin);
	void ActualizaEstadoPedido(const char *pchrPtrIdPedido,const char *pchrPtrEstado);
	void ActualizaCantidadProducto(const char *pchrPtrIdPedido,
				       const char *pchrPtrIdProducto,
				     const char *pchrPtrProducto,
				     const char *pchrPtrCantidad);

	int ValidaExistenciaExpendio(const char *pchrPtrIdExpendio,
				     const char *pchrPtrCveProducto,
				     const char *pchrPtrCantidad);
	void RecibePedidoMaterial(const char *pchrPtrIdExpendio,
				  const char *pchrPtrIdPedido,
				  SiscomRegistro3Lst *pSisReg3LstProductos);
	int PedidosPendientesPorEnviaAMatriz(const char *pchrPtrFechaIni,
					     const char *pchrPtrFechaFin,
					     SiscomRegistro3Lst *pSisReg3LstRegreso);
	int EnviaPedidoPendientePorEnviarAMatriz(SiscomRegistro3 *pSisReg3Pedido);
	int DetallePedidoPendientePorEnviarAMatriz(const char *pchrPtrIdPedido,
						  SiscomRegistro3Lst *pSisReg3LstRegreso);
};
#endif
