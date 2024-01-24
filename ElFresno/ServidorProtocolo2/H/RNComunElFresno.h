#ifndef __RNCOMUNELFRESNO_H__
#define __RNCOMUNELFRESNO_H__
typedef struct Consultas
{
     int (*Consulta)(char **);
     void (*FormaConsulta)(char **,SiscomOperacionesServidor *);
}StcConsultas;

#endif
