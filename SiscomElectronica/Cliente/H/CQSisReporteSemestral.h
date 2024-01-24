#ifndef __CQSISREPORTESEMESTRAL_H__
#define __CQSISREPORTESEMESTRAL_H__
#include <SiscomOperaciones3.h>
#include <SiscomRegistros3.h>

class CQSisReporteSemestral:public SiscomOperaciones3
{
public:
	CQSisReporteSemestral(SiscomDatCom *);
	void ReporteSemestral(const char *pchrPtrFInicio,
			      const char *pchrPtrFFin,
			      const char *pchrPtrExpendio,
			      SiscomRegistro3Lst *pSisReg3LstRegreso);
};
#endif
