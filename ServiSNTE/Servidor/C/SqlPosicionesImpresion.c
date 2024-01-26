#include <SqlPosicionesImpresion.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>
int SqlPosicionesPuntoVenta(SiscomOperaciones *pSiscomOpePtrDato)
{

char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=0							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=0");
LogSiscom("%s",lchrArrSqlCampoRegistro); 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);
}


int SqlPosicionesReciboApartado(SiscomOperaciones *pSiscomOpePtrDato)
{

char lchrArrBuffer[512],
	lchrArrSqlPosicionesCampo[512];
sprintf(lchrArrSqlPosicionesCampo,
	"							\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=1							\n\
order by a.idcampo");

LogSiscom("%s",lchrArrSqlPosicionesCampo);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesReciboApartado%",
		   lchrArrSqlPosicionesCampo);
}

int SqlPosicionesTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{

char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=2							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=2");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);
}

int SqlPosicionesListaPrecios(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=4							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=4");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}

int SqlPosicionesListaPreciosComprador(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=5							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=5");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}



int SqlPosicionesStockTienda(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=3							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=3");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}

int SqlPosicionesExistenciaTiendaProveedor(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=11							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=11");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}

int SqlPosicionesSoporteTransferencias(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=14							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=14");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}
int SqlPosicionesCuentasPagar(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=8							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=8");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}

int SqlPosicionesRelacionChequesPagar(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=7							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=7");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}
int SqlPosicionesSoporteCompras(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=10							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=10");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}
int SqlPosicionesSoporteVentas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=15							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=15");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}
int SqlPosicionesStockProveedorCosto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=6							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=6");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);
}
int SqlPosicionesExistenciaProveedor(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=9							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=9");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}

int SqlPosicionesDatosCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=12							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=12");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}

int SqlPosicionesProveedores(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlPosicionesCampo[1024],
	lchrArrSqlCampoRegistro[1024];
sprintf(lchrArrSqlPosicionesCampo,
	"									\n\
select *,0 as registrocampo							\n\
from impresiones as a inner join						\n\
	tipocampo as b on(a.idmoduloimpresion=b.idmoduloimpresion and 		\n\
			  a.idcampo=b.idcampo) left outer join			\n\
	posicionescampo as c on(a.idmoduloimpresion=c.idmoduloimpresion and 	\n\
				a.idcampo=c.idcampo)				\n\
where a.idmoduloimpresion=13							\n\
order by a.idcampo");

sprintf(lchrArrSqlCampoRegistro,
	"select a.idregistro,								\n\
		a.idcampo,								\n\
		a.campo,								\n\
		x,									\n\
		y,									\n\
		anchox,									\n\
		anchoy									\n\
	 from nombrescamporegistro as a inner join					\n\
	      camposregistro as b on (a.idmoduloimpresion=b.idmoduloimpresion and 	\n\
	      			      a.idregistro=b.idregistro and 			\n\
				      a.idcampo=b.idcampo)				\n\
	 where a.idregistro in (select idcampo 						\n\
	 		      from tipocampo 						\n\
			      where idtipocampo=1) 					\n\
	     and a.idmoduloimpresion=13");
	 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PosicionesPuntoVenta%CampoRegistroPosiciones%",
		   lchrArrSqlPosicionesCampo,
		   lchrArrSqlCampoRegistro);

}


