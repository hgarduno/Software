#ifndef __CQSISCONSULTAS_H__
#define __CQSISCONSULTAS_H__
#include <SISCOMComunicaciones++.h>
class CQSisPersona;

class CQSisConsulta:public SiscomInformacion
{
public:
	CQSisConsulta(
		const char *,
		const char *,
		const char *,
		const char *,
		const char *,
		const char *);
	CQSisConsulta(
	 	      const char *,
		      CQSisPersona *,
		      CQSisPersona *,
		      CQSisPersona *,
		      const char *,
		      const char *,
		      const char *,
		      const char *);
	CQSisPersona *Medico();
	CQSisPersona *Paciente();
	CQSisPersona *Empleado();
private:
	CQSisPersona *CQSPMedico;
	CQSisPersona *CQSPPaciente;
	CQSisPersona *CQSPEmpleado;
};

class CQSisLstConsulta:public QPtrList<CQSisConsulta>
{
public:
	CQSisLstConsulta();
	CQSisLstConsulta &operator<<(CQSisConsulta *);
private:
};

class CQSisOpConsulta:public SiscomOperaciones
{
public:
	CQSisOpConsulta(SiscomDatCom *);
	void Consulta(CQSisConsulta *,
		      SiscomRegistrosPro2 **);
	void ConsultasPendientesMedico(const char *,
					const char *,
					const char *,
			     		char *);
	void Consultas(const char *,
		       const char *,
		       const char *,
		       const char *,
		       const char *,
		       CQSisLstConsulta *);
	void ConsultaActualMedico(const char *,
				  CQSisLstConsulta *);
private:
	SiscomParametrosConsulta SPConsulta;
private:
	void EliminaConsulta(CQSisLstConsulta *);
};

#endif
