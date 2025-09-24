#include <SqlPedidoMaterial.h>

void SqlExistenciaExpendio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select * 				\n\
	 from existenciaexpendiobodegas 	\n\
	 where cveproducto='%s' and 		\n\
	       IdExpendio='%s'",
	 SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom),
	 SiscomCampoDatosEntrada("IdExpendio",pSAgsSiscom));
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseAsignaArgumento("SqlPedidoMaterial",
				   lchrArrSql,
				   pSAgsSiscom);
}
void SqlPedidosExpendios(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"									\n\
	select a.*,								\n\
		b.razonsocial,							\n\
		d.*								\n\
	from pedidosmaterial as a inner join					\n\
     		empresas as b on a.idexpendio=b.idempresa  inner join		\n\
     		ultimoestadopedido as c using(idpedido) inner join		\n\
     		estadopedidomaterial as d using(idestado)			\n\
	 where fecha::date>='%s' and fecha::date<='%s'				\n\
	order by fecha desc,a.idexpendio",
	SiscomCampoSubRegistroPrincipalArgs("FechaInicio",pSAgsSiscom),
	SiscomCampoSubRegistroPrincipalArgs("FechaFin",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlPedidosExpendios",
				   lchrArrSql,
				   pSAgsSiscom);
SiscomLog("Consultando el servidor (%s:%d)",
	pSAgsSiscom->chrArrDirIpAD,
	pSAgsSiscom->intPtoComAD);
SiscomLog("%s",lchrArrSql);
}

void SqlDetallePedidoExpendio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select a.*,b.existencia,b.exbodegas 					\n\
	 from detallepedidomaterial  as a inner join				\n\
	      existenciaexpendiobodegas as b  using(cveproducto) inner join	\n\
	      matriz as c on b.idexpendio=c.idempresa				\n\
	      where idpedido in(select idpedido 				\n\
	      			from pedidosmaterial				\n\
				where fecha::date>='%s' and fecha::date<='%s')	\n\
	 order by idpedido,cveproducto",
	SiscomCampoSubRegistroPrincipalArgs("FechaInicio",pSAgsSiscom),
	SiscomCampoSubRegistroPrincipalArgs("FechaFin",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlDetallePedidoExpendio",
				   lchrArrSql,
				   pSAgsSiscom);
}

void SqlImprimePedido(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
SiscomLog("-----");
/*
sprintf(lchrArrSql,
	"select a.idexpendio,					\n\
		b.*,						\n\
		c.razonsocial					\n\
	 from pedidosmaterial as a inner join 			\n\
	 detallepedidomaterial as b using(idpedido) inner join	\n\
	 empresas as c on a.idexpendio=c.idempresa		\n\
	 where idpedido=%s					\n\
	 order by idpedido,cveproducto",
	SiscomCampoDatosEntrada("IdPedido",pSAgsSiscom));

*/
sprintf(lchrArrSql,
	"								\n\
select a.idexpendio,							\n\
       b.*,								\n\
        c.razonsocial,							\n\
	d.existencia,							\n\
	d.exbodegas,							\n\
	f.estante,							\n\
	g.caja								\n\
from pedidosmaterial as a inner join 					\n\
     detallepedidomaterial as b using(idpedido) inner join		\n\
     empresas as c on a.idexpendio=c.idempresa left outer join 		\n\
     existenciaexpendiobodegas as d using(cveproducto) left outer join 	\n\
     ubicacionproducto as e using(cveproducto) left outer join		\n\
     estante as f using(idestante) left outer join 			\n\
     cajamaterial as g using(idcaja)					\n\
where idpedido=%s							\n\
order by idpedido,cveproducto",
SiscomCampoDatosEntrada("IdPedido",pSAgsSiscom));

SiscomConsultaBaseAsignaArgumento("SqlImprimePedido",
				   lchrArrSql,
				   pSAgsSiscom);

}

void SqlRegistraRecibePedido(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[512];
SiscomInsercionActualizacionSubRegistros(0,
					 pSAgsSiscom,
					 "SqlRecibePedido",
					 lchrArrBuffer,
					 SqlUpdateDetallePedidoMaterial);
}

void SqlActualizaExistenciasPorEntregaPedido(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[512];
SiscomInsercionActualizacionSubRegistros(0,
					 pSAgsSiscom,
					 "SqlRecibePedido",
					 lchrArrBuffer,
					 SqlUpdateExistenciasPorEntregaMaterial);
}
void SqlPedidosPendientesPorEnviarAMatriz(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"						\n\
	 select * 					\n\
	 from pedidosmaterial inner join 		\n\
	 	ultimoestadopedido using(idpedido) 	\n\
	where idestado=4;");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlDetallePedidoPendientePorEnviarAMatriz(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"						\n\
	 select  *					\n\
	 from detallepedidomaterial 			\n\
	 where idpedido=%s;",
SiscomCampoDatosEntrada("Parametro",pSAgsSiscom)); 
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlDetallePedidoPendientePorEnviarAMatriz2(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"						\n\
	 select  *					\n\
	 from detallepedidomaterial 			\n\
	 where idpedido=%s;",
SiscomCampoDatosEntrada("idpedido",pSAgsSiscom)); 
SiscomConsultaBaseAsignaArgumento("SqlPedidosPendientes",
				   lchrArrSql,
				   pSAgsSiscom);
}

