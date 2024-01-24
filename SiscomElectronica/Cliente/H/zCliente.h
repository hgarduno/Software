#ifndef __ZCLIENTE_H__
#define __ZCLIENTE_H__
#include <zSiscomRegistro.h>
class zPersona;
class zEmpresa;
class zCorreos;
class zDireccion;
class zTelefonos;
class zCorreo;
class zCliente:public zSiscomRegistro
{
public:
	zCliente();
	zCliente(const char *pchrPtrRFC);
	~zCliente();
	void Persona(zPersona *pzPersona);
	void Empresa(zEmpresa *pzEmpresa);
	void Direccion(zDireccion *pzDireccion);
	void Correos(zCorreos *pzCorreos);
	void Telefonos(zTelefonos  *pzTelefonos);
	void RFC(const char *pchrPtrRFC);
	int EsPersonaFisica();

	void NombreCompleto(char *pchrPtrNombre);
	void Direccion(char *pchrPtrDireccion);

	zEmpresa *Empresa();
	zPersona *Persona();
	zDireccion *Direccion();
	zCorreo *Correo();

	void ReIniciaApuntadorCorreo();
	zCorreo *Correo(int pintNCorreo);
	void CorreoActivo(zCorreo *pzCorreo);
	zCorreo *CorreoActivo();
	void LiberaCorreos();
	const char *RFC();
	int TieneCorreos();
private:
	zCorreo *IniciaRecorridoCorreo();
private:
	zCorreo *zCorreoA;
	zCorreos *zCorreosC;
	
};

#endif
