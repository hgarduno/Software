#include <SqlPersonas.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <SiscomDesarrolloMacros.h> 

#include <stdio.h>

int SqlRegistraCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaPersona",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaPersona",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToPersonas);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaPersona",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToClientes);
SiscomReplicaMaquinaLocal("SqlInsertaPersona", lchrArrBuffer, 0, pSiscomOpePtrDat);
return 0;
}
int SqlActualizaRFC(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaPersona",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaPersona",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateRFC);
SiscomReplicaMaquinaLocal("SqlInsertaPersona", lchrArrBuffer, 0, pSiscomOpePtrDat);
return 0;
}


void SqlConsultaPersonaPorNombre(SiscomOperaciones *pSiscomOpePtrDat,
				 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *									\n\
	 from personas as a left outer join 						\n\
	      direccionescliente as b on a.idpersona=b.idcliente left outer join 	\n\
	      direcciones as c using(iddireccion)					\n\
	 where nombre='%s' and 								\n\
	       apaterno='%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Nombre",pSiscomOpePtrDat),
	 SiscomCampoAsociadoEntradaOperacion("Envio","APaterno",pSiscomOpePtrDat));
}
void SqlConsultaTelefonosPorNombre(SiscomOperaciones *pSiscomOpePtrDat,
				   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *					\n\
	 from telefonocliente as a left outer join 	\n\
	      telefonos as b using(idtelefono)		\n\
	where idcliente=(select idpersona 		\n\
			 from personas 			\n\
			 where nombre='%s' and 		\n\
			       apaterno='%s')",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Nombre",pSiscomOpePtrDat),
	 SiscomCampoAsociadoEntradaOperacion("Envio","APaterno",pSiscomOpePtrDat));
}
int SqlPersonaYaRegistrada(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrSqlPersona[1024],
	lchrArrSqlTelefonos[256],
	lchrArrBuffer[1024];
SqlConsultaPersonaPorNombre(pSiscomOpePtrDat,lchrArrSqlPersona);
SqlConsultaTelefonosPorNombre(pSiscomOpePtrDat,lchrArrSqlTelefonos);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
				pSiscomOpePtrDat,
				"SqlPersonaRegistrada%SqlTelefonos%",
				lchrArrSqlPersona,
				lchrArrSqlTelefonos);
}

int SqlRFCRegistradoBaseDatos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrSqlPersona[1024],
	lchrArrBuffer[1024];
sprintf(lchrArrSqlPersona,
	"select * 		\n\
	 from rfcbasedatos	\n\
	 where rfc='%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDat));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
				pSiscomOpePtrDat,
				"RFCRegistradoBaseDatos%",
				lchrArrSqlPersona);
}

void InsertToPersonas(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
const char *lchrPtrRFC=SiscomObtenCampoRegistroProLChar("RFC",pSiscomRegProLPtrEnt);
lchrPtrRFC=lchrPtrRFC ? lchrPtrRFC : "" ;
sprintf(pchrPtrSql,
	"insert into Personas values(%s,'%s','%s','%s','%s');",
	 SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Nombre",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("APaterno",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("AMaterno",pSiscomRegProLPtrEnt),
	 lchrPtrRFC);
}

void UpdatePersonas(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Personas set nombre='%s',apaterno='%s',amaterno='%s',rfc='%s' where idpersona=%s;",
	 SiscomObtenCampoRegistroProLChar("Nombre",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("APaterno",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("AMaterno",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("RFC",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt));
}
void UpdateRFC(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Personas set rfc='%s' where idpersona=%s;",
	 SiscomObtenCampoRegistroProLChar("RFC",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt));
}
void InsertToClientes(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Clientes values(%s);",
	 SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt));
}



