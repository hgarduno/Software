#include <RNProductos.h>
#include <RNPersonas.h>
#include <ServidorGeneral.h>
#include <ManejoCapacitores.h>

#include <ComunElectronica.h>
#include <ComunElectronica2.h>
#include <string.h>
#include <stdlib.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;

/*  Consulta Productos a un % de la existencia
 *  Si se tiene que el producto debe tener como existencia minima
 *  20, y se pide que me de el porcentaje de la existencia con la
 *  que este producto esta actualmente, si el producto tiene 40, 
 *  se tendra a al 100 % de la existencia minima
 *  entonces la formula es la siguiente 
 *  20 -> 100% Existencia Minima
 *  20 -> x
 *
 *  (40*100)/20 = 
 */
StcConsultas gStcCnsProductos[]={
	{EsConsultaCodigoCapacitores,FormaConsultaCodigoCapacitores},
	{EsConsultaProductos,FormaConsultaProductos},
	{EsConsultaDatosProductos,FormaConsultaDatosProductos},
	{EsConsultaProductosSimilares,FormaConsultaProductosSimilares},
	{EsConsultaPrecioProducto,FormaConsultaPrecioProducto},
	{EsConsultaUltimaCompra,FormaConsultaUltimaCompra},
	{EsConsultaPorcentajeExistenciaMinima,FormaConsultaPorcentajeExistenciaMinima}
				};
int gintCnsProductos=7;

int EsConsultaPorcentajeExistenciaMinima(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ConsultaPorcentajeExistenciaMinima");
}
void FormaConsultaPorcentajeExistenciaMinima(char **pchrPtrEntrada,
					     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];

 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
/*{*/
 sprintf(lchrArrConsulta,
 	 "SELECT a.* ,					\n\
	 	 0 as unidad,				\n\
		 0 as idfamilia,			\n\
		 0 as precio,				\n\
		 '' as nmbtipoprecio,			\n\
		 0 as cantidad,				\n\
		 0 as idcliente,			\n\
		 0 as importe,				\n\
		 0 as sepuedevender,			\n\
		 0 as numjuegos,			\n\
		 0 as idproveedor,			\n\
		 '' as numfactura,			\n\
		 '' as fechapago,			\n\
		 '' as edoregistro,			\n\
		 0 as idpractica,			\n\
		 '' as nmbunidad,			\n\
		 '' as abreviatura,			\n\
		 '' as nmbfamilia,			\n\
		 '' as dscproducto			\n\
	  from vporexistenciaminima as a		\n\
	  where idexpendio=%s and 			\n\
	        poreximinima>=%s and			\n\
		poreximinima<=%s			\n\
	  order by existencia",
	   pchrPtrEntrada[1],
	   pchrPtrEntrada[2],
	   pchrPtrEntrada[3]);
SiscomLog(
		  "%s",
		  lchrArrConsulta);
 /*}*/
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);




}

int EsConsultaPrecioProducto(char **pchrPtrEntrada)
{

	return !strcmp(pchrPtrEntrada[0],"ConsultaPrecioProducto");

}
void FormaConsultaPrecioProducto(char **pchrPtrEntrada,
				    SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrSimilares[1024];
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
/* Tepotzotlan Mexico Martes 15 Enero 2019
 * Desarrollo para la integracion de los precios
 * para mayoreo
 */
sprintf(lchrArrSimilares,
	"select a.CveProducto,						\n\
		'' as dscproducto,					\n\
		0 as unidad,						\n\
		0 as idfamilia,						\n\
		b.precio,						\n\
		b.nmbtipoprecio,					\n\
		0 as cantidad,						\n\
		0 as existencia,					\n\
		0 as idcliente,						\n\
		0 as idexpendio,					\n\
		0 as importe, 						\n\
		0 as sepuedevender, 					\n\
		0 as numjuegos, 					\n\
		0 as idproveedor,					\n\
		'' as numfactura, 					\n\
		'' as fechapago, 					\n\
		'' as edoregistro, 					\n\
		0 as idpractica, 					\n\
		''  as nmbunidad, 					\n\
		'' as abreviatura, 					\n\
		'' as nmbfamilia					\n\
	from	productos as a 						\n\
		inner join precios as b using(CveProducto) 		\n\
	where a.CveProducto='%s' and b.idpersona=%s",
	pchrPtrEntrada[1],
	pchrPtrEntrada[2]);
SiscomLog("%s",lchrArrSimilares);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrSimilares);
}


