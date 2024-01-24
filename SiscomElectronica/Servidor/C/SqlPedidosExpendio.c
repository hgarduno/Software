#include <SqlPedidosExpendio.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include <stdio.h>

int SqlTransfiereBodegaExpendioParaPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateMaterialBodegaParaPedido);
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertIntoBodegaAExpendioParaPedido);
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateFromExistenciasParaPedido);
SiscomEnviaRegistrosAlServidorBD("SqlIniciaPedidoExpendio",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}


int SqlActualizaInventarioParaPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertIntoDesajusteInventarioParaPedido);
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertIntoInventarioParaPedido);
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateFromExistenciasParaPedido);
SiscomEnviaRegistrosAlServidorBD("SqlIniciaPedidoExpendio",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}
int SqlPedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSqlPedidoExpendioHoy[512],
	lchrArrSqlDetallePedidoExpendio[512];

SqlConsultaPedidoExpendioHoy(pSiscomOpePtrDato,lchrArrSqlPedidoExpendioHoy);
SqlConsultaDetallePedidoExpendioHoy(pSiscomOpePtrDato,lchrArrSqlDetallePedidoExpendio);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PedidoExpendio%DetallePedidoExpendio%",
		   lchrArrSqlPedidoExpendioHoy,
		   lchrArrSqlDetallePedidoExpendio);
}
int SqlServidoresSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
sprintf(lchrArrSql,
	"								\n\
select idempresa as idmaquina,						\n\
	diripsvrad as dirip,						\n\
	b.puerto,							\n\
	basedatos,							\n\
	'Servidor' as tipoequipo					\n\
from expendios as a inner join 						\n\
     servidoressiscom4 as b using(idempresa) 				\n\
where idempresa != (select idempresa from matriz)			\n\
union 									\n\
select idempresa as idmaquina,						\n\
	diripsvrad as dirip,						\n\
	b.puerto,							\n\
	basedatos,							\n\
	'Matriz' as tipoequipo						\n\
from matriz as a inner join 						\n\
	servidoressiscom4 as b using(idempresa) inner join 		\n\
	expendios as c using(idempresa)					\n\
order by idmaquina");
	


SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "Servidores%",
			      lchrArrSql);

}
int SqlExistenciaExpendioBodegaProducto(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];

sprintf(lchrArrSql,
	"select *				\n\
	 from existenciaexpendiobodegas		\n\
	 where cveproducto='%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","CveProducto",pSisOpePtrDato));

SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
					"SqlExistenciaExpendioBodegaProducto",
					lchrArrBuffer,
					pSisOpePtrDato);

}
void SqlConsultaPedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato,
				  char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"select *			\n\
	 from pedidosmaterial 		\n\
	 where idexpendio=%s and 	\n\
	 	fecha::date='%s'",
SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato));
}

void SqlConsultaDetallePedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato,
					 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select a.*,						\n\
		case when b.estado is null then 		\n\
		        'Sin Enviar' 				\n\
			else					\n\
			'Enviado'				\n\
		end as estado					\n\
	from detallepedidomaterial as a left outer join		 \n\
	     EstadoPedidoExpendioProducto as b using(idProducto) \n\
	where a.idpedido in(select idpedido			 \n\
			  from pedidosmaterial			 \n\
			  where idexpendio=%s and 		 \n\
			        fecha::date='%s')",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato));
}
int SqlIniciandoPedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
        lchrArrSql[128];
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     InsertToPedidosMaterial);

SiscomEnviaRegistrosAlServidorBD("SqlIniciaPedidoExpendio",lchrArrBuffer,pSiscomOpePtrDato);
}
int SqlEliminaProductoPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
        lchrArrSql[128];
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     DeleteFromDetallePedidoMaterial);

SiscomEnviaRegistrosAlServidorBD("SqlIniciaPedidoExpendio",lchrArrBuffer,pSiscomOpePtrDato);
}
int SqlActualizaProductoPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
        lchrArrSql[512];
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     UpdateFromDetallePedidoMaterial);

SiscomEnviaRegistrosAlServidorBD("SqlIniciaPedidoExpendio",lchrArrBuffer,pSiscomOpePtrDato);
}
int SqlActualizaObservacionesPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
        lchrArrSql[512];
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     UpdateFromPedidosMaterialObservaciones);

SiscomEnviaRegistrosAlServidorBD("SqlIniciaPedidoExpendio",lchrArrBuffer,pSiscomOpePtrDato);
}

int SqlProductoAPedidoExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
        lchrArrSql[1024];
SiscomAgregaSentenciasSqlDelAsociado("SqlIniciaPedidoExpendio",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     InsertToDetallePedidoMaterial);
SiscomEnviaRegistrosAlServidorBD("SqlIniciaPedidoExpendio",lchrArrBuffer,pSiscomOpePtrDato);
}
int SqlEstadoPedidoExpendioProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomEnviaRegistrosAlServidorBD("SqlEstadoPedidoExpendioProducto",lchrArrBuffer,pSiscomOpePtrDato);
}
int SqlRegistraPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
        lchrArrSql[1024];

SiscomAgregaSentenciasSqlCampoAsociado("SqlPedidoExpendioAMatriz",
                                     "Envio",
				     "Pedido",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     InsertToPedidosMaterialAMatriz);
SiscomAgregaSentenciasSqlCampoAsociado("SqlPedidoExpendioAMatriz",
                                     "Envio",
				     "Productos",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     InsertToDetallePedidoMaterialAMatriz);
