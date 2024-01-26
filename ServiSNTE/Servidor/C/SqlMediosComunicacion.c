#include <SqlMediosComunicacion.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include  <stdio.h>
int SqlTelefonosCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlTelefonos",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlTelefonos",
				       "Envio",
				       "Telefonos",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToTelefonos);
SiscomAgregaSentenciasSqlCampoAsociado("SqlTelefonos",
				       "Envio",
				       "Telefonos",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToTelefonoCliente);
SiscomAgregaSentenciasSqlCampoAsociado("SqlTelefonos",
				       "Envio",
				       "Correo",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToCorreo);

SiscomAgregaSentenciasSqlCampoAsociado("SqlTelefonos",
				       "Envio",
				       "Correo",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToCorreoCliente);
SiscomReplicaMaquinaLocal("SqlTelefonos", lchrArrBuffer, 0, pSiscomOpePtrDat);
return 0;
}

int SqlActualizaTelefonosCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlTelefonos",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlTelefonos",
				       "Envio",
				       "Telefonos",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateTelefonos);
SiscomAgregaSentenciasSqlCampoAsociado("SqlTelefonos",
				       "Envio",
				       "Correo",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateCorreo);
SiscomReplicaMaquinaLocal("SqlTelefonos", lchrArrBuffer, 0, pSiscomOpePtrDat);
return 0;
}
void InsertToTelefonos(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Telefonos values(%s,'%s','%s','');",
	SiscomObtenCampoRegistroProLChar("IdTelefono",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Telefono",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Descripcion",pSiscomRegProLPtrEnt));
}

void UpdateTelefonos(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Telefonos set telefono='%s', descripcion='%s' where idtelefono=%s;",
	SiscomObtenCampoRegistroProLChar("Telefono",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Descripcion",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdTelefono",pSiscomRegProLPtrEnt));
}
void InsertToTelefonoCliente(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
/* Domingo 5 de Junio 
 * Cambie el nombre del campo IdPersona, que 
 * tenia en esta funcion , por IdCliente 
 * ya que es mas general al contexto, ahora
 * hay que ver donde mas se llama esta funcion
 * Inicialmente la uso en ventas , habria 
 * que revisar si en los contratos de beneficios 
 * se llama ...
 */

sprintf(pchrPtrSql,
	"insert into TelefonoCliente values(%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdCliente",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("IdTelefono",pSiscomRegProLPtrEnt));
}

void InsertToCorreo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Correos values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdCorreo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Correo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Descripcion",pSiscomRegProLPtrEnt));
}

void UpdateCorreo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Correos set correo='%s',descripcion='%s' where idcorreo=%s;",
	SiscomObtenCampoRegistroProLChar("Correo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Descripcion",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdCorreo",pSiscomRegProLPtrEnt));
}

void InsertToCorreoCliente(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CorreoCliente values(%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("IdCorreo",pSiscomRegProLPtrEnt));
}
