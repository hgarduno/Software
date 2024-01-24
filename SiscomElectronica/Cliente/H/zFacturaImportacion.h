#ifndef __ZFACTURAIMPORTACION_H__
#define __ZFACTURAIMPORTACION_H__

#include <zSiscomRegistro.h>

class zProductosImportados;
class zProductoImportado;
class zFacturaImportacion:public zSiscomRegistro
{
public:
	zFacturaImportacion(const char *,const char *);
	zProductosImportados *Productos();
private:
	FILE *FlePtrArchivo;
	const char *chrPtrArchivo;
	zProductosImportados *zProdsImps;
	const char *chrPtrIdProveedor;
private:
	int AbreArchivo();
	int LeeLinea(zProductoImportado **);
	void ProductosImportados();
	void Inicia();
	virtual void ProductoImportado(const char *,zProductoImportado **);
	virtual void ObtenPrecio(const char *pchrPtrPrecioE,char *pchrPtrPrecio);
};

#endif
