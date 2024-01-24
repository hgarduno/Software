#ifndef __GRUPOS_H__
#define __GRUPOS_H__
#include <SiscomDesarrollo2.h>

void AsignaArgumentosGrupos(SArgsSiscom *);
void ClasificaGruposPorGrupo(SArgsSiscom *);
void EnviaGrupos(SArgsSiscom *);
void ObtenNombresGrupos(SArgsSiscom *);


void AnexaRegistroNombreGrupo(const char *,
			      SCampoSiscomPro2 *,
			      LCamposSiscomPro2 **,
			      LCamposSiscomPro2 **,
			      int *);

#endif
