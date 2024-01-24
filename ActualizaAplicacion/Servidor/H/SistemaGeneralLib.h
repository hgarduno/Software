#ifndef __SISTEMAGENERALLIB_H__
#define __SISTEMAGENERALLIB_H__
#include <SiscomDesarrollo2.h>


void OperacionesSistemaGeneral(SSiscomOperaciones **);

void OP_CreaDirectorioTrabajo(int,int);
void OP_CopiaModulo(int,int);
void OP_ObtenEstaciones(int,int);

void InsertaEstacion(int,int);
void ConsultaEstaciones(int,int);
void TransfiereAEstaciones(int,int);

#endif

