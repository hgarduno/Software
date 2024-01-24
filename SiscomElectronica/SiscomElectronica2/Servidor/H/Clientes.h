#ifndef __CLIENTES_H__
#define __CLIENTES_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpClientes();
SiscomOperaciones2 *OPRegistraCliente();
SiscomOperaciones2 *OPRegistraClienteMoral();
void RegistraClienteMoral(SArgsSiscom *pSAgsSiscom);

void RegistraCliente(SArgsSiscom *pSisArgsSiscom);
void ArgumentosPersonaMoral(SArgsSiscom *pSisArgsSiscom);

#endif
