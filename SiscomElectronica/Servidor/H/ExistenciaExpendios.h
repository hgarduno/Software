#ifndef __EXISTENCIAEXPENDIOS_H__
#define __EXISTENCIAEXPENDIOS_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void ExistenciaExpendios(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);


int ExistenciaProductoExpendios(SiscomOperaciones *pSiscomOpePtrDato);
int CreaArgumentosExistenciaExpendios(SiscomOperaciones *pSiscomOpePtrDato);
void CondicionConsultaProductos(SiscomRegistroProL *pSiscomRegProLPtrDatos,char **pchrPtrCondicion);

int ErrorConexionExpendio(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
			  const char *pchrPtrCampoParaNombre,
			  SiscomOperaciones *pSiscomOpePtrDato);

int EstadoConsultaSistemaSiscom(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
			  const char *pchrPtrCampoParaNombre,
			  SiscomOperaciones *pSiscomOpePtrDato);

int ConexionExpendioConsultaSiscom(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
				   const char *pchrPtrCampoParaNombre,
				   SiscomOperaciones *pSiscomOpePtrDato);
#endif
