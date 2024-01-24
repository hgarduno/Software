#include <SQLAlumnos.h>
#include <SiscomFuncionesComunes.h>

void SQLIniciaComprasCliente(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SisSQLPersona",
				   SQLGeneraIniciaComprasCliente);
}


void SQLRegistraAlumnoExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SisSQLPersona",
				   SQLGeneraRegistroAlumnoExpendio);
}
void SQLActualizaParaClienteElectronica(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
			  "SisSQLPersona",
			  SQLParaClienteElectronica);
}
void SQLRegistraAlumnoEscuela(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
			  "SisSQLPersona",
			  SQLAlumnoEscuela);
}
void SQLRegistraGrupoAlumno(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
			  "SisSQLPersona",
			  SQLGrupoAlumno);
}


void SQLRegistraCelularAlumno(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
			  "SisSQLPersona",
			  SQLCelularAlumno);
}
void SQLRegistraTelefonoAlumno(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
			  "SisSQLPersona",
			  SQLTelefonoAlumno);
}
void SQLRegistraCorreoAlumno(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
			  "SisSQLPersona",
			  SQLCorreoAlumno);
}
void SQLRegistraAlumno(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
			  "SisSQLPersona",
			  SQLAlumno);
}

void SqlRegistraCredencialAlumno(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
			  "SisSQLPersona",
			  SqlInsertIntoCredencialAlumno);
}


void SQLGeneraIniciaComprasCliente(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
char lchrArrFechaHoy[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSQL,
	"insert into ComprasClientes values(%s,0,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	lchrArrFechaHoy);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}
void SQLGeneraRegistroAlumnoExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into ClienteExpendio values(%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"IdExpendio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}



void SQLParaClienteElectronica(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"update personas set tipopersona=1,rfc=%s where idpersona=%s;",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}
void SQLAlumnoEscuela(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into alumnoescuela values(%s,%s)",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"idescuela"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}
void SQLGrupoAlumno(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into GrupoAlumno values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"Grupo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}


void SQLCelularAlumno(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Telefonos values(%s,0,'%s','Celular');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"Celular"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}
void SQLTelefonoAlumno(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Telefonos values(%s,0,'%s','');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"Telefono"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}
void SQLCorreoAlumno(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Correos values(%s, 0, '%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"Correo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}


void SQLAlumno(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Alumnos values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"Boleta"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}

void SqlInsertIntoCredencialAlumno(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into CredencialAlumno values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"NoCredencial"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}
void SqlAlumnosExpendio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	" 								\n\
select a.*,								\n\
       b.idescuela,							\n\
       c.nombre as escuela ,						\n\
       a.nombre || ' ' ||  a.apaterno as boleta,			\n\
       case when f.credencial is null					\n\
       then								\n\
       		a.nombre || ' ' ||  a.apaterno 				\n\
	else								\n\
		f.credencial						\n\
       end as credencial						\n\
from personas as a inner join 						\n\
     alumnoescuela as b  on a.idpersona=b.idpersona inner join 		\n\
     escuelas as c on b.idescuela=c.idescuela inner join 		\n\
     clienteexpendio as d on a.idpersona=d.idpersona inner join 	\n\
     alumnos as e on a.idpersona=e.idpersona  left outer join 		\n\
     credencialalumno as f on f.idpersona=a.idpersona			\n\
where d.idempresa=%s							\n\
union									\n\
select *,								\n\
	0,								\n\
	'',								\n\
	'Publico En General',						\n\
	'Publico En General' 						\n\
from personas								\n\
where apaterno='GENERAL' 						\n\
order by idescuela 							\n\
",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
SiscomLog("%s",lchrArrSql);
}

void SqlGrupoAlumno(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"SELECT * 		\n\
	from grupoalumno	\n\
	where idpersona=%s",
SiscomCampoSubRegistroArgs(0,"idpersona",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento(
		"SqlGrupo",
		lchrArrSql,
		pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlGrupo",pSAgsSiscom);
}
void SqlCorreosAlumno(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"SELECT * 		\n\
	from correos		\n\
	where idpersona=%s",
SiscomCampoSubRegistroArgs(0,"idpersona",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento(
		"SqlCorreos",
		lchrArrSql,
		pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlCorreos",pSAgsSiscom);
}
void SqlDatosAlumno(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"SELECT a.idpersona,					\n\
		a.nombre,					\n\
		a.apaterno,					\n\
		a.amaterno,					\n\
		c.boleta,					\n\
		f.idescuela,					\n\
		f.nombre as escuela				\n\
	from personas as a inner join 				\n\
		grupoalumno as b using(idpersona) inner join	\n\
		alumnos as c using(idpersona) inner join	\n\
		correos as d using(idpersona) inner join	\n\
		alumnoescuela as e using(idpersona) inner join  \n\
		escuelas as f using(idescuela)			\n\
	where idpersona=%s",
SiscomCampoSubRegistroArgs(0,"idpersona",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento(
		"SqlAlumno",
		lchrArrSql,
		pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlAlumno",pSAgsSiscom);
}

void SqlTelefonosAlumno(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"SELECT *				\n\
	from telefonos				\n\
	where idpersona=%s			\n\
	order by departamenteo desc",
SiscomCampoSubRegistroArgs(0,"idpersona",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento(
		"SqlTelefonos",
		lchrArrSql,
		pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlTelefonos",pSAgsSiscom);
}
