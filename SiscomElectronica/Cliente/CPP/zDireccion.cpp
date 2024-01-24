#include <zDireccion.h>
#include <zSiscomCampo.h>
/* CDMX Siscom Electronica Zacatenco 
 *
 * Agosto 2022 
 * En la tabla direcciones, se tiene considerado el IdPersona, IdEmpresa , 
 * pero no cuenta con un identificador unico para la direccion, cuando 
 * en el sistema de pedidos a los clientes se les agregaron varias direcciones
 * fue el problema, porque no se tuvo forma de identificar una de las 4 o 5 
 * direcciones de envio, por tal motivo se agrego a la tabla de direcciones 
 * el campo IdDireccion , las clases que usamos aqui le agregamos 
 * el campo IdDireccion0 , para almacenar esta informacion
 */
zDireccion::zDireccion(const char *pchrPtrIdDireccion,
			const char *pchrPtrCalle,
			const char *pchrPtrNumero,
			const char *pchrPtrNumeroInt,
			const char *pchrPtrDelegacion,
			const char *pchrPtrColonia,
			const char *pchrPtrEstado,
			const char *pchrPtrCP)
{
(*this) 									<< 
new zSiscomCampo("IdDireccion",(const unsigned char *)pchrPtrIdDireccion)	<<
new zSiscomCampo("Calle",(const unsigned char *)pchrPtrCalle)			<<
new zSiscomCampo("Numero",(const unsigned char *)pchrPtrNumero)			<<
new zSiscomCampo("NumeroInt",(const unsigned char *)pchrPtrNumeroInt)		<<
new zSiscomCampo("Delegacion",(const unsigned char *)pchrPtrDelegacion)		<<
new zSiscomCampo("Colonia",(const unsigned char *)pchrPtrColonia)		<<
new zSiscomCampo("Estado",(const unsigned char *)pchrPtrEstado)			<<
new zSiscomCampo("CP",(const unsigned char *)pchrPtrCP)				<<
new zSiscomCampo("Calle1")							<<
new zSiscomCampo("Calle2")							<<
new zSiscomCampo("Referencias")							<<
new zSiscomCampo("EdoRegistro",(const unsigned char *)"0")			<<
new zSiscomCampo("IdDireccion0");
}

zDireccion::zDireccion(zSiscomRegistro *pzSisRegDireccion)
{
(*this) 								<< 
new zSiscomCampo("IdDireccion",(*pzSisRegDireccion)["idpersona"])	<<
new zSiscomCampo("Calle",(*pzSisRegDireccion)["calle"])			<<
new zSiscomCampo("Numero",(*pzSisRegDireccion)["numero"])		<<
new zSiscomCampo("NumeroInt",(*pzSisRegDireccion)["numext"])		<<
new zSiscomCampo("Delegacion",(*pzSisRegDireccion)["municipio"])	<<
new zSiscomCampo("Colonia",(*pzSisRegDireccion)["colonia"])		<<
new zSiscomCampo("Estado",(*pzSisRegDireccion)["estado"])		<<
new zSiscomCampo("CP",(*pzSisRegDireccion)["cp"])			<<
new zSiscomCampo("Calle1",(*pzSisRegDireccion)["calle1"])		<<
new zSiscomCampo("Calle2",(*pzSisRegDireccion)["calle2"])		<<
new zSiscomCampo("Referencias",(*pzSisRegDireccion)["referencias"])	<<
new zSiscomCampo("EdoRegistro",(*pzSisRegDireccion)["edoregistro"])	<<
new zSiscomCampo("IdDireccion0",(*pzSisRegDireccion)["iddireccion"]);
}
const char *zDireccion::Calle()
{
   return (const char *)Campo("Calle");
}

const char *zDireccion::Numero()
{
   return (const char *)Campo("Numero");
}
const char *zDireccion::NumeroInt()
{
   return (const char *)Campo("NumeroInt");
}
const char *zDireccion::Delegacion()
{
   return (const char *)Campo("Delegacion");
}
const char *zDireccion::Colonia()
{
   return (const char *)Campo("Colonia");
}
const char *zDireccion::CP()
{
   return (const char *)Campo("CP");
}
const char *zDireccion::Estado()
{
   return (const char *)Campo("Estado");
}
const char *zDireccion::Calle1()
{
	return CampoConstChar("Calle1");
}
const char *zDireccion::Calle2()
{
	return CampoConstChar("Calle2");
}

const char *zDireccion::Referencias()
{
   return (const  char *)Campo("Referencias");
}

void zDireccion::Calle1(const char *pchrPtrCalle1)
{
  ActualizaCampo("Calle1",(const unsigned char *)pchrPtrCalle1);
}
void zDireccion::Calle2(const char *pchrPtrCalle2)
{
  ActualizaCampo("Calle2",(const unsigned char *)pchrPtrCalle2);
}

void zDireccion::Referencias(const char *pchrPtrReferencias)
{
     ActualizaCampo("Referencias",(const unsigned char *)pchrPtrReferencias);
}
void zDireccion::IdDireccion0(const char *pchrPtrIdDireccion)
{
    ActualizaCampo("IdDireccion0",(const unsigned char *)pchrPtrIdDireccion);
}
zDireccion *zDireccion::Direccion(zSiscomRegistro *pzSisRegistro)
{
zDireccion *lzDireccion;
 lzDireccion=new zDireccion(pzSisRegistro->CampoConstChar("iddireccion"),
 		       pzSisRegistro->CampoConstChar("calle"),
		       pzSisRegistro->CampoConstChar("numero"),
		       pzSisRegistro->CampoConstChar("numext"),
		       pzSisRegistro->CampoConstChar("municipio"),
		       pzSisRegistro->CampoConstChar("colonia"),
		       pzSisRegistro->CampoConstChar("estado"),
		       pzSisRegistro->CampoConstChar("cp"));
lzDireccion->Referencias(pzSisRegistro->CampoConstChar("referencias"));
lzDireccion->IdDireccion0(pzSisRegistro->CampoConstChar("iddireccion"));
return lzDireccion;
}
