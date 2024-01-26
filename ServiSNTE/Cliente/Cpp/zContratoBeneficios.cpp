#include <zContratoBeneficios.h>
#include <zProductos.h>
#include <zDireccion.h>
#include <zTelefonos.h>
#include <zCorreo.h>
#include <zEmpleo.h>
#include <zEmpresa.h>
#include <zPersona.h>
#include <zSiscomCampo.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zCargoPublico.h>
#include <zAportacionTercero.h>
#include <zBeneficioTercero.h>
#include <zDatosGenerales.h>
#include <zDatosComunicacion.h>
#include <zGeneralesBeneficios.h>
#include <zReferenciasPersonales.h>
#include <zCentroTrabajo.h>


#include <zSiscomDesarrollo4.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

zContratoBeneficios::zContratoBeneficios(zSiscomRegistro *pzSisRegCliente)
{
  (*this) 						<<	
  new zSiscomCampo("Cliente")				<<
  new zSiscomCampo("Generales")			<<
  new zSiscomCampo("Productos")			<<
  new zSiscomCampo("DireccionParticular")		<<
  new zSiscomCampo("Comunicacion")			<<
  new zSiscomCampo("Credito")				<<
  new zSiscomCampo("TiempoResidir")			<<
  new zSiscomCampo("TipoVivienda")			<<
  new zSiscomCampo("Empleo")				<<
  new zSiscomCampo("CargoPublico")			<<
  new zSiscomCampo("BeneficioTercero")		<<
  new zSiscomCampo("AportacionTercero")		<<
  new zSiscomCampo("BeneficioTercero")		<<
  new zSiscomCampo("GeneralesContrato")		<<
  new zSiscomCampo("ReferenciasPersonales")		<<
  new zSiscomCampo("CentroTrabajo");
  AsociadoAlCampo("Cliente",pzSisRegCliente);
}
void zContratoBeneficios::CentroTrabajo(zCentroTrabajo *pzCentroTrabajo)
{
 AsociadoAlCampo("CentroTrabajo",pzCentroTrabajo);
}
void zContratoBeneficios::ReferenciasPersonales(zReferenciasPersonales *pzRefsPersonales)
{
  AsociadoAlCampo("ReferenciasPersonales",pzRefsPersonales);
}
void zContratoBeneficios::GeneralesContrato(zGeneralesBeneficios *pzGenBeneficios)
{
AsociadoAlCampo("GeneralesContrato",pzGenBeneficios);
}
void zContratoBeneficios::Comunicacion(zDatosComunicacion *pzDatComunicacion)
{
  AsociadoAlCampo("Comunicacion",pzDatComunicacion);
}
zDatosComunicacion *zContratoBeneficios::Comunicacion()
{
  return (zDatosComunicacion *)AsociadoDelCampo("Comunicacion");
}
zEmpleo *zContratoBeneficios::Empleo()
{
   return (zEmpleo *)AsociadoDelCampo("Empleo");
}
void zContratoBeneficios::Generales(zDatosGenerales *pzDatGenerales)
{
	AsociadoAlCampo("Generales",pzDatGenerales);
}
void zContratoBeneficios::BeneficioTercero(zBeneficioTercero *pzBeneficioTercero)
{
  	AsociadoAlCampo("BeneficioTercero",pzBeneficioTercero); 
}
void zContratoBeneficios::AportacionTercero(zAportacionTercero *pzAportacionTercero)
{
	AsociadoAlCampo("AportacionTercero",pzAportacionTercero);
}
void zContratoBeneficios::TiempoResidir(const char *pchrPtrTiempoResidir)
{
 ActualizaCampo("TiempoResidir",(unsigned char *)pchrPtrTiempoResidir);
}

