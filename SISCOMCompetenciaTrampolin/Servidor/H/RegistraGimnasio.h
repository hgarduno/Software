#ifndef __REGISTRAGIMANSIO_H__
#define __REGISTRAGIMANASIO_H__
#include <SiscomDesarrollo2.h>

void RegistraGimnasio(SArgsSiscom *);

int VerificaNombreGimnasio(SArgsSiscom *);
int SeVerificaNombreGimnasio(LCamposSiscomPro2 *);
int VerificandoNombreGimnasio(SArgsSiscom *);
void CreaCondicionConsulta(const char *,char *);
#endif
