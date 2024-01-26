#include <zTelefonos.h>
#include <zSiscomCampo.h>
#include <zDireccion.h>
#include <zSiscomRegistros.h>

#include <zSiscomDesarrollo4.h>
zTelefonos::zTelefonos(const char *pchrPtrIdPersona)
{
 (*this) 								<<
 new zSiscomCampo("IdPersona",(unsigned char *)pchrPtrIdPersona)	<<
 new zSiscomCampo("Telefonos");
}
zTelefonos::zTelefonos()
{
 (*this) 				<<
 new zSiscomCampo("IdPersona")	<<
 new zSiscomCampo("Telefonos");
}
zTelefonos::zTelefonos(zSiscomRegistros *pzSisRegsTelefonos)
{
   (*this)		<<
   new zSiscomCampo("IdPersona")	<<
   new zSiscomCampo("Telefonos");
   AgregaTelefonos(pzSisRegsTelefonos); 

}
void zTelefonos::AgregaTelefonos(zSiscomRegistros *pzSisRegsTelefonos)
{
zSiscomRegistro *lzSisRegTelefono;
for(lzSisRegTelefono=pzSisRegsTelefonos->Primer();
    lzSisRegTelefono;
    lzSisRegTelefono=pzSisRegsTelefonos->Siguiente())
 AgregaTelefono((const char *)(*lzSisRegTelefono)["idtelefono"],
 		(const char *)(*lzSisRegTelefono)["descripcion"],
 		(const char *)(*lzSisRegTelefono)["telefono"]);
}
void zTelefonos::IdPersona(const char *pchrPtrIdPersona)
{
  ActualizaCampo("IdPersona",(unsigned char *)pchrPtrIdPersona);
}
void zTelefonos::AgregaTelefono(const char *pchrPtrIdTelefono,
				const char *pchrPtrDescripcion,
				const char *pchrPtrTelefono)
{
zSiscomRegistro *lzSisRegistro=new zSiscomRegistro;
(*lzSisRegistro) 							<<
new zSiscomCampo("IdTelefono",(unsigned char *)pchrPtrIdTelefono)	<<
new zSiscomCampo("Descripcion",(unsigned char *)pchrPtrDescripcion)	<<
new zSiscomCampo("Telefono",(unsigned char *)pchrPtrTelefono);
AsociadoAlCampo("Telefonos",lzSisRegistro);
}
void zTelefonos::AgregaTelefono(const char *pchrPtrIdTelefono,
				const char *pchrPtrDescripcion,
				const char *pchrPtrTelefono,
				const char *pchrPtrExtension)
{
zSiscomRegistro *lzSisRegistro=new zSiscomRegistro;
(*lzSisRegistro) 							<<
new zSiscomCampo("IdTelefono",(unsigned char *)pchrPtrIdTelefono)	<<
new zSiscomCampo("Descripcion",(unsigned char *)pchrPtrDescripcion)	<<
new zSiscomCampo("Telefono",(unsigned char *)pchrPtrTelefono)		<<
new zSiscomCampo("Extension",(unsigned char *)pchrPtrExtension);
AsociadoAlCampo("Telefonos",lzSisRegistro);
}
void zTelefonos::AgregaTelefono(zSiscomRegistro *pzSisRegTelefono)
{
zSiscomRegistro *lzSisRegTelefono=new zSiscomRegistro;
(*lzSisRegTelefono)							<<
new zSiscomCampo("IdTelefono",(*pzSisRegTelefono)["idtelefono"])	<<
new zSiscomCampo("Descripcion",(*pzSisRegTelefono)["descripcion"])	<<
new zSiscomCampo("Telefono",(*pzSisRegTelefono)["telefono"])		<<
new zSiscomCampo("Extension",(*pzSisRegTelefono)["extension"]);
AsociadoAlCampo("Telefonos",lzSisRegTelefono);
}

