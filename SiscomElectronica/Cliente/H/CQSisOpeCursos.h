#ifndef __CQSISOPECURSOS_H__
#define __CQSISOPECURSOS_H__
#include <SiscomOperaciones3.h>

class CQSisCursosDiaHora;
class CQSisOpeCursos:public SiscomOperaciones3
{
public:
	CQSisOpeCursos(SiscomDatCom *pSisDatCom);
	void RegistraHorariosCursos(CQSisCursosDiaHora *pCQSisCuDiaHora);
	
};


#endif
