#ifndef __SQLREGISTRAUSUARIO_H__
#define __SQLREGISTRAUSUARIO_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>


int SqlRegistraUsuarioSiscom(SiscomOperaciones *pSiscomOpePtrDato);
void SqlFormaConsultaAplicacionSeguridad3(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
void SqlFormaConsultaPerfilSeguridad3(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
void SqlDatosAplicacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraSeguridad3(SiscomOperaciones *pSiscomOpePtrDato);
int SqlExpendiosSiscomElectronica(SiscomOperaciones *pSiscomOpePtrDato);

void InsertToFirmas(SiscomOperaciones *pSiscomOpePtrDato,
		   SiscomRegistroProL *pSisRegProLPtrDato,
		   char *pchrPtrSql);

void InsertToFirmasSeguridad3(SiscomOperaciones *pSiscomOpePtrDato,
			      SiscomRegistroProL *pSiscomRegProLPtrDato,
			      char *pchrPtrSql);
void InsertToUsuarios(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToPersonaSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSisRegProLPtrDato,
			   char *pchrPtrSql);
#endif
