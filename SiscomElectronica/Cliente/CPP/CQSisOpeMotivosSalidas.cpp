#include <CQSisOpeMotivosSalidas.h>
#include <CQSisMotivosSalidas.h>
#include <CQSisDatosMotivosSalidas.h>
CQSisOpeMotivosSalidas::CQSisOpeMotivosSalidas(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{

}

void CQSisOpeMotivosSalidas::Motivos(CQSisDatosMotivosSalidas *pCQSDMSalidas,
				CQSisMotivosSalidas *pCQSMSalidas)
{
pCQSMSalidas->SiscomLimpia();
SiscomEnvia("MotivosSalidas",
	    0,
	    pCQSDMSalidas,
	    pCQSMSalidas);

}
