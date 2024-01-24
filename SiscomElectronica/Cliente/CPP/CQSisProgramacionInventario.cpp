#include <CQSisProgramacionInventario.h>
CQSisProgramacionInventario::CQSisProgramacionInventario(
				SiscomRegistro3 *pSisReg3Expendio,
				SiscomRegistro3 *pSisReg3Motivo,
				const char *pchrPtrDescripcion)
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaRegistro(0,pSisReg3Expendio);
SiscomAgregaRegistro(1,pSisReg3Motivo);
SiscomAgregaRegistro(2,ProgramacionInventario(pchrPtrDescripcion));
}
SiscomRegistro3 *CQSisProgramacionInventario::ProgramacionInventario(
						const char *pchrPtrDescripcion)
{
SiscomRegistro3 *lSisReg3PInventario=new SiscomRegistro3;
(*lSisReg3PInventario)				<<
new SiscomCampo3("Descripcion",pchrPtrDescripcion);

return lSisReg3PInventario;
}

void CQSisProgramacionInventario::EdoOperacion(SiscomRegistro4 *pSisReg4EdoOperacion)
{
	SisReg4EdoOperacion=pSisReg4EdoOperacion;
}

CQSisOpProgramacionInventario::CQSisOpProgramacionInventario(SiscomDatCom *pSisDatCom):
				SiscomOperaciones3(pSisDatCom)
{

}

void CQSisOpProgramacionInventario::Registra(CQSisProgramacionInventario *pCQSProgInventario)
{
SiscomRegistro4 *lSisReg4Regreso=new SiscomRegistro4;
SiscomEnvia("RegistraProgramacionInventario",
	     0,
	     pCQSProgInventario,
	     lSisReg4Regreso);
lSisReg4Regreso->first();
pCQSProgInventario->EdoOperacion(lSisReg4Regreso);
}
