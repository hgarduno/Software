#include <CQSisAparato.h>
CQSisAparato::CQSisAparato(const char *pchrPtrIdAparato,
			   const char *pchrPtrAparato,
			   const char *pchrPtrDescripcion)
{

	SRegistroPro2				<<
	"IdAparato"				<<
	"Aparato"				<<
	"Descripcion";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2						<<
	SiscomCampoPro2("IdAparato",pchrPtrIdAparato)		<<
	SiscomCampoPro2("Aparato",pchrPtrAparato)		<<
	SiscomCampoPro2("Descripcion",pchrPtrDescripcion);

	SRegistrosPro2.SiscomAnexaRegistro();
}
int CQSisAparato::operator==(CQSisAparato *pCQSAparato)
{
return !strcmp((*this)["Aparato"],
	       (*pCQSAparato)["Aparato"]);
}
CQSisLstAparato::CQSisLstAparato()
{

}

CQSisLstAparato &CQSisLstAparato::operator<<(CQSisAparato *pCQSAparato)
{
	append(pCQSAparato);
	return *this;
}

