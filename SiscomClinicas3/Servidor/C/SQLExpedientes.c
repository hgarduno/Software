#include <SQLExpedientes.h>
#include <string.h>
#include <stdlib.h>

void SQLRegistraExpediente(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraRegistroExpediente);
}

void SQLGeneraRegistroExpediente(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char *lchrArrSQL;
lchrArrSQL=(char *)malloc(strlen(SiscomObtenDato(pLCSiscomPro2,"Observaciones"))+512);
sprintf(lchrArrSQL,
"insert into Expediente(IdConsulta,Fecha,Observaciones)  values(%s,'%s','%s');",
SiscomObtenDato(pLCSiscomPro2,"IdConsulta"),
SiscomObtenDato(pLCSiscomPro2,"Fecha"),
SiscomObtenDato(pLCSiscomPro2,"Observaciones"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
free(lchrArrSQL);
}


void SQLActualizaObservaciones(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraActualizaObservaciones);
}

void SQLGeneraActualizaObservaciones(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
"update Expediente set Observaciones='%s',Fecha='%s' where idconsulta=%s;",
SiscomObtenDato(pLCSiscomPro2,"Observaciones"),
SiscomObtenDato(pLCSiscomPro2,"Fecha"),
SiscomObtenDato(pLCSiscomPro2,"IdConsulta"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLObservacionesConsulta(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[256];
sprintf(lchrArrSQL,
"					\
select * 				\
from	expediente			\
where idconsulta=%s",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}


void SQLExpediente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
"							\
select a.* ,						\
       c.*,						\
       '' as rfc,					\
       '' as firma,					\
       '' as password,					\
       0  as idperfil					\
from expediente as a inner join				\
     consulta as b using(idconsulta) inner join		\
     personas as c on (b.idmedico=c.idpersona)		\
where b.idconsulta in (					\
	select idconsulta				\
	from consulta 					\
	where idpaciente=%s and 			\
	      idestado=3)				\
order by fecha desc",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}


void SQLRecetasPaciente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
"							\
select  *						\
from	recetas 					\
where idconsulta in (					\
			select idconsulta		\
			from consulta			\
			where idpaciente=%s)		\
order by fecha desc					\
",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
