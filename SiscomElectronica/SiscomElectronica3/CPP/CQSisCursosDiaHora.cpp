#include <CQSisCursosDiaHora.h>

CQSisCursosDiaHora::CQSisCursosDiaHora():
			SiscomRegistro4()
{
}

const char *CQSisCursosDiaHora::Dia()
{
SiscomRegistro3 *lSisReg3Regreso;

 if((lSisReg3Regreso=RegistroPrincipal()))
 return (*lSisReg3Regreso)["Dia"];
 else
 return 0;
}
void CQSisCursosDiaHora::SiguienteDia()
{
    next();
}

SiscomRegistro3Lst *CQSisCursosDiaHora::Cursos()
{
SiscomRegistro3LstLst *lSisReg3LstLstDato=current();
SiscomRegistro3Lst *lSisReg3LstSubGrupo=lSisReg3LstLstDato->at(1);
return lSisReg3LstSubGrupo;
}

void CQSisCursosDiaHora::ActualizaEstatusHorario(int pintDia,
						 int pintHora,
						 const char *pchrPtrEstatus)
{

SiscomActualizaCampoSubRegistro(pintDia,1,pintHora,"IdEstatus",pchrPtrEstatus);

}
const char *CQSisCursosDiaHora::IdCurso(int pintDia,int pintHora)
{
return CampoRegistroSubGrupo(pintDia,1,pintHora,"IdCurso");
}
const char *CQSisCursosDiaHora::Curso(int pintDia,int pintHora)
{
return CampoRegistroSubGrupo(pintDia,1,pintHora,"Curso");
}
const char *CQSisCursosDiaHora::IdProgramacion(int pintDia,int pintHora)
{
return CampoRegistroSubGrupo(pintDia,1,pintHora,"IdProgramacion");
}
