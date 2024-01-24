#include <CQSisCajas.h>

CQSisCaja::CQSisCaja(const char *pchrPtrIdCaja,
		       const char *pchrPtrDireccionIp,
		       const char *pchrPtrDescripcion,
		       const char *pchrPtrImporte,
		       const char *pchrPtrIdExpendio)
{
	(*this)							<<
	new SiscomCampo3("IdCaja",pchrPtrIdCaja)		<<
	new SiscomCampo3("DireccionIp",pchrPtrDireccionIp)	<<
	new SiscomCampo3("Descripcion",pchrPtrDescripcion)	<<
	new SiscomCampo3("Importe",pchrPtrImporte)		<<
	new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);

}

CQSisOpCajas::CQSisOpCajas(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{

}

void CQSisOpCajas::RegistraImporteCaja(CQSisCaja *pCQSCaja)
{
SiscomRegistro3Lst lSReg3Caja;
SiscomRegistro3Lst lSReg3Respuesta;
lSReg3Caja << pCQSCaja;
SiscomEnvia("RegistraImporteCaja",
	    &lSReg3Caja,
	    &lSReg3Respuesta);
}