int EsConsultaProductosSimilares(char **pchrPtrEntrada)
{

	return !strcmp(pchrPtrEntrada[0],"ConsultaSimilares");

}
void FormaConsultaProductosSimilares(char **pchrPtrEntrada,
				    SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrSimilares[1024];
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 /*  Tepotzotlan Mexico 
  *  1 Septiembre del 2021 Seguimos con lo del Covid 
  *  se agrega a.idpersona = 1153257207 
  *  para filtrar solo los precios de public en general, ya que al 
  *  incluir los precios, para clientes diferentes la consulta se 
  *  hace sobre los productos mas los clientes ahorita creo que 
  *  hay cuatro clientes, con lo que los productos que se regresan son 12000
  */
 if(*(pchrPtrEntrada[1]))
sprintf(lchrArrSimilares,
 	 "											\n\
	 	SELECT	a.CveProducto,								\n\
			        a.DscProducto,							\n\
				a.Unidad,							\n\
				a.IdFamilia,							\n\
				b.NmbUnidad,							\n\
				b.Abreviatura,							\n\
				c.NmbFamilia,							\n\
				e.precio,							\n\
				d.existencia as existencia,					\n\
				'' as eximinima							\n\
			from    productos as a							\n\
				inner join unidades as b using(unidad)				\n\
				inner join familias as c using(idFamilia)			\n\
				inner join existencias as d using(cveproducto)			\n\
				inner join precios as e on (a.cveproducto=e.cveproducto and	\n\
							    nmbtipoprecio='DEFAULT')		\n\
			where a.CveProducto like '%%%s%%' and					\n\
			      d.idexpendio=%s		  and					\n\
			      e.idpersona=1153257207						\n\
			order by a.CveProducto",
			pchrPtrEntrada[1],
			pchrPtrEntrada[4]);
else
sprintf(lchrArrSimilares,
 	 "											\n\
	 	SELECT	a.CveProducto,								\n\
			        a.DscProducto,							\n\
				a.Unidad,							\n\
				a.IdFamilia,							\n\
				b.NmbUnidad,							\n\
				b.Abreviatura,							\n\
				c.NmbFamilia,							\n\
				e.precio,							\n\
				d.existencia as existencia,					\n\
				'' as eximinima							\n\
			from    productos as a							\n\
				inner join unidades as b using(unidad)				\n\
				inner join familias as c using(idFamilia)			\n\
				inner join existencias as d using(cveproducto)			\n\
				inner join precios as e on (a.cveproducto=e.cveproducto and	\n\
							    nmbtipoprecio='DEFAULT')		\n\
			where d.idexpendio=%s and						\n\
			      e.idpersona=1153257207						\n\
			order by a.CveProducto",
			pchrPtrEntrada[4]);

 SiscomLog("%s",lchrArrSimilares);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrSimilares);
}
int EsConsultaProductosDescripcion(char **pchrPtrEntrada)
{

	return !strcmp(pchrPtrEntrada[0],"ConsultaSimilares");

}
void FormaConsultaProductosDescripcion(char **pchrPtrEntrada,
				    SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrSimilares[1024];
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
sprintf(lchrArrSimilares,
 	 "SELECT	a.CveProducto,						\n\
			        a.DscProducto,					\n\
				a.Unidad,					\n\
				a.IdFamilia,					\n\
				b.NmbUnidad,					\n\
				b.Abreviatura,					\n\
				c.NmbFamilia,					\n\
				'' as precio					\n\
			from    productos as a					\n\
				inner join unidades as b using(unidad)		\n\
				inner join familias as c using(idFamilia)	\n\
			where a.CveProducto like '%%%s%%'",
			pchrPtrEntrada[1]);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrSimilares);
}		
int EsConsultaProductos(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ProductosExpendio");
}

void FormaConsultaProductos(char **pchrPtrEntrada,
			    SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrCadenaConsulta[1024];

	sprintf(lchrArrCadenaConsulta,
		"select a.*,							\n\
			'' as nmbUnidad,					\n\
			'' as abreviatura,					\n\
			'' as nmbfamilia,					\n\
			'' as precio,						\n\
			b.existencia,						\n\
			b.eximinima,						\n\
			c.idtipoproducto					\n\
		from productos as a inner join					\n\
		     existencias as b using(cveproducto) left outer  join	\n\
		     productoportipoproducto as c using(cveproducto) 		\n\
		where b.idexpendio=%s						\n\
		order by cveproducto",
		pchrPtrEntrada[4]);

 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrCadenaConsulta);
SiscomLog("La Consulta:%s",lchrArrCadenaConsulta);
}

int EsConsultaDatosProductos(char **pchrPtrEntrada)
{

	return !strcmp(pchrPtrEntrada[0],"DatosProducto");
	
}

