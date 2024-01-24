#include <SepomexAsentamientos.h>
SepomexAsentamiento::SepomexAsentamiento(const char *pchrPtrNumEstado,
				   const char *pchrPtrNumMunicipio,
				   const char *pchrPtrTipo,
				   const char *pchrPtrCP,
				   const char *pchrPtrAsentamiento,
				   const char *pchrPtrIdAsentamiento)
{

	SRegistroPro2 				<<
	"NumEstado"				<<
	"NumMunicipio"				<<
	"Tipo"					<<
	"CP"					<<
	"Asentamiento"				<<
	"IdAsentamiento";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2 							<<
	SiscomCampoPro2("NumEstado",pchrPtrNumEstado) 			<<
	SiscomCampoPro2("NumMunicipio",pchrPtrNumMunicipio)		<<
	SiscomCampoPro2("Tipo",pchrPtrTipo)				<<
	SiscomCampoPro2("CP",pchrPtrCP)					<<
	SiscomCampoPro2("Asentamiento",pchrPtrAsentamiento)		<<
	SiscomCampoPro2("IdAsentamiento",pchrPtrIdAsentamiento);
	SRegistrosPro2.SiscomAnexaRegistro();
}

SepomexAsentamientos::SepomexAsentamientos()
{


}
SepomexAsentamientos &SepomexAsentamientos::operator<<(SepomexAsentamiento *pSepAsentamiento)
{
	append(pSepAsentamiento);

	return *this;
}

SepomexOpAsentamientos::SepomexOpAsentamientos(SiscomDatCom *pSisDatCom,
					 SiscomParametrosConsulta *pSPConsulta):
		SiscomOperaciones(pSisDatCom,
				  (QPtrList<SiscomInformacion> *)pSPConsulta)
{


}

void SepomexOpAsentamientos::SiscomGeneraRegistros(const SiscomComunicaSrv *pSComunicaSrv,
						QPtrList<SiscomInformacion> *pQPtrSInformacion)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
SepomexAsentamientos *lSepAsentamientos=(SepomexAsentamientos *)pQPtrSInformacion;
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	   (*lSepAsentamientos) << 
	   		new SepomexAsentamiento(lSRegistrosPro2["numestado"],
					     lSRegistrosPro2["nummunicipio"],
					     lSRegistrosPro2["tipo"],
					     lSRegistrosPro2["cp"],
					     lSRegistrosPro2["asentamiento"],
					     lSRegistrosPro2["idasentamiento"]);
}
