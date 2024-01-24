#ifndef __CQSISEXPENDIOS_H__
#define __CQSISEXPENDIOS_H__

#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>
class CQSisExpendio:public SiscomRegistro3
{
public:
	CQSisExpendio(const char *pchrPtrIdExpendioReg,
		      const char *pchrPtrIdExpendio,
		      const char *pchrPtrRazonSocial,
		      const char *pchrPtrRFC,
		      const char *pchrPtrDireccionIp,
		      const char *pchrPtrPuerto,
		      const char *pchrPtrBase);
};

class CQSisOpExpendio:public SiscomOperaciones3
{
public:
	CQSisOpExpendio(SiscomDatCom *pSisDatCom);

	void Registra(CQSisExpendio *pCQSisExpendio,
		      SiscomRegistro3Lst *pSisReg3LstEdoReg);
	void Actualiza(CQSisExpendio *pCQSisExpendio,
		      SiscomRegistro3Lst *pSisReg3LstEdoReg);
	void Inicia(const  char *pchrPtrIdExpendio,
		    SiscomRegistro3 *pSisReg3Expendio,
		    SiscomRegistro3Lst *pSisReg3LstEdoReg);

};
#endif
