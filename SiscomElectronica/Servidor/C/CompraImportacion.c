#include <CompraImportacion.h>

#include <OrdenesVendidas.h>
#include <SqlCompraImportacion.h>
#include <ComunSiscomElectronica4.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomMacrosInsercionesSql.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>

#include <string.h>
#include <stdlib.h>

void CompletaProductosImportacion(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCondicionVentas,&lSiscomProDat);
SiscomAgregaOperacion(FormaCondicionClavesProveedores,&lSiscomProDat);
SiscomAgregaOperacion(SqlCompletaProductosImportacion,&lSiscomProDat);
SiscomAgregaOperacion(CompletandoDatosProductoImportacion,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCompletaProductosImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void RegistroParcialCompraImportacionFaltaronProductos(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistroParcialCompraImportacionFaltaronProductos,&lSiscomProDat);
SiscomAgregaOperacion(GuardandoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void ProductoImportadoInf(int pintSocket,
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
SiscomAgregaOperacion(SqlProductoImportadoInf,&lSiscomProDat);
SiscomAgregaOperacion(EnviaProductoImportadoInf,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}
void GuardaCompraImportacionComo(int pintSocket,
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
SiscomAgregaOperacion(AsignaIdCompraImportacionComo,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(SqlGuardaCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(GuardandoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}
void GuardaCompraImportacion(int pintSocket,
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
SiscomAgregaOperacion(AsignaIdCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(SqlGuardaCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(GuardandoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaCompraImportacion(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoConsultaCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ConsultaComprasImportacion(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaComprasImportacion,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoConsultaComprasImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CompraImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSiscomOpDatError={0,ProductoYaEstaEnLaLista,0};
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(VerificaProductoDuplicado,&lSiscomProDat); 
SiscomAgregaOperacion(CalculandoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSiscomOpDatError,lSiscomProDat);
}

void RegistraCompraImportacion(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(AgregaIdCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCompraImportacion,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoCompraImportacion,&lSiscomProDat);
/* 
 *
 * CDMX a 4 Marzo 2021 
 * Se elimino esto, debido a que duplica la compra 
 * SiscomAgregaOperacion(AsignaIdCompraImportacion,&lSiscomProDat);
 * SiscomAgregaOperacion(SqlGuardaCompraImportacion,&lSiscomProDat); 
 *
 */
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}

void ProductosPorFiltroComprasImportacion(int pintSocket,
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
SiscomAgregaOperacion(SqlProductosPorFiltro,&lSiscomProDat);
SiscomAgregaOperacion(ProductosPorFiltro,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}



int RegistrandoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomArgumentoInsercionSqlLog("SqlCompraImportacion",
				lchrArrBuffer,
				pSiscomOpePtrDato);

SiscomAsociadoAsociadoLog("Envio","Productos",lchrArrBuffer,pSiscomOpePtrDato);

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

return 0;
}


int CalculandoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
float lfltPesoCompra=0.0,
	lfltCostoGramoEnvio;
SiscomRegistroProL *lSisRegProLPtrProductos,*lSisRegProLPtrPaso;

if((lSisRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio","Productos",pSiscomOpePtrDato))) 
{
lSisRegProLPtrPaso=lSisRegProLPtrProductos;
lfltPesoCompra=ObtenPesoCompra(lSisRegProLPtrProductos);
lfltCostoGramoEnvio=CostoGramoEnvio(lfltPesoCompra,pSiscomOpePtrDato);
PonderacionCostoAdministrativo(pSiscomOpePtrDato);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","PesoCompra",lfltPesoCompra,pSiscomOpePtrDato);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","CostoGrEnvio",lfltCostoGramoEnvio,pSiscomOpePtrDato);
for(;lSisRegProLPtrProductos;lSisRegProLPtrProductos=lSisRegProLPtrProductos->SiscomRegProLPtrSig)
{
   PesoTotalProducto(lSisRegProLPtrProductos);
   CostoEnvioProducto(lfltCostoGramoEnvio,lSisRegProLPtrProductos);
   CostoTotalDolares(lSisRegProLPtrProductos);
   PrecioMasCostoEnvio(lSisRegProLPtrProductos);
   CostoFinalPesos(pSiscomOpePtrDato,lSisRegProLPtrProductos);
   CostoFinalMasCostoAdministrativo(pSiscomOpePtrDato,lSisRegProLPtrProductos);
   CostoPartida(lSisRegProLPtrProductos);
}
}
ObtenImporteCompra(lSisRegProLPtrPaso,pSiscomOpePtrDato);
return 0;
}

int EnviandoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomEnviaAsociadoEntradaCliente("Envio",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}


int ProductosPorFiltro(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomEnviaAsociadoRespuestaCliente("Productos",
                                    lchrArrBuffer,
                                    pSiscomOpePtrDato);
return 0;
}
int EnviandoConsultaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomRegistroProL *lSisRegProLPtrCompraI;

lSisRegProLPtrCompraI=SiscomRegistrosAsociadoRespuestaOperacion("Compra",pSiscomOpePtrDato);
if(lSisRegProLPtrCompraI)
{
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrCompraI);
 if(SiscomRegistrosAsociadoRespuestaOperacion("DetalleCompra",pSiscomOpePtrDato))
    SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
 else
 {
 LogSiscom("NO se pudo cargar la informacion de la compra");
 NoSePuedeCargarImportacion(pSiscomOpePtrDato);
 }

}

return 0;
}

int EnviandoConsultaComprasImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
return 0;
}
int EnviaProductoImportadoInf(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomRegistroRegresoLog(lchrArrBuffer,pSiscomOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer); 
return 0;
}

float ObtenPesoCompra(SiscomRegistroProL *pSisRegProLPtrProductos)
{
float lfltPesoCompra=0.0;
for(;pSisRegProLPtrProductos;pSisRegProLPtrProductos=pSisRegProLPtrProductos->SiscomRegProLPtrSig)
 lfltPesoCompra+=SiscomObtenCampoRegistroProLFloat("Cantidad",pSisRegProLPtrProductos)*
 		 SiscomObtenCampoRegistroProLFloat("Peso",pSisRegProLPtrProductos);

return lfltPesoCompra;
}
void PesoTotalProducto(SiscomRegistroProL *pSisRegProLPtrProducto)
{
SiscomMultiplicaCamposACampo("Cantidad","Peso","PesoTotal","%.3f",pSisRegProLPtrProducto);
}
float CostoGramoEnvio(float pfltPesoTotal,SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltCostoGramoEnvio;

lfltCostoGramoEnvio=SiscomCampoAsociadoEntradaOperacionFloat("Envio", "CostoEnvio", pSiscomOpePtrDato)/pfltPesoTotal;
return lfltCostoGramoEnvio;
}
void CostoEnvioProducto(float pfltCostoGramoEnvio,
			SiscomRegistroProL *pSisRegProLPtrProducto)
{
  SiscomMultiplicaCampoPorDato("PesoTotal",
  				pfltCostoGramoEnvio,
				"CostoEnvio",
				"%.3f",
				pSisRegProLPtrProducto);
}

void CostoTotalDolares(SiscomRegistroProL *pSisRegProLPtrProducto)
{
SiscomMultiplicaCamposACampo("Cantidad",
			     "CostoUnitarioDolares",
			     "CostoTotalDolares",
			     "%.3f",
			     pSisRegProLPtrProducto);
}
void PrecioMasCostoEnvio(SiscomRegistroProL *pSisRegProLPtrProducto)
{
 SiscomSumaCamposACampo("CostoTotalDolares",
 			"CostoEnvio",
			"PrecioMasCostoEnvio",
			"%.3f",
			pSisRegProLPtrProducto);
}
void CostoFinalPesos(SiscomOperaciones *pSiscomOpePtrDato,
		     SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
float lfltPrecioFinal,
	lfltPrecioMasCostoEnvio,
	lfltPrecioDolar,
	lfltCantidad;
char lchrArrResultado[28];
lfltPrecioMasCostoEnvio=SiscomObtenCampoRegistroProLFloat("PrecioMasCostoEnvio",
							  pSiscomRegProLPtrProducto);
lfltPrecioDolar=SiscomCampoAsociadoEntradaOperacionFloat("Envio","CostoDolar",pSiscomOpePtrDato);
lfltCantidad=SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrProducto);

lfltPrecioFinal=(lfltPrecioMasCostoEnvio/lfltCantidad)*1.16*lfltPrecioDolar;
sprintf(lchrArrResultado,"%.2f",lfltPrecioFinal);
SiscomActualizaCampoAsignaMemoria2("CostoFinalPesos",lchrArrResultado,pSiscomRegProLPtrProducto);
}
void PonderacionCostoAdministrativo(SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltNumPartidas,
	lfltCostoAdministrativo,
	lfltPonderacionCosAdm;
char lchrArrResultado[28];
lfltNumPartidas=SiscomCampoAsociadoEntradaOperacionFloat("Envio","NumPartidas",pSiscomOpePtrDato);
lfltCostoAdministrativo=SiscomCampoAsociadoEntradaOperacionFloat("Envio",
								"CostoAdministrativo",
								pSiscomOpePtrDato);
lfltPonderacionCosAdm=lfltCostoAdministrativo/lfltNumPartidas;
sprintf(lchrArrResultado,"%.3f",lfltPonderacionCosAdm);
SiscomActualizaCampoAsociadoEntrada("Envio",
				    "PonderacionCostoAdministrativo",
				    lchrArrResultado,
				    pSiscomOpePtrDato);
}
void CostoFinalMasCostoAdministrativo(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
float lfltPonderacion,
	lfltCantidad,
	lfltCostoFinalPesos,
	lfltCostoFinalMasCosAdm;
lfltPonderacion=SiscomCampoAsociadoEntradaOperacionFloat("Envio",
						         "PonderacionCostoAdministrativo",
							 pSiscomOpePtrDato);
lfltCantidad=SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrProducto);
lfltPonderacion/=lfltCantidad;
SiscomSumaCampoPorDato("CostoFinalPesos",
			lfltPonderacion,
			"CostoFinalMasCosAdm",
			"%.2f",
			pSiscomRegProLPtrProducto);
}
void CostoPartida(SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
SiscomMultiplicaCamposACampo("Cantidad",
			     "CostoFinalMasCosAdm",
			     "CostoPartida",
			     "%.2f",
			     pSiscomRegProLPtrProducto);
}


int ArgumentoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlCompraImportacion",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}

int AgregaIdCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
/*
SiscomAgregaCampoAsociadoEntrada("IdCompra",0,"Envio",pSiscomOpePtrDato);
SiscomIdARegistrosAsociadosEntrada("Envio","IdCompra",pSiscomOpePtrDato);
*
*/
if(!SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSiscomOpePtrDato))
SiscomIdARegistrosAsociadosEntrada("Envio","IdCompraImportacion",pSiscomOpePtrDato);

return 0;
}
int AgregaFechaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaCampoAsociadoEntrada("Fecha",0,"Envio",pSiscomOpePtrDato);
SiscomAsignaFechaHoraAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
return 0;
}
void EnviaIdCompraRegreso(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrPrimReg=0,
		   *lSisRegProLPtrActReg=0;
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(&lSisRegProLPtrPrimReg,
		       &lSisRegProLPtrActReg,
		       lchrArrBuffer,
		       "IdCompraImportacion,",
		       SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSisOpePtrDato));

SiscomEnviaRegistrosSocket(pSisOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSisRegProLPtrPrimReg);
}
int GuardandoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
LogSiscom("");
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

SiscomArgumentoInsercionSqlLog("SqlCompraImportacion",
				lchrArrBuffer,
				pSiscomOpePtrDato);
EnviaIdCompraRegreso(pSiscomOpePtrDato);
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

int AsignaIdCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrIdCompraImportacion=SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSiscomOpePtrDato);
LogSiscom("El Id de la compra %s",lchrPtrIdCompraImportacion);
if(!lchrPtrIdCompraImportacion)
SiscomIdARegistrosAsociadosEntrada("Envio","IdCompraImportacion",pSiscomOpePtrDato);
else
LogSiscom("Ya viene el IdCompra ..., es consulta");
return 0;
}

