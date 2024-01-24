#ifndef __CQSISROTACIONES_H__
#define __CQSISROTACIONES_H__
#include <SiscomOperaciones3.h>

class CQSisCompetencia;
class SiscomRegistro3Lst;
class CQSisOpRotaciones:public SiscomOperaciones3
{
public:
	CQSisOpRotaciones(SiscomDatCom *);
	void EjecutaRotacion(CQSisCompetencia *,const char *);
	void RondasCompetencia(const char *,SiscomRegistro3Lst *);
};
#endif
