#include <CQSisFacturas.h>

CQSisFacturando::CQSisFacturando(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{

}

void CQSisFacturando::Facturas(const char *pchrPtrIdExpendio,
			       const char *pchrPtrFechaIni,
			       const char *pchrPtrFechaFin,
			       const char *pchrPtrIdProveedor,
			       SiscomRegistro3Lst *pSisReg3LstRegreso)
{

SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstRegreso,
	    "%s%s%s%s%s",
	    "FacturasCompras",
	    pchrPtrIdExpendio,
	    pchrPtrFechaIni,
	    pchrPtrFechaFin,
	    pchrPtrIdProveedor);
}

void CQSisFacturando::DetalleFactura(const char *pchrPtrIdExpendio,
				     const char *pchrPtrNumFactura,
				     const char *pchrPtrFechaHora,
				     SiscomRegistro3Lst *pSisReg3LstDFactura)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstDFactura,
	    "%s%s%s%s",
	    "DetalleFactura",
	    pchrPtrIdExpendio,
	    pchrPtrNumFactura,
	    pchrPtrFechaHora);
}
void CQSisFacturando::BuscaFacturas(const char *pchrPtrIdExpendio,
				    const char *pchrPtrNumFactura,
				    SiscomRegistro3Lst *pSisReg3LstFacturas)
{
pSisReg3LstFacturas->clear();
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstFacturas,
	    "%s%s%s",
	    "BuscaFacturas",
	    pchrPtrIdExpendio,
	    pchrPtrNumFactura);

}
void CQSisFacturando::ActualizaNumeroFactura(
		SiscomRegistro3 *pSisReg3Factura
					     )
{
SiscomRegistro3Lst lSisReg3LstRegreso;

SiscomEnvia("ActualizaNumeroFactura",
	    pSisReg3Factura,
	    &lSisReg3LstRegreso);
}
void CQSisFacturando::AnexaFacturasContabilidad(SiscomRegistro3Lst *pSisReg3LstFacturas)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
SiscomEnvia("AnexaFacturasContabilidad",
	    pSisReg3LstFacturas,
	    &lSisReg3LstRegreso);
}	  
