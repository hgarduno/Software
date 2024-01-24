#include <CQSisProgramacionPlacas.h>

CQSisProgramacionPlacas::CQSisProgramacionPlacas(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{

}

void CQSisProgramacionPlacas::ProgramacionPlacas(const char *pchrPtrFecha,
					 	 const char *pchrPtrFechaFin,
						 const char *pchrPtrIdExpendio,
						 SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	     pSisReg3LstRegreso,
	     "%s%s%s%s",
	     "ProgramacionPlacas",
	     pchrPtrIdExpendio,
	     pchrPtrFecha,
	     pchrPtrFechaFin);
}
void CQSisProgramacionPlacas::EntregarPlaca(const char *pchrPtrIdExpendio,
					   SiscomRegistro3 *pSisRegPlaca)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
(*pSisRegPlaca) << new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);
SiscomEnvia("EntregaPlaca",pSisRegPlaca,&lSisReg3LstRegreso);
}
