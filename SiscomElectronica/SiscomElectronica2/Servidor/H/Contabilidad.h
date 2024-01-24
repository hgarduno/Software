#ifndef __CONTABILIDAD_H__
#define __CONTABILIDAD_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpEjecutaContabilidad();
void ArgumentosContabilidad(SArgsSiscom *);
void EjecutaProcesoContable(SArgsSiscom *);
void RegistraCalculos(SArgsSiscom *);
#endif