void FormaConsultaDatosProductos(char **pchrPtrEntrada,
			    SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrCadena[1024];

 
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 if(!pchrPtrEntrada[2] &&
    !pchrPtrEntrada[3])
 sprintf(lchrArrCadena,
 	 "SELECT	a.CveProducto,						\
			        a.DscProducto,					\
				a.Unidad,					\
				a.IdFamilia,					\
				b.NmbUnidad,					\
				b.Abreviatura,					\
				c.NmbFamilia,					\
				'' as precio,					\
				'' as eximinima					\
			from    productos as a					\
				inner join unidades as b using(unidad)		\
				inner join familias as c using(idFamilia)	\
			where a.CveProducto='%s'",
			pchrPtrEntrada[1]);
  else
  {
  	SiscomLog("Consulta Total : %s %s",
			  pchrPtrEntrada[1],
			  pchrPtrEntrada[2]);
  	if(!strcmp(pchrPtrEntrada[3],"Total"))
	sprintf(lchrArrCadena,
 	 	"SELECT	a.CveProducto,						\
			        a.DscProducto,					\
				a.Unidad,					\
				a.IdFamilia,					\
				b.NmbUnidad,					\
				b.Abreviatura,					\
				c.NmbFamilia,					\
				'' as precio,					\
				d.existencia,					\
				d.eximinima,					\
				d.idexpendio					\
			from    productos as a					\
				inner join unidades as b using(unidad)		\
				inner join familias as c using(idFamilia)	\
				inner join existencias as d using(cveProducto)  \
			where a.CveProducto='%s' and				\
			      d.idExpendio=%s					\
			order by d.existencia asc",
			pchrPtrEntrada[1],
			pchrPtrEntrada[2]);
	if(!strcmp(pchrPtrEntrada[3],"Similares"))
	{
	SiscomLog("La Consulta....");	
	sprintf(lchrArrCadena,
 	 	"SELECT	a.CveProducto,						\
			        a.DscProducto,					\
				a.Unidad,					\
				a.IdFamilia,					\
				b.NmbUnidad,					\
				b.Abreviatura,					\
				c.NmbFamilia,					\
				'' as precio,					\
				d.existencia,					\
				d.eximinima,					\
				d.idexpendio					\
			from    productos as a					\
				inner join unidades as b using(unidad)		\
				inner join familias as c using(idFamilia)	\
				inner join existencias as d using(cveProducto)  \
			where a.CveProducto like '%%%s%%' and			\
			      d.idExpendio=%s					\
			 order by d.existencia asc",
			pchrPtrEntrada[1],
			pchrPtrEntrada[2]);
	}


  }

 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrCadena);
				
}
int EsConsultaUltimaCompra(char **pchrPtrEntrada)
{

	return !strcmp(pchrPtrEntrada[0],"ConsultaUltimaCompra");
}

void FormaConsultaUltimaCompra(char **pchrPtrEntrada,
			    SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];

 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 sprintf(lchrArrConsulta,
 	 "select	compras.fecha,							\n\
	 		compras.CveProducto,						\n\
			compras.precio as PrecioCompra,					\n\
			compras.cantidad,						\n\
			compras.numfactura,						\n\
			a.Precio as PrecioVenta,					\n\
			b.IdEmpresa as IdProveedor, 					\n\
			b.RazonSocial as Proveedor 					\n\
	from    compras 								\n\
		left outer join precios as a on (compras.CveProducto=a.CveProducto and 	\n\
					     idpersona ='%s')				\n\
		left outer join empresas as b on(proveedor=b.idempresa) 		\n\
	where compras.CveProducto='%s'  and 						\n\
	      idExpendio=%s 								\n\
	order by fecha desc",
	pchrPtrEntrada[2],
	pchrPtrEntrada[1],
	pchrPtrEntrada[3]);

 	
