#ifndef __SQLIMPRESIONTICKETVENTA_H__
#define __SQLIMPRESIONTICKETVENTA_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlDireccionExpendio(SiscomOperaciones *pSiscomOpePtrDato);
int SqlTelefonosExpendio(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPuntosVentaImpresoras(SiscomOperaciones *pSiscomOpePtrDato);
int SqlEnviaRegistroImpresionTicket(SiscomOperaciones *pSiscomOpePtrDato);

int SqlImpresionTicket(SiscomOperaciones *pSiscomOpePtrDato);
int SqlImpresionesTicket(SiscomOperaciones *pSiscomOpePtrDato);
int SqlImpresionesTicketTotal(SiscomOperaciones *pSiscomOpePtrDato);
int SqlImpresionTicketHistorial(SiscomOperaciones *pSiscomOpePtrDato);




void InsertToTicketImpreso(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void InsertToImpresionesTicket(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void InsertToImpresionesTicketTotal(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void InsertToImpresionTicketHistorial(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
void InsertToImpresionTicketTotal(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql);
#endif
