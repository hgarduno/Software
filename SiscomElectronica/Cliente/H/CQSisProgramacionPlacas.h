#ifndef __CQSISHISTRANSFERENCIAS_H__
#define __CQSISHISTRANSFERENCIAS_H__
#include <SiscomOperaciones3.h>
#include <SiscomRegistros3.h>
class CQSisProgramacionPlacas:public SiscomOperaciones3
{
public:
	CQSisProgramacionPlacas(SiscomDatCom *);

	void ProgramacionPlacas(const char *pchrPtrFecha,
				 const char *pchrPtrFechaFin,
				 const char *pchrPtrIdExpendio,
				 SiscomRegistro3Lst *pSisReg3LstRegreso);
	void EntregarPlaca(const char *pchrPtrIdExpendio,SiscomRegistro3 *pSisRegPlaca);
};

#endif
