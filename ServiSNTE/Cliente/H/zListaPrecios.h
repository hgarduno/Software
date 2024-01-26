#ifndef __ZLISTAPRECIOS_H__
#define __ZLISTAPRECIOS_H__
#include <zSiscomRegistros.h>
/* 
 *  Lista de precios por proveedor
 */
class zListaPrecios:public zSiscomRegistros
{
public:
	zListaPrecios();
	int SiguienteProveedor();
	int PrimerProveedor();
	const char *NumeroProveedor();
	const char *RazonSocial();

	const char *Numero();
	const char *Nombre();
	const char *Modelo();
	const char *PrecioGeneral();
	const char *Stock();

	const char *IdDepartamento();
	const char *NombreDepartamento();

	zSiscomRegistros *Productos();
	zSiscomRegistro *Proveedor();
	zSiscomRegistro *Producto();
	zSiscomRegistro *Departamento();
	int SiguienteProducto();
	int PrimerProducto();
	
	int SiguienteDepartamento();
	int PrimerDepartamento();

private:
	zSiscomRegistro *zSisRegProveedor;	
	zSiscomRegistro *zSisRegProducto;
	zSiscomRegistro *zSisRegDepartamento;
};

#endif
