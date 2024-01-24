#ifndef __EXPENDIOS_H__
#define __EXPENDIOS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpRegistraExpendio();
SiscomOperaciones2 *OpActualizaDatosExpendio();
SiscomOperaciones2 *OPExpendios();


void RegistraExpendio(SArgsSiscom *pSArgsSiscom);
void ActualizaDatosExpendio(SArgsSiscom *pSArgsSiscom);
void ArgumentosExpendios(SArgsSiscom *pSAgsSiscom);
void GeneraIdExpendio(SArgsSiscom *pSAgsSiscom);
#endif
