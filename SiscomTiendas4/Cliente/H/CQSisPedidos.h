#ifndef __CQSISPEDIDOS_H__
#define __CQSISPEDIDOS_H__
#include <SISCOMComunicaciones++.h>

class CQSisCliente;
class CQSisLstPedido;

class CQSisPedido:public SiscomInformacion
{
public:
	CQSisPedido(const char *,
		    const char *,
		    const char *,
		    const char *,
		    const char *,
		    const char *);
private:
};

class CQSisLstPedido:public QPtrList<CQSisPedido>
{
public:
	CQSisLstPedido();
	CQSisLstPedido &operator<<(CQSisPedido *);
};

class CQSisOpPedido:public SiscomOperaciones
{
public:
	CQSisOpPedido(SiscomDatCom *);
	void Registra(CQSisPedido *);
	void Pedidos(CQSisCliente *,CQSisLstPedido *);
	void PedidoEntregado(CQSisPedido *);
private:
	SiscomParametrosConsulta SPConsulta;
};
#endif
