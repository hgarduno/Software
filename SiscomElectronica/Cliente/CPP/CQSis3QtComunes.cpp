#include <CQSis3QtComunes.h>
#include <CQSisCorteCaja.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomParametroConsulta3.h>
#include <stdlib.h>

CQSis3QtComunes::CQSis3QtComunes(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{


}
const char *CQSis3QtComunes::ObtenCambio(const char *pchrPtrImporte,
				  const char *pchrPtrRecibo,
				  int *pintPtrImporteValido)
{
SiscomRegistro3Lst lSRegistro3LstCns;
SiscomRegistro3Lst lSRegistro3LstReg;
lSRegistro3LstCns				<<
new SiscomParametroConsulta3("CalculaCambio")	<<
new SiscomParametroConsulta3(pchrPtrImporte)	<<
new SiscomParametroConsulta3(pchrPtrRecibo);

SiscomEnvia("ConsultasSiscomElectronica2",
	    &lSRegistro3LstCns,
	    &lSRegistro3LstReg);
*pintPtrImporteValido=atoi(lSRegistro3LstReg["ImporteValido"]);
return lSRegistro3LstReg["Cambio"];

}
void CQSis3QtComunes::ImporteDenominaciones(const char *pchrPtrDenominacion,
					    const char *pchrPtrCantidad,
					    SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstRegreso,
	    "%s%s%s",
	    "ImporteDenominacion",
	    pchrPtrDenominacion,
	    pchrPtrCantidad);
}
void CQSis3QtComunes::CajasRegistradas(const char *pchrPtrIdExpendio,
				       SiscomRegistro3Lst *pSisReg3Cajas)
{

SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3Cajas,
	    "%s%s",
	    "CajasRegistradas",
	    pchrPtrIdExpendio);
}

void CQSis3QtComunes::AgregaCveNueva(const char *pchrPtrIdExpendio,
				      const char *pchrPtrCveNueva,
					     SiscomRegistro3 *pSisReg3Producto)
{
 (*pSisReg3Producto) <<
 new SiscomCampo3("CveNueva",pchrPtrCveNueva) <<
 new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);

}
void CQSis3QtComunes::CambiaClave(const char *pchrPtrIdExpendio,
				  const char *pchrPtrCveNueva,
				  SiscomRegistro3 *pSisReg3Producto,
				  SiscomRegistro3Lst *pSisReg3LstRegreso)
{
    AgregaCveNueva(pchrPtrIdExpendio,
    		   pchrPtrCveNueva,
			   pSisReg3Producto);

    SiscomEnvia("CambiaClave",
    		pSisReg3Producto,
		pSisReg3LstRegreso);
}

void CQSis3QtComunes::EliminaProducto(const char *pchrPtrIdExpendio,
			     SiscomRegistro3 *pSisReg3Producto,
			     SiscomRegistro3Lst *pSisReg3LstRegreso)
{

 (*pSisReg3Producto) << new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);
 SiscomEnvia("EliminaProducto",
 	      pSisReg3Producto,
	      pSisReg3LstRegreso);
}
void CQSis3QtComunes::InventariosProgramados(
			const char *pchrPtrIdExpendio,
			SiscomRegistro3Lst *pSisReg3LstInventarios)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstInventarios,
	    "%s%s",
	    "InventariosProgramados",
	    pchrPtrIdExpendio);
}
