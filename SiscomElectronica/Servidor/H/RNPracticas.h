#ifndef __RNPRACTICAS_H__
#define __RNPRACTICAS_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>

void ConsultaPracticas(int,int);
void RegistraPracticas(int,int);
void RegistraDetallePractica(int,int);
int EsConsultaPracticas(char **);
int EsCotizaPractica(char **);
void CotizaLaPractica(char **,SiscomOperacionesServidor *);
void FormaConsultaPracticas(char **,SiscomOperacionesServidor *);


#endif
