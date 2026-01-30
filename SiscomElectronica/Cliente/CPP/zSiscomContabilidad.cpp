#include <zSiscomContabilidad.h>
#include <zSiscomRegistros.h>

zSiscomContabilidad::zSiscomContabilidad(zSiscomConexion *pzSisConexion,
					const char *pchrPtrFuncion,
					const char *pchrPtrModulo):
					zSiscomOperaciones(pzSisConexion,
							pchrPtrModulo,
							pchrPtrFuncion)
{


}

zSiscomContabilidad::~zSiscomContabilidad()
{

}


void zSiscomContabilidad::OrdenesTarjetaTransferencia(const char *pchrPtrFechaIni,
					 const char *pchrPtrFechaFin)
{
zSiscomRegistros *lzSisRegsRegreso;

AgregaEnvio(zSiscomRegistro().Registro("%s [FechaInicio] %s [FechaFin]",
				       pchrPtrFechaIni,
				       pchrPtrFechaFin));

lzSisRegsRegreso=EnviaRecibe();

}
