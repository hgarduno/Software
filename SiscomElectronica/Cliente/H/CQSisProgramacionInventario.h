#ifndef __CQSISPROGRAMACIONINVENTARIO_H__
#define __CQSISPROGRAMACIONINVENTARIO_H__
#include <SiscomRegistros4.h>
#include <SiscomOperaciones3.h>

class CQSisProgramacionInventario:public SiscomRegistro4
{
public:
	CQSisProgramacionInventario(SiscomRegistro3 *pSisReg3Expendio,
				    SiscomRegistro3 *pSisReg3Motivo,
				    const char *pchrPtrDescripcion);

	void EdoOperacion(SiscomRegistro4 *pSisReg4EdoOperacion);	
private:
	SiscomRegistro3 *ProgramacionInventario(const char *pchrPtrDescripcion);
private:
	SiscomRegistro4 *SisReg4EdoOperacion;
};

class CQSisOpProgramacionInventario:public SiscomOperaciones3 
{
public:
	CQSisOpProgramacionInventario(SiscomDatCom *);
	void Registra(CQSisProgramacionInventario *);

};
#endif
