#include <CQSisPreciosServicios.h>
#include <CQSisObjetos.h>

CQSisPrecioServicio::CQSisPrecioServicio(
			CQSisServicio *pCQSServicio,
			CQSisPrecio *pCQSPrecio,
			const char *pchrPtrPrecio):
			CQSServicio(pCQSServicio),
			CQSPrecio(pCQSPrecio)
{
	SRegistroPro2		<<
	"Precio";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("Precio",pchrPtrPrecio);
	SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisPrecioServicio::CQSisPrecioServicio(
			const char *pchrPtrIdServicio,
			const char *pchrPtrIdPrecio,
			const char *pchrPtrIdMedico,
			const char *pchrPtrPrecio)
{
	SRegistroPro2		<<
	"IdServicio"		<<
	"IdPrecio"		<<
	"IdMedico"		<<
	"Precio";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("IdServicio",pchrPtrIdServicio)	<<
	SiscomCampoPro2("IdPrecio",pchrPtrIdPrecio)	<<
	SiscomCampoPro2("IdMedico",pchrPtrIdMedico)	<<
	SiscomCampoPro2("Precio",pchrPtrPrecio);
	SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisServicio *CQSisPrecioServicio::Servicio()
{
	return CQSServicio;
}
CQSisPrecio *CQSisPrecioServicio::Precio()
{
	return CQSPrecio;
}

CQSisLstPrecioServicio::CQSisLstPrecioServicio()
{

}
CQSisLstPrecioServicio &CQSisLstPrecioServicio::operator<<(
					CQSisPrecioServicio *pCQSPServicio)
{
	append(pCQSPServicio);
	return *this;
}
CQSisOpPrecioServicio::CQSisOpPrecioServicio(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)

{


}

void CQSisOpPrecioServicio::PreciosServicio(const char *pchrPtrServicio,
					    CQSisLstPrecioServicio *pCQSLServicio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "PreciosServicioGeneral",
			 pchrPtrServicio);
Elimina(pCQSLServicio);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::PreciosServicio(lSRegistrosPro2,pCQSLServicio);
}

void CQSisOpPrecioServicio::PreciosServicio(const char *pchrPtrIdMedico,
				        const char *pchrPtrServicio,
					CQSisLstPrecioServicio *pCQSLServicio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s%s",
			 "PreciosServicioMedico",
			 pchrPtrIdMedico,
			 pchrPtrServicio);
Elimina(pCQSLServicio);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::PreciosServicio(lSRegistrosPro2,pCQSLServicio);

}

void CQSisOpPrecioServicio::ActualizaPrecio(CQSisPrecioServicio *pCQSPServicio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisLstPrecioServicio lCQSLPServicio;
	lCQSLPServicio << pCQSPServicio;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPServicio);
SiscomActualiza2SubRegistros("ActualizaPrecioServicioGeneral",
			     &lSRegistrosPro2);
Elimina(&lCQSLPServicio);
}


void CQSisOpPrecioServicio::ActualizaPrecioMedico(CQSisPrecioServicio *pCQSPServicio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisLstPrecioServicio lCQSLPServicio;
	lCQSLPServicio << pCQSPServicio;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPServicio);
SiscomActualiza2SubRegistros("ActualizaPrecioServicioMedico",
			     &lSRegistrosPro2);
Elimina(&lCQSLPServicio);
}
void CQSisOpPrecioServicio::Elimina(CQSisLstPrecioServicio *pCQSLPServicio)
{
pCQSLPServicio->setAutoDelete(true);
pCQSLPServicio->clear();
pCQSLPServicio->setAutoDelete(false);
}
