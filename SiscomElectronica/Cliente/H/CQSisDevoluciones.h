#ifndef __CQSISDEVOLCIONES_H__
#define __CQSISDEVOLCIONES_H__
#include <SiscomOperaciones3.h>

class CQSisDevolviendo:public SiscomOperaciones3
{
public:
	CQSisDevolviendo(SiscomDatCom *);

	void CalculaDevolucion(SiscomRegistro3Lst *,
			       SiscomRegistro3Lst *);

	void Devuelve(SiscomRegistro3Lst *);
			       
};
#endif
