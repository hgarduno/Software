#ifndef __REGISTRAORDEN_H__
#define __REGISTRAORDEN_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void RegistraOrden(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);

void PagarApartado(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaDescripcionCotizacion(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);
int RegistrandoOrden(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoOrden(SiscomOperaciones *pSiscomOpePtrDato);
int CamposCierraApartadoOtroDia(SiscomOperaciones *);

int ValidandoFechaPedido(SiscomOperaciones *pSiscomOpePtrDato);
int SePagoConTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
SiscomRegistroProL *InformacionTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
const char *InformacionTransferenciaObservaciones(SiscomOperaciones *pSisOpePtrDato);
const char *InformacionTransferenciaSeReflejo(SiscomOperaciones *pSisOpePtrDato);
#endif
