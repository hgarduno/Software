#ifndef __CQSISAPARATO_H__
#define __CQSISAPARATO_H__
#include <SISCOMComunicaciones++.h>

class CQSisAparato:public SiscomInformacion
{
public:
	CQSisAparato(const char *,const char *,const char *);
	int operator==(CQSisAparato *);

};

class CQSisLstAparato:public QPtrList<CQSisAparato>
{
public:
	CQSisLstAparato();
	CQSisLstAparato &operator<<(CQSisAparato *);
};

#endif
