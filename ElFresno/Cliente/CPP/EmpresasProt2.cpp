#include <EmpresasProt2.h>
EmpresaProt2::EmpresaProt2(const char *pchrPtrRazonSocial,
			   const char *pchrPtrRFC,
			   const char *pchrPtrIdEmpresa,
			   const char *pchrPtrEsExpendio)
{

	SRegistroPro2 		<<
	"RazonSocial"           <<
	"RFC"                   <<
	"IdEmpresa"             <<
	"EsExpendio";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 					  <<
	SiscomCampoPro2("RazonSocial",pchrPtrRazonSocial) <<
	SiscomCampoPro2("RFC",pchrPtrRFC)		  <<
	SiscomCampoPro2("IdEmpresa",pchrPtrIdEmpresa)     <<
	SiscomCampoPro2("EsExpendio",pchrPtrEsExpendio);
	SRegistrosPro2.SiscomAnexaRegistro();
}
EmpresasProt2::EmpresasProt2()
{

}
EmpresaProt2 *EmpresasProt2::operator++()
{
	return next();
}