SiscomLog("FormaConsultaUltimaCompra:%s",
		  lchrArrConsulta);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
			
}
void AnalizaConsultaProductos(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsProductos;
	    lintContador++)
	   if(gStcCnsProductos[lintContador].Consulta(pchrPtrEntrada))
	   {
	     SiscomLog("%d",lintContador);
	     gStcCnsProductos[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);
	     return;
	   }


}
void ConsultaProductos(int pintSocket,
		       int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;

	lSOpServidor.EjecutaProcesoAntes=0;
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	SiscomContenidoProtocolo(lSOpServidor.LCSiscomPro2Dat);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	ElectronicaComunicacionExpendio2(lchrPtrEntrada[4],
					  &lSOpServidor.intPtoCom, 
					  lSOpServidor.chrPtrDirIpSvr,
					  0);
	AnalizaConsultaProductos(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);
}
void FormaConsultaProductosParaDescripcion(char **pchrPtrEntrada,
			    SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrCadena[1024];
SiscomLog("%s",pchrPtrEntrada[0]);
SiscomLog("%s",pchrPtrEntrada[1]);
SiscomLog("%s",pchrPtrEntrada[2]);

 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 /*
 sprintf(lchrArrCadena,
 	 "SELECT CveProducto,					\n\
		 DscProducto					\n\
	   from    productos					\n\
	   order by CveProducto");
*/

 sprintf(lchrArrCadena,
	 "											\n\
	 	SELECT	a.CveProducto,								\n\
			        a.DscProducto,							\n\
				a.Unidad,							\n\
				a.IdFamilia,							\n\
				b.NmbUnidad,							\n\
				b.Abreviatura,							\n\
				c.NmbFamilia,							\n\
				e.precio,							\n\
				d.existencia as existencia,					\n\
				'' as eximinima							\n\
			from    productos as a							\n\
				inner join unidades as b using(unidad)				\n\
				inner join familias as c using(idFamilia)			\n\
				inner join existencias as d using(cveproducto)			\n\
				inner join precios as e on (a.cveproducto=e.cveproducto and	\n\
							    nmbtipoprecio='DEFAULT')		\n\
			where d.idexpendio=%s							\n\
			order by a.CveProducto",
			pchrPtrEntrada[1]);

SiscomLog("%s",lchrArrCadena);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrCadena);
				
}
void BuscaCadenaEnLaDescripcion(const char *pchrPtrCadena,
				LCamposSiscomPro2 *pLCSiscomPro2,
				int *pintPtrNRegistrosRes,
				LCamposSiscomPro2 **pLCSiscomPro2Res)
{
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
	*pintPtrNRegistrosRes=0;
	for(;
		pLCSiscomPro2;
		pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
	   if(strstr(SiscomObtenDato(pLCSiscomPro2,"dscproducto"),pchrPtrCadena))
	   {
	   SiscomAnexaRegistroPro2(pLCSiscomPro2Res,
	   			   &lLCSiscomPro2Act,
				   pintPtrNRegistrosRes,
				   "cveproducto,	\
				    dscproducto,	\
				    unidad,		\
				    idfamilia,		\
				    precio,		\
				    nmbprecio,		\
				    cantidad,		\
				    existencia,		\
				    idcliente,		\
				    idexpendio,		\
				    importe,		\
				    sepuedevender,	\
				    numjuegos,		\
				    idproveedor,	\
				    proveedor,		\
				    numfactura,		\
				    fechapago,		\
				    edoregistro,	\
				    idpractica,		\
				    nmbunidad,		\
				    abreviatura,	\
				    nmbfamilia",
				    SiscomObtenDato(pLCSiscomPro2,"cveproducto"),
				    SiscomObtenDato(pLCSiscomPro2,"dscproducto"),
				    "",
				    "",
				    SiscomObtenDato(pLCSiscomPro2,"precio"),
				    "",
				    "",
				    SiscomObtenDato(pLCSiscomPro2,"existencia"),
				    "",
				    "",
				    "",
				    "",
				    "",
				    "",
				    "",
				    "",
				    "",
				    "",
				    "",
				    "",
				    "",
				    SiscomObtenDato(pLCSiscomPro2,"nmbfamilia"));
	   }


	}

}
				
