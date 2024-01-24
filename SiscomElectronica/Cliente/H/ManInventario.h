#ifndef __INVENTARIO_H__
#define __INVENTARIO_H__
#include <ProductosE.h>
class ManInventario
{
public:
	ManInventario(SiscomDatCom *,ProductosE &);
	void Registra();
private:
	SiscomDatCom *SisDatCom;
	ProductosE Productos;
};

#endif
