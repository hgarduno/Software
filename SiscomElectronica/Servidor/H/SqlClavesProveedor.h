#ifndef __SQLCLAVESPROVEEDOR_H__
#define __SQLCLAVESPROVEEDOR_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlRegistraClavesProveedor(SiscomOperaciones *pSiscomOpePtrDato);
int SqlConsultaClaveProveedor(SiscomOperaciones *pSiscomOpePtrDato);
int SqlActualizaClaveProveedor(SiscomOperaciones *pSiscomOpePtrDato);
void InsertToClavesProveedor(SiscomOperaciones *pSiscomOpePtrDato,
			     SiscomRegistroProL *pSiscomRegProLPtrDato,
			     char *pchrPtrSql);

void UpdateClaveProveedor(SiscomOperaciones *pSiscomOpePtrDato,
			     SiscomRegistroProL *pSiscomRegProLPtrDato,
			     char *pchrPtrSql);

void SqlFormaConsultaProductoClaveProveedor(SiscomOperaciones *pSiscomOpePtrDato,char *);
#endif
