#include <CQSisCotizando.h>
#include <CQSisObjetos.h>
CQSisCotizando::CQSisCotizando(const char *pchrPtrIdSerProd,
			       const char *pchrPtrIdMedico,
			       const char *pchrPtrIdPrecio,
			       const char *pchrPtrCantidad)
{

SRegistroPro2			<<
"IdSerProd"			<<
"IdMedico"			<<
"IdPrecio";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2 						<<
SiscomCampoPro2("IdSerProd",pchrPtrIdSerProd)		<<
SiscomCampoPro2("IdMedico",pchrPtrIdMedico)		<<
SiscomCampoPro2("IdPrecio",pchrPtrIdPrecio)		<<
SiscomCampoPro2("Cantidad",pchrPtrCantidad);
SRegistrosPro2.SiscomAnexaRegistro();


}
CQSisCotizando::CQSisCotizando(const char *pchrPtrIdSerProd,
			       const char *pchrPtrClave,
			       const char *pchrPtrDescripcion,
			       const char *pchrPtrIdMedico,
			       const char *pchrPtrIdPrecio,
			       const char *pchrPtrPrecio,
			       const char *pchrPtrImporte,
			       const char *pchrPtrCantidad,
			       const char *pchrPtrSePuedeVender,
			       const char *pchrPtrIdConsulta)
{

SRegistroPro2			<<
"IdSerProd"			<<
"Clave"				<<
"Descripcion"			<<
"IdMedico"			<<
"IdPrecio"			<<
"Precio"			<<
"Importe"			<<
"Cantidad"			<<
"SePuedeVender"			<<
"IdConsulta";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2 						<<
SiscomCampoPro2("IdSerProd",pchrPtrIdSerProd)		<<
SiscomCampoPro2("Clave",pchrPtrClave)			<<
SiscomCampoPro2("Descripcion",pchrPtrDescripcion)	<<
SiscomCampoPro2("IdMedico",pchrPtrIdMedico)		<<
SiscomCampoPro2("IdPrecio",pchrPtrIdPrecio)		<<
SiscomCampoPro2("Precio",pchrPtrPrecio)			<<
SiscomCampoPro2("Importe",pchrPtrImporte)		<<
SiscomCampoPro2("Cantidad",pchrPtrCantidad)		<< 
SiscomCampoPro2("SePuedeVender",pchrPtrSePuedeVender)	<<
SiscomCampoPro2("IdConsulta",pchrPtrIdConsulta);
SRegistrosPro2.SiscomAnexaRegistro();

}
CQSisLstCotizando::CQSisLstCotizando()
{

}
CQSisLstCotizando &CQSisLstCotizando::operator<<(CQSisCotizando *pCQSCotizando)
{
	append(pCQSCotizando);
	return *this;
}
const char *CQSisLstCotizando::ImporteTotal()
{
return chrPtrImporteTotal;
}
void CQSisLstCotizando::ImporteTotal(const char *pchrPtrImporteTotal)
{
	chrPtrImporteTotal=pchrPtrImporteTotal;
}
void CQSisLstCotizando::AsignaIdConsulta(const char *pchrPtrIdConsulta)
{
CQSisCotizando *lCQSCotizando;
for(lCQSCotizando=first();
    lCQSCotizando;
    lCQSCotizando=next())
lCQSCotizando->SiscomActualizaCampo("IdConsulta",pchrPtrIdConsulta);

}
CQSisOpCotizando::CQSisOpCotizando(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{


}
void CQSisOpCotizando::CotizaServicios(CQSisLstCotizando *pCQSLCotizando)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLCotizando);
SiscomActualiza2SubRegistros("CotizaClinica",&lSRegistrosPro2);

}
void CQSisOpCotizando::CotizaPerfilMedico(const char *pchrPtrIdMedico,
					  const char *pchrPtrIdPrecio,
					  CQSisLstCotizando *pCQSLCotizando)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisLstCotizando lCQSLCotizando;
lCQSLCotizando << new CQSisCotizando("",
				     pchrPtrIdMedico,
				     pchrPtrIdPrecio,
				     "");
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLCotizando);
SiscomActualiza2SubRegistros("CotizaPerfilMedico",&lSRegistrosPro2);
CQSisObjetos::Cotizando(lSRegistrosPro2,pCQSLCotizando);
Elimina(&lCQSLCotizando);
}
void CQSisOpCotizando::CotizaConsulta(CQSisLstCotizando *pCQSLCotizando)
{
if(pCQSLCotizando->count())
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLCotizando);
SiscomActualiza2SubRegistros("CotizaConsulta",&lSRegistrosPro2);
Elimina(pCQSLCotizando);
CQSisObjetos::Cotizando(lSRegistrosPro2,pCQSLCotizando);
}
}
void CQSisOpCotizando::CotizaConsulta(const char *pchrPtrIdConsulta,
				      CQSisLstCotizando *pCQSLCotizando)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "DatosParaCobrar",
			 pchrPtrIdConsulta);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
Elimina(pCQSLCotizando);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Cotizando(lSRegistrosPro2,pCQSLCotizando);
}


void CQSisOpCotizando::VentasTotalesMedico(
			const char *pchrPtrFechaIni,
			const char *pchrPtrFechaFin,
			const char *pchrPtrIdMedico,
			CQSisLstCotizando *pCQSLCotizando)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s%s%s",
			 "VentasTotalesMedico",
			 pchrPtrFechaIni,
			 pchrPtrFechaFin,
			 pchrPtrIdMedico);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
Elimina(pCQSLCotizando);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Cotizando(lSRegistrosPro2,pCQSLCotizando);
}
void CQSisOpCotizando::Elimina(CQSisLstCotizando *pCQSLCotizando)
{
pCQSLCotizando->setAutoDelete(true);
pCQSLCotizando->clear();
pCQSLCotizando->setAutoDelete(false);
}
