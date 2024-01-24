#ifndef __CIRCUITOSIMPRESOS_H__
#define __CIRCUITOSIMPRESOS_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void EstadosImpresosSE(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
void RegistraCircuitoImpreso(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
void CircuitosImpresosPendientes(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);

void ImpresosPorEstadoFecha(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
void CircuitoImpresoActualizaEdo(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaCircuitoImpreso(SiscomOperaciones *pSisOpePtrDato);
int EnviaCircuitosImpresosPendientes(SiscomOperaciones *pSisOpePtrDato);
int ArgumentoRegistroCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato);
int AsignaIdCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoEstadosImpresosSE(SiscomOperaciones *pSiscomOpePtrDato);
#endif
