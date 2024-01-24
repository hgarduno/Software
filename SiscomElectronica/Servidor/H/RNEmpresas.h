#ifndef __RNEMPRESAS_H__
#define __RNEMPRESAS_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>

void ConsultaEmpresas(int,int);
void RegistraEmpresas(int,int);
int EsConsultaEmpresas(char **);
void FormaConsultaEmpresas(char **,SiscomOperacionesServidor *);

int EsConsultaProveedores(char **);
void FormaConsultaProveedores(char **,SiscomOperacionesServidor *);

int EsConsultaMatriz(char **);
void FormaConsultaMatriz(char **,SiscomOperacionesServidor *);
#endif
