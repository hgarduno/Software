#ifndef __CQSISOPESALIDAPRODUCTOS_H__
#define __CQSISOPESALIDAPRODUCTOS_H__
#include <SiscomOperaciones3.h>
#include <SiscomRegistros.h>
class CQSisProducto4;
class CQSisOpeSalidaProductos:public SiscomOperaciones3
{
public:
	CQSisOpeSalidaProductos(SiscomDatCom *);
	void RegistraSalidaProductos(CQSisProducto4 *);
private:
	SiscomRegistro4 SisReg4EdoConexion;
};
#endif
