#ifndef __CQSISCONTABILIDAD_H__
#define __CQSISCONTABILIDAD_H__
#include <SiscomOperaciones3.h>

class SiscomRegistro3Lst;
class CQSisContabilidad:public SiscomOperaciones3
{
public:
	CQSisContabilidad(SiscomDatCom *);
	/*
	 * Por cuestion de tiempo solo se regresa 
	 * la informacion ...
	 */
	void Contabilidad(const char *pchrPtrIdExpendio,
			  SiscomRegistro3Lst *pSisReg3LstFactCompras,
			  SiscomRegistro3Lst *pSisReg3LstFactVentas,
			  SiscomRegistro3Lst *pSisReg3LstTotales,
			  SiscomRegistro3Lst *pSisReg3LstDatRegistro);

	void EjecutaProceso(const char *pchrPtrIdExpendio,
					const char *pchrPtrIdProceso);

};

#endif
