#ifndef __REGISTRAPERSONA_H__
#define __REGISTRAPERSONA_H__
#include <SiscomDesarrollo2.h>

void RegistraPersona(SArgsSiscom *);

int VerificaNombre(SArgsSiscom *);
void InsercionPersonaNormalizada(const char *,
				 LCamposSiscomPro2 *,
				 LCamposSiscomPro2 **,
				 LCamposSiscomPro2 **,
				 int *);
void InsercionPersonas(const char *,
			LCamposSiscomPro2 *,
				 LCamposSiscomPro2 **,
				 LCamposSiscomPro2 **,
				 int *);

void ObtenFechaNacimiento(LCamposSiscomPro2 *,char *);
#endif
