#ifndef __CQSISORVENDIDAS_H__
#define __CQSISORVENDIDAS_H__
#include <SISCOMComunicaciones++.h>
class CQSisLstProdCotiza;
class CQSisEmpresa;
class CQSisFormaPago;
class CQSisCliente;
class CQSisEmpleado;

class CQSisOpOrdenes:public SiscomOperaciones
{
public:
	CQSisOpOrdenes(SiscomDatCom *);
/*
 * En esta funcion se considera que la orden se ha seleccionado
 * de forma previa, en donde ya se cuenta con la forma de pago
 * y los datos generales de la orden, esta funcion 
 * lo que hace es copiar esta informacion y preparar los
 * datos para poder manipularlos, principalmente en la interfaz
 * de ventas o orden para la caja
 *
 */
	void Orden(const char *,
		   CQSisEmpresa *,
		   CQSisFormaPago *,
		   CQSisCliente *,
		   CQSisEmpleado *,
		   CQSisLstProdCotiza *);
/*
 *
 * Para devoluciones 
 *
 */
	void Orden(const char *,
		   CQSisEmpresa *,
		   CQSisLstProdCotiza *);


private:
	SiscomParametrosConsulta SPConsulta;	
private:
	void FormaProductoCotiza(SiscomRegistrosPro2 *,
				 CQSisFormaPago *,
				 CQSisCliente *,
				 CQSisEmpleado *,
				 CQSisLstProdCotiza *);
	void FormaProductoCotiza(SiscomRegistrosPro2 *,
				 CQSisLstProdCotiza *);

};
#endif
