#include <ProductosProt2.h>
ProductoProt2::ProductoProt2(const char *pchrPtrCve,
			     const char *pchrPtrDescripcion,
			     const char *pchrPtrIdFamilia,
			     const char *pchrPtrUnidad,
			     const char *pchrPtrExistencia)
{

	SRegistroPro2 			<<
	"Clave"				<<
	"Descripcion"			<<
	"IdFamilia"			<<
	"Unidad" 			<<
	"Existencia";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2				<<
	SiscomCampoPro2("Clave",pchrPtrCve)	<<
	SiscomCampoPro2("Descripcion",pchrPtrDescripcion) <<
	SiscomCampoPro2("IdFamilia",pchrPtrIdFamilia)	  <<
	SiscomCampoPro2("Unidad",pchrPtrUnidad)		  <<
	SiscomCampoPro2("Exitencia",pchrPtrExistencia);

	SRegistrosPro2.SiscomAnexaRegistro();
}

ProductosProt2::ProductosProt2()
{

}
ProductosProt2 &ProductosProt2::operator<<(ProductoProt2 *pProductoProt2)
{
	append(pProductoProt2);
	return *this;
}
