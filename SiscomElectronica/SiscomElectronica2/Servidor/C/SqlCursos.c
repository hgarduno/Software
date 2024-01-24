#include <SqlCursos.h>
#include <RegistraCursos.h>

void SqlCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomEjecutaConsultaYResponde(pSAgsSiscom,"select * from cursos");
}

void SqlFechasCursos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
if(*(*(pSAgsSiscom->chrPtrArgConsulta+2)))
sprintf(lchrArrSql,
	"select *		\n\
	 from fechascursos	\n\
	 where IdCurso=%s",
pSAgsSiscom->chrPtrArgConsulta[2]);
else
sprintf(lchrArrSql,
	"select distinct fecha from fechascursos order by fecha desc");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
void SqlDisponibilidadCursos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"						\n\
select a.idcurso,					\n\
	curso,						\n\
	duracion,					\n\
	cupo,						\n\
	horainicio,					\n\
	horafin,					\n\
	disponibles					\n\
from fechascursos as a inner join			\n\
      cursos as b using(idcurso) inner join		\n\
      horarioscursos as c on a.idcurso=c.idcurso and 	\n\
      			  a.fecha=c.fecha		\n\
where a.fecha ='%s'					\n\
order by horainicio,disponibles desc",
pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);

}
void SqlRegistraAlumnoInscrito(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlInsertIntoAlumnoInscritoCurso);
}

void SqlRegistraProgramacionCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlProgramacionCursos",
				   SqlInsertIntoRegistroProgramaCurso);

}
void SqlDecrementaDisponibles(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlUpdateFechasCursosDisponibles);


}

void SqlProgramandoCurso(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlProgramandoCurso",
				   SqlInsertIntoProgramacionCursos);
}

void SqlRegistraFechasCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlProgramandoCurso",
				   SqlInsertIntoFechasCursos);
}

void SqlIniciaCostoCurso(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlProgramandoCurso",
				   SqlInsertandoInicioCostoCurso);
 
}
void SqlRegistraCostosCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlCostosCursos",
				   SqlInsertIntoCostosCursos);
}

void SqlInsertIntoHorariosCursos(LCamposSiscomPro2 *pLCSiscomPro2Curso,
				LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				int *pintPtrNRegistros)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
		"insert into HorariosCursos values(%s,'%s','%s','%s',%s)",
		SiscomObtenDato(pLCSiscomPro2Curso,"IdCurso"),
		SiscomObtenDato(pLCSiscomPro2Curso,"Fecha"),
		SiscomObtenDato(pLCSiscomPro2Curso,"HoraInicio"),
		SiscomObtenDato(pLCSiscomPro2Curso,"HoraFin"),
		SiscomObtenDato(pLCSiscomPro2Curso,"IdProgramacion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSql,
			"");
}

void SqlInsertIntoInicioCurso(LCamposSiscomPro2 *pLCSiscomPro2Curso,
				LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				int *pintPtrNRegistros)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
		"insert into InicioCurso values(%s,'%s','%s','%s',%s)",
		SiscomObtenDato(pLCSiscomPro2Curso,"IdCurso"),
		SiscomObtenDato(pLCSiscomPro2Curso,"Fecha"),
		SiscomObtenDato(pLCSiscomPro2Curso,"HoraInicio"),
		SiscomObtenDato(pLCSiscomPro2Curso,"HoraFin"),
		SiscomObtenDato(pLCSiscomPro2Curso,"IdProgramacion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSql,
			"");
}
void SqlRegistraHorariosCursos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim=0,
		  *lLCSiscomPro2SqlAct=0,
		  *lLCSiscomPro2Curso;
