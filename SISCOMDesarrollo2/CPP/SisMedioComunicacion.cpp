#include <SisMedioComunicacion.h>

SisMedCom::SisMedCom()
{
	SRegistroPro2		<<
	"IdMedio"		<<
	"Medio"			<<
	"Dato"			<<
	"Descripcion";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2						<<
SiscomCampoPro2("IdMedio","")				<<
SiscomCampoPro2("Medio","")				<<
SiscomCampoPro2("Dato","")				<<
SiscomCampoPro2("Descripcion","");
SRegistrosPro2.SiscomAnexaRegistro();
}
SisMedCom::SisMedCom(const char *pchrPtrIdMedio,
			   const char *pchrPtrMedio,
			   const char *pchrPtrDato,
			   const char *pchrPtrDescripcion)
{
	SRegistroPro2		<<
	"IdMedio"		<<
	"Medio"			<<
	"Dato"			<<
	"Descripcion";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2						<<
SiscomCampoPro2("IdMedio",pchrPtrIdMedio)		<<
SiscomCampoPro2("Medio",pchrPtrMedio)			<<
SiscomCampoPro2("Dato",pchrPtrDato)			<<
SiscomCampoPro2("Descripcion",pchrPtrDescripcion);
SRegistrosPro2.SiscomAnexaRegistro();
}
SisMedCom::SisMedCom(const char *pchrPtrIdMedio,
			   const char *pchrPtrMedio,
			   const char *pchrPtrDato,
			   const char *pchrPtrDescripcion,
			   const char *pchrPtrIdPersona)
{
	SRegistroPro2		<<
	"IdMedio"		<<
	"Medio"			<<
	"Dato"			<<
	"Descripcion"		<<
	"IdPersona";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2						<<
SiscomCampoPro2("IdMedio",pchrPtrIdMedio)		<<
SiscomCampoPro2("Medio",pchrPtrMedio)			<<
SiscomCampoPro2("Dato",pchrPtrDato)			<<
SiscomCampoPro2("Descripcion",pchrPtrDescripcion)	<<
SiscomCampoPro2("IdPersona",pchrPtrIdPersona);
SRegistrosPro2.SiscomAnexaRegistro();
}
SisLstMedCom::SisLstMedCom()
{

}
SisLstMedCom &SisLstMedCom::operator<<(SisMedCom *pSCMCPtrMedio)
{
	append(pSCMCPtrMedio);
	return *this;
}
