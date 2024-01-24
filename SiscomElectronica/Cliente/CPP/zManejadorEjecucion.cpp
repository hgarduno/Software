#include <zManejadorEjecucion.h>
#include <zLineaComandosTiendas.h>
#include <zSiscomConexion.h>
#include <zEjecucionTienda.h>
#include <zSiscomRegistros.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
zManejadorEjecucion::zManejadorEjecucion(zSiscomConexion *pzSiscomConexion):
					zSiscomOperaciones(pzSiscomConexion,"Prueba","Probando")
{

}
zManejadorEjecucion::zManejadorEjecucion(zSiscomConexion *pzSisConexion,int):
					zSiscomOperaciones(pzSisConexion)
{
 zSisRegsRegreso=Respuesta();
 SiscomRegistrosLog(zSisRegsRegreso);
}
void zManejadorEjecucion::Agrega(zLineaComandosTiendas *pzLineaCmdsTiendas)
{

AgregaEnvio(new zEjecucionTienda(pzLineaCmdsTiendas->NombreEjecucion(),Pid()));
Enviando();
}
const char *zManejadorEjecucion::Pid()
{
 char lchrArrPid[16];
 sprintf(lchrArrPid,"%ld",getpid());
 return strdup(lchrArrPid);
}
