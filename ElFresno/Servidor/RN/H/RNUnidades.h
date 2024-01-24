#ifndef __RNUNIDADES_H__
#define __RNUNIDADES_H__
#include <FuncionesComunes.h>
#define RN_Unidades_Unidad		1
#define RN_Unidades_NmbUnidad		2
#define RN_Unidades_Abreviatura		3
#define RN_Unidades_EdoRegistro		4

const char *ObtenUnidad(char **);
const char *ObtenNmbUnidad(char **);
const char *ObtenAbreviatura(char **);
const char *ObtenEdoRegistroUnidad(char **);

StcLtaRegComSISCOM *RegistraUnidades(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ConsultaUnidades(int,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *GeneraRespuestaUnidades(int *);
void AnexaRegistroUnidad(char **,int,int *,StcLtaRegComSISCOM **,StcLtaRegComSISCOM **);
#endif
