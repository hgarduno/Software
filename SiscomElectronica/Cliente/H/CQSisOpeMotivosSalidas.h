#ifndef __CQSISOPEMOTIVOSSALIDAS_H__
#define __CQSISOPEMOTIVOSSALIDAS_H__
#include <SiscomOperaciones3.h>
class CQSisMotivosSalidas;
class CQSisDatosMotivosSalidas;
class CQSisOpeMotivosSalidas:public SiscomOperaciones3
{
public:
	CQSisOpeMotivosSalidas(SiscomDatCom *pSisDatCom);
	void Motivos(CQSisDatosMotivosSalidas *,
		     CQSisMotivosSalidas *pCQSMSalidas);

};
#endif
