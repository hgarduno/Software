#ifndef __RNSISCOMSEGURIDAD3PROT2_H__
#define __RNSISCOMSEGURIDAD3PROT2_H__
#include <SiscomDesarrollo2.h>

void ConsultaSeguridad3Pro2Version2(int,int);
void ConsultaSeguridad3Pro2(int,int);
void RegistraSeguridad3Pro2(int,int);
int EsConsultaSeguridad3Pro2(char **);
void FormaConsultaSeguridad3Pro2(char **,SiscomOperacionesServidor *);

int EsConsultaPerfilesSeguridad3Pro2(char **);
void FormaConsultaPerfilesSeguridad3Pro2(char **,SiscomOperacionesServidor *);
int EsConsultaUsuariosPerfil(char **);
void FormaConsultaUsuariosPerfil(char **,SiscomOperacionesServidor *);

int EsConsultaValidaFirma(char **);
void FormaConsultaValidaFirma(char **,SiscomOperacionesServidor *);

char *ObtenBaseDatosSeguridad3();

#endif
