#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>

#include <stdio.h>

zSiscomOperaciones::zSiscomOperaciones()
{

}
zSiscomOperaciones::zSiscomOperaciones(zSiscomConexion *pzSisConexion):
					zSiscomRecibe(pzSisConexion)
{

}
zSiscomOperaciones::zSiscomOperaciones(zSiscomConexion *pzSisConexion,
				       const char *pchrPtrModulo,
				       const char *pchrPtrFuncion):
				       zSiscomEnvio(pzSisConexion),
				       zSiscomRecibe(pzSisConexion),
				       chrPtrModulo(pchrPtrModulo),
				       chrPtrFuncion(pchrPtrFuncion)
{
  if(pzSisConexion->SeDebeConectar())
  pzSisConexion->Conectate();
  PreparaEnvio();
}
zSiscomOperaciones::zSiscomOperaciones(zSiscomConexion *pzSisConexion,
				       const char *pchrPtrModulo,
				       const char *pchrPtrFuncion,
				       zSiscomRegistros *pzSisRegsEnvio):
				       zSiscomEnvio(pzSisConexion),
				       zSiscomRecibe(pzSisConexion),
				       chrPtrModulo(pchrPtrModulo),
				       chrPtrFuncion(pchrPtrFuncion)
{
if(pzSisConexion->SeDebeConectar())
pzSisConexion->Conectate();
PreparaEnvio();
AgregaEnvio(pzSisRegsEnvio);
}


zSiscomOperaciones::zSiscomOperaciones(zSiscomConexion *pzSisConexion,
				       const char *pchrPtrModulo,
				       const char *pchrPtrFuncion,
				       zSiscomRegistro *pzSisRegEnvio):
				       zSiscomEnvio(pzSisConexion),
				       zSiscomRecibe(pzSisConexion),
				       chrPtrModulo(pchrPtrModulo),
				       chrPtrFuncion(pchrPtrFuncion)
{
if(pzSisConexion->SeDebeConectar())
pzSisConexion->Conectate();
PreparaEnvio();
AgregaEnvio(pzSisRegEnvio);
}
void zSiscomOperaciones::AgregaEnvio(zSiscomRegistro *pzSisRegEnvio)
{
Primer()->AsociadoAlCampo("Envio",pzSisRegEnvio);
}
void zSiscomOperaciones::AgregaEnvio(zSiscomRegistros *pzSisRegsEnvio)
{
 Primer()->AsociadosAlCampo("Envio",pzSisRegsEnvio);
}
void zSiscomOperaciones::PreparaEnvio()
{
zSiscomRegistros *lzSisRegistros=new zSiscomRegistros;
(*this) << zSiscomRegistro().Registro("%s[ModuloServidor] %s[Configuracion] %s[Envio] ",0,0,0);
(*lzSisRegistros) << zSiscomRegistro().Registro("%s[Modulo] %s[Funcion]",
				             chrPtrModulo,
					     chrPtrFuncion);
Primer()->AsociadosAlCampo("ModuloServidor",lzSisRegistros);
}

void zSiscomOperaciones::Enviando()
{
   EnviaVersionProtocolo();
   zSiscomEnvio::Envio((zSiscomRegistros *)this);
   zSiscomEnvio::Registros();
}
zSiscomRegistros *zSiscomOperaciones::Respuesta()
{
   return zSiscomRecibe::Registros();
}

zSiscomRegistros *zSiscomOperaciones::EnviaRecibe()
{
	Enviando();
	return Respuesta();
}
void zSiscomOperaciones::EnviaVersionProtocolo()
{
char lchrArrVersionProtocolo[16];
sprintf(lchrArrVersionProtocolo,"%05d%05d%05d",4,0,0);
zSiscomEnvio::Cadena(lchrArrVersionProtocolo);
}
