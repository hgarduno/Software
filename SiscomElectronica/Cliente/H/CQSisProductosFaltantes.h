#ifndef __CQSISPRODUCTOSFALTANTES_H__
#define __CQSISPRODUCTOSFALTANTES_H__
#include <SiscomRegistros4.h>
#include <SiscomOperaciones3.h>

class SiscomRegistro3Lst;


class CQSisProductosFaltantes:public SiscomRegistro4
{
public:
	CQSisProductosFaltantes();

};

class CQSisProductosFaltantesOp:public SiscomOperaciones3
{
public:
	CQSisProductosFaltantesOp(SiscomDatCom *pSisDatCom);
	void Faltantes(const char *pchrPtrIdExpendio,CQSisProductosFaltantes *pCQSProdsFaltantes);
};


#endif

