#ifndef __CLAVESSATSISCOM_H__
#define __CLAVESSATSISCOM_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void RegistraClaveSat(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct); 

void ClaveSat(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int GeneraIdClaveSat(SiscomOperaciones *pSiscomOpePtrDato);
int RegistrandoClaveSat(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoRegistroClaveSat(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoClaveSat(SiscomOperaciones *pSiscomOpePtrDato);
#endif
