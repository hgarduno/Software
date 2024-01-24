#include <zTelefonos.h>
#include <zSiscomRegistro.h>
#include <zTelefono.h>
#include <zSiscomRegistro.h>
zTelefonos::zTelefonos()
{

}
zTelefonos::zTelefonos(zSiscomRegistros *pzSisRegsTelefonos)
{
zSiscomRegistro *lzSisRegTelefono;
for(lzSisRegTelefono=pzSisRegsTelefonos->Primer();
    lzSisRegTelefono;
    lzSisRegTelefono=pzSisRegsTelefonos->Siguiente())
    (*this) << new zTelefono(lzSisRegTelefono);
}