void zContratoBeneficios::TipoVivienda(zSiscomRegistro *pzSisRegTipoVivienda)
{
 AsociadoAlCampo("TipoVivienda",pzSisRegTipoVivienda);
}
void zContratoBeneficios::Empleo(zEmpleo *pzEmpleo)
{
  AsociadoAlCampo("Empleo",pzEmpleo);
}
void zContratoBeneficios::DireccionParticular(zDireccion *pzDireccion)
{
    AsociadoAlCampo("DireccionParticular",pzDireccion);
}
void zContratoBeneficios::Productos(zProductos *pzProdsContratoBeneficios)
{
  AsociadosAlCampo("Productos",pzProdsContratoBeneficios);
}
void zContratoBeneficios::CargoPublico(zCargoPublico *pzCargoPublico)
{
   AsociadoAlCampo("CargoPublico",pzCargoPublico);
}
const char *zContratoBeneficios::IdVenta()
{
 return Cadena(CampoAsociado("Credito","idventa"));
}
zProductos *zContratoBeneficios::Productos()
{
    return (zProductos *)AsociadosDelCampo("Productos"); 
}

void zContratoBeneficios::Credito(zSiscomRegistro *pzSisRegCredito)
{
   AsociadoAlCampo("Credito",pzSisRegCredito);
}

const char *zContratoBeneficios::Lugar()
{
 return Cadena(CampoAsociado("GeneralesContrato","Lugar"));
}

const char *zContratoBeneficios::PagoQuincenal()
{
zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Credito")))
   return Cadena((*lzSisRegCredito)["pagoquincenal"]);
   else
   return "";
}
const char *zContratoBeneficios::Importe()
{
return Cadena(CampoAsociado("Credito","total"));
}
const char *zContratoBeneficios::ImporteLetra()
{
const char *lchrPtrImporte=Importe();
char *lchrPtrImporteLetra;
float lfltImporte=atof(lchrPtrImporte);
zSiscomQt3::SiscomALetra(lfltImporte,&lchrPtrImporteLetra);
return (const char *)lchrPtrImporteLetra;
}
const char *zContratoBeneficios::PagoTotal()
{
zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Credito")))
   return Cadena((*lzSisRegCredito)["pagototal"]);
   else
   return "";
}
const char *zContratoBeneficios::PagoTotalLetra()
{
const char *lchrPtrImporte=PagoTotal();
char *lchrPtrImporteLetra;
float lfltImporte;
if(*lchrPtrImporte)
{
lfltImporte=atof(lchrPtrImporte);
zSiscomQt3::SiscomALetra(lfltImporte,&lchrPtrImporteLetra);
return (const char *)lchrPtrImporteLetra;
}
else
return "";
}
const char *zContratoBeneficios::PagoQuincenalLetra()
{
const char *lchrPtrImporte=PagoQuincenal();
char *lchrPtrImporteLetra;
float lfltImporte=atof(lchrPtrImporte);
zSiscomQt3::SiscomALetra(lfltImporte,&lchrPtrImporteLetra);
return (const char *)lchrPtrImporteLetra;
}
const char *zContratoBeneficios::Plazo()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Credito")))
   return (const char *)(*lzSisRegCredito)["plazo"];
   else
   return "";
}
const char *zContratoBeneficios::Tasa()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Credito")))
   return (const char *)(*lzSisRegCredito)["tasa"];
   else
   return "";
}
const char *zContratoBeneficios::NumeroPagos()
{
return Cadena(CampoAsociado("Credito","numeropagos"));
}
const char *zContratoBeneficios::PorcentajeTasa()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Credito")))
   return (const char *)(*lzSisRegCredito)["porcentajetasa"];
   else
   return "";
}
const char *zContratoBeneficios::PorcentajeTasaLetra()
{
const char *lchrPtrPorcentajeTasa=PorcentajeTasa();
char *lchrPtrPorcentajeLetra;
float lfltPorcentaje=atof(lchrPtrPorcentajeTasa);
zSiscomQt3::SiscomALetraSinDecimal(lfltPorcentaje,&lchrPtrPorcentajeLetra);
return lchrPtrPorcentajeLetra;
}
const char *zContratoBeneficios::NombreCompleto()
{
char lchrArrCompleto[256];
sprintf(lchrArrCompleto,"%s %s %s",Nombre(),APaterno(),AMaterno());
return strdup(lchrArrCompleto);
}
const char *zContratoBeneficios::Nombre()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Cliente")))
   return (const char *)(*lzSisRegCredito)["nombre"];
   else
   return "";
}

