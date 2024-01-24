#ifndef __COTIZADISPOSITIVOS_H__
#define __COTIZADISPOSITIVOS_H__
#include <SISCOMComunicaciones++.h>
#include <ProductosE.h>
class CotizaDispositivosE
{
public:
	CotizaDispositivosE(SiscomDatCom *,
			   ProductosE &);
	/* Tepotzotlan Mexico a 23 de Octubre del 2015
	 * Cuando un producto se eliminino de la base 
	 * de datos, o se cambio la clave, el sistema 
	 * truena, cerrandose con los problemas que 
	 * ello conlleva, por lo que se agrego la 
	 * validacion para que el sistema informe al 
	 * usuario que el producto no existe en la
	 * base de datos, o mejor dicho no tiene
	 * toda la informacion para poder cotizarse
	 */

	int EstadoCotizacion();
private:
	void GeneraDispositivosCotizados(const SiscomComunicaSrv *,ProductosE &);
private:
	int intEstadoCotizacion;
};
#endif
