#include <SqlReferenciasPersonales.h>
#include <SqlDirecciones.h>
#include <SqlEmpleo.h>
#include <SqlPersonas.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include  <stdio.h>
int SqlInsertaReferenciasPersonales(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlReferenciasPersonales",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlDelAsociado("SqlReferenciasPersonales",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToReferenciaPersonal);
InsertToPersonaReferencia(pSiscomOpePtrDat);
SiscomReplicaMaquinaLocal("SqlReferenciasPersonales", lchrArrBuffer, 0, pSiscomOpePtrDat);    
return 0;
} 

void InsertToReferenciaPersonal(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ReferenciaPersonal values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdReferencia",pSiscomRegProLPtrEnt),
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtr));
}
void InsertToPersonaReferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],lchrArrSql[256];
SiscomRegistroProL *lSisRegProLPtrActSql,
		   *lSisRegProLPtrPersonas,
		   *lSisRegProLPtrParentescos,
		   *lSisRegProLPtrDirecciones,
		   *lSisRegProLPtrTelefonos,
		   *lSisRegProLPtrNumeros;
int lintNombreVacio;
lSisRegProLPtrActSql=SiscomObtenArgumentoActOperaciones("SqlReferenciasPersonales",
							pSiscomOpePtrDato);	
lSisRegProLPtrPersonas=SiscomRegistrosAsociadosCampoEntrada("Envio","Nombres",pSiscomOpePtrDato);
lSisRegProLPtrParentescos=SiscomRegistrosAsociadosCampoEntrada("Envio","Parentesco",pSiscomOpePtrDato);
lSisRegProLPtrDirecciones=SiscomRegistrosAsociadosCampoEntrada("Envio","Direcciones",pSiscomOpePtrDato);
lSisRegProLPtrTelefonos=SiscomRegistrosAsociadosCampoEntrada("Envio","Telefonos",pSiscomOpePtrDato);
while(lSisRegProLPtrPersonas)
{
lSisRegProLPtrNumeros=SiscomObtenRegistrosCampoProL("Telefonos",lSisRegProLPtrTelefonos);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrNumeros);
lintNombreVacio=SiscomCampoRegistroProLCharEsVacio("Nombre",lSisRegProLPtrPersonas);
if(lintNombreVacio==0)
{
sprintf(lchrArrSql,
	"insert into personas values(%s,'%s','%s','%s','%s');",
	 SiscomObtenCampoRegistroProLChar("IdPersona",lSisRegProLPtrPersonas),
	 SiscomObtenCampoRegistroProLChar("Nombre",lSisRegProLPtrPersonas),
	 SiscomObtenCampoRegistroProLChar("APaterno",lSisRegProLPtrPersonas),
	 SiscomObtenCampoRegistroProLChar("AMaterno",lSisRegProLPtrPersonas),
	 SiscomObtenCampoRegistroProLChar("RFC",lSisRegProLPtrPersonas));

SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     lSisRegProLPtrActSql,
			     lchrArrBuffer,
			     "Sql,Estado,",
			     lchrArrSql,
			     (char *)0);
}
sprintf(lchrArrSql,
	"insert into PersonaReferencia values(%s,%s,'%s');",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdReferencia",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("IdPersona",lSisRegProLPtrPersonas),
	 SiscomObtenCampoRegistroProLChar("Parentesco",lSisRegProLPtrParentescos));
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     lSisRegProLPtrActSql,
			     lchrArrBuffer,
			     "Sql,Estado,",
			     lchrArrSql,
			     (char *)0);

