#include <CQSisContactos.h>
CQSisContacto::CQSisContacto(SisPersona *pSPersona):
		SPersona(pSPersona)
{

}

CQSisContacto::CQSisContacto(SisPersona *pSPersona,
			     CQSisEmpresa *pCQSEmpresa):
			   SPersona(pSPersona),
			   CQSEmpresa(pCQSEmpresa)
{


}

SisPersona *CQSisContacto::ObtenPersona()
{
	return SPersona;
}
CQSisEmpresa *CQSisContacto::ObtenEmpresa()
{
	return CQSEmpresa;
}

CQSisLstContacto::CQSisLstContacto()
{
//	setAutoDelete(true);
}
CQSisLstContacto::~CQSisLstContacto()
{
	clear();
}
CQSisLstContacto &CQSisLstContacto::operator<<(CQSisContacto *pCQSContacto)
{
	append(pCQSContacto);
	return *this;
}
