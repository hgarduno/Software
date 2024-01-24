#include <CQSisCostoCurso.h>
#include <SiscomCampos3.h>
CQSisCostoCurso::CQSisCostoCurso(const char *pchrPtrIdProgramacion,
				 const char *pchrPtrIdCurso):
				 chrPtrIdProgramacion(pchrPtrIdProgramacion),
				 chrPtrIdCurso(pchrPtrIdCurso)
{

}

void CQSisCostoCurso::CostoAlCurso(const char *pchrPtrIdPromocion,
				   const char *pchrPtrPromocion,
				   const char *pchrPtrCosto)
{
SiscomRegistro3 *lSisReg3CostoCurso=new SiscomRegistro3;
       (*lSisReg3CostoCurso)		<<
  	new SiscomCampo3("IdProgramacion",chrPtrIdProgramacion) 	<<
	new SiscomCampo3("IdCurso",chrPtrIdCurso)		   	<<
	new SiscomCampo3("IdPromocion",pchrPtrIdPromocion)	   	<<
  	new SiscomCampo3("Promocion",pchrPtrPromocion) 			<<
	new SiscomCampo3("Costo",pchrPtrCosto);
append(lSisReg3CostoCurso);
}
				     
