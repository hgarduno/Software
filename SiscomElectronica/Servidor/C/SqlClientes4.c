#include <SqlClientes4.h>
#include <Facturando4.h>
#include <SiscomInsercionesSql.h>
#include <SiscomMacrosOperaciones.h>
#include <stdio.h>


#include <SiscomDesarrolloMacros.h>


int SqlCompletaDatosPersona(const char *pchrPtrIdPersona,
			    SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSqlDirecciones[256],
	lchrArrSqlTelefonos[256],
	lchrArrSqlCorreos[256];
sprintf(lchrArrSqlDirecciones,"select *,1 as edoregistro from direcciones where idpersona=%s",pchrPtrIdPersona);
sprintf(lchrArrSqlTelefonos,"select * from telefonos where idpersona=%s",pchrPtrIdPersona);
sprintf(lchrArrSqlCorreos,"select * from correos where idpersona=%s",pchrPtrIdPersona);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSisOpePtrDato,
			     "Direcciones%Correos%Telefonos%",
			     lchrArrSqlDirecciones,
			     lchrArrSqlCorreos,
			     lchrArrSqlTelefonos);
return 0;
}

int SqlEnviaRegistroCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
 SiscomEnviaRegistrosAlServidorBD("SqlCliente",
 				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
int SqlEnviaRegistroFactura(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
 SiscomEnviaRegistrosAlServidorBD("SqlRegistroFactura",
 				  lchrArrBuffer,
				  pSiscomOpePtrDato);

}
int SqlRegistraFacturaFisica(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];
SiscomAgregaSentenciasSqlCampoAsociado("SqlRegistroFactura",
					"Envio",
					"Cliente",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToFacturadoFisica);
}
int SqlRegistraFacturaMoral(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];
SiscomAgregaSentenciasSqlCampoAsociado("SqlRegistroFactura",
					"Envio",
					"Cliente",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToFacturadoMoral);
}


int SqlRegistraOrdenesFacturadas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];
SiscomAgregaSentenciasSqlCampoAsociado("SqlRegistroFactura",
					"Envio",
					"Ordenes",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToOrdenesFacturadas);
}
int SqlRegistraAlumnoEscuela4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[128];
SiscomAgregaSentenciasSqlDelAsociado("SqlCliente",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToAlumnoEscuela);

return 0;
}

int SqlRegistraCorreoAlumno(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Correo",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToCorreoAlumno);

}
int SqlRegistraCelularAlumno(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Celular",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToCelularAlumno);

}
int SqlRegistraDireccionAlumno(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrBufferSql[1024];
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Direccion",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToDireccionAlumno);
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Direccion",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToEntreCallesAlumno);
}
int SqlRegistraClientePersona(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlCliente",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToPersonaCliente);
return 0;
}

int SqlRegistraPersona4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];
if(EsPersonaFisica(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Persona",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToPersona4);
return 0;
}

int SqlRegistraPersonaNormalizada4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];
SiscomAgregaSentenciaSqlArgumento("SqlCliente",
				  "Normalizado",
				   lchrArrBuffer,
				   lchrArrBufferSql,
				pSiscomOpePtrDato,
				InsertToPersonaNormalizada4);
return 0;
}

int SqlRegistraEmpresa4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrBufferSql[1024];
if(!EsPersonaFisica(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Empresa",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToEmpresa4);
return 0;
}
int SqlRegistraDireccion4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrBufferSql[256];
if(EsPersonaFisica(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Direccion",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToDireccionFisica4);
else
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Direccion",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToDireccionMoral4);

return 0;
}

int SqlRegistraTelefonos4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];
if(EsPersonaFisica(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Telefonos",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToTelefonoFisica4);
else
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Telefonos",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToTelefonoMoral4);

return 0;
}

int SqlRegistraCorreos4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];
if(EsPersonaFisica(pSiscomOpePtrDato))
{
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Correos",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToCorreoFisica4);
}
else
SiscomAgregaSentenciasSqlCampoAsociado("SqlCliente",
					"Envio",
					"Correos",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToCorreoMoral4);
return 0;
}
void SqlConsultaPersonas4(SiscomOperaciones *pSiscomOpePtrDato,
		 	  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"			\n\
	select *		\n\
	from personas 		\n\
	where rfc='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDato));
}
void SqlConsultaEmpresas4(SiscomOperaciones *pSiscomOpePtrDato,
		 	  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"						\n\
	select razonsocial as \"RazonSocial\",		\n\
	       idempresa as \"IdEmpresa\",		\n\
	       rfc as \"Rfc\",				\n\
	       regimenfiscal as \"RegimenFiscal\" 	\n\
	from empresas 					\n\
	where rfc='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDato));
}

