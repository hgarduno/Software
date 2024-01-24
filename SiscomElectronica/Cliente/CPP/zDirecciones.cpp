#include <zDirecciones.h>
#include <zDireccion.h>

zDirecciones::zDirecciones()
{

}
zDirecciones::zDirecciones(zSiscomRegistros *pzSisRegsDirecciones)
{
zSiscomRegistro *lzSisRegDireccion;
zDireccion *lzDireccion;
for(lzSisRegDireccion=pzSisRegsDirecciones->Primer();
    lzSisRegDireccion;
    lzSisRegDireccion=pzSisRegsDirecciones->Siguiente())
{
	lzDireccion=new zDireccion(lzSisRegDireccion);
	lzDireccion->Referencias(lzSisRegDireccion->CampoConstChar("referencias"));
   (*this) << lzDireccion;
}
}
zDireccion *zDirecciones::Direccion(int pintNDireccion)
{
	return (zDireccion *)(*this)[pintNDireccion];
}
