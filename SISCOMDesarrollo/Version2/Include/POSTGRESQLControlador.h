#ifndef __POSTGRESQLCONTROLADOR_H__
#define __POSTGRESQLCONTROLADOR_H__
#include <libpq-fe.h>
#include <FuncionesComunes.h>
void ControladorComandosSQL(const char *,StcLtaRegComSISCOM *);
void ControladorEjecutaConsulta(const char *,StcLtaRegComSISCOM *,int *,int*,StcLtaRegComSISCOM **);

#endif 
