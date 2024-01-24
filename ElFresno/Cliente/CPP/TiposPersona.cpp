#include <TiposPersona.h>
CQTipoPersona::CQTipoPersona(const char *pchrPtrTipoPersona,
			      const char *pchrPtrNmbTipoPersona,
			      const char *pchrPtrDscTipoPersona):
		chrPtrTipoPersona(pchrPtrTipoPersona),
		chrPtrNmbTipoPersona(pchrPtrNmbTipoPersona),
		chrPtrDscTipoPersona(pchrPtrDscTipoPersona)
{

}

void CQTipoPersona::PonTipoPersona(const char *pchrPtrTipoPersona)
{
	chrPtrTipoPersona=pchrPtrTipoPersona;
}

void CQTipoPersona::PonNmbTipoPersona(const char *pchrPtrNmbTipoPersona)
{
	chrPtrNmbTipoPersona=pchrPtrNmbTipoPersona;
}

void CQTipoPersona::PonDscTipoPersona(const char *pchrPtrDscTipoPersona)
{
	chrPtrDscTipoPersona=pchrPtrDscTipoPersona;
}

const char *CQTipoPersona::ObtenTipoPersona()
{
	return chrPtrTipoPersona;
}
const char *CQTipoPersona::ObtenNmbTipoPersona()
{
	return chrPtrNmbTipoPersona;
}
const char *CQTipoPersona::ObtenDscTipoPersona()
{
	return chrPtrDscTipoPersona;
}

