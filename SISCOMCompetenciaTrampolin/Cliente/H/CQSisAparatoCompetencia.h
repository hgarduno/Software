#ifndef __CQSISAPARATOCOMPETENCIA_H__
#define __CQSISAPARATOCOMPETENCIA_H__
#include <SISCOMComunicaciones++.h>

class CQSisAparato;
class CQSisTipoCompetencia;

class CQSisAparatoCompetencia:public SiscomInformacion
{
public:
	CQSisAparatoCompetencia(CQSisAparato *,
				CQSisTipoCompetencia *);

	CQSisAparato *ObtenAparato();
	CQSisTipoCompetencia *ObtenTipoCompetencia();
private:

	CQSisAparato *CQSAparato;
	CQSisTipoCompetencia *CQSTCompetencia;


};

class CQSisLstAparatoCompetencia:public QPtrList<CQSisAparatoCompetencia>
{
public:
	CQSisLstAparatoCompetencia();
	CQSisLstAparatoCompetencia &operator<<(CQSisAparatoCompetencia *);
	int operator==(CQSisAparatoCompetencia *);
};

#endif