const char *zContratoBeneficios::APaterno()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Cliente")))
   return (const char *)(*lzSisRegCredito)["apaterno"];
   else
   return "";
}
const char *zContratoBeneficios::AMaterno()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Cliente")))
   return (const char *)(*lzSisRegCredito)["amaterno"];
   else
   return "";
}
const char *zContratoBeneficios::RFC()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Cliente")))
   return (const char *)(*lzSisRegCredito)["rfc"];
   else
   return "";
}
const char *zContratoBeneficios::IdCliente()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("Cliente")))
   return (const char *)(*lzSisRegCredito)["idpersona"];
   else
   return "";
}

zDireccion *zContratoBeneficios::DireccionParticular()
{
  return (zDireccion *)AsociadoDelCampo("DireccionParticular");
}
const char *zContratoBeneficios::Calle()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("DireccionParticular")))
   return (const char *)(*lzSisRegCredito)["Calle"];
   else
   return "";
}

const char *zContratoBeneficios::NumExterior()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("DireccionParticular")))
   return Cadena((*lzSisRegCredito)["NumExterior"]);
   else
   return "";
}
const char *zContratoBeneficios::NumInterior()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("DireccionParticular")))
   return Cadena((*lzSisRegCredito)["NumInterior"]);
   else
   return "";
}
const char *zContratoBeneficios::Colonia()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("DireccionParticular")))
   return (const char *)(*lzSisRegCredito)["Colonia"];
   else
   return "";
}
const char *zContratoBeneficios::CodigoPostal()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("DireccionParticular")))
   return (const char *)(*lzSisRegCredito)["CodigoPostal"];
   else
   return "";
}
const char *zContratoBeneficios::Delegacion()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("DireccionParticular")))
   return (const char *)(*lzSisRegCredito)["DelegMunic"];
   else
   return "";
}
const char *zContratoBeneficios::Ciudad()
{
return "Ciudad";
}

const char *zContratoBeneficios::Estado()
{
  zSiscomRegistro *lzSisRegCredito;
  if((lzSisRegCredito=AsociadoDelCampo("DireccionParticular")))
   return (const char *)(*lzSisRegCredito)["Estado"];
   else
   return "";
}

const char *zContratoBeneficios::TelefonoParticular()
{
zTelefonos *lzTelefonos=Telefonos();
return lzTelefonos ? Cadena((const unsigned char *)lzTelefonos->TelefonoPorDsc("Particular")) : "" ;
}

const char *zContratoBeneficios::TelefonoCelular()
{
zTelefonos *lzTelefonos=Telefonos();
return lzTelefonos ? lzTelefonos->TelefonoPorDsc("Celular") :"" ;
}
const char *zContratoBeneficios::TelefonoRecados()
{
zTelefonos *lzTelefonos=Telefonos();
return  lzTelefonos ? lzTelefonos->TelefonoPorDsc("Recado"):""; 
}

const char *zContratoBeneficios::TiempoResidir()
{
   return Cadena((*this)["TiempoResidir"]);
}
const char *zContratoBeneficios::CorreoElectronico()
{
 return Cadena(CampoAsociadoAsociado("Comunicacion","Correo","Correo"));
}
const char *zContratoBeneficios::TipoViviendaPropia()
{
 zSiscomRegistro *lzSisRegDato=AsociadoDelCampo("TipoVivienda");
 if(lzSisRegDato && !strcmp((const char *)(*lzSisRegDato)["nombre"],"PROPIA"))
 return "[ / ]" ;
 else
 return "[   ]";
}

