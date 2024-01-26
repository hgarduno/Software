#include <zSisCampoProtocoloLst.h>

zSisCampoProtocoloLst::zSisCampoProtocoloLst()
{

}
zSisCampoProtocoloLst &zSisCampoProtocoloLst::operator<<(zSisCampoProtocolo *pzSisCamProt)
{
	Agrega(pzSisCamProt);
	return *this;
}
