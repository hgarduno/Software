#include <zClienteSiscom.h>
#include <zSiscomCampo.h>
#include <zCorreo.h>
#include <zTelefono.h>
#include <zDireccion.h>
#include <zEscuela.h>
#include <zDirecciones.h>
#include <zTelefonos.h>
#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>
#include <zTelefonos.h>
#include <string.h>
zClienteSiscom::zClienteSiscom(const char *pchrPtrIdPersona,
			       const char *pchrPtrNombre,
			       const char *pchrPtrAPaterno,
			       const char *pchrPtrAMaterno):
			     zPersona(pchrPtrIdPersona,
			     	      pchrPtrNombre,
				      pchrPtrAPaterno,
				      pchrPtrAMaterno)
{

 (*this) 								<<
 new zSiscomCampo("TipoCliente",(const unsigned char *)"General")	<<
 new zSiscomCampo("Escuela")						<<
 new zSiscomCampo("Celular")						<<
 new zSiscomCampo("Correo")						<<
 new zSiscomCampo("Direccion")  					<<
 new zSiscomCampo("RFC")						<<
 new zSiscomCampo("Mayoreo",(const unsigned char *)"0");
}
zClienteSiscom::zClienteSiscom(zSiscomRegistro *pzSisRegPersona):
			zPersona(pzSisRegPersona)
{
int lintTelefonos;
 (*this) 								<<
 new zSiscomCampo("TipoCliente",(const unsigned char *)"General")	<<
 new zSiscomCampo("Escuela")						<<
 new zSiscomCampo("Celular")						<<
 new zSiscomCampo("Correo")						<<
 new zSiscomCampo("Direccion")						<<
 new zSiscomCampo("RFC")						<<
 new zSiscomCampo("Mayoreo",(const unsigned char *)"0");
 EscuelaCliente(pzSisRegPersona);
 if((lintTelefonos=TraeTelefonosCliente(pzSisRegPersona))==1)
 Telefonos(pzSisRegPersona->AsociadosDelCampo("telefonos"));
 else
 if(lintTelefonos==2)
 Celular(new zTelefono(pzSisRegPersona));
 ActualizaCampo("RFC",(*pzSisRegPersona)["rfc"]);
}
zClienteSiscom::zClienteSiscom(const char *,
			zSiscomRegistro *pzSisRegPersona):
			zPersona(pzSisRegPersona)
{
zDirecciones *lzDirecciones;
 (*this) 								<<
 new zSiscomCampo("TipoCliente",(const unsigned char *)"General")	<<
 new zSiscomCampo("Escuela")						<<
 new zSiscomCampo("Celular")						<<
 new zSiscomCampo("Correo")						<<
 new zSiscomCampo("Direccion")						<<
 new zSiscomCampo("RFC")						<<
 new zSiscomCampo("Mayoreo",(const unsigned char *)"0");
 EscuelaCliente(pzSisRegPersona);
 if(TraeDireccionesCliente(pzSisRegPersona))
 Direcciones(pzSisRegPersona->AsociadosDelCampo("direcciones"));
 if(TraeTelefonosCliente(pzSisRegPersona))
 Telefonos(pzSisRegPersona->AsociadosDelCampo("telefonos"));
 
}

