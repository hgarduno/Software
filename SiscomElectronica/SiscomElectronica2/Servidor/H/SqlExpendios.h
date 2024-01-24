#ifndef __SQLEXPENDIOS_H__
#define __SQLEXPENDIOS_H__

#include <SiscomDesarrollo2.h>

void SqlExpendios(SArgsSiscom *pSAgsSiscom);

void SqlInsertaExpendio(SArgsSiscom *);
void SqlGeneraInsertaExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

void SqlInsertaEmpresa(SArgsSiscom *);
void SqlGeneraInsertaEmpresa(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);


void SqlActualizaExpendio(SArgsSiscom *);
void SqlGeneraActualizaExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

void SqlActualizaEmpresa(SArgsSiscom *);
void SqlGeneraActualizaEmpresa(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

#endif
