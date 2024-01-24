#include <zCliente.h>
#include <zEmpresa.h>
#include <zPersona.h>
#include <zCorreos.h>
#include <zCorreo.h>
#include <zTelefonos.h>
#include <zTelefono.h>
#include <zDireccion.h>
#include <zTelefonos.h>


#include <zSiscomCampo.h>
#include <stdio.h>
zCliente::zCliente():
	zCorreoA(0)
{
   (*this)							<< 
   new zSiscomCampo("Persona") 					<<
   new zSiscomCampo("Empresa") 					<<
   new zSiscomCampo("Direccion")				<<
   new zSiscomCampo("Correos")					<<
   new zSiscomCampo("Telefonos") 				<<
   new zSiscomCampo("RFC")					<<
   new zSiscomCampo("CorreoActivo");
}
zCliente::~zCliente()
{


}
zCliente::zCliente(const char *pchrPtrRFC)
{
   (*this)							<< 
   new zSiscomCampo("Persona") 					<<
   new zSiscomCampo("Empresa") 					<<
   new zSiscomCampo("Direccion")				<<
   new zSiscomCampo("Correos")					<<
   new zSiscomCampo("Telefonos") 				<<
   new zSiscomCampo("RFC",(const unsigned char *)pchrPtrRFC)	<<
   new zSiscomCampo("CorreoActivo");
}

void zCliente::Persona(zPersona *pzPersona)
{
	AsociadoAlCampo("Persona",pzPersona);
}
void zCliente::Empresa(zEmpresa *pzEmpresa)
{
     AsociadoAlCampo("Empresa",pzEmpresa);

}
void zCliente::RFC(const char *pchrPtrRFC)
{
    ActualizaCampo("RFC",(const unsigned char *)pchrPtrRFC);
}
void zCliente::Correos(zCorreos *pzCorreos)
{
   AsociadosAlCampo("Correos",pzCorreos);
}
void zCliente::Telefonos(zTelefonos *pzTelefonos)
{
	AsociadosAlCampo("Telefonos",pzTelefonos);
}
void zCliente::Direccion(zDireccion *pzDireccion)
{
   AsociadoAlCampo("Direccion",pzDireccion);
}

void zCliente::NombreCompleto(char *pchrPtrNombre)
{
sprintf(pchrPtrNombre,
	"%s %s %s",
	((zPersona *)AsociadoDelCampo("Persona"))->Nombre(),
	((zPersona *)AsociadoDelCampo("Persona"))->APaterno(),
	((zPersona *)AsociadoDelCampo("Persona"))->AMaterno());
}
zPersona *zCliente::Persona()
{
  return ((zPersona *)AsociadoDelCampo("Persona"));
}
void zCliente::Direccion(char *pchrPtrDireccion)
{
sprintf(pchrPtrDireccion,
	"%s %s %s %s %s %s %s",
	((zDireccion *)AsociadoDelCampo("Direccion"))->Calle(),
	((zDireccion *)AsociadoDelCampo("Direccion"))->Numero(),
	((zDireccion *)AsociadoDelCampo("Direccion"))->NumeroInt(),
	((zDireccion *)AsociadoDelCampo("Direccion"))->Delegacion(),
	((zDireccion *)AsociadoDelCampo("Direccion"))->Colonia(),
	((zDireccion *)AsociadoDelCampo("Direccion"))->Estado(),
	((zDireccion *)AsociadoDelCampo("Direccion"))->CP());
}
zDireccion *zCliente::Direccion()
{
   return ((zDireccion *)AsociadoDelCampo("Direccion"));
}
zEmpresa *zCliente::Empresa()
{
   return ((zEmpresa *)AsociadoDelCampo("Empresa"));
}
int zCliente::EsPersonaFisica()
{
   return AsociadoDelCampo("Persona") ? 1  :0 ;
}

zCorreo *zCliente::Correo()
{
     if(!zCorreoA)
     {
      zCorreoA=IniciaRecorridoCorreo();
     return zCorreoA;
     }
     else
     return (zCorreo *)zCorreosC->Siguiente();
}
zCorreo *zCliente::IniciaRecorridoCorreo()
{
     zCorreosC=(zCorreos *)AsociadosDelCampo("Correos");
     return (zCorreo *)zCorreosC->Primer();
}
void zCliente::ReIniciaApuntadorCorreo()
{ 
  zCorreoA=0;
}
zCorreo *zCliente::Correo(int pintNCorreo)
{
   return (zCorreo *)(*(AsociadosDelCampo("Correos")))[pintNCorreo];
}
void zCliente::CorreoActivo(zCorreo *pzCorreo)
{
zSiscomRegistros *lzSisRegsDatos;
   if((lzSisRegsDatos=AsociadosDelCampo("CorreoActivo")))
	lzSisRegsDatos->Libera();
   AsociadoAlCampo("CorreoActivo",(zSiscomRegistro *)pzCorreo);
}
void zCliente::LiberaCorreos()
{
  ActualizaCampo("Correos",(const unsigned char *)0);       
}
zCorreo *zCliente::CorreoActivo()
{
   return (zCorreo *)(AsociadoDelCampo("CorreoActivo"));
}

const char *zCliente::RFC()
{
 	return (const char *)(*this)["RFC"];
}