int lintNRegistros=0;
int lintHorarioInicio=0;
char *lchrPtrHoraIniEliminar=0,*lchrPtrHoraFinEliminar=0;
const char *lchrPtrIdCurso;
SiscomLog("Insertando en los horarios");
SiscomContenidoProtocolo(lLCSiscomPro2Dat);
for(; lLCSiscomPro2Dat;lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
  if(SiscomEstaElCampo(lLCSiscomPro2Dat,"Dia"))
  {
  	lLCSiscomPro2Curso=lLCSiscomPro2Dat;
	lLCSiscomPro2Dat=VerificaHorariosEliminados(lLCSiscomPro2Dat,
						    &lchrPtrHoraIniEliminar,
						    &lchrPtrHoraFinEliminar);
	if(!lchrPtrHoraIniEliminar &&
	   !lchrPtrHoraFinEliminar)
	{
	SiscomLog("Se Insertara IdCurso(%s) Fecha(%s) HoraInicio(%s) HoraFin(%s) IdProgramacion(%s)",
		  SiscomObtenDato(lLCSiscomPro2Curso,"IdCurso"),
		  SiscomObtenDato(lLCSiscomPro2Curso,"Fecha"),
		  SiscomObtenDato(lLCSiscomPro2Curso,"HoraInicio"),
		  SiscomObtenDato(lLCSiscomPro2Curso,"HoraFin"),
		  SiscomObtenDato(lLCSiscomPro2Curso,"IdProgramacion"));
	SqlInsertIntoHorariosCursos(lLCSiscomPro2Curso,
				    &lLCSiscomPro2SqlPrim,
				    &lLCSiscomPro2SqlAct,
				    &lintNRegistros);
	  if(!lintHorarioInicio)
	  {
	     lintHorarioInicio=1;
	     SiscomLog("Se Inserta en la tabla de inicio curso");
		SqlInsertIntoInicioCurso(lLCSiscomPro2Curso,
				    &lLCSiscomPro2SqlPrim,
				    &lLCSiscomPro2SqlAct,
				    &lintNRegistros);

	  }
	}
	else
	{
		/*
		SiscomLog("Se debe eliminar el horario:(%s-%s)",
			  lchrPtrHoraIniEliminar,
			  lchrPtrHoraFinEliminar);
		*/
	  if(AjustaHorariosCurso(lLCSiscomPro2Curso,lchrPtrHoraIniEliminar,lchrPtrHoraFinEliminar))
	  {
	      
	  }
	  else
	  SiscomLog("Se Elimino el horario:(%s-%s)",
	  	    lchrPtrHoraIniEliminar,
		    lchrPtrHoraFinEliminar);
	}
  }
}

SiscomAsignaInformacionArgumento("SqlHorariosCursos",
				 pSAgsSiscom,
				 lLCSiscomPro2SqlPrim,
				 lLCSiscomPro2SqlAct,
				 lintNRegistros);
}

