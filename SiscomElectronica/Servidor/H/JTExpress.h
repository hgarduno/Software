#ifndef __JTEXPRESS_H__
#define __JTEXPRESS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void JTExpressCobertura(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaCoberturaJTExpress(SiscomOperaciones *pSiscomOpePtrDato);
#endif
