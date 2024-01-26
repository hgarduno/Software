#include <SqlTransferencias.h>
#include <SqlDirecciones.h>
#include <SqlInventario.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SqlRegistraTransferencia(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomAgregaArgumentoInsercionSql("SqlInsertaTransferencia",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaTransferencia",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToTransferencias);

if(!SiscomCampoAsociadoEntradaOperacionInt("Envio","IdTipoTransferencia",pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaTransferencia",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToTransporteTransferencias);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaTransferencia",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToEstadoTransferencias);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaTransferencia",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToObservacionTransferencias);

SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaTransferencia",
					"Envio",
					"Productos",
					lchrArrBuffer,
					lchrArrSql,
					pSiscomOpePtrDat,
					InsertToDetalleTransferencia);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaTransferencia",
					"Envio",
					"Productos",
					lchrArrBuffer,
					lchrArrSql,
					pSiscomOpePtrDat,
					InsertToObservacionProductos);
if(SiscomCampoAsociadoEntradaOperacionInt("Envio","IdTipoTransferencia",pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaTransferencia",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToTransferenciaPiso);
SiscomReplicaMaquinaLocal("SqlInsertaTransferencia", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlConsultaTransferencias(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
    lchrArrSql[1024];
sprintf(lchrArrSql,
"                               					\n\
select t.*, 								\n\
	et.idestado,							\n\
	a.idtransferencia as transferenciaapiso				\n\
from transferencias as t inner join     				\n\
estadotransferencia as et using(idtransferencia) left outer join	\n\
transferenciapiso as a using(idtransferencia)				\n\
where et.idestado=1");
LogSiscom("El tamano %d",strlen(lchrArrSql));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "Transferencias%",
                 lchrArrSql);

}
int SqlCostoPrecioTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[2048],
    *lchrPtrSql,
    *lchrPtrCondicion;
FormaCondicionConsultaPrecioCosto(pSiscomOpePtrDato,&lchrPtrCondicion);
lchrPtrSql=(char *)malloc(strlen(lchrPtrCondicion)+512);
sprintf(lchrPtrSql,
"                               						\n\
select  a.idproducto,								\n\
	b.idprecio,								\n\
	d.preciogeneral,							\n\
	e.idcostobruto,								\n\
	e.costobruto								\n\
from  	productos as a  inner join 						\n\
	ultimopreciogeneral as b  using(idproducto) inner join			\n\
	ultimocosto as c using(idproducto) inner join				\n\
	preciogeneral as d on d.idpreciogeneral=b.idprecio inner join		\n\
	costobruto as e on e.idcostobruto=c.idcosto				\n\
  %s",
  lchrPtrCondicion);

LogSiscom("%s",lchrPtrSql);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDato,
                 "SqlCostoPrecioTransferencia%",
                 lchrPtrSql);
}


int SqlConsultaInformacionTransferencia(SiscomOperaciones *pSiscomOpePtrDat)
{
    char lchrArrSqlDetalleTransferencia[1024],
         lchrArrSqlProductosTransferencia[1024],
         lchrArrBuffer[1024];
    SqlDetalleTransferencia(pSiscomOpePtrDat,lchrArrSqlDetalleTransferencia);
    SqlProductosTransferencia(pSiscomOpePtrDat,lchrArrSqlProductosTransferencia);
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "DetalleTransferencia%ProductosTransferencia%",
                  lchrArrSqlDetalleTransferencia,
                  lchrArrSqlProductosTransferencia);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"DetalleTransferencia",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"ProductosTransferencia",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
}

int SqlTransferenciasEnviadas(SiscomOperaciones *pSiscomOpePtrDat)
{
    char lchrArrSqlTransferenciasEnviadas[1024],
         lchrArrBuffer[1024];
    sprintf(lchrArrSqlTransferenciasEnviadas,
    	"									\n\
select a.idtransferencia,							\n\
	a.fechahora::date,							\n\
	b.nombre as tienda,							\n\
	c.nombre || ' ' || c.apaterno as almacenista,				\n\
	d.*,									\n\
	e.*,									\n\
	f.nombre as camion,							\n\
	g.nombre || ' ' || g.apaterno as chofer					\n\
from transferencias as a  inner join						\n\
	tiendas as b using(idtienda) inner join					\n\
	personas as c on c.idpersona=a.idalmacenista inner join			\n\
	estadotransferencia as d using(idtransferencia) inner join		\n\
	transportetransferencia as e using(idtransferencia) inner join		\n\
	camiones as f using(idcamion) inner join 				\n\
	personas as g on e.idchofer=g.idpersona");
	
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "Transferencias%",
                  lchrArrSqlTransferenciasEnviadas);
SiscomRegistrosAsociadosLog(lchrArrBuffer,
			    "Transferencias",
			    pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
}

