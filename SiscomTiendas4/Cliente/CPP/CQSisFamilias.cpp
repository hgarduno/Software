#include <CQSisFamilias.h>
CQSisFamilia::CQSisFamilia(const char *pchrPtrIdFamilia,
			   const char *pchrPtrFamilia,
			   const char *pchrPtrDsc)
{
	SRegistroPro2		<<
	"IdFamilia"		<<
	"Familia"		<<
	"Dsc";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2				<<
	SiscomCampoPro2("IdFamilia",pchrPtrIdFamilia)	<<
	SiscomCampoPro2("Familia",pchrPtrFamilia)	<<
	SiscomCampoPro2("Dsc",pchrPtrDsc);
	SRegistrosPro2.SiscomAnexaRegistro();

}

CQSisLstFamilia::CQSisLstFamilia()
{

}
CQSisLstFamilia &CQSisLstFamilia::operator<<(CQSisFamilia *pCQSFamilia)
{
	append(pCQSFamilia);
	return *this;
}
