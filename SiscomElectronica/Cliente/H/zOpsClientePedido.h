#ifndef __ZOPSCLIENTEPEDIDO_H__
#define __ZOPSCLIENTEPEDIDO_H__

#include <zSiscomOperaciones.h>


class zSiscomRegistros;
class zCobertura;
class zOpsClientePedido:public zSiscomOperaciones
{
public:
	zOpsClientePedido(zSiscomConexion *,
			const char *pchrPtrFuncion,
			const char *pchrPtrModulo="libSiscomElectronica4.so");

	zCobertura *CoberturaJTExpress(const char *);
	void Enviando(zSiscomRegistro *);

private:
	zSiscomRegistros *zSisRegsRespuesta;
};

#endif