const char *zContratoBeneficios::TipoViviendaHipotecada()
{
 zSiscomRegistro *lzSisRegDato=AsociadoDelCampo("TipoVivienda");
 if(lzSisRegDato && !strcmp((const char *)(*lzSisRegDato)["nombre"],"HIPOTECADA"))
 return "[ / ]" ;
 else
 return "[   ]";
}
const char *zContratoBeneficios::TipoViviendaFamiliar()
{
 zSiscomRegistro *lzSisRegDato=AsociadoDelCampo("TipoVivienda");
 if(lzSisRegDato && !strcmp((const char *)(*lzSisRegDato)["nombre"],"FAMILIAR"))
 return "[ / ]" ;
 else
 return "[  ]";
}
const char *zContratoBeneficios::TipoViviendaRentada()
{
 zSiscomRegistro *lzSisRegDato=AsociadoDelCampo("TipoVivienda");
 if(lzSisRegDato && !strcmp((const char *)(*lzSisRegDato)["nombre"],"RENTADA"))
 return "[ / ]" ;
 else
 return "[   ]";
}
const char *zContratoBeneficios::EsTipoViviendaPropia()
{
 zSiscomRegistro *lzSisRegDato=AsociadoDelCampo("TipoVivienda");
 if(lzSisRegDato && !strcmp((const char *)(*lzSisRegDato)["nombre"],"PROPIA"))
 return "x" ;
 else
 return "";
}

const char *zContratoBeneficios::EsTipoViviendaHipotecada()
{
 zSiscomRegistro *lzSisRegDato=AsociadoDelCampo("TipoVivienda");
 if(lzSisRegDato && !strcmp((const char *)(*lzSisRegDato)["nombre"],"HIPOTECADA"))
 return "x" ;
 else
 return "";
}
const char *zContratoBeneficios::EsTipoViviendaFamiliar()
{
 zSiscomRegistro *lzSisRegDato=AsociadoDelCampo("TipoVivienda");
 if(lzSisRegDato && !strcmp((const char *)(*lzSisRegDato)["nombre"],"FAMILIAR"))
 return "x" ;
 else
 return "";
}
const char *zContratoBeneficios::EsTipoViviendaRentada()
{
 zSiscomRegistro *lzSisRegDato=AsociadoDelCampo("TipoVivienda");
 if(lzSisRegDato && !strcmp((const char *)(*lzSisRegDato)["nombre"],"RENTADA"))
 return "x" ;
 else
 return "";
}

const char *zContratoBeneficios::Antiguedad()
{
return Cadena(CampoAsociado("Empleo","Antiguedad"));
}
const char *zContratoBeneficios::Sueldo()
{
return Cadena(CampoAsociado("Empleo","Sueldo"));
}
const char *zContratoBeneficios::TotalIngresos()
{
return Cadena(CampoAsociado("Empleo","TotalIngresos"));
}
const char *zContratoBeneficios::OtrosIngresosMonto()
{
return Cadena(CampoAsociadoAsociado("Empleo","OtrosIngresos","Monto"));
}
const char *zContratoBeneficios::OtrosIngresosDescripcion()
{
return Cadena(CampoAsociadoAsociado("Empleo","OtrosIngresos","Descripcion"));
}

const char *zContratoBeneficios::Puesto()
{
return Cadena(CampoAsociado("Empleo","Puesto"));
}
const char *zContratoBeneficios::FrecuenciaPago()
{
return Cadena(CampoAsociado("Empleo","FrecuenciaPago"));
}

const char *zContratoBeneficios::EsFrecuenciaPagoSemanal()
{
   if(!strcmp("Semanal",FrecuenciaPago()))
   return "x";
   else
   return "";
}
const char *zContratoBeneficios::EsFrecuenciaPagoCatorcenal()
{
   if(!strcmp("Catorcenal",FrecuenciaPago()))
   return "x";
   else
   return "";
}
const char *zContratoBeneficios::EsFrecuenciaPagoQuincenal()
{
   if(!strcmp("Quincenal",FrecuenciaPago()))
   return "x";
   else
   return "";
}
const char *zContratoBeneficios::EsFrecuenciaPagoMensual()
{
   if(!strcmp("Mensual",FrecuenciaPago()))
   return "x";
   else
   return "";
}
const char *zContratoBeneficios::Empresa()
{
 return Cadena(CampoAsociadoAsociado("Empleo","Empresa","RazonSocial"));
}
const char *zContratoBeneficios::Giro()
{
  return Cadena(CampoAsociadoAsociado("Empleo","Empresa","Giro"));
} 

const char *zContratoBeneficios::NombreJefe() 
{
return Cadena(CampoAsociadoAsociado("Empleo","Jefe","Nombre"));

}

