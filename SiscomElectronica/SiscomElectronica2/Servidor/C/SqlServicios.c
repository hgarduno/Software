#include <SqlServicios.h>

void SqlServicios(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
sprintf(lchrArrSql, "select * from servicios");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlAlumnosSinRegistroSalida(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"				\n\
select idregistroservicio,		\n\
	idpersona,			\n\
	horaentrada,			\n\
	nombre 		|| 		\n\
	' ' 		||  		\n\
	apaterno 	|| 		\n\
	' '		||		\n\
	amaterno as nombre 		\n\
from alumnoservicio as a  inner join 	\n\
	personas as b using(idpersona)	\n\
where horasalida is null");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlRegistraAlumnoServicio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlAlumnoServicio",
				   SqlInsertIntoAlumnoServicio);
}

void SqlActualizaAlumnoServicioHoraSalida(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlAlumnoServicio",
				   SqlUpdateAlumnoServicioHoraSalida);
}



void SqlInsertIntoAlumnoServicio(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into AlumnoServicio(idregistroservicio,idservicio,idpersona,comentarios,horaentrada) values(%s,%s,%s,'%s','%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdRegistroServicio"),
	SiscomObtenDato(pLCSiscomPro2,"IdServicio"),
	SiscomObtenDato(pLCSiscomPro2,"IdAlumno"),
	SiscomObtenDato(pLCSiscomPro2,"Comentarios"),
	SiscomObtenDato(pLCSiscomPro2,"HoraEntrada"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");

}

void SqlUpdateAlumnoServicioHoraSalida(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"update AlumnoServicio set HoraSalida='%s' where idregistroservicio=%s ",
	SiscomObtenDato(pLCSiscomPro2,"HoraSalida"),
	SiscomObtenDato(pLCSiscomPro2,"IdServicio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}
