#ifndef __RNCORTEEXISTENCIAS_H__
#define __RNCORTEEXISTENCIAS_H__
#include <SiscomDesarrollo2.h>
#include <RNComunElFresno.h>




void ConsultaCorteExistencias(int,int);
void CorteExistencias(int,int);
int EsConsultaFechasCorte(char **);
void FormaConsultaFechasCorte(char **,SiscomOperacionesServidor *);

void FijaFechaCorte(int,int);
#endif
