#ifndef __DEVOLUCIONES_H__
#define __DEVOLUCIONES_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
#include <stdio.h>

void DevolucionOrden(int pintSocket,
			 SiscomRegistroProL *pSiscomRegProLPtrPrim,
			 SiscomRegistroProL *pSiscomRegProLPtrAct);

int DevolviendoOrden(SiscomOperaciones *pSiscomOpePtrDatos);
#endif
