#ifndef __CQSISOPEPRODUCTONOSINCRONIZADO_H__
#define __CQSISOPEPRODUCTONOSINCRONIZADO_H__
#include <SiscomOperaciones3.h>
class SiscomDatCom;
class SiscomRegistro4;
class CQSisProductoNoSincronizado;
class CQSisOpeProductoNoSincronizado:public SiscomOperaciones3
{
public:
	CQSisOpeProductoNoSincronizado(SiscomDatCom *pSisDatCom);
	void ProductosNoSincronizados(const char *pchrPtrIdExpendio,
		CQSisProductoNoSincronizado *pCQSPNSincronizado);
	void EjecutaSincronizacion(const char *pchrPtrIdExpendio,SiscomRegistro4 *pSisReg4EdoRegistro);

};

#endif
