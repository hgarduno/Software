#ifndef __SEGURIDADCAJAS_H__
#define __SEGURIDADCAJAS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpCajasYControles();
SiscomOperaciones2 *OpControlesCaja();
SiscomOperaciones2 *OpActualizaEdoControlCaja();
void ActualizaEdoControlCaja(SArgsSiscom *);
void ArgumentosEdoControlCaja(SArgsSiscom *);
void DireccionIpCaja(SArgsSiscom *pSAgsSiscom);

#endif
