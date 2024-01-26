#include <zReportesServiSNTE.h>
#include <zListaPrecios.h>
#include <zStockTienda.h>
#include <zExistenciaProveedor.h>
#include <zProveedores.h>
zReportesServiSNTE::zReportesServiSNTE(zSiscomConexion *pzSisConexion,
				       const char *pchrPtrFuncion,
				       const char *pchrPtrModulo):
				zSiscomOperaciones(pzSisConexion,
						   pchrPtrModulo,
						   pchrPtrFuncion)
{



}
zSiscomRegistros *zReportesServiSNTE::StockDepartamentoProveedor(zSiscomRegistro *pzSisRegTienda,
				zSiscomRegistro *pzSisRegDepartamento,
				zSiscomRegistro *pzSisRegProveedor)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;


AgregaEnvio(zSiscomRegistro().Registro("%s [IdTienda] %s [IdDepartamento] %s [IdProveedor]",
					(*pzSisRegTienda)["idtienda"],
					/*
					(*pzSisRegDepartamento)["iddepartamento"], 
					*/
					"0",
					pzSisRegProveedor ? (*pzSisRegProveedor)["idempresa"]:0));

if((lzSisRegsRegreso=EnviaRecibe()))
{
 SiscomRegistrosLog(lzSisRegsRegreso);
  return lzSisRegsRegreso;
}
return 0;
}

zExistenciaProveedor *zReportesServiSNTE::ExistenciaProveedor(zSiscomRegistro *pzSisRegProveedor,
							      zSiscomRegistro *pzSisRegProducto)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdProveedor] %s [IdProducto] ",
				       (*pzSisRegProveedor)["idempresa"],
				       pzSisRegProducto ? (*pzSisRegProducto)["idproducto"] : 0));

if((lzSisRegsRegreso=EnviaRecibe()))
{
 SiscomRegistrosLog(lzSisRegsRegreso);
  return (zExistenciaProveedor *)lzSisRegsRegreso;
}
return 0;
}

zListaPrecios *zReportesServiSNTE::ListaPrecios(zSiscomRegistro *pzSisRegTienda,
						zSiscomRegistro *pzSisRegProveedor,
						char **pchrPtrMensajeError)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdTienda] %s [IdProveedor]",
				       (*pzSisRegTienda)["idtienda"],
				       (pzSisRegProveedor ? (*pzSisRegProveedor)["idempresa"]:0)));

if((lzSisRegsRegreso=EnviaRecibe()))
{
  if((lzSisRegRegreso=lzSisRegsRegreso->Primer()) &&
     lzSisRegRegreso->EstaElCampoEnElRegistro("EstadoConsulta")) 
  {
  	*pchrPtrMensajeError=(char *)(*lzSisRegRegreso)["Mensajes"];
	return 0;	
   }
  else
// SiscomRegistrosLog(lzSisRegsRegreso);
  return (zListaPrecios *)lzSisRegsRegreso;
}

return 0;
}

zListaPrecios *zReportesServiSNTE::ListaPreciosComprador(zSiscomRegistro *pzSisRegProveedor,
							 char **pchrPtrMensajeError)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdProveedor]",
					(pzSisRegProveedor ? (*pzSisRegProveedor)["idempresa"]:0)));

if((lzSisRegsRegreso=EnviaRecibe()))
{
  if((lzSisRegRegreso=lzSisRegsRegreso->Primer()) &&
     lzSisRegRegreso->EstaElCampoEnElRegistro("EstadoConsulta")) 
  {
  	*pchrPtrMensajeError=(char *)(*lzSisRegRegreso)["Mensajes"];
	return 0;	
   }
  else
{
  SiscomRegistrosLog(lzSisRegsRegreso);
  return (zListaPrecios *)lzSisRegsRegreso;
}
}

return 0;
}

zStockTienda *zReportesServiSNTE::StockTienda(zSiscomRegistro *pzSisRegTienda, zSiscomRegistro *pzSisRegProveedor)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdTienda] %s [IdProveedor]",
				       	(*pzSisRegTienda)["idtienda"],
					(pzSisRegProveedor ? (*pzSisRegProveedor)["idempresa"]:0)));

if((lzSisRegsRegreso=EnviaRecibe()))
{
   SiscomRegistrosLog(lzSisRegsRegreso);
  return (zStockTienda *)lzSisRegsRegreso;
}

return 0;
}

zDatosCompra *zReportesServiSNTE::DatosCompra(zSiscomRegistro *pzSisRegProveedor,
					      zSiscomRegistro *pzSisRegDepartamento)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdProveedor] %s [IdDepartamento]",
				       	(*pzSisRegProveedor)["idempresa"],
				       	(*pzSisRegDepartamento)["iddepartamento"]));



if((lzSisRegsRegreso=EnviaRecibe()))
{
   SiscomRegistrosLog(lzSisRegsRegreso);
  return (zDatosCompra *)lzSisRegsRegreso;
}

return 0;
}


zProveedores *zReportesServiSNTE::Proveedores(zSiscomRegistro *pzSisRegProveedor)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdProveedor] ",
		pzSisRegProveedor ? (*pzSisRegProveedor)["idempresa"] : 0));



if((lzSisRegsRegreso=EnviaRecibe()))
  return (zProveedores *)lzSisRegsRegreso;
return 0;
}


