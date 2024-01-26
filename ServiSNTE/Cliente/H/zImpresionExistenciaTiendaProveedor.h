#ifndef __ZIMPRESIONEXISTENCIAPROVEEDOR_H__
#define __ZIMPRESIONEXISTENCIAPROVEEDOR_H__
#include <zImpresion.h>


class zExistenciaTiendaProveedor;

class zImpresionExistenciaTiendaProveedor:public zImpresion
{
public:
	zImpresionExistenciaTiendaProveedor(zExistenciaTiendaProveedor *pzLstPrecios);
	void Encabezado();
	zExistenciaTiendaProveedor *ExistenciaTiendaProveedor();
private:
	zExistenciaTiendaProveedor *zExtTiendaProveedor;	
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
