#ifndef __SERVICIOS_H__
#define __SERVICIOS_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OpServicios();
SiscomOperaciones2 *OpRegistraAlumnoServicio();
SiscomOperaciones2 *OpAlumnosServicioSinRegSalida();
SiscomOperaciones2 *OpRegistraSalidaServicio();
void RegistraAlumnoServicio(SArgsSiscom *pSAgsSiscom);
void ArgumentosAlumnoServicio(SArgsSiscom *pSAgsSiscom);
void GeneraIdRegistroServicio(SArgsSiscom *pSAgsSiscom);
void AsignaHoraEntrada(SArgsSiscom *pSAgsSiscom);
void AsignaHoraSalida(SArgsSiscom *pSAgsSiscom);
void RegresaInformacionRegistro(SArgsSiscom *pSAgsSiscom);
void AsignaAAlArgumento(SArgsSiscom *pSAgsSiscom);
void AsignaCampoIdPersona(SArgsSiscom *pSAgsSiscom);
const char *CampoIdPersona(SArgsSiscom *);
const char *AAlArgumentoPersonales(SArgsSiscom *);
#endif
