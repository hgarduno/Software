#include <zCreditosCliente.h>
#include <zDireccion.h>
#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>
zCreditosCliente::zCreditosCliente(zSiscomRegistros *pzSisRegsCreditosCliente):
				zSisRegsCreditosCliente(pzSisRegsCreditosCliente)
{
zSiscomRegistros *lzSisRegsCreditos;
zSiscomRegistros *lzSisRegsPersonas;
if((lzSisRegsCreditos=(zSisRegsCreditosCliente->Primer()->AsociadosDelCampo("Persona"))))
{
   zSisRegCliente=lzSisRegsCreditos->Primer();   
   zSisRegsCreditos=zSisRegsCreditosCliente->Primer()->AsociadosDelCampo("Creditos");
   zDirCliente=new zDireccion(zSisRegsCreditosCliente->Primer()->AsociadosDelCampo("Direccion")->Primer());
}
}
zSiscomRegistro *zCreditosCliente::Cliente()
{
 return zSisRegCliente;
}
zSiscomRegistros *zCreditosCliente::Creditos()
{
  return zSisRegsCreditos;
}
zDireccion *zCreditosCliente::Direccion()
{
  return zDirCliente;
}
