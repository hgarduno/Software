#ifndef __PROMOCIONESELECTRONICA_H__
#define __PROMOCIONESELECTRONICA_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpRegistraPromocion();


void RegistraPromocion(SArgsSiscom *);
void GeneraIdPromocion(SArgsSiscom *);
void ArgumentosPromocion(SArgsSiscom *);

void ValidaEdoRegistro(SArgsSiscom *);
void EnviaEdoRegistroCliente(SArgsSiscom *,const char *);

#endif
