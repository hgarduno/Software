#include <FamiliasProt2.h>

FamiliaProt2::FamiliaProt2(const char *pchrPtrIdFamilia,
			   const char *pchrPtrNmbFamilia,
			   const char *pchrPtrDescripcion)
{
	SRegistroPro2 			<<
	"IdFamilia"			<<
	"NmbFamilia"			<<
	"Descripcion";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 						<<
	SiscomCampoPro2("IdFamilia",pchrPtrIdFamilia) 		<<
	SiscomCampoPro2("NmbFamilia",pchrPtrNmbFamilia)		<<
	SiscomCampoPro2("Descripcion",pchrPtrDescripcion);
	SRegistrosPro2.SiscomAnexaRegistro();
}

FamiliasProt2::FamiliasProt2()
{


}

FamiliasProt2 &FamiliasProt2::operator<<(FamiliaProt2 *pFamilia)
{
	append(pFamilia);
	return *this;
}