void SqlDireccionPersona4(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *		\n\
	 from direcciones 	\n\
	 where idpersona=%s",
	 SiscomObtenCampoRegistroProLChar("idpersona",pSiscomRegProLPtrPersona));

}

void SqlTelefonosPersona4(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *			\n\
	from telefonos			\n\
	where idpersona=%s  and		\n\
	      telefono is not null",
	 SiscomObtenCampoRegistroProLChar("idpersona",pSiscomRegProLPtrPersona));
}
void SqlCorreosPersona4(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select idpersona as \"IdPersona\",	\n\
		idempresa as \"IdEmpresa\",	\n\
		correo as \"Correo\"		\n\
	from correos \n\
	where idpersona=%s",
	 SiscomObtenCampoRegistroProLChar("idpersona",pSiscomRegProLPtrPersona));
}


void SqlDireccionEmpresa4(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *		\n\
	 from direcciones 	\n\
	 where idempresa=%s",
	 SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrPersona));

}
void SqlTelefonosEmpresa4(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *		\n\
	from telefonos		\n\
	where idempresa=%s",
	 SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrPersona));
}
void SqlCorreosEmpresa4(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select idpersona as \"IdPersona\",	\n\
		idempresa as \"IdEmpresa\",	\n\
		correo as \"Correo\"		\n\
	from correos \n\
	where idempresa=%s",
	 SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrPersona));
}
int SqlDireccionEscuela(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],lchrArrSql[256];

sprintf(lchrArrSql,
	"select *		\n\
	 from direcciones 	\n\
	 where idempresa=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","IdEscuela",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSiscomOpePtrDato,
			     "SqlDirecciones%",
			     lchrArrSql);
LogSiscom("%s",lchrArrSql);
}

int SqlDireccionesPersonaEnvioIdPersona(SiscomOperaciones *pSisOpePtrDato)
{
SqlDireccionesPersona(
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSisOpePtrDato),
	pSisOpePtrDato);
return 0;
}
int SqlDireccionesPersona(const char *pchrPtrIdPersona,
			  SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSql[128],lchrArrBuffer[128];
sprintf(lchrArrSql,
	"select *,1 as edoregistro 	\n\
	 from direcciones		\n\
	 where idpersona=%s",
	 pchrPtrIdPersona);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
				pSiscomOpePtrDato,
				"SqlDirecciones%",
				lchrArrSql);
return 0;
}
int SqlClienteRegistrado4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],lchrArrSql[256];
SqlConsultaPersonas4(pSiscomOpePtrDato,lchrArrSql);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSiscomOpePtrDato,
			     "SqlPersona%",
			     lchrArrSql);
}
int SqlBuscandoClienteRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[4192],lchrArrSql[4192];
const char *lchrPtrSql;
if((lchrPtrSql=SiscomCampoArgumentoPrim("ConsultaSql",
				       "Sql",
				       pSiscomOpePtrDato)))
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSiscomOpePtrDato,
			     "SqlPersona%",
			     lchrPtrSql);
}

int SqlClienteEmpresaRegistrado4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],lchrArrSql[256];
SqlConsultaEmpresas4(pSiscomOpePtrDato,lchrArrSql);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSiscomOpePtrDato,
			     "SqlPersona%",
			     lchrArrSql);
}

int SqlDatosFisicaRegistrada(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			    SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrDirecciones[128],
	lchrArrTelefonos[128],
	lchrArrCorreos[256];

SqlDireccionPersona4(pSiscomRegProLPtrPersona,lchrArrDirecciones);
SqlTelefonosPersona4(pSiscomRegProLPtrPersona,lchrArrTelefonos);
SqlCorreosPersona4(pSiscomRegProLPtrPersona,lchrArrCorreos);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		pSiscomOpePtrDato,
		"SqlDireccion%SqlTelefonos%SqlCorreos%",
		lchrArrDirecciones,
		lchrArrTelefonos,
		lchrArrCorreos);
}
int SqlDatosMoralRegistrada(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			    SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrDirecciones[128],
	lchrArrTelefonos[128],
	lchrArrCorreos[256];

SqlDireccionEmpresa4(pSiscomRegProLPtrPersona,lchrArrDirecciones);
SqlTelefonosEmpresa4(pSiscomRegProLPtrPersona,lchrArrTelefonos);
SqlCorreosEmpresa4(pSiscomRegProLPtrPersona,lchrArrCorreos);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		pSiscomOpePtrDato,
		"SqlDireccion%SqlTelefonos%SqlCorreos%",
		lchrArrDirecciones,
		lchrArrTelefonos,
		lchrArrCorreos);
}

