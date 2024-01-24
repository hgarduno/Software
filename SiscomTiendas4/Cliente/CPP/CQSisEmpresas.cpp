#include <CQSisEmpresas.h>
CQSisEmpresa::CQSisEmpresa()
{

	SRegistroPro2		<<
	"IdEmpresa"		<<
	"RazonSocial";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2					<<
	SiscomCampoPro2("IdEmpresa","")	<<
	SiscomCampoPro2("RazonSocial","");

	SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisEmpresa::CQSisEmpresa(const char *pchrPtrIdEmpresa,
			   const char *pchrPtrRSocial)
{

	SRegistroPro2		<<
	"IdEmpresa"		<<
	"RazonSocial";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2					<<
	SiscomCampoPro2("IdEmpresa",pchrPtrIdEmpresa)	<<
	SiscomCampoPro2("RazonSocial",pchrPtrRSocial);

	SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisEmpresa::CQSisEmpresa(const char *pchrPtrIdEmpresa,
			   const char *pchrPtrRSocial,
			   const char *pchrPtrCalle,
			   const char *pchrPtrNumero,
			   const char *pchrPtrIdAsentamiento,
			   const char *pchrPtrNombre,
			   const char *pchrPtrAPaterno,
			   const char *pchrPtrAMaterno,
			   const char *pchrPtrDscContacto,
			   const char *pchrPtrIdMedio,
			   const char *pchrPtrMedio,
			   const char *pchrPtrDscMedio,
			   const char *pchrPtrTipoEmpresa)
{

	SRegistroPro2		<<
	"IdEmpresa"		<<
	"RazonSocial"		<<
	"Calle"			<<
	"Numero"		<<
	"IdAsentamiento"	<<
	"IdContacto"		<<
	"Nombre"		<<
	"APaterno"		<<
	"AMaterno"		<<
	"DscContacto"		<<
	"IdMedio"		<<
	"Medio"			<<
	"DscMedio"		<<
	"TipoEmpresa";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2							<<
	SiscomCampoPro2("IdEmpresa",pchrPtrIdEmpresa)			<<
	SiscomCampoPro2("RazonSocial",pchrPtrRSocial)			<<
	SiscomCampoPro2("Calle",pchrPtrCalle)				<<
	SiscomCampoPro2("Numero",pchrPtrNumero)				<<
	SiscomCampoPro2("IdAsentamiento",pchrPtrIdAsentamiento)		<<
	SiscomCampoPro2("IdContacto","")				<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)				<<
	SiscomCampoPro2("APaterno",pchrPtrAPaterno)			<<
	SiscomCampoPro2("AMaterno",pchrPtrAMaterno)			<<
	SiscomCampoPro2("DscContacto",pchrPtrDscContacto)		<<
	SiscomCampoPro2("IdMedio",pchrPtrIdMedio)			<<
	SiscomCampoPro2("Medio",pchrPtrMedio)				<<
	SiscomCampoPro2("DscMedio",pchrPtrDscMedio)			<<
	SiscomCampoPro2("TipoEmpresa",pchrPtrTipoEmpresa);
	SRegistrosPro2.SiscomAnexaRegistro();
}
void CQSisEmpresa::AnexaDireccion(SisDireccion *pSDireccion)
{
	SLDireccion << pSDireccion;
}
void CQSisEmpresa::AnexaContacto(SisPersona *pSPersona)
{
	SLContactos << pSPersona;
}
void CQSisEmpresa::AnexaMedioComunicacion(SisMedCom *pSMComunica)
{
	SLMCComunicacion << pSMComunica;
}

const SisLstDireccion &CQSisEmpresa::Direcciones()
{
	return SLDireccion;
}
const SisLstPersona &CQSisEmpresa::Contactos()
{
	return SLContactos;
}
const SisLstMedCom &CQSisEmpresa::Comunicacion()
{
	return SLMCComunicacion;
}
CQSisLstEmpresa::CQSisLstEmpresa()
{
	setAutoDelete(true);
}
CQSisLstEmpresa::~CQSisLstEmpresa()
{
	clear();
}
CQSisLstEmpresa &CQSisLstEmpresa::operator<<(CQSisEmpresa *pCQSEmpresa)
{
	append(pCQSEmpresa);
	return *this;
}



CQSisEmpresa3Qt::CQSisEmpresa3Qt(const char *pchrPtrIdEmpresa,
				 const char *pchrPtrRazonSocial)
{
  (*this)						<<
  new SiscomCampo3("IdEmpresa",pchrPtrIdEmpresa)	<<
  new SiscomCampo3("RazonSocial",pchrPtrRazonSocial);
}
