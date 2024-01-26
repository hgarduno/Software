#include <SqlCatalogos.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>
#include <string.h>

int SqlTiposFolio(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "TiposFolio%",
			      "select * from tiposfolio");
SiscomRegistrosAsociadosLog(lchrArrBuffer,"TiposFolio",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}


int SqlFrecuenciaTransaccional(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "FrecuenciaTransaccional%",
			      "select * from frecuenciatransaccional");
SiscomRegistrosAsociadosLog(lchrArrBuffer,"FrecuenciaTransaccional",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}

int SqlFrecuenciaPagos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "FrecuenciaPagos%",
			      "select * from frecuenciapagos");
SiscomRegistrosAsociadosLog(lchrArrBuffer,"FrecuenciaPagos",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}
int SqlTipoVivienda(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "TipoVivienda%",
			      "select * from tipoviviendas");
SiscomRegistrosAsociadosLog(lchrArrBuffer,"TipoVivienda",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}


int SqlConceptosExistencias(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "ConceptosExistencias%",
			      "select * from conceptosexistencias");
SiscomRegistrosAsociadosLog(lchrArrBuffer,"ConceptosExistencias",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}


int SqlTiendasEntrega(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "TiendasEntrega%",
			      "select * from tiendas");
}

int SqlVendedores(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
const char *pchrArrTipoPersona;
pchrArrTipoPersona=SiscomCampoAsociadoEntradaOperacion("Envio",
                "TipoPersona",
                pSiscomOpePtrDat);
if(strcmp(pchrArrTipoPersona,"Vendedores")==0)
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Vendedores%",
			      "select vendedores.*, 						\n\
			      	      personas.* 						\n\
			       from personas,vendedores						\n\
			       WHERE personas.idpersona=vendedores.idvendedor");
else if(strcmp(pchrArrTipoPersona,"Choferes")==0)
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "Vendedores%",
                  "select choferes.*,                         \n\
                          personas.*                        \n\
                   from personas,choferes                     \n\
                   WHERE personas.idpersona=choferes.idchofer");
else if(strcmp(pchrArrTipoPersona,"Almacenistas")==0)
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "Vendedores%",
                  "select almacenistas.*,                         \n\
                          personas.*                        \n\
                   from personas,almacenistas                     \n\
                   WHERE personas.idpersona=almacenistas.idalmacenista");
}

int SqlPerfiles(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Perfiles%",
			     "select * from tipospersona;");
}



int SqlPlazos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Plazos%",
			      "select * from Plazos");
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Plazos",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}

int SqlCamiones(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Camiones%",
			      "select * from Camiones");
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Camiones",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}

int SqlProveedores(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Proveedores%",
			      "select * 			\n\
			       from proveedores inner join 	\n\
			            empresas using(idempresa);");
}

int SqlProductos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"select * 						\n\
	 from productos inner join 				\n\
	      productoproveedor using(idproducto) inner join	\n\
	      productocodigobarras using(idproducto) inner join	\n\
	      estatusproducto using(idproducto)			\n\
	 where productoproveedor.idempresa=%s and 		\n\
	       idestatus in(1,3)				\n\
	 order by numproducto",
	SiscomCampoAsociadoEntradaOperacion("Envio",
			       		    "IdProveedor",
					    pSiscomOpePtrDat));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Productos%",
			     lchrArrSql);
}

int SqlProductosCodigoBarras(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"select * 							\n\
	 from productos	inner join 					\n\
	      productoproveedor using(idproducto) left outer join 	\n\
	      productocodigobarras using(idproducto)			\n\
	 where productoproveedor.idempresa=%s 				\n\
	 order by nombreproducto",
	SiscomCampoAsociadoEntradaOperacion("Envio",
			       		    "IdProveedor",
					    pSiscomOpePtrDat));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Productos%",
			     lchrArrSql);
}

int SqlProductoCodigoBarras(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"select * 							\n\
	 from productos	inner join 					\n\
	      productocodigobarras using(idproducto)			\n\
	 where codigobarras='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio",
			       		    "CodigoBarras",
					    pSiscomOpePtrDat));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Productos%",
			     lchrArrSql);
}
int SqlProductoProveedor(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
"							\n\
select * 						\n\
from productos inner join 				\n\
     productoproveedor using(idproducto) inner join	\n\
     productocodigobarras using(idproducto) 		\n\
where productoproveedor.idempresa=%s and  		\n\
	numproducto=%s",
SiscomCampoAsociadoEntradaOperacion("Envio",
			       	    "IdEmpresa",
				     pSiscomOpePtrDat),
SiscomCampoAsociadoEntradaOperacion("Envio",
			       	    "NumProducto",
				     pSiscomOpePtrDat));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Productos%",
			     lchrArrSql);
}

int SqlProductosCodigoBarrasFechaCompra(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
"select *						\n\
from productos left outer join				\n\
	productocodigobarras using(idproducto)		\n\
where idproducto in(					\n\
select idproducto 					\n\
from  compras inner join 				\n\
	detallecompras using(idcompra)			\n\
where fecha='%s')					\n\
	 order by nombreproducto",
	SiscomCampoAsociadoEntradaOperacion("Envio",
			       		    "FechaCompra",
					    pSiscomOpePtrDat));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Productos%",
			     lchrArrSql);
}

int SqlProductosCodigoBarrasTodos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
"								\n\
select *							\n\
from productos inner join 					\n\
     estatusproducto as b  using(idproducto) left outer join	\n\
     productocodigobarras using(idproducto)			\n\
where b.idestatus in (1,3) order by nombreproducto");

SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Productos%",
			     lchrArrSql);
}

int SqlDepartamentos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Departamentos%",
			      "select * 			\n\
			       from departamentos");

}

int SqlTipoDocumentos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "TipoDocumentos%",
			      "select * from tipodocumentos");
}

int SqlEstados(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Estados%",
			      "select * from estados");
}

int SqlFormasEntrega(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "FormasEntrega%",
			      "select * from formasentrega");
}


int SqlTipoVentas(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "TipoVentas%",
			      "select * from tipoventas");
}

int SqlFinanciadoras(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Financiadoras%",
			      "select * from financiadoras");
}
