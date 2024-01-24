#include <SqlCotizacionImportacion.h>

#include <SiscomInsercionesSql.h>

#include <SiscomDesarrolloMacros.h>
#include <stdio.h>

int SqlDetalleCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"select a.*,b.peso						\n\
	 from DetalleCotizacionImportacion as a inner join		\n\
	      PesoProducto as b using(cveproducto)			\n\
	 where IdCotizacion=%s						\n\
	 order by numeroproducto",
SiscomCampoAsociadoEntradaOperacion("Envio","IdCotizacion",pSiscomOpePtrDato));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "DetalleCotizacionImportacion%",
		   lchrArrSql);
return 0;
}

int SqlCotizacionesImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"											\n\
	select	b.*,									\n\
		a.*,										\n\
		c.*										\n\
	from cotizacionimportacion as a inner join 						\n\
     	     empresas as b on a.idproveedor=b.idempresa inner join				\n\
             TotalesCotizacionImportacion as c on a.idcotizacionimportacion=c.idcotizacion");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "CotizacionImportacion%",
		   lchrArrSql);

return 0;


}
int SqlRegistraCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];

SiscomAgregaSentenciasSqlDelAsociado("SqlCotizacionImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToCotizacionImportacion);


SiscomAgregaSentenciasSqlDelAsociado("SqlCotizacionImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToTotalesCotizacionImportacion);
SiscomEnviaRegistrosAlServidorBD("SqlCotizacionImportacion",
			       lchrArrBuffer,
			       pSiscomOpePtrDato);
return 0;
}



int SqlAnexaProductoCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlCotizacionImportacion",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     DeleteFromDetalleCotizacionImportacion);
SiscomAgregaSentenciasSqlCampoAsociado("SqlCotizacionImportacion",
                                        "Envio",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        InsertToDetalleCotizacionImportacion);
SiscomAgregaSentenciasSqlDelAsociado("SqlCotizacionImportacion",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     UpdateTotalesCotizacionImportacion);

SiscomEnviaRegistrosAlServidorBD("SqlCotizacionImportacion",
			       lchrArrBuffer,
			       pSiscomOpePtrDato);
return 0;
}


void InsertToCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CotizacionImportacion values(%s,%s,'%s',%s,0,0);",
SiscomObtenCampoRegistroProLChar("IdCotizacion",pSiscomRegProLPtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Proveedor","idempresa",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Cotizacion",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoDolar",pSiscomRegProLPtrDato));
}

void InsertToTotalesCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into TotalesCotizacionImportacion values(%s,0,0);",
SiscomObtenCampoRegistroProLChar("IdCotizacion",pSiscomRegProLPtrDato));
}

void InsertToDetalleCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleCotizacionImportacion(IdCotizacion,CveProducto,Cantidad,Precio,PesoTotal,Importe)  values(%s,'%s',%s,%s,%s,%s);",
SiscomCampoAsociadoEntradaOperacion("Envio","IdCotizacion",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("Precio",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("PesoTotal",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("Importe",pSiscomRegProLPtrDato));
}

void DeleteFromDetalleCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from DetalleCotizacionImportacion where idcotizacion=%s;",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdCotizacion",pSiscomOpePtrDato));
}

void UpdateTotalesCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update TotalesCotizacionImportacion set Peso=%s,Importe=%s where idCotizacion=%s;",
	SiscomCampoAsociadoEntradaOperacion("Envio","PesoTotal",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","ImporteTotal",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdCotizacion",pSiscomOpePtrDato));
}
