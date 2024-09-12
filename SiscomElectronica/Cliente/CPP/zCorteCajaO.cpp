#include <zCorteCajaO.h>
#include <zCorteCaja.h>

zCorteCajaO::zCorteCajaO(zSiscomConexion *pzSisConexion,
			 const char *pchrPtrFuncion,
			 const char *pchrPtrModulo):
			 zSiscomOperaciones(pzSisConexion,
			 		    pchrPtrModulo,
					    pchrPtrFuncion)
{


}
zCorteCajaO::~zCorteCajaO()
{

}

int zCorteCajaO::RealizaCorte(const char *pchrPtrFechaIni,
			      const char *pchrPtrFechaFin,
			      zCorteCaja *pzCorteC)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [FechaInicio] %s [FechaFin]",
				      pchrPtrFechaIni,
				      pchrPtrFechaFin));
if((lzSisRegsRegreso=EnviaRecibe()))
{
  lzSisRegRegreso=(*lzSisRegsRegreso)[0];
  SiscomRegistroLog2(lzSisRegRegreso);
  pzCorteC->CorteCaja(lzSisRegRegreso);
  return 1;
}
else return 0;


}
