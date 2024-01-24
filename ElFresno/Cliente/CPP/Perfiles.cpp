#include <Perfiles.h>

CQPerfil::CQPerfil(const char *pchrPtrIdPerfil,
		   const char *pchrPtrNmbPerfil):
		chrPtrIdPerfil(pchrPtrIdPerfil),
		chrPtrNmbPerfil(pchrPtrNmbPerfil),
		chrPtrEdoRegistro("")
{

}
const char CQPerfil::ObtenIdPerfil()
{
	return chrPtrIdPerfil;
}

const char CQPerfil::ObtenNmbPerfil()
{
	return chrPtrNmbPerfil;
}

const char CQPerfil::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
void CQPerfil::PonIdPefil(const char *pchrPtrIdPefil)
{
	chrPtrIdPefil=pchrPtrIdPefil;
}
void CQPerfil::PonNmbPerfil(const char *pchrPtrNmbPerfil)
{
	chrPtrNmbPerfil=pchrPtrNmbPerfil;
}
void CQPerfil::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
CQ_Perfiles::CQ_Perfiles()
{

}
