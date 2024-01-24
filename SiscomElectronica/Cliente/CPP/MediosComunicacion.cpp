#include <MediosComunicacion.h>

MedioComunicacion::MedioComunicacion(const char *pchrPtrIdEmpresa,
				     const char *pchrPtrIdPersona,
				     const char *pchrPtrMedio,
				     const char *pchrPtrNmbMedio,
				     const char *pchrPtrDepartamento)
{

	SRegistroPro2 				<<
	"IdEmpresa"				<<
	"IdPersona"				<<
	"Medio"					<<
	"NmbMedio"				<<
	"Departamento";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2					<<
	SiscomCampoPro2("IdEmpresa",pchrPtrIdEmpresa)	<<
	SiscomCampoPro2("IdPersona",pchrPtrIdPersona)	<<
	SiscomCampoPro2("Medio",pchrPtrMedio)		<<
	SiscomCampoPro2("NmbMedio",pchrPtrNmbMedio)	<<
	SiscomCampoPro2("Departamento",pchrPtrDepartamento);

	SRegistrosPro2.SiscomAnexaRegistro();

}
MediosComunicacion::MediosComunicacion()
{

}

MediosComunicacion &MediosComunicacion::operator<<(MedioComunicacion *pMedioCom)
{
	append(pMedioCom);
	return *this;
}
