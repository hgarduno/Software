#ifndef __SQLSERVICIOS_H__
#define __SQLSERVICIOS_H__
#include <SiscomDesarrollo2.h>

void SqlServicios(SArgsSiscom *);
void SqlAlumnosSinRegistroSalida(SArgsSiscom *pSAgsSiscom);
void SqlRegistraAlumnoServicio(SArgsSiscom *pSAgsSiscom);
void SqlActualizaAlumnoServicioHoraSalida(SArgsSiscom *pSAgsSiscom);
void SqlInsertIntoAlumnoServicio(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);


void SqlUpdateAlumnoServicioHoraSalida(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);
	
#endif
