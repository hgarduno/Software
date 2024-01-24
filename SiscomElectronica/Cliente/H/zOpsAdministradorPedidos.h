#ifndef __ZOPSADMINISTRADORPEDIDOS_H__
#define __ZOPSADMINISTRADORPEDIDOS_H__

#include <zSiscomOperaciones.h>


class zSiscomRegistros;
class zCobertura;
class zOpsAdministradorPedidos:public zSiscomOperaciones
{
public:
	zOpsAdministradorPedidos(zSiscomConexion *,
			const char *pchrPtrFuncion,
			const char *pchrPtrModulo="libSiscomElectronica4.so");

	void Enviando(zSiscomRegistro *);
	int ActualizaEstadoPedido(const char *pchrPtrIdVenta,const char *);

private:
	zSiscomRegistros *zSisRegsRespuesta;
};

#endif
