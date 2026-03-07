#include <zSiscom.PortaPapeles.h>
#include <zClienteSiscom.h>
#include <zTelefono.h>
#include <zSiscomRegistro.h>

zSiscomPortaPapeles::zSiscomPortaPapeles(zSiscomConexion *pzSisConexion,
					 const char *pchrPtrFuncion,
					 const char *pchrPtrModulo):
					 zSiscomOperaciones(pzSisConexion,
					 		    pchrPtrModulo,
					 		    pchrPtrFuncion)
{


}
zSiscomPortaPapeles::~zSiscomPortaPapeles()
{

}

void zSiscomPortaPapeles::ClienteSiscom(const char *pchrPtrCadena,
					zClienteSiscom *pzCliSiscom)
{
zSiscomRegistros *lzSisRegsRespuesta;
zSiscomRegistro *lzSisRegRespuesta;
AgregaEnvio(zSiscomRegistro().Registro("%s [PortaPapeles]",pchrPtrCadena));
if((lzSisRegsRespuesta=EnviaRecibe()))
{
   lzSisRegRespuesta=(*lzSisRegsRespuesta)[0]; 
   SiscomRegistroLog2(lzSisRegRespuesta);
   pzCliSiscom->Celular(Celular(lzSisRegRespuesta));
}
}
zTelefono *zSiscomPortaPapeles::Celular(zSiscomRegistro *pzSisRegDatos)
{
  return new zTelefono("",(const char *)(*pzSisRegDatos)["Celular"]);
}
