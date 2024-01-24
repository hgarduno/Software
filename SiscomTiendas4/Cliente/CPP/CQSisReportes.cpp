#include <CQSisReportes.h>
#include <CQSisObjetosTiendas4.h>
#include <CQSisProdCotiza.h>

CQSisRepVenta::CQSisRepVenta(
		const char *pchrPtrNumOrdenes,
		const char *pchrPtrTotal,
		const char *pchrPtrFecha)
{

SRegistroPro2		<<
"NumOrdenes"		<<
"Total"			<<
"Fecha";

SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2					<<
SiscomCampoPro2("NumOrdenes",pchrPtrNumOrdenes)	<<
SiscomCampoPro2("Total",pchrPtrTotal)		<<
SiscomCampoPro2("Fecha",pchrPtrFecha);

SRegistrosPro2.SiscomAnexaRegistro();

}
CQSisLstRepVenta::CQSisLstRepVenta()
{

}
CQSisLstRepVenta &CQSisLstRepVenta::operator<<(CQSisRepVenta *pCQSRVenta)
{
	append(pCQSRVenta);
	return *this;
}
CQSisOpReportes::CQSisOpReportes(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpReportes::ReporteVentas(
			const char *pchrPtrFechaIni,
			const char *pchrPtrFechaFin,
			CQSisLstRepVenta *pCQSLRVenta)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s%s",
			 "ReporteVentas",
			 pchrPtrFechaIni,
			 pchrPtrFechaFin);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
EliminaReportes(pCQSLRVenta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
FormaReporteVentas(lSRegistrosPro2,pCQSLRVenta);
}
void CQSisOpReportes::FormaReporteVentas(SiscomRegistrosPro2 *pSRegistrosPro2,
					 CQSisLstRepVenta *pCQSLRVenta)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	 (*pCQSLRVenta) << ObjetosTiendas4::ReporteVenta(pSRegistrosPro2);
}

void CQSisOpReportes::DetalleVentas(
			const char *pchrPtrFechaIni,
			const char *pchrPtrFechaFin,
			CQSisLstProdCotiza *pCQSLPCotiza)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s%s",
			 "ReporteDetalleVentas",
			 pchrPtrFechaIni,
			 pchrPtrFechaFin);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
EliminaProductos(pCQSLPCotiza);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
ObjetosTiendas4::ProdsCotiza(lSRegistrosPro2,pCQSLPCotiza);
}
void CQSisOpReportes::EliminaProductos(CQSisLstProdCotiza *pCQSLPCotiza)
{

pCQSLPCotiza->setAutoDelete(true);
pCQSLPCotiza->clear();
pCQSLPCotiza->setAutoDelete(true);

}
void CQSisOpReportes::EliminaReportes(CQSisLstRepVenta *pCQSLRVenta)
{
pCQSLRVenta->setAutoDelete(true);
pCQSLRVenta->clear();
pCQSLRVenta->setAutoDelete(false);
}
