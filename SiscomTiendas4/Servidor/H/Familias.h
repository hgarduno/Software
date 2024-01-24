#ifndef __FAMILIAS_H__
#define __FAMILIAS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OperacionesFamilias();
SiscomOperaciones2 *FamiliasRegistradas();

void RegistraFamilia(SArgsSiscom *);
void ArgumentosFamilia(SArgsSiscom *);
void CambiaMayusculasFamilia(SArgsSiscom *);
void AsignaIdentificadorFamilia(SArgsSiscom *);
#endif