void SqlAmbienteFacturacion(SiscomOperaciones *pSiscomOpePtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select b.* 						\n\
	 from ambientefacturacionactivo as a  inner join 	\n\
	      ambientesfacturacionphp as b using(idambiente)");
}
void SqlAmbienteFacturacionCorreoActivo(SiscomOperaciones *pSiscomOpePtrDato,
					     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 						\n\
	 from correoactivoenviofacturacion as a inner join 	\n\
	      correosenviofacturacion as b using(idcorreo)");
}

int SqlAmbienteActivoTimbrado(SiscomOperaciones *pSiscomOpePtrDato,
			      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * from ambienteactivotimbrado inner join ambientetimbrado using(idambiente);");
}
int SqlAmbienteFacturacionPhp(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSqlAmbiente[256],
	lchrArrSqlCorreo[256],
	lchrArrAmbienteActivoTimbrado[256];
SqlAmbienteFacturacion(pSiscomOpePtrDato,lchrArrSqlAmbiente);
SqlAmbienteFacturacionCorreoActivo(pSiscomOpePtrDato,lchrArrSqlCorreo);
SqlAmbienteActivoTimbrado(pSiscomOpePtrDato,lchrArrAmbienteActivoTimbrado);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "AmbientePhp%Correo%AmbienteTimbrado%",
			      lchrArrSqlAmbiente,
			      lchrArrSqlCorreo,
			      lchrArrAmbienteActivoTimbrado);
}
int SqlClientePublicoEnGeneral(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"select * 		\n\
	 from personas 		\n\
	 where rfc='GENERAL'");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "PublicoEnGeneral%",
			      lchrArrSql);

}

int SqlClientesMayoreo(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "ClientesMayoreo%",
			      "select *				\n\
			       from preciocliente inner join	\n\
			            personas using(idpersona)	\n\
			       where tipopersona=2");
return 0;
}

