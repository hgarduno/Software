#ifndef __ZPRODUCTOSIMPORTADOS_H__
#define __ZPRODUCTOSIMPORTAODS_H__

#include <zSiscomRegistros.h>


class zProductoImportado;
class zProductosImportados:public zSiscomRegistros
{
public:
	zProductosImportados();
	zProductosImportados &operator<<(zProductoImportado *);
	void Actualiza(zSiscomRegistros *);
	zProductoImportado *Producto(zProductoImportado *);
	void Partidas(char *pchrPtrPartidas);
	void ProductosFiltrados(const char *,
				const char *,
				const char *,
			        zSiscomRegistros *pzSisRegsProductos);
	void AsignaClave(zSiscomRegistros *);
	void ActualizandoClave(zSiscomRegistro *);

};
#endif
