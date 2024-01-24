#include <zEmpresa.h>
#include <zSiscomCampo.h>
#include <SiscomRegistros3.h>
zEmpresa::zEmpresa(const  char *pchrPtrIdEmpresa,
		   const char *pchrPtrRazonSocial)
{
(*this)	<<
new zSiscomCampo("IdEmpresa",(const unsigned char *)pchrPtrIdEmpresa)			<<
new zSiscomCampo("RazonSocial",(const unsigned char *)pchrPtrRazonSocial)		<<
new zSiscomCampo("RegimenFiscal");

}
const char *zEmpresa::RazonSocial()
{
   return (const char *)Campo("RazonSocial");
}
const char *zEmpresa::IdEmpresa()
{
   return (const char *)Campo("IdEmpresa");
}
void zEmpresa::IdEmpresa(const char *pchrPtrIdEmpresa)
{
	ActualizaCampo("IdEmpresa",(const unsigned char *)pchrPtrIdEmpresa);
}
void zEmpresa::RegimenFiscal(const char *pchrPtrRegimenFiscal)
{
  ActualizaCampo("RegimenFiscal",(const unsigned char *)pchrPtrRegimenFiscal);
}
/* Tepotzotlan Martes 14 de abril 2020 
 * Funcion static que , crea una objeto zEmpresa , cuando 
 *  pzSisRegEmpresa trae los datos consultados 
 *  directamente de la tabla empresas 
 */
zEmpresa *zEmpresa::DeConsultaEmpresas(zSiscomRegistro *pzSisRegEmpresa)
{
  return new zEmpresa((const char *)(*pzSisRegEmpresa)["idempresa"],
  		      (const char *)(*pzSisRegEmpresa)["razonsocial"]);
}
zEmpresa *zEmpresa::DeSiscomRegistro3(SiscomRegistro3 *pSisReg3Empresa)
{
 return new zEmpresa((*pSisReg3Empresa)["idempresa"],(*pSisReg3Empresa)["razonsocial"]);
}
