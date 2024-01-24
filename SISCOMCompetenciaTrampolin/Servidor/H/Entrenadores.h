#ifndef __ENTRENADORES_H__
#define __ENTRENADORES_H__
#include <SiscomDesarrollo2.h>

void InsertaEntrenador(SArgsSiscom *);

SiscomOperaciones2 *GeneraOperacionesEntrenador();
void AsignaArgumentosEntrenador(SArgsSiscom *);
void ObtenInformacionConSubRegistros(SArgsSiscom *);
void GeneraIdentificadores(SArgsSiscom *);
void RegistraEntrenador(SArgsSiscom *);


#endif
