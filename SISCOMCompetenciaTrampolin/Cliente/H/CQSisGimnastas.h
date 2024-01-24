#ifndef __CQSISGIMNASTAS_H__
#define __CQSISGIMNASTAS_H__
#include <CQSisEntrenadores.h>
class CQSisGimnasta:public CQSisEntrenador
{
public:
	CQSisGimnasta(const char *,
		      const char *,
		      const char *,
		      const char *);
private:
};

class CQSisLstGimnasta:public QPtrList<CQSisGimnasta>
{
public:
	CQSisLstGimnasta();
	CQSisLstGimnasta &operator<<(CQSisGimnasta *);
};

class CQSisOpGimnasta:public SiscomOperaciones
{
public:
	CQSisOpGimnasta(SiscomDatCom *);
	void InsertaGimnasta(CQSisGimnasta *,SiscomRegistrosPro2 **);
private:
	CQSisLstGimnasta CQSLGimnasta;
};
#endif
