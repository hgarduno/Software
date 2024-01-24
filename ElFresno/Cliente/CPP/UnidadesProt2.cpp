#include <UnidadesProt2.h>
UnidadProt2::UnidadProt2(const char *pchrPtrUnidad,
			 const char *pchrPtrNmbUnidad,
			 const char *pchrPtrAbreviatura)
{

	SRegistroPro2 			<<
	"Unidad"			<<
	"NmbUnidad"			<<
	"Abreviatura";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("Unidad",pchrPtrUnidad)		<<
	SiscomCampoPro2("NmbUnidad",pchrPtrNmbUnidad)   <<
	SiscomCampoPro2("Abreviatura",pchrPtrAbreviatura);
	SRegistrosPro2.SiscomAnexaRegistro();

}

UnidadesProt2::UnidadesProt2()
{

}

UnidadesProt2 &UnidadesProt2::operator<<(UnidadProt2 *pUnidadProt2)
{
	append(pUnidadProt2);
	return *this;
}
			 
