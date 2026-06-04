
#include <PedidoPorCotizacion.h>
#include <SqlPedidoPorCotizacion.h>



#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomMacrosInsercionesSql.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>


void PedidoPorCotizacion(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{

SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
/*SiscomOperacionErrores lSiscomOpDatError={0,NoSeRegistraNoAlcanza,0}; */
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoPedidoPorCotizacion,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaYIdPedidoPorCotizacion,&lSiscomProDat);
SiscomAgregaOperacion(SqlPedidoPorCotizacion,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPedidoPorCotizacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaPedidoPorCotizacion(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[256];
LogSiscom("");
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDatos);
SiscomAsociadoAsociadoLog("Envio","Productos",lchrArrBuffer,pSisOpePtrDatos);
SiscomArgumentoInsercionSqlLog("SqlPedidoPC",lchrArrBuffer,pSisOpePtrDatos);
return 0;
}

int ArgumentoPedidoPorCotizacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlPedidoPC",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}

int AgregaFechaYIdPedidoPorCotizacion(SiscomOperaciones *pSisOpePtrDatos)
{
SiscomAsignaFechaHoraAsociadoEntrada("Envio","Fecha",pSisOpePtrDatos);
SiscomIdARegistrosAsociadosEntrada("Envio","IdPedido",pSisOpePtrDatos);
SiscomIdAsociadosCampoEntrada("Envio","Productos","IdProducto",pSisOpePtrDatos); 
return 0;
}
