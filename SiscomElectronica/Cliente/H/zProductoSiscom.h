#ifndef __ZPRODUCTOISCOM_H__
#define __ZPRODUCTOISCOM_H__
#include <zProducto.h>
class zSiscomRegistros;
class zProductoSiscom:public zProducto
{
   public:
   	zProductoSiscom(zSiscomRegistro *pzSisRegistro);
	void CantidadAComprar(const char *pchrPtrCantidadAComprar);
	void IdCompra(const char *pchrPtrIdCompra);
	void ActualizaProductos(zSiscomRegistros *pzSisRegsProductos);
	int NoAlcanza();
	void NoAlcanza(int pintNoAlcanza);
	int SiAlcanzaProdDefinicion();
	int PrimerProdDefinicion();
	int SiguienteProdDefinicion();
	const char *NoAlcanzaAComprar();
	const char *NoAlcanzaExistencia();
	const char *ClaveProdDef();
	const char *CantidadProdDef();
	void AgregaOrigenDefinicion();

private:
	int intNoAlcanza;
	zSiscomRegistro *zSisRegProdDefActual;
};


void ProductoSiscom(const char *pchrPtrArchivo,
		    const char *pchrPtrFuncion,
		    int pintNoLinea,
		    zProductoSiscom *);

#define LogProductoSiscom(pzProdSiscom) 			\
	ProductoSiscom(__FILE__,__FUNCTION__,__LINE__,pzProdSiscom);
#endif
