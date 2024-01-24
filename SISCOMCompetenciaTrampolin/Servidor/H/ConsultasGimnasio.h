#ifndef __CONSULTAGIMNASIO_H__
#define __CONSULTAGIMNASIO_H__
#include <SiscomDesarrollo2.h>
#include <ConsultaPersonas.h>
SiscomOperaciones2 *GimnasiosRegistrados();
SiscomOperaciones2 *ClasesRegistradas();
SiscomOperaciones2 *NivelesRegistrados();
SiscomOperaciones2 *GruposRegistrados();
SiscomOperaciones2 *CompetenciasRegistradas();
SiscomOperaciones2 *PersonasRegistradas();
SiscomOperaciones2 *GimnastasCompetencia();
SiscomOperaciones2 *GimnastasCompetencia01();
SiscomOperaciones2 *CalificacionesGimnasta();
SiscomOperaciones2 *TiposCompetencia();
SiscomOperaciones2 *AparatosCompetencia();
SiscomOperaciones2 *MediosPersona();
SiscomOperaciones2 *DireccionesPersona();

void ConsultaDireccionesPersona(SArgsSiscom *);
void ConsultaGimnasiosRegistrados(SArgsSiscom *);
void ConsultaClases(SArgsSiscom *);
void ConsultaNiveles(SArgsSiscom *);
void ConsultaGrupos(SArgsSiscom *);
void ConsultaCompetencias(SArgsSiscom *);
void ConsultaPersonas(SArgsSiscom *);
void ConsultaGimnastasCompetencia(SArgsSiscom *);
void ConsultaGimnastasCompetencia01(SArgsSiscom *);
void ConsultaCalificacionesGimnasta(SArgsSiscom *);
void ConsultaTiposCompetencia(SArgsSiscom *);
void ConsultaAparatosCompetencia(SArgsSiscom *);
void ConsultaMediosPersona(SArgsSiscom *);

void FormaCadenaConsultaCalificacionesGimnasta(const char *pchrPtrIdGimnasta,
					       const char *pchrPtrIdCompetencia,
					       char *pchrPtrCadena);


void EjecutaConsultaYResponde(SArgsSiscom *,const char *);


#endif
