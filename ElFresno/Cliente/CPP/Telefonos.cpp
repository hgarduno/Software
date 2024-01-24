#include <Telefonos.h>
CQ_Telefono::CQ_Telefono(const char *pchrPtrIdPersona,
			 const char *pchrPtrTelefono):
			chrPtrIdPersona(pchrPtrIdPersona),
			chrPtrTelefono(pchrPtrTelefono),
			chrPtrEdoRegistro("")
{

}
void CQ_Telefono::PonIdPersona(const char *pchrPtrIdPersona)
{
	chrPtrIdPersona=pchrPtrIdPersona;
}
void CQ_Telefono::PonTelefono(const char *pchrPtrTelefono)
{
	chrPtrTelefono=pchrPtrTelefono;
}
const char *CQ_Telefono::ObtenIdPersona()
{
	return chrPtrIdPersona;
}

const char *CQ_Telefono::ObtenTelefono()
{
	return chrPtrTelefono;
}
const char *CQ_Telefono::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
CQ_Telefonos::CQ_Telefonos()
{

}

