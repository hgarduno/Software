#include <CQSisOpeCursos.h>
#include <CQSisCursosDiaHora.h>
CQSisOpeCursos::CQSisOpeCursos(SiscomDatCom *pSisDatCom):
			  SiscomOperaciones3(pSisDatCom)
{


}
void CQSisOpeCursos::RegistraHorariosCursos(CQSisCursosDiaHora *pCQSisCuDiaHora)
{
SiscomRegistro4 lSisReg4Regreso;
SiscomEnvia("RegistraHorarioCurso",
	    0,
	    pCQSisCuDiaHora,
	    &lSisReg4Regreso);
}
