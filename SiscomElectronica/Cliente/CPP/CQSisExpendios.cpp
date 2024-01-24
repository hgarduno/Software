#include <CQSisExpendios.h>
CQSisExpendio::CQSisExpendio(const char *pchrPtrIdExpendioReg,
			    const char *pchrPtrIdExpendio,
			    const char *pchrPtrRazonSocial,
			    const char *pchrPtrRFC,
			    const char *pchrPtrDireccionIp,
			    const char *pchrPtrPuerto,
			    const char *pchrPtrBase)
{

(*this)  						<<
new SiscomCampo3("IdExpendio",pchrPtrIdExpendioReg)	<<
new SiscomCampo3("ExpendioId",pchrPtrIdExpendio)		<<
new SiscomCampo3("RazonSocial",pchrPtrRazonSocial)		<<
new SiscomCampo3("RFC",pchrPtrRFC)				<<
new SiscomCampo3("DireccionIp",pchrPtrDireccionIp)		<<
new SiscomCampo3("Puerto",pchrPtrPuerto)			<<
new SiscomCampo3("Base",pchrPtrBase);
}


CQSisOpExpendio::CQSisOpExpendio(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{

}
void CQSisOpExpendio::Registra(CQSisExpendio *pCQSisExpendio,
			       SiscomRegistro3Lst *pSisReg3LstEdoReg)
{
SiscomRegistro3Lst lSisReg3LstEnvio;
lSisReg3LstEnvio << pCQSisExpendio;

SiscomEnvia("RegistroExpendio",
	    &lSisReg3LstEnvio,
	    pSisReg3LstEdoReg);
}

void CQSisOpExpendio::Actualiza(CQSisExpendio *pCQSisExpendio,
				SiscomRegistro3Lst *pSisReg3LstEdoReg)
{
SiscomRegistro3Lst lSisReg3LstEnvio;
lSisReg3LstEnvio << pCQSisExpendio;

SiscomEnvia("ActualizaDatosExpendio",
	    &lSisReg3LstEnvio,
	    pSisReg3LstEdoReg);

}
void CQSisOpExpendio::Inicia(const char *pchrPtrIdExpendio,
			     SiscomRegistro3 *pSisReg3Expendio,
			     SiscomRegistro3Lst *pSisReg3LstEdoReg)
{
SiscomRegistro3Lst lSisReg3LstEnvio;
(*pSisReg3Expendio) << new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);
lSisReg3LstEnvio << pSisReg3Expendio;
SiscomEnvia("IniciaDatosExpendio",
	    &lSisReg3LstEnvio,
	    pSisReg3LstEdoReg);
}
