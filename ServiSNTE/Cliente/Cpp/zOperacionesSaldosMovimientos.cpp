#include <zOperacionesSaldosMovimientos.h>
#include <zSiscomConexion.h>
zOperacionesSaldosMovimientos::zOperacionesSaldosMovimientos(zSiscomConexion *pzSisConexion,
							    const char *pchrPtrFuncion,
							    const char *pchrPtrModulo):
						zSiscomOperaciones(pzSisConexion,
								   pchrPtrModulo,
								   pchrPtrFuncion)
{


}
zSiscomRegistros *zOperacionesSaldosMovimientos::ProveedorProductoMes(zSiscomRegistro *pzSisRegTienda,
						zSiscomRegistro *pzSisRegProveedor,
						 zSiscomRegistro *pzSisRegProducto)
{
zSiscomRegistros *lzSisRegsRegreso;

AgregaEnvio(zSiscomRegistro().Registro("%s [IdTienda] %s [IdProveedor] %s [IdProducto]",
					(*pzSisRegTienda)["idtienda"],
					(*pzSisRegProveedor)["idempresa"],
					(*pzSisRegProducto)["idproducto"]));

if((lzSisRegsRegreso=EnviaRecibe()))
{
   SiscomRegistrosLog(lzSisRegsRegreso);
   return lzSisRegsRegreso;

}
else
return 0;


}

zSiscomRegistros *zOperacionesSaldosMovimientos::ConceptosSaldosMovimientos(
						zSiscomRegistro *pzSisRegTienda,
						 zSiscomRegistro *pzSisRegProducto)
{
zSiscomRegistros *lzSisRegsRegreso;

AgregaEnvio(zSiscomRegistro().Registro("%s [IdTienda] %s  [IdProducto]",
					(*pzSisRegTienda)["idtienda"],
					(*pzSisRegProducto)["idproducto"]));

if((lzSisRegsRegreso=EnviaRecibe()))
{
   SiscomRegistrosLog(lzSisRegsRegreso);
   return lzSisRegsRegreso;
}
else
return 0;
}
