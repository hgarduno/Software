#ifndef __RNPERSONAS2_H__
#define __RNPERSONAS2_H__
#include <FuncionesComunes.h>

const char *RNPersonas2RFC(StcLtaRegComSISCOM *);
const char *RNPersonas2Nombre(StcLtaRegComSISCOM *);
const char *RNPersonas2APaterno(StcLtaRegComSISCOM *);
const char *RNPersonas2AMaterno(StcLtaRegComSISCOM *);
const char *RNPersonas2Apodo(StcLtaRegComSISCOM *);
const char *RNPersonas2Calle(StcLtaRegComSISCOM *);
const char *RNPersonas2Numero(StcLtaRegComSISCOM *);
const char *RNPersonas2CP(StcLtaRegComSISCOM *);
const char *RNPersonas2Colonia(StcLtaRegComSISCOM *);
const char *RNPersonas2Municipio(StcLtaRegComSISCOM *);
const char *RNPersonas2Estado(StcLtaRegComSISCOM *);
const char *RNPersonas2Referencias(StcLtaRegComSISCOM *);
const char *RNPesonas2Telefono(StcLtaRegComSISCOM *);


StcLtaRegComSISCOM *OperacionesPersonas2(int,
					     const char *,
					     StcLtaRegComSISCOM *,
					     int *);
int EsRegistroPersonas2(int,
			    const char *,
			    char **,
			    char *,
			    StcLtaRegComSISCOM *,
			    StcLtaRegComSISCOM **,
			    int *);	
void RegistraPersonas2(int,
			   const char *,
			   const char *,
			   StcLtaRegComSISCOM *,
			   int,
			   StcLtaRegComSISCOM **,
			   int *);

void RespuestaGeneralPersonas2(int,
				   const char *,
				   int,
				   StcLtaRegComSISCOM *,
				   StcLtaRegComSISCOM **,
				   int *);

int EsConsultaPersonas2(int,
			    const char *,
			    char **,
			    char *,
			    StcLtaRegComSISCOM *,
			    StcLtaRegComSISCOM **,
			    int *);
void ConsultaPersonas2(int,
			   const char *,
			   const char *,
			   StcLtaRegComSISCOM *,
			   int,
			   StcLtaRegComSISCOM **,
			   int *);

/*
 *
 *
 *

void CreaConsultaOrdenesPorFecha(char **,
			       StcLtaRegComSISCOM *,
			       StcLtaRegComSISCOM **,
			       int *,
			       char *);
void CreaConsultaOrdenesAFacturar(char **,
				  StcLtaRegComSISCOM *,
				  StcLtaRegComSISCOM **,
				  int *,
				  char *);
*/
#endif
