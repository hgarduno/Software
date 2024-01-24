#ifndef __SQLEXPEDIENTES_H__
#define __SQLEXPEDIENTES_H__
#include <SiscomDesarrollo2.h>

void SQLRegistraExpediente(SArgsSiscom *pSAgsSiscom);

void SQLGeneraRegistroExpediente(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);



void SQLActualizaObservaciones(SArgsSiscom *pSAgsSiscom);

void SQLGeneraActualizaObservaciones(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
void SQLObservacionesConsulta(SArgsSiscom *);
void SQLExpediente(SArgsSiscom *);
void SQLRecetasPaciente(SArgsSiscom *);
#endif
