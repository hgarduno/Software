#include <zEmpleo.h>
#include <zDireccion.h>
#include <zTelefonos.h>
#include <zPersona.h>
#include <zEmpresa.h>
#include <zOtrosIngresos.h>

#include <zSiscomCampo.h>
zEmpleo::zEmpleo(const char *pchrPtrIdPersona)
{
   (*this)									<<
   new zSiscomCampo("IdEmpleo")						<<
   new zSiscomCampo("IdPersona",(const unsigned char *)pchrPtrIdPersona)	<<
   new zSiscomCampo("Empresa")						<<
   new zSiscomCampo("Jefe")							<<
   new zSiscomCampo("Puesto")							<<
   new zSiscomCampo("Sueldo")							<<
   new zSiscomCampo("Antiguedad")						<<
   new zSiscomCampo("OtrosIngresos")						<<
   new zSiscomCampo("FrecuenciaPago")						<<
   new zSiscomCampo("TotalIngresos");
}
zEmpleo::zEmpleo(zSiscomRegistro *pzSisRegEmpleo)
{
zPersona *lzPerJefe=new zPersona(pzSisRegEmpleo);
   (*this)									<<
   new zSiscomCampo("IdEmpleo",(*pzSisRegEmpleo)["idempleo"])			<< 
   new zSiscomCampo("IdPersona")						<<
   new zSiscomCampo("Empresa")						<<
   new zSiscomCampo("Jefe")							<<
   new zSiscomCampo("Puesto")							<<
   new zSiscomCampo("Sueldo")							<<
   new zSiscomCampo("Antiguedad")						<<
   new zSiscomCampo("OtrosIngresos")						<<
   new zSiscomCampo("FrecuenciaPago")						<<
   new zSiscomCampo("TotalIngresos");

Puesto((const char *)(*pzSisRegEmpleo)["puesto"]);
Sueldo((const char *)(*pzSisRegEmpleo)["sueldo"]);
Antiguedad((const char *)(*pzSisRegEmpleo)["antiguedad"]);
Jefe(lzPerJefe);
OtrosIngresos(zOtrosIngresos().DesdeDatosEmpleo(pzSisRegEmpleo));
FrecuenciaPago((const char *)(*pzSisRegEmpleo)["frecuenciapago"]);
TotalIngresos((const char *)(*pzSisRegEmpleo)["totalingresos"]);
}
void zEmpleo::TotalIngresos(const char *pchrPtrTotalIngresos)
{
ActualizaCampo("TotalIngresos",(const unsigned char *)pchrPtrTotalIngresos);
}
void zEmpleo::FrecuenciaPago(const char *pchrPtrFrecPago)
{
 ActualizaCampo("FrecuenciaPago",(const unsigned char *)pchrPtrFrecPago);
}
void zEmpleo::FrecuenciaPago(zSiscomRegistro *pzSisRegFrecPago)
{
  ActualizaCampo("FrecuenciaPago",(*pzSisRegFrecPago)["nombre"]);
}
void zEmpleo::Puesto(const char *pchrPtrPuesto)
{
   ActualizaCampo("Puesto",(unsigned char *)pchrPtrPuesto); 
}

void zEmpleo::Sueldo(const char *pchrPtrSueldo)
{
   ActualizaCampo("Sueldo",(unsigned char *)pchrPtrSueldo);
}
void zEmpleo::Antiguedad(const char *pchrPtrAntiguedad)
{
   ActualizaCampo("Antiguedad",(unsigned char *)pchrPtrAntiguedad);
}
void zEmpleo::Empresa(zEmpresa *pzEmpresa)
{
   AsociadoAlCampo("Empresa",pzEmpresa);
}
void zEmpleo::Jefe(zPersona *pzPersona)
{
  AsociadoAlCampo("Jefe",pzPersona);
}
void zEmpleo::OtrosIngresos(zOtrosIngresos *pzOtrosIng)
{
  AsociadoAlCampo("OtrosIngresos",pzOtrosIng);
}
zPersona *zEmpleo::Jefe()
{
  return (zPersona *)AsociadoDelCampo("Jefe");
}
zEmpresa *zEmpleo::Empresa()
{
  return (zEmpresa *)AsociadoDelCampo("Empresa");
}

