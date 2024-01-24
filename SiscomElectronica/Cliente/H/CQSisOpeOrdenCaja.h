#ifndef __CQSISOPEORDENCAJA_H__
#define __CQSISOPEORDENCAJA_H__
#include <SiscomOperaciones3.h>
#include <SiscomRegistros.h>

class CQSisDatosOrdenCaja;
class CQSisOrdenCaja;

class CQSisOpeOrdenCaja:public SiscomOperaciones3
{
public:
	CQSisOpeOrdenCaja(SiscomDatCom *pSisDatCom);
	void OrdenesPendientes(CQSisDatosOrdenCaja *pCQDOCaja,
			       CQSisOrdenCaja *);
	void VendeOrden(CQSisDatosOrdenCaja *pCQDOCaja);
private:
	SiscomRegistro4 SisReg4EdoConexion;
			
};

#endif
