#ifndef __ZSISCAMPOPROTOCOLOLST_H__
#define __ZSISCAMPOPROTOCOLOLST_H__
#include <zSisCampoProtocolo.h>
#include <zSisListas.h>
class zSisCampoProtocoloLst:public zSisLista<zSisCampoProtocolo>
{
public:
	zSisCampoProtocoloLst();
	zSisCampoProtocoloLst &operator<<(zSisCampoProtocolo *);



};

#endif
