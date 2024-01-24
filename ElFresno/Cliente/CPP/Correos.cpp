#include <Correos.h>

CQ_Correo::CQ_Correo(const char *pchrPtrIdPersona,
		     const char *pchrPtrCorreo):
		chrPtrIdPersona(pchrPtrIdPersona),
		chrPtrCorreo(pchrPtrCorreo),
		chrPtrEdoRegistro("")
{

}

void CQ_Correo::PonIdPersona(const char *pchrPtrIdPersona)
{
	chrPtrIdPersona=pchrPtrIdPersona;
}
void CQ_Correo::PonCorreo(const char *pchrPtrCorreo)
{
	chrPtrCorreo=pchrPtrCorreo;
}
void CQ_Correo::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}

const char *CQ_Correo::ObtenIdPersona()
{
	return chrPtrIdPersona;
}

const char *CQ_Correo::ObtenCorreo()
{
	return chrPtrCorreo;
}
const char *CQ_Correo::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
CQ_Correos::CQ_Correos()
{

}
