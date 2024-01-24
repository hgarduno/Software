#ifndef __UTILIZACIONVENTAS_H__
#define __UTILIZACIONVENTAS_H__

#include <CQSisPerfilUtilizacion.h>
/*
extern "C" CQSisPerfilVentas *UtilizacionNivelUno();
extern "C" CQSisPerfilVentas *UtilizacionNivelDos();

extern "C" void NivelUnoPrincipal(void *);
extern "C" void NivelDosPrincipal(void *);

extern "C"  void SiscomValidaAutenticidad(const char *);
extern "C"  void SiscomValidaMacAddres(const char *);
*/
extern "C"
{
CQSisPerfilVentas *UtilizacionNivelUno();
CQSisPerfilVentas *UtilizacionNivelDos();
void NivelUnoPrincipal(void *);
void NivelDosPrincipal(void *);
void SiscomValidaAutenticidad(const char *);
void SiscomValidaMacAddres(const char *);
int SiscomEsSistemaMultiUsuario();
}

#endif
