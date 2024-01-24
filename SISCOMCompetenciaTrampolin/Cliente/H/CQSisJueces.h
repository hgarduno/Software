#ifndef __CQSISJUECES_H__
#define __CQSISJUECES_H__
#include <CQSisEntrenadores.h>
class CQSisJuez:public CQSisEntrenador
{
public:
	CQSisJuez(const char *,
		  const char *,
		  const char *,
		  const char *);
};

class CQSisLstJuez:public QPtrList<CQSisJuez>
{
public:
	CQSisLstJuez();
	CQSisLstJuez &operator<<(CQSisJuez *);
};

class CQSisOpJuez:public SiscomOperaciones
{
public:
	CQSisOpJuez(SiscomDatCom *);
	void InsertaJuez(CQSisJuez *,SiscomRegistrosPro2 **);
private:
	CQSisLstJuez CQSLJuez;


};

#endif

