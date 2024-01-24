#ifndef __GASTOSEXPENDIO_H__
#define __GASTOSEXPENDIO_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void GastosSiscom(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
	
int EnviandoGastosSiscom(SiscomOperaciones *pSiscomOpePtrDato);

#endif
