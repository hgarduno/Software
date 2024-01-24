#ifndef __CQSISPRECIOS_H__
#define __CQSISPRECIOS_H__
#include <SISCOMComunicaciones++.h>

class CQSisPrecio:public SiscomInformacion
{
public:
	CQSisPrecio(const char *,
		    const char *,
		    const char *);
	CQSisPrecio();
};

class CQSisLstPrecio:public QPtrList<CQSisPrecio>
{
public:
	CQSisLstPrecio();
	~CQSisLstPrecio();
	CQSisLstPrecio &operator<<(CQSisPrecio *);
};
#endif
