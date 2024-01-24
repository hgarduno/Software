#include <SQLConsultas.h>
#include <string.h>
#include <stdlib.h>

void SQLActualizaReceta(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraActualizaReceta);
}

void SQLGeneraActualizaReceta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char *lchrArrSQL;

lchrArrSQL=(char *)malloc(strlen(SiscomObtenDato(pLCSiscomPro2,"Receta")) +
			  128);
sprintf(lchrArrSQL,
	"update recetas set receta='%s',fecha='%s'  \
	 where idconsulta=%s and folio='%s'",
	 SiscomObtenDato(pLCSiscomPro2,"Receta"),
	 SiscomObtenDato(pLCSiscomPro2,"Fecha"),
	 SiscomObtenDato(pLCSiscomPro2,"IdConsulta"),
	 SiscomObtenDato(pLCSiscomPro2,"Folio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLRegistraReceta(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraRegistraReceta);
}

void SQLGeneraRegistraReceta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char *lchrArrSQL;

lchrArrSQL=(char *)malloc(strlen(SiscomObtenDato(pLCSiscomPro2,"Receta")) +
			  128);

sprintf(lchrArrSQL,
	"insert into Recetas values(%s,'%s','%s','%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdConsulta"),
	SiscomObtenDato(pLCSiscomPro2,"Fecha"),
	SiscomObtenDato(pLCSiscomPro2,"Folio"),
	SiscomObtenDato(pLCSiscomPro2,"Receta"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}

void SQLRegistraConsulta(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraRegistroConsultas);
}

void SQLGeneraRegistroConsultas(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Consulta values(%s,%s,%s,%s,'%s',%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdConsulta"),
	SiscomObtenDato(pLCSiscomPro2,"IdMedico"),
	SiscomObtenDato(pLCSiscomPro2,"IdEmpleado"),
	SiscomObtenDato(pLCSiscomPro2,"IdPaciente"),
	SiscomObtenDato(pLCSiscomPro2,"Fecha"),
	SiscomObtenDato(pLCSiscomPro2,"IdEdo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}

void SQLEdoConsultaTermina(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraEdoConsultaTermina);
}

void SQLGeneraEdoConsultaTermina(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"update consulta set idestado=7 where idConsulta=%s;",
	SiscomObtenDato(pLCSiscomPro2,"IdConsulta"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
SiscomLog(" >>>>>>>>>>>>> %s ",lchrArrSQL);
}

void SQLTerminaConsulta(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraTerminaConsulta);
}

void SQLGeneraTerminaConsulta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
char lchrArrFechaHora[20];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
sprintf(lchrArrSQL,
	"insert into EvolucionConsulta values(%s,%s,'%s',%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdConsulta"),
	SiscomObtenDato(pLCSiscomPro2,"IdMedico"),
	lchrArrFechaHora,
	"7");
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}


void SQLServiciosProductosConsulta(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraServiciosProductosConsulta);
}