zClienteSiscom::zClienteSiscom()
{
 (*this) 								<<
 new zSiscomCampo("TipoCliente",(const unsigned char *)"General")	<<
 new zSiscomCampo("Escuela")						<<
 new zSiscomCampo("Celular")						<<
 new zSiscomCampo("Correo")						<<
 new zSiscomCampo("Direccion")						<<
 new zSiscomCampo("RFC")						<<
 new zSiscomCampo("Mayoreo",(const unsigned char *)"0");
}
void zClienteSiscom::Telefonos(zSiscomRegistros *pzSisRegsTelefonos)
{
zTelefonos *lzTelefonos;
lzTelefonos=new zTelefonos(pzSisRegsTelefonos);
AsociadosAlCampo("Celular",lzTelefonos);
}
void zClienteSiscom::Direcciones(zSiscomRegistros *pzSisRegsDirecciones)
{
zDirecciones *lzDirecciones;
lzDirecciones=new zDirecciones(pzSisRegsDirecciones);
AsociadosAlCampo("Direccion",lzDirecciones);
}
int zClienteSiscom::TelefonoValido(zSiscomRegistro *pzSisRegPersona)
{
}
int zClienteSiscom::EscuelaValida(zSiscomRegistro *pzSisRegPersona)
{
if(pzSisRegPersona->EstaElCampoEnElRegistro("escuela") &&
   (const char *)(*pzSisRegPersona)["escuela"])
return 1;
else
return 0;
}
zEscuela *zClienteSiscom::Escuela2(zSiscomRegistro *pzSisRegPersona)
{
zSiscomRegistro *lzSisRegCliente;
if(lzSisRegCliente=pzSisRegPersona->AsociadoDelCampo("Escuela"))
{
    return new zEscuela(lzSisRegCliente->Campo("idescuela"),
    			lzSisRegCliente->Campo("nombre"));
}
else
return 0;
}
void zClienteSiscom::EscuelaCliente(zSiscomRegistro *pzSisRegPersona)
{
zEscuela *lzCliEscuela;
 if(EscuelaValida(pzSisRegPersona))
 {
   lzCliEscuela=new zEscuela(pzSisRegPersona->Campo("idescuela"),
   			     pzSisRegPersona->Campo("escuela")); 
   ActualizaCampo("Escuela",lzCliEscuela);
 }
 else
 {
   /*
   LogSiscom("La escuela es no valida ");
   lzCliEscuela=Escuela2(pzSisRegPersona);
   */
   ActualizaCampo("Escuela",Escuela2(pzSisRegPersona));
 }
}
void zClienteSiscom::Celular(zSiscomRegistro *pzSisRegPersona)
{
zTelefono *lzCliEscuela;
 if(TelefonoValido(pzSisRegPersona)) 
 {
   lzCliEscuela=new zTelefono("",pzSisRegPersona->CampoConstChar("telefonos")); 
   ActualizaCampo("Celular",lzCliEscuela);
 }
}
void zClienteSiscom::Escuela(zSiscomRegistro *pzSisRegEscuela)
{
	ActualizaCampo("Escuela",pzSisRegEscuela);
}
void zClienteSiscom::Celular(zTelefono *pzTelefono)
{
	AsociadoAlCampo("Celular",pzTelefono);
}
void zClienteSiscom::Correo(zCorreo *pzCorreo)
{
	AsociadoAlCampo("Correo",pzCorreo);
}
void zClienteSiscom::Direccion(zDireccion *pzDireccion)
{
	AsociadoAlCampo("Direccion",pzDireccion);
}
void zClienteSiscom::IdPersona(const char *pchrPtrIdPersona)
{
	ActualizaCampo("IdPersona",(const unsigned char *)pchrPtrIdPersona);
}
void zClienteSiscom::TipoCliente(const char *pchrPtrTipoCliente)
{
  ActualizaCampo("TipoCliente",(const unsigned char *)pchrPtrTipoCliente);
}
const char *zClienteSiscom::IdPersona()
{
   return (const char *)(*this)["IdPersona"];
}
const char *zClienteSiscom::Escuela()
{
    return (const char *)CampoAsociado("Escuela","nombre");
}
zTelefono *zClienteSiscom::Celular()
{
  return (zTelefono *)AsociadoDelCampo("Celular");
}
zCorreo *zClienteSiscom::Correo()
{
	return (zCorreo *)AsociadoDelCampo("Correo");
}

zDireccion *zClienteSiscom::Direccion()
{
	return (zDireccion *)AsociadoDelCampo("Direccion");
}
zDirecciones *zClienteSiscom::Direcciones()
{
   return (zDirecciones *)AsociadosDelCampo("Direccion");
}
zSiscomRegistro *zClienteSiscom::EscuelaReg()
{
      return AsociadoDelCampo("Escuela");
}

int zClienteSiscom::EsPublicoEnGeneral()
{
    return !strcmp(RFC(),"GENERAL"); 
}
const char *zClienteSiscom::RFC()
{
   return (const char *)(*this)["RFC"];
}
void zClienteSiscom::RFC(const char *pchrPtrRFC)
{
	ActualizaCampo("RFC",(const unsigned char *)pchrPtrRFC);
}

void zClienteSiscom::Mayoreo(const char *pchrPtrMayoreo)
{
	ActualizaCampo("Mayoreo",(const unsigned char *)pchrPtrMayoreo);
}
const char *zClienteSiscom::Mayoreo()
{
    return (const char *)(*this)["Mayoreo"];
}
int zClienteSiscom::MayoreoInt()
{
   return CampoInt("Mayoreo");
}
int zClienteSiscom::TraeDireccionesCliente(zSiscomRegistro *pzSisRegCliente)
{
  if(pzSisRegCliente->AsociadosDelCampo("direcciones"))
  return 1;
  else
  return 0;

}

int zClienteSiscom::TraeTelefonosCliente(zSiscomRegistro *pzSisRegCliente)
{
  if(pzSisRegCliente->AsociadosDelCampo("telefonos"))
  return 1;
  else
  if(pzSisRegCliente->Campo("telefono"))
    return 2;
  else
  return 0;
}
zTelefonos *zClienteSiscom::Telefonos()
{
    return (zTelefonos *)AsociadosDelCampo("Celular");
}
