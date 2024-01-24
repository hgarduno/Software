#ifndef __ALUMNOS_H__
#define __ALUMNOS_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OPRegistraAlumno();
SiscomOperaciones2 *OPRegistraAlumnoSiscom();
SiscomOperaciones2 *OPRegistraAlumno2();
SiscomOperaciones2 *OPAlumnosExpendio();
SiscomOperaciones2 *OpRegistraAlumnoCurso();
SiscomOperaciones2 *OpInscribeClienteCurso();
SiscomOperaciones2 *OpAlumnoYaRegistrado();
SiscomOperaciones2 *OpValidaCamposMinimosRegistroAlumno();

SiscomOperaciones2 *OpDatosAlumno();
void ConsultaAlumno(SArgsSiscom *);
void ArgumentosConsultaAlumno(SArgsSiscom *);

void RegistraAlumno(SArgsSiscom *);
void AlumnoYaRegistrado(SArgsSiscom *);


void AsignaCodigosErrorAlumnoCurso(SArgsSiscom *pSAgsSiscom);


void SiscomDescartaRegistrosSimilares(SArgsSiscom *pSAgsSiscom);
void ValidaCamposMinimosRegistroAlumno(SArgsSiscom *pSAgsSiscom);
#endif