const char *zContratoBeneficios::APaternoJefe()
{
return Cadena(CampoAsociadoAsociado("Empleo","Jefe","APaterno"));
}
const char *zContratoBeneficios::AMaternoJefe()
{
return Cadena(CampoAsociadoAsociado("Empleo","Jefe","AMaterno"));
}
const char *zContratoBeneficios::CalleEmpleo()
{
zEmpleo *lzEmpleo;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  zEmpresa *lzEmpresa;
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    zDireccion *lzDireccion;
    if((lzDireccion=(zDireccion *)lzEmpresa->AsociadoDelCampo("Direccion")))
    return (const char *)(*lzDireccion)["Calle"];
    else
    return "";
  }
  else
  return "";
}
else
return "";
}
const char *zContratoBeneficios::NumExteriorEmpleo()
{
zEmpleo *lzEmpleo;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  zEmpresa *lzEmpresa;
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    zDireccion *lzDireccion;
    if((lzDireccion=(zDireccion *)lzEmpresa->AsociadoDelCampo("Direccion")))
    return Cadena((*lzDireccion)["NumExterior"]);
    else
    return "";
  }
  else
  return "";
}
else
return "";
}
const char *zContratoBeneficios::NumInteriorEmpleo()
{
zEmpleo *lzEmpleo;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  zEmpresa *lzEmpresa;
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    zDireccion *lzDireccion;
    if((lzDireccion=(zDireccion *)lzEmpresa->AsociadoDelCampo("Direccion")))
    return Cadena((*lzDireccion)["NumInterior"]);
    else
    return "";
  }
  else
  return "";
}
else
return "";
}
const char *zContratoBeneficios::ColoniaEmpleo()
{
zEmpleo *lzEmpleo;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  zEmpresa *lzEmpresa;
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    zDireccion *lzDireccion;
    if((lzDireccion=(zDireccion *)lzEmpresa->AsociadoDelCampo("Direccion")))
    return (const char *)(*lzDireccion)["Colonia"];
    else
    return "";
  }
  else
  return "";
}
else
return "";
}
const char *zContratoBeneficios::CodigoPostalEmpleo()
{
zEmpleo *lzEmpleo;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  zEmpresa *lzEmpresa;
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    zDireccion *lzDireccion;
    if((lzDireccion=(zDireccion *)lzEmpresa->AsociadoDelCampo("Direccion")))
    return (const char *)(*lzDireccion)["CodigoPostal"];
    else
    return "";
  }
  else
  return "";
}
else
return "";
}
const char *zContratoBeneficios::DelegacionEmpleo()
{
zEmpleo *lzEmpleo;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  zEmpresa *lzEmpresa;
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    zDireccion *lzDireccion;
    if((lzDireccion=(zDireccion *)lzEmpresa->AsociadoDelCampo("Direccion")))
    return (const char *)(*lzDireccion)["DelegMunic"];
    else
    return "";
  }
  else
  return "";
}
else
return "";
}
const char *zContratoBeneficios::EstadoEmpleo()
{
zEmpleo *lzEmpleo;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  zEmpresa *lzEmpresa;
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    zDireccion *lzDireccion;
    if((lzDireccion=(zDireccion *)lzEmpresa->AsociadoDelCampo("Direccion")))
    return (const char *)(*lzDireccion)["Estado"];
    else
    return "";
  }
  else
  return "";
}
else
return "";
}
const char *zContratoBeneficios::TelefonoEmpleo()
{
zEmpleo *lzEmpleo;
zEmpresa *lzEmpresa;
zTelefonos *lzTelefono;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    if((lzTelefono=(zTelefonos *)lzEmpresa->AsociadoDelCampo("Telefonos")))
	 return Cadena((const unsigned char *)lzTelefono->Telefono());
    else
    	 return "Empresa Sin Telefono";

  }
  else
  return "Empresa Sin Telefono";
}
else
{
   return "Contrato Sin Datos Empleo";
}
}

