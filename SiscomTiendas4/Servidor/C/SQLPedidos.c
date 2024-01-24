#include <SQLPedidos.h>
void SqlRegistraPedido(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SqlPedido",
			     SqlGeneraPedido);

}

void SqlGeneraPedido(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"insert into Pedidos(idVenta,observaciones) values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPedido"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Observaciones"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlRegistraPedidoEntregado(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SqlPedido",
			     SqlGeneraPedidoEntregado);

}

void SqlGeneraPedidoEntregado(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[1024];
char lchrArrFecha[25];
SiscomContenidoProtocolo(pLCSiscomPro2Dat);
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFecha);
sprintf(lchrArrSql,
	"update pedidos set identrego=%s,fecha='%s'  where idventa=%s",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdEmpleado"),
	lchrArrFecha,
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPedido"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlRegistraSeguimientoPedido(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SqlPedido",
			     SqlGeneraSeguimientoPedido);

}

void SqlGeneraSeguimientoPedido(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[1024];
char lchrArrFechaHora[25];
SiscomContenidoProtocolo(pLCSiscomPro2Dat);
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
sprintf(lchrArrSql,
	"insert into seguimiento values(%s,%s,'%s','%s',%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCliente"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdEmpleado"),
	lchrArrFechaHora,
	SiscomObtenDato(pLCSiscomPro2Dat,"Observaciones"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPedido"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlPedidosCliente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select a.idventa,			\
		b.fecha,			\
		b.importe,			\
		a.observaciones,		\
		1 as idempleado,		\
		idcliente			\
	 from pedidos as a inner join		\
	      ventas as b using(idVenta)	\
	 where idcliente=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
