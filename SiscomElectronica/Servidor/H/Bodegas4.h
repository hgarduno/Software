#ifndef __BODEGAS4_H__
#define __BODEGAS4_H_

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void TransfiereBodegaBodega(int pintSocket,
             SiscomRegistroProL *pSiscomRegProLPtrPrim,
             SiscomRegistroProL *pSiscomRegProLPtrAct);

void BodegasExpendios(int pintSocket,
             SiscomRegistroProL *pSiscomRegProLPtrPrim,
             SiscomRegistroProL *pSiscomRegProLPtrAct);

void ExistenciaBodega4(int pintSocket,
             SiscomRegistroProL *pSiscomRegProLPtrPrim,
             SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaExistenciaBodega4(int pintSocket,
             SiscomRegistroProL *pSiscomRegProLPtrPrim,
             SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaExpendiosBodegas(SiscomOperaciones *pSisOpePtrDatos);
int EnviaExistenciaBodega(SiscomOperaciones *pSisOpePtrDatos);
int EnviaActualizaExistenciaBodega(SiscomOperaciones *pSisOpePtrDatos);
int TransfiriendoBodegaBodega(SiscomOperaciones *pSisOpePtrDatos);

int ArgumentoExistenciaBodega(SiscomOperaciones *pSisOpPtrDatos);
int ArgumentoActualizaExistencia(SiscomOperaciones *pSisOpePtrDato);

int ArgumentoBodegaOrigen(SiscomOperaciones *pSisOpePtrDatos);
int ArgumentoBodegaDestino(SiscomOperaciones *pSisOpePtrDatos);



const char *DatoBodega(const char *pchrPtrDato,SiscomOperaciones *pSisOpePtrDatos);
const char *DatoBodegaExpendio(const char *pchrPtrDato,SiscomOperaciones *pSisOpePtrDatos);


const char *ObtenDirIpExpendioBodegaO(SiscomOperaciones *pSisOpePtrDato);
const char *ObtenBaseBodegaO(SiscomOperaciones *pSisOpePtrDato);
const char *ObtenIdBodegaO(SiscomOperaciones *pSisOpePtrDato);
int ObtenPuertoExpendioBodegaO(SiscomOperaciones *pSisOpePtrDato);


const char *ObtenDirIpExpendioBodegaD(SiscomOperaciones *pSisOpePtrDato);
const char *ObtenBaseBodegaD(SiscomOperaciones *pSisOpePtrDato);
const char *ObtenIdBodegaD(SiscomOperaciones *pSisOpePtrDato);
int ObtenPuertoExpendioBodegaD(SiscomOperaciones *pSisOpePtrDato);


int PuertoExpendioBodega(SiscomOperaciones *pSisOpePtrDatos);
#endif
