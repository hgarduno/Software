#include <CQSisProductoPorTipo.h>
CQSisProductoPorTipo::CQSisProductoPorTipo()
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
}
void CQSisProductoPorTipo::Producto(const char *pchrPtrProducto,
				    const char *pchrPtrIdProducto)
{
SiscomRegistro3 *lSisReg3Producto=new SiscomRegistro3;

(*lSisReg3Producto) 					<< 
new SiscomCampo3("Producto",pchrPtrProducto)		<<
new SiscomCampo3("IdProducto",pchrPtrIdProducto);
SiscomAgregaRegistro(0,lSisReg3Producto);

}
void CQSisProductoPorTipo::AgregaProducto(const char *pchrPtrCveProducto,
					  const char *pchrPtrCantidad)
{
SiscomRegistro3 *lSisReg3Producto=new SiscomRegistro3;

(*lSisReg3Producto) << 
new SiscomCampo3("CveProducto",pchrPtrCveProducto) <<
new SiscomCampo3("Cantidad",pchrPtrCantidad);
SiscomAgregaRegistro(1,lSisReg3Producto);
}
SiscomRegistro3Lst *CQSisProductoPorTipo::Productos()
{
   return RegistrosSubGrupo(0,1);
}
void CQSisProductoPorTipo::EliminaProducto(int pintNProducto)
{
   EliminaRegistroDelGrupo(0,1,pintNProducto);  
}
CQSisProductoPorTipoOp::CQSisProductoPorTipoOp(SiscomDatCom *pSisDatCom):
				SiscomOperaciones3(pSisDatCom)
{

}

void CQSisProductoPorTipoOp::ProductosAlTipoProducto(CQSisProductoPorTipo *pCQSProdPorTipo)
{
SiscomRegistro4 lSisReg4Respuesta;
SiscomEnvia("ProductosAlTipoProducto",0,pCQSProdPorTipo,&lSisReg4Respuesta);
}
