#ifndef __SQLIMPRESION_H__
#define __SQLIMPRESION_H__
#include <SiscomDesarrollo2.h>

void SqlTicketYaRegistrado(SArgsSiscom *pSAgsSiscom);


void SqlInsertaTicketImpreso(SArgsSiscom *pSAgsSiscom);
void SqlInsertaTicketImpresoTotal(SArgsSiscom *pSAgsSiscom);
void SqlInsertaTicketImpresoHistorial(SArgsSiscom *pSAgsSiscom);


void SqlInsertandoTicketImpreso(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
				LCamposSiscomPro2 **pLCSiscomPro2DatAct,
				int *pintPtrNRegistros);

void SqlInsertandoTicketImpresoTotal(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
				LCamposSiscomPro2 **pLCSiscomPro2DatAct,
				int *pintPtrNRegistros);
void SqlInsertandoTicketImpresoHistorial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
				LCamposSiscomPro2 **pLCSiscomPro2DatAct,
				int *pintPtrNRegistros);
#endif
