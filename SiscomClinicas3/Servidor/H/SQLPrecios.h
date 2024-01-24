#ifndef __SQLPRECIOS_H__
#define __SQLPRECIOS_H__
#include <SiscomDesarrollo2.h>
void SQLConsultaPreciosServicio(SArgsSiscom *);
void SQLConsultaPreciosServicioMedico(SArgsSiscom *);
void SQLActualizaPrecioServicioGeneral(SArgsSiscom *pSAgsSiscom);
void SQLGeneraActualizaPrecioServicioGeneral(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SQLActualizaPrecioServicioMedico(SArgsSiscom *pSAgsSiscom);
void SQLGeneraActualizaPrecioServicioMedico(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

#endif
