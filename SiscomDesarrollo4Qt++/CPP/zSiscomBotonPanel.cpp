#include <zSiscomBotonPanel.h>

#include <zSiscomCampo.h>
zSiscomBotonPanel::zSiscomBotonPanel(const char *pchrPtrNombre,
				     const char *pchrPtrImagen,
				     const char *pchrPtrTexto,
				     const char *pchrPtrWidget):
				chrPtrNombre(pchrPtrNombre),
				chrPtrImagen(pchrPtrImagen),
				chrPtrTexto(pchrPtrTexto),
				chrPtrWidget(pchrPtrWidget)
{
Datos();
}

void zSiscomBotonPanel::Datos()
{
AgregaCampo(new zSiscomCampo("Nombre",(const unsigned char *)chrPtrNombre));
AgregaCampo(new zSiscomCampo("Imagen",(const unsigned char *)chrPtrImagen));
AgregaCampo(new zSiscomCampo("Texto",(const unsigned char *)chrPtrTexto));
AgregaCampo(new zSiscomCampo("Widget",(const unsigned char *)chrPtrWidget));
AgregaCampo(new zSiscomCampo("Propiedades"));
}

void zSiscomBotonPanel::Propiedad(const char *pchrPtrNombre,
				  const char *pchrPtrValor)
{

AsociadoAlCampo("Propiedades",
		Registro("%s[Nombre] %s[Valor]",
		         pchrPtrNombre,
			 pchrPtrValor));
}
