#ifndef __ZOPERACIONESSALDOSMOVIMIENTOS_H__
#define __ZOPERACIONESSALDOSMOVIMIENTOS_H__
#include <zSiscomOperaciones.h>

class zSiscomConexion;
class zOperacionesSaldosMovimientos:public zSiscomOperaciones
{
public:
	zOperacionesSaldosMovimientos(zSiscomConexion *pzSisConexion,
				      const char *pchrPtrFuncion,
				      const char *pchrPtrModulo="libSiscomServiSNTE.so");

	zSiscomRegistros *ProveedorProductoMes(zSiscomRegistro *pzSisRegTienda,
						zSiscomRegistro *pzSisRegProveedor,
						zSiscomRegistro *pzSisRegProducto);
	zSiscomRegistros *ConceptosSaldosMovimientos(zSiscomRegistro *pziSisRegTienda,
						     zSiscomRegistro *pzSisRegProducto);
							 
};

#endif
