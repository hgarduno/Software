#include <MediosComunicacion.h>

MedioComunicacion::MedioComunicacion(const char *pchrPtrIdEmpresaPersona,
				     const char *pchrPtrDescripcion,
				     const char *pchrPtrNombreMedio,
				     const char *pchrPtrMedio)
{

	SRegistroPro2			<<
	"IdEmpresaPersona"		<<
	"Descripcion"			<<
	"NombreMedio"			<<
	"Medio";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2							<<
	SiscomCampoPro2("IdEmpresaPersona",pchrPtrIdEmpresaPersona) 	<<
	SiscomCampoPro2("Descripcion",pchrPtrDescripcion)		<<
	SiscomCampoPro2("NombreMedio",pchrPtrNombreMedio)		<<
	SiscomCampoPro2("Medio",pchrPtrMedio);

	SRegistrosPro2.SiscomAnexaRegistro();


}

