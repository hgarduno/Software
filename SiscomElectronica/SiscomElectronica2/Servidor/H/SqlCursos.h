#ifndef __SQLCURSOS_H__
#define __SQLCURSOS_H__
#include <SiscomDesarrollo2.h>

void SqlCursos(SArgsSiscom *);
void SqlFechasCursos(SArgsSiscom *pSAgsSiscom);
void SqlFechasCursos2(SArgsSiscom *pSAgsSiscom);
void SqlCostosCursos(SArgsSiscom *pSAgsSiscom);
void SqlVentasCursos(SArgsSiscom *pSAgsSiscom);
void SqlCursosProgramados(SArgsSiscom *pSAgsSiscom);
void SqlExplicacionPromocion(SArgsSiscom *pSAgsSiscom);
void SqlDisponibilidadCursos(SArgsSiscom *pSAgsSiscom);
void SqlAlumnoRegistrado(SArgsSiscom *pSAgsSiscom);

void SqlRegistraAlumnoInscrito(SArgsSiscom *pSAgsSiscom);
void SqlAlumnosInscritosCurso(SArgsSiscom *pSAgsSiscom);
void SqlRegistraProgramacionCursos(SArgsSiscom *pSAgsSiscom);
void SqlProgramandoCurso(SArgsSiscom *pSAgsSiscom);
void SqlRegistraFechasCursos(SArgsSiscom *pSAgsSiscom);
void SqlRegistraCostosCursos(SArgsSiscom *pSAgsSiscom);
void SqlIniciaCostoCurso(SArgsSiscom *pSAgsSiscom);

void SqlRegistraHorariosCursos(SArgsSiscom *pSAgsSiscom);


void SqlDecrementaDisponibles(SArgsSiscom *pSAgsSiscom);
void SqlCursosEnEsaFecha(SArgsSiscom *pSAgsSiscom);
void SqlProgramacionCurso(SArgsSiscom *pSAgsSiscom);

void SqlInsertIntoAlumnoInscritoCurso(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);


void SqlUpdateFechasCursosDisponibles(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);



void SqlInsertIntoRegistroProgramaCurso(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);


void SqlInsertIntoProgramacionCursos(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);


void SqlInsertandoInicioCostoCurso(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);

void SqlInsertIntoFechasCursos(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);



void SqlInsertIntoCostosCursos(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros);
#endif
