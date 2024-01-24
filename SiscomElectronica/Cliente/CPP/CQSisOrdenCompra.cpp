#include <CQSisOrdenCompra.h>
#include <SiscomRegistros4.h>

CQSisComprasProducto::CQSisComprasProducto()
{


}

const char *CQSisComprasProducto::PrecioVenta()
{
   return CampoRegistroPrincipal("PrecioVenta");
}

const char *CQSisComprasProducto::Existencia()
{
   return CampoRegistroPrincipal("Existencia");
}

const char *CQSisComprasProducto::ExBodegas()
{
   return CampoRegistroPrincipal("ExBodegas");
}

const char *CQSisComprasProducto::Transferencias()
{
   return CampoRegistroPrincipal("TotalTransferencias");
}
const char *CQSisComprasProducto::ComprasSemAnterior()
{
   return CampoRegistroPrincipal("ComprasSemAnterior");
}
const char *CQSisComprasProducto::VentasSemAnterior()
{
   return CampoRegistroPrincipal("VentasSemAnterior");
}
const char *CQSisComprasProducto::ComprasSemActual()
{
   return CampoRegistroPrincipal("ComprasSemActual");
}
const char *CQSisComprasProducto::VentasSemActual()
{
   return CampoRegistroPrincipal("VentasSemActual");
}
SiscomRegistro3Lst *CQSisComprasProducto::HistoricoCompras()
{
   return RegistrosSubGrupo(0,1);
}

SiscomRegistro3Lst *CQSisComprasProducto::TransferenciasExpendios()
{
   return RegistrosSubGrupo(0,2);
}

SiscomRegistro3 *CQSisComprasProducto::DiaCompra(int pintDia)
{
 return RegistroSubGrupo(0,1,pintDia);
}
CQSisOrdenCompra2::CQSisOrdenCompra2()
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
}
void CQSisOrdenCompra2::Producto(SiscomRegistro3 *pSisReg3Producto)
{
SiscomRegistro3 *lSisReg3Producto=new SiscomRegistro3(pSisReg3Producto);
  SiscomAgregaRegistro(0,lSisReg3Producto);
}
SiscomRegistro3Lst *CQSisOrdenCompra2::Productos()
{
  return RegistrosSubGrupo(0,0);
}
CQSisOrdenCompraOp::CQSisOrdenCompraOp(SiscomDatCom *pSisDatCom):
				SiscomOperaciones3(pSisDatCom)
{


}
void CQSisOrdenCompraOp::ComprasProducto(const char *pchrPtrIdExpendio,
					const char *pchrPtrCveProducto,
					CQSisComprasProducto *pCQSComprasProducto)
{
SiscomEnvia2("DatosComprasProducto",
	      pCQSComprasProducto,
	      "%s [IdExpendio] %s [CveProducto] ",
	      pchrPtrIdExpendio,
	      pchrPtrCveProducto);
}
