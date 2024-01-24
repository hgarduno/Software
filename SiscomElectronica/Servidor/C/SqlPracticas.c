#include <SqlPracticas.h>
#include <SiscomInsercionesSql.h>
#include <SiscomDesarrolloMacros.h>

int SqlPracticaRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSqlDefProducto[256],
     lchrArrSqlPractica[256],
     lchrArrSqlProfesor[256];

SqlDefinicionTipoProductoPractica(pSiscomOpePtrDato,lchrArrSqlDefProducto);
SqlDatosPractica(pSiscomOpePtrDato,lchrArrSqlPractica);
SqlDatosProfesor(pSiscomOpePtrDato,lchrArrSqlProfesor);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "DefProducto%Practica%Profesor%",
		   lchrArrSqlDefProducto,
		   lchrArrSqlPractica,
		   lchrArrSqlProfesor);

}

void SqlDatosPractica(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 		\n\
	 from practica2		\n\
	 where idproducto=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","idproducto",pSiscomOpePtrDato));


}
void SqlDefinicionTipoProductoPractica(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 				\n\
	 from definiciontiposproducto 		\n\
	 where idproducto=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","idproducto",pSiscomOpePtrDato));
}
void SqlDatosProfesor(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
        "select b.*				\n\
	 from profesor as a inner join 		\n\
	      personas as b using(idpersona)	\n\
	 where idproducto=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","idproducto",pSiscomOpePtrDato));
}
    
int SqlPractica(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlPractica",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToPractica);
	
return 0;
}

int SqlProductoPorTipoProductoPractica(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlPractica",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToProductoPorTipoProductoPractica);
return 0;
}

void InsertToPractica(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSisRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Practicas values('%s','%s','%s',%s,%s);",
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Producto","cveproducto",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Nombre",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Materia",pSisRegProLPtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Escuela","idescuela",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("IdProducto",pSisRegProLPtrDato));
}

void InsertToProductoPorTipoProductoPractica(SiscomOperaciones *pSiscomOpePtrDato,
		      			     SiscomRegistroProL *pSisRegProLPtrDato,
		      			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"insert into ProductoPorTipoProducto values('%s',1,%s);",
   SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Producto","cveproducto",pSiscomOpePtrDato),
   SiscomObtenCampoRegistroProLChar("IdProducto",pSisRegProLPtrDato));
}
