#include <SQLCotizando.h>
#include <string.h>
#include <stdlib.h>
void FormaCadenaServiciosProducto(const char *pchrPtrNmbId,
			  LCamposSiscomPro2 *pLCSiscomPro2Dat,
			  char **pchrPtrCondicion)
{
char lchrArrPaso[25];
sprintf(lchrArrPaso,"a.%s in(",
	pchrPtrNmbId);
 *pchrPtrCondicion=strdup(lchrArrPaso);
for(;
	pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
   if(strcmp(SiscomObtenDato(pLCSiscomPro2Dat,"Clave"),
   	     "TotalServicio"))
   {
	if(pLCSiscomPro2Dat->SCP2PtrSig)
	sprintf(lchrArrPaso,
		"%s,",
		SiscomObtenDato(pLCSiscomPro2Dat,"IdSerProd"));
	else
	sprintf(lchrArrPaso,
		"%s) ",
		SiscomObtenDato(pLCSiscomPro2Dat,"IdSerProd"));
	*pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,
					  strlen(*pchrPtrCondicion)+
					  strlen(lchrArrPaso)      +
					  1);
	strcat(*pchrPtrCondicion,lchrArrPaso);
   }


}

}
void SQLDatosCotizaConsulta(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
char lchrArrSQL[4192];
int lintNRegreso;
char *lchrPtrCondicion;
char *lchrPtrCondicionProducto;

SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
FormaCadenaServiciosProducto("idServicio",
			pSAgsSiscom->LCSiscomPro2Dat,
		     &lchrPtrCondicion);
FormaCadenaServiciosProducto("idProducto",
			pSAgsSiscom->LCSiscomPro2Dat,
		     &lchrPtrCondicionProducto);
sprintf(lchrArrSQL,
"								\
select a.idservicio,						\
	a.idpersona,						\
	a.clave,						\
	a.descripcion,						\
	b.precio,						\
	b.idprecio,						\
	1 as cantidad, 						\
	1 as existencia,					\
	'Servicio Medico' as Tipo,				\
	0 as importe						\
from	serviciomedico as a inner join 				\
	precioserviciomedico as b using(idservicio)		\
where  idprecio=%s 	and 					\
       a.idpersona=%s 	and					\
	%s							\
union								\
select a.idservicio,						\
	'%s' as idpersona,					\
	a.clave,						\
	a.descripcion,						\
	b.precio,						\
	b.idprecio,						\
	1 as cantidad, 						\
	1 as existencia,					\
	'Servicio General' as Tipo,				\
	0 as importe						\
from	servicios as a inner join 				\
	preciosservicio as b using(idservicio)			\
where  idprecio=%s	and 					\
	%s 							\
union								\
select a.idproducto as idservicio,				\
	'%s' as idpersona,					\
	a.clave,						\
	a.dsc as descripcion,					\
	b.precio,						\
	b.idprecio,						\
	1 as cantidad, 						\
	c.existencia as existencia,				\
	'Producto'  as Tipo,					\
	0 as importe						\
from	producto as a inner join				\
	preciosproducto as b using(idproducto) inner join	\
	inventario as c using(idproducto)			\
where  idprecio=%s	and 					\
	%s							\
order by tipo",
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPrecio"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdMedico"),
lchrPtrCondicion,
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdMedico"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPrecio"),
lchrPtrCondicion,
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdMedico"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPrecio"),
lchrPtrCondicionProducto);
SiscomConsultaBaseDatosSinDatosConexion(lchrArrSQL,
					pSAgsSiscom->chrArrDirIpAD,
					pSAgsSiscom->intPtoComAD,
					&lLCSiscomPro2Reg,
					&lintNRegreso);
SiscomAsignaInformacionArgumento("SQLCotizando",
				 pSAgsSiscom,
				 lLCSiscomPro2Reg,
				 0,
				 lintNRegreso);