void InsertToPersonaCliente(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"insert into personas values('%s','%s','%s','%s',%s,1);",
	SiscomObtenCampoRegistroProLChar("Nombre",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("APaterno",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("AMaterno",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("RFC",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrDato));
}
void InsertToPersona4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
SiscomRegistroProtocoloLog(pchrPtrSql,pSiscomRegProLPtrDato);
sprintf(pchrPtrSql,
	"insert into personas values('%s','%s','%s','%s',%s,1,'');",
	SiscomObtenCampoRegistroProLChar("Nombre",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("APaterno",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("AMaterno",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrDato));
}
void InsertToPersonaNormalizada4(SiscomOperaciones *pSiscomOpePtrDato,
		      		SiscomRegistroProL *pSiscomRegProLPtrDato,
		      		char *pchrPtrSql)
{
LogSiscom("");
SiscomRegistroProtocoloLog(pchrPtrSql,pSiscomRegProLPtrDato);
sprintf(pchrPtrSql,
	"insert into PersonaNormalizada values(%s,'%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Nombre",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("APaterno",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("AMaterno",pSiscomRegProLPtrDato));
}

void InsertToEmpresa4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into empresas values('%s',%s,'%s',%s);",
	SiscomObtenCampoRegistroProLChar("RazonSocial",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("RegimenFiscal",pSiscomRegProLPtrDato));
}

void InsertToDireccionFisica4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
const char *lchrPtrNumInterior;
lchrPtrNumInterior=SiscomObtenCampoRegistroProLChar("NumeroInt",pSiscomRegProLPtrDato);
sprintf(pchrPtrSql,
	"insert into Direcciones values(%s,0,'%s','%s','%s',%s,'%s','%s','','%s');",
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Persona","IdPersona",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Calle",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Numero",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Colonia",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("CP",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Delegacion",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Estado",pSiscomRegProLPtrDato),
	lchrPtrNumInterior ? lchrPtrNumInterior : "");
}

void InsertToDireccionMoral4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
const char *lchrPtrNumInterior;
lchrPtrNumInterior=SiscomObtenCampoRegistroProLChar("NumeroInt",pSiscomRegProLPtrDato);
sprintf(pchrPtrSql,
	"insert into Direcciones values(0,%s,'%s','%s','%s',%s,'%s','%s','','%s');",
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Empresa","IdEmpresa",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Calle",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Numero",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Colonia",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("CP",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Delegacion",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Estado",pSiscomRegProLPtrDato),
	lchrPtrNumInterior ? lchrPtrNumInterior : "");
}


void InsertToTelefonoMoral4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into telefonos values(0,%s,'%s','');",
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Empresa","IdEmpresa",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Telefono",pSiscomRegProLPtrDato));
}
void InsertToTelefonoFisica4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into telefonos values(%s,0,'%s','');",
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Persona","IdPersona",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Telefono",pSiscomRegProLPtrDato));


}
void InsertToCorreoMoral4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into correos values(0,%s,'%s');",
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Empresa","IdEmpresa",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Correo",pSiscomRegProLPtrDato));
}
void InsertToCorreoFisica4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into correos values(%s,0,'%s');",
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Persona","IdPersona",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Correo",pSiscomRegProLPtrDato));
}
void InsertToFacturadoFisica(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql)
{
SiscomRegistroProtocoloLog(pchrPtrSql,pSiscomRegProLPtrDato);
sprintf(pchrPtrSql,
	"insert into Facturado values(%s,0,%s,0,'%s');",
SiscomAsociadoPrimerCampo("Persona","IdPersona",pSiscomRegProLPtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdFactura",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato));
}
void InsertToFacturadoMoral(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;

lSiscomRegProLPtrDato=SiscomObtenRegistrosCampoProL("Empresa",pSiscomRegProLPtrDato);

SiscomRegistroProtocoloLog(pchrPtrSql,pSiscomRegProLPtrDato);
SiscomRegistroProtocoloLog(pchrPtrSql,lSiscomRegProLPtrDato);
sprintf(pchrPtrSql,
	"insert into Facturado values(0,%s,%s,0,'%s');",
SiscomAsociadoPrimerCampo("Empresa","IdEmpresa",pSiscomRegProLPtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdFactura",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato));
}

void InsertToOrdenesFacturadas(SiscomOperaciones *pSiscomOpePtrDato,
			       SiscomRegistroProL *pSiscomRegProLPtrDato,
			       char *pchrPtrSql)
{
 sprintf(pchrPtrSql,
 	"insert into OrdenesFacturadas values(%s,%s)",
SiscomCampoAsociadoEntradaOperacion("Envio","IdFactura",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("idventa",pSiscomRegProLPtrDato));
}

void InsertToAlumnoEscuela(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into AlumnoEscuela values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Escuela","idescuela",pSiscomOpePtrDato));
}

void InsertToCorreoAlumno(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into correos values(%s,0,'%s');",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Correo",pSiscomRegProLPtrDato));

}
void InsertToCelularAlumno(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into telefonos values(%s,0,'%s','');",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Telefono",pSiscomRegProLPtrDato));
}
void InsertToDireccionAlumno(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
const char *lchrPtrColonia,*lchrPtrReferencia;
char lchrArrBuffer[256];
if(!SiscomObtenCampoRegistroProLInt("EdoRegistro",pSiscomRegProLPtrDato))	     
{
lchrPtrColonia=SiscomObtenCampoRegistroProLChar("Colonia",pSiscomRegProLPtrDato) ;
lchrPtrColonia=lchrPtrColonia ? lchrPtrColonia : "";
lchrPtrReferencia=SiscomObtenCampoRegistroProLChar("Referencias",pSiscomRegProLPtrDato);
lchrPtrReferencia=lchrPtrReferencia ? lchrPtrReferencia : "";
sprintf(pchrPtrSql,
	"insert into direcciones values(%s,0,'%s','%s','%s','%s','%s','%s','%s','',%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Calle",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Numero",pSiscomRegProLPtrDato),
	lchrPtrColonia,
	SiscomObtenCampoRegistroProLChar("CP",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Delegacion",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Estado",pSiscomRegProLPtrDato),
	lchrPtrReferencia,
	SiscomObtenCampoRegistroProLChar("IdDireccion0",pSiscomRegProLPtrDato));
}
}


void InsertToEntreCallesAlumno(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
if(!SiscomObtenCampoRegistroProLInt("EdoRegistro",pSiscomRegProLPtrDato))	     
sprintf(pchrPtrSql,
	"insert into EntreCalles values(%s,'%s','%s');",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Calle1",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Calle2",pSiscomRegProLPtrDato));
}
void SqlArmaConsultaEmpresaPorIdFactura(SiscomOperaciones *pSiscomOpePtrDato,
					char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 				\n\
	 from facturado inner join 		\n\
	      empresas using(idempresa) 	\n\
	where idfactura = %s",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdFactura",pSiscomOpePtrDato));
}
void SqlArmaConsultaCorreosEmpresaPorIdFactura(SiscomOperaciones *pSiscomOpePtrDato,
					        char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 					\n\
	 from correos 					\n\
	 where idempresa in (select idempresa 		\n\
	 		     from facturado 		\n\
			     where idfactura=%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdFactura",pSiscomOpePtrDato));

}

int SqlConsultaParaReEnvioFactura(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSqlEmpresa[256],
	lchrArrSqlCorreos[256];

SqlArmaConsultaEmpresaPorIdFactura(pSiscomOpePtrDato,lchrArrSqlEmpresa);
SqlArmaConsultaCorreosEmpresaPorIdFactura(pSiscomOpePtrDato,lchrArrSqlCorreos);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "Empresa%Correos%",
			      lchrArrSqlEmpresa,
			      lchrArrSqlCorreos);
}
