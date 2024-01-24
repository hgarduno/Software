#ifndef __ORDENESCAJACENTRALIZADA_H__
#define __ORDENESCAJACENTRALIZADA_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpOrdenesPendientes();
SiscomOperaciones2 *OpVendeOrdenCajaCentral();

void OrdenesPendientes(SArgsSiscom *pSAgsSiscom);
void EnviaOrdenesPendientes(SArgsSiscom *pSAgsSiscom);
void VendeOrdenCajaCentral(SArgsSiscom *pSAgsSiscom);

void ArgumentosOrdenesPendientes(SArgsSiscom *pSAgsSiscom);
void ArgumentosVendeOrdenCajaCentral(SArgsSiscom *pSAgsSiscom);
LCamposSiscomPro2 *NodoCliente(LCamposSiscomPro2 *,LCamposSiscomPro2 *);
void AgregaDatosCliente(LCamposSiscomPro2 *pLCSiscomPro2Orden,
			LCamposSiscomPro2 **pLCSiscomPro2PrimReg,
			LCamposSiscomPro2 **pLCSiscomPro2ActReg,
			int *pintPtrNRegRegreso);
#endif