void SQLGeneraServiciosProductosConsulta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
for(;
	pLCSiscomPro2;
     pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
{
if(strcmp(SiscomObtenDato(pLCSiscomPro2,"Clave"),"TotalServicio"))
{
sprintf(lchrArrSQL,
	"insert into MaterialServicioConsulta values(%s,%s,%s,%s,%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdConsulta"),
	SiscomObtenDato(pLCSiscomPro2,"IdSerProd"),
	SiscomObtenDato(pLCSiscomPro2,"Precio"),
	SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
	SiscomObtenDato(pLCSiscomPro2,"Importe"),
	SiscomObtenDato(pLCSiscomPro2,"IdPrecio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
}

void SQLCambiaEdoConsulta(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraCambioEdoConsulta);
}

void SQLGeneraCambioEdoConsulta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"UPDATE consulta set idestado = %s where idconsulta=%s;",
	SiscomObtenDato(pLCSiscomPro2,"IdEdo"),
	SiscomObtenDato(pLCSiscomPro2,"IdConsulta"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLConsultasPendientesMedico(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
char lchrArrFecha[25];
/*SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha); */
sprintf(lchrArrSQL,
"SELECT count(*) as \"NoConsultas\" 	\
from consulta 				\
where fecha::date>='%s' and 		\
      fecha::date<='%s' and		\
      idmedico=%s      and		\
      idestado=1",
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
/*
 *
 * Se modificara esta funcion para que se pueda 
 * regresar varios estados de consulta, por ejemplo
 * en el caso de la recepccion se requiere que 
 * la recepcionista pueda ver las consultas en espera
 * y las consultas terminadas para poder cobrar 
 * la consulta
 *
 */
void GeneraCondicionEstados(const char *pchrPtrEdos,
			    char **pchrPtrConsulta)
{
char **lchrPtrEdos;
char lchrArrBuffer[512];
int lintNumCadenas;
int lintContador;
if((lintNumCadenas=SiscomAnalizaCadenas(pchrPtrEdos,
					'|',
					lchrArrBuffer,
					&lchrPtrEdos))>1)
{
*pchrPtrConsulta=strdup("idestado in( select idestado		\
				      from estadoconsulta	\
				      where estado in(");
 for(lintContador=0;
     lintContador<lintNumCadenas;
     lintContador++)
  {  
     if(lchrPtrEdos[lintContador+1])
     sprintf(lchrArrBuffer,"'%s',",lchrPtrEdos[lintContador]);
     else
     sprintf(lchrArrBuffer,"'%s')) ",lchrPtrEdos[lintContador]);
     *pchrPtrConsulta=(char *)realloc(*pchrPtrConsulta,
     				      strlen(*pchrPtrConsulta)	+
				      strlen(lchrArrBuffer) 	+
				      1);
      strcat(*pchrPtrConsulta,lchrArrBuffer);
  }
}
else
{
	SiscomLog("No Importa El Estado");
	if(strstr(pchrPtrEdos,"PorMedico"))
	{
	SiscomLog("Es Por Medico");
	sprintf(lchrArrBuffer,
		"consulta.idmedico=%s",
		pchrPtrEdos+9);
	*pchrPtrConsulta=strdup(lchrArrBuffer);
	}
	else
	{
	SiscomLog("Todos Los Registros ");
	*pchrPtrConsulta=strdup("idestado in (select idestado		\
					      from estadoconsulta )");
	}
}
}
void SQLConsultasRegistradasHoyEnEspera(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[2048];
char *lchrPtrCondicion;
GeneraCondicionEstados(pSAgsSiscom->chrPtrArgConsulta[4],
		       &lchrPtrCondicion);
sprintf(lchrArrSQL,
"											\
select	consulta.idConsulta,								\
	'' as noconsulta,								\
	consulta.fecha,									\
	consulta.idmedico,								\
	medico.nombre as NmbMedico,							\
	medico.apaterno as APatMedico,							\
	medico.amaterno as AMatMedico,							\
	consulta.idpaciente,								\
	paciente.nombre as NmbPaciente,							\
	paciente.apaterno as Apatpaciente,						\
	paciente.amaterno as AMatPaciente,						\
	consulta.idempleado,								\
	empleado.nombre as nmbempleado,							\
	empleado.apaterno as apatempleado,						\
	empleado.amaterno as amatempleado,						\
	estadoconsulta.estado,								\
	consulta.idestado								\
from	consulta inner join								\
	personas as medico on (consulta.idmedico=medico.idpersona) inner join		\
	personas as paciente on (consulta.idpaciente=paciente.idpersona) inner join	\
	personas as empleado on (consulta.idempleado=empleado.idpersona) inner join	\
	estadoconsulta using(idestado)							\
where 	fecha::date>='%s' and								\
        fecha::date<='%s'  and								\
	%s										\
order by consulta.idmedico,								\
	 fecha",
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
lchrPtrCondicion);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLConsultasMedicoHoy(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[2048];
char lchrArrFecha[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
sprintf(lchrArrSQL,
"											\
select	consulta.idConsulta,								\
	'' as noconsulta,								\
	consulta.fecha,									\
	consulta.idmedico,								\
	medico.nombre as NmbMedico,							\
	medico.apaterno as APatMedico,							\
	medico.amaterno as AMatMedico,							\
	consulta.idpaciente,								\
	paciente.nombre as NmbPaciente,							\
	paciente.apaterno as Apatpaciente,						\
	paciente.amaterno as AMatPaciente,						\
	consulta.idempleado,								\
	empleado.nombre as nmbempleado,							\
	empleado.apaterno as apatempleado,						\
	empleado.amaterno as amatempleado,						\
	estadoconsulta.estado,								\
	consulta.idestado								\
from	consulta inner join								\
	personas as medico on (consulta.idmedico=medico.idpersona) inner join		\
	personas as paciente on (consulta.idpaciente=paciente.idpersona) inner join	\
	personas as empleado on (consulta.idempleado=empleado.idpersona) inner join	\
	estadoconsulta using(idestado)							\
where 	fecha::date>='%s' and								\
        fecha::date<='%s'  and								\
	consulta.idmedico=%s								\
order by consulta.idmedico,								\
	 fecha",
lchrArrFecha,
lchrArrFecha,
pSAgsSiscom->chrPtrArgConsulta[5]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);

}

void SQLConsultasActualMedico(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[2048];
char lchrArrFecha[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
sprintf(lchrArrSQL,
"											\
select	consulta.idConsulta,								\
	'' as noconsulta,								\
	consulta.fecha,									\
	consulta.idmedico,								\
	medico.nombre as NmbMedico,							\
	medico.apaterno as APatMedico,							\
	medico.amaterno as AMatMedico,							\
	consulta.idpaciente,								\
	paciente.nombre as NmbPaciente,							\
	paciente.apaterno as Apatpaciente,						\
	paciente.amaterno as AMatPaciente,						\
	consulta.idempleado,								\
	empleado.nombre as nmbempleado,							\
	empleado.apaterno as apatempleado,						\
	empleado.amaterno as amatempleado,						\
	estadoconsulta.estado,								\
	consulta.idestado								\
from	consulta inner join								\
	personas as medico on (consulta.idmedico=medico.idpersona) inner join		\
	personas as paciente on (consulta.idpaciente=paciente.idpersona) inner join	\
	personas as empleado on (consulta.idempleado=empleado.idpersona) inner join	\
	estadoconsulta using(idestado)							\
where 	fecha::date='%s' and								\
	consulta.idmedico=%s and							\
	consulta.idestado=2								\
order by consulta.idmedico,								\
	 fecha",
lchrArrFecha,
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);

}
void SQLRecetaConsulta(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[256];
sprintf(lchrArrSQL,
	"select * 			\
	 from recetas			\
	 where idconsulta=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
