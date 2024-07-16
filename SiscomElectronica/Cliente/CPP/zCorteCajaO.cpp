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

int zCorteCajaO::RealizaCorte(const char *pchrPtrFecha,
			      zCorteCaja *pzCorteC)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Fecha]",pchrPtrFecha));
if((lzSisRegsRegreso=EnviaRecibe()))
{
  lzSisRegRegreso=(*lzSisRegsRegreso)[0];
  pzCorteC->CorteCaja(lzSisRegRegreso);
  return 1;
}
else return 0;


}
