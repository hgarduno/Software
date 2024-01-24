#ifndef __VENTASCAJA_H__
#define __VENTASCAJA_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OpVentasPorCaja();
SiscomOperaciones2 *OpCajasRegistradas();
SiscomOperaciones2 *OpRegistraImporteCaja();
SiscomOperaciones2 *OpVentasPorCajaFecha();


void ArgumentosCajas(SArgsSiscom *pSAgsSiscom);

void EnviaImporteCajaServidor(SArgsSiscom *pSAgsSiscom);

void CalculaTotalEnCaja(SArgsSiscom *pSAgsSiscom);


#endif
