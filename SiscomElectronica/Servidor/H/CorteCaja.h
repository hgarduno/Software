#ifndef __CORTECAJA_H__
#define __CORTECAJA_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void RegistraCorteCaja(int pintSocket,
                       SiscomRegistroProL *pSiscomRegProLPtrPrim,
                       SiscomRegistroProL *pSiscomRegProLPtrAct);

void CalculaCorteCaja(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);


void RegistraCambioCaja(int pintSocket,
                        SiscomRegistroProL *pSiscomRegProLPtrPrim,
                        SiscomRegistroProL *pSiscomRegProLPtrAct);

void CambiosCaja(int pintSocket,
                  SiscomRegistroProL *pSiscomRegProLPtrPrim,
                  SiscomRegistroProL *pSiscomRegProLPtrAct);


void ConsultaCambioCaja(int pintSocket,
                  SiscomRegistroProL *pSiscomRegProLPtrPrim,
                  SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviandoCalculoCorteCaja(SiscomOperaciones *pSisOpePtrDato);
int MultiplicaSumaDenominaciones(SiscomOperaciones *pSisOpePtrDato);
int SumaGastosCaja(SiscomOperaciones *);
int RegistrandoCambio(SiscomOperaciones *);
int ArgumentoCorteCaja(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaArgumentoCajaCambio(SiscomOperaciones *pSisOpePtrDato);
int AgregaArgumentoDatosCambioCaja(SiscomOperaciones *pSisOpePtrDato);
int EnviandoCambiosCaja(SiscomOperaciones *pSisOpePtrDato);
int EnviandoCambioCaja(SiscomOperaciones *pSisOpePtrDato);
int AcondicionandoParaMostrar(SiscomOperaciones *pSisOpePtrDatos);
int EnviaRegistroCorteCaja(SiscomOperaciones *pSisOpePtrDato);

int MultiplicandoSumandoCajas(SiscomOperaciones *pSisOpePtrDato);
int CalculandoCorteCaja(SiscomOperaciones *pSisOpePtrDato);
float MultiplicaSumaCaja(SiscomRegistroProL *pSisRegProLPtrDeno);


SiscomRegistroProL *CajaDeCambio(SiscomOperaciones *pSisOpePtrDato);
SiscomRegistroProL *EfectivoCambioCaja(SiscomOperaciones *pSisOpePtrDato);

int YaHayCajaConCambio(SiscomOperaciones *pSisOpPtrDato);
int ColocaFechaHoyCorteCaja(SiscomOperaciones *pSisOpePtrDato);

int ContandoCambioCaja(SiscomOperaciones *pSisOpePtrDato);
int AsignaCamposConsultaCorteCaja(SiscomOperaciones *pSisOpePtrDato);
float ContandoCajaDinero(SiscomOperaciones *pSisOpePtrDato);

SiscomRegistroProL *ContandoCajaPrincipalDinero(SiscomOperaciones *pSisOpePtrDato);
#endif
