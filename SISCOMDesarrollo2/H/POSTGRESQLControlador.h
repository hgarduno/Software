#ifndef __POSTGRESQLCONTROLADOR_H__
#define __POSTGRESQLCONTROLADOR_H__
#include <libpq-fe.h>
#include <SiscomDesarrollo2.h>
void ControladorComandosSQL(
		const char *,
		const char *,
		LCamposSiscomPro2 *);
void ControladorEjecutaConsulta(
		const char *,
		const char *,
		LCamposSiscomPro2 *,
		int *,
		int*,
		LCamposSiscomPro2 **);

#endif 
