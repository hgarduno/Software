#ifndef __RNTRANSFIEREPRODUCTOS_H__
#define __RNTRANSFIEREPRODUCTOS_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>

void ConsultaTransfiereProductos(int,int);
void TransfiereProductos(int,int);
void ValidaExistencia(int,int);
int EsConsultaTransfiereProductos(char **);
void FormaConsultaTransfiereProductos(char **,SiscomOperacionesServidor *);
int ValidandoExistenciaExpendio(LCamposSiscomPro2 *pLCSiscomPro2Productos,
				int pintSocket,
				SArgsSiscom *pSAgsSiscom);

void ArgumentosValidaExistenciaExpendio(SArgsSiscom *pSAgsSiscom);
#endif