void ConsultaProductosDescripcion(int pintSocket,
		       int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
int lintNRegRespuesta;
char **lchrPtrEntrada=0;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
	/*
	 * HGE Queretaro 6 De agos 2008 
	 * Se agrego la inicializacion de la variable
	 * EjecutaProcesoAntes, ya que al no tener
	 * un dato valido, en la funcion
	 * SiscomIniciaComunicacionesSrv, se cumplia
	 * la condicion, y se ejecutaba EjecutaProcesoAntes
	 * lo que generaba una SIGSEV
	 *
	 * Este error impedia que los datos del resultado
	 * de la busqueda regresaran de manera correcta 
	 * a la interfaz
	 */
	lSOpServidor.EjecutaProcesoAntes=0;
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	/* 
	 * HGE Cuahutitlan Izcalli
	 * Necesito revisar, porque razon tengo la consulta
	 * de productos aqui
	 *
	 */
	AnalizaConsultaProductos(lchrPtrEntrada,&lSOpServidor);
	FormaConsultaProductosParaDescripcion(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	BuscaCadenaEnLaDescripcion(lchrPtrEntrada[2],
				   lSOpServidor.LCSiscomPro2,
				   &lintNRegRespuesta,
				   &lLCSiscomPro2Res);

	SiscomEnviaAlServidor(pintSocket,
			      lintNRegRespuesta,
			      "ClientesRegistrados",
			      lLCSiscomPro2Res);
	close(pintSocket);
}
void ActualizaPrecio(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador;
char **lchrPtrEntrada;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
	SiscomCopiaDatosProtocoloCharChar(lLCSiscomPro2,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
/*
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
*/
  {
	 sprintf(lchrArrActualiza,
	 	 "update precios set Precio=%s  \
		  where CveProducto='%s' and	\
		        idpersona=%s;",
		  lchrPtrEntrada[3],
		  lchrPtrEntrada[1],
		  lchrPtrEntrada[2]);
	SiscomLog("%s",lchrArrActualiza);		 		       
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL,EdoRegistro",
				 lchrArrActualiza,
				 "");
  }
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	/*  
	 *  Jueves 8 de Agosto 2019
	 *  CDMX 
	 * Se elimina la replicacion de los precios a los demas expendios
	 * if(lchrPtrEdoConexion)
	 * SiscomLog(
	 *		  "Error Al Enviar:%s",
	 *                 lchrPtrEdoConexion);
	 *	InsertandoALosExpendios(lintNRegistros,lLCSiscomPro2Ins);
	 */
}
void ActualizaProducto(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0,
		  *lLCSiscomPro2RegIns=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador;

SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 sprintf(lchrArrActualiza,
	 	 "update Productos set DscProducto='%s',   \
		  		       Unidad=%s,	   \
				       IdFamilia=%s	   \
		  where CveProducto='%s'",
		  SiscomObtenDato(lLCSiscomPro2,"DscProducto"),
		  SiscomObtenDato(lLCSiscomPro2,"IdUnidad"),
		  SiscomObtenDato(lLCSiscomPro2,"IdFamilia"),
		  SiscomObtenDato(lLCSiscomPro2,"CveProducto"));

		 		       
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL,EdoRegistro",
				 lchrArrActualiza);
  }
       
       SiscomLog("Actualizando algun dato del producto");
        SiscomContenidoProtocolo(lLCSiscomPro2Ins);
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	 InsertandoALosExpendios(lintNRegistros,
	 			 lLCSiscomPro2Ins,
				 &lLCSiscomPro2RegIns);

	if(lchrPtrEdoConexion)
	SiscomLog("Error Al Enviar:%s",lchrPtrEdoConexion);
}
void ObtenExpendios(LCamposSiscomPro2 **pLCSiscomPro2)
{
char *lchrPtrEdoConexion=0,
     *lchrPtrOperacion=0;
int lintSocketCliente,
    lintNRegistros;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
SiscomConsultaBaseDeDatos("select * from empresas where idempresa < 0",
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  &lchrPtrEdoConexion,
			  &lintSocketCliente,
			  &lintNRegistros,
			  &lchrPtrOperacion,
			  pLCSiscomPro2);
}

void ObtenDatosSistema(const char *pchrPtrSql,
			LCamposSiscomPro2 **pLCSiscomPro2)
{
char *lchrPtrEdoConexion=0,
     *lchrPtrOperacion=0;
int lintSocketCliente,
    lintNRegistros;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
SiscomConsultaBaseDeDatos(pchrPtrSql,
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  &lchrPtrEdoConexion,
			  &lintSocketCliente,
			  &lintNRegistros,
			  &lchrPtrOperacion,
			  pLCSiscomPro2);
}


void ObtenBodegas(LCamposSiscomPro2 **pLCSiscomPro2Dat)
{
	ObtenDatosSistema("select * from bodegas",pLCSiscomPro2Dat);
}
void ObtenTipoPrecios(LCamposSiscomPro2 **pLCSiscomPro2)
{
char *lchrPtrEdoConexion=0,
     *lchrPtrOperacion=0;
int lintSocketCliente,
    lintNRegistros;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
 SiscomConsultaBaseDeDatos("select * from tipoprecio", 
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  &lchrPtrEdoConexion,
			  &lintSocketCliente,
			  &lintNRegistros,
			  &lchrPtrOperacion,
			  pLCSiscomPro2);
}
void ObtenIdPublicoEnGeneral(int *pintPtrIdPublico)
{
char *lchrPtrEdoConexion=0,
     *lchrPtrOperacion=0;
int lintSocketCliente,
    lintNRegistros;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
SiscomConsultaBaseDeDatos("select * from personas where apaterno='GENERAL'",
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  &lchrPtrEdoConexion,
			  &lintSocketCliente,
			  &lintNRegistros,
			  &lchrPtrOperacion,
			  &lLCSiscomPro2Res);
if(lLCSiscomPro2Res)
*pintPtrIdPublico=atoi(SiscomObtenDato(lLCSiscomPro2Res,"idpersona"));

}
void FormaCadenaOperacionSqlProductos(int lintContador,
			     int pintIdPublicoEnGeneral,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     LCamposSiscomPro2 *pLCSiscomPro2TPrecio,
			     LCamposSiscomPro2 *pLCSiscomPro2Expendios,
			     char *pchrPtrCadena,
			     char *pchrPtrCadInsercion,
			     char *pchrPtrExistencia)
{

sprintf(pchrPtrCadena,
		"insert into Productos values('%s','%s',%s,%s);",
		SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		SiscomObtenDato(pLCSiscomPro2,"DscProducto"),
		SiscomObtenDato(pLCSiscomPro2,"IdUnidad"),
		SiscomObtenDato(pLCSiscomPro2,"IdFamilia"));
sprintf(pchrPtrCadInsercion,
	"insert into precios values('%s',%d,0,0,0,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
	pintIdPublicoEnGeneral,
	SiscomObtenDato(pLCSiscomPro2TPrecio,"nmbtipoprecio"));
sprintf(pchrPtrExistencia,
	"insert into existencia values('%s',0,%s);",
	SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Expendios,"idempresa"));

}