void SqlFechasCursos2(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
/*
sprintf(lchrArrSql,
	"							\n\
select a.idcurso,						\n\
       b.fecha,							\n\
       horainicio,						\n\
       horafin,							\n\
       cupo,							\n\
       disponibles,						\n\
       b.idprogramacion						\n\
from	cursos as a inner join					\n\
	horarioscursos as b using(idcurso) inner join		\n\
	fechascursos as c on b.fecha=c.fecha and 		\n\
			     b.idcurso=c.idcurso inner join	\n\
	programacioncursos as d on (b.fecha=d.fecha and 	\n\
				    b.idcurso=d.idcurso)	\n\
	 where a.idcurso=%s",
	 SiscomCampoDatosEntrada("IdCurso",pSAgsSiscom));
*/
/*
sprintf(lchrArrSql,
	"								\n\
select a.idcurso,							\n\
	a.fecha,							\n\
	a.horainicio,							\n\
	a.horafin,							\n\
	b.cupo,								\n\
	b.disponibles,							\n\
	b.idprogramacion						\n\
from horarioscursos  as a  inner join					\n\
	fechascursos as b on a.idcurso=b.idcurso and 			\n\
			     a.idprogramacion=b.idprogramacion		\n\
where a.idcurso=%s and 							\n\
	b.activo=1							\n\
	limit 1;",
	 SiscomCampoDatosEntrada("IdCurso",pSAgsSiscom));
*/

sprintf(lchrArrSql,
	"								\n\
select distinct a.idcurso,						\n\
	a.fecha,							\n\
	a.horainicio,							\n\
	a.horafin,							\n\
	b.cupo,								\n\
	b.disponibles,							\n\
	b.idprogramacion						\n\
from  iniciocurso as a  inner join					\n\
     fechascursos as b on a.idcurso=b.idcurso and 			\n\
                          a.idprogramacion=b.idprogramacion 		\n\
where a.idcurso=%s and 							\n\
      b.activo=1							\n\
order by a.fecha desc",
SiscomCampoDatosEntrada("IdCurso",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlFechasCurso",lchrArrSql,pSAgsSiscom);
SiscomLog("%s",lchrArrSql);
}

void SqlProgramacionCurso(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
SiscomLog("Obteniendo los cursos de la fecha:%s", SiscomCampoDatosEntrada("FechaInicio",pSAgsSiscom));
sprintf(lchrArrSql,
	"			\n\
	select *		\n\
	from programacioncursos	\n\
	where fecha='%s'",
	SiscomCampoDatosEntrada("FechaInicio",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlProgramacionCurso",lchrArrSql,pSAgsSiscom);
SiscomLog("%s",lchrArrSql);

}
void SqlCursosEnEsaFecha(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
SiscomLog("Obteniendo los cursos de la fecha:%s", SiscomCampoDatosEntrada("FechaInicio",pSAgsSiscom));
sprintf(lchrArrSql,
	"					\n\
select a.*,curso				\n\
from horarioscursos as a inner join 		\n\
     cursos as b using(idcurso) 		\n\
where fecha>='%s'				\n\
order by idcurso,fecha,horainicio",
	SiscomCampoDatosEntrada("FechaInicio",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlCursosEnEsaFecha",lchrArrSql,pSAgsSiscom);
SiscomLog("%s",lchrArrSql);
}
void SqlAlumnoRegistrado(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"							\n\
select idpersona,						\n\
	boleta,							\n\
	a.nombre,						\n\
	apaterno,						\n\
	amaterno,						\n\
	idescuela,						\n\
	f.nombre as escuela,					\n\
	grupo,							\n\
	correo,							\n\
	telefono						\n\
from 	personas as a inner join 				\n\
	alumnos as b using(idpersona) inner join 		\n\
	correos as c using(idpersona) inner join		\n\
	grupoalumno as d using(idpersona) inner join		\n\
	alumnoescuela as e using(idpersona) inner join		\n\
	escuelas as f using(idescuela) inner join		\n\
	telefonos as g using(idpersona)				\n\
where idpersona=%s and 						\n\
	telefono!=''",
SiscomCampoDatosEntrada("IdPersona",pSAgsSiscom));
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseAsignaArgumento("SqlAlumnoRegistrado",lchrArrSql,pSAgsSiscom); 
}

void SqlCostosCursos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"						\n\
select *						\n\
from costoscursos as a inner join			\n\
     explicacionpromocion as b using(idestatus)		\n\
where a.idcurso=%s and 					\n\
      a.idprogramacion=%s					\n\
order by idestatus",
	 SiscomCampoDatosEntrada("IdCurso",pSAgsSiscom),
	 SiscomCampoDatosEntrada("IdProgramacion",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlCostosCurso",lchrArrSql,pSAgsSiscom);
SiscomLog("%s",lchrArrSql);
}

void SqlVentasCursos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"					\n\
select count(*) as cantidad,			\n\
       idcurso,					\n\
       curso,					\n\
       costo,					\n\
       0 as importe 				\n\
from alumnoinscritocurso as a inner join 	\n\
	cursos as b using(idcurso)		\n\
where fecha in(select fecha 			\n\
               from programacioncursos 		\n\
	       where idprogramacion=%s)		\n\
group by idcurso,costo,curso			\n\
order by curso asc",
	 SiscomCampoDatosEntrada("IdProgramacionCurso",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento("SqlVentasCursos",lchrArrSql,pSAgsSiscom);
SiscomLog("%s",lchrArrSql);
}

void SqlCursosProgramados(SArgsSiscom *pSAgsSiscom)
{
SiscomEjecutaConsultaYResponde(pSAgsSiscom,"select * from RegistroProgramaCurso");
}

void SqlExplicacionPromocion(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
SiscomLog("Llenando el control");
sprintf(lchrArrSql,"select * from explicacionpromocion");
SiscomLog("%s",lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,"select * from explicacionpromocion");
sleep(1);
SiscomLog("Se Respondio lo de las explicaciones");

}
void SqlAlumnosInscritosCurso(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"							\n\
select a.idpersona,						\n\
       explicacion,						\n\
       b.nombre || ' ' 	|| b.apaterno as nombrec, 		\n\
       a.costo,							\n\
       d.correo,						\n\
       (select telefono 					\n\
        from telefonos 						\n\
	where idpersona=a.idpersona and 			\n\
		telefono!='' limit 1 ) as telefono		\n\
from alumnoinscritocurso as a inner join 			\n\
     personas as b using(idpersona) inner join			\n\
     ExplicacionPromocion as c using(idestatus)	 inner join 	\n\
     correos as d using(idpersona) 				\n\
				where idcurso=%s and		\n\
				fecha='%s' 			\n\
order by apaterno,amaterno,nombre",
	 pSAgsSiscom->chrPtrArgConsulta[2],
	 pSAgsSiscom->chrPtrArgConsulta[3]);
SiscomLog("%s",lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}


void SqlInsertIntoAlumnoInscritoCurso(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into AlumnoInscritoCurso values(%s,%s,'%s','%s',%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"IdCurso"),
	SiscomObtenDato(pLCSiscomPro2,"fecha"),
	SiscomObtenDato(pLCSiscomPro2,"horainicio"),
	SiscomObtenDato(pLCSiscomPro2,"idestatus"),
	SiscomObtenDato(pLCSiscomPro2,"costo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");

}

void SqlUpdateFechasCursosDisponibles(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"update FechasCursos set disponibles=disponibles-1	\n\
	 where idcurso=%s and 					\n\
	       idprogramacion=%s", 
	SiscomObtenDato(pLCSiscomPro2,"IdCurso"),
	SiscomObtenDato(pLCSiscomPro2,"idprogramacion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");



}

void SqlInsertIntoRegistroProgramaCurso(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)

{

char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into RegistroProgramaCurso values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdProgramacion"),
	SiscomObtenDato(pLCSiscomPro2,"DscProgramacion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}

void SqlInsertIntoProgramacionCursos(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into ProgramacionCursos values(%s,%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdProgramacion"),
	SiscomObtenDato(pLCSiscomPro2,"IdCurso"),
	SiscomObtenDato(pLCSiscomPro2,"FechaInicio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");

}

void SqlInsertandoInicioCostoCurso(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into CostosCursos values(%s,%s,%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdCurso"),
	"0",
	"0",
	SiscomObtenDato(pLCSiscomPro2,"IdProgramacion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");

}

void SqlInsertIntoFechasCursos(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into FechasCursos values(%s,'%s',2,24,24,%s,1);",
	SiscomObtenDato(pLCSiscomPro2,"IdCurso"),
	SiscomObtenDato(pLCSiscomPro2,"FechaInicio"),
	SiscomObtenDato(pLCSiscomPro2,"IdProgramacion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");

}



void SqlInsertIntoCostosCursos(LCamposSiscomPro2 *pLCSiscomPro2,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into CostosCursos values(%s,%s,%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdCurso"),
	SiscomObtenDato(pLCSiscomPro2,"IdPromocion"),
	SiscomObtenDato(pLCSiscomPro2,"Costo"),
	SiscomObtenDato(pLCSiscomPro2,"IdProgramacion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegitro",
			lchrArrSQL,
			"");
}


