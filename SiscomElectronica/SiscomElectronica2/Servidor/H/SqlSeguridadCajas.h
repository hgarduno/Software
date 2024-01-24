#ifndef __SQLSEGURIDADCAJAS_H__
#define __SQLSEGURIDADCAJAS_H__
#include <SiscomDesarrollo2.h>

void SqlCajasYControles(SArgsSiscom *);
void SqlControlesCaja(SArgsSiscom *pSAgsSiscom);

void SqlActualizaEdoControl(SArgsSiscom *);
void SqlGeneraActualizaEdoControl(LCamposSiscomPro2 *,
				  LCamposSiscomPro2 **,
				  LCamposSiscomPro2 **,
				  int *pintPtrNRegistros);
#endif