void zTelefonos::AgregaTelefono2(zSiscomRegistro *pzSisRegTelefono)
{
zSiscomRegistro *lzSisRegTelefono=new zSiscomRegistro;
(*lzSisRegTelefono)							<<
new zSiscomCampo("IdTelefono",(*pzSisRegTelefono)["IdTelefono"])	<<
new zSiscomCampo("Descripcion",(*pzSisRegTelefono)["Descripcion"])	<<
new zSiscomCampo("Telefono",(*pzSisRegTelefono)["Telefono"])		<<
new zSiscomCampo("Extension",(*pzSisRegTelefono)["Extension"]);
AsociadoAlCampo("Telefonos",lzSisRegTelefono);
}

zSiscomRegistro *zTelefonos::Telefono(const char *pchrPtrDescripcion)
{
zSiscomRegistros *lzSisRegsTelefonos=AsociadosDelCampo("Telefonos");
zSiscomRegistro *lzSisRegDato;
if(lzSisRegsTelefonos)
{
if((lzSisRegDato=lzSisRegsTelefonos->PorCampoDato("Descripcion",
					(const unsigned char *)pchrPtrDescripcion)))
return lzSisRegDato;
else
return 0;
}
else
return 0;
}

const char *zTelefonos::TelefonoPorDsc(const char *pchrPtrDescripcion)
{
zSiscomRegistros *lzSisRegsTelefonos=AsociadosDelCampo("Telefonos");
zSiscomRegistro *lzSisRegDato;
if(lzSisRegsTelefonos &&
   (lzSisRegDato=lzSisRegsTelefonos->PorCampoDato("Descripcion",
					(const unsigned char *)pchrPtrDescripcion)))
return (const char *)(*lzSisRegDato)["Telefono"];
else
return "";
}
void zTelefonos::ActualizaPorDescripcion(const char *pchrPtrDescripcion,
						 const char *pchrPtrTelefono)
{
zSiscomRegistros *lzSisRegsTelefonos=AsociadosDelCampo("Telefonos");
zSiscomRegistro *lzSisRegDato;
if((lzSisRegDato=lzSisRegsTelefonos->PorCampoDato("Descripcion",
					(const unsigned char *)pchrPtrDescripcion)))
 lzSisRegDato->ActualizaCampo("Telefono",(const unsigned char *)pchrPtrTelefono);


}
/* Tepotzotlan Mexico a 9 de Enero del 2016 
 *
 * Cuando sabemos que la lista tiene un solo telefono 
 */
const char *zTelefonos::Telefono()
{
 zSiscomRegistros *lzSisTelefonos;
 if((lzSisTelefonos=AsociadosDelCampo("Telefonos")))
     return  lzSisTelefonos->CampoRegistro(0,"Telefono");
 else
 return "";
 
}
const char *zTelefonos::Extension()
{
 zSiscomRegistros *lzSisTelefonos;
 if((lzSisTelefonos=AsociadosDelCampo("Telefonos")))
     return  lzSisTelefonos->CampoRegistro(0,"Extension");
 else
 return "";
 
}

zTelefonos *zTelefonos::DesdeDatosEmpleo(zSiscomRegistro *pzSisRegEmpleo)
{
zTelefonos *lzTelefonos=new zTelefonos;
lzTelefonos->AgregaTelefono((const char *)(*pzSisRegEmpleo)["idtelefono"],
			    (const char *)(*pzSisRegEmpleo)["descripcion"],
			    (const char *)(*pzSisRegEmpleo)["telefono"],
			    (const char *)(*pzSisRegEmpleo)["extension"]);
return lzTelefonos;
}
zTelefonos *zTelefonos::DesdePersonaRegistrada(zSiscomRegistro *pzSisRegPersona)
{
zSiscomRegistros *lzSisRegsTelefonos=pzSisRegPersona->AsociadosDelCampo("Telefonos");
zSiscomRegistro *lzSisRegTelefono=0;
zTelefonos *lzTelefono=new zTelefonos;
if(lzSisRegsTelefonos)
{
lzTelefono->IdPersona((const char *)(*pzSisRegPersona)["idpersona"]);
for(lzSisRegTelefono=lzSisRegsTelefonos->Primer();
    lzSisRegTelefono;
    lzSisRegTelefono=lzSisRegsTelefonos->Siguiente())
    lzTelefono->AgregaTelefono(lzSisRegTelefono);
}
return lzTelefono;
}
