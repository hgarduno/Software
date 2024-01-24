#ifndef __CQSISPERSONAS_H__
#define __CQSISPERSONAS_H__
#include <SISCOMComunicaciones++.h>


class CQSisPersona:public SiscomInformacion
{
public:
	CQSisPersona(const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *);
};

class CQSisLstPersona:public QPtrList<CQSisPersona>
{
public:
	CQSisLstPersona();
	CQSisLstPersona &operator<<(CQSisPersona *);
};

class CQSisOpPersona:public SiscomOperaciones
{
public:
	CQSisOpPersona(SiscomDatCom *);
	void Empleado(CQSisPersona *,SiscomRegistrosPro2 **);
	void Empleados(const char *,CQSisLstPersona *);
	void Paciente(CQSisPersona *,SiscomRegistrosPro2 **);
	void PacientesSimilares(CQSisPersona *,SiscomRegistrosPro2 **);
	void ActualizaNombre(CQSisPersona *,SiscomRegistrosPro2 **);

private:
	void EliminaPersonas(CQSisLstPersona *);
private:
	SiscomParametrosConsulta SPConsulta;
};
#endif
