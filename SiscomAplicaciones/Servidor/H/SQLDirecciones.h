#ifndef __SQLDIRECCIONES_H__
#define __SQLDIRECCIONES_H__
#include <SiscomDesarrollo2.h>

void SQLSiscomDireccionesReg(SArgsSiscom *);
void SQLSiscomRegistraDireccion(SArgsSiscom *pSAgsSiscom);
void SQLGeneraSiscomRegistraDireccion(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
#endif
