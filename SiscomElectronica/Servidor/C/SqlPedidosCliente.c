#include <SqlPedidosCliente.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <SqlOrdenes.h>
#include <stdio.h>

int SqlActualizaEstadoPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlClientePedido",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToPedidoCliente);

SiscomAgregaSentenciasSqlDelAsociado("SqlClientePedido",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     UpdateFromEstadosPedidoCliente);


SiscomEnviaRegistrosAlServidorBD("SqlClientePedido",lchrArrBuffer,pSiscomOpePtrDato);
return 0;

}


int SqlConsultaEstadosPedidosCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"select * from  estadospedido");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "EstadosPedidosCliente%",
		   lchrArrSql);
}



void UpdateFromEstadosPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"update EstadosPedidoCliente set idestado=%s where idventa=%s" ,
        SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato));
}
