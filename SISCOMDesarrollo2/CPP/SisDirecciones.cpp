#include <SisDirecciones.h>
SisDireccion::SisDireccion(const char *pchrPtrCalle,
			   const char *pchrPtrNumero,
			   const char *pchrPtrComoLlegar,
			   const char *pchrPtrIdAsentamiento,
			   const char *pchrPtrAsentamiento,
			   const char *pchrPtrEstado,
			   const char *pchrPtrMunicipio):
			  chrPtrCalle(pchrPtrCalle),
			  chrPtrNumero(pchrPtrNumero),
			  chrPtrComoLlegar(pchrPtrComoLlegar),
			  chrPtrIdAsentamiento(pchrPtrIdAsentamiento),
			  chrPtrAsentamiento(pchrPtrAsentamiento),
			  chrPtrEstado(pchrPtrEstado),
			  chrPtrMunicipio(pchrPtrMunicipio)
{
	SiscomAsignaInformacion();	
}
SisDireccion::SisDireccion(const char *pchrPtrCalle,
			   const char *pchrPtrNumero,
			   const char *pchrPtrComoLlegar,
			   const char *pchrPtrIdAsentamiento):
			  chrPtrCalle(pchrPtrCalle),
			  chrPtrNumero(pchrPtrNumero),
			  chrPtrComoLlegar(pchrPtrComoLlegar),
			  chrPtrIdAsentamiento(pchrPtrIdAsentamiento),
			  chrPtrAsentamiento(""),
			  chrPtrEstado(""),
			  chrPtrMunicipio("")
{
	SiscomAsignaInformacion();	
}
void SisDireccion::SiscomFormaRegistro()
{

	SRegistroPro2 			<<
	"Calle"				<<
	"Numero"			<<
	"ComoLlegar"			<<
	"IdAsentamiento"		<<
	"Asentamiento"			<<
	"Estado"			<<
	"Municipio"			<<
	"IdPersona";
}
void SisDireccion::SiscomAnexaRegistro()
{
	SRegistrosPro2						<<
	SiscomCampoPro2("Calle",chrPtrCalle)			<<
	SiscomCampoPro2("Numero",chrPtrNumero)			<<
	SiscomCampoPro2("ComoLlegar",chrPtrComoLlegar)		<<
	SiscomCampoPro2("IdAsentamiento",chrPtrIdAsentamiento)	<<
	SiscomCampoPro2("Asentamiento",chrPtrAsentamiento)	<<
	SiscomCampoPro2("Estado",chrPtrEstado)			<<
	SiscomCampoPro2("Municipio",chrPtrMunicipio)		<<
	SiscomCampoPro2("IdPersona","");
}
void SisDireccion::IdPersona(const char *pchrPtrIdPersona)
{
	SRegistrosPro2.SiscomActualizaCampo("IdPersona",pchrPtrIdPersona);
}
SisLstDireccion::SisLstDireccion()
{

}
SisLstDireccion &SisLstDireccion::operator<<(SisDireccion *pSDPtrDireccion)
{
	append(pSDPtrDireccion);
	return *this;
}
