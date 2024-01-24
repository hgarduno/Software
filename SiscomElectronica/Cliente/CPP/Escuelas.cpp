#include <Escuelas.h>
Escuela::Escuela(const char *pchrPtrIdEscuela,
		 const char *pchrPtrNmbEscuela,
		 const char *pchrPtrEdoRegistro)
{
	SRegistroPro2				<<
	"IdEscuela"				<<
	"Nombre" 				<<
	"EdoRegistro";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("IdEscuela",pchrPtrIdEscuela)	<<
	SiscomCampoPro2("Nombre",pchrPtrNmbEscuela)	<<
	SiscomCampoPro2("EdoRegistro",pchrPtrEdoRegistro);

	SRegistrosPro2.SiscomAnexaRegistro();

}
Escuelas::Escuelas()
{

}

Escuelas &Escuelas::operator<<(Escuela *pEscuela)
{
	append(pEscuela);
	return *this;
}
ConsultaEscuelas::ConsultaEscuelas(SiscomDatCom *pSisDatCom,
				   Escuelas &pEscuelas):
		SisDatCom(pSisDatCom),
		EEscuelas(pEscuelas)
{
SiscomParametrosConsulta lSPConsulta;
	lSPConsulta <<
	new SiscomParametroConsulta("Todo");
SiscomGeneralOperacionesSrv lSGenOp(
				pSisDatCom,
				(QPtrList<SiscomInformacion > *)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaEscuelas");
		GeneraEscuelas((const SiscomComunicaSrv *)lSGenOp,pEscuelas);
}
void ConsultaEscuelas::GeneraEscuelas(const SiscomComunicaSrv *pSComunicaSrv,
				      Escuelas &pEscuelas)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	  pEscuelas <<
	  new Escuela(lSRegistrosPro2["idescuela"],
	  	      lSRegistrosPro2["nombre"]);
delete pSComunicaSrv;
}
void ConsultaEscuelas::RegistraEscuelas()
{
SiscomGeneralOperacionesSrv lSGenOp(SisDatCom,
				(QPtrList<SiscomInformacion > *)&EEscuelas);
		lSGenOp.SiscomEjecutaEnvio("RegistraEscuelas");
}
