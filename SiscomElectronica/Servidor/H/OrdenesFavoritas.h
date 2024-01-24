#ifndef __ORDENESFAVORITAS_H__
#define __ORDENESFAVORITAS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void RegistraOrdenesFavoritas(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);

void ConsultaOrdenesFavoritas(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);

void EliminaOrdenesFavoritas(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);
int RegistrandoOrdenesFavoritas(SiscomOperaciones *);
int EnviaOrdenesFavoritas(SiscomOperaciones *);
int AgregaArgumentosOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato);

#endif
