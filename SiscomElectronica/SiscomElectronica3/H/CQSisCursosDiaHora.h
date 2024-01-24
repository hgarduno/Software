#ifndef __CQSISCURSOSDIAHORA_H__
#define __CQSISCURSOSDIAHORA_H__
#include <SiscomRegistros4.h>

class CQSisCursosDiaHora:public SiscomRegistro4
{
public:
	CQSisCursosDiaHora();
	const char *Dia();
	SiscomRegistro3Lst *Cursos();
	void SiguienteDia();
	void ActualizaEstatusHorario(int pintDia,int pintHora,const char *pchrPtrEstatus);
	const char *IdCurso(int pintDia,int pintHora);
	const char *IdProgramacion(int pintDia,int pintHora);
	const char *Curso(int pintDia,int pintHora);

	


};

#endif
