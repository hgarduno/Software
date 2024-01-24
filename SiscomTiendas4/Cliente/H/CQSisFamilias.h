#ifndef __CQSISFAMILIA_H__
#define __CQSISFAMILIA_H__
#include <SISCOMComunicaciones++.h>

class CQSisFamilia:public SiscomInformacion
{
public:
	CQSisFamilia(const char *,
		     const char *,
		     const char *);
};

class CQSisLstFamilia:public QPtrList<CQSisFamilia>
{
public:
	CQSisLstFamilia();
	CQSisLstFamilia &operator<<(CQSisFamilia *);
};

#endif
