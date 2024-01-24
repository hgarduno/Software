#include <CQSisPrecios.h>
CQSisPrecio::CQSisPrecio(const char *pchrPtrIdPrecio,
			 const char *pchrPtrNombre,
			 const char *pchrPtrDsc)
{
	
	SRegistroPro2			<<
	"IdPrecio"			<<
	"Nombre"			<<
	"Dsc";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2 					<<
	SiscomCampoPro2("IdPrecio",pchrPtrIdPrecio)	<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)		<<
	SiscomCampoPro2("Dsc",pchrPtrDsc);		

	SRegistrosPro2.SiscomAnexaRegistro();

}
CQSisPrecio::CQSisPrecio()
{
	
	SRegistroPro2			<<
	"IdPrecio"			<<
	"Nombre"			<<
	"Dsc";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2 					<<
	SiscomCampoPro2("IdPrecio","")			<<
	SiscomCampoPro2("Nombre","")			<<
	SiscomCampoPro2("Dsc","");		

	SRegistrosPro2.SiscomAnexaRegistro();

}
CQSisLstPrecio::CQSisLstPrecio()
{
//	setAutoDelete(true);
}
CQSisLstPrecio::~CQSisLstPrecio()
{
	clear();
}
CQSisLstPrecio &CQSisLstPrecio::operator<<(CQSisPrecio *pCQSPrecio)
{
	append(pCQSPrecio);
	return *this;
}
