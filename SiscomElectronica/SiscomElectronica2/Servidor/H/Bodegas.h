#ifndef __BODEGAS_H__
#define __BODEGAS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPBodegas();
SiscomOperaciones2 *OPExistenciaProductoBodega();
SiscomOperaciones2 *OPTransfiereBodegaExpendio();
SiscomOperaciones2 *OPInventarioBodega();

void TransfiereBodegaExpendio(SArgsSiscom *pSAgsSiscom);
void InventarioBodega(SArgsSiscom *pSAgsSiscom);
void ArgumentosBodegas(SArgsSiscom *pSAgsSiscom);
void ArgumentosInventarioBodegas(SArgsSiscom *pSAgsSiscom);

void RespondeEstadoOperacion(SArgsSiscom *pSAgsSiscom,
			     const char *pchrPtrEdoOperacion,
			     const char *pchrPtrMensaje);
#endif
