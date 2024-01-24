#ifndef __SQLMEDIOSCOMUNICACION_H__
#define __SQLMEDIOSCOMUNICACION_H__
#include <SiscomDesarrollo2.h>



void SQLSiscomMediosComunicacionReg(SArgsSiscom *);
void SQLSiscomRegistraMedioComunicacion(SArgsSiscom *pSAgsSiscom);
void SQLGeneraSiscomRegistraMedioComunicacion(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
#endif

