#ifndef __CQSISPROMOCIONESCLIENTE_H__
#define __CQSISPROMOCIONESCLIENTE_H__
#include <SiscomRegistros4.h>

class CQSisExpendio;
class SiscomRegistro3;
class SiscomRegistro3Lst;
class CQSisPromocionesCliente:public SiscomRegistro4
{
public:
	CQSisPromocionesCliente(SiscomRegistro3 *pSisReg3Expendio,
				SiscomRegistro3 *pSisReg3Cliente,
			        SiscomRegistro3Lst *pSisReg3LstPromociones,
				const char *pchrPtrPuntosTotProm);
	void EdoTomaPromociones(SiscomRegistro4 *pSisReg3EdoTomaPromcion);
private:

	SiscomRegistro4 *SisReg4EdoTomaPromocion;
private:
	SiscomRegistro3 *PuntosTotalesPromo(const char *);
};

#endif
