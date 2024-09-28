#include <CQSisPedidoMaterial.h>
#include <zSiscomDesarrollo4.h>
#include <SiscomDesarrollo3Qt++.h>
#include <string.h>

CQSisPedidoMaterial::CQSisPedidoMaterial(const char *pchrPtrIdExpendio,
					 const char *pchrPtrIdPedido,
					 SiscomRegistro3Lst *pSisReg3LstProductos)
{
SiscomRegistro3 *lSisReg3Envio=new SiscomRegistro3;
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();

(*lSisReg3Envio) 					<< 
new SiscomCampo3("IdExpendio",pchrPtrIdExpendio) 	<<
new SiscomCampo3("IdPedido",pchrPtrIdPedido);
SiscomAgregaRegistro(0,lSisReg3Envio);
SiscomAgregaRegistros(1,pSisReg3LstProductos);
}
CQSisPedidoMaterial::CQSisPedidoMaterial()
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
}
void CQSisPedidoMaterial::Expendio(const char *pchrPtrIdExpendio)
{
SiscomRegistro3 *lSisReg3Expendio=new SiscomRegistro3;

     (*lSisReg3Expendio) << new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);
SiscomAgregaRegistro(0,lSisReg3Expendio);
}

void CQSisPedidoMaterial::AgregaProducto(const char *pchrPtrCveProducto,
					 const char *pchrPtrCantidad,
					 const char *pchrPtrObservaciones)
{
SiscomRegistro3 *lSisReg3Producto=new SiscomRegistro3;

     (*lSisReg3Producto) 					<< 
     new SiscomCampo3("CveProducto",pchrPtrCveProducto) <<
     new SiscomCampo3("Cantidad",pchrPtrCantidad)	<<
     new SiscomCampo3("Observaciones",pchrPtrObservaciones);
    SiscomAgregaRegistro(1,lSisReg3Producto);
}
void CQSisPedidoMaterial::Observaciones(const char *pchrPtrObservaciones)
{
{
SiscomRegistro3 *lSisReg3Observaciones=new SiscomRegistro3;
     (*lSisReg3Observaciones) << new SiscomCampo3("Observaciones",pchrPtrObservaciones);
SiscomAgregaRegistro(0,lSisReg3Observaciones);
}
}

const char *CQSisPedidoMaterial::IdPedido(int pintNumeroPedido)
{
return CampoRegistroPrincipal(pintNumeroPedido,"idpedido");
}
const char *CQSisPedidoMaterial::IdEstado(int pintNumeroPedido)
{
  return CampoRegistroPrincipal(pintNumeroPedido,"idestado");
}
const char *CQSisPedidoMaterial::Observaciones(int pintNumeroPedido)
{
  return CampoRegistroPrincipal(pintNumeroPedido,"observaciones");
}
const char *CQSisPedidoMaterial::CveProducto(int pintNumeroPedido,
					     int pintNumeroProducto)
{
return CampoRegistroSubGrupo(pintNumeroPedido,
			     1,
			     pintNumeroProducto,
			     "cveproducto");
}
void CQSisPedidoMaterial::Cantidad(int pintNumeroPedido,
				   int pintNumeroProducto,
				   const char *pchrPtrCantidad)
{
 SiscomActualizaCampoSubRegistro(pintNumeroPedido,
 				 1,
				 pintNumeroProducto,
				 "cantidad",
				 pchrPtrCantidad);
}
void CQSisPedidoMaterial::Observaciones(int pintNumeroPedido,
				   int pintNumeroProducto,
				   const char *pchrPtrObservaciones)
{
SiscomEscribeLog3Qt("00000");
 SiscomActualizaCampoSubRegistro(pintNumeroPedido,
 				 1,
				 pintNumeroProducto,
				 "observaciones",
				 pchrPtrObservaciones);
}

const char *CQSisPedidoMaterial::IdProducto(int pintNumeroPedido,
					     int pintNumeroProducto)
{
return CampoRegistroSubGrupo(pintNumeroPedido,
			     1,
			     pintNumeroProducto,
			     "idproducto");
}

