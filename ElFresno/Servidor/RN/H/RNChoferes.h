#ifndef __RNCHOFERES_H__
#define __RNCHOFERES_H__
#include <FuncionesComunes.h>
#include <RNComunFresno.h>
#include <RNVarios.h>

StcLtaRegComSISCOM *OperacionesChoferes(int ,const char *,StcLtaRegComSISCOM *,int *);
int EsConsultaTodosLosChoferes(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **);
void EjecutaConsultaTodosLosChoferes(int,
					const char *,
					const char *,
					StcLtaRegComSISCOM *,
					StcLtaRegComSISCOM **,
					int *);

void FormaRespuestaTodosLosChoferes(int,
				    	const char *,
					int,
					StcLtaRegComSISCOM *,
					StcLtaRegComSISCOM **,
					int *);
#endif
