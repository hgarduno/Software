#ifndef __SISTEMAACCESODATOS_H__
#define __SISTEMAACCESODATOS_H__
#include <SiscomDesarrollo2.h>

void OperacionesSistemaGeneral(SSiscomOperaciones **);

void EjecutaInserciones(int,int);
void EjecutaConsultas(int,int);

void EjecutaInsercionesBaseDatos(int,int);
void EjecutaConsultasBaseDatos(int,int);

#endif
