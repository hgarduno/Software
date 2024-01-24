#include <zCorreo.h>
#include <zSiscomCampo.h>

zCorreo::zCorreo(const char *pchrPtrIdCorreo,
		 const char *pchrPtrCorreo)
{
(*this)  						<< 
	new zSiscomCampo("IdCorreo",(const unsigned char *)pchrPtrIdCorreo) 	<<
	new zSiscomCampo("Correo",(const unsigned char *)pchrPtrCorreo);
	
}
zCorreo::zCorreo(zSiscomRegistro *pzSisRegRegreso)
{
(*this)  						<< 
	new zSiscomCampo("IdCorreo") 	<<
	new zSiscomCampo("Correo",(*pzSisRegRegreso)["Correo"]);


}
const char *zCorreo::Correo()
{
 	return (const char *)Campo("Correo");
}
