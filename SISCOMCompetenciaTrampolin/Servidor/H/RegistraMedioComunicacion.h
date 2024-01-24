#ifndef __REGISTRAMEDIOCOMUNICACION_H__
#define __REGISTRAMEDIOCOMUNICACION_H__
#include <SiscomDesarrollo2.h>

void RegistraMedioComunicacion(SArgsSiscom *);
void RegistraMedioComunicacion2(SArgsSiscom *);
int ObtenIdMedioComunicacion(LCamposSiscomPro2 *,
			      char *);
int ValidaMedioComunicacionNoVacio(LCamposSiscomPro2 *);
void AnexaComunicacionPersona(SArgsSiscom *);
#endif
