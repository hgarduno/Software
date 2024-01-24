#ifndef __SISCOMCLINICAS3_H__
#define __SISCOMCLINICAS3_H__

#include <SISCOMVentanaPrincipal3.h>

class SiscomClinicas3:public SISCOMVentanaPrincipal
{
Q_OBJECT

public:
	SiscomClinicas3(QWidget *pQWParent=0,
			const char *pchrPtrName=0,
			WFlags pWFlags=0);
private:
	const char *chrPtrIdAplicacion;
	const char *chrPtrIdPerfil;
	int intSistemaMultiUsuario;
private:
	void CargaFirmaUsuario();
	void CargaSistemaSeguridad();
	
};

#endif
