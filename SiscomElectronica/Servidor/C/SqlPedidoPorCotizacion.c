#include <SqlPedidoPorCotizacion.h>
#include <stdlib.h>
#include <string.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>


int SqlPedidoPorCotizacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlPedidoPC",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToPedidosMaterialPC);

SiscomAgregaSentenciasSqlCampoAsociado("SqlPedidoPC",
				       "Envio",
				       "Productos",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDato,
				       InsertToDetallePedidosMaterialPC);

SiscomAgregaSentenciasSqlDelAsociado("SqlPedidoPC",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToEstadoPedidoMaterialPC);


SiscomAgregaSentenciasSqlDelAsociado("SqlPedidoPC",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToUltimoEstadoPedidoMaterialPC);
 SiscomEnviaRegistrosAlServidorBD("SqlPedidoPC",
 				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}


void InsertToPedidosMaterialPC(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into PedidosMaterial values(%s,'%s','%s',%s);",
	SiscomObtenCampoRegistroProLChar("IdPedido",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Observaciones",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdExpendio",pSiscomRegProLPtrDato));
}
void InsertToEstadoPedidoMaterialPC(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into EstadoPedidoMaterial values(0,%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdPedido",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrDato));
}

void InsertToUltimoEstadoPedidoMaterialPC(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into UltimoEstadoPedido values(%s,0);",
	SiscomObtenCampoRegistroProLChar("IdPedido",pSiscomRegProLPtrDato));
}


void InsertToDetallePedidosMaterialPC(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetallePedidoMaterial values(%s,%s,'%s','',0,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPedido",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrDato));
}