void SqlRegistraUltimoEstadoPedido(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[256];
SiscomInsercionActualizacionSubRegistros(0,
					 pSAgsSiscom,
					 "SqlPedidoMaterial",
					 lchrArrBuffer,
					 SqlInsertIntoUltimoEstadoPedido);
}
void SqlActualizaEstadoPedido(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlActualizaEstado",
				   SqlActualizaEstadoPedidoMaterial);
}
void SqlActualizaCantidadProductoPedido(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlActualizaEstado",
				   SqlUpdateDetallePedidoCantidad);
}

void SqlRegistraPedidoMaterial(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBufferSql[256];
SiscomInsercionActualizacionRegistroPrincipal(pSAgsSiscom,
					"SqlPedidoMaterial",
					lchrArrBufferSql,
					SqlInsertIntoPedidoMaterial);
}

void SqlRegistraEstadosPedidoRecibioEnExpendio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBufferSql[256];
SiscomInsercionActualizacionRegistroPrincipal(pSAgsSiscom,
					"SqlRecibePedido",
					lchrArrBufferSql,
					SqlInsertIntoEstadosPedidoMaterialRecibioEnExpendio);
}
void SqlRegistraDetallePedidoMaterial(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[256];
SiscomInsercionActualizacionSubRegistros(1,
					 pSAgsSiscom,
					 "SqlPedidoMaterial",
					 lchrArrBuffer,
					 SqlInsertIntoDetallePedidoMaterial);
}
void SqlRegistraEstadosPedidoMaterial(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[256];
SiscomInsercionActualizacionSubRegistros(0,
					 pSAgsSiscom,
					 "SqlPedidoMaterial",
					 lchrArrBuffer,
					 SqlInsertIntoEstadosPedidoMaterial);
}

void SqlInsertIntoPedidoMaterial(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				 SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into PedidosMaterial values(%s,'%s','%s',%s);",
	SiscomObtenCampoArgumento("Operacion","IdPedidoMaterial",pSAgsSiscom),
	SiscomObtenCampoArgumento("Operacion","Fecha",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"Observaciones",pSAgsSiscom),
	SiscomCampoRegistroPrincipal(pLCSiscomPro2SRDat,"IdExpendio"));
}

void SqlInsertIntoEstadosPedidoMaterialRecibioEnExpendio(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				 SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into EstadosPedidoMaterial values(%s,%s,'%s');",
	SiscomObtenCampoArgumento("Operacion","EstadoPedido",pSAgsSiscom),
	SiscomObtenCampoArgumento("Operacion","IdPedidoMaterial",pSAgsSiscom),
	SiscomObtenCampoArgumento("Operacion","Fecha",pSAgsSiscom));
}

void SqlUpdateDetallePedidoMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				SArgsSiscom *pSAgsSiscom,
				char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update DetallePedido set CantidadRecibida=%s where idpedido=%s and cveproducto'%s';",
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	SiscomCampoRegistroPrincipal(pSAgsSiscom->LCSiscomPro2SREntrada,"IdPedido"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
}

void SqlUpdateExistenciasPorEntregaMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				SArgsSiscom *pSAgsSiscom,
				char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update existencias set existencia=existencia+%s where idexpendio=%s and cveproducto'%s';",
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	SiscomCampoRegistroPrincipal(pSAgsSiscom->LCSiscomPro2SREntrada,"IdExpendio"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
}

/* Queretaro a 3 de diciembre del 2015 
 * Se identifico que al registrar el pedido en los expendios 
 * es comun que repitan producto, esto genera el problema que
 * tiene que ver en la actualizacion y asignacion de cantidad 
 * ya que se asignaria 2 veces la misma cantidad, por lo que 
 * se agrega el IdProducto en DetallePeidoMaterial para poder 
 * realizar las actualizaciones correspondientes al producto
 * seleccionado, sin afectar al duplicado
 */
void SqlInsertIntoDetallePedidoMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				SArgsSiscom *pSAgsSiscom,
				char *pchrPtrSql)
{
char lchrArrIdProducto[25];
SiscomObtenNumeroUnicoChar(lchrArrIdProducto);
sprintf(pchrPtrSql,
	"insert into DetallePedidoMaterial values(%s,%s,'%s','%s',%s,%s);",
	SiscomObtenCampoArgumento("Operacion","IdPedidoMaterial",pSAgsSiscom),
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Observaciones"),
	"0",	
	lchrArrIdProducto);
}
void SqlInsertIntoEstadosPedidoMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into EstadosPedidoMaterial values(%s,%s,'%s');",
	SiscomObtenCampoArgumento("Operacion","EstadoPedido",pSAgsSiscom),
	SiscomObtenCampoArgumento("Operacion","IdPedidoMaterial",pSAgsSiscom),
	SiscomObtenCampoArgumento("Operacion","Fecha",pSAgsSiscom));
}

void SqlInsertIntoUltimoEstadoPedido(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into UltimoEstadoPedido values(%s,%s);",
	SiscomObtenCampoArgumento("Operacion","IdPedidoMaterial",pSAgsSiscom),
	SiscomObtenCampoArgumento("Operacion","EstadoPedido",pSAgsSiscom));
}

void SqlActualizaEstadoPedidoMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				      int *pintPtrNRegistros)
{
char lchrArrFechaHoy[28];
char lchrArrSql[256];
 SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"insert into EstadosPedidoMaterial values(%s,%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdEstado"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPedido"),
	lchrArrFechaHoy);
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
sprintf(lchrArrSql,
	"update ultimoestadopedido set idestado=%s where idpedido=%s",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdEstado"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPedido"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlUpdateDetallePedidoCantidad(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				      int *pintPtrNRegistros)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
"update DetallePedidoMaterial set cantidad=%s where idpedido=%s and cveproducto='%s' and idproducto=%s;",
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPedido"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
