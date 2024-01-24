#include <DireccionesProt2.h>
DireccionProt2::DireccionProt2(const char *pchrPtrIdPersonaEmpresa,
			       const char *pchrPtrCalle,
			       const char *pchrPtrNum,
			       const char *pchrPtrCP,
			       const char *pchrPtrColonia,
			       const char *pchrPtrMunicipio,
			       const char *pchrPtrEstado)
{

	SRegistroPro2		<<
	"IdPersonaEmpresa"	<<
	"Calle" 		<<
	"Numero"		<<
	"CP"			<<
	"Colonia"		<<
	"Municipio"		<<
	"Estado";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2				<<
	SiscomCampoPro2("IdPersonaEmpresa",pchrPtrIdPersonaEmpresa)	<<
	SiscomCampoPro2("Calle",pchrPtrCalle)	<<
	SiscomCampoPro2("Numero",pchrPtrNum)	<<
	SiscomCampoPro2("CP",pchrPtrCP)		<<
	SiscomCampoPro2("Colonia",pchrPtrColonia)	<<
	SiscomCampoPro2("Municipio",pchrPtrMunicipio)<<
	SiscomCampoPro2("Estado",pchrPtrEstado);
	SRegistrosPro2.SiscomAnexaRegistro();


}
DireccionesProt2::DireccionesProt2()
{

}
DireccionesProt2 &DireccionesProt2::operator<<(DireccionProt2 *pDirProt2)
{
	append(pDirProt2);
	return *this;
}
