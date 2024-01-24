#ifndef __ZCLAVEPROVEEDOR_H__
#define __ZCLAVEPROVEEDOR_H__
#include <zProducto.h>


class zSiscomRegistro;

class zEmpresa;
class zClaveProveedor:public zProducto
{
 public:
 	zClaveProveedor();
	zClaveProveedor(zSiscomRegistro *pzSisRegProducto);
	void ClaveP(const char *pchrPtrCveProveedor);
	void DescripcionP(const char *);
	void Proveedor(zSiscomRegistro *);

	const char *ClaveP();
	const char *DescripcionP();
	zEmpresa *Proveedor();

};


#endif
