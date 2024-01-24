#ifndef __REPORTESSISCOM_H__
#define __REPORTESSISCOM_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void ReporteVentas4(int pintSocket,
		    SiscomRegistroProL *pSiscomRegProLPtrPrim,
		    SiscomRegistroProL *pSiscomRegProLPtrAct);

void CierraDia(int pintSocket,
		    SiscomRegistroProL *pSiscomRegProLPtrPrim,
		    SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaReportes(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaVentasSiscom(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaCierreDia(SiscomOperaciones *pSiscomOpePtrDato);
int AsignaReporteCierre(SiscomOperaciones *pSiscomOpePtrDato);


#endif