int SqlConsultaDetalleTransferencia(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrSqlTransferenciasEnviadas[1024],
         lchrArrBuffer[1024];
    sprintf(lchrArrSqlTransferenciasEnviadas,
    	"							\n\
select *							\n\
from detalletransferencia as a inner join			\n\
	productos as b  using(idproducto) inner join 		\n\
	productoproveedor as c using(idproducto) inner join 	\n\
	productocodigobarras as d using(idproducto) inner join	\n\
	empresas as e using(idempresa)				\n\
where idtransferencia=%s",
SiscomCampoAsociadoEntradaOperacion("Envio", "idtransferencia", pSiscomOpePtrDat));

	
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "Transferencias%",
                  lchrArrSqlTransferenciasEnviadas);
SiscomRegistrosAsociadosLog(lchrArrBuffer,
			    "Transferencias",
			    pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);

}
int SqlDetalleTransferencia(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
if(!SeTransfiereAPiso(pSiscomOpePtrDat))
sprintf(pchrPtrSql,
    "select 	t.*,                    						\n\
     		tr.*, 									\n\
     		ti.nombre as tienda, 							\n\
     		al.nombre as almacenista,						\n\
     		ch.nombre as chofer, 							\n\
     		ca.nombre as camion, 							\n\
     		ca.placas, 								\n\
     		ot.*   									\n\
     from  transferencias as t inner join    						\n\
     	   tiendas as ti using(idtienda) inner join   					\n\
           transportetransferencia as tr using(idtransferencia) inner join    		\n\
           camiones as ca using(idcamion) inner join      				\n\
           personas al on(al.idpersona = idalmacenista) inner join       		\n\
           personas ch on(ch.idpersona = idchofer) inner join         			\n\
           observaciontransferencia as ot using(idtransferencia) inner join      	\n\
           estadotransferencia as est using(idtransferencia)      			\n\
     where idtransferencia='%s'",
           SiscomCampoAsociadoEntradaOperacion("Envio", "idtransferencia", pSiscomOpePtrDat));
   else
   sprintf(pchrPtrSql,
	   "select a.*,										\n\
			b.*,									\n\
			c.nombre as tienda,							\n\
			'' as almacenista,							\n\
			'' as chofer,								\n\
			'' as camion,								\n\
			d.*,									\n\
			e.*									\n\
		from transferencias as a left outer join 					\n\
     			personas as b on a.idalmacenista=b.idpersona inner join 		\n\
     			tiendas as c using(idtienda) inner join					\n\
     			observaciontransferencia as d using(idtransferencia) inner join		\n\
     			estadotransferencia as e using(idtransferencia)				\n\
		where idtransferencia=%s",
           SiscomCampoAsociadoEntradaOperacion("Envio", "idtransferencia", pSiscomOpePtrDat));
    LogSiscom("SqlConsulta: %s",pchrPtrSql);
}

int SqlProductosTransferencia(SiscomOperaciones *pSiscomOpePtrDat,
            char *pchrPtrSql)
{
sprintf(pchrPtrSql,
    "select *, case when esstock=1 then					\n\
    		    'Si'						\n\
		    else						\n\
		    'No' 						\n\
		 end as Stock						\n\
     from productos as a  inner join                  			\n\
          productocodigobarras as b using(idproducto) inner join     	\n\
     detalletransferencia as c using(idproducto) left outer join	\n\
     observacionproductos as d on c.idproducto=d.idproducto and 	\n\
     				  d.idtransferencia=c.idtransferencia	\n\
     where c.idtransferencia='%s'",
    SiscomCampoAsociadoEntradaOperacion("Envio",
                            "idtransferencia",
                        pSiscomOpePtrDat));

    LogSiscom("SqlConsulta %s",pchrPtrSql);
}

int SqlActualizaEstadoTransferencia(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];

