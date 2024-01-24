#ifndef __CQSISPROMOCIONES_H__
#define __CQSISPROMOCIONES_H__
#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>
class CQSisPromocion:public SiscomRegistro3
{
public:
	CQSisPromocion(const char *pchrPtrIdExpendio,
			const char *pchrPtrIdPromocion,
		       const char *pchrPtrNombre,
		       const char *pchrPtrFechaIni,
		       const char *pchrPtrFechaFin,
		       const char *pchrPtrPuntos,
		       const char *pchrPtrDescripcion);

};


class CQSisOpPromocion:public SiscomOperaciones3
{
public:
	CQSisOpPromocion(SiscomDatCom *pSisDatCom);
	void Registra(CQSisPromocion *,
		      SiscomRegistro3Lst *pSisReg3LstRegreso);			 

};

#endif
