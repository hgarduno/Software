#ifndef __CQSISCONSULTAS_H__
#define __CQSISCONSULTAS_H__
#include <SISCOMComunicaciones++.h>
class CQSisLstClase;
class CQSisLstNivel;
class CQSisLstGrupo;
class CQSisLstCompetencia;
class SisLstPersona;
class SisLstMedCom;
class SisLstDireccion;
class CQSisLstEntrenador;
class CQSisLstCompitiendo;
class CQSisLstTipoCompetencia;
class CQSisLstAparatoCompetencia;
class CQSisClase;
class CQSisCompetencia;
class CQSisTipoCompetencia;
class CQSisAparato;
class CQSisEntrenador;

class CQSisLstLstGrupo:public QPtrList<CQSisLstGrupo>
{
public:
	CQSisLstLstGrupo();
	CQSisLstLstGrupo &operator<<(CQSisLstGrupo *);

};
class CQSisOpConsultas:public SiscomOperaciones
{
public:
	CQSisOpConsultas(SiscomDatCom *);
	void ObtenClases(const char *,CQSisLstClase *);
	void ObtenNiveles(CQSisClase *,CQSisLstNivel *);
	void ObtenGrupos(CQSisLstGrupo *);
	void ObtenGrupos(const char *,CQSisLstLstGrupo *);
	void ObtenCompetencias(CQSisLstCompetencia *);
	void ConsultaPersonasNombre(
				const char *,
				const char *,
				const char *,
				const char *,
				SisLstPersona *);
	void ConsultaPersonasNombre(
				const char *,
				const char *,
				const char *,
				const char *,
				CQSisLstEntrenador *);
	void GimnastasCompetencia(CQSisCompetencia *,
				  CQSisAparato *,
				  CQSisLstCompitiendo *);
	void GimnastasCompetencia(CQSisCompetencia *,
				  CQSisLstCompitiendo *);
	void ConsultaTipoCompetencia(CQSisLstTipoCompetencia *);
	void ConsultaAparatosCompetencia(CQSisCompetencia *,
					 CQSisLstAparatoCompetencia *);
	void ConsultaMediosPersona(CQSisEntrenador *,
				   SisLstMedCom *);
	void DireccionesPersona(CQSisEntrenador *,
				SisLstDireccion *);

private:

	SiscomParametrosConsulta SPConsulta;
private:
	void FormaDireccionesPersona(SiscomRegistrosPro2 *,
				     SisLstDireccion *);
	void FormaClases(SiscomRegistrosPro2 *,CQSisLstClase *);
	void FormaNiveles(SiscomRegistrosPro2 *,CQSisLstNivel *);
	void FormaGrupos(SiscomRegistrosPro2 *,CQSisLstLstGrupo *);
	void FormaCompetencias(SiscomRegistrosPro2 *,CQSisLstCompetencia *);
	void FormaPersonas(SiscomRegistrosPro2 *,SisLstPersona *);
	void FormaEntrenadores(SiscomRegistrosPro2 *,CQSisLstEntrenador *);

	void FormaConsultaPorNombre(const char *,
					const char *,
					const char *,
					const char *);
	void FormaGimnastasCompetencia(SiscomRegistrosPro2 *,CQSisLstCompitiendo *);
	void FormaTipoCompetencia(SiscomRegistrosPro2 *,CQSisLstTipoCompetencia *);
	void FormaAparatoCompetencia(SiscomRegistrosPro2 *,CQSisLstAparatoCompetencia *);

	int EsElUltimoGrupo(SiscomRegistrosPro2 *);

	void FormaMedioComunicacion(SiscomRegistrosPro2 *,
				    SisLstMedCom *);
};

#endif
