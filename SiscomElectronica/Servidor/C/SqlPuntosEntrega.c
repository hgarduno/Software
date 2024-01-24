
#include <SqlPuntosEntrega.h>
#include <SiscomInsercionesSql.h>
#include <stdio.h>

int SqlRegistrandoPuntoEntrega(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],lchrArrSql[250];
SiscomAgregaSentenciasSqlDelAsociado("SqlPuntoEntrega",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSisOpePtrDato,
				     InsertToPuntoEntrega);
SiscomAgregaSentenciasSqlCampoAsociado("SqlPuntoEntrega",
					"Envio",
					"Direccion",
					lchrArrBuffer,
					lchrArrSql,
					pSisOpePtrDato,
					InsertIntoToDireccionesPuntosEntrega);

SiscomEnviaRegistrosAlServidorBD("SqlPuntoEntrega",
 				  lchrArrBuffer,
				  pSisOpePtrDato);
return 0;
}
int SqlPuntosEntrega(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[512],lchrArrSql[512];
SqlConsultaPuntosEntrega(pSisOpePtrDato,lchrArrSql);
SiscomConsultasSqlOperaciones(lchrArrBuffer,pSisOpePtrDato,"SqlPuntosEntrega%",lchrArrSql);
return 0;
}
void InsertToPuntoEntrega(SiscomOperaciones *pSisOpePtrDato,
		      SiscomRegistroProL *pSisRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into PuntosEntrega values(%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdPuntoEntrega",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("PuntoEntrega",pSisRegProLPtrDato));
}

void InsertIntoToDireccionesPuntosEntrega(SiscomOperaciones *pSisOpePtrDato,
					 SiscomRegistroProL *pSisRegProLPtrDato,
					 char *pchrPtrSql)
{
const char *lchrPtrNumInterior;
lchrPtrNumInterior=SiscomObtenCampoRegistroProLChar("NumeroInt",pSisRegProLPtrDato);
sprintf(pchrPtrSql,
	"insert into Direcciones values(0,%s,'%s','%s','%s',%s,'%s','%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdDireccion",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Calle",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Numero",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Colonia",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("CP",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Delegacion",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Estado",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Referencias",pSisRegProLPtrDato),
	lchrPtrNumInterior ? lchrPtrNumInterior : "");

}
void SqlConsultaPuntosEntrega(SiscomOperaciones *pSisOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select a.idpuntoentrega, 					\n\
	        a.nombre,						\n\
		b.idempresa as iddireccion,				\n\
		b.calle,						\n\
		b.numero,						\n\
		b.colonia,						\n\
		b.cp,							\n\
		b.municipio,						\n\
		b.estado,						\n\
		b.referencias,						\n\
		b.numext						\n\
	 from  PuntosEntrega as a inner join 				\n\
	       direcciones as b on (a.idpuntoentrega=b.idempresa)");

}
