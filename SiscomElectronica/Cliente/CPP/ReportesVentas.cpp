#include <ReportesVentas.h>

RegistroRepVenta::RegistroRepVenta(const char *pchrPtrCantidad,
				   const char *pchrPtrImporte,
				   const char *pchrPtrFecha,
				   const char *pchrPtrCveProducto,
				   const char *pchrPtrDscProducto,
				   const char *pchrPtrReporte)
{

	SRegistroPro2				<<
	"Cantidad"				<<
	"Importe"				<<
	"Fecha"					<<
	"CveProducto"				<<
	"DscProducto"				<<
	"Reporte";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("Cantidad",pchrPtrCantidad)	<<
	SiscomCampoPro2("Importe",pchrPtrImporte)	<<
	SiscomCampoPro2("Fecha",pchrPtrFecha)		<<
	SiscomCampoPro2("CveProducto",pchrPtrCveProducto)	<<
	SiscomCampoPro2("DscProducto",pchrPtrDscProducto)	<<
	SiscomCampoPro2("Reporte",pchrPtrReporte);
	SRegistrosPro2.SiscomAnexaRegistro();
}

RegistrosRepVenta::RegistrosRepVenta()
{

}

RegistrosRepVenta &RegistrosRepVenta::operator<<(RegistroRepVenta *pRRegVenta)
{
	append(pRRegVenta);
	return *this;
}

ReportesVentasSrv::ReportesVentasSrv(SiscomDatCom *pSisDatCom,
				     const char *pchrPtrIdExpendio):
	SisDatCom(pSisDatCom),
	chrPtrIdExpendio(pchrPtrIdExpendio)
{

}
void ReportesVentasSrv::GeneraReporteVentas(const char *pchrPtrFechaIni,
					  const char *pchrPtrFechaFin,
					  ProductosE &pProductos)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         	<<
		new SiscomParametroConsulta("ReportesVentas")	<<
		new SiscomParametroConsulta(pchrPtrFechaIni)		<<
		new SiscomParametroConsulta(pchrPtrFechaFin)		<<
		new SiscomParametroConsulta(chrPtrIdExpendio);
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaReportesVentas");
		GeneraProductos((const SiscomComunicaSrv *)lSGenOp,pProductos);
}
void ReportesVentasSrv::GeneraReporteVentas(const char *pchrPtrFechaIni,
					  const char *pchrPtrFechaFin,
					  RegistrosRepVenta &pRRepVentaDetalle,
					  RegistrosRepVenta &pRRepOrdenes,
					  RegistrosRepVenta &pRRepImporteDia,
					  RegistrosRepVenta &pRRepOrdenesE,
					  RegistrosRepVenta &pRRepOrdenesTotalesE)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         	<<
		new SiscomParametroConsulta("ReportesVentas")		<<
		new SiscomParametroConsulta(pchrPtrFechaIni)		<<
		new SiscomParametroConsulta(pchrPtrFechaFin)		<<
		new SiscomParametroConsulta(chrPtrIdExpendio);
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaReportesVentas");
		GeneraReportes((const SiscomComunicaSrv *)lSGenOp,
				pRRepVentaDetalle,
				pRRepOrdenes,
				pRRepImporteDia,
				pRRepOrdenesE,
				pRRepOrdenesTotalesE);

}
void ReportesVentasSrv::GeneraReportes(const SiscomComunicaSrv *pSComunicaSrv,
				 	RegistrosRepVenta &pRRepVentaDetalle,
					RegistrosRepVenta &pRRepOrdenes,
					RegistrosRepVenta &pRRepImporteDia,
					RegistrosRepVenta &pRRepOrdenesE,
					RegistrosRepVenta &pRRepOrdenesTotalesE)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
RegistroRepVenta *lRRepVenta;
const char *lchrPtrReporte;
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	{
	    lRRepVenta=new RegistroRepVenta(
	    			lSRegistrosPro2["cantidad"],
				lSRegistrosPro2["importe"],
				lSRegistrosPro2["fecha"],
				lSRegistrosPro2["cveproducto"],
				lSRegistrosPro2["dscproducto"],
				lSRegistrosPro2["reporte"]);
	     lchrPtrReporte=lSRegistrosPro2["reporte"];
	     if(!strcmp(lchrPtrReporte,"DetalleVenta"))
	      pRRepVentaDetalle << lRRepVenta;
	     else
	     if(!strcmp(lchrPtrReporte,"ImportePorDia"))
	     pRRepImporteDia << lRRepVenta;
	     else
	     if(!strcmp(lchrPtrReporte,"OrdenesPorDia"))
	     pRRepOrdenes << lRRepVenta;
	     else
	     if(!strcmp(lchrPtrReporte,"OrdenesPorEscuela"))
	     pRRepOrdenesE << lRRepVenta;
	     else
	     if(!strcmp(lchrPtrReporte,"TotalOrdenesPorEscuela"))
	     pRRepOrdenesTotalesE << lRRepVenta;
	}
delete pSComunicaSrv;
}

void ReportesVentasSrv::GeneraProductos(const SiscomComunicaSrv *pSComunicaSrv,
				     ProductosE &pProductos)
{

SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	  pProductos 	<<
	   new ProductoE(lSRegistrosPro2["cveproducto"],
	   	        lSRegistrosPro2["dscproducto"],
			"",
			"",
			"",
			"",
			lSRegistrosPro2["cantidad"],
			"",
			"",
			"",
			lSRegistrosPro2["importe"],
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"");
delete pSComunicaSrv;
}
