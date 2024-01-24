#include <SQLServicios.h>
#include <SQLComunClinicas3.h>
void SQLServicio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Servicios",
				   SQLGeneraRegistroServicio);
}

void SQLGeneraRegistroServicio(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Servicios values(%s,'%s','%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdServicio"),
	SiscomObtenDato(pLCSiscomPro2,"Clave"),
	SiscomObtenDato(pLCSiscomPro2,"Descripcion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}


void SQLPerfilServicioMedico(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Servicios",
				   SQLGeneraRegistroPerfilServicioMedico);
}

void SQLGeneraRegistroPerfilServicioMedico(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];

for(;
    pLCSiscomPro2;
    pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into perfilserviciomedico values(%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdServicio"),
	SiscomObtenDato(pLCSiscomPro2,"IdMedico"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}


void SQLServicioMedico(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Servicios",
				   SQLGeneraRegistroServicioMedico);
}

void SQLGeneraRegistroServicioMedico(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into ServicioMedico values(%s,%s,'%s','%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdMedico"),
	SiscomObtenDato(pLCSiscomPro2,"IdServicio"),
	SiscomObtenDato(pLCSiscomPro2,"Clave"),
	SiscomObtenDato(pLCSiscomPro2,"Descripcion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}


void SQLServiciosMedicoRegistrados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
"select *,'ServicioMedico' as tipo	\
 from ServicioMedico 			\
 where idPersona=%s			\
 order by clave",
 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLAnexaPreciosServicio(SArgsSiscom *pSAgsSiscom)
{
SQLPreciosServicio("Servicios",pSAgsSiscom);
}
void SQLAnexaPreciosServicioMedico(SArgsSiscom *pSAgsSiscom)
{
SQLPreciosServicioMedico("Servicios",pSAgsSiscom);
}


void SQLRegistroProductoServicio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraRegistroProductoServicio);
}

void SQLGeneraRegistroProductoServicio(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
char lchrArrFecha[25];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFecha);
for(;
    pLCSiscomPro2;
    pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into RegistroProductoServicio values(%s,%s,%s,%s,'%s',%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdConsulta"),
	SiscomObtenDato(pLCSiscomPro2,"IdSerProd"),
	SiscomObtenDato(pLCSiscomPro2,"IdPrecio"),
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	lchrArrFecha,
	SiscomObtenDato(pLCSiscomPro2,"Cantidad"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}

void SQLRegistroEliminaServiciosMaterial(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraRegistroEliminaServicioMaterial);
}

void SQLGeneraRegistroEliminaServicioMaterial(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"delete from materialservicioconsulta where idconsulta=%s;",
	SiscomObtenDato(pLCSiscomPro2,"IdConsulta"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}


void SQLServiciosRegistrados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,"select *,'ServicioGeneral' as Tipo  from servicios order by clave");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLMaterialHospitalizado(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
        "								\
select idConsulta,							\
       idSerProd,							\
       b.Clave,								\
       b.Descripcion,							\
       IdEmpleado,							\
       c.Nombre,							\
       c.APaterno,							\
       c.AMaterno,							\
       fecha,								\
       cantidad								\
from	RegistroProductoServicio as a inner join 			\
	servicios as b	on idSerProd=idservicio inner join		\
	personas  as c  on  idEmpleado=idpersona			\
where idConsulta=%s							\
union									\
select idConsulta,							\
       idSerProd,							\
       b.Clave,								\
       b.Descripcion,							\
       IdEmpleado,							\
       c.Nombre,							\
       c.APaterno,							\
       c.AMaterno,							\
       fecha,								\
       cantidad								\
from	RegistroProductoServicio as a inner join 			\
	serviciomedico as b	on idSerProd=idservicio inner join	\
	personas  as c  on  idEmpleado=c.idpersona			\
where idConsulta=%s							\
union									\
select idConsulta,							\
       idSerProd,							\
       b.Clave,								\
       b.Dsc,								\
       IdEmpleado,							\
       c.Nombre,							\
       c.APaterno,							\
       c.AMaterno,							\
       fecha,								\
       cantidad								\
from	RegistroProductoServicio as a inner join 			\
	producto  as b	on idSerProd=idproducto inner join		\
	personas  as c  on  idEmpleado=c.idpersona			\
where idConsulta=%s							\
order by fecha desc",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