if(lintNombreVacio==0)
{
sprintf(lchrArrSql,
	"insert into Direcciones values(%s,'%s','%s','%s','%s','%s','%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdDireccion",lSisRegProLPtrDirecciones),
	SiscomObtenCampoRegistroProLChar("Calle",lSisRegProLPtrDirecciones),
	SiscomObtenCampoRegistroProLChar("NumInterior",lSisRegProLPtrDirecciones),
	SiscomObtenCampoRegistroProLChar("NumExterior",lSisRegProLPtrDirecciones),
	SiscomObtenCampoRegistroProLChar("Colonia",lSisRegProLPtrDirecciones),
	SiscomObtenCampoRegistroProLChar("DelegMunic",lSisRegProLPtrDirecciones),
	SiscomObtenCampoRegistroProLChar("Estado",lSisRegProLPtrDirecciones),
	SiscomObtenCampoRegistroProLChar("CodigoPostal",lSisRegProLPtrDirecciones),
	SiscomObtenCampoRegistroProLChar("Referencias",lSisRegProLPtrDirecciones));
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     lSisRegProLPtrActSql,
			     lchrArrBuffer,
			     "Sql,Estado,",
			     lchrArrSql,
			     (char *)0);
}
sprintf(lchrArrSql,
	"insert into DireccionesReferencia values(%s,%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdReferencia",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("IdPersona",lSisRegProLPtrPersonas),
	 SiscomObtenCampoRegistroProLChar("IdDireccion",lSisRegProLPtrDirecciones));
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     lSisRegProLPtrActSql,
			     lchrArrBuffer,
			     "Sql,Estado,",
			     lchrArrSql,
			     (char *)0);

if(lintNombreVacio==0)
{
sprintf(lchrArrSql,
	"insert into Telefonos values(%s,'%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdTelefono",lSisRegProLPtrNumeros),
	SiscomObtenCampoRegistroProLChar("Telefono",lSisRegProLPtrNumeros),
	SiscomObtenCampoRegistroProLChar("Descripcion",lSisRegProLPtrNumeros),
	SiscomObtenCampoRegistroProLChar("Extension",lSisRegProLPtrNumeros));
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     lSisRegProLPtrActSql,
			     lchrArrBuffer,
			     "Sql,Estado,",
			     lchrArrSql,
			     (char *)0);
}
sprintf(lchrArrSql,
	"insert into TelefonoReferencia values(%s,%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdReferencia",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("IdPersona",lSisRegProLPtrPersonas),
	SiscomObtenCampoRegistroProLChar("IdTelefono",lSisRegProLPtrNumeros));
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     lSisRegProLPtrActSql,
			     lchrArrBuffer,
			     "Sql,Estado,",
			     lchrArrSql,
			     (char *)0);

lSisRegProLPtrPersonas=lSisRegProLPtrPersonas->SiscomRegProLPtrSig;
lSisRegProLPtrParentescos=lSisRegProLPtrParentescos->SiscomRegProLPtrSig;
lSisRegProLPtrDirecciones=lSisRegProLPtrDirecciones->SiscomRegProLPtrSig;
lSisRegProLPtrTelefonos=lSisRegProLPtrTelefonos->SiscomRegProLPtrSig;
}
}

void InsertToTelefonosReferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],lchrArrSql[256];
SiscomRegistroProL *lSisRegProLPtrActSql,
		   *lSisRegProLPtrTelefonos,
		   *lSisRegProLPtrNumeros;
lSisRegProLPtrActSql=SiscomObtenArgumentoActOperaciones("SqlReferenciasPersonales",
							 pSiscomOpePtrDato);

lSisRegProLPtrTelefonos=SiscomRegistrosAsociadosCampoEntrada("Envio","Telefonos",pSiscomOpePtrDato);
while(lSisRegProLPtrTelefonos)
{
lSisRegProLPtrNumeros=SiscomObtenRegistrosCampoProL("Telefonos",lSisRegProLPtrTelefonos);
sprintf(lchrArrSql,
	"insert into telefonos values(%s,'%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdTelefono",lSisRegProLPtrNumeros),
	SiscomObtenCampoRegistroProLChar("Telefono",lSisRegProLPtrNumeros),
	SiscomObtenCampoRegistroProLChar("Descripcion",lSisRegProLPtrNumeros),
	SiscomObtenCampoRegistroProLChar("Extension",lSisRegProLPtrNumeros));
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     lSisRegProLPtrActSql,
			     lchrArrBuffer,
			     "Sql,Estado,",
			     lchrArrSql,
			     (char *)0);
 sprintf(lchrArrSql,
 	 "insert into telefonoreferencia values(%s,%s)",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdReferencia",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("IdTelefono",lSisRegProLPtrNumeros));
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     lSisRegProLPtrActSql,
			     lchrArrBuffer,
			     "Sql,Estado,",
			     lchrArrSql,
			     (char *)0);

lSisRegProLPtrTelefonos=lSisRegProLPtrTelefonos->SiscomRegProLPtrSig;
}
}

void InsertToDireccionesReferencia(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DireccionesReferencia values(%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdReferencia",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("IdDireccion",pSiscomRegProLPtrEnt));
}
