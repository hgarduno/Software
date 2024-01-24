#include <CQSisProductos4.h>
#include <ProductosE.h>
CQSisProducto4::CQSisProducto4(SiscomRegistro3 *pSisReg3Expendio,
			       SiscomRegistro3 *pSisReg3Producto)
{
  SiscomAgregaRegistro();
  SiscomAgregaSubRegistro();
  SiscomAgregaSubRegistro();
  SiscomAgregaRegistro(0,pSisReg3Expendio);
  SiscomAgregaRegistro(1,pSisReg3Producto);
}

CQSisProducto4::CQSisProducto4()
{
  SiscomAgregaRegistro();
  SiscomAgregaSubRegistro();
  SiscomAgregaSubRegistro();

}
CQSisProducto4::CQSisProducto4(const char *pchrPtrIdExpendio)
{
  SiscomAgregaRegistro();
  SiscomAgregaSubRegistro(); //Expendio
  SiscomAgregaSubRegistro(); //Motivo Salida
  SiscomAgregaSubRegistro(); //Productos
  SiscomAgregaRegistro(0,Expendio(pchrPtrIdExpendio));
}
void CQSisProducto4::AgregaProducto(ProductoE *pProducto)
{
SiscomAgregaRegistro(2,Producto(pProducto));
}
void CQSisProducto4::Expendio(SiscomRegistro3 *pSisReg3Expendio)
{
   SiscomAgregaRegistro(0,pSisReg3Expendio);
}
void CQSisProducto4::Producto(SiscomRegistro3 *pSisReg3Expendio)
{
  SiscomAgregaRegistro(1,pSisReg3Expendio);
}
SiscomRegistro3 *CQSisProducto4::Expendio(const char *pchrPtrIdExpendio)
{
SiscomRegistro3 *lSisReg3Expendio=new SiscomRegistro3;
(*lSisReg3Expendio) <<
new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);
return lSisReg3Expendio;
}
SiscomRegistro3 *CQSisProducto4::Producto(ProductoE *pProductoE)
{
SiscomRegistro3 *lSisReg3Producto=new SiscomRegistro3;
(*lSisReg3Producto)	<<
new SiscomCampo3("Clave",(*pProductoE)["CveProducto"])	<<
new SiscomCampo3("Cantidad",(*pProductoE)["Cantidad"]);
return lSisReg3Producto;
}
void CQSisProducto4::MotivoSalida(SiscomRegistro3 *pSisReg3Motivo)
{
SiscomAgregaRegistro(1,pSisReg3Motivo);
}
