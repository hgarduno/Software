#include <ReporteFechaCorte.h>
#include <ProductosProt2.h>

RegistroRepFechaCorte::RegistroRepFechaCorte(ProductoProt2 *pProducto,
					     const char *pchrPtrCantidadVendida,
					     const char *pchrPtrInventario,
					     const char *pchrPtrCuadra,
					     const char *pchrPtrFechaCorte)
{

	SRegistroPro2					<<
	"CveProducto"					<<
	"Descripcion"					<<
	"IdFamilia"					<<
	"Unidad"					<<
	"Existencia"					<<
	"CantidadVendida"				<<
	"Inventario"					<<
	"Cuadra"					<<
	"FechaCorte";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("CveProducto",pProducto->SRegistrosPro2["CveProducto"]) <<
	SiscomCampoPro2("Descripcion",pProducto->SRegistrosPro2["Descripcion"])<<
	SiscomCampoPro2("IdFamilia",pProducto->SRegistrosPro2["IdFamilia"])<<
	SiscomCampoPro2("Unidad",pProducto->SRegistrosPro2["Unidad"]) <<
	SiscomCampoPro2("Existencia",pProducto->SRegistrosPro2["Existencia"]) <<
	SiscomCampoPro2("CantidadVendida",pchrPtrCantidadVendida) <<
	SiscomCampoPro2("Inventario",pchrPtrInventario)<<
	SiscomCampoPro2("Cuadra",pchrPtrCuadra)        <<
	SiscomCampoPro2("FechaCorte",pchrPtrFechaCorte);

	SRegistrosPro2.SiscomAnexaRegistro();
}
RegistrosRepFechaCorte::RegistrosRepFechaCorte()
{

}
RegistrosRepFechaCorte &RegistrosRepFechaCorte::operator<<(RegistroRepFechaCorte *pRRFechaCorte)
{
	append(pRRFechaCorte);
	return *this;
}
void RegistrosRepFechaCorte::GeneraRegistros(const SiscomComunicaSrv *pSComunicaSrv)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
		append(new RegistroRepFechaCorte(new ProductoProt2(
							lSRegistrosPro2["cveproducto"],
							lSRegistrosPro2["dscproducto"],
							lSRegistrosPro2["unidad"],
							lSRegistrosPro2["idfamilia"],
							lSRegistrosPro2["existencia"]),
							lSRegistrosPro2["cantidadvendida"],
							lSRegistrosPro2["inventario"],
							lSRegistrosPro2["cuadra"],
							lSRegistrosPro2["fechahoracorte"]));

				

}
OpReporteFechaCorte::OpReporteFechaCorte(SiscomDatCom *pSisDatCom):
	SisDatCom(pSisDatCom)
{


}

void OpReporteFechaCorte::ObtenReporteFechaCorte(const char *pchrPtrIdExpendio,
					         const char *pchrPtrFechaCorte,
						 const char *pchrPtrFechaReporte,
						 RegistrosRepFechaCorte &pRRFechaCorte)
{
SiscomParametrosConsulta lSPConsulta;
		lSPConsulta                                             <<
                new SiscomParametroConsulta(pchrPtrIdExpendio)          <<
                new SiscomParametroConsulta(pchrPtrFechaCorte)          <<
		new SiscomParametroConsulta(pchrPtrFechaReporte);
SiscomGeneralOperacionesSrv lSGenOp(
			SisDatCom,
			(QPtrList<SiscomInformacion>*)&lSPConsulta);
	lSGenOp.SiscomEjecutaEnvio("ObtenReporteFechaCorte");
	pRRFechaCorte.GeneraRegistros((const SiscomComunicaSrv *)lSGenOp);

}
void OpReporteFechaCorte::ObtenFechasCorte(const char *pchrPtrIdExpendio,
					  RegistrosRepFechaCorte &pRRFechaCorte)
{
SiscomParametrosConsulta lSPConsulta;
		lSPConsulta                                             <<
                new SiscomParametroConsulta("FechasCorte")          <<
		new SiscomParametroConsulta(pchrPtrIdExpendio);
SiscomGeneralOperacionesSrv lSGenOp(
			SisDatCom,
			(QPtrList<SiscomInformacion>*)&lSPConsulta);
	lSGenOp.SiscomEjecutaEnvio("ConsultaCorteExistencias");
	pRRFechaCorte.GeneraRegistros((const SiscomComunicaSrv *)lSGenOp);
}
