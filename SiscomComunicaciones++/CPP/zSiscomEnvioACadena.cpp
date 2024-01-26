#include <zSiscomEnvioACadena.h>
#include <zSiscomConexion.h>
#include <stdio.h>
#include <string.h>
zSiscomEnvioACadena::zSiscomEnvioACadena(zSiscomConexion *pzSisConexion,
					  zSiscomRegistros *pzSisRegsEnvio):
				     zSiscomEnvio(pzSisConexion,pzSisRegsEnvio)
{
Registros();

}
void zSiscomEnvioACadena::Cadena(const char *pchrPtrCadena)
{
 strcat(Conexion()->Cadena(),pchrPtrCadena);
}


