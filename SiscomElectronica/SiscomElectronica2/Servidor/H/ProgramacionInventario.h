#ifndef __PROGRAMACIONINVENTARIO_H__
#define __PROGRAMACIONINVENTARIO_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpRegistraProgramacionInventario();
void ProgramacionInventario(SArgsSiscom *pSAgsSiscom);
void ArgumentosProgramacion(SArgsSiscom *pSAgsSiscom);

SiscomOperaciones2 *OpInventariosProgramados();
#endif
