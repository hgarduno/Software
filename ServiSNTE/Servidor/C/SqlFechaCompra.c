#include <SqlFechaCompra.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlRegistraFechaCompra(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaFechaCompra",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaFechaCompra",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToFijaFechaCompra);
SiscomReplicaMaquinaLocal("SqlInsertaFechaCompra", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlFechaCompraProveedor(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
     lchrArrSql[256];

sprintf(lchrArrSql,
	"select *			\n\
	 from fijafechacompra		\n\
	 where idproveedor=%s and 		\n\
	 	fechahoy='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDat),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaHoy", pSiscomOpePtrDat));
LogSiscom("%s",lchrArrSql);	
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "FechaCompraProveedor%",
			      lchrArrSql);
SiscomRegistrosAsociadosLog(lchrArrBuffer,
			    "FechaCompraProveedor",
			    pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  



}
void InsertToFijaFechaCompra(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into FijaFechaCompra values(%s,'%s','%s');",
	 SiscomObtenCampoRegistroProLChar("IdProveedor",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("FechaHoy",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("FechaCompra",pSiscomRegProLPtrEnt));
}
