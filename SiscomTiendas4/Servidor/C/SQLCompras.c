#include <SQLCompras.h>
#include <ComunSiscomTiendas4.h>
void SQLRegistraCompra(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLCompras",
			     SQLGeneraCompras);

}
void SQLActualizaInventario(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLCompras",
			     SQLGeneraInventario);
}
void SQLProductosCotizando(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SQLCompras",
			     SQLGeneraProductosCotizando);
}
void SQLUltimaCompraProducto(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[2048];
sprintf(lchrArrSQL,"							\
select	a.idcompra,							\
  	a.idproducto,							\
	a.cantidad,							\
	a.preciocompra,							\
	a.factura,							\
	a.idempresa,							\
	a.idformapago,							\
	a.fecha,							\
	b.clave,							\
	b.dsc as dscproducto,						\
	g.idfamilia,							\
	g.familia,							\
	e.nombre,							\
	e.apaterno,							\
	e.amaterno,							\
	e.idpersona,							\
	d.razonsocial,							\
	c.diassigpago							\
from	compras as a inner join 					\
	producto as b using(idProducto) inner join			\
	formapago as c using(idformapago) inner join			\
	empresas as d using(idempresa) inner join			\
	personas as e on idcontacto=idpersona inner join		\
	famproducto as f using(idProducto) inner join			\
	familia as g using(idfamilia)					\
where idProducto=%s and							\
      idexpendio=%s							\
order by fecha desc							\
limit 1",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);


}
void SQLCompras(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[2048];
sprintf(lchrArrSQL,"							\
select	a.idcompra,							\
  	0 as idproducto,						\
	0 as cantidad,							\
	0 as preciocompra,						\
	a.factura,							\
	a.idempresa,							\
	a.idformapago,							\
	a.fecha::date,							\
	'' as clave,							\
	'' as dscproducto,						\
	0 as idfamilia,							\
	0 as familia,							\
	e.nombre,							\
	e.apaterno,							\
	e.amaterno,							\
	e.idpersona,							\
	d.razonsocial,							\
	0 as diassigpago						\
from	compras as a inner join 					\
	formapago as c using(idformapago) inner join			\
	empresas as d using(idempresa) inner join			\
	personas as e on idcontacto=idpersona				\
where fecha::date>='%s' and						\
      fecha::date<='%s' and						\
      idexpendio=%s							\
group by a.idcompra,							\
	 a.factura,							\
	 a.idempresa,							\
	 a.idformapago,							\
	 a.fecha::date,							\
	 e.nombre,							\
	 e.apaterno,							\
	 e.amaterno,							\
	 e.idpersona,							\
	 d.razonsocial,							\
	 a.factura							\
order by fecha desc",							\
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[1]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);

}
void SQLDetalleCompra(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[2048];

sprintf(lchrArrSQL,"							\
select	a.idcompra,							\
  	a.idproducto,							\
	a.cantidad,							\
	a.preciocompra,							\
	a.factura,							\
	a.idempresa,							\
	a.idformapago,							\
	a.fecha,							\
	b.clave,							\
	b.dsc as dscproducto,						\
	g.idfamilia,							\
	g.familia,							\
	e.nombre,							\
	e.apaterno,							\
	e.amaterno,							\
	e.idpersona,							\
	d.razonsocial,							\
	c.diassigpago							\
from	compras as a inner join 					\
	producto as b using(idProducto) inner join			\
	formapago as c using(idformapago) inner join			\
	empresas as d using(idempresa) inner join			\
	personas as e on idcontacto=idpersona inner join		\
	famproducto as f using(idProducto) inner join			\
	familia as g using(idfamilia)					\
where idCompra=%s 	and						\
      e.idpersona=%s 	and						\
      d.idempresa=%s							\
order by fecha desc",
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[4]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);

}

void SQLGeneraCompras(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
LCamposSiscomPro2 *lLCSiscomPro2Contador;
const char *lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio");
char lchrArrFechaHoraHoy[25];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
for(lLCSiscomPro2Contador=pLCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into Compras values(%s,%s,%s,%s,'%s',%s,%s,%s,'%s',%s);",
	SiscomObtenDato(lLCSiscomPro2Contador,"IdCompra"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"),
	SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"),
	SiscomObtenDato(lLCSiscomPro2Contador,"Precio"),
	SiscomObtenDato(lLCSiscomPro2Contador,"Factura"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdEmpresa"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdContacto"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdFormaPago"),
	lchrArrFechaHoraHoy,
	lchrPtrIdExpendio);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
void SQLGeneraInventario(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
LCamposSiscomPro2 *lLCSiscomPro2Contador;
const char *lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio");
for(lLCSiscomPro2Contador=pLCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
sprintf(lchrArrSQL,
 	"insert into Inventario values(%s,%s,%s,%s);",
	lchrPtrIdExpendio,
	SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"),
	"0.0",
	"0.0");
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
sprintf(lchrArrSQL,
 	"update inventario set Existencia=Existencia+%s		\
	 where idExpendio=%s and idProducto=%s",
	 SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"),
	lchrPtrIdExpendio,
	SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}

void SQLGeneraProductosCotizando(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
LCamposSiscomPro2 *lLCSiscomPro2Contador;
const char *lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio");
for(lLCSiscomPro2Contador=pLCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
sprintf(lchrArrSQL,
 	"insert into ProductosCotizando values(%s,%s,%s);",
	SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"),
	lchrPtrIdExpendio,
	"0.0");
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
