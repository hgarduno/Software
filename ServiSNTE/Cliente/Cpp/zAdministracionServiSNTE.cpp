#include <zAdministracionServiSNTE.h>
zAdministracionServiSNTE::zAdministracionServiSNTE(zSiscomConexion *pzSisConexion,
				       const char *pchrPtrFuncion,
				       const char *pchrPtrModulo):
				zSiscomOperaciones(pzSisConexion,
						   pchrPtrModulo,
						   pchrPtrFuncion)
{

}
void zAdministracionServiSNTE::ActivaServidor(zSiscomRegistro *pzSisRegTienda,
					      const char *pchrPtrActivo)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;

AgregaEnvio(zSiscomRegistro().Registro("%s [IdMaquina] %s [Activo]",
					(*pzSisRegTienda)["idtienda"],
					pchrPtrActivo));
if((lzSisRegsRegreso=EnviaRecibe()))
{
 SiscomRegistrosLog(lzSisRegsRegreso);
}
}

zSiscomRegistros *zAdministracionServiSNTE::EstadoServidores()
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;

AgregaEnvio(zSiscomRegistro().Registro("%s [Maquinas]","Todas"));
if((lzSisRegsRegreso=EnviaRecibe()))
{
 SiscomRegistrosLog(lzSisRegsRegreso);
 return lzSisRegsRegreso;
}
}
