#ifndef __CQSISPERSONASPROT3_H__
#define __CQSISPERSONASPROT3_H__
#include <SiscomOperaciones3.h>
class SiscomDatCom;

class CQSisPersonasProt3:public SiscomOperaciones3
{
public:
	CQSisPersonasProt3(SiscomDatCom *);
	void Registra(SiscomRegistro3Lst *);
	void Registra(const char *pchrPtrOperacion,
		      SiscomRegistro3 *,
		      SiscomRegistro3Lst *pSisReg3LstRegreso);

};

#endif
