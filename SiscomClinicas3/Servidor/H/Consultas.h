#ifndef __CONSULTAS_H__
#define __CONSULTAS_H__
#include <SiscomDesarrollo2.h>

typedef struct TiposConsultas
{
	const char *chrPtrConsulta;
	void (*SQLConsulta)(SArgsSiscom *);
}StcTiposConsultas;
#define TipoConsulta	1
#define	FechaIni	2
#define FechaFin	3
#define Estado		4
#define IdMedico	5
typedef void (*SQLConsulta)(SArgsSiscom *);
SiscomOperaciones2 *OPConsultasPendientesMedico();
SiscomOperaciones2 *OPConsultas();
SiscomOperaciones2 *OPConsultaActualMedico();
SiscomOperaciones2 *OPActualizaEstadoConsulta();
SiscomOperaciones2 *OPRegistraExpediente();
SiscomOperaciones2 *OPObservacionesConsulta();
SiscomOperaciones2 *OPActualizaObservaciones();
SiscomOperaciones2 *OPTerminaConsulta();
SiscomOperaciones2 *OPMaterialServicioHospitalizacion();
SiscomOperaciones2 *OPMaterialHospitalizado();
SiscomOperaciones2 *OPMaterialHospSesion();
SiscomOperaciones2 *OPRegistraReceta();
SiscomOperaciones2 *OPActualizaReceta();
SiscomOperaciones2 *OPRecetaConsulta();
SiscomOperaciones2 *OPExpediente();
SiscomOperaciones2 *OPRecetasPaciente();

void RegistraConsultas(SArgsSiscom *);
void GeneraIdConsulta(SArgsSiscom *);
void ArgumentosConsultas(SArgsSiscom *);
void FechaRegistro(SArgsSiscom *);
void SeleccionaConsulta(SArgsSiscom *);

void EliminaCaracteresInvalidos(const char *,SArgsSiscom *);
void EliminaCaracteresInvalidosObservaciones(SArgsSiscom *);
void EliminaCaracteresInvalidosReceta(SArgsSiscom *);
SQLConsulta ObtenTipoConsulta(StcTiposConsultas *,
			      char **);

#endif
