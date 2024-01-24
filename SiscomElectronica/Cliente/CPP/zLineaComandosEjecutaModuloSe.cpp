#include <zLineaComandosEjecutaModuloSe.h>
#include <stdlib.h>
zLineaComandosEjecutaModuloSe::zLineaComandosEjecutaModuloSe(int pintArgc,
							    char **pchrPtrArgv):
							  zSiscomLineaComandos(pintArgc,
							  		       pchrPtrArgv)
{


}
int zLineaComandosEjecutaModuloSe::SeCargaModulo()
{
 if(EstaLaOpcion("Biblioteca") && EstaLaOpcion("Modulo"))
   return 1;
 else
 return 0;
}
const char *zLineaComandosEjecutaModuloSe::Biblioteca()
{
   return (*this)["Biblioteca"];
}
const char *zLineaComandosEjecutaModuloSe::Modulo()
{
   return (*this)["Modulo"];
}

int zLineaComandosEjecutaModuloSe::TipoLetra()
{
      return EstaLaOpcion("TipoLetra") ;
}

const char *zLineaComandosEjecutaModuloSe::Letra()
{
     return (*this)["Letra"];
}
int zLineaComandosEjecutaModuloSe::TamanoLetra()
{
    return atoi((*this)["TamanoLetra"]);
}
int zLineaComandosEjecutaModuloSe::SePuedeCambiarLetra()
{
   if(EstaLaOpcion("Letra") && EstaLaOpcion("TamanoLetra"))
   return 1;
   else
   return 0;
}
