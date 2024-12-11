#include <CorteCaja.h>

#include <SqlCorteCajaSucursal.h>


#include <ComunSiscomElectronica4.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomMacrosInsercionesSql.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>


#include <string.h>
#include <stdlib.h>
void RegistraCorteCajaSucursal(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCorteCaja,&lSiscomProDat);
SiscomAgregaOperacion(AsignaIdCorteCajaSucursal,&lSiscomProDat);
SiscomAgregaOperacion(AsignaFechaRegistroCorte,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCorteCajaSucursal,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(EnviaRegistraCorteCajaSucursal,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}
void CambiosRegistrados(int pintSocket,
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
SiscomAgregaOperacion(SqlDatosCierreCorteSucursal,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCambiosRegistrados,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CalculaCorteCaja(int pintSocket,
                      SiscomRegistroProL *pSiscomRegProLPtrPrim,
                      SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
/*
SiscomOperacionErrores lSiscomOpErrores{
*/
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
                           0,
                           (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
                           (SiscomRegistroProL *)pSiscomRegProLPtrAct,
                           &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlDatosCierreCorteSucursal,&lSiscomProDat);
SiscomAgregaOperacion(AsignaCamposConsultaCorteCaja,&lSiscomProDat);
SiscomAgregaOperacion(MultiplicaSumaDenominaciones,&lSiscomProDat);
SiscomAgregaOperacion(SumaGastosCaja,&lSiscomProDat);
SiscomAgregaOperacion(MultiplicandoSumandoCajas,&lSiscomProDat);
SiscomAgregaOperacion(ContandoCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(CalculandoCorteCaja,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCalculoCorteCaja,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CambiosCaja(int pintSocket,
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
SiscomAgregaOperacion(SqlCambiosCaja,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCambiosCaja,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaCambioCaja(int pintSocket,
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
SiscomAgregaOperacion(SqlCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(AcondicionandoParaMostrar,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void RegistraCambioCaja(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCorteCaja,&lSiscomProDat);
SiscomAgregaOperacion(AgregaArgumentoCajaCambio,&lSiscomProDat);
SiscomAgregaOperacion(AgregaArgumentoDatosCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(YaHayCajaConCambio,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoCambio,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int ColocaFechaHoyCorteCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrFecha[28];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomActualizaCampoAsociadoEntrada("Envio",
				    "Fecha",
				    lchrArrFecha,
				    pSisOpePtrDato);
return 0;
}
int RegistrandoCambio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadosArgumentoLog("SqlCorteCaja",
                            "SentenciasSql",
                             lchrArrBuffer,
                           pSisOpePtrDato);
return 0;
}
void AgregaRespuestaImportesCorteEnvio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomCampoProL *lSisCampoProLPtrDato;
SiscomRegistroProL *lSisRegProLPtrEnvio,
		   *lSisRegProLPtrRes;
lSisRegProLPtrEnvio=SiscomObtenRegistrosCampoEntrada("Envio",pSisOpePtrDato);
lSisCampoProLPtrDato=SiscomUltimoCampoRegistro(lSisRegProLPtrEnvio);
lSisCampoProLPtrDato->SiscomCamProLPtrSig=pSisOpePtrDato->SiscomRegProLPtrPrimRes->SiscomCamProLPtrDato; 
lSisRegProLPtrEnvio->SiscomCamProLPtrDato->intNCampos+=pSisOpePtrDato->SiscomRegProLPtrPrimRes->SiscomCamProLPtrDato->intNCampos;

}
int EnviandoCalculoCorteCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
AgregaRespuestaImportesCorteEnvio(pSisOpePtrDato);
SiscomEnviaAsociadoEntradaCliente("Envio",lchrArrBuffer,pSisOpePtrDato);
return 0;
}
float RealizaSumatoriaGastosCaja(SiscomRegistroProL *pSisRegProLPtrGastos)
{

}
int SumaGastosCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
float lfltTotalGastos;
SiscomRegistroProL *lSisRegProLPtrGastos;
if((lSisRegProLPtrGastos=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion(
				"Envio",
				"Cajas",
				"Gastos",
				pSisOpePtrDato)))
				
{
lfltTotalGastos=SiscomObtenSumatoriaRegistros("Importe",lSisRegProLPtrGastos); 
SiscomActualizaCampoAsociadoEntradaFloat("Envio",
					 "TotalGastos",
					 lfltTotalGastos,
					 pSisOpePtrDato);
}
else
LogSiscom("NO Se registraron gastos");
return 0;
}
int MultiplicandoSumandoCajas(SiscomOperaciones *pSisOpePtrDato)
{
float lfltTotal;
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrCajas,*lSisRegProLPtrCajas1;
lSisRegProLPtrCajas1=lSisRegProLPtrCajas=SiscomRegistroAsociadoEntradaOperacion("Envio",
										"Cajas",
								          pSisOpePtrDato);
for(;
    lSisRegProLPtrCajas;
    lSisRegProLPtrCajas=lSisRegProLPtrCajas->SiscomRegProLPtrSig)
{
lfltTotal=MultiplicaSumaCaja(SiscomObtenRegistrosCampoProL("Dinero",lSisRegProLPtrCajas));
SiscomActualizaCampoFloatRegistroActual("Total","%.2f",lfltTotal,lSisRegProLPtrCajas);
}

return 0;
}

float MultiplicaSumaCaja(SiscomRegistroProL *pSisRegProLPtrDeno)
{
float lfltTotal=0.0;
for(;
    pSisRegProLPtrDeno;
    pSisRegProLPtrDeno=pSisRegProLPtrDeno->SiscomRegProLPtrSig)
{
SiscomMultiplicaCamposACampo("Valor","Cantidad","Importe","%.2f",pSisRegProLPtrDeno); 
lfltTotal+=SiscomObtenCampoRegistroProLFloat("Importe",pSisRegProLPtrDeno);
}
return lfltTotal;
}

int MultiplicaSumaDenominaciones(SiscomOperaciones *pSisOpePtrDato)
{
float lfltTotal;
SiscomRegistroProL *lSisRegProLPtrDeno;
lSisRegProLPtrDeno=SiscomRegistrosAsociadosCampoEntrada("Envio",	
						        "Dinero",
							pSisOpePtrDato);
lfltTotal=MultiplicaSumaCaja(lSisRegProLPtrDeno);
return 0;
}

int ArgumentoCorteCaja(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlCorteCaja",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}
int AgregaArgumentoCajaCambio(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrCajaCambio;
lSisRegProLPtrCajaCambio=CajaDeCambio(pSisOpePtrDato);
SiscomAgregaArgumentoOperacion("CajaCambio",
			       lSisRegProLPtrCajaCambio,
			       lSisRegProLPtrCajaCambio,
			       pSisOpePtrDato);
return 0;
}
int AgregaArgumentoDatosCambioCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrIdCambioCaja[28],
	lchrArrFecha[28];;


SiscomRegistroProL *lSisRegProLPtrPrim=0,
		   *lSisRegProLPtrAct=0;
SiscomObtenNumeroUnicoChar(lchrArrIdCambioCaja);
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);

SiscomAnexaRegistroPro(&lSisRegProLPtrPrim,
		       &lSisRegProLPtrAct,
		       lchrArrBuffer,
		       "IdCambioCaja,Fecha,",
		       lchrArrIdCambioCaja,
		       lchrArrFecha);
SiscomAgregaArgumentoOperacion("DCorteCaja",
			       lSisRegProLPtrPrim,
			       lSisRegProLPtrAct,
			       pSisOpePtrDato);
return 0;
}
SiscomRegistroProL *CajaDeCambio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrCajas;
lSisRegProLPtrCajas=SiscomObtenRegistrosCampoEntrada("Envio",pSisOpePtrDato);
return SiscomBuscaRegistroLista("Nombre","Cambio",lSisRegProLPtrCajas);
}



SiscomRegistroProL *EfectivoCambioCaja(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrCCaja;

if((lSisRegProLPtrCCaja=CajaDeCambio(pSisOpePtrDato)))
return SiscomObtenRegistrosCampoProL("Dinero",lSisRegProLPtrCCaja);
}
int YaHayCajaConCambio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrIdCajaCambio[128];
LogSiscom("");
   if(SqlCajaConCambio(pSisOpePtrDato,lchrArrIdCajaCambio))
   {
	SiscomActualizaCampoArgumento2("DCorteCaja",
				       "IdCambioCaja",
				       lchrArrIdCajaCambio,
				       pSisOpePtrDato);
	SqlActualizaCambioCaja(pSisOpePtrDato);

   }
   else
	SqlRegistraCambioCaja(pSisOpePtrDato);
}

int EnviandoCambiosCaja(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[256];
SiscomEnviaAsociadoRespuestaCliente("CambiosCaja",lchrArrBuffer,pSisOpePtrDatos);
return 0;
}
char *CampoAcondicionado(const char *pchrPtrCampo,
			      SiscomRegistroProL *pSisRegProLPtrReg)
{
char lchrArrRegreso[12];
sprintf(lchrArrRegreso,
	 "%.0f",
	 SiscomObtenCampoRegistroProLFloat(pchrPtrCampo,pSisRegProLPtrReg));
return strdup(lchrArrRegreso);;
}
void AcondicionaRegistro(SiscomRegistroProL *pSisRegProLPtrReg)
{

SiscomActualizaCampoRegistroActual("cantidad",
				  CampoAcondicionado("cantidad",pSisRegProLPtrReg),
				  pSisRegProLPtrReg);


SiscomActualizaCampoRegistroActual("importe",
				  CampoAcondicionado("importe",pSisRegProLPtrReg),
				  pSisRegProLPtrReg);


if(!SiscomComparaCadenaCampoRegistroProL("0.500","valor",pSisRegProLPtrReg))
SiscomActualizaCampoRegistroActual("valor",
				  "0.50",
				  pSisRegProLPtrReg);
else
SiscomActualizaCampoRegistroActual("valor",
				  CampoAcondicionado("valor",pSisRegProLPtrReg),
				  pSisRegProLPtrReg);
				   
}
int AcondicionandoParaMostrar(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[128],
	lchrArrCantidad[12],
	lchrArrImporte[12],
	lchrArrValor[12];
SiscomRegistroProL *lSisRegProLPtrRegreso;
lSisRegProLPtrRegreso=SiscomRegistrosAsociadoRespuestaOperacion("CambioCaja",
							pSisOpePtrDatos);
for(;
	lSisRegProLPtrRegreso;
	lSisRegProLPtrRegreso=lSisRegProLPtrRegreso->SiscomRegProLPtrSig)
  AcondicionaRegistro(lSisRegProLPtrRegreso);

return 0;
}
int EnviandoCambioCaja(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[256];
SiscomEnviaAsociadoRespuestaCliente("CambioCaja",lchrArrBuffer,pSisOpePtrDatos);
return 0;
}
int EnviaCambiosRegistrados(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroRegresoLog(lchrArrBuffer,pSisOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSisOpePtrDato,lchrArrBuffer);
return 0;
}
SiscomRegistroProL *CajaCambio(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrCajas,
	 	   *lSisRegProLPtrCambio,
		   *lSisRegProLPtrCaja;
char lchrArrBuffer[128];
if((lSisRegProLPtrCajas=SiscomRegistroAsociadoEntradaOperacion("Envio",
							       "Cajas",
							       pSisOpePtrDato)))
{
for(lSisRegProLPtrCaja=lSisRegProLPtrCajas;
    lSisRegProLPtrCaja;
    lSisRegProLPtrCaja=lSisRegProLPtrCajas->SiscomRegProLPtrSig)
  if(!SiscomComparaCadenaCampoRegistroProL("Cambio","Nombre",lSisRegProLPtrCaja))
  return lSisRegProLPtrCaja;
}
return 0;
}
float CuantoVaEnCambio(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrCajaCambio;
if((lSisRegProLPtrCajaCambio=CajaCambio(pSisOpePtrDato)))
return SiscomObtenCampoRegistroProLFloat("Total",lSisRegProLPtrCajaCambio);
}
int ContandoCambioCaja(SiscomOperaciones *pSisOpePtrDato)
{
float lfltCuantoVaCambio,
	lfltCambioDiaAnterior;
const char *lchrPtrCambioDiaAnterior;
if((lchrPtrCambioDiaAnterior=SiscomCampoAsociadoEntradaOperacion("Envio",
							       "CambioDiaAnterior",
							       pSisOpePtrDato)))
{
lfltCambioDiaAnterior=atof(lchrPtrCambioDiaAnterior);
lfltCuantoVaCambio=CuantoVaEnCambio(pSisOpePtrDato);
if(lfltCambioDiaAnterior>lfltCuantoVaCambio)
SiscomActualizaCampoAsociadoEntrada("Envio","EdoCuentaCambio","0",pSisOpePtrDato);
else
SiscomActualizaCampoAsociadoEntrada("Envio","EdoCuentaCambio","1",pSisOpePtrDato);

}
else
LogSiscom("NO se ha registrado el cambio del dia anterior");
return 0;
}
int AsignaCamposConsultaCorteCaja(SiscomOperaciones *pSisOpePtrDato)
{
char *lchrPtrImpEntroC;
lchrPtrImpEntroC=(char *)SiscomCampoAsociadoRespuesta("PagaConP","importe",pSisOpePtrDato);
if(lchrPtrImpEntroC)
SiscomActualizaCampoAsociadoEntrada("Envio","DineroEntroCaja",lchrPtrImpEntroC,pSisOpePtrDato);
else
LogSiscom("----- No viene el cambo PagaConP");
return 0;
}
float CalculandoEfectivoCaja(SiscomOperaciones *pSisOpePtrDato)
{
float lfltEfectivo=0.0;
lfltEfectivo=SiscomCampoAsociadoEntradaOperacionFloat("Envio","DineroEntroCaja", pSisOpePtrDato)-
	    SiscomCampoAsociadoEntradaOperacionFloat("Envio","CambioDiaAnterior", pSisOpePtrDato);
return lfltEfectivo;
}

SiscomRegistroProL *ContandoCajaPrincipalDinero(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrCajas;
lSisRegProLPtrCajas=SiscomRegistrosAsociadosCampoEntrada("Envio","Cajas",pSisOpePtrDato);
return SiscomBuscaRegistroLista("Nombre","Principal",lSisRegProLPtrCajas);
}

SiscomRegistroProL *ContandoCajaCambio(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrCajas;
lSisRegProLPtrCajas=SiscomRegistrosAsociadosCampoEntrada("Envio","Cajas",pSisOpePtrDato);
return SiscomBuscaRegistroLista("Nombre","Cambio",lSisRegProLPtrCajas);
}
float ContandoCajaDinero(SiscomOperaciones *pSisOpePtrDato)
{
float lfltImporte;
SiscomRegistroProL *lSisRegProLPtrCajaPriD;
lSisRegProLPtrCajaPriD=ContandoCajaPrincipalDinero(pSisOpePtrDato);
lfltImporte=SiscomObtenCampoRegistroProLFloat("Total",lSisRegProLPtrCajaPriD);
return lfltImporte;
}

/*
 *  Total Ventas ------   100
 *   58                     X
 *
 *  X = 100x58/TotalVentas;
 *
 */

float PorcentajeDesvioCorte(float pfltVentasTotales,
			    float pfltCalculandoCorte)
{
return (100.00*pfltCalculandoCorte/pfltVentasTotales);

}

int CalculandoCorteCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
float lfltEfectivoCajaCalculado,
	lfltImporte,
	lfltImporteVentas,
	lfltTransferencias,
	lfltCalculandoCorte,
	lfltTotalGastos,
	lfltPorcentajeDesvioCorte,
	lfltCorte;
char *lchrPtrVentasTotalesP,
     *lchrPtrTransferenciasP;

lchrPtrVentasTotalesP=(char *)SiscomCampoAsociadoRespuesta("VentasTotalesP","importe",pSisOpePtrDato);
lchrPtrTransferenciasP=(char *)SiscomCampoAsociadoRespuesta("TransferenciasP","importe",pSisOpePtrDato);
if(lchrPtrVentasTotalesP)
SiscomActualizaCampoAsociadoEntrada("Envio","VentasTotales",lchrPtrVentasTotalesP,pSisOpePtrDato);
if(lchrPtrTransferenciasP)
SiscomActualizaCampoAsociadoEntrada("Envio","Transferencias",lchrPtrTransferenciasP,pSisOpePtrDato);

lfltImporte=ContandoCajaDinero(pSisOpePtrDato);
lfltEfectivoCajaCalculado=CalculandoEfectivoCaja(pSisOpePtrDato); 

lfltImporteVentas=SiscomCampoAsociadoEntradaOperacionFloat("Envio","VentasTotales",pSisOpePtrDato);
lfltTransferencias=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Transferencias",pSisOpePtrDato);
lfltTotalGastos=SiscomCampoAsociadoEntradaOperacionFloat("Envio","TotalGastos",pSisOpePtrDato);
lfltCalculandoCorte=(lfltImporte+lfltTransferencias+lfltTotalGastos)-lfltImporteVentas;
lfltCorte=(lfltImporte+lfltTransferencias+lfltTotalGastos);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","CalculandoCorte",lfltCalculandoCorte,pSisOpePtrDato);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","Billetes",lfltImporte,pSisOpePtrDato);
lfltPorcentajeDesvioCorte=PorcentajeDesvioCorte(lfltImporteVentas,lfltCalculandoCorte);
LogSiscom("Calculo de Efectivo en Caja %f",lfltEfectivoCajaCalculado);
LogSiscom("Importe Ventas              %f",lfltImporteVentas);
LogSiscom("Total Transferencias        %f",lfltTransferencias);
LogSiscom("Efectivo Contando           %f",lfltImporte);
LogSiscom("Total Gastos		       %f",lfltTotalGastos);
LogSiscom("Calculando Corte	       %f",lfltCalculandoCorte);
LogSiscom("Porcentaje Desvio Corte     %f",lfltPorcentajeDesvioCorte);
LogSiscom("Corte		       %f",lfltCorte);
SiscomEnviaAsociadoEntradaCliente("Envio",lchrArrBuffer,pSisOpePtrDato);
return 0;
}


int RespondeNoSeHaRegistradoCambio(SiscomOperaciones *pSisOpePtrDato)
{
LogSiscom("");
return 0;
}

int EnviaRegistraCorteCajaSucursal(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
}


int AsignaIdCorteCajaSucursal(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrIdCorteCaja[28];
SiscomObtenNumeroUnicoChar(lchrArrIdCorteCaja);
SiscomActualizaCampoAsociadoEntrada("Envio","IdCorte",lchrArrIdCorteCaja,pSisOpePtrDato);
return 0;
}
int AsignaFechaRegistroCorte(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrFecha[28];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomActualizaCampoAsociadoEntrada("Envio","Fecha",lchrArrFecha,pSisOpePtrDato);
return 0;
}
