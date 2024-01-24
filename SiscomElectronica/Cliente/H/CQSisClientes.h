#ifndef __CQSISCLIENTES_H__
#define __CQSISCLIENTES_H__
#include <SiscomRegistros3.h>


class CQSisCliente:public SiscomRegistro3
{
public:
	CQSisCliente(const char *pchrPtrNombre,
		     const char *pchrPtrAPaterno,
		     const char *pchrPtrAMaterno,
		     const char *pchrPtrRFC,
		     const char *pchrPtrIdPersona,
		     const char *pchrPtrIdExpendio);
	CQSisCliente(const char *pchrPtrRazonSocial,
		     const char *pchrPtrRFC,
		     const char *pchrPtrIdPersona,
		     const char *pchrPtrIdExpendio);

	void Direccion(const char *pchrPtrCalle,
			const char *pchrPtrNumero,
			const char *pchrPtrColonia,
			const char *pchrPtrCP,
			const char *pchrPtrDelMunicipio,
			const char *pchrPtrEstado);
	void Telefono(const char *pchrPtrTelefono);
	void Correo(const char *pchrPtrCorreo);
};



#endif
