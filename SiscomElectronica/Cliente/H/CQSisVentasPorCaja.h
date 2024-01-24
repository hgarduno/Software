#ifndef __CQSISVENTASPORCAJA_H__
#define __CQSISVENTASPORCAJA_H__
#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>
/*!
 * Genera....
 */
class CQSisVentaCaja:public SiscomRegistro3
{
public:

	CQSisVentaCaja(const char *pchrPtrCaja,
		       const char *pchrPtrFecha,
		       const char *pchrPtrTotal,
		       const char *pchrPtrValidacion,
		       const char *pchrPtrEdoReporte);
private:

	void IniciaRegistroVentaCaja();
};
class CQSisOpVentaCaja:public SiscomOperaciones3
{
public:
	CQSisOpVentaCaja(SiscomDatCom *pSisDatCom);
	void VentasPorCaja(const char *pchrPtrFechaIni,
			   const char *pchrPtrFechaFin,
			   const char *pchrPtrIdExpendio,
			   SiscomRegistro3Lst *pSisReg3LstVentasCaja);
	void VentasPorCajaFecha(const char *pchrPtrFechaIni,
			   const char *pchrPtrFechaFin,
			   const char *pchrPtrIdExpendio,
			   SiscomRegistro3Lst *pSisReg3LstVentasCaja);

};
#endif


