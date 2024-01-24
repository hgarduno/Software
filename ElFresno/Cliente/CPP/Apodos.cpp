#include <Apodos.h>
CQ_Apodo::CQ_Apodo(const char *pchrPtrIdPersona,
		   const char *pchrPtrApodo):
		chrPtrIdPersona(pchrPtrIdPersona),
		chrPtrApodo(pchrPtrApodo),
		chrPtrEdoRegistro("")
{

}
void CQ_Apodo::PonIdPersona(const char *pchrPtrIdPersona)
{

	chrPtrIdPersona=pchrPtrIdPersona;
}
void CQ_Apodo::PonApodo(const char *pchrPtrApodo)
{

	chrPtrApodo=pchrPtrApodo;
}
void CQ_Apodo::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{

	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
const char *CQ_Apodo::ObtenIdPersona()
{
	return chrPtrIdPersona;
}
const char *CQ_Apodo::ObtenApodo()
{
	return chrPtrApodo;
}
const char *CQ_Apodo::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
CQ_Apodos::CQ_Apodos()
{

}
