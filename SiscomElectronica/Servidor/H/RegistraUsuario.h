#ifndef __REGISTRAUSUARIO_H__
#define __REGISTRAUSUARIO_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void RegistraUsuarioSiscom(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int RegistrandoUsuarioSiscom(SiscomOperaciones *pSiscomOpePtrDato);


int EnviandoRegistroSeguridad3(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoSiscomSeguridad3(SiscomOperaciones *pSiscomOpePtrDato);
#endif
