#include <zProveedores.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
zProveedores::zProveedores():
			zSisRegsTelefonos(0),
			zSisRegProveedor(0),
			zSisRegTelefono(0)
{


}


void zProveedores::Inicia()
{
zSisRegsTelefonos=0;
zSisRegProveedor=0;
zSisRegTelefono=0;

}
int zProveedores::SiguienteProveedor()
{
    if(!zSisRegProveedor)
    zSisRegProveedor=Primer();
    else
    zSisRegProveedor=Siguiente();

  return zSisRegProveedor ? 1 : 0;
}

int zProveedores::SiguienteTelefono()
{
    	if(!zSisRegsTelefonos)
    	{
		zSisRegsTelefonos=zSisRegProveedor->AsociadosDelCampo("Telefonos");
		if(zSisRegsTelefonos)
	  	zSisRegTelefono=zSisRegsTelefonos->Primer();
		
    	}
    	else
	    zSisRegTelefono=zSisRegsTelefonos->Siguiente();
  if(zSisRegTelefono)
  return 1;
  else
  {
     zSisRegsTelefonos=0;
     zSisRegTelefono=0;
     return 0;
  }
}
zSiscomRegistro *zProveedores::Proveedor()
{
   return zSisRegProveedor;
}
zSiscomRegistro *zProveedores::Telefono()
{
  return zSisRegTelefono;
}
