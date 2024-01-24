#include <CQSisProdBodExpendio.h>
CQSisProdBodExpendio::CQSisProdBodExpendio(const char *pchrPtrCantidad,
					   const char *pchrPtrIdExpFis,
					   const char *pchrPtrIdEmpleado,
					   SiscomRegistro3 *pSisReg3Producto,
					   SiscomRegistro3 *pSisReg3Expendio,
					   SiscomRegistro3 *pSisReg3Bodega)
{
  (*this) 							<< 
  new SiscomCampo3("Cantidad",pchrPtrCantidad)  		<<
  new SiscomCampo3("IdExpendio",pchrPtrIdExpFis)		<<
  new SiscomCampo3("IdEmpleado",pchrPtrIdEmpleado)		<<
  pSisReg3Bodega->Campo3("idbodega")				<<
  pSisReg3Producto->Campo3("cveproducto")			<<
  pSisReg3Producto->Campo3("existencia")			<<
  pSisReg3Expendio->Campo3("idempresa");
  /*
  (*this)+=pSisReg3Expendio;
  (*this)+=pSisReg3Producto;
  (*this)+=pSisReg3Bodega;
  */

}