SiscomLog("%s",lchrArrSQL);
}
void SQLDatosPerfilServicioMedico(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
char lchrArrSQL[2048];
int lintNRegreso;
sprintf(lchrArrSQL,
"										\
select a.idservicio,								\
       idmedico as idpersona,							\
       b.clave,									\
       b.descripcion,								\
       c.precio,								\
       c.idprecio,								\
       1 as cantidad,								\
       1 as existencia,								\
       'Servicio Medico' as Tipo,						\
       0 as importe								\
from	perfilserviciomedico as a  inner join					\
	serviciomedico  as b on (a.idmedico=b.idpersona and			\
				 a.idservicio=b.idservicio) inner join		\
	precioserviciomedico as c on (a.idmedico=c.idpersona and		\
				    a.idservicio=c.idservicio)			\
where	idmedico=%s		and						\
	idprecio=%s								\
union										\
select a.idservicio,								\
       idmedico as idpersona,							\
	b.clave,								\
	b.descripcion,								\
	c.precio,								\
	c.idprecio,								\
	1,									\
	1,									\
	'Servicio General',							\
	0 as importe								\
from	perfilserviciomedico as a inner join					\
	servicios as b using (idservicio) inner join				\
	preciosservicio as c on(a.idservicio=c.idservicio) 			\
where   idprecio=%s	 	and						\
	idmedico=%s								\
union										\
select	a.idservicio,								\
	idmedico as idpersona,							\
	b.clave,								\
	b.dsc,									\
	c.precio,								\
	c.idprecio,								\
	1,									\
	existencia,								\
	'Producto',								\
	0 as importe								\
from	perfilserviciomedico as a inner join					\
	producto as b on (a.idservicio=b.idproducto) inner join			\
	preciosproducto as c on(b.idproducto=c.idproducto)  inner join		\
	inventario as d on(a.idservicio=d.idproducto)				\
where idprecio=%s	 and							\
      idmedico=%s	 and							\
	idexpendio=0",
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdMedico"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPrecio"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPrecio"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdMedico"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPrecio"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdMedico"));
SiscomConsultaBaseDatosSinDatosConexion(lchrArrSQL,
					pSAgsSiscom->chrArrDirIpAD,
					pSAgsSiscom->intPtoComAD,
					&lLCSiscomPro2Reg,
					&lintNRegreso);
SiscomAsignaInformacionArgumento("SQLCotizando",
				 pSAgsSiscom,
				 lLCSiscomPro2Reg,
				 0,
				 lintNRegreso);
}


