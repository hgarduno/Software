#ifndef __CQSISCONTACTOS_H__
#define __CQSISCONTACTOS_H__
#include <SISCOMComunicaciones++.h>
class CQSisEmpresa;
class SisPersona;
class CQSisContacto:public SiscomInformacion
{
public:
	CQSisContacto(SisPersona *);
	CQSisContacto(SisPersona *,
		      CQSisEmpresa *);
	SisPersona *ObtenPersona();
	CQSisEmpresa *ObtenEmpresa();
private:
	SisPersona *SPersona;
	CQSisEmpresa *CQSEmpresa;
};
class CQSisLstContacto:public QPtrList<CQSisContacto>
{
public:
	CQSisLstContacto();
	~CQSisLstContacto();
	CQSisLstContacto &operator<<(CQSisContacto *);
};
#endif
