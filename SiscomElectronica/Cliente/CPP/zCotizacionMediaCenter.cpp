#include <zCotizacionMediaCenter.h>
#include <zSiscomCampo.h>
#include <string.h>
#include <zSiscomDesarrollo4.h>
zCotizacionMediaCenter::zCotizacionMediaCenter():
			zCotizacion()
{
IniciaCampos();
}
zCotizacionMediaCenter::zCotizacionMediaCenter(zCotizacion *pzCotizacion):
			zCotizacion()
{
IniciaCampos();

   ActualizaCampo("Descripcion",(const unsigned char*)pzCotizacion->Descripcion());
}



void zCotizacionMediaCenter::CadenaCompleta(const char *pchrPtrEscuela)
{
const char *lchrPtrNombre,
	   *lchrPtrTelefono;

lchrPtrNombre=Identificacion(&lchrPtrTelefono);
sprintf(chrArrCadena,
	 "00:00\n"
	 "\n"
         "%s %s\n"
	 "Entregar en %s\n"
	 "\n"
	 "Paga con 000.00",
	 lchrPtrNombre,
	 lchrPtrTelefono,
	 pchrPtrEscuela);
if(PagaCon())
sprintf(chrArrCadena,
	 "00:00\n"
	 "\n"
         "%s %s\n"
	 "Entregar en %s\n"
	 "\n"
	 "Paga con %s",
	 lchrPtrNombre,
	 lchrPtrTelefono,
	 pchrPtrEscuela,
	 PagaCon());

if(PagaCon() && Hora())
sprintf(chrArrCadena,
	 "%s\n"
	 "\n"
         "%s %s\n"
	 "Entregar en %s\n"
	 "\n"
	 "Paga con %s",
	 Hora(),
	 lchrPtrNombre,
	 lchrPtrTelefono,
	 pchrPtrEscuela,
	 PagaCon());

}
const char *zCotizacionMediaCenter::Identificacion(const char **pchrPtrTelefono)
{
const char *lchrPtrNombre;
    *pchrPtrTelefono=Telefono() ? Telefono() : "";

   lchrPtrNombre=Nombre();

    return lchrPtrNombre ? lchrPtrNombre : "";

}
void zCotizacionMediaCenter::DescripcionMediaCenterEnvio()
{
SiscomRegistroLog2(this);
CadenaCompleta(Escuela() ? Escuela() :"_");
LogSiscom("%s",chrArrCadena);
Descripcion(chrArrCadena);
}
void zCotizacionMediaCenter::DescripcionMediaCenterCotizacion()
{
   if(Telefono())
    sprintf(chrArrCadena,"%s",Telefono());
   if(Nombre())
   sprintf(chrArrCadena,"%s",Nombre());
 Descripcion(chrArrCadena);
}
void zCotizacionMediaCenter::DescripcionMediaCenter()
{
   if(!CampoVsCadena("Modo","Cotizacion"))
    DescripcionMediaCenterCotizacion();
   else
   if(!CampoVsCadena("Modo","Envio"))
   DescripcionMediaCenterEnvio();
}
void zCotizacionMediaCenter::Telefono(const char *pchrPtrTelefono)
{
 ActualizaCampo("Telefono",(const unsigned char *)pchrPtrTelefono);
}
void zCotizacionMediaCenter::PagaCon(const char *pchrPtrPagaCon)
{
 ActualizaCampo("PagaCon",(const unsigned char *)pchrPtrPagaCon);
}

void zCotizacionMediaCenter::Hora(const char *pchrPtrHora)
{
 ActualizaCampo("Hora",(const unsigned char *)pchrPtrHora);
}
void zCotizacionMediaCenter::LlevarA(const char *pchrPtrLlevarA)
{

}
void zCotizacionMediaCenter::Escuela(const char *pchrPtrEscuela)
{
   ActualizaCampo("Escuela",(const unsigned char *)pchrPtrEscuela);
}

void zCotizacionMediaCenter::Modo(const char *pchrPtrModo)
{
   ActualizaCampo("Modo",(const unsigned char *)pchrPtrModo);
}

void zCotizacionMediaCenter::Nombre(const char *pchrPtrNombre)
{
   ActualizaCampo("Nombre",(const unsigned char *)pchrPtrNombre);
}
const char *zCotizacionMediaCenter::Hora()
{
	return (const char *)Campo("Hora");
}

const char *zCotizacionMediaCenter::PagaCon()
{
	return (const char *)Campo("PagaCon");
}

const char *zCotizacionMediaCenter::Telefono()
{
	return (const char *)Campo("Telefono");
}
const char *zCotizacionMediaCenter::Escuela()
{

	return (const char *)Campo("Escuela");
}

const char *zCotizacionMediaCenter::Modo()
{
	return (const char *)Campo("Modo");
}

const char *zCotizacionMediaCenter::Nombre()
{
	return (const char *)Campo("Nombre");
}
void zCotizacionMediaCenter::IniciaCampos()
{
 (*this)			<<
 new zSiscomCampo("Telefono")	<<
 new zSiscomCampo("Hora")	<<
 new zSiscomCampo("PagaCon")	<<
 new zSiscomCampo("Escuela")	<<
 new zSiscomCampo("Modo")	<<
 new zSiscomCampo("Nombre");
}