void SQLDatosParaCobrarConsulta(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
char lchrArrSQL[2048];
int lintNRegreso;
sprintf(lchrArrSQL,
"									\
select	a.idserprod as idservicio,					\
	b.idmedico as idpersona,					\
	c.clave,							\
	c.descripcion,							\
	a.precio,							\
	a.idprecio,							\
	a.cantidad,							\
	1 as existencia,						\
	'Servicio Medico' as tipo,					\
	a.importe							\
from	materialservicioconsulta as a inner join 			\
	consulta as b using(idconsulta) inner join			\
	serviciomedico as c on (a.idserprod=c.idservicio)		\
where idconsulta=%s							\
union									\
select	a.idserprod as idservicio,					\
	b.idmedico as idpersona,					\
	c.clave,							\
	c.descripcion,							\
	a.precio,							\
	a.idprecio,							\
	a.cantidad,							\
	1 as existencia,						\
	'Servicio General' as tipo,					\
	a.importe							\
from	materialservicioconsulta as a inner join 			\
	consulta as b using(idconsulta) inner join			\
	servicios as c on (a.idserprod=c.idservicio)			\
where idconsulta=%s							\
union									\
select	a.idserprod as idservicio,					\
	b.idmedico as idpersona,					\
	c.clave,							\
	c.dsc,								\
	a.precio,							\
	a.idprecio,							\
	a.cantidad,							\
	1 as existencia,						\
	'Producto' as tipo,						\
	a.importe							\
from	materialservicioconsulta as a inner join 			\
	consulta as b using(idconsulta) inner join			\
	producto as c on (a.idserprod=c.idproducto)			\
where idconsulta=%s",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[1]);

SiscomConsultaBaseDatosSinDatosConexion(lchrArrSQL,
					pSAgsSiscom->chrArrDirIpAD,
					pSAgsSiscom->intPtoComAD,
					&lLCSiscomPro2Reg,
					&lintNRegreso);
SiscomAsignaInformacionArgumento("SQLCotizando",
				 pSAgsSiscom,
				 lLCSiscomPro2Reg,
				 0,
				 lintNRegreso);



}
void ObtenRangoFechas(SArgsSiscom *pSAgsSiscom,
		      char *pchrPtrFechaIni,
		      char *pchrPtrFechaFin)
{

	if(!pSAgsSiscom->chrPtrArgConsulta[1][0]  &&
	   !pSAgsSiscom->chrPtrArgConsulta[2][0])
	{
	 SiscomObtenFechaHoyCharAAAADDMM(pchrPtrFechaIni);
	 strcpy(pchrPtrFechaFin,pchrPtrFechaIni);
	}
	else
	{
	  strcpy(pchrPtrFechaIni,
	  	 pSAgsSiscom->chrPtrArgConsulta[1]);
	  strcpy(pchrPtrFechaFin,
	  	 pSAgsSiscom->chrPtrArgConsulta[2]);
	}

}
void SQLVentasMedico(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[2048];
char lchrArrFechaIni[25];
char lchrArrFechaFin[25];

ObtenRangoFechas(pSAgsSiscom,lchrArrFechaIni,lchrArrFechaFin);
sprintf(lchrArrSQL,
"								\
select 0 as idservicio,						\
	b.clave,						\
	b.descripcion,						\
	0 as idpersona,						\
	0 as idprecio,						\
	a.precio,						\
	sum(a.precio) as importe,				\
       sum(a.cantidad) as cantidad				\
from	materialservicioconsulta as a inner join		\
	servicios as b on  a.idserprod=b.idservicio		\
where idconsulta in (						\
select idconsulta						\
from consulta							\
where idmedico=%s and 						\
      fecha::date>='%s' and					\
      fecha::date<='%s' and 					\
      idestado=3)						\
group by b.clave,						\
         b.descripcion,						\
	 a.precio						\
union								\
select 0 as idservicio,						\
	c.clave,						\
	c.descripcion,						\
	0 as idpersona,						\
	0 as idprecio,						\
	a.precio,						\
	sum(a.precio) as importe,				\
	sum(a.cantidad) as cantidad				\
from	materialservicioconsulta as a inner join		\
	consulta as b using(idconsulta)  inner join		\
	serviciomedico as c on  (b.idmedico=c.idpersona and 	\
	                         a.idserprod=c.idservicio) 	\
where idconsulta in (						\
select idconsulta						\
from consulta							\
where idmedico=%s and 						\
      fecha::date>='%s' and					\
      fecha::date<='%s' and					\
      idestado=3)						\
group by c.clave,						\
         c.descripcion,						\
	 a.precio						\
union								\
select 0 as idservicio,						\
	b.clave,						\
	b.dsc as descripcion,					\
	0 as idpersona,						\
	0 as idprecio,						\
       a.precio,						\
	sum(a.precio) as importe,				\
       sum(a.cantidad) as  cantidad				\
from	materialservicioconsulta as a inner join		\
	producto as b on  a.idserprod=b.idproducto		\
where idconsulta in (						\
select idconsulta						\
from consulta							\
where idmedico=%s and 						\
      fecha::date>='%s' and					\
      fecha::date<='%s' and					\
      idestado=3	)					\
group by b.clave,						\
         b.dsc,							\
	 a.precio						\
order by  7 desc						\
",
pSAgsSiscom->chrPtrArgConsulta[3],
lchrArrFechaIni,
lchrArrFechaFin,
pSAgsSiscom->chrPtrArgConsulta[3],
lchrArrFechaIni,
lchrArrFechaFin,
pSAgsSiscom->chrPtrArgConsulta[3],
lchrArrFechaIni,
lchrArrFechaFin);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
