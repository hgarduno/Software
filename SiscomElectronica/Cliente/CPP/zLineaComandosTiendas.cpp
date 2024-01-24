#include <zLineaComandosTiendas.h>
#include <string.h>
zLineaComandosTiendas::zLineaComandosTiendas(int pintArgc,
					     char **pchrPtrArgv):
			zSiscomLineaComandos(pintArgc,pchrPtrArgv)
{

}

int zLineaComandosTiendas::CorreMaximizada()
{
 return EstaLaOpcion("Maximizada");
}
const char *zLineaComandosTiendas::NombreEjecucion()
{
const char *lchrPtrNombreEjecucion;

if((lchrPtrNombreEjecucion=(const char *)(*this)["NombreEjecucion"]))
  return lchrPtrNombreEjecucion;
else
return 0;
}
int zLineaComandosTiendas::SegundoPlano()
{
return EstaLaOpcion("SegundoPlano");
}
