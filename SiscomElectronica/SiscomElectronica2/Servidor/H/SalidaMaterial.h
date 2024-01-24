#ifndef __SALIDAMATERIAL_H__
#define __SALIDAMATERIAL_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OpMotivosSalidas();
SiscomOperaciones2 *OpRegistraSalidaMaterial();
void ArgumentosMotivosSalidas(SArgsSiscom *pSAgsSiscom);
void ArgumentosSalidaMaterial(SArgsSiscom *pSAgsSiscom);
void EnviaMotivosSalidas(SArgsSiscom *pSAgsSiscom);
void EnviaRegistroSalidaMaterial(SArgsSiscom *pSAgsSiscom);
void IniciaArgumentoDatos(SArgsSiscom *pSAgsSiscom);

#endif
