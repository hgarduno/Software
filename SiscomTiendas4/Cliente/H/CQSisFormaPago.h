#ifndef __CQSISFORMAPAGO_H__
#define __CQSISFORMAPAGO_H__
#include <SISCOMComunicaciones++.h>

class CQSisFormaPago:public SiscomInformacion
{
public:
	CQSisFormaPago(const char *,
		       const char *,
		       const char *);
};

class CQSisLstFormaPago:public QPtrList<CQSisFormaPago>
{
public:
	CQSisLstFormaPago();
	~CQSisLstFormaPago();
	CQSisLstFormaPago &operator<<(CQSisFormaPago *);
};


#endif
