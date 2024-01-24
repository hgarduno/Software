#ifndef __CATALOGOSSAT_H__
#define __CATALOGOSSAT_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void FormasPagoSat(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);
void MetodoPagoSat(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);
void UsoFacturaSat(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);

void RegimenFiscal(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaFormasPagoSat(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaMetodoPagoSat(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaUsoFacturaSat(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaRegimenFiscal(SiscomOperaciones *pSiscomOpePtrDato);

#endif
