#include <SqlFolio.h>


#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>


int SqlRegistraFolio(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
const char *lchrPtrIdTienda;
SiscomRegistroProL *lSisRegProLPtrDat;

lchrPtrIdTienda=SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDat);
SiscomAgregaArgumentoInsercionSql("SqlFolio",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlFolio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToFolio);
SiscomAgregaSentenciasSqlDelAsociado("SqlFolio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateFolioActual);

SiscomReplicaMaquinaLocal("SqlFolio", lchrArrBuffer, 0, pSiscomOpePtrDat);

SiscomReplicaMaquinaSistema(lchrPtrIdTienda,
			    "SqlFolio",
			    lchrArrBuffer,
			    gSiscomRegProLPtrMemoria,
			    0,
			    pSiscomOpePtrDat);

}

void InsertToFolio(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Folios values(%s,%s,%s,%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdFolio",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdTienda",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdTipoFolio",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Inicio",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fin",pSiscomRegProLPtrEnt));
}

void UpdateFolioActual(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update folioactual set folio=%s where idtipofolio=%s;",
	 SiscomObtenCampoRegistroProLChar("Inicio",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdTipoFolio",pSiscomRegProLPtrEnt));
}

int SqlFolioActual(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512],
	lchrArrSqlFolioTienda[128];
const char *lchrPtrIdTipoFolio=SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoFolio",pSiscomOpePtrDat);
sprintf(lchrArrSql,
"select folio+1 as folio				\n\
 from folioactual 					\n\
 where idtipofolio=%s",
   lchrPtrIdTipoFolio);

sprintf(lchrArrSqlFolioTienda,
        "select * 				\n\
	 from folios inner join 		\n\
	 	tienda using(idtienda)		\n\
	 where idtipofolio=%s",
	 lchrPtrIdTipoFolio);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "FolioActual%FolioTienda%",
			     lchrArrSql,
			     lchrArrSqlFolioTienda);
}
