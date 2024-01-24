#ifndef __RONDAS_H__
#define __RONDAS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *RegistraRondas();
SiscomOperaciones2 *CalificaRonda();
void ArgumentosRonda(SArgsSiscom *);
void InsertaRondas(SArgsSiscom *);
void SQLCalificaRonda(SArgsSiscom *);
void GeneraIdRonda(SArgsSiscom *);
void RondaGimnastaAparato(SArgsSiscom *);
void RondaGimnastaAparato01(SArgsSiscom *);
void ObtenRondasCompetencia(SArgsSiscom *);
void EnviaRondasCliente(SArgsSiscom *);


void GeneraAparatoGimnasta(int ,LCamposSiscomPro2ConSubReg *,LCamposSiscomPro2 **);
void GeneraRondas(int,LCamposSiscomPro2 *,LCamposSiscomPro2 *,LCamposSiscomPro2ConSubReg *);
void AnexaRegistroInicioAparato(const char *,
				const char *,
				const char *,
				const char *,
				SCampoSiscomPro2 *,
				LCamposSiscomPro2 **,
				LCamposSiscomPro2 **,
				int *);
void AnexaRegistroInicioRonda(const char *,
			      const char *,
			      SCampoSiscomPro2 *,
			      LCamposSiscomPro2 **,
			      LCamposSiscomPro2 **,
			      int *);
void RondaAparatoGimnasta(int ,LCamposSiscomPro2ConSubReg *,SArgsSiscom *);
#endif
