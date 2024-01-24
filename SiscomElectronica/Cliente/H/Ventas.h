#ifndef __VENTAS_H__
#define __VENTAS_H__
#include <SISCOMComunicaciones++.h>
#include <ProductosE.h>
class VentasE
{
public:
	VentasE(SiscomDatCom *,
		const char *,
		ProductosE &);
private:
	void GeneraDispositivosCotizados(const SiscomComunicaSrv *,ProductosE &);
private :
};
#endif
