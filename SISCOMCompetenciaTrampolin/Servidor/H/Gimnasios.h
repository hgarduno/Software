#ifndef __GIMNASIOS_H__
#define __GIMNASIOS_H__
#include <SiscomDesarrollo2.h>

void InsertaGimnasio(SArgsSiscom *);
void InsertaGimnasioPrueba(SArgsSiscom *);
void AsignaIdentificadores(SArgsSiscom *);
void AsignaArgumentosOperaciones(SArgsSiscom  *);
void NormalizaContacto(SArgsSiscom *);

void ComunicacionAccesoDatos(SArgsSiscom *);


void EnviaError(SArgsSiscom *);

void ArmaEnvioErrores(SArgsSiscom *);
SiscomOperaciones2 *GeneraOperacionesGimnasio();

void ConsultaGimnasio(SArgsSiscom *);
SiscomOperaciones2 *GeneraConsultasGimnasio();
void ConsultaNoSoportada(SArgsSiscom *);

#endif
