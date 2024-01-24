#include <Direcciones.h>
Direccion::Direccion()
{
	SRegistroPro2 				<<
	"IdEmpresa"				<<
	"IdPersona"				<<
	"Calle"					<<
	"Numero"				<<
	"Colonia"				<<
	"CP"					<<
	"Municipio"				<<
	"Estado"				<<
	"Referencia";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("IdEmpresa","")			<<
	SiscomCampoPro2("IdPersona","")			<<
	SiscomCampoPro2("Calle","")			<<
	SiscomCampoPro2("Numero","")			<<
	SiscomCampoPro2("Colonia","")			<<
	SiscomCampoPro2("CP","")			<<
	SiscomCampoPro2("Municipio","")			<<
	SiscomCampoPro2("Estado","")			<<
	SiscomCampoPro2("Referencia","");

	SRegistrosPro2.SiscomAnexaRegistro();


}
Direccion::Direccion(const char *pchrPtrIdEmpresa,
		     const char *pchrPtrIdPersona,
		     const char *pchrPtrCalle,
		     const char *pchrPtrNumero,
		     const char *pchrPtrColonia,
		     const char *pchrPtrCP,
		     const char *pchrPtrMunicipio,
		     const char *pchrPtrEstado,
		     const char *pchrPtrReferencias)
{

	SRegistroPro2 				<<
	"IdEmpresa"				<<
	"IdPersona"				<<
	"Calle"					<<
	"Numero"				<<
	"Colonia"				<<
	"CP"					<<
	"Municipio"				<<
	"Estado"				<<
	"Referencia";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("IdEmpresa",pchrPtrIdEmpresa)	<<
	SiscomCampoPro2("IdPersona",pchrPtrIdPersona)	<<
	SiscomCampoPro2("Calle",pchrPtrCalle)		<<
	SiscomCampoPro2("Numero",pchrPtrNumero)		<<
	SiscomCampoPro2("Colonia",pchrPtrColonia)	<<
	SiscomCampoPro2("CP",pchrPtrCP)			<<
	SiscomCampoPro2("Municipio",pchrPtrMunicipio)	<<
	SiscomCampoPro2("Estado",pchrPtrEstado)		<<
	SiscomCampoPro2("Referencia",pchrPtrReferencias);

	SRegistrosPro2.SiscomAnexaRegistro();

	

}
Direcciones::Direcciones()
{

}

Direcciones &Direcciones::operator<<(Direccion *pDireccion)
{
	append(pDireccion);
	return  *this;
}
