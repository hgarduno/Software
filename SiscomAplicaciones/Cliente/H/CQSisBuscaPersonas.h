#ifndef __CQSISBUSCAPERSONAS_H__
#define __CQSISBUSCAPERSONAS_H__
#include <SISCOMComunicaciones++.h>



class CQSisBuscaPersona:public SiscomInformacion
{
public:
	CQSisBuscaPersona(const char *,
			  const char *,
			  const char *,
			  const char *);
};
class CQSisLstBuscaPersona:public QPtrList<CQSisBuscaPersona>
{
public:
	CQSisLstBuscaPersona();
	CQSisLstBuscaPersona &operator<<(CQSisBuscaPersona *);
};
class SiscomRegistrosPro2;

class CQSisOpBuscaPersonas:public SiscomOperaciones
{

public:
	CQSisOpBuscaPersonas(SiscomDatCom *,CQSisBuscaPersona *);
	void Personas(CQSisLstBuscaPersona *);

private:
	CQSisBuscaPersona *CQSBPersona;
	SiscomRegistrosPro2 *SRegistrosPro2;
private:
	void Elimina(CQSisLstBuscaPersona *);
};



#endif
