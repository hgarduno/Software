#ifndef __ZIMPRESIONPROVEEDORES_H__
#define __ZIMPRESIONPROVEEDORES_H__
#include <zImpresion.h>


class zProveedores;

class zImpresionProveedores:public zImpresion
{
public:
	zImpresionProveedores(zProveedores *pzLstPrecios);
	void Encabezado();
	zProveedores *Proveedores();
private:
	zProveedores *zProvDatos;	
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);

};

#endif
