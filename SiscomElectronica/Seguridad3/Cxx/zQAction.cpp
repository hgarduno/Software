#include <zQAction.h> 
#include <zSiscomCampo.h>
zQAction::zQAction(const char *pchrPtrNombre,
		   const char *pchrPtrVisible,
		   const char *pchrPtrEnabled)
{

(*this)										<< 
	new zSiscomCampo("Nombre",(const unsigned char *)pchrPtrNombre) 	<<
	new zSiscomCampo("Visible",(const unsigned char *)pchrPtrVisible) 	<<
	new zSiscomCampo("Enabled",(const unsigned char *)pchrPtrEnabled);
}
