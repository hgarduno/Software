#ifndef __ZSISCOMBOTONPANEL_H__
#define __ZSISCOMBOTONPANEL_H__
#include <zSiscomRegistro.h>

class zSiscomBotonPanel:public zSiscomRegistro
{
public:
	zSiscomBotonPanel(const char *pchrPtrName,
			  const char *pchrPtrImagen,
			  const char *pchrPtrTexto,
			  const char *pchrPtrWidget=0);
	void Datos();
	void Propiedad(const char *pchrPtrNombre,const char *pchrPtrValor);

private:
	const char *chrPtrNombre;
	const char *chrPtrImagen;
	const char *chrPtrTexto;
	const char *chrPtrWidget;
};



#endif
