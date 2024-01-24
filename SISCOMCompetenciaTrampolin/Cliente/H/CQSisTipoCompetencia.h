#ifndef __CQSISTIPOCOMPETENCIA_H__
#define __CQSISTIPOCOMPETENCIA_H__
#include <SISCOMComunicaciones++.h>

class CQSisTipoCompetencia:public SiscomInformacion
{
public:
	CQSisTipoCompetencia(const char *,
			     const char *);
private:
};

class CQSisLstTipoCompetencia:public QPtrList<CQSisTipoCompetencia>
{
public:
	CQSisLstTipoCompetencia();
	CQSisLstTipoCompetencia &operator<<(CQSisTipoCompetencia *);
};

#endif