SiscomAgregaArgumentoInsercionSql("SqlActualizaTransferencia",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
    
SiscomAgregaSentenciasSqlDelAsociado("SqlActualizaTransferencia",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateToEstado);
SiscomReplicaMaquinaLocal("SqlActualizaTransferencia", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlRecibeTransferencia(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024],
    lchrArrSqlProductosTransferencia[1024];
SiscomAgregaArgumentoInsercionSql("SqlRecibeTransferencia",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlRecibeTransferencia",
					"Envio",
					"ProductosTransferencia",
					lchrArrBuffer,
					lchrArrSql,
					pSiscomOpePtrDat,
					UpdateToExistenciaSuma);
SiscomAgregaSentenciasSqlCampoAsociado("SqlRecibeTransferencia",
					"Envio",
					"ProductosTransferencia",
					lchrArrBuffer,
					lchrArrSql,
					pSiscomOpePtrDat,
					InsertToProductoStock);

SiscomAgregaSentenciasSqlCampoAsociado("SqlRecibeTransferencia",
					"Envio",
					"DetalleTransferencia",
					lchrArrBuffer,
					lchrArrSql,
					pSiscomOpePtrDat,
					UpdateToEstado2);
SiscomReplicaMaquinaLocal("SqlRecibeTransferencia", lchrArrBuffer, 0, pSiscomOpePtrDat); 
}
int SqlActualizaAlmacenCentral(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512],
    lchrArrSqlProductosTransferencia[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlActualizaAlmacen",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlActualizaAlmacen",
					"Envio",
					"ProductosTransferencia",
					lchrArrBuffer,
					lchrArrSql,
					pSiscomOpePtrDat,
					UpdateToExistenciaAlmacen2);
SiscomReplicaMaquinaSistema("5",
			    "SqlActualizaAlmacen",
			    lchrArrBuffer,
			    gSiscomRegProLPtrMemoria,
			    0,
			    pSiscomOpePtrDat);
}
void InsertToTransferenciaPiso(SiscomOperaciones *pSiscomOpePtrDatos,
				SiscomRegistroProL *pSiscomRegProLPtrEnt,
				char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into TransferenciaPiso values(%s);",
	 SiscomObtenCampoRegistroProLChar("IdTransferencia",pSiscomRegProLPtrEnt));
}
void InsertToTransferencias(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
if(!SiscomCampoAsociadoEntradaOperacionInt("Envio","IdTipoTransferencia",pSiscomOpePtrDatos))
sprintf(pchrPtrSql,
	"insert into Transferencias values(%s,%s,%s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdTransferencia",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdTienda",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdAlmacenista",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
else
sprintf(pchrPtrSql,
	"insert into Transferencias values(%s,%s,%s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdTransferencia",pSiscomRegProLPtrEnt),
	 "5",
	 SiscomObtenCampoRegistroProLChar("IdAlmacenista",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));

}

void InsertToTransporteTransferencias(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into TransporteTransferencia values(%s,%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdTransferencia",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdChofer",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdCamion",pSiscomRegProLPtrEnt));
}

void InsertToEstadoTransferencias(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into EstadoTransferencia values(%s,%s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdTransferencia",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
}

void InsertToObservacionTransferencias(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ObservacionTransferencia values(%s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdTransferencia",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("ObservacionGeneral",pSiscomRegProLPtrEnt));
}

void InsertToDetalleTransferencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      	  SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      	  char *pchrPtrSql)
{
char lchrArrBuffer[128];
sprintf(pchrPtrSql,
	"insert into DetalleTransferencia values(%s,%s,%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdTransferencia",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Stock",pSiscomRegProLPtrEnt));
}

void InsertToObservacionProductos(SiscomOperaciones *pSiscomOpePtrDatos,
		      	  SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      	  char *pchrPtrSql)
{
char lchrArrBuffer[128];
const char *lchrPtrObservacion;
if((lchrPtrObservacion=SiscomObtenCampoRegistroProLChar("Observacion",pSiscomRegProLPtrEnt)))
sprintf(pchrPtrSql,
	"insert into ObservacionProductos values(%s,%s,'%s');",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdTransferencia",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	lchrPtrObservacion);
else
*pchrPtrSql=0;

}

void InsertToComentarioDetalleTransferencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      	  SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      	  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleTransferencia values(%s,%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdTransferencia",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrEnt));
}

void InsertToEstadoTransferencia(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql)
{
    sprintf(pchrPtrSql,
    "insert into Transferencias values(%s,%s,'%s');",
     SiscomObtenCampoRegistroProLChar("IdTransferencia",pSiscomRegProLPtrEnt),
     SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrEnt),
     SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
}

void UpdateToEstado(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql)
{
sprintf(pchrPtrSql,
    "update estadotransferencia set idestado=%s where idtransferencia=%s;",
     SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrEnt),
     SiscomObtenCampoRegistroProLChar("IdTransferencia",pSiscomRegProLPtrEnt));
}
void UpdateToEstado2(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql)
{
sprintf(pchrPtrSql,
    "update estadotransferencia set idestado=%s where idtransferencia=%s;",
    SiscomCampoAsociadoEntradaOperacion("Envio","IdEstado",pSiscomOpePtrDatos),
     SiscomObtenCampoRegistroProLChar("idtransferencia",pSiscomRegProLPtrEnt));
}

void UpdateToExistenciaSuma(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql)
{
sprintf(pchrPtrSql,
    "update Existencia set Existencia=(Existencia+%s) where idproducto=%s;",
     SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrEnt),
     SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
 LogSiscom("%s",pchrPtrSql);
}
void InsertToProductoStock(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql)
{
if(!SiscomComparaCadenaCampoRegistroProL("1","esstock",pSiscomRegProLPtrEnt))
sprintf(pchrPtrSql,
	"insert into productostock values(%s);",
     	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
else
*pchrPtrSql=0;

}

