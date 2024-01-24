#ifndef __PAQUETES_H__
#define __PAQUETES_H__
#include <SiscomDesarrollo2.h>

void ArgumentosPaquetes(SArgsSiscom *);
void GeneraIdPaquete(SArgsSiscom *);
void RegistraPaquete(SArgsSiscom *);
SiscomOperaciones2 *ORegistraPaquete();
SiscomOperaciones2 *OProductosPaquete();
SiscomOperaciones2 *OPaquetesDisponibles();
SiscomOperaciones2 *OProductosDelPaquete();
SiscomOperaciones2 *OEliminaProductoPaquete();
SiscomOperaciones2 *OAnexarProductoPaquete();
SiscomOperaciones2 *OEliminaPaquete();



#endif
