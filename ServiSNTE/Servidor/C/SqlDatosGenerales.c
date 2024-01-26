#include <SqlDatosGenerales.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include  <stdio.h>
int SqlInsertaGeneralesCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlDatosGenerales",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlDelAsociado("SqlDatosGenerales",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToDatosNacimiento);

SiscomAgregaSentenciasSqlDelAsociado("SqlDatosGenerales",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToIdentificacion);

SiscomAgregaSentenciasSqlDelAsociado("SqlDatosGenerales",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToOtrosDatosPersonales);
SiscomReplicaMaquinaLocal("SqlDatosGenerales", lchrArrBuffer, 0, pSiscomOpePtrDat);
return 0;
}
int SqlActualizaGeneralesCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlDatosGenerales",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlDelAsociado("SqlDatosGenerales",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateDatosNacimiento);

SiscomAgregaSentenciasSqlDelAsociado("SqlDatosGenerales",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateIdentificacion);

SiscomAgregaSentenciasSqlDelAsociado("SqlDatosGenerales",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateOtrosDatosPersonales);
SiscomReplicaMaquinaLocal("SqlDatosGenerales", lchrArrBuffer, 0, pSiscomOpePtrDat);
return 0;
}


void InsertToDatosNacimiento(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DatosNacimiento values(%s,'%s','%s','%s','%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("CURP",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("EstadoNacimiento",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("PaisNacimiento",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Genero",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("FechaNacimiento",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Nacionalidad",pSiscomRegProLPtrEnt));
}

void UpdateDatosNacimiento(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"update DatosNacimiento 			\n\
	        set  curp='%s' ,			\n\
		     estado='%s',			\n\
		     pais='%s',				\n\
		     sexo='%s' ,			\n\
		     fecha='%s',			\n\
		     nacionalidad='%s'			\n\
	  where idpersona=%s",
	SiscomObtenCampoRegistroProLChar("CURP",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("EstadoNacimiento",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("PaisNacimiento",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Genero",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("FechaNacimiento",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Nacionalidad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt));
}

void InsertToIdentificacion(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Identificacion values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Identificacion",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("NoIdentificacion",pSiscomRegProLPtrEnt));
}
void UpdateIdentificacion(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Identificacion			\n\
	        set Identificacion='%s' , 	\n\
		    NoIdentificacion='%s'	\n\
	 where idpersona=%s",
	SiscomObtenCampoRegistroProLChar("Identificacion",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("NoIdentificacion",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt));

}

void InsertToOtrosDatosPersonales(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into OtrosDatosPersonales values(%s,'%s','%s',%s);",
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Ocupacion",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("EstadoCivil",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Edad",pSiscomRegProLPtrEnt));
}

void UpdateOtrosDatosPersonales(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update OtrosDatosPersonales	\n\
	        set ocupacion='%s' ,	\n\
		    estadocivil='%s',	\n\
		    edad=%s 		\n\
	 where idpersona=%s",
	SiscomObtenCampoRegistroProLChar("Ocupacion",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("EstadoCivil",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Edad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt));
}