const char *CQSisPedidoMaterial::Cantidad(int pintPedido,int pintProducto)
{

return CampoRegistroSubGrupo(pintPedido,
			     1,
			     pintProducto,
			     "cantidad");
}
void CQSisPedidoMaterial::EliminaProducto(int pintNRegistro,
					  int pintProducto)
{
   EliminaRegistroDelGrupo(pintNRegistro,1,pintProducto);
}
SiscomRegistro3Lst *CQSisPedidoMaterial::Productos(int pintPedido)
{
   return RegistrosSubGrupo(pintPedido,1);
}
CQSisPedidoMaterialOp::CQSisPedidoMaterialOp(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{


}

SiscomRegistro3 *CQSisPedidoMaterialOp::Registra(CQSisPedidoMaterial *pCQSPedidoMaterial)
{
SiscomRegistro4 lSisReg4Regreso;
SiscomEnvia("RegistraPedidoMaterial",
	     0,
	     pCQSPedidoMaterial,
	     &lSisReg4Regreso);
SiscomContenidoRegistro4Log(&lSisReg4Regreso);
return lSisReg4Regreso.RegistroPrincipal();
}

void CQSisPedidoMaterialOp::PedidosExpendios(const char *pchrPtrFechaInicio,
					     const char *pchrPtrFechaFin,
					     const char *pchrPtrIdExpendio,
					     CQSisPedidoMaterial *pCQSPedidoMaterial)
{
SiscomEnvia2("PedidosExpendios",
	    pCQSPedidoMaterial,
	    "%s[FechaInicio] %s[FechaFin]",
	     pchrPtrFechaInicio,
	     pchrPtrFechaFin);
}

void CQSisPedidoMaterialOp::ActualizaEstadoPedido(const char *pchrPtrIdPedido,
						  const char *pchrPtrEstado)
{
SiscomRegistro3Lst lSisReg3LstRespuesta;

SiscomEnvia2("ActualizaEstadoPedidoMaterial",
	     &lSisReg3LstRespuesta,
	     "%s[IdPedido] %s[IdEstado]",
	     pchrPtrIdPedido,
	     pchrPtrEstado);
}

void CQSisPedidoMaterialOp::ActualizaCantidadProducto(const char *pchrPtrIdPedido,
						  const char *pchrPtrIdProducto,
						  const char *pchrPtrCveProducto,
						  const char *pchrPtrCantidad)
{
SiscomRegistro3Lst lSisReg3LstRespuesta;
SiscomEnvia2("ActualizaCantidadProductoPedido",
	     &lSisReg3LstRespuesta,
	     "%s[IdPedido] %s[CveProducto] %s[Cantidad] %s[IdProducto]",
	     pchrPtrIdPedido,
	     pchrPtrCveProducto,
	     pchrPtrCantidad,
	     pchrPtrIdProducto);
}

int CQSisPedidoMaterialOp::ValidaExistenciaExpendio(const char *pchrPtrIdExpendio,
						    const char *pchrPtrCveProducto,
						    const char *pchrPtrCantidad)
{
SiscomRegistro3Lst lSisReg3LstRespuesta;
SiscomRegistro3 *lSisReg3Regreso;
SiscomEnvia2("ValidaExistenciaExpendio",
	     &lSisReg3LstRespuesta,
	     "%s [IdExpendio] %s[CveProducto] %s[Cantidad] ",
	     pchrPtrIdExpendio,
	     pchrPtrCveProducto,
	     pchrPtrCantidad);
if((lSisReg3Regreso=lSisReg3LstRespuesta.first()))
   return !strcmp((*lSisReg3Regreso)["EdoValidacion"],"1");
else
return 0;

}

void CQSisPedidoMaterialOp::RecibePedidoMaterial(const char *pchrPtrIdExpendio,
						 const char *pchrPtrIdPedido,
						 SiscomRegistro3Lst *pSisReg3LstProductos)
{
SiscomRegistro4 lSisReg4Respuesta;
CQSisPedidoMaterial lCQSPedidoMaterial(pchrPtrIdExpendio,
				  pchrPtrIdPedido,
				  pSisReg3LstProductos);
SiscomEnvia("RecibePedido",
	    0,
	    &lCQSPedidoMaterial,
	    &lSisReg4Respuesta);
}



int CQSisPedidoMaterialOp::PedidosPendientesPorEnviaAMatriz(const char *pchrPtrFechaInicio,
							    const char *pchrPtrFechaFin,
							    SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia("PedidosPendientesPorEnviarAMatriz",
	    pSisReg3LstRegreso,
	    "%s [FechaInicio] %s[FechaFin]",
	    pchrPtrFechaInicio,
	    pchrPtrFechaFin);
}
int CQSisPedidoMaterialOp::DetallePedidoPendientePorEnviarAMatriz(const char *pchrPtrIdPedido,
							    SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia("DetallePedidoPendientePorEnviarAMatriz",
	    pSisReg3LstRegreso,
	    "%s [IdPedido] ",
	    pchrPtrIdPedido);
}
int CQSisPedidoMaterialOp::EnviaPedidoPendientePorEnviarAMatriz(SiscomRegistro3 *pSisReg3Pedido)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
SiscomEnvia("EnviaPedidoPendientePorEnviarAMatriz",
	     pSisReg3Pedido,
	     &lSisReg3LstRegreso);
}
