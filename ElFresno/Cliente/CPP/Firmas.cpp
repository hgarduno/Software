#include <Firmas.h>

CQ_Firma::CQ_Firma(const char *pchrPtrFirma,
		   const char *pchrPtrIdPersona):
		chrPtrFirma(pchrPtrFirma),
		chrPtrIdPersona(pchrPtrIdPersona),
		chrPtrEdoRegistro("")
{

}
void CQ_Firma::PonFirma(const char *pchrPtrFirma)
{
	chrPtrFirma=pchrPtrFirma;
}

void CQ_Firma::PonIdPersona(const char *pchrPtrIdPersona)
{
	chrPtrIdPersona=pchrPtrIdPersona;
}



void CQ_Firma::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}

const char *CQ_Firma::ObtenFirma()
{
	return chrPtrFirma;
}

const char *CQ_Firma::ObtenIdPersona()
{
	return chrPtrIdPersona;
}


const char *CQ_Firma::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}







