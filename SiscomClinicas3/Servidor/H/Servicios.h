#ifndef __SERVICIOS_H__
#define __SERVICIOS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPServicio();
SiscomOperaciones2 *OPServiciosMedico();
SiscomOperaciones2 *OPServiciosRegistrados();
SiscomOperaciones2 *OPServiciosMedicoRegistrados();
SiscomOperaciones2 *OPPerfilServicioMedico();
void RegistraServicio(SArgsSiscom *);
void ArgumentosServicio(SArgsSiscom *);
void GeneraIdServicio(SArgsSiscom *);


#endif
