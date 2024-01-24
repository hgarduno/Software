#include <Direcciones.h>

CQ_Direccion::CQ_Direccion(const char *pchrPtrCalle,
			       const char *pchrPtrNumero,
			       const char *pchrPtrColonia,
			       const char *pchrPtrCP,
			       const char *pchrPtrDelegacion,
			       const char *pchrPtrEstado,
			       const char *pchrPtrReferencias):
			chrPtrCalle(pchrPtrCalle),
			chrPtrNumero(pchrPtrNumero),
			chrPtrColonia(pchrPtrColonia),
			chrPtrCP(pchrPtrCP),
			chrPtrDelegacion(pchrPtrDelegacion),
			chrPtrEstado(pchrPtrEstado),
			chrPtrEdoRegistro(""),
			chrPtrReferencias(pchrPtrReferencias)
{

}
const char *CQ_Direccion::ObtenCalle()
{
	return chrPtrCalle;
}

const char *CQ_Direccion::ObtenNumero()
{
	return chrPtrNumero;
}
const char *CQ_Direccion::ObtenColonia()
{
	return chrPtrColonia;
}
const char *CQ_Direccion::ObtenCP()
{
	return chrPtrCP[0] ? chrPtrCP :"0";
}
const char *CQ_Direccion::ObtenDelegacion()
{
	return chrPtrDelegacion;
}
const char *CQ_Direccion::ObtenEstado()
{
	return chrPtrEstado;
}
const char *CQ_Direccion::ObtenReferencias()
{
	return chrPtrReferencias;
}
const char *CQ_Direccion::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}

void CQ_Direccion::PonCalle(const char *pchrPtrCalle)
{
	chrPtrCalle=pchrPtrCalle;
}
void CQ_Direccion::PonNumero(const char *pchrPtrNumero)
{
	chrPtrNumero=pchrPtrNumero;
}
void CQ_Direccion::PonColonia(const char *pchrPtrColonia)
{
	chrPtrColonia=pchrPtrColonia;
}
void CQ_Direccion::PonCP(const char *pchrPtrCP)
{
	chrPtrCP=pchrPtrCP;
}
void CQ_Direccion::PonDelegacion(const char *pchrPtrDelegacion)
{
	chrPtrDelegacion=pchrPtrDelegacion;
}
void CQ_Direccion::PonReferencias(const char *pchrPtrReferencias)
{
	chrPtrReferencias=pchrPtrReferencias;
}
void CQ_Direccion::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}

CQ_Direcciones::CQ_Direcciones()
{

}

