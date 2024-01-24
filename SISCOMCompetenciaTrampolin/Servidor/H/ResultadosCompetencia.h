#ifndef __RESULTADOSCOMPETENCIA_H__
#define __RESULTADOSCOMPETENCIA_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *CompetenciaGeneral();
SiscomOperaciones2 *ResultadosPorAparato();
SiscomOperaciones2 *TablaResultados();
void SQLCompetenciaGeneral(SArgsSiscom *);
void SQLResultadoAparatos(SArgsSiscom *);
void SQLTablaResultados(SArgsSiscom *pSAgsSiscom);
void ObtenAparatos(SArgsSiscom *);
void ClasificaGruposPorAparato(int ,
			       int ,
			       LCamposSiscomPro2 *,
				LCamposSiscomPro2ConSubReg *,
				LCamposSiscomPro2ConSubReg *,
				int *);

void EjecutaResultadosPorAparato(SArgsSiscom *);
void FormaRespuestaResultadosAparatos(int ,int,LCamposSiscomPro2ConSubReg *,SArgsSiscom *);
void FormaEstructuraSubAparatos(LCamposSiscomPro2 *pLCSiscomPro2Aparatos,
				StcSisFormaRegistro *pSSFormaReg);
#endif
