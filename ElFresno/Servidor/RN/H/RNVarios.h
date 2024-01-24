#ifndef __RNVARIOS_H__
#define __RNVARIOS_H__
#include <FuncionesComunes.h>

StcLtaRegComSISCOM *ConsultaTiposPrecios(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ConsultaGenericaALaBaseElFresno(int , const char *,const char *); 
StcLtaRegComSISCOM *ConsultaGenericaALaBaseElFresnoConNumeroRegistros(int ,
								      const char *,
								      const char *,
								      int *); 

#endif
