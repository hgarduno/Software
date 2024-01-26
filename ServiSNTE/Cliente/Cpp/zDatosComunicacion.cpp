#include <zDatosComunicacion.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
#include <zCorreo.h>

zDatosComunicacion::zDatosComunicacion(const char *pchrPtrIdPersona):
			zTelefonos(pchrPtrIdPersona)
{
   (*this)				<<
   new zSiscomCampo("Correo");
}
zDatosComunicacion::zDatosComunicacion(zSiscomRegistros *pzSisRegsDatos):
				zTelefonos(pzSisRegsDatos)
{
   (*this)	<<
   new zSiscomCampo("Correo");

}

void zDatosComunicacion::Correo(zCorreo *pzCorreo)
{
AsociadoAlCampo("Correo",pzCorreo); 
}

void zDatosComunicacion::ActualizaCorreo(const char *pchrPtrCorreo)
{
zSiscomRegistro *lzSisRegCorreo;
if((lzSisRegCorreo=AsociadoDelCampo("Correo")))
lzSisRegCorreo->ActualizaCampo("Correo",(const unsigned char *)pchrPtrCorreo);
}
