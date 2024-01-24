#include <SQLPrecios.h>

void SQLConsultaPreciosServicioMedico(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
"								\
select a.idservicio,						\
       a.idprecio,						\
       a.precio,						\
       b.clave,							\
       b.descripcion,						\
	'' as tipo,						\
       c.nombre,						\
       c.dsc							\
from	precioserviciomedico	as a inner join				\
	serviciomedico as b using(idservicio) inner join		\
	precios as c using(idprecio)				\
where idservicio=%s and a.idpersona=%s",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLConsultaPreciosServicio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
"								\
select a.idservicio,						\
       a.idprecio,						\
       a.precio,						\
       b.clave,							\
       b.descripcion,						\
	'' as tipo,						\
       c.nombre,						\
       c.dsc							\
from	preciosservicio	as a inner join				\
	servicios as b using(idservicio) inner join		\
	precios as c using(idprecio)				\
where idservicio=%s",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLActualizaPrecioServicioGeneral(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SQLPrecios",
				   SQLGeneraActualizaPrecioServicioGeneral);
}

void SQLGeneraActualizaPrecioServicioGeneral(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[256];
sprintf(lchrArrSQL,
	"update preciosservicio set precio=%s \
	 where idprecio=%s and idservicio='%s'",
	 SiscomObtenDato(pLCSiscomPro2,"Precio"),
	 SiscomObtenDato(pLCSiscomPro2,"IdPrecio"),
	 SiscomObtenDato(pLCSiscomPro2,"IdServicio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}

void SQLActualizaPrecioServicioMedico(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SQLPrecios",
				   SQLGeneraActualizaPrecioServicioMedico);
}

void SQLGeneraActualizaPrecioServicioMedico(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[256];
sprintf(lchrArrSQL,
	"update precioserviciomedico set precio=%s \
	 where idprecio=%s and idservicio='%s' and idpersona=%s",
	 SiscomObtenDato(pLCSiscomPro2,"Precio"),
	 SiscomObtenDato(pLCSiscomPro2,"IdPrecio"),
	 SiscomObtenDato(pLCSiscomPro2,"IdServicio"),
	 SiscomObtenDato(pLCSiscomPro2,"IdMedico"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