void RegistraProductoBodegas(const char *pchrPtrCveProducto,
		     LCamposSiscomPro2 **pLCSiscomPro2Prim,
		     LCamposSiscomPro2 **pLCSiscomPro2Act,
		     int *pintPtrNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2Bodegas=0;
char lchrArrSql[512];
ObtenBodegas(&lLCSiscomPro2Bodegas);
for(;
     lLCSiscomPro2Bodegas ;
     lLCSiscomPro2Bodegas=lLCSiscomPro2Bodegas->SCP2PtrSig)
{
   sprintf(lchrArrSql,
   	   "insert into materialbodega values(%s,'%s',0,0)",
	   SiscomObtenDato(lLCSiscomPro2Bodegas,"idbodega"),
	   pchrPtrCveProducto);
    SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
	 		    pLCSiscomPro2Act,
			    pintPtrNRegistros,
			   "ComandoSQL",
			    lchrArrSql);
}
}

/* Miercoles 16 de Octubre del 2013 
 * Con la sincronizacion de productos a los 
 * expendios, se procedio a sacar de la funcion
 * RegistraProductos, la logica que realiza la 
 * insercion de la informacion y replica los datos
 * a los distintos expendios, con lo que se dejo
 * en la funcion solo la llamada a RegistrandoProductos
 * y la lectura de los datos por el socket.
 */