const char *zContratoBeneficios::CorreoEmpleo()
{
zEmpleo *lzEmpleo;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  zEmpresa *lzEmpresa;
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    zCorreo *lzCorreo;
    if((lzCorreo=(zCorreo *)lzEmpresa->AsociadoDelCampo("Correos")))
    return Cadena((*lzCorreo)["Correo"]);
    else
    return "";
  }
  else
  return "";
}
else
return "";
}
const char *zContratoBeneficios::Cadena(const unsigned char *pchrPtrCadena)
{
  return pchrPtrCadena ? (const char *)pchrPtrCadena : (const char *)"";
}

const char *zContratoBeneficios::Fecha()
{
 return Cadena(CampoAsociado("GeneralesContrato","Fecha"));
}
const char *zContratoBeneficios::FechaConMesLetra()
{
char lchrArrFecha[56];
sprintf(lchrArrFecha,
	"%s-%s-%s",
	DiaFecha(),
	MesFechaLetra(),
	AnioFecha());
return strdup(lchrArrFecha);
}
const char *zContratoBeneficios::CURP()
{
 return Cadena(CampoAsociado("Generales","CURP"));
}
const char *zContratoBeneficios::EstadoNacimiento()
{
  return Cadena(CampoAsociado("Generales","EstadoNacimiento"));
}
const char *zContratoBeneficios::PaisNacimiento()
{
 return Cadena(CampoAsociado("Generales","PaisNacimiento"));
}
const char *zContratoBeneficios::Genero()
{
  return Cadena(CampoAsociado("Generales","Genero"));
}
const char *zContratoBeneficios::EsMasculino()
{
   if(!strcmp("Masculino",Genero()))
   return "x";
   else
   return "";
}
const char *zContratoBeneficios::EsFemenino()
{
   if(!strcmp("Femenino",Genero()))
   return "x";
   else
   return "";
}

const char *zContratoBeneficios::EstadoCivil()
{
 return Cadena(CampoAsociado("Generales","EstadoCivil"));
}
const char *zContratoBeneficios::EsSoltero()
{
    if(!strcmp("Soltero",EstadoCivil()))
     return "x";
     else
     return "";
}
const char *zContratoBeneficios::EsCasado()
{
    if(!strcmp("Casado",EstadoCivil()))
     return "x";
     else
     return "";
}

const char *zContratoBeneficios::Edad()
{
 return Cadena(CampoAsociado("Generales","Edad"));
}

const char *zContratoBeneficios::FechaNacimiento()
{
 return Cadena(CampoAsociado("Generales","FechaNacimiento"));
}

const char *zContratoBeneficios::Identificacion()
{
 return Cadena(CampoAsociado("Generales","Identificacion"));
}
const char *zContratoBeneficios::NoIdentificacion()
{
 return Cadena(CampoAsociado("Generales","NoIdentificacion"));
}

const char *zContratoBeneficios::Ocupacion()
{
 return Cadena(CampoAsociado("Generales","Ocupacion"));
}

const char *zContratoBeneficios::Nacionalidad()
{
 return Cadena(CampoAsociado("Generales","Nacionalidad"));
}


const char *zContratoBeneficios::Jefe()
{
char lchrArrNombre[128];
sprintf(lchrArrNombre,"%s %s %s",NombreJefe(),APaternoJefe(),AMaternoJefe());
return strdup(lchrArrNombre);
}

const char *zContratoBeneficios::CiudadEmpleo()
{
 return "Ciudad Empleo";
}
const char *zContratoBeneficios::ExtensionEmpleo()
{
zEmpleo *lzEmpleo;
zEmpresa *lzEmpresa;
zTelefonos *lzTelefono;
if((lzEmpleo=(zEmpleo *)AsociadoDelCampo("Empleo")))
{
  if((lzEmpresa=(zEmpresa *)lzEmpleo->AsociadoDelCampo("Empresa")))
  {
    if((lzTelefono=(zTelefonos *)lzEmpresa->AsociadoDelCampo("Telefonos")))
	 return Cadena((const unsigned char *)lzTelefono->Extension());
    else
    	 return "Empresa Sin Telefono";

  }
  else
  return "Empresa Sin Telefono";
}
else
{
   return "Contrato Sin Datos Empleo";
}

}

