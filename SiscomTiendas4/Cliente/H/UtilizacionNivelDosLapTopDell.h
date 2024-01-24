#ifndef __UTILIZACIONNIVELDOSLAPTOPDELL_H__
#define __UTILIZACIONNIVELDOSLAPTOPDELL_H__
#include <CQSisPerfilUtilizacion.h>
extern "C"
{

CQSisPerfilVentas *UtilizacionNivelDos();
void NivelDosPrincipal(void *);
void SiscomValidaAutenticidad(const char *);
void SiscomValidaMacAddres(const char *);
int SiscomEsSistemaMultiUsuario();

}

#endif
