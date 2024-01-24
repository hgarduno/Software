#ifndef __CQSISFACTURAS_H__
#define __CQSISFACTURAS_H__
#include <SiscomOperaciones3.h>
class SiscomRegistro3Lst;

class CQSisFacturando:public SiscomOperaciones3
{
public:
	CQSisFacturando(SiscomDatCom *);
	void Facturas(const char *pchrPtrIdExpendio,
		      const char *pchrPtrFechaIni,
		      const char *pchrPtrFechaFin,
		      const char *pchrPtrIdProveedor,
		      SiscomRegistro3Lst *);
	void DetalleFactura(const char *pchrPtrIdExpendio,
			    const char *pchrPtrNumFactura,
			    const char *pchrPtrFechaHora,
			    SiscomRegistro3Lst *pSisReg3LstDFactura);
	void ActualizaNumeroFactura(SiscomRegistro3 *);
	void BuscaFacturas(const char *pchrPtrIdExpendio,
			   const char *pchrPtrNumFactura,
			   SiscomRegistro3Lst *pSisReg3LstFacturas);
	void AnexaFacturasContabilidad(SiscomRegistro3Lst *pSisReg3LstFacturas);
				    
				    
};
#endif
