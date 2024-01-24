#ifndef __ZDATOSREENVIOFACTURA_H__
#define __ZDATOSREENVIOFACTURA_H__
#include <zSiscomRegistro.h>
class zSiscomRegistros;
class zDatosReEnvioFactura:public zSiscomRegistro
{
public:
	zDatosReEnvioFactura(zSiscomRegistro *pzSisRegDatReEnvio);
	const char *RFC();
	const char *RazonSocial();
	const char *Correo();
	const char *Correo(int pintNCorreo);
	void Inicia();
private:
	zSiscomRegistros *zSisRegsCorreos;
	zSiscomRegistro *zSisRegCorreo;
private:
	int IniciaReCorridoCorreos();
	int SiguienteCorreo();
};

#endif
