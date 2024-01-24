#ifndef __SISCOMTIENDAS4_H__
#define __SISCOMTIENDAS4_H__
#include <SiscomDesarrollo2.h>
#include <Sepomex.h>


void OperacionesSistemaGeneral(SSiscomOperaciones **);
void AsignaOperacionesVersion2(int ,
				int,
				SSiscomOperaciones2 **,
				SArgsSiscom *);
void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr);


#endif