void RegistrandoProductos(LCamposSiscomPro2 *pLCSiscomPro2,
			  LCamposSiscomPro2 *pLCSiscomPro2Expendios,
			  int pintRegistraEnMatriz,
			  int pintSocket)
{
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0,
		  *lLCSiscomPro2TipoPrecio=0,
		  *lLCSiscomPro2Expendios=0;
LCamposSiscomPro2 *lLCSiscomPro2IniTipoPrecio=0,
		  *lLCSiscomPro2IniExpendios=0;
/* Viernes 11 de Octubre del 2013 
 * Se agrega la sincronizacion de los productos a todos los expendios
 * Siscom Electronica, por lo que es necesario saber cuando la conexion
 * no estuvo disponible en alguno de ellos
 */
LCamposSiscomPro2 *lLCSiscomPro2Productos,
		  *lLCSiscomPro2EdoExpendioPrim=0,
		  *lLCSiscomPro2EdoExpendioAct=0;

char lchrArrActualiza[1204],
	lchrArrCadInsertaPrecios[1024],
	lchrArrCadInsertaExistencia[1024];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador,
	lintIdPublicoEnGeneral;
  lLCSiscomPro2Productos=pLCSiscomPro2;
  ObtenIdPublicoEnGeneral(&lintIdPublicoEnGeneral);
  ObtenTipoPrecios(&lLCSiscomPro2IniTipoPrecio);

/*{************************** Ciclo genera sentencias Sql */
/*
  for(lintContador=0;
  	pLCSiscomPro2;
	pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	sprintf(lchrArrActualiza,
		"insert into productos values('%s','%s',%s,%s);",
		SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		SiscomObtenDato(pLCSiscomPro2,"DscProducto"),
		SiscomObtenDato(pLCSiscomPro2,"IdUnidad"),
		SiscomObtenDato(pLCSiscomPro2,"IdFamilia"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	RegistraProductoBodegas(SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
				&lLCSiscomPro2Ins,
				&lLCSiscomPro2InsAct,
				&lintNRegistros);
    for(lLCSiscomPro2TipoPrecio=lLCSiscomPro2IniTipoPrecio;
    	lLCSiscomPro2TipoPrecio;
	lLCSiscomPro2TipoPrecio=lLCSiscomPro2TipoPrecio->SCP2PtrSig)
    {
    	sprintf(lchrArrCadInsertaPrecios,
		"insert into precios values('%s',%d,0,0,0,'%s');",
		SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		lintIdPublicoEnGeneral,
		SiscomObtenDato(lLCSiscomPro2TipoPrecio,"nmbtipoprecio"));

	SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrCadInsertaPrecios);

     lLCSiscomPro2Expendios=pLCSiscomPro2Expendios;

	{* CDMX A 18 de Febrero del 2021 
	 * Ya no es necesario tener en la base de datos de la matriz
	 * el registro de existencias de los expendios, eso fue en la 
	 * prehistoria del sistema. 
	 * El principal problema que esto esta acarreando es el cuando
	 * se registra un producto nuevo, se inserta una entrada para 
	 * cada expendio, cuando se hace cotizacion de es producto nuevo
	 * el sistema trae de existencias todos los productos 
	 * 
       for(lLCSiscomPro2Expendios=pLCSiscomPro2Expendios;
       	    lLCSiscomPro2Expendios;
	    lLCSiscomPro2Expendios=lLCSiscomPro2Expendios->SCP2PtrSig)
	 *}
      {	
	sprintf(lchrArrCadInsertaExistencia,
		"insert into existencias values('%s',0,%s);",
		SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		SiscomObtenDato(lLCSiscomPro2Expendios,"idempresa"));
	SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrCadInsertaExistencia);

      }
    }
  }
 
*/
/*}************************** Ciclo genera sentencias Sql */
/* 
 * Miercoles 10 de agosto del 2022 
 *
 * El primer semestre completo luego de la pandemia esta por iniciar.
 *
 * Para poder resolver el problema de la insercion de un producto en los
 * expendios , y que se haga con el Id del expendio de manera correcta
 * modifico toda esta parte e integro la funcion 
 *
 * RegistrandoProductoExpendios, que forma las cadenas Sql con el Id del
 * expendio correspondiente
 * 

 GenerandoSqlsRegistroProductos(pLCSiscomPro2,
 		       pLCSiscomPro2Expendios,
		       lLCSiscomPro2IniTipoPrecio,
		       lintIdPublicoEnGeneral,
		       &lintNRegistros,
		       &lLCSiscomPro2Ins,
		       &lLCSiscomPro2InsAct);


       SiscomLog("Registrando los productos");
   	if(pintRegistraEnMatriz)
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	SiscomContenidoProtocolo(lLCSiscomPro2Ins);
	if(lchrPtrEdoConexion)
	SiscomLog("Error Al Enviar:%s",lchrPtrEdoConexion);

  	SiscomLog("Registrando los productos En los expendios");
	* Jueves 8 de agosto del 2019
	 * Se cambia la funcion, porque se modifico el prototipo  
	InsertandoALosExpendios(lintNRegistros,
				lLCSiscomPro2Ins,
				&lLCSiscomPro2EdoExpendioPrim,
				&lLCSiscomPro2EdoExpendioAct);
	 *

InsertandoALosExpendios(lintNRegistros, lLCSiscomPro2Ins,&lLCSiscomPro2EdoExpendioPrim);

ConexionNoDisponibleALosExpendiosProductos(lLCSiscomPro2Productos,lLCSiscomPro2EdoExpendioPrim);

*/



if(RegistrandoProductoExpendios(pLCSiscomPro2,
			     *gLCSiscomPro2Memoria,
			     lLCSiscomPro2IniTipoPrecio,
			     lintIdPublicoEnGeneral,
			     &lLCSiscomPro2EdoExpendioPrim,
			     &lLCSiscomPro2EdoExpendioAct))
{
   SiscomLog("Hay almenos un expendio sin Conexion");
   RespondiendoExpendioSinConexion(pintSocket,lLCSiscomPro2EdoExpendioPrim);
   close(pintSocket);
   ConexionNoDisponibleALosExpendiosProductos(lLCSiscomPro2Productos,
					   lLCSiscomPro2EdoExpendioPrim);
}

}
void RespondiendoExpendioSinConexion(int pintSocket,
				     LCamposSiscomPro2 *pLCSisPro2EdoExpendioPrim)
{
LCamposSiscomPro2 *lLCSiscomPro2PrimReg=0,
		  *lLCSiscomPro2ActReg=0;
int lintNRegistros;
 SiscomAnexaRegistroPro2(&lLCSiscomPro2PrimReg,
  		         &lLCSiscomPro2ActReg,
			&lintNRegistros,
			"EdoConexionExpendio,Descripcion",
			"0",
			"Un Expendio sin conexion");

SiscomEnviaAlServidor(pintSocket,1,"Respuesta",lLCSiscomPro2PrimReg);
}
/* Miercoles 16 de Octubre del 2013 
 * Con la integracion de la sincronizacion de productos
 * a los expendios, y debido a que si no hay conexion al 
 * expendio se debera realizar el proceso despues, se generalizo
 * la funcion RegistraProductos.
 */
/* Jueves 11 de agosto del 2022 CDMX 
 * Despues de a;os , con el problema del registro del producto 
 * con el Id del expendio correcto, hago los cambios necesarios 
 * para ajustar esto
 *
 */
