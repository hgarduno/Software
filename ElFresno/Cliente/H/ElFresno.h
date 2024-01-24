#ifndef __ELFRESNO_H__
#define __ELFRESNO_H__
#include <SISCOMVentanaPrincipal3.h>

class SiscomElFresno:public SISCOMVentanaPrincipal
{
Q_OBJECT

public:
	SiscomElFresno(
			QWidget *pQWParent=0,
			const char *pchrPtrName=0,
			WFlags	pWFlags=0);
			
private:
	const char *chrPtrIdAplicacion;
	const char *chrPtrIdPerfil;
	int intSistemaMultiUsuario;
private:
	void CargaFirmaUsuario();
	void CargaSistemaSeguridad();

};

#endif
