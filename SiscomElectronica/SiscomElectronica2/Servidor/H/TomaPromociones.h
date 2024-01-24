#ifndef __TOMAPROMOCIONES_H__
#define __TOMAPROMOCIONES_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpTomaPromociones();
void RegistraTomaPromociones(SArgsSiscom *);
void GeneraIdOperacion(SArgsSiscom *);
void ArgumentosTomaPromociones(SArgsSiscom *pSAgsSiscom);
void TomaPromociones(SArgsSiscom *pSAgsSiscom);
void RegistraTomaPromocionesCliente(SArgsSiscom *pSAgsSiscom);

SiscomOperaciones2 *OpPuntosPromocionesCliente();

#endif
