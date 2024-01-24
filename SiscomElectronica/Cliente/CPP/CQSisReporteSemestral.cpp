#include <CQSisReporteSemestral.h>
CQSisReporteSemestral::CQSisReporteSemestral(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{


}
void CQSisReporteSemestral::ReporteSemestral(const char *pchrPtrFInicio,
					     const char *pchrPtrFFin,
					     const char *pchrPtrExpendio,
					     SiscomRegistro3Lst *pSisReg3LstRegreso)
{
pSisReg3LstRegreso->clear();
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstRegreso,
	    "%s%s%s%s",
	    "ReporteSemestral",
	    pchrPtrExpendio,
	    pchrPtrFInicio,
	    pchrPtrFFin);


}
