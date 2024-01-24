#ifndef __REGISTRACURSOS_H__
#define __REGISTRACURSOS_H__
#include <SiscomDesarrollo2.h>

void RegistraHorarioCurso(SArgsSiscom *pSAgsSiscom);
void ProgramandoCurso(SArgsSiscom *pSAgsSiscom);
void ArgumentosProgramandoCursos(SArgsSiscom *pSAgsSiscom);
void ArgumentosHorariosCursos(SArgsSiscom *pSAgsSiscom);

LCamposSiscomPro2 *VerificaHorariosEliminados(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					      char **pchrPtrHoraIniEliminar,
					      char **pchrPtrHoraFinEliminar);

int AjustaHorariosCurso(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 const char *pchrPtrHoraIniEliminar,
			 const char *pchrPtrHoraFinEliminar);
#endif
