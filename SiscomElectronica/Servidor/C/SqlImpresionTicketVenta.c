#include <SqlImpresionTicketVenta.h>
#include <SiscomInsercionesSql.h>
#include <SiscomMacrosOperaciones.h>
#include <stdio.h>
int SqlPuntosVentaImpresoras(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
const char *lchrPtrSqlMaquinas="select * 					\n\
			       from impresorapuntoventa inner join 		\n\
			            impresoras using(idimpresora) inner join 	\n\
				     puntosventa using(idpuntoventa);		\n\
				";
SiscomConsultaSqlAArgumentoOperaciones(lchrPtrSqlMaquinas,
				       "SqlImpresoras",
				       lchrArrBuffer,
				       pSiscomOpePtrDato);
return 0;
}

int SqlDireccionExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
char lchrArrSql[128];
sprintf(lchrArrSql,
	"select * 		\n\
	 from direcciones	\n\
	 where idempresa=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato));
SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
				       "SqlDirExpendio",
				       lchrArrBuffer,
				       pSiscomOpePtrDato);
return 0;
}

int SqlTelefonosExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
char lchrArrSql[128];
sprintf(lchrArrSql,
	"select * 		\n\
	 from telefonos 	\n\
	 where idempresa=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato));
SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
				       "SqlTelefonos",
				       lchrArrBuffer,
				       pSiscomOpePtrDato);
return 0;
}
int SqlEnviaRegistroImpresionTicket(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomEnviaRegistrosAlServidorBD("SqlImpresionTicket",
			       lchrArrBuffer,
			       pSiscomOpePtrDato);

return 0;
}
int SqlImpresionTicket(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];

SiscomAgregaSentenciasSqlDelAsociado("SqlImpresionTicket",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToTicketImpreso);
return 0;
}

int SqlImpresionesTicket(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];

SiscomAgregaSentenciasSqlDelAsociado("SqlImpresionTicket",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToImpresionesTicket);
return 0;
}

int SqlImpresionesTicketTotal(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlImpresionTicket",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToImpresionesTicketTotal);
return 0;
}

int SqlImpresionTicketHistorial(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
  SiscomAgregaSentenciasSqlCampoAsociado("SqlImpresionTicket",
  					 "Envio",
					 "Productos",
					 lchrArrBuffer,
					 lchrArrSql,
					 pSiscomOpePtrDato,
					 InsertToImpresionTicketHistorial);
return 0;
}
void InsertToTicketImpreso(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{

sprintf(pchrPtrSql,
        "insert into TicketImpreso values(%s,%s,'%s');",
	"120",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDato));
}


void InsertToImpresionesTicket(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{

sprintf(pchrPtrSql,
        "insert into ImpresionesTicket values(%s,%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdImpresion",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDato));
}

void InsertToImpresionesTicketTotal(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{

sprintf(pchrPtrSql,
        "insert into ImpresionTicketTotal values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdImpresion",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Importe",pSiscomRegProLPtrDato));
}

void InsertToImpresionTicketHistorial(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ImpresionTicketHistorial values(%s,%s,'%s',%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdImpresion",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Importe",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Precio",pSiscomRegProLPtrDato));

}
