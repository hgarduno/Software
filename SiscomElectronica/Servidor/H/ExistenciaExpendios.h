#ifndef __EXISTENCIAEXPENDIOS_H__
#define __EXISTENCIAEXPENDIOS_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void ExistenciaExpendios(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);


void ExistenciaSiscom(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void ExistenciaSiscomT(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int ExistenciaProductoExpendios(SiscomOperaciones *pSiscomOpePtrDato);
int ExistenciasVentasExpendios(SiscomOperaciones *pSiscomOpePtrDato);
int ExistenciasVentasExpendiosT(SiscomOperaciones *pSiscomOpePtrDato);
int CreaArgumentosExistenciaExpendios(SiscomOperaciones *pSiscomOpePtrDato);
void CondicionConsultaProductos(SiscomRegistroProL *pSiscomRegProLPtrDatos,char **pchrPtrCondicion);

int ErrorConexionExpendio(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
			  const char *pchrPtrCampoParaNombre,
			  SiscomOperaciones *pSiscomOpePtrDato);

int EstadoConsultaSistemaSiscom(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
			  const char *pchrPtrCampoParaNombre,
			  SiscomOperaciones *pSiscomOpePtrDato);
int EstadoConsultaSistemaSiscomT(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
			  const char *pchrPtrCampoParaNombre,
			  SiscomOperaciones *pSiscomOpePtrDato);

int ConexionExpendioConsultaSiscom(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
				   const char *pchrPtrCampoParaNombre,
				   SiscomOperaciones *pSiscomOpePtrDato);




char *ClausulaInProductos(SiscomRegistroProL *pSisRegProLPtrProductos,char **pchrPtrClausula);
char *AgregandoUnaCadena(const char *pchrPtrAgrega,char *pchrPtrCadena);



void ExistenciaExpendiosAlLog(const char *pchrPtrArchivo,
			  const char *pchrPtrFuncion,
			  int pintLineaN,
			  SiscomRegistroProL *pSisRegProLPtrDatos);


#define ExistenciaExpendiosLog(pSiscomRegProLPtrDatos) 	\
ExistenciaExpendiosAlLog(__FILE__,				\
		     __FUNCTION__,			\
		     __LINE__,				\
		     pSiscomRegProLPtrDatos)
#endif
