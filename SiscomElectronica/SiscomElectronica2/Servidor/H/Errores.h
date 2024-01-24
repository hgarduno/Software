#ifndef __ERRORES_H_
#define __ERRORES_H_
#include <SiscomDesarrollo2.h>

/*
 *
 *
 */


void EnviaMensajeErrorCliente(const char *,
			      const char *,
			      SArgsSiscom *);
void ErrorDatosPersonalesInvalidos(SArgsSiscom *);
void ErrorPersonaEnNormalizados(SArgsSiscom *);
void ErrorPasswordDiferente(SArgsSiscom *);
void ErrorPasswordVacio(SArgsSiscom *);
void ErrorFirmaYaRegistrada(SArgsSiscom *);

void ManejadorErrores(SArgsSiscom *);


#endif
