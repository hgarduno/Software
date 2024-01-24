#ifndef __PUNTOSENTREGA_H__
#define __PUNTOSENTREGA_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void RegistraPuntoEntrega(int pintSocket,
			  SiscomRegistroProL *pSisRegProLPtrPrim,
			  SiscomRegistroProL *pSisRegProLPtrAct);

void PuntosEntrega(int pintSocket,
			  SiscomRegistroProL *pSisRegProLPtrPrim,
			  SiscomRegistroProL *pSisRegProLPtrAct);


int RegistrandoPuntoEntrega(SiscomOperaciones *);

int ArgumentoPuntoEntrega(SiscomOperaciones *pSisOpePtrDato);
int IdPuntoEntrega(SiscomOperaciones *pSisOpePtrDato);
int AsignaIdPuntoEntregaADireccion(SiscomOperaciones *pSisOpePtrDato);

int ConsultandoPuntosEntrega(SiscomOperaciones *pSisOpePtrDato);
#endif