void RegistraProductos(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Expendios=0;
SiscomLeeInformacionProtocolo(pintSocket,pintNRegistros,&lLCSiscomPro2);
ObtenExpendios(&lLCSiscomPro2Expendios);
SiscomContenidoProtocolo(lLCSiscomPro2);
RegistrandoProductos(lLCSiscomPro2,lLCSiscomPro2Expendios,1,pintSocket);
}

void ActualizaExistenciaMinima(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador;
int lintPtoComAD;
char lchrArrDirIpSvrAD[35];
const char *lchrPtrIdExpendio;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);
lchrPtrIdExpendio=SiscomObtenDato(lLCSiscomPro2,"IdExpendio");
ElectronicaComunicacionExpendio2(lchrPtrIdExpendio,
				&lintPtoComAD, 
				lchrArrDirIpSvrAD,
					  0);

  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig
	)

  {
	 sprintf(lchrArrActualiza,
	 	 "update existencias set eximinima=%s  \
		  where CveProducto='%s' and	\
		        idexpendio=%s;",
		  SiscomObtenDato(lLCSiscomPro2,"ExistenciaMinima"),
		  SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		  lchrPtrIdExpendio);

		 		       
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
  }
	SiscomInformacionServidor(lintPtoComAD,
	                          lchrArrDirIpSvrAD,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomLog("Error Al Enviar:%s",lchrPtrEdoConexion);
}
void AgregaRegistroInsercionProductoExpendioNoDisponible(
		LCamposSiscomPro2 *pLCSiscomPro2Expendio,
		LCamposSiscomPro2 *pLCSiscomPro2Producto,
		int *pintPtrNRegistros,
		LCamposSiscomPro2 **pLCSiscomPro2SqlInsPrim,
		LCamposSiscomPro2 **pLCSiscomPro2SqlInsAct)
{
char lchrArrSql[256];
while(pLCSiscomPro2Producto)
{
sprintf(lchrArrSql,
	"insert into ProductoExpendioNoSincronizado values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Expendio,"idempresa"),
	SiscomObtenDato(pLCSiscomPro2Producto,"cveproducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlInsPrim,
			pLCSiscomPro2SqlInsAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
pLCSiscomPro2Producto=pLCSiscomPro2Producto->SCP2PtrSig;
}
}
void ConexionNoDisponibleALosExpendiosProductos(
			LCamposSiscomPro2 *pLCSiscomPro2Prod,
			LCamposSiscomPro2 *pLCSiscomPro2EdoExpendioPrim)
{
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim=0,
		  *lLCSiscomPro2SqlAct=0;
int lintNRegistros=0;
int lintSocketAD;
char *lchrPtrEdoConexion;
if(pLCSiscomPro2EdoExpendioPrim)
{
while(pLCSiscomPro2EdoExpendioPrim)
{
AgregaRegistroInsercionProductoExpendioNoDisponible(
		pLCSiscomPro2EdoExpendioPrim,
		pLCSiscomPro2Prod,
		&lintNRegistros,
		&lLCSiscomPro2SqlPrim,
		&lLCSiscomPro2SqlAct);
pLCSiscomPro2EdoExpendioPrim=pLCSiscomPro2EdoExpendioPrim->SCP2PtrSig;
}
}
SiscomContenidoProtocolo(lLCSiscomPro2SqlPrim);
SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			"Inserciones",
			lintNRegistros,
			lLCSiscomPro2SqlPrim,
			&lchrPtrEdoConexion,
			&lintSocketAD);
}




int EsConsultaCodigoCapacitores(char **pchrPtrEntrada)
{
char lchrArrComando[128];
strcpy(lchrArrComando,*(pchrPtrEntrada+1));
SiscomCambiaMayusculas(lchrArrComando);
return !strncmp("CAP ",lchrArrComando,4);
}

/* Queretaro Lunes 21 abril del 2014
 * Con estas funciones se facilitara la seleccion de capacitores
 * ya que se podra capturar en la ventana de cotizacion de dispositivos
 * CAP valor 6.8n y el sistema debera regresar los capacitores que 
 *   tenemos que sean en este caso de 0.0068mfd cerarmicos.
 * Tambien se podra utilizar la sintaxis
 * siguiente
 * CAP codigo 682k y me regresara de igual forma los capacitores que 
 * tenemos registros para ese codigo.
 */

void FormaConsultaCodigoCapacitores(char **pchrPtrEntrada,
				    SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrSql[2048];
SiscomLog("Buscando capacitores por codigo de entrada:(%s) Expendio(%s)",
	   *(pchrPtrEntrada+1),
	   *(pchrPtrEntrada+4));
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
ManejoCapacitores(pchrPtrEntrada,lchrArrSql);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrSql);
SiscomLog("%s",lchrArrSql);
}
