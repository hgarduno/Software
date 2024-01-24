#include <PedidosCliente.h>
#include <SqlPedidosCliente.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <SiscomMacrosOperaciones.h>

#include <ComunSiscomElectronica4.h>
#include <string.h>
void EstadosPedidosCliente(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlConsultaEstadosPedidosCliente,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoEstadosPedidosCliente,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ActualizaEstadoPedidoCliente(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(AgregaArgumentosEstadoPedidoCliente,&lSiscomProDat);
SiscomAgregaOperacion(FechaHoraCambioEstado,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaEstadoPedidoCliente,&lSiscomProDat);
SiscomAgregaOperacion(EnviaActualizaEstadoPedidoCliente,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviandoEstadosPedidosCliente(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[128];
SiscomEnviaAsociadoRespuestaCliente("EstadosPedidosCliente",
				    lchrArrBuffer,
				    pSisOpePtrDatos);

return 0;
}
int EnviaActualizaEstadoPedidoCliente(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[128];
LogSiscom("Actualizando el estado del pedido");
SiscomAsociadosArgumentoLog("SqlClientePedido","SentenciasSql",lchrArrBuffer,pSisOpePtrDatos);
return 0;
}

int FechaHoraCambioEstado(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAsignaFechaHoraAsociadoEntrada("Envio","FechaHora",pSiscomOpePtrDato);
return 0;
}
int AgregaArgumentosEstadoPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAgregaArgumentoInsercionSql("SqlClientePedido",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}

