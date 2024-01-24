#ifndef __CURSOS_H__
#define __CURSOS_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OpCursos();
SiscomOperaciones2 *OpFechasCursos();
SiscomOperaciones2 *OpAlumnosInscritosCurso();
SiscomOperaciones2 *OpDisponibilidadCursos();
SiscomOperaciones2 *OpVentasCursos();
SiscomOperaciones2 *OpFechasCostosCursos();
SiscomOperaciones2 *OpCostosCurso();
SiscomOperaciones2 *OpCursosProgramados();
SiscomOperaciones2 *OpRegistraProgramacionCursos();
SiscomOperaciones2 *OpCursosProgramadosFechaRegistro();
SiscomOperaciones2 *OpConsultaCursosProgramados();
SiscomOperaciones2 *OpExplicacionPromocion();
SiscomOperaciones2 *OpRegistraCostosCurso();
SiscomOperaciones2 *OpRegistraHorarioCurso();
SiscomOperaciones2 *OpProgramandoCurso();


void ArgumentosFechasCursos(SArgsSiscom *pSAgsSiscom);
void ArgumentosRegistraProgramacionCursos(SArgsSiscom *pSAgsSiscom);
void ArgumentosRegistraHorarioCursos(SArgsSiscom *pSAgsSiscom);
void ArgumentosRegistraCostosCursos(SArgsSiscom *pSAgsSiscom);

void RegistraCostosCurso(SArgsSiscom *pSAgsSiscom);
void FormaVentasCursos(SArgsSiscom *pSAgsSiscom);
void ArgumentosVentasCursos(SArgsSiscom *pSAgsSiscom);
void EnviaVentasCursos(SArgsSiscom *pSAgsSiscom);
void EnviaCostosCurso(SArgsSiscom *pSAgsSiscom);

void EnviaFechasCursos(SArgsSiscom *pSAgsSiscom);
void CalculaImporteCurso(SArgsSiscom *pSAgsSiscom);
void TotalCursosYParticipacionSiscom(SArgsSiscom *pSAgsSiscom);
void RegistraProgramacionCursos(SArgsSiscom *pSAgsSiscom);
void AsignaIdRegistroProgramacionCurso(SArgsSiscom *pSAgsSiscom);
void CursosProgramadosFechaRegistro(SArgsSiscom *pSAgsSiscom);
void GeneraHorariosDiasSemana(SArgsSiscom *pSArgsSiscom);

void AgregaNodoTotalCurso(const char *pchrPtrIdCurso,
			     float pfltTotalCurso,
			     LCamposSiscomPro2 *pLCSiscomPro2Anterior,
			     LCamposSiscomPro2 *pLCSiscomPro2Siguiente);

const char *ObtenIdProgramacionCurso(SArgsSiscom *pSAgsSiscom,const char *pchrPtrIdCurso);
#endif
