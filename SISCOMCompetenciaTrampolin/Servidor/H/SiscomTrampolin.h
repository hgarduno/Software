#ifndef __SISCOMTRAMPOLIN_H__
#define __SISCOMTRAMPOLIN_H__
#include <SiscomDesarrollo2.h>
#include <Sepomex.h>
#include <Gimnasios.h>
#include <Entrenadores.h>
#include <Gimnastas.h>
#include <Competencias.h>
#include <Compitiendo.h>
#include <Jueces.h>
#include <Calificaciones.h>
#include <Rondas.h>


void OperacionesSistemaGeneral(SSiscomOperaciones **);
void AsignaOperacionesVersion2(int ,
				int,
				SSiscomOperaciones2 **,
				SArgsSiscom *);
void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr);
#endif
