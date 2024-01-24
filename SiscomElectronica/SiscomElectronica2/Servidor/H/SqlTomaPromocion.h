#ifndef __SQLTOMAPROMOCION_H__
#define __SQLTOMAPROMOCION_H__
#include <SiscomDesarrollo2.h>


void SqlSeguimientoPuntosClientes(SArgsSiscom *pSAgsSiscom);
void SqlSeguimientoPuntosClientesInserta(SArgsSiscom *pSAgsSiscom,
					 LCamposSiscomPro2 *pSLCSiscomPro2Dat);

void SqlDetalleOperacionPuntosClientes(SArgsSiscom *pSAgsSiscom);
void SqlDetalleOperacionPuntosClientesInserta(SArgsSiscom *pSAgsSiscom,
					 LCamposSiscomPro2 *pSLCSiscomPro2Dat);
#endif
