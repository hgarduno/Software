#ifndef __CALIFICACIONES_H__
#define __CALIFICACIONES_H__
#include <SiscomDesarrollo2.h>

void IniciaCalificacion(SArgsSiscom *);
void ActualizaCalificacion(SArgsSiscom *);
SiscomOperaciones2 *OperacionesIniciaCalificacion();
SiscomOperaciones2 *OperacionesActualizaEjecucion();
SiscomOperaciones2 *OperacionesActualizaDificultad();

void ArgumentosCalificacion(SArgsSiscom *pSAgsSiscom);


#endif
