#ifndef __CQSISCALIFICACIONES_H__
#define __CQSISCALIFICACIONES_H__
#include <SISCOMComunicaciones++.h>
class CQSisCompetencia;
class CQSisEntrenador;
class CQSisJuez;
class CQSisCompitiendo;
class CQSisAparato;
class CQSisCalificacion:public SiscomInformacion
{
public:
	CQSisCalificacion(CQSisAparato *,
			  CQSisCompetencia *,
			  CQSisEntrenador *,
			  CQSisJuez *,
			  CQSisJuez *);
	CQSisCalificacion(CQSisAparato *,
			  const char *,
			  const char *,
			  const char *);
	void PonEjecucion(const char *);
	void PonDificultad(const char *);
	void PonNotaFinal(const char *);

	CQSisCompetencia *ObtenCompetencia();
	CQSisEntrenador *ObtenGimnasta();
	CQSisAparato *ObtenAparato();
	int operator==(CQSisAparato *);
private:
	CQSisCompetencia *CQSCompetencia;
	CQSisEntrenador *CQSEGimnasta;
	CQSisJuez *CQSJuezEjecucion;
	CQSisJuez *CQSJuezDificultad;
	CQSisAparato *CQSAparato;
	const char *chrPtrDificultad;
	const char *chrPtrEjecucion;
	const char *chrPtrNotaFinal;
private:
	void SiscomFormaRegistro();
	void SiscomAnexaRegistro();
	void SiscomAsignaInformacion();
};

class CQSisLstCalificacion:public QPtrList<CQSisCalificacion>
{
public:
	CQSisLstCalificacion();
	CQSisLstCalificacion&operator<<(CQSisCalificacion *);
};

class CQSisOpCalificacion:public SiscomOperaciones
{
public:
	CQSisOpCalificacion(SiscomDatCom *);

	void IniciaCalificacion(CQSisCalificacion *,SiscomRegistrosPro2 **);
	void ActualizaEjecucion(CQSisCalificacion *,SiscomRegistrosPro2 **);
	void ActualizaDificultad(CQSisCalificacion *,SiscomRegistrosPro2 **);

	void ObtenCalificaciones(CQSisCompitiendo *,
				 CQSisCalificacion **);
private:
	CQSisLstCalificacion CQSLCalificacion;	
	SiscomParametrosConsulta SPConsulta;
private:
	void FormaCalificacion(SiscomRegistrosPro2 *,CQSisCalificacion **);
};

#endif
