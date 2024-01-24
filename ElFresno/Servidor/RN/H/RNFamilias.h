#ifndef __RNFAMILIAS_H__
#define __RNFAMILIAS_H__
#include <FuncionesComunes.h>

#define RN_Familia_IdFamilia 	1
#define RN_Familia_NmbFamilia 	2
#define RN_Familia_DscFamilia 	3
#define RN_Familia_EdoRegistro 	4

const char *ObtenIdFamilia(char **);
const char *ObtenNmbFamilia(char **);
const char *ObtenDscFamilia(char **);
const char *ObtenEdoRegistro(char **);

StcLtaRegComSISCOM *RegistraFamilias(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ConsultaFamilias(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *GeneraRespuestaFamilias(int *);


#endif
