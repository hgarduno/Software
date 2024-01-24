#include <CQSisEscuelas.h>
CQSisOpEscuelas::CQSisOpEscuelas(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{


}
void CQSisOpEscuelas::Escuelas(const char *pchrPtrIdExpendio,
			       SiscomRegistro3Lst *pSisReg3LstEscuelas)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstEscuelas,
	    "%s%s",
	    "EscuelasExpendio",
	    pchrPtrIdExpendio);

}
