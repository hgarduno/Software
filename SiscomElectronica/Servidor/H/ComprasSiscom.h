#ifndef __COMPRASSISCOM_H__
#define __COMPRASSISCOM_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void ConsultaComprasSiscom(int pintSocket,
                SiscomRegistroProL *pSiscomRegProLPtrPrim,
                SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviandoComprasSiscom(SiscomOperaciones *pSisOpePtrDato);


#endif
