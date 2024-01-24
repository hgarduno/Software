#include <zOpsPuntosEntrega.h>

#include <zPuntoEntrega.h>
#include <zPuntosEntrega.h>

zOpsPuntosEntrega::zOpsPuntosEntrega(zSiscomConexion *pzSisConexion,
				    zPuntoEntrega *pzPEntrega,
				     const char *pchrPtrFuncion,
				     const char *pchrPtrModulo):
			zSiscomOperaciones(pzSisConexion,pchrPtrModulo,pchrPtrFuncion)
{
   RegistraPuntoEntrega(pzPEntrega);
  //PuntosEntrega(0);
}

/*  CDMX , Domingo 14 Agosto, en el local del Casco de Siscom , esperando 
 *  la instalacion del Internet 
 *
 * La solucion mas chafa, pero mientra encuntro como poder seleccionar 
 * el movimiento desde la clase 
 *
 */
zOpsPuntosEntrega::zOpsPuntosEntrega(const char *pchrPtrConsulta,
				    zSiscomConexion *pzSisConexion,
				    zPuntoEntrega *pzPEntrega,
				     const char *pchrPtrFuncion,
				     const char *pchrPtrModulo):
			zSiscomOperaciones(pzSisConexion,pchrPtrModulo,pchrPtrFuncion)
{
   //RegistraPuntoEntrega(pzPEntrega);
  PuntosEntrega(0);
}



void zOpsPuntosEntrega::Enviando(zSiscomRegistro *pzSisRegEnvio)
{
  AgregaEnvio(pzSisRegEnvio);
  if((zSisRegsRespuesta=EnviaRecibe()))
  {
  }
  else
  {

  }
}
void zOpsPuntosEntrega::RegistraPuntoEntrega(zPuntoEntrega *pzPEntrega)
{
   Enviando(pzPEntrega);
}
void zOpsPuntosEntrega::PuntosEntrega(const char *pchrPtrConsulta)
{
     Enviando((zSiscomRegistro *)0);
     PuntosEntrega();

}
void zOpsPuntosEntrega::PuntosEntrega()
{
 zPsEntrega=zPuntosEntrega::DeConsulta(zSisRegsRespuesta);
}
zPuntosEntrega *zOpsPuntosEntrega::ObtenPuntosEntrega()
{
 return zPsEntrega;
 }
