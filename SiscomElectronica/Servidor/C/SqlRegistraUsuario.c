#include <SqlRegistraUsuario.h>
#include <SqlClientes4.h>
#include <SiscomInsercionesSql.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomReplicacion.h>
#include <stdio.h>
int SqlRegistraUsuarioSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{

char lchrArrBuffer[256],
	lchrArrSql[256];

SiscomAgregaSentenciasSqlDelAsociado("SqlCliente",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToPersonaSiscom);
SiscomAgregaSentenciasSqlDelAsociado("SqlCliente",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToFirmas);
SiscomReplicaMaquinasSistema("Servidor",
			     "SqlCliente",
			     lchrArrBuffer,
			     pSiscomOpePtrDato->SiscomRegProLPtrPrimRes,
			     0,
			     pSiscomOpePtrDato);
}

int SqlRegistraSeguridad3(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];

SiscomAgregaSentenciasSqlDelAsociado("SqlSeguridad3",
				      "Envio",
				      lchrArrBuffer,
				      lchrArrSql,
				      pSiscomOpePtrDato,
				      InsertToUsuarios);
SiscomAgregaSentenciasSqlDelAsociado("SqlSeguridad3",
				      "Envio",
				      lchrArrBuffer,
				      lchrArrSql,
				      pSiscomOpePtrDato,
				      InsertToFirmasSeguridad3);

SiscomReplicaMaquinasSistema("Servidor",
			     "SqlSeguridad3",
			     lchrArrBuffer,
			     pSiscomOpePtrDato->SiscomRegProLPtrPrimRes,
			     0,
			     pSiscomOpePtrDato);
}

void SqlDatosAplicacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[512],
	lchrArrSqlPerfil[256];
SqlFormaConsultaAplicacionSeguridad3(pSiscomOpePtrDato,lchrArrSql);
SqlFormaConsultaPerfilSeguridad3(pSiscomOpePtrDato,lchrArrSqlPerfil);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "Aplicacion%Perfil%",
			      lchrArrSql,
			      lchrArrSqlPerfil);
}
int SqlExpendiosSiscomElectronica(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];

SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "Servidores%",
			      "select a.puerto,				\n\
			              b.diripsvrad as dirip,		\n\
				      'Servidor' as tipoequipo	\n\
			       from ServidoresSiscom4  as a inner join	\n\
			       	    expendios as b using(idempresa)");
return 0;
}
void SqlFormaConsultaAplicacionSeguridad3(SiscomOperaciones *pSiscomOpePtrDato,
					  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select idaplicacion 	\n\
	 from aplicaciones 	\n\
	 where nmbaplicacion='%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Aplicacion",pSiscomOpePtrDato));
}
void SqlFormaConsultaPerfilSeguridad3(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 		\n\
	 from perfiles		\n\
	 where nmbperfil='%s';",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Perfil",pSiscomOpePtrDato));
}

void InsertToUsuarios(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Usuarios values(%s,%s,%s,'%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoRespuestaOperacion("Aplicacion","idaplicacion",pSiscomOpePtrDato),
	SiscomCampoAsociadoRespuestaOperacion("Perfil","idperfil",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Nombre",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("APaterno",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("AMaterno",pSiscomRegProLPtrDato));
}
void InsertToFirmas(SiscomOperaciones *pSiscomOpePtrDato,
		   SiscomRegistroProL *pSisRegProLPtrDato,
		   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into firmas values('%s',%s,-%s);",
	SiscomObtenCampoRegistroProLChar("Firma",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdPersona",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdExpendio",pSisRegProLPtrDato));
}
void InsertToFirmasSeguridad3(SiscomOperaciones *pSiscomOpePtrDato,
			      SiscomRegistroProL *pSiscomRegProLPtrDato,
			      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"insert into firmas values(%s,'%s','%s',1);",
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Firma",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Password",pSiscomRegProLPtrDato));
}
void InsertToPersonaSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSisRegProLPtrDato,
			   char *pchrPtrSql)
{
 sprintf(pchrPtrSql,
 	"insert into personas values('%s','%s','%s','%s',%s,%s);",
	SiscomObtenCampoRegistroProLChar("Nombre",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("APaterno",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("AMaterno",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("RFC",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdPersona",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("TipoPersona",pSisRegProLPtrDato));
}
