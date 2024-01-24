#include <CQSisCorteCaja.h>
CQSisCorteCaja::CQSisCorteCaja(const char *pchrPtrIdCaja,
			       const char *pchrPtrFechaHora,
			       const char *pchrPtrImporte,
			       const char *pchrPtrDenominacion,
			       const char *pchrPtrCantidad,
			       const char *pchrPtrIdEmpleado,
			       const char *pchrPtrImporteActualCaja,
			       const char *pchrPtrIdExpendio,
			       const char *pchrPtrIdReporte)
{
	(*this)								<<
	new SiscomCampo3("IdCaja",pchrPtrIdCaja)			<<
	new SiscomCampo3("FechaHora",pchrPtrFechaHora)			<<
	new SiscomCampo3("Importe",pchrPtrImporte)			<<
	new SiscomCampo3("Denominacion",pchrPtrDenominacion)		<<
	new SiscomCampo3("Cantidad",pchrPtrCantidad)			<<
	new SiscomCampo3("IdEmpleado",pchrPtrIdEmpleado)		<<
	new SiscomCampo3("Total","")					<<
	new SiscomCampo3("ImporteActualCaja",pchrPtrImporteActualCaja)	<<
	new SiscomCampo3("IdExpendio",pchrPtrIdExpendio)		<<
	new SiscomCampo3("IdReporte",pchrPtrIdReporte)			<<
	new SiscomCampo3("RestoEnCaja","");
}
CQSisOpCorteCaja::CQSisOpCorteCaja(SiscomDatCom *pSisDatCom):
		   SiscomOperaciones3(pSisDatCom)
{

}
void CQSisOpCorteCaja::ImporteDenominacion(SiscomRegistro3Lst *pSisReg3LRegreso)
{
SiscomEnvia("ImporteDenominacion",
	    pSisReg3LRegreso);

}

void CQSisOpCorteCaja::RegistraCorteCaja(SiscomRegistro3Lst *pSisReg3LCorteCaja)
{
SiscomRegistro3Lst lSisReg3LRegreso;
SiscomEnvia("RegistraCorteCaja",
	    pSisReg3LCorteCaja,
	    &lSisReg3LRegreso);
}
