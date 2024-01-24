#include <CQSisPromociones.h>

CQSisPromocion::CQSisPromocion(const char *pchrPtrIdExpendio,
				const char *pchrPtrIdPromocion,
			       const char *pchrPtrNombre,
			       const char *pchrPtrFechaIni,
			       const char *pchrPtrFechaFin,
			       const char *pchrPtrPuntos,
			       const char *pchrPtrDescripcion)
{

  (*this)						<<
  new SiscomCampo3("IdExpendio",pchrPtrIdExpendio)	<<
  new SiscomCampo3("IdPromocion",pchrPtrIdPromocion)	<<
  new SiscomCampo3("Nombre",pchrPtrNombre)		<<
  new SiscomCampo3("FechaIni",pchrPtrFechaIni)		<<
  new SiscomCampo3("FechaFin",pchrPtrFechaFin)		<<
  new SiscomCampo3("Puntos",pchrPtrPuntos)		<<
  new SiscomCampo3("Descripcion",pchrPtrDescripcion);





}

CQSisOpPromocion::CQSisOpPromocion(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{


}

void CQSisOpPromocion::Registra(CQSisPromocion *pCQSPromocion,
				SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia("RegistraPromocion",
	    pCQSPromocion,
	    pSisReg3LstRegreso);
}
