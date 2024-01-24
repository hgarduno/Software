#include <SepomexMunicipios.h>
SepomexMunicipio::SepomexMunicipio(const char *pchrPtrNumMunicipio,
				   const char *pchrPtrNumEstado,
				   const char *pchrPtrMunicipio)
{

	SRegistroPro2 				<<
	"NumMunicipio"				<<
	"NumEstado"				<<
	"Municipio";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2 						<<
	SiscomCampoPro2("NumMunicipio",pchrPtrNumMunicipio) 	<<
	SiscomCampoPro2("NumEstado",pchrPtrNumEstado)		<<
	SiscomCampoPro2("Municipio",pchrPtrMunicipio);

	SRegistrosPro2.SiscomAnexaRegistro();


}

SepomexMunicipios::SepomexMunicipios()
{


}
SepomexMunicipios &SepomexMunicipios::operator<<(SepomexMunicipio *pSepMunicipio)
{
	append(pSepMunicipio);

	return *this;
}

SepomexOpMunicipios::SepomexOpMunicipios(SiscomDatCom *pSisDatCom,
					 SiscomParametrosConsulta *pSPConsulta):
		SiscomOperaciones(pSisDatCom,
				  (QPtrList<SiscomInformacion> *)pSPConsulta)
{


}

void SepomexOpMunicipios::SiscomGeneraRegistros(const SiscomComunicaSrv *pSComunicaSrv,
						QPtrList<SiscomInformacion> *pQPtrSInformacion)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
SepomexMunicipios *lSepMunicipios=(SepomexMunicipios *)pQPtrSInformacion;
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	   (*lSepMunicipios) << 
	   		new SepomexMunicipio(lSRegistrosPro2["nummunicipio"],
					     lSRegistrosPro2["numestado"],
					     lSRegistrosPro2["municipio"]);
	   			
}
