#ifndef __ZCONCUANTOPAGO_H__
#define __ZCONCUANTOPAGO_H__

#include <zSiscomRegistro.h>

class zConCuantoPago:public zSiscomRegistro
{
public:
	zConCuantoPago(const char *pchrPtrConCuantoPago,const char *pchrPtrImporte);
	void SiAlcanza(const char *);	       
	int SiAlcanzaInt();

};
#endif
