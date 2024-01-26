#include <zVerificaActualizacion.h>

zVerificaActualizacion::zVerificaActualizacion(zSiscomConexion *pzSiscomConexion,
					       const char *pchrPtrFuncion,
					       const char *pchrPtrModulo):
				zSiscomOperaciones(pzSiscomConexion,
						   pchrPtrModulo,
						   pchrPtrFuncion)
{
Verificando();

}
void zVerificaActualizacion::Verificando()
{
 AgregaEnvio(zSiscomRegistro().Registro("%s [Verificando] ","Verifica"));
 EnviaRecibe();
}
