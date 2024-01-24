#include <CQSisClientes.h>
#include <CQSisEmpresas.h>
#include <CQSisContactos.h>
CQSisCliente::CQSisCliente()
{
	SRegistroPro2		<<
	"TipoCliente"		<<
	"Nombre";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2		<<
	SiscomCampoPro2("TipoCliente","Fisica")	<<
	SiscomCampoPro2("Nombre","");
	SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisCliente::CQSisCliente(SisPersona *pSPersona):
			SPersona(pSPersona)
{
char lchrArrNombre[125];
	sprintf(lchrArrNombre,
		"%s %s %s",
		pSPersona->SRegistrosPro2["Nombre"],
		pSPersona->SRegistrosPro2["APaterno"],
		pSPersona->SRegistrosPro2["AMaterno"]);
	SRegistroPro2		<<
	"TipoCliente"		<<
	"Nombre";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2		<<
	SiscomCampoPro2("TipoCliente","Fisica")	<<
	SiscomCampoPro2("Nombre",lchrArrNombre);
	SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisCliente::CQSisCliente(CQSisEmpresa *pCQSECliente,
			   CQSisContacto *pCQSContacto):
		CQSEmpresa(pCQSECliente),
		CQSContacto(pCQSContacto)
{
SRegistroPro2		<<
	"TipoCliente"	<<
	"Nombre";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2							<<
	SiscomCampoPro2("TipoCliente","Moral")				<<
	SiscomCampoPro2("Nombre",pCQSECliente->SRegistrosPro2["RazonSocial"]);
	SRegistrosPro2.SiscomAnexaRegistro();

}
CQSisCliente::CQSisCliente(const char *pchrPtrNombre,
			   const char *pchrPtrAPaterno,
			   const char *pchrPtrAMaterno,
			   const char *pchrPtrRFC,
			   const char *pchrPtrIdPersona)
{
SRegistroPro2		<<
"Nombre"		<<
"APaterno"		<<
"AMaterno"		<<
"RFC"			<<
"IdPersona";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2					<<
SiscomCampoPro2("Nombre",pchrPtrNombre)		<<
SiscomCampoPro2("APaterno",pchrPtrAPaterno)	<<
SiscomCampoPro2("AMaterno",pchrPtrAMaterno)	<<
SiscomCampoPro2("RFC",pchrPtrRFC)		<<
SiscomCampoPro2("IdPersona",pchrPtrIdPersona);
SRegistrosPro2.SiscomAnexaRegistro();
}
SisPersona *CQSisCliente::Persona()
{
	return SPersona;
}
CQSisEmpresa *CQSisCliente::Empresa()
{
	return CQSEmpresa;
}
CQSisContacto *CQSisCliente::Contacto()
{
	if(!strcmp(SRegistrosPro2["TipoCliente"],"Moral"))
	return CQSContacto;
	else
	return 0;
}
CQSisLstCliente::CQSisLstCliente()
{
//	setAutoDelete(true);
}
CQSisLstCliente::~CQSisLstCliente()
{
	clear();
}
CQSisLstCliente &CQSisLstCliente::operator<<(CQSisCliente *pCQSCliente)
{
	append(pCQSCliente);
	return *this;
}
int CQSisLstCliente::operator==(const char *pchrPtrIdCliente)
{

}
CQSisCliente *CQSisLstCliente::operator[](const char *pchrPtrIdCliente)
{
CQSisCliente *lCQSCliente;
SisPersona *lSPersona;
int lintContador;
for(lCQSCliente=first(),
    lintContador=0;
    lCQSCliente;
    lCQSCliente=next(),
    lintContador++)
{
lSPersona=lCQSCliente->Persona();
if(!strcmp(pchrPtrIdCliente,(*lSPersona)["IdPersona"]))
return lCQSCliente;
}
return 0;
}
