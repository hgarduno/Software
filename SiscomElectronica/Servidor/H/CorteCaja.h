#ifndef __CORTECAJA_H__
#define __CORTECAJA_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>


void CalculaCorteCaja(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviandoCalculoCorteCaja(SiscomOperaciones *pSisOpePtrDato);
int MultiplicaSumaDenominaciones(SiscomOperaciones *pSisOpePtrDato);
int SumaGastosCaja(SiscomOperaciones *);
void MultiplicandoSumandoCajas(SiscomOperaciones *pSisOpePtrDato);
float MultiplicaSumaCaja(SiscomRegistroProL *pSisRegProLPtrDeno);
#endif
