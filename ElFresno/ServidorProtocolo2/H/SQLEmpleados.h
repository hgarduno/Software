#ifndef __SQLEMPLEADOS_H__
#define __SQLEMPLEADOS_H__
#include <SiscomDesarrollo2.h>

void SQLEmpleados(SArgsSiscom *);
void SQLBorraEmpleado(SArgsSiscom *);

void SQLGeneraRegistroBorraEmpleado(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
#endif
