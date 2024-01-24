#ifndef __EMPRESAS_H__
#define __EMPRESAS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void RFCs(int pintSocket,
	  SiscomRegistroProL *pSiscomRegProLPtrPrim,
	  SiscomRegistroProL *pSiscomRegProLPtrAct);

void RegistraRegimenFiscal(int pintSocket,
	  SiscomRegistroProL *pSiscomRegProLPtrPrim,
	  SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaRFCs(SiscomOperaciones *pSiscomOpePtrDato);
int RegistrandoRegimenFiscal(SiscomOperaciones *pSiscomOpePtrDato);
int CreaArgumentoRegimenFiscal(SiscomOperaciones *pSiscomOpePtrDato);
#endif
