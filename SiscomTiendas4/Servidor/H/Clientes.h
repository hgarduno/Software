#ifndef __CLIENTES_H__
#define __CLIENTES_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPDireccionesCliente();
SiscomOperaciones2 *OPClientesRegistrados();
SiscomOperaciones2 *ORegistraClienteFisica();
SiscomOperaciones2 *ORegistraPropietarioVehiculo();
SiscomOperaciones2 *ORegistraResponsableVehiculo();
SiscomOperaciones2 *ORegistraDireccion2();

void ArgumentosDirecciones2(SArgsSiscom *pSAgsSiscom);
void RegistraClientes(SArgsSiscom *);
void RegistraDirecciones2(SArgsSiscom *pSAgsSiscom);

#endif
