#include <zOpsAdministradorPedidos.h>

zOpsAdministradorPedidos::zOpsAdministradorPedidos(zSiscomConexion *pzSisConexion,
				     const char *pchrPtrFuncion,
				     const char *pchrPtrModulo):
       zSiscomOperaciones(pzSisConexion,pchrPtrModulo,pchrPtrFuncion)
{


}
void zOpsAdministradorPedidos::Enviando(zSiscomRegistro *pzSisRegEnvio)
{

  AgregaEnvio(pzSisRegEnvio);
 if((zSisRegsRespuesta=EnviaRecibe()))
 {

 }
 else
 {

 }
 
}
int zOpsAdministradorPedidos::ActualizaEstadoPedido(const char *pchrPtrIdVenta,
						     const char *pchrPtrEstado)
{
Enviando(zSiscomRegistro().Registro("%s [IdVenta] %s[IdEstado] %s[FechaHora]",
	 pchrPtrIdVenta,
	 pchrPtrEstado,
	 ""));
return 0;
}
