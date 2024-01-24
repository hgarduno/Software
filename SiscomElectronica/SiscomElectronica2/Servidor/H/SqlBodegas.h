#ifndef __SQLBODEGAS_H__
#define __SQLBODEGAS_H__

#include <SiscomDesarrollo2.h>


void SqlBodegas(SArgsSiscom *pSAgsSiscom);
void SqlExistenciaProductoBodega(SArgsSiscom *pSAgsSiscom);


void SqlActualizaMaterialBodega(SArgsSiscom *);
void SqlGeneraActualizaMaterialBodega(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

void SqlInsertaBodegaAExpendio(SArgsSiscom *);
void SqlGeneraInsertaBodegaAExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

void SqlInsertaInventarioBodega(SArgsSiscom *);
void SqlGeneraInsertaInventarioBodega(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
void SqlActualizaExistenciaExpendio(SArgsSiscom *);
void SqlGeneraActualizaExistenciaExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);


void SqlActualizaExistenciaBodega(SArgsSiscom *);
void SqlGeneraActualizaExistenciaBodega(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
#endif
