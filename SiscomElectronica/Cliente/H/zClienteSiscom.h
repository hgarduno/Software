#ifndef __ZCLIENTESISCOM_H__
#define __ZCLIENTESISCOM_H__

#include <zPersona.h>
class zCorreo;
class zDireccion;
class zTelefono;
class zDirecciones;
class zTelefonos;
class zEscuela;

class zClienteSiscom:public zPersona
{
public:
	zClienteSiscom(const char *pchrPtrIdPersona,
		       const char *pchrPtrNombre,
		       const char *pchrPtrAPaterno,
		       const char *pchrPtrAMaterno);
	zClienteSiscom(zSiscomRegistro *pzSisRegPersona);
	zClienteSiscom(const char *,zSiscomRegistro *);
	zClienteSiscom();
	void TipoCliente(const char *pchrPtrTipoCliente);
	void IdPersona(const char *pchrPtrIdPersona);
	const char *IdPersona();
	const char *RFC();
	void RFC(const char *pchrPtrRFC);

	void Escuela(zSiscomRegistro *pzSisRegEscuela);
	void Celular(zTelefono *pzTelefono);
	void Direccion(zDireccion *pzDireccion);
	void Correo(zCorreo *pzCorreo);
	const char *Escuela();
	

	zTelefonos *Telefonos();

	zTelefono *Celular();
	zCorreo *Correo();
	zDireccion *Direccion();
	zDirecciones *Direcciones();
	zSiscomRegistro *EscuelaReg();
	zEscuela *Escuela2(zSiscomRegistro *);
	int EsPublicoEnGeneral();
	void EscuelaCliente(zSiscomRegistro *);
private:
	int TelefonoValido(zSiscomRegistro *);
	int EscuelaValida(zSiscomRegistro *);
	int TraeDireccionesCliente(zSiscomRegistro *);
	int TraeTelefonosCliente(zSiscomRegistro *);
	void Celular(zSiscomRegistro *);	

	void Direcciones(zSiscomRegistros *);
	void Telefonos(zSiscomRegistros *);

};

#endif
