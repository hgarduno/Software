#ifndef __CQSISHISTRANSFERENCIAS_H__
#define __CQSISHISTRANSFERENCIAS_H__
#include <SiscomOperaciones3.h>
#include <SiscomRegistros3.h>
class CQSisHisTransferencias:public SiscomOperaciones3
{
public:
	CQSisHisTransferencias(SiscomDatCom *);

	void MaterialTransferido(const char *pchrPtrFecha,
				 const char *pchrPtrFechaFin,
				 const char *pchrPtrIdExpendio,
				 const char *pchrPtrIdExpendioAConsultar,
				 SiscomRegistro3Lst *pSisReg3LstRegreso);
};

#endif
