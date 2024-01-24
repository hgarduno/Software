#include <CQSisFormaPago.h>
CQSisFormaPago::CQSisFormaPago(const char *pchrPtrIdFormaPago,
			       const char *pchrPtrNombre,
			       const char *pchrPtrDiasSPago)
{
	SRegistroPro2		<<
	"IdFormaPago"		<<
	"Nombre"		<<
	"DiasSigPago";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2		<<
	SiscomCampoPro2("IdFormaPago",pchrPtrIdFormaPago)	<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)			<<
	SiscomCampoPro2("DiasSigPago",pchrPtrDiasSPago);
	SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisLstFormaPago::CQSisLstFormaPago()
{
	setAutoDelete(true);
}
CQSisLstFormaPago::~CQSisLstFormaPago()
{
	clear();
}
CQSisLstFormaPago &CQSisLstFormaPago::operator<<(CQSisFormaPago *pCQSFPago)
{
	append(pCQSFPago);
	return *this;
}

