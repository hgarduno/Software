#include <CQSisInventarioBodega.h>

CQSisInventarioBodega::CQSisInventarioBodega(const char *pchrPtrIdExpendio,
					     const char *pchrPtrIdEmpleado,
					     const char *pchrPtrCantidad,
					     SiscomRegistro3 *pSisReg3Bodega,
					     SiscomRegistro3 *pSisReg3ProdBodega)
{
(*this)							<<
new SiscomCampo3("IdExpendio",pchrPtrIdExpendio)	<<
new SiscomCampo3("IdEmpleado",pchrPtrIdEmpleado)	<<
new SiscomCampo3("Cantidad",pchrPtrCantidad)		<<
pSisReg3Bodega->Campo3("idbodega")			<<
pSisReg3ProdBodega->Campo3("cveproducto")		<<
pSisReg3ProdBodega->Campo3("existencia");
}
