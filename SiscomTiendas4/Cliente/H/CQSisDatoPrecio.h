#ifndef __CQSISDATOPRECIO_H__
#define __CQSISDATOPRECIO_H__
#include <SISCOMComunicaciones++.h>
class CQSisPrecio;
class CQSisDatoPrecio:public SiscomInformacion
{
public:
	CQSisDatoPrecio(CQSisPrecio *,
		       const char *,
		       const char *);
	CQSisPrecio *ObtenPrecio();
private:
	CQSisPrecio *CQSPrecio;
};
class CQSisLstDatoPrecio:public QPtrList<CQSisDatoPrecio>
{
public:
	CQSisLstDatoPrecio();
	~CQSisLstDatoPrecio();
	CQSisLstDatoPrecio &operator<<(CQSisDatoPrecio *);
};
#endif
