#include <zOpsClientePedido.h>
#include <zCobertura.h>

zOpsClientePedido::zOpsClientePedido(zSiscomConexion *pzSisConexion,
				     const char *pchrPtrFuncion,
				     const char *pchrPtrModulo):
       zSiscomOperaciones(pzSisConexion,pchrPtrModulo,pchrPtrFuncion)
{


}
zCobertura *zOpsClientePedido::CoberturaJTExpress(const char *pchrPtrCP)
{
Enviando(zSiscomRegistro().Registro("%s [CP]",pchrPtrCP));
return new zCobertura((*zSisRegsRespuesta)[0]->AsociadoDelCampo("Cobertura"));
}

void zOpsClientePedido::Enviando(zSiscomRegistro *pzSisRegEnvio)
{

  AgregaEnvio(pzSisRegEnvio);
 if((zSisRegsRespuesta=EnviaRecibe()))
 {

 }
 else
 {

 }
 
}
