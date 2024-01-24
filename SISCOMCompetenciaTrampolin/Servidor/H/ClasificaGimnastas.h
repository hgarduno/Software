#ifndef __CLASIFICAGIMNASTAS_H__
#define __CLASIFICAGIMNASTAS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *ClasificaGimnastas();
void SQLClasificaGimnastas(SArgsSiscom *);
void SQLResultadosGimnastas(SArgsSiscom *);
void EjecutaClasificacionGimnastas(SArgsSiscom *);
void ObtenGrupos(SArgsSiscom *);
void ObtenNiveles(SArgsSiscom *);
void ObtenClases(SArgsSiscom *);
void AsignaArgumentosClasificacion(SArgsSiscom *);
void EnviaInformacionCliente(SArgsSiscom *);
void ActualizaRangoEdad(SArgsSiscom *);

void ClasificaPorGrupos(int,
			int,
			int,
			LCamposSiscomPro2ConSubReg *,
			SArgsSiscom *,
			LCamposSiscomPro2ConSubReg *,
			int *);



void AnexaRegistroInicioClaseNivel(const char *,
				   const char *,
				   SCampoSiscomPro2 *,
				   LCamposSiscomPro2 **,
				   LCamposSiscomPro2 **,
				   int *);
void FormaRespuestaClasificacion(int,
				 int,
				LCamposSiscomPro2ConSubReg *,
				 SArgsSiscom *);
#endif
