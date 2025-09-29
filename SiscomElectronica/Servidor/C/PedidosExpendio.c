#include <PedidosExpendio.h>
#include <Facturando4.h>

#include <SqlPedidosExpendio.h>

#include <Facturando4.h> 

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>

void TransfiereBodegaExpendioParaPedido(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSisOpErrValExi={0,
					ERRORCantidadVsExBodega,
					0};
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoIniciaPedidoExpendio,&lSiscomProDat); 
SiscomAgregaOperacion(AgregaFecha,&lSiscomProDat); 
SiscomAgregaOperacion(ArgumentoExistenciaExpendioBodegaProducto,&lSiscomProDat); 
SiscomAgregaOperacion(SqlExistenciaExpendioBodegaProducto,&lSiscomProDat); 
SiscomAgregaOperacion(ValidaExistenciaBodegaVsCantidad,&lSiscomProDat); 
SiscomAgregaOperacion(SqlTransfiereBodegaExpendioParaPedido,&lSiscomProDat); 
SiscomAgregaOperacion(SqlExistenciaExpendioBodegaProducto,&lSiscomProDat); 
SiscomAgregaOperacion(ActualizandoInventarioParaPedido,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSisOpErrValExi,lSiscomProDat);


}
void ActualizaInventarioParaPedido(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoIniciaPedidoExpendio,&lSiscomProDat); 
SiscomAgregaOperacion(AgregaFechaSinHora,&lSiscomProDat); 
SiscomAgregaOperacion(SqlActualizaInventarioParaPedido,&lSiscomProDat);
SiscomAgregaOperacion(ActualizandoInventarioParaPedido,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void PedidoExpendioHoy(int pintSocket,
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
SiscomAgregaOperacion(AgregaFechaSinHora,&lSiscomProDat);
SiscomAgregaOperacion(SqlPedidoExpendioHoy,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoPedidoExpendioHoy,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void IniciaPedidoExpendioHoy(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoIniciaPedidoExpendio,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFecha,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdPedidoExpendio,&lSiscomProDat);
SiscomAgregaOperacion(SqlIniciandoPedidoExpendioHoy,&lSiscomProDat);
SiscomAgregaOperacion(EnviaInicioPedidoExpendioHoy,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ProductoAPedidoExpendio(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoIniciaPedidoExpendio,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdProducto,&lSiscomProDat);
SiscomAgregaOperacion(SqlProductoAPedidoExpendio,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoProductoPedidoExpendio,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void EliminaProductoPedido(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoIniciaPedidoExpendio,&lSiscomProDat);
SiscomAgregaOperacion(SqlEliminaProductoPedido,&lSiscomProDat);
SiscomAgregaOperacion(EnviaInicioPedidoExpendioHoy,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ActualizaProductoPedido(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoIniciaPedidoExpendio,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaProductoPedido,&lSiscomProDat);
SiscomAgregaOperacion(EnviaInicioPedidoExpendioHoy,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void ActualizaObservacionesPedido(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoIniciaPedidoExpendio,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaObservacionesPedido,&lSiscomProDat);
SiscomAgregaOperacion(EnviaInicioPedidoExpendioHoy,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



void RegistraPedido(int pintSocket,
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
SiscomAgregaOperacion(SqlServidoresSiscom,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoServidores,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoPedidoExpendioAMatriz,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoEstadoPedidoExpendioProducto,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraPedido,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaPedidoMatriz,&lSiscomProDat);
SiscomAgregaOperacion(SqlEstadoPedidoExpendioProducto,&lSiscomProDat);
SiscomAgregaOperacion(EnviaRegistroPedido,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviandoPedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];

if(SiscomObtenRegistrosCampoRespuesta("PedidoExpendio",pSiscomOpePtrDato))
{
  SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer); 
}
else
{
   pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
   pSiscomOpePtrDato->SiscomRegProLPtrActRes=0;
  SiscomFormaEnviaRegistroRespuesta(pSiscomOpePtrDato,
  				   lchrArrBuffer,
				   "Estado,Mensaje,",
				   "0",
				   "Sin Pedido Hoy");
   LogSiscom("NO Se encontro informacion del pedido para el expendio");
}
return 0;
}

int EnviaInicioPedidoExpendioHoy(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadosArgumentoLog("SqlIniciaPedidoExpendio",
                              "SentenciasSql",
                              lchrArrBuffer,
                              pSiscomOpePtrDato);
}
int EnviandoProductoPedidoExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadosArgumentoLog("SqlIniciaPedidoExpendio",
                              "SentenciasSql",
                              lchrArrBuffer,
                              pSiscomOpePtrDato);
}

int EnviaRegistroPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
SiscomAsociadosArgumentoLog("SqlIniciaPedidoExpendio",
                              "SentenciasSql",
                              lchrArrBuffer,
                              pSiscomOpePtrDato);
}

int AgregaFechaSinHora(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaCampoAsociadoEntrada("Fecha",0,"Envio",pSiscomOpePtrDato);
SiscomAsignaFechaAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
return 0;
}

int ArgumentoIniciaPedidoExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlIniciaPedidoExpendio",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}
int ArgumentoPedidoExpendioAMatriz(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
int lintPuertoMatriz;
const char *lchrPtrDirIpMatriz,
	   *lchrPtrBaseDatosMatriz;
SiscomServidorPorTipoMaquina("Matriz",
			     pSiscomOpePtrDato->SiscomRegProLPtrPrimRes,
			     &lintPuertoMatriz,
			     &lchrPtrDirIpMatriz,
			     &lchrPtrBaseDatosMatriz);
SiscomAgregaArgumentoInsercionSql("SqlPedidoExpendioAMatriz",
				  lchrPtrBaseDatosMatriz,
				  "",
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}

int ArgumentoServidores(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlServidoresSiscom",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}

int ArgumentoEstadoPedidoExpendioProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlEstadoPedidoExpendioProducto",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}
int ArgumentoExistenciaExpendioBodegaProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlExistenciaExpendioBodegaProducto",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}


int GeneraIdPedidoExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaCampoAsociadoEntrada("IdPedido",0,"Envio",pSiscomOpePtrDato);
SiscomIdARegistrosAsociadosEntrada("Envio","IdPedido",pSiscomOpePtrDato);
return 0;
}
int GeneraIdProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdProducto",pSiscomOpePtrDato);
return 0;
}
int ActualizandoInventarioParaPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlIniciaPedidoExpendio",
                              "SentenciasSql",
                              lchrArrBuffer,
                              pSiscomOpePtrDato);
return 0;
}


int ValidaExistenciaBodegaVsCantidad(SiscomOperaciones *pSisOpePtrDato)
{
float lfltCantidad,
	lfltExistenciaBodega=atof(SiscomCampoArgumentoPrim("SqlExistenciaExpendioBodegaProducto",
							   "exbodegas",
							   pSisOpePtrDato));
char lchrArrBuffer[256];
  SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
  SiscomArgumentoLog("SqlExistenciaExpendioBodegaProducto",lchrArrBuffer,pSisOpePtrDato);
  lfltCantidad=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Cantidad",pSisOpePtrDato);
  if(lfltCantidad<=lfltExistenciaBodega)
  return 0;
  else
  {
   LogSiscom("La Cantidad es mas grande que la existencia en bodega");
  return 1;
  }
}
int ERRORCantidadVsExBodega(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[1024];
const char *lchrPtrExistenciaBodega,
	   *lchrPtrExistenciaExp,
	   *lchrPtrCveProducto;

lchrPtrExistenciaBodega=SiscomCampoArgumentoPrim("SqlExistenciaExpendioBodegaProducto",
				   			    "exbodegas",
							    pSisOpePtrDato);
lchrPtrExistenciaExp=SiscomCampoArgumentoPrim("SqlExistenciaExpendioBodegaProducto",
					      "existencia",
					      pSisOpePtrDato);

lchrPtrCveProducto=SiscomCampoArgumentoPrim("SqlExistenciaExpendioBodegaProducto",
					     "cveproducto",
					     pSisOpePtrDato);

 SiscomFormaEnviaRegistroRespuesta(pSisOpePtrDato,
 				  lchrArrBuffer,
				  "Error,Descripcion,Estado,CveProducto,ExistenciaB,ExistenciaE,",
				  (const char *)0,
				  "Existencia en bodega es menor que la cantidad solicitada\n"
				  "Se asignara la existencia actual de bodega!!",
				  "1",
				   lchrPtrCveProducto,
				   lchrPtrExistenciaBodega,
				   lchrPtrExistenciaExp);
  LogSiscom("Se detecto error al validar la existencia ");

return 1;
}