SiscomAgregaSentenciasSqlCampoAsociado("SqlPedidoExpendioAMatriz",
                                     "Envio",
				     "Pedido",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     InsertToUltimoEstadoPedidoMatriz);

SiscomAgregaSentenciasSqlCampoAsociado("SqlEstadoPedidoExpendioProducto",
                                     "Envio",
				     "Productos",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     InsertToEstadoPedidoExpendioProducto);


}
int SqlEnviaPedidoMatriz(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
 SiscomReplicaMaquinasSistema("Matriz",
 			     "SqlPedidoExpendioAMatriz",
			     lchrArrBuffer,
			     pSiscomOpePtrDato->SiscomRegProLPtrPrimRes,
			     0,
			     pSiscomOpePtrDato);

}
void InsertToPedidosMaterial(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
        "insert into PedidosMaterial values(%s,'%s','',%s);",
        SiscomObtenCampoRegistroProLChar("IdPedido",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("IdExpendio",pSiscomRegProLPtrDato));
}

void InsertToPedidosMaterialAMatriz(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
        "insert into PedidosMaterial values(%s,'%s','%s',%s);",
        SiscomObtenCampoRegistroProLChar("idpedido",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("fecha",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("observaciones",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("idexpendio",pSiscomRegProLPtrDato));
}
void InsertToUltimoEstadoPedidoMatriz(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
        "insert into UltimoEstadoPedido values(%s,0);",
        SiscomObtenCampoRegistroProLChar("idpedido",pSiscomRegProLPtrDato));
}

void InsertToDetallePedidoMaterial(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
const char *lchrPtrObsProducto;

lchrPtrObsProducto=SiscomObtenCampoRegistroProLChar("ObsProducto",pSiscomRegProLPtrDato);
lchrPtrObsProducto=lchrPtrObsProducto ? lchrPtrObsProducto : "" ;
sprintf(pchrPtrSql,
        "insert into DetallePedidoMaterial values(%s,%s,'%s','%s',%s,%s);",
        SiscomObtenCampoRegistroProLChar("IdPedido",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
	lchrPtrObsProducto,
	"0",
        SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrDato));
LogSiscom("%s",pchrPtrSql);
}

void InsertToDetallePedidoMaterialAMatriz(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
const char *lchrPtrObsProducto;
*pchrPtrSql=0;
if(!SiscomComparaCadenaCampoRegistroProL("Sin Enviar","estado",pSiscomRegProLPtrDato))
{
lchrPtrObsProducto=SiscomObtenCampoRegistroProLChar("observacion",pSiscomRegProLPtrDato);
lchrPtrObsProducto=lchrPtrObsProducto ? lchrPtrObsProducto : "" ;
sprintf(pchrPtrSql,
        "insert into DetallePedidoMaterial values(%s,%s,'%s','%s',%s,%s);",
        SiscomObtenCampoRegistroProLChar("idpedido",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato),
	lchrPtrObsProducto,
	"0",
        SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrDato));
}
}
void InsertToEstadoPedidoExpendioProducto(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
*pchrPtrSql=0;
if(!SiscomComparaCadenaCampoRegistroProL("Sin Enviar","estado",pSiscomRegProLPtrDato))
{
sprintf(pchrPtrSql,
        "insert into EstadoPedidoExpendioProducto values(%s,%s,1);",
        SiscomObtenCampoRegistroProLChar("idpedido",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrDato));
}
}

void InsertIntoDesajusteInventarioParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
char lchrArrSqlExistencia[256];
sprintf(lchrArrSqlExistencia,
	"select existencia			\n\
	 from existencias			\n\
	 where cveproducto='%s' and 		\n\
	       idexpendio=%s",
	  SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato),
	  SiscomObtenCampoRegistroProLChar("IdExpendio",pSiscomRegProLPtrDato));
sprintf(pchrPtrSql,
	"insert into DesajusteInventario values('%s',%s,(%s),%s,'%s','19:22:45');",
	SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	lchrArrSqlExistencia,
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrDato));
}

void InsertIntoInventarioParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into inventario values('%s',%s,1180535225,%s,'%s','19:22:45');",
	SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdExpendio",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrDato));


}

void InsertIntoBodegaAExpendioParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into BodegaAExpendio values(0,%s,'%s',%s,%s,'%s');",
	  SiscomObtenCampoRegistroProLChar("IdExpendio",pSiscomRegProLPtrDato),
	  SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrDato),
	  SiscomObtenCampoRegistroProLChar("IdEmpleado",pSiscomRegProLPtrDato),
	  SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	  SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato));
}
void DeleteFromDetallePedidoMaterial(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"delete from DetallePedidoMaterial where idpedido=%s and idproducto=%s",
        SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("IdPedido",pSiscomRegProLPtrDato));
}

void UpdateFromDetallePedidoMaterial(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"update DetallePedidoMaterial 		\n\
	set cantidad=%s,observacion='%s'	\n\
	where idpedido=%s and idproducto=%s;",
        SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("ObsProducto",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("IdPedido",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrDato));
}

void UpdateFromPedidosMaterialObservaciones(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update pedidosmaterial set observaciones='%s' where  idpedido=%s;",
	SiscomObtenCampoRegistroProLChar("Observaciones",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdPedido",pSiscomRegProLPtrDato));
}

void UpdateFromExistenciasParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update existencias set Existencia=Existencia+%s where CveProducto='%s' and idExpendio=%s;",
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("IdExpendio",pSiscomRegProLPtrDato));
}

void UpdateMaterialBodegaParaPedido(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update MaterialBodega set existencia=existencia-%s where idbodega=0 and CveProducto='%s';",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato));
}
