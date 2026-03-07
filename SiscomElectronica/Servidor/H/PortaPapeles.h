#ifndef __PORTAPAPELES_H__
#define __PORTAPAPELES_H_
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
void ClienteSiscomPortaPapeles(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaClienteSiscomPortaPapeles(SiscomOperaciones *pSiscomOpePtrDato);
void AnalizandoCadenaPortaPapeles(SiscomOperaciones *pSiscomOpePtrDato);

void EnviaRespuestaPortaPapeles(SiscomOperaciones *pSisOpePtrDatos,
				    const char *pchrPtrTelefono);
#endif 
