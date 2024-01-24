#ifndef __SQLEVOLUCIONCONSULTA_H__
#define __SQLEVOLUCIONCONSULTA_H__
#include <SiscomDesarrollo2.h>

void SQLRegistraEvolucionConsulta(SArgsSiscom *pSAgsSiscom);
void SQLGeneraRegistroEvolucionConsulta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);


#endif