zTelefonos *zContratoBeneficios::Telefonos()
{
zTelefonos *lzTelefonos=(zTelefonos *)AsociadoDelCampo("Comunicacion");
return lzTelefonos;
}

const char *zContratoBeneficios::NombreReferencia(int pintNReferencia)
{
char lchrArrNombre[128];
zReferenciasPersonales *lzRefsPersonales=(zReferenciasPersonales *)AsociadoDelCampo("ReferenciasPersonales");
if(lzRefsPersonales)
{
zSiscomRegistro *lzSisRegNombre=(*lzRefsPersonales->Nombres())[pintNReferencia];
if(lzSisRegNombre)
{
sprintf(lchrArrNombre,
	"%s %s %s",
	(*lzSisRegNombre)["Nombre"],
	(*lzSisRegNombre)["APaterno"],
	(*lzSisRegNombre)["AMaterno"]);
return strdup(lchrArrNombre);
}
else
return "";
}
else
return "";
}
const char *zContratoBeneficios::DomicilioReferencia(int pintNReferencia)
{
char lchrArrDomicilio[128];
zReferenciasPersonales *lzRefsPersonales=(zReferenciasPersonales *)AsociadoDelCampo("ReferenciasPersonales");
if(lzRefsPersonales)
{
zSiscomRegistro *lzSisRegDomicilio=(*lzRefsPersonales->Direcciones())[pintNReferencia];
if(lzSisRegDomicilio)
{
sprintf(lchrArrDomicilio,
	"%s %s %s %s",
	(*lzSisRegDomicilio)["Calle"],
	Cadena((*lzSisRegDomicilio)["NumExterior"]),
	Cadena((*lzSisRegDomicilio)["NumInterior"]),
	(*lzSisRegDomicilio)["Colonia"]);
return strdup(lchrArrDomicilio);
}
else
return "";
}
else
return "";
}
const char *zContratoBeneficios::TelefonoReferencia(int pintNReferencia)
{
zReferenciasPersonales *lzRefsPersonales=(zReferenciasPersonales *)AsociadoDelCampo("ReferenciasPersonales");
if(lzRefsPersonales)
{
zTelefonos *lzTelefonos=(zTelefonos *)(*lzRefsPersonales->Telefonos())[pintNReferencia];
if(lzTelefonos)
return Cadena((const unsigned char *)lzTelefonos->Telefono());
else
return "";
}
else
return "";
}
const char *zContratoBeneficios::ParentescoReferencia(int pintNReferencia)
{

}

const char *zContratoBeneficios::DiaFecha()
{
const char *lchrPtrFecha=Fecha();
const char *lchrPtrDia=lchrPtrFecha+8;;
return lchrPtrDia;
}

const char *zContratoBeneficios::MesFecha()
{
const char *lchrPtrFecha=Fecha();
char *lchrPtrMes=chrArrMes;
strncpy(lchrPtrMes,lchrPtrFecha+5,2);
*(lchrPtrMes+2)=0;
return lchrPtrMes;
}

const char *zContratoBeneficios::AnioFecha()
{
const char *lchrPtrFecha=Fecha();
char *lchrPtrAnio=chrArrAnio;
strncpy(lchrPtrAnio,lchrPtrFecha,4);
*(lchrPtrAnio+4)=0;
return lchrPtrAnio;
}
const char *zContratoBeneficios::MesFechaLetra()
{
const char *lchrPtrMeses[]={"Ene",
			    "Feb",
			    "Mar",
			    "Abr",
			    "May",
			    "Jun",
			    "Jul",
			    "Ago",
			    "Sep",
			    "Oct",
			    "Nov",
			    "Dic"};

return strdup(lchrPtrMeses[atoi(MesFecha())-1]);
}
zCentroTrabajo *zContratoBeneficios::CentroTrabajo()
{
return (zCentroTrabajo *)AsociadoDelCampo("CentroTrabajo");
}
const char *zContratoBeneficios::CentroTrabajo2()
{
return Cadena(CampoAsociado("CentroTrabajo","CentroTrabajo"));
}
const char *zContratoBeneficios::ClavePresupuestal()
{
return Cadena(CampoAsociado("CentroTrabajo","ClavePresupuestal"));
}