int AsignaIdCompraImportacionComo(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdCompraImportacion",pSiscomOpePtrDato);
return 0;
}
void ObtenImporteCompra(SiscomRegistroProL *pSiscomRegProLPtrProductos,
			SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltImporteCompra=SiscomObtenSumatoriaRegistros("CostoPartida",pSiscomRegProLPtrProductos);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","ImporteFactura",lfltImporteCompra,pSiscomOpePtrDato);
}
int VeSiEstaYaEnLaListaElProducto(SiscomRegistroProL *pSisRegProLPtrProd,
				  SiscomRegistroProL *pSisRegProLPtrProductos)
{
char lchrArrBuffer[256];
for(;pSisRegProLPtrProductos;pSisRegProLPtrProductos=pSisRegProLPtrProductos->SiscomRegProLPtrSig)
{
  if(!SiscomComparaCampoRegistrosProL("CveProducto",pSisRegProLPtrProd,pSisRegProLPtrProductos))
  { 
     SiscomRegistroProtocoloLog(lchrArrBuffer,pSisRegProLPtrProductos);
     return 1;
  }
}

return 0;
}
		

int VerificaProductoDuplicado(SiscomOperaciones *pSisOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLPtrProductos,
		   *lSisRegProLPtrProductosRe;
int lintRegreso=0;
char lchrArrBuffer[512];
if((lSisRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio","Productos",pSisOpePtrDatos))) 
{
    lSisRegProLPtrProductosRe=lSisRegProLPtrProductos->SiscomRegProLPtrSig;
  for(;
       lSisRegProLPtrProductos&&lSisRegProLPtrProductosRe;
       lSisRegProLPtrProductos=lSisRegProLPtrProductos->SiscomRegProLPtrSig,
       lSisRegProLPtrProductosRe=lSisRegProLPtrProductos->SiscomRegProLPtrSig)
  {
  LogSiscom("Nodo Actual %s",SiscomObtenCampoRegistroProLChar("CveProducto",lSisRegProLPtrProductos));
   if(VeSiEstaYaEnLaListaElProducto(lSisRegProLPtrProductos,lSisRegProLPtrProductosRe))
   {
      LogSiscom("\t\t Ya esta");
      lintRegreso=1;
     break;
   }
  }
}
return lintRegreso;
}

int ProductoYaEstaEnLaLista(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRespuestaEstado(pSisOpePtrDato, "1", "El Producto ya esta en la lista");
return 0;
}

int NoSePuedeCargarImportacion(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRespuestaEstado(pSisOpePtrDato, "1", "No se puede cargar la compra de importacion");
return 0;
}
void AgregaProductoCondicion(const char *pchrPtrProducto,
			     char *pchrPtrProdCondicion)
{
    sprintf(pchrPtrProdCondicion,"'%s'",pchrPtrProducto);
}
char *IniciaMemoriaCondicionClavesProveedores(SiscomRegistroProL *pSisRegProLPtrDat)
{
char lchrArrCondicion[256];
sprintf(lchrArrCondicion,
	"where idempresa=%s and 		\n\
		cveproveedor in(",
	SiscomObtenCampoRegistroProLChar("IdProveedor",pSisRegProLPtrDat));

return strdup(lchrArrCondicion);
}
void AgregandoProductoCondicion(const char *pchrPtrPaso,
			        char **pchrPtrCondicion)
{
int lintTamanoBuffer;
  lintTamanoBuffer=strlen(*pchrPtrCondicion) +
  		   strlen(pchrPtrPaso)+1;
 *pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,lintTamanoBuffer);
 strcat(*pchrPtrCondicion,pchrPtrPaso);
}
void AgregandoLaComa(SiscomRegistroProL *pSisRegProLPtrProd,
		     char *pchrPtrCondicion)
{
   if(pSisRegProLPtrProd->SiscomRegProLPtrSig)
    strcat(pchrPtrCondicion,",");

}
int FormaCondicionClavesProveedores(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
	*lchrPtrCondicion,
	lchrArrPaso[256];
SiscomRegistroProL *lSisRegProLPtrProd;
lSisRegProLPtrProd=SiscomRegistroAsociadoEntradaOperacion("Envio","Productos",pSisOpePtrDato);
lchrPtrCondicion=IniciaMemoriaCondicionClavesProveedores(lSisRegProLPtrProd);
for(;
	lSisRegProLPtrProd;
	lSisRegProLPtrProd=lSisRegProLPtrProd->SiscomRegProLPtrSig)
{
  AgregaProductoCondicion(SiscomObtenCampoRegistroProLChar("CveProveedor",lSisRegProLPtrProd),
  			  lchrArrPaso);
  AgregandoProductoCondicion(lchrArrPaso,&lchrPtrCondicion);
  AgregandoLaComa(lSisRegProLPtrProd,lchrPtrCondicion);
}
strcat(lchrPtrCondicion,")");
ActualizaArgumentoCondicion(lchrPtrCondicion,pSisOpePtrDato);
return 0;
}
void AgregaPesoClaveSiscom(SiscomRegistroProL *pSisRegProLPtrProducto,
			   SiscomRegistroProL *pSisRegProLPtrProductos)
{
int lintSiSeEncontro=0;
LogSiscom("Buscando informacion de %s",
	  SiscomObtenCampoRegistroProLChar("CveProveedor",pSisRegProLPtrProducto));
   for(;
       pSisRegProLPtrProductos;
       pSisRegProLPtrProductos=pSisRegProLPtrProductos->SiscomRegProLPtrSig)
   {
  	if(!SiscomComparaCampoRegistrosProL2("cveproveedor",
					     "CveProveedor",
					     pSisRegProLPtrProductos,
					     pSisRegProLPtrProducto))
	{
	   LogSiscom("Si se encontro Clave Siscom (%s) Peso (%s)",
	   	      SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrProductos),
		      SiscomObtenCampoRegistroProLChar("peso",pSisRegProLPtrProductos));	   
	  SiscomAsignaCampo("CveProducto",
	   	      SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrProductos),
		      pSisRegProLPtrProducto);
	  SiscomAsignaCampo("Peso",
	   	      SiscomObtenCampoRegistroProLChar("peso",pSisRegProLPtrProductos),
		      pSisRegProLPtrProducto);
	   lintSiSeEncontro=1;
	  			
	}

   }
    if(!lintSiSeEncontro)
      LogSiscom("\tEl Producto no tiene informacion de Siscom");

}
int CompletandoDatosProductoImportacion(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrProductos,
		   *lSisRegProLPtrPorCompletar;
lSisRegProLPtrProductos=SiscomRegistrosAsociadoRespuestaOperacion("Productos",pSisOpePtrDato);
lSisRegProLPtrPorCompletar=SiscomRegistroAsociadoEntradaOperacion("Envio","Productos",pSisOpePtrDato); 
for(;
     lSisRegProLPtrPorCompletar;
     lSisRegProLPtrPorCompletar=lSisRegProLPtrPorCompletar->SiscomRegProLPtrSig)
{
     AgregaPesoClaveSiscom(lSisRegProLPtrPorCompletar,lSisRegProLPtrProductos);

}
     


}
					 
int EnviaCompletaProductosImportacion(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256];
/*
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
SiscomAsociadoAsociadoLog("Envio","Productos",lchrArrBuffer,pSisOpePtrDato);
*/
SiscomEnviaRegistrosEntrada(pSisOpePtrDato,lchrArrBuffer);
return 0;
}
