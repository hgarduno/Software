#include <SepomexTAsentamientos.h>
SepomexTAsentamiento::SepomexTAsentamiento( const char *pchrPtrTipo,
				   const char *pchrPtrAsentamiento)
{

	SRegistroPro2 				<<
	"Tipo"				<<
	"Asentamiento";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2 						<<
	SiscomCampoPro2("Tipo",pchrPtrTipo)		<<
	SiscomCampoPro2("Asentamiento",pchrPtrAsentamiento);

	SRegistrosPro2.SiscomAnexaRegistro();


}

SepomexTAsentamientos::SepomexTAsentamientos()
{


}
SepomexTAsentamientos &SepomexTAsentamientos::operator<<(SepomexTAsentamiento *pSepMunicipio)
{
	append(pSepMunicipio);

	return *this;
}

SepomexOpTAsentamientos::SepomexOpTAsentamientos(SiscomDatCom *pSisDatCom,
					 SiscomParametrosConsulta *pSPConsulta):
		SiscomOperaciones(pSisDatCom,
				  (QPtrList<SiscomInformacion> *)pSPConsulta)
{


}

void SepomexOpTAsentamientos::SiscomGeneraRegistros(const SiscomComunicaSrv *pSComunicaSrv,
						QPtrList<SiscomInformacion> *pQPtrSInformacion)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
SepomexTAsentamientos *lSepTAsentamientos=(SepomexTAsentamientos *)pQPtrSInformacion;
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	   (*lSepTAsentamientos) << 
	   		new SepomexTAsentamiento(lSRegistrosPro2["tipo"],
					     lSRegistrosPro2["asentamiento"]);
	   			
}
