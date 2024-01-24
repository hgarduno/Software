#ifndef __CQSISESCUELAS_H__
#define __CQSISESCUELAS_H__
#include <SiscomOperaciones3.h>




class CQSisOpEscuelas:public SiscomOperaciones3
{
public:
	CQSisOpEscuelas(SiscomDatCom *);
	void Escuelas(const char *,SiscomRegistro3Lst *);
private:
};
#endif
