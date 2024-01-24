#include <CQSisHisTransferencias.h>

CQSisHisTransferencias::CQSisHisTransferencias(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{

}

void CQSisHisTransferencias::MaterialTransferido(const char *pchrPtrFecha,
					 	 const char *pchrPtrFechaFin,
						 const char *pchrPtrIdExpendio,
						 const char *pchrPtrIdExpendioAConsultar,
						 SiscomRegistro3Lst *pSisReg3LstRegreso)
{

SiscomEnvia("ConsultasSiscomElectronica2",
	     pSisReg3LstRegreso,
	     "%s%s%s%s%s",
	     "Transferencias",
	     pchrPtrIdExpendio,
	     pchrPtrFecha,
	     pchrPtrFechaFin,
	     pchrPtrIdExpendioAConsultar);
}
