#include <zEscuela.h>
#include <zSiscomCampo.h>

zEscuela::zEscuela(zSiscomRegistro *pzSisRegEscuela)
{
  (*this) << new zSiscomCampo("idescuela",(*pzSisRegEscuela)["idescuela"]) 
  	  << new zSiscomCampo("nombre",(*pzSisRegEscuela)["nombre"])
	  << new zSiscomCampo("escuela",(*pzSisRegEscuela)["nombre"]);
}
zEscuela::zEscuela(const unsigned char *pchrPtrIdEscuela,
		   const unsigned char *pchrPtrEscuela)
{
  (*this) << 
  new zSiscomCampo("idescuela",pchrPtrIdEscuela) <<
  new zSiscomCampo("nombre",pchrPtrEscuela);
         

}
void zEscuela::Escuela(const char *pchrPtrEscuela)
{
	ActualizaCampo("nombre",(const unsigned char *)pchrPtrEscuela);
}

const char *zEscuela::Nombre()
{
    return (const char *)Campo("nombre");
}

