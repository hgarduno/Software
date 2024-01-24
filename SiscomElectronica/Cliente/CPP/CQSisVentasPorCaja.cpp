#include <CQSisVentasPorCaja.h>
#include <SiscomParametroConsulta3.h>

CQSisVentaCaja::CQSisVentaCaja(const char *pchrPtrCaja,
			       const char *pchrPtrFecha,
			       const char *pchrPtrTotal,
			       const char *pchrPtrValidacion,
			       const char *pchrPtrEdoReporte)
{

	IniciaRegistroVentaCaja();
	SiscomActualizaCampo("Descripcion",pchrPtrCaja);
	SiscomActualizaCampo("Fecha",pchrPtrFecha);
	SiscomActualizaCampo("Total",pchrPtrTotal);
	SiscomActualizaCampo("Validacion",pchrPtrValidacion);
	SiscomActualizaCampo("EdoReporte",pchrPtrEdoReporte);

}

void CQSisVentaCaja::IniciaRegistroVentaCaja()
{

	(*this)					<<
	new SiscomCampo3("IdCaja","")		<<
	new SiscomCampo3("DireccionIp","")	<<
	new SiscomCampo3("Descripcion","")	<<
	new SiscomCampo3("IdVenta","")		<<
	new SiscomCampo3("Fecha","")		<<
	new SiscomCampo3("Cantidad","")		<<
	new SiscomCampo3("CveProducto","")	<<
	new SiscomCampo3("Importe","")		<<
	new SiscomCampo3("Total","")		<<
	new SiscomCampo3("Recibio","")		<<
	new SiscomCampo3("Cambio","")		<<
	new SiscomCampo3("EdoReporte","")	<<
	new SiscomCampo3("Validacion","");

}




CQSisOpVentaCaja::CQSisOpVentaCaja(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{


}

void CQSisOpVentaCaja::VentasPorCaja(const char *pchrPtrFechaIni,
				      const char *pchrPtrFechaFin,
				      const char *pchrPtrIdExpendio,
				      SiscomRegistro3Lst *pSisReg3LstVentasCaja)
{
SiscomRegistro3Lst lSReg3LstConsulta;

lSReg3LstConsulta 					<<
new SiscomParametroConsulta3("VentasPorCaja")		<<
new SiscomParametroConsulta3(pchrPtrIdExpendio)		<<
new SiscomParametroConsulta3(pchrPtrFechaIni)		<<
new SiscomParametroConsulta3(pchrPtrFechaFin);

SiscomEnvia("ConsultasSiscomElectronica2",
	    &lSReg3LstConsulta,
	    pSisReg3LstVentasCaja);
}

void CQSisOpVentaCaja::VentasPorCajaFecha(const char *pchrPtrFechaIni,
				      const char *pchrPtrFechaFin,
				      const char *pchrPtrIdExpendio,
				      SiscomRegistro3Lst *pSisReg3LstVentasCaja)
{
SiscomRegistro3Lst lSReg3LstConsulta;

lSReg3LstConsulta 					<<
new SiscomParametroConsulta3("VentasPorCajaFecha")	<<
new SiscomParametroConsulta3(pchrPtrIdExpendio)		<<
new SiscomParametroConsulta3(pchrPtrFechaIni)		<<
new SiscomParametroConsulta3(pchrPtrFechaFin);

SiscomEnvia("ConsultasSiscomElectronica2",
	    &lSReg3LstConsulta,
	    pSisReg3LstVentasCaja);
}
